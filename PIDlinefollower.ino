
//leftmotor
#define en1 9
#define lmp 2
#define lmn 3

//Rightmotor
#define en2 10
#define rmp 5
#define rmn 4

int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;
int lfspeed = 255;

float Kp = 0;
float Kd = 0;
float Ki = 0 ;

int minValues[6], maxValues[6], threshold[6];

void calibrate();

void setup() {
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(en1,OUTPUT);

  pinMode(rmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(en2,OUTPUT);

  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);

  Serial.begin(9600);
}
void loop(){
    while(digitalRead(11)) {}
    Serial.println("Calibrating");
    delay(1000);
    calibrate();

}
void drivemotor(int motor, int speed)
{
  int pin1, pin2;

  if (motor == 1) {
    pin1 = lmp;
    pin2 = lmn;
    analogWrite(en1, speed);
  } else {
    pin1 = rmp;
    pin2 = rmn;
    analogWrite(en2, speed);
  }

  if (speed > 0) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  } else if (speed < 0) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  } else {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
}
void calibrate(){
  drivemotor(1,150);
  drivemotor(2,-150);
  for (int i = 0;i<5;i++){
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }
  for(int i = 0;i<3000;i++){
    for(int j = 0;j<5;j++){
      if (analogRead(j) < minValues[j])
      {
        minValues[j] = analogRead(j);
      }
      if (analogRead(j) > maxValues[j])
      {
        maxValues[j] = analogRead(j);
      }
    }
  }
  for ( int i = 0; i < 5; i++){
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    Serial.print(threshold[i]);
    Serial.print("   ");
  }
  Serial.println();

  drivemotor(1,0);
  drivemotor(2,0);
}

