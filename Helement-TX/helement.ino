#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

#define buttonPin 6
unsigned long buttonPressTime = 0;
bool buttonPressed = false;

unsigned long previousMillis = 0;

unsigned long currentMillis;

int value = 0;

int sleep = 0;
int alcohol = 0;
int helmet = 0;

#define sleepalarm 13
#define helmetsense 4
#define mq3 A0

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(sleepalarm, OUTPUT);
  pinMode(helmetsense, INPUT);

  digitalWrite(sleepalarm, LOW);

  mySwitch.enableTransmit(12);
}

void loop() 
{
  helmet = digitalRead(helmetsense);
  
  int buttonState = !digitalRead(buttonPin);
  if (buttonState == LOW && !buttonPressed) 
  {
    buttonPressed = true;
    buttonPressTime = millis(); // Record the time the button was pressed
  }

  else if (buttonState == LOW && buttonPressed) 
  {
    if (millis() - buttonPressTime >= 3000 && helmet == 1) 
    { 
      sleep = 1;
      digitalWrite(sleepalarm, HIGH);
    }   
  }  

  else if (buttonState == HIGH && buttonPressed) 
  {
   buttonPressed = false; 
  }
  

  if(analogRead(mq3) >= 500)
  {
    alcohol = 1;
  }

  else
  {
    alcohol = 0;
  }

  if(helmet == 1 && alcohol == 0 && sleep == 0)
  value = 1;

  else if(helmet == 1 && alcohol == 1 && sleep == 0)
  value = 2;

  else if(helmet == 1 && alcohol == 0 && sleep == 1)
  value = 3;

  else if(helmet == 0)
  value = 7;

  else
  value = 9;

  mySwitch.send(value, 30);

  delay(100);
}
