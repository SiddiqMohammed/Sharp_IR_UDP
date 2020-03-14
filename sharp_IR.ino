#include <SPI.h>
#include <Ethernet2.h>
#include <EthernetUdp2.h>
#include <SharpDistSensor.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>

//--------------------PIN DECLARATION-----------------//
//const byte sensorPin[] = {A1, A3, A4, A5};

const byte sensorPin[] = {A1};

//-----------------UDP -----------------------------//
byte MAC[] = {0x2C, 0xF7, 0xF1, 0x08, 0x0B, 0x11};
IPAddress local_IP(192, 168, 1, 101);
IPAddress SERVER_IP(192, 168, 1, 100);
unsigned int localPort = 5001;
EthernetUDP Udp;

unsigned int distance[] = {0, 0, 0, 0};


int min_distance[] = {150, 150, 150, 150};
int max_distance[] = {350, 350, 350, 350};

// Window size of the median filter (odd number, 1 = no filtering)
const byte medianFilterWindowSize = 10;

String Status[] = {"", "", "", ""};

SharpDistSensor sensor1(sensorPin[0], medianFilterWindowSize);

int data = 0;


void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(115200);
  Ethernet.begin(MAC, local_IP);
  Udp.begin(localPort);

}

void loop()
{
  Status[0] = "";

  distance[0] = sensor1.getDist();

  int A =  distance[0];

  Serial.print("Distance A1: ");
  Serial.println(distance[0]);

  Serial.println(" ");

  if ((distance[0] >= min_distance[0]) && (distance[0] <= max_distance[0]))
  {
    Status[0] = "1";
  }
  else
  {
    Status[0] = "0";
  }

  //  Udp.beginPacket(SERVER_IP, localPort );
  //  Udp.print(Status[0] + "," + Status[1] + "," + Status[2]+ "," + Status[3]);
  //  Udp.endPacket();

  Udp.beginPacket(SERVER_IP, localPort );
  Udp.print("A");
  Udp.print(A);
  Udp.print(" ");
  Udp.print(Status[0]);

  Udp.endPacket();

  //  Serial.println(Status[0] + "," + Status[1] + "," + Status[2] + "," + Status[3]);
  Serial.println(Status[0]);

  delay(50);
}
