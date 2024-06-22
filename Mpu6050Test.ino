//Stem Project about Gyroscope and accelerometer and complementary filter... 
//mpu6050 Test on x axis

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip"); // error
    while (1) { delay(10); }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  Serial.println("MPU6050 initialized"); //succses
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  Serial.print(a.acceleration.x); //accelerometer x
  Serial.print(" ");
  Serial.println(g.gyro.x); //Gyroscope x

  delay(500);
}
