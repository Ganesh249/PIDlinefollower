//leftmotor
const int en1 = 9;
const int lmp = 2;
const int lmn = 3;

//Rightmotor
const int en2 = 10;
const int rmp = 5;
const int rmn = 4;

const int maxspeed = 255;

void setup() {
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(en1,OUTPUT);

  pinMode(rmn,OUTPUT);
  pinMode(rmp,OUTPUT);
  pinMode(en2,OUTPUT);

  Serial.begin(9600);

}

void loop(){
  for (int i = 0;i<10;i++){
    Serial.println("forward");
    analogWrite(en1,maxspeed);
    analogWrite(en2,maxspeed);
    forward();
    

    delay(3000);

    Serial.println("Backward");
    analogWrite(en1,maxspeed);
    analogWrite(en2,maxspeed);
    backward();
    delay(3000);
    
  }
}

void forward(){
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW);
}
void backward(){
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  digitalWrite(rmp,LOW);
  digitalWrite(rmn,HIGH);
}
