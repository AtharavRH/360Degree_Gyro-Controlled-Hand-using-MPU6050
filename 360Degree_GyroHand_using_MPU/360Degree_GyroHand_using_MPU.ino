#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

Servo servo1;          
Servo servo2;  //initlizeing servo instance   
int servo_pin1 = 2;
int servo_pin2 = 3;  

MPU6050 sensor ;

int16_t ax, ay, az ; //16 byte variable
int16_t gx, gy, gz ; //16 byte variable

void setup()
{ 

servo1.attach ( servo_pin1 );
servo1.attach ( servo_pin2 );

Wire.begin ( );

Serial.begin  (9600); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

}




void loop ( ) 

{ 

sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);

ax = map (ax, -17000, 17000, 0, 180) ;

ay = map (ay, -17000, 17000, 0, 180) ;

Serial.println (ax);

servo1.write (ax); 
servo2.write (ay);
delay (200);

}
