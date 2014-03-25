/*******************************************************************************
 * Project  : Ultrasonic HC SR04                                               *
 * Compiler : Arduino 1.0.2                                                    *
 * Board    : Arduino UNO                                                      *
 * Module   : Ultrasonic HC SR04                                               *
 *          : LiquidCrystal                                                    *
 * Author   : Bavensky :3                                                      *
 * E-Mail   : Aphirak_Sang-ngenchai@hotmail.com                                *
 * Date     : 25/03/2014 [dd/mm/yyyy]                                          *
 *******************************************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define trigPin A0
#define echoPin A1

long duration, distance;
int i=0; int n=0; int b=0; int s=0;

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  check();
  lcd.setCursor(0, 0);lcd.print("TEST Ultrasonic");
  lcd.setCursor(0, 1);lcd.print("Distance :");lcd.print(distance);delay(1000);
}

void check()
{
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}
