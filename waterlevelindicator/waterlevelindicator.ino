/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************

  Output any data on LCD widget!

  App project setup:
    LCD widget, switch to ADVANCED mode, select pin V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int trig=4 ,echo=5;
int distance;
long duration;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "T5FsV9VGFOLYB721ExGDF6DoOcIQC7Y4";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "Virus infected Wi-Fi!";    // Your WiFi credentials.
char pass[] = "laddusai1"; 
void setup()
{
  // Debug console
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

 // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped


void loop()
{
  
 digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(10);
digitalWrite(trig,LOW);
duration=pulseIn(echo,HIGH);
distance=0.0343*duration/2;
Serial.println("distance in cm:");
Serial.println(distance);
/*Serial.println("distance in m:");
Serial.println(distance/100);*/
float per =float ((distance*100)/14);
int percentage = int (per);
//Serial.println(percentage);
if(distance < 14)
{
  Serial.println("Percentage tank filled");
Serial.println(String (100-percentage)+"%"); 
Blynk.virtualWrite(V0,100-percentage);
delay(1000);
  }
  else
  {
    Serial.println("Percentage tank filled");
Serial.println("100%");
Blynk.virtualWrite(V0,0);
delay(1000);
  }  Blynk.run();

  delay(1500);
}
