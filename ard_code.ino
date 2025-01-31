// Pins for sensor
int echopin = 0   ;  // Define pin numbers for echopin and trigpin (assumed 6 and 7)
int trigpin = 6 ;

// Pins for motor
int ForwardRotate_LeftMotor = 2;
int BackwardRotate_LeftMotor = 3;
int ForwardRotate_RightMotor = 4;
int BackwardRotate_RightMotor = 5;


// Pins for LCD display
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 8, 9, 10, 11);

long duration;
int distance;

void setup() {
  pinMode(echopin, INPUT);        // Correct pinMode for echopin (INPUT)
  pinMode(trigpin, OUTPUT);       // Correct pinMode for trigpin (OUTPUT)
  pinMode(ForwardRotate_LeftMotor, OUTPUT);
  pinMode(BackwardRotate_LeftMotor, OUTPUT);
  pinMode(ForwardRotate_RightMotor, OUTPUT);
  pinMode(BackwardRotate_RightMotor, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(1, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);          // Corrected `delayMicroSeconds` to `delayMicroseconds`

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);  // Corrected variable name `Duration` to `duration`
  distance = duration * 0.034/2 ;        // Fixed `^` (bitwise XOR) to `*` for multiplication

 /* lcd.setCursor(0, 0);           // Corrected `setcursor` to `setCursor`
  lcd.print("Distance: ");
  lcd.setCursor(9, 0);
  lcd.println(distance);      */     // Fixed `Distance` to `distance`

    //if (distance > 500) {
    // Rotate in opposite direction
    lcd.clear();
    lcd.setCursor(0 , 1);
    lcd.print("Moving Back");
    lcd.setCursor(0, 0);
    lcd.print(distance);

  
    int(BackwardRotate_LeftMotor, HIGH);
    digitalWrite(BackwardRotate_RightMotor, HIGH);

    digitalWrite(ForwardRotate_LeftMotor, LOW);
    digitalWrite(ForwardRotate_RightMotor, LOW);

     
   

     if (distance < 500) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Moving Left");
    lcd.setCursor(0, 0);
    lcd.print(distance);

    // Move in left/ right direction
    digitalWrite(BackwardRotate_LeftMotor, HIGH);
    digitalWrite(BackwardRotate_RightMotor, LOW);
  

    digitalWrite(ForwardRotate_LeftMotor, HIGH);
    digitalWrite(ForwardRotate_RightMotor, LOW);
    analogWrite(7 , 200); // Added missing semicolon
    delay(1000);
  } else {
    // Moving forward
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Moving Forward");
    lcd.setCursor(0, 0);
    lcd.print(distance);


    digitalWrite(BackwardRotate_LeftMotor, LOW);
    digitalWrite(BackwardRotate_RightMotor, HIGH);
    analogWrite(1 , 200);
    digitalWrite(ForwardRotate_LeftMotor, HIGH);
    digitalWrite(ForwardRotate_RightMotor, LOW);
    analogWrite(7 , 200); // Added missing semicolon
    delay(1000);
      }

} 

  

