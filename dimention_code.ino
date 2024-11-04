#include <LiquidCrystal.h>

LiquidCrystal lcd(10,9,5,4,3,2);

const int trigPin = 11;
const int echoPin = 12;
const int trigPi = 7;
const int echoPi = 8;
const int trigP = 18;
const int echoP = 19;


long duration;
int length;
int width;
int area;
int height;
int volume;


void setup() {
  // put your setup code here, to run once:
    analogWrite(6,100);
    lcd.begin(16,2);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(trigPi, OUTPUT);
    pinMode(echoPi, INPUT);
    pinMode(trigP, OUTPUT);
    pinMode(echoP, INPUT);

Serial.begin(9600); // Starts the serial communication

    
}

void loop() {
long duration, distance,distance_w,area;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  int t=duration/2;
   float v = 1/29.1; 
   distance = v*t;
   length =29-distance;
   
    lcd.setCursor(0,0);
    lcd.print("L=");
    lcd.setCursor(2,0);
    lcd.print(distance);
    lcd.setCursor(5,0);
    lcd.print("CM");

// code for width
  digitalWrite(trigPi,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPi, LOW);
  duration=pulseIn(echoPi, HIGH);
  width=28-(duration/2)/29.1;
  lcd.setCursor(7,0);
  lcd.print(" w=");
  lcd.setCursor(10,0);
  lcd.print(width);
  lcd.setCursor(13,0);
  lcd.print("CM");

  
  //code for height
  digitalWrite(trigP,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigP, LOW);
  duration=pulseIn(echoP, HIGH);
  height =15-(duration/2)/29.1;
  lcd.setCursor(0,1);
  lcd.print("H= ");
  lcd.setCursor(2,1);
  lcd.print(height);
  lcd.setCursor(5,1);
  lcd.print("CM");
  delay(3000);
  lcd.clear();
  
  //code for Area
  area=width*length;
  lcd.setCursor(0,0);
  lcd.print("AREA= ");
  lcd.setCursor(6,0);
  lcd.print(area);
  lcd.setCursor(10,0);
  lcd.print("CM^2");



  //code for Volume
    volume=width*length*height;
    lcd.setCursor(0,1);
    lcd.print("VOLM= ");
    lcd.setCursor(6,1);
    lcd.print(volume);
    lcd.setCursor(10,1);
    lcd.print("CM^3");
delay(3000);   
}
