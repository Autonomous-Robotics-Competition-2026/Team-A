#include <Servo.h>
Servo leftServo;
Servo rightServo;

#define LEFT_MOTOR_PIN 6
#define RIGHT_MOTOR_PIN 5
#define MIN_SERVO 0
#define MAX_SERVO 90
/***************************************************************/
void drive(int leftProportion, int rightProportion, float durationInSeconds)
{
  int leftPosition = map(leftProportion, -100, 100, MIN_SERVO, MAX_SERVO);
  int rightPosition = map(rightProportion, 100, -100, MIN_SERVO, MAX_SERVO);
  long durationInMs = durationInSeconds * 1000;
  
  leftServo.write(leftPosition);
  rightServo.write(rightPosition);
  delay(durationInMs);
}
/***************************************************************/
void setup() 
{
  Serial.begin(9600);
//  while (!Serial) { }  // Wait for serial connection to establish
  Serial.println("Setup started.");
  
  // Initialize the servo on pin 9.
  leftServo.attach(LEFT_MOTOR_PIN);
  leftServo.write(90);  // Start at a neutral position.
  rightServo.attach(RIGHT_MOTOR_PIN);
  rightServo.write(90);  // Start at a neutral position.
}
/***************************************************************/
void loop() 
{
  drive(50, -50, 0.5);
  drive(0, 0, 3);
}

