#define motorA_L 6
#define motorB_L 7
#define speed_L  5
#define motorA_R 4
#define motorB_R 2
#define speed_R  3
#define set_sw1 1
int leftSensor = A0;
int rightSensor = A4;

void setup() {
  Serial.begin(9600);
  pinMode (set_sw1, INPUT);
  pinMode (motorA_L, OUTPUT);
  pinMode (motorB_L, OUTPUT);
  pinMode (speed_L, OUTPUT);
  pinMode (motorA_R, OUTPUT);
  pinMode (motorB_R, OUTPUT);
  pinMode (speed_R, OUTPUT);
}

void forword(int SL, int SR)
{
  digitalWrite(motorA_L, LOW);// 0 มอเตอร์ซ้ายถอยหลัง
  digitalWrite(motorB_L, HIGH);// 1 มอเตอร์ซ้ายไปข้างหน้า
  analogWrite  (speed_L, SL);
  digitalWrite(motorA_R, HIGH);// 1 มอเตอร์ขวาไปข้างหน้า
  digitalWrite(motorB_R, LOW);// 0 มอเตอร์ขวาถอยหลัง
  analogWrite  (speed_R, SR);
}

void turnRight(int SL, int SR)
{
  digitalWrite(motorA_L, LOW);
  digitalWrite(motorB_L, HIGH);
  analogWrite(speed_L, SL);
  digitalWrite(motorA_R, LOW);
  digitalWrite(motorB_R, LOW);
  analogWrite(speed_R, SR);
}

void turnLeft(int SL, int SR)
{
  digitalWrite(motorA_L, LOW);
  digitalWrite(motorB_L, LOW);
  analogWrite(speed_L, SL);
  digitalWrite(motorA_R, HIGH);
  digitalWrite(motorB_R, LOW);
  analogWrite(speed_R, SR);
}

void Stop(int SL, int SR)
{
  digitalWrite(motorA_L, LOW);
  digitalWrite(motorB_L, LOW);
  analogWrite(speed_L, SL);
  digitalWrite(motorA_R, LOW);
  digitalWrite(motorB_R, LOW);
  analogWrite(speed_R, SR);
}


void loop() {
  Serial.println("Left Sensor : " + String(digitalRead(A0)) + 
  "\nRight Sensor : " + String(digitalRead(A4)));
  while (digitalRead(set_sw1) == 1); {
    if (digitalRead(leftSensor) == 1 && digitalRead(rightSensor) == 1){
      forword(60, 60);
    }

    if (digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 1){
      turnLeft(60, 100);
    }

    if (digitalRead(leftSensor) == 1 && digitalRead(rightSensor) == 0){
      turnRight(100, 60);
    }

    if (digitalRead(leftSensor) == 0 && digitalRead(rightSensor) == 0){
      Stop(0, 0);
    }
    
  }
}
