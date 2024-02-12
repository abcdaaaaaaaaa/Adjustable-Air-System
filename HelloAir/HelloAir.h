#ifndef HelloAir_h
#define HelloAir_h

#include "Arduino.h"

class HelloSensor
{
  private:
  float _ratio;
  float _percentile;
  int _bitadc;
  float _Rload;
  byte _pin;
  float _RSRo;
  float _va;
  float _vb;
  float limitValue10000(float Sensorvalue);
  float limitValue7000(float Sensorvalue);
  float limitValue4000(float Sensorvalue);
  float limitValue3000(float Sensorvalue);
  float limitValue1000(float Sensorvalue);
  float limitValue500(float Sensorvalue);
  float limitValue200(float Sensorvalue);
  float limitValue100(float Sensorvalue);
  public:
  HelloSensor(int bitadc, byte pin);
  void begin();
  void setRL(float Rload);
  void dangerousPer(float per);
  void RSRoMQAir(float RSRo);
  int MQData100();
  int read();
  float readValue();
  //int MQ2DataAir();
  int MQ3DataAir();
  int MQ4DataAir();
  int MQ5DataAir();
  int MQ6DataAir();
  int MQ7DataAir();
  int MQ8DataAir();
  int MQ9DataAir();
  int MQ131DataAir();
  int MQ135DataAir();
  int MQ136DataAir();
  int MQ137DataAir();
  //float MQ303ADataAir();
  int MQ303ADataAir();
  int MQ309ADataAir();
  float MQ2DataH2();
  float MQ2DataLPG();
  float MQ2DataCO();
  float MQ2DataAlcohol();
  float MQ2DataPropane();
  float MQ2DataCH4();
  float MQ2Datasmoke();
  float MQ3DataLPG();
  float MQ3DataCH4();
  float MQ3DataCO();
  float MQ3DataAlcohol();
  float MQ3DataBenzene();
  float MQ3DataHexane();
  float MQ4DataLPG();
  float MQ4DataCH4();
  float MQ4DataCO();
  float MQ4DataAlcohol();
  float MQ4DataSmoke();
  float MQ4DataH2();
  float MQ5DataH2();
  float MQ5DataLPG();
  float MQ5DataCH4();
  float MQ5DataCO();
  float MQ5DataAlcohol();
  float MQ6DataH2();
  float MQ6DataLPG();
  float MQ6DataCH4();
  float MQ6DataCO();
  float MQ6DataAlcohol();
  float MQ7DataH2();
  float MQ7DataLPG();
  float MQ7DataCH4();
  float MQ7DataCO();
  float MQ7DataAlcohol();
  float MQ8DataH2();
  float MQ8DataLPG();
  float MQ8DataCH4();
  float MQ8DataCO();
  float MQ8DataAlcohol();
  float MQ9DataLPG();
  float MQ9DataCH4();
  float MQ9DataCO();
  float MQ131DataNOx();
  float MQ131DataCL2();
  float MQ131DataO3();
  float MQ135DataCO();
  float MQ135DataAlcohol();
  float MQ135DataCO2();
  float MQ135DataToluen();
  float MQ135DataNH4();
  float MQ135DataAceton();
  float MQ136DataH2S();
  float MQ136DataNH4();
  float MQ136DataCO();
  float MQ137DataCO();
  float MQ137DataEthanol();
  float MQ137DataNH3();
  float MQ303ADataIso();
  float MQ303ADataHyd();
  float MQ303ADataEthanol();
  float MQ309ADataH2();
  float MQ309ADataCH4();
  float MQ309ADataCO();
  float MQ309ADataAlcohol();
  float MQ309ADataLowCO();
  float MQ309ADataSecondH2();
};

#endif
