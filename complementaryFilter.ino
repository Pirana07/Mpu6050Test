#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  Wire.beginTransmission(0x68);
  Wire.write(0x1C); 
  Wire.write(0x10); 
  Wire.endTransmission(true);

  Wire.beginTransmission(0x68);
  Wire.write(0x1B); 
  Wire.write(0x08); 
  Wire.endTransmission(true);

  Serial.println("MPU6050 initialized and calibrated");
}

void loop() {
  mpu6050.update();

  // print angles using complementry filter
  Serial.print("Angle X: "); Serial.print(mpu6050.getAngleX());
  Serial.print("  Angle Y: "); Serial.print(mpu6050.getAngleY());
  Serial.print("  Angle Z: "); Serial.println(mpu6050.getAngleZ());

  delay(100);
}