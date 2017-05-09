#include <Wire.h>
#include <LIS3MDL.h>
#include <LSM303.h>

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
  switch (compass.getDeviceType())
  {
    case LSM303::device_D:
      compass.writeReg(LSM303::CTRL2, 0x18); // 8 g full scale: AFS = 011
      break;
    case LSM303::device_DLHC:
      compass.writeReg(LSM303::CTRL_REG4_A, 0x28); // 8 g full scale: FS = 10; high resolution output mode
      break;
    default: // DLM, DLH
      compass.writeReg(LSM303::CTRL_REG4_A, 0x30); // 8 g full scale: FS = 11
  }

}

void Read_Compass()
{

  compass.readMag();

  magnetom_x = SENSOR_SIGN[6] * compass.m.x;
  magnetom_y = SENSOR_SIGN[7] * compass.m.y;
  magnetom_z = SENSOR_SIGN[8] * compass.m.z;
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
  Serial.println();
  delay(500);
}
