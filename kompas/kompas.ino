#include <Wire.h>
#include <LIS3MDL.h>
#include <LSM303.h>
#include <math.h>
LIS3MDL mag;
LSM303 compass;
int magnetom_x;
int magnetom_y;
int magnetom_z;
int SENSOR_SIGN[9] = {1,1,1,-1,-1,-1,1,1,1};

void Accel_Init()
{

  compass.init();
  compass.enableDefault();
//  compass.m_max = (LSM303::vector<int16_t>){  780,   286,   778};
//  compass.m_min = (LSM303::vector<int16_t>){  -260,   -708,   -104};
  switch (compass.getDeviceType())
  {
    case LSM303::device_D:
  Serial.println("X1");    
      compass.writeReg(LSM303::CTRL2, 0x18); // 8 g full scale: AFS = 011
      break;
    case LSM303::device_DLHC:
    Serial.println("X2");    
      compass.writeReg(LSM303::CTRL_REG4_A, 0x28); // 8 g full scale: FS = 10; high resolution output mode
      compass.writeReg(0x01, 0x20); // 8 g full scale: FS = 10; high resolution output mode
      break;
    default: // DLM, DLH
      compass.writeReg(LSM303::CTRL_REG4_A, 0x30); // 8 g full scale: FS = 11
  }

}

void Read_Compass()
{

  compass.readMag();

  magnetom_x = compass.m.x-224;
  magnetom_y = compass.m.y+224;
  magnetom_z = compass.m.z;
  //Serial.println(compass.m.x);



Serial.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9800);
  Wire.begin();
  Serial.println("heh ho");
  Accel_Init();
}

void loop() {
  Read_Compass();
  Serial.println(magnetom_x);
  Serial.println(magnetom_y);
  Serial.println(magnetom_z);
  double arct = atan2((double)magnetom_y,(double)magnetom_x);
  
  Serial.println(arct* (180/M_PI));
  
  Serial.println();
  delay(500);
}  
