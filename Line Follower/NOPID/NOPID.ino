//MotorDriver pins
#define ENA 6
#define ENB 11
#define IN1 7
#define IN2 8
#define IN3 12
#define IN4 13

//Ir
#define IR1 5
#define IR2 4
#define IR3 3
#define IR4 2

int Sinput;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //ENA 1--backward 2-forward ENB 3-backward 4-forward

  sensor();


}

void sensor()
{
  int IA = digitalRead(IR1);
  int IB = digitalRead(IR2);
  int IC = digitalRead(IR3);
  int ID = digitalRead(IR4);

  if (IA == 0 && IB == 1 && IC == 1 && ID == 0){ //ideal
    forward();
  }
  else if (IA == 1 && IB == 0 && IC == 0 && ID == 0){ //left turn
    nrightturn();
  }
  else if (IA == 1 && IB == 1 && IC == 0 && ID == 0){
    nrightturn();
  }
  else if (IA == 1 && IB == 1 && IC == 1 && ID == 0){//leftturn
    rightturn();
  }
  else if (IA == 0 && IB == 0 && IC == 0 && ID == 1){
    nleftturn();
  }
  else if (IA == 0 && IB == 0 && IC == 1 && ID == 1){
    nleftturn();
  }  
  else if (IA == 0 && IB == 1 && IC == 1 && ID == 1){
    leftturn();
  }
  else if (IA == 1 && IB == 1 && IC == 1 && ID == 1){
    nleftturn();
  }
  else if (IA == 0 && IB == 0 && IC == 0 && ID == 0){
    Uturn();
  }
}

void Uturn()
{

  analogWrite(ENA, 30);
  analogWrite(ENB, 30);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);


}
void forward()
{

  analogWrite(ENA, 70);
  analogWrite(ENB, 70);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void backward()
{

  analogWrite(ENA, 40);
  analogWrite(ENB, 40);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void leftturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward
  analogWrite(ENA, 20);
  analogWrite(ENB, 40);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}

void rightturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward
  analogWrite(ENA, 40);
  analogWrite(ENB, 20);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void nrightturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward  
  analogWrite(ENA, 70);
  analogWrite(ENB, 30);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
}

void nleftturn()
{
//ENA 1--backward 2-forward ENB 3-backward 4-forward
  analogWrite(ENA, 30);
  analogWrite(ENB, 70);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}