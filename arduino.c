#include <Servo.h>
#define BLYNK_TEMPLATE_NAME "PARTH"
#define BLYNK_AUTH_TOKEN "hoCJbtbuLYcygDFIHp1_XjAjkkaz_s2f"
int pos = 0;

const int xPin = A1;
const int yPin = A2;
const int zPin = A0;
int minVal = 511;
int maxVal = 575;
int x;
int y;
int z;
Servo servo_5;
Servo servo_6;
Servo servo_7;
Servo servo_8;
Servo servo_9;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  servo_5.attach(5, 500, 2500);
  servo_6.attach(6, 500, 2500);
  servo_7.attach(7, 500, 2500);
  servo_8.attach(8, 500, 2500);
  servo_9.attach(9, 500, 2500);
  analogReference(EXTERNAL);

}

void loop()
{
  /*//Therapy
  for(int i=0;i<100000;i++)
  {
  for (pos = 0; pos <= 90; pos += 1)
 {
    servo_5.write(pos);
    servo_6.write(pos);
    servo_7.write(pos);
    servo_8.write(pos);
    servo_9.write(pos);
    delay(50);
  }
  for (pos = 90; pos >= 0; pos -= 1) 
{
   servo_5.write(pos);
    servo_6.write(pos);
    servo_7.write(pos);
    servo_8.write(pos);
    servo_9.write(pos);
    delay(50); 
  }
  }*/
  //Monitoring
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);
  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);
  x = (int)RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = (int)RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z =(int) RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" | y: ");
  Serial.print(y);
  Serial.print(" | z: ");
  Serial.println(z);
  if ((x!=225) || (y!=225)|| (z!=225))  // maximum safe deceleration.
  {
        Serial.print(" MOVEMENT DETECTED ");
        digitalWrite(2, HIGH);
        delay(1000);
  }
          digitalWrite(2, LOW);
}

