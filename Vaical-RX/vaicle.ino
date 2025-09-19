#include <RCSwitch.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

#define time_offset 19800

SoftwareSerial gsm(6, 7);

char incoming_char = 0;
String gMap = "http://www.google.com/maps/place/";
double Latitude, Longitude, Altitude, speed;
boolean GPSstatus = false;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

char Time[]  = "00:00:00";
char Date[]  = "00-00-2000";
String nameofday;
int Year;
byte last_second , Month, Day, Hour, Minute, Second;
String DateString = "";

LiquidCrystal_I2C lcd(0x27,20,4);

RCSwitch mySwitch = RCSwitch();

int value;

int helmet = 0;
int engine = 0;
int received = 1;

#define pushpin 4
#define relay 5

int sos = 0;
int sent = 0;
#define sosbutton 12
#define buz 13

void setup() 
{
  Serial.begin(9600);
  gsm.begin(9600);
  delay(20);
  gsm.println("AT");
  delay(20);
  gsm.println("AT+CMGF=1");

  if(!accel.begin())
  {
   Serial.println("No valid sensor found");
   while(1);
  }
  
  pinMode(pushpin, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(sosbutton, INPUT);
  digitalWrite(relay, HIGH);
  digitalWrite(buz, LOW);
  
  mySwitch.enableReceive(0);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("    Smart Helmet    ");

  delay(3000);
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Please Wear Helmet ");
}

void loop() 
{
  sensors_event_t event;
  accel.getEvent(&event);

  if(event.acceleration.y > 5 || event.acceleration.y < -5 || event.acceleration.x > 5 || event.acceleration.x < -5 && engine == 1) 
  {
    sos = 1;
  }
  
  if(digitalRead(sosbutton) == 1)
  sos = 1;
  
  while (Serial.available() > 0)
    if (gps.encode(Serial.read()))
    {
      getGPSdata();
      Serial.print("Latitude : ");
      Serial.print(Latitude);
      Serial.print("    Longitude : ");
      Serial.print(Longitude);
    }
    
  if (mySwitch.available()) 
  {
    value = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();

    received = 0;
  }

  if(value == 1 && engine == 0)
    {
      lcd.setCursor(0,0);
      lcd.print("  Push the  switch  ");
      lcd.setCursor(0,1);
      lcd.print("   To turn on the   ");
      lcd.setCursor(0,2);
      lcd.print("       Engine       ");

      helmet = 1;
    }

  else if(value == 7 && engine == 0)
    {
      helmet = 0;
      
      lcd.setCursor(0,0);
      lcd.print(" Please Wear Helmet ");
      lcd.setCursor(0,1);
      lcd.print("                    ");
      lcd.setCursor(0,2);
      lcd.print("                    ");
    }

  else if(value == 7 && engine == 1)
    {
      helmet = 0;

      lcd.setCursor(0,1);
      lcd.print("  Turning off the   ");
      lcd.setCursor(0,2);
      lcd.print("      Engine        ");
      lcd.setCursor(0,0);
      lcd.print("Helmet Not  detected");

      digitalWrite(buz, HIGH);
      delay(3000);
      digitalWrite(relay, HIGH);
      digitalWrite(buz, LOW);
      engine = 0;
    }

  else if(value == 2 && engine == 1)
    {
      

      lcd.setCursor(0,1);
      lcd.print("  Turning off the   ");
      lcd.setCursor(0,2);
      lcd.print("      Engine        ");
      lcd.setCursor(0,0);
      lcd.print(" Alcohol  Detected  ");

      digitalWrite(buz, HIGH);
      delay(3000);
      digitalWrite(buz, LOW);
      digitalWrite(relay, HIGH);
      engine = 0;
    }

  else if(value == 2 && engine == 0)
    {
      lcd.setCursor(0,1);
      lcd.print(" Cannot Start The   ");
      lcd.setCursor(0,2);
      lcd.print("      Engine        ");
      lcd.setCursor(0,0);
      lcd.print(" Alcohol  Detected  ");
    }

  else if(value == 3 && engine == 1)
    {
      lcd.setCursor(0,1);
      lcd.print("  Turning off the   ");
      lcd.setCursor(0,2);
      lcd.print("      Engine        ");
      lcd.setCursor(0,0);
      lcd.print("  Sleep  Detected  ");

      digitalWrite(buz, HIGH);
      delay(3000);
      digitalWrite(buz, LOW);
      digitalWrite(relay, HIGH);
      engine = 0;

      lcd.setCursor(0,1);
      lcd.print("  Please Reset the  ");
      lcd.setCursor(0,2);
      lcd.print("       Helmet       ");
      lcd.setCursor(0,0);
      lcd.print("                    ");
    }
  

  if(helmet == 1 && digitalRead(pushpin) == 1 && engine == 0 && value == 1)
  {
    digitalWrite(relay, LOW);
    engine = 1;

    lcd.setCursor(0,1);
    lcd.print("   Engine Running   ");
    lcd.setCursor(0,2);
    lcd.print("                    ");
    lcd.setCursor(0,0);
    lcd.print("                    ");
  }


  if(sos == 1 && sent <= 3)
  {
    digitalWrite(relay, HIGH);
    engine = 0;
    
    dateString();
    gsm.println("AT+CMGF=1");
    delay(20);
    gsm.println("AT+CMGS=\"+919845018457\"");
    delay(20);
    gsm.println(dateString()); 
    delay(20);
    gsm.print(gMap); 
    delay(20);
    gsm.print(Latitude, 6);
    delay(20);
    gsm.print(",");
    delay(20);
    gsm.println(Longitude, 6);
    delay(20);
    gsm.print("ACCIDENT DETECTED!!");
    gsm.write(26);

    lcd.setCursor(0,0);
    lcd.print(" ACCIDENT  DETECTED ");
    lcd.setCursor(0,1);
    lcd.print("  SOS Message sent  ");
    lcd.setCursor(0,2);
    lcd.print("   With Location    ");

    sent++;
    digitalWrite(buz, HIGH);
    delay(3000);
    digitalWrite(buz, LOW);
    delay(7000);

    if(sent == 3)
    {
      sent = 0;
      sos = 0;
    }
  }
  


  received = 1;
}






void getGPSdata() 
{
  if (gps.location.isValid()) {
    Latitude = gps.location.lat(), 6; // Latitude in degrees (double)
    Longitude = gps.location.lng(), 6; // Longitude in degrees (double)
    GPSstatus =  true;
  }
  else
    GPSstatus =  false;
  if (gps.date.isValid()) {
    Year = gps.date.year(); // Year (2000+) (u16)
    Month = gps.date.month(); // Month (1-12) (u8)
    Day = gps.date.day(); // Day (1-31) (u8)
  }
  else
    GPSstatus =  false;

  if (gps.time.isValid()) {
    Hour = gps.time.hour(); // Hour (0-23) (u8)
    Minute = gps.time.minute(); // Minute (0-59) (u8)
    Second = gps.time.second(); // Second (0-59) (u8)
  }
  else
    GPSstatus =  false;

  if (last_second != gps.time.second()) {
    last_second = gps.time.second();
    // set current UTC time
    setTime(Hour, Minute, Second, Day, Month, Year);
    // add the offset to get local time
    adjustTime(time_offset);
    // update time array
    Time[6] = second() / 10 + '0';
    Time[7] = second() % 10 + '0';
    Time[3]  = minute() / 10 + '0';
    Time[4] = minute() % 10 + '0';
    Time[0]  = hour()   / 10 + '0';
    Time[1]  = hour()   % 10 + '0';
    // update date array
    Date[8] = (year()  / 10) % 10 + '0';
    Date[9] =  year()  % 10 + '0';
    Date[3]  =  month() / 10 + '0';
    Date[4] =  month() % 10 + '0';
    Date[0]  =  day()   / 10 + '0';
    Date[1]  =  day()   % 10 + '0';
  }
  switch (weekday())  {
    case 1:  nameofday = "SUNDAY, ";   break;
    case 2:  nameofday = "MONDAY, ";   break;
    case 3:  nameofday = "TUESDAY, ";   break;
    case 4:  nameofday = "WEDNESDAY, ";   break;
    case 5:  nameofday = "THURSDAY, ";   break;
    case 6:  nameofday = "FRIDAY, ";   break;
    default: nameofday = "SATURDAY, ";
  }
  if (gps.speed.isValid()) {
    speed = gps.speed.mps(); // Speed in meters per second (double)
  }
  else
    GPSstatus =  false;

  if (gps.altitude.isValid()) {
    Altitude = gps.altitude.meters(); // Altitude in meters (double)
  }
  else
    GPSstatus =  false;
}

String dateString() {
  DateString = "";
  DateString += nameofday;
  DateString += " ";
  DateString += Date;
  DateString += " ";
  DateString += Time;
  return DateString;
}
