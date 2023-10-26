#include <WiFi.h>
#include <TinyGPS++.h>
#include "ThingSpeak.h"
#include "TM1637.h"
#include "HelloSensor.h"

#define Rload         (10)
#define ADC_BIT_RESU  (12)
#define space1        (12)
#define space2        (14)

#define CLK (18)
#define DIO (15)

TM1637 tm1637(CLK,DIO);

HelloSensor MQ(ADC_BIT_RESU, Rload, space1);
HelloSensor other(ADC_BIT_RESU, Rload, space2);

HardwareSerial neogps(1); 
TinyGPSPlus gps;

int value1, value2, value3, value4, value5, value6, value7, sec;  
int gpscontrol = 0;

String latitude, longitude;

const char* ssid = "REPLACE_WİTH_YOUR_SSID";  // VINNWiFi_80B6
const char* password = "REPLACE_WİTH_YOUR_PASSWORD"; // 92030887
WiFiClient  client;

unsigned long int hello2 = 2;
unsigned long int hello1 = 1;

static const char * myWriteAPIKey1 = "J2UEIZSZTC5568NM";
static const char * myWriteAPIKey2 = "ZVZ3UYIV4PTYA6XP";

unsigned long int lastTime = 0;
unsigned long int timerDelay = 15000;

void setup() {
  Serial.begin(115200);  
  MQ.begin();
  other.begin();
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
  neogps.begin(9600, SERIAL_8N1, 4, 2); 
  WiFi.mode(WIFI_STA);  Serial.println("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
  ThingSpeak.begin(client);  

}

void loop() {
sec = map(analogRead(13),0,8191,1,13);
switch(sec){
case (1):
{
MQ135doing();
}
break;
case (2):
{
normal();
MQ.MQ2calibrate();
value1 = MQ.MQ2DataH2();
value2 = MQ.MQ2DataH2();
value3 = MQ.MQ2DataLPG();
value4 = MQ.MQ2DataCO();
value5 = MQ.MQ2DataAlcohol();
value6 = MQ.MQ2DataPropane();  
value7 = MQ.MQ2DataAir();
}
break;
case (3):
{
normal();
MQ.MQ3calibrate();
value1 = MQ.MQ3DataLPG();
value2 = MQ.MQ3DataCH4();
value3 = MQ.MQ3DataCO();
value4 = MQ.MQ3DataAlcohol();
value5 = MQ.MQ3DataBenzene();
value6 = MQ.MQ3DataHexane();  
value7 = MQ.MQ3DataAir();
}
break;
case (4):
{
normal();
MQ.MQ4calibrate();
value1 = MQ.MQ4DataLPG();
value2 = MQ.MQ4DataCH4();
value3 = MQ.MQ4DataCO();
value4 = MQ.MQ4DataAlcohol();
value5 = MQ.MQ4DataSmoke();
value6 = MQ.MQ4DataAir();
value7 = 0; 
}
break;
case (5):
{
normal();
MQ.MQ5calibrate();
value1 = MQ.MQ5DataH2();
value2 = MQ.MQ5DataLPG();
value3 = MQ.MQ5DataCH4();
value4 = MQ.MQ5DataCO();
value5 = MQ.MQ5DataAlcohol();
value6 = MQ.MQ5DataAir();
value7 = 0;
}
break;
case (6):
{
normal();
MQ.MQ6calibrate();
value1 = MQ.MQ6DataH2();
value2 = MQ.MQ6DataLPG();
value3 = MQ.MQ6DataCH4();
value4 = MQ.MQ6DataCO();
value5 = MQ.MQ6DataAlcohol();
value6 = MQ.MQ6DataAir();
value7 = 0;
}
break;
case (7):
{
normal();
MQ.MQ7calibrate();
value1 = MQ.MQ7DataH2();
value2 = MQ.MQ7DataLPG();
value3 = MQ.MQ7DataCH4();
value4 = MQ.MQ7DataCO();
value5 = MQ.MQ7DataAlcohol();
value6 = MQ.MQ7DataAir();
value7 = 0;
}
break;
case (8):
{
normal();
MQ.MQ8calibrate();
value1 = MQ.MQ8DataH2();
value2 = MQ.MQ8DataLPG();
value3 = MQ.MQ8DataCH4();
value4 = MQ.MQ8DataCO();
value5 = MQ.MQ8DataAlcohol();
value6 = MQ.MQ8DataAir();
value7 = 0;
}
break;
case (9):
{
normal();
MQ.MQ9calibrate();
value1 = MQ.MQ9DataLPG();
value2 = MQ.MQ9DataCH4();
value3 = MQ.MQ9DataCO();
value4 = MQ.MQ9DataAir();
value5 = value6 = value7 = 0;
}
break;
case (10):
{
tm1637.display(3,1);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.MQ131calibrate();
value1 = MQ.MQ131DataNOx();
value1 = MQ.MQ131DataCL2();
value1 = MQ.MQ131DataO3();
value4 = MQ.MQ131DataAir();
value5 = value6 = value7 = 0;
}
break;
case (11):
{
tm1637.display(3,6);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.MQ136calibrate();
value1 = MQ.MQ136DataH2S();
value1 = MQ.MQ136DataNH4();
value1 = MQ.MQ136DataCO();
value4 = value5 = value6 = value7 = 0;
}
break;
case (12):
{
tm1637.display(3,10);
tm1637.display(2,3);
tm1637.display(1,0);
tm1637.display(0,3);
MQ.MQ303Acalibrate();
value1 = MQ.MQ303ADataIso();
value1 = MQ.MQ303ADataHyd();
value1 = MQ.MQ303ADataEthanol();
value4 = MQ.MQ303ADataAir();
value5 = value6 = value7 = 0;
}
break;
case (13):
{
tm1637.display(3,10);
tm1637.display(2,9);
tm1637.display(1,0);
tm1637.display(0,3);
MQ.MQ309Acalibrate();
value1 = MQ.MQ309ADataH2();
value1 = MQ.MQ309ADataCH4();
value1 = MQ.MQ309ADataCO();
value1 = MQ.MQ309ADataAlcohol();
value5 = MQ.MQ309ADataAir();
value6 = value7 = 0;

}
break;
default:
{
sec = 1;
MQ135doing();
}
break;
}

  if (neogps.available()) {
    char c = neogps.read();
    if (gps.encode(c)) {
      if (gps.location.isValid()) {
       latitude  = (gps.location.lat(), 6) * pow(10,6); 
       longitude = (gps.location.lng(), 6) * pow(10,6); 
       gpscontrol = 1;
      }
    }
  }
  
  if ((millis() - lastTime) > timerDelay) {

    ThingSpeak.setField(1, value1);
    ThingSpeak.setField(2, value2);
    ThingSpeak.setField(3, value3);
    ThingSpeak.setField(4, value4);
    ThingSpeak.setField(5, value5);
    ThingSpeak.setField(6, value6);
    ThingSpeak.setField(7, value7);
    ThingSpeak.setField(8, sec);
  int a = ThingSpeak.writeFields(hello1, myWriteAPIKey1);   
    ThingSpeak.setField(5, MQ.MQData100());    
    ThingSpeak.setField(6, other.MQData100());   
    if (gpscontrol == 1){ 
    ThingSpeak.setField(7, latitude);
    ThingSpeak.setField(8, longitude);
    }
    int b = ThingSpeak.writeFields(hello2, myWriteAPIKey2);
    lastTime = millis();
    gpscontrol = 0;
  }
}

void normal(){
tm1637.display(3,sec);
tm1637.display(2,sec);
tm1637.display(1,sec);
tm1637.display(0,sec);
}

void MQ135doing(){
tm1637.display(3,5);
tm1637.display(2,3);
tm1637.display(1,1);
tm1637.display(0,0);
MQ.MQ135calibrate();
value1 = MQ.MQ135DataCO();
value2 = MQ.MQ135DataAlcohol();
value3 = MQ.MQ135DataCO2();
value4 = MQ.MQ135DataToluen();
value5 = MQ.MQ135DataNH4();
value6 = MQ.MQ135DataAceton();
value7 = MQ.MQ135DataAir();
}

// GPS : [GND --> GND] [TX --> D4] [RX --> D2] [VCC --> 3.3V]
// TfLuna Lidar: [VCC --> 5V] [SDA --> D21] [SCL --> D22] [GND --> GND] [I2C --> GND] 
// MQ-X: [PIN --> D12] [GND --> GND] [VCC --> 3.3V]
// Other Sensor: [PIN --> D14] [GND --> GND] [VCC --> 3.3V]
// Potentiometer: [PIN --> D13] [GND --> GND] [VCC --> 3.3V]
// TM1637: [CLK --> D18] [DIO --> D15] [VCC --> 5V] [GND --> GND]
