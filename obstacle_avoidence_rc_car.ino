// --> MOTOR PINS <-- 
int Motor_Right_Positive =  3;
int Motor_Right_Negative =  5;
int Motor_Left_Positive  =  6;
int Motor_Left_Negative  =  9;
int left_IR = A0;
int right_IR = A1;
int IRL;
int IRR;


void setup() {
  
  pinMode(Motor_Right_Positive, OUTPUT);
  pinMode(Motor_Right_Negative, OUTPUT);
  pinMode(Motor_Left_Positive, OUTPUT);
  pinMode(Motor_Left_Negative, OUTPUT);
  pinMode(left_IR, INPUT);
  pinMode(right_IR, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  
  IRL = !digitalRead(left_IR);
  IRR = !digitalRead(right_IR);
  Serial.print(IRL);
  Serial.print("\t");
  Serial.print(IRR);
  Serial.println();


  if(IRL == 0 && IRR == 0){ forward();}
  if(IRL == 1 && IRR == 0){ rightback();}
  if(IRL == 0 && IRR == 1){ leftback();}
  if(IRL == 1 && IRR == 1){ leftback();}
  
}

void forward()
{
  digitalWrite(Motor_Right_Positive,HIGH);
  analogWrite(Motor_Right_Negative, 160);
  digitalWrite(Motor_Left_Positive,HIGH);
  analogWrite(Motor_Left_Negative, 168);
}

void rightback() 
{
  digitalWrite(Motor_Right_Negative,HIGH);
  analogWrite(Motor_Right_Positive, 160);
  digitalWrite(Motor_Left_Positive,HIGH);
  analogWrite(Motor_Left_Negative, 255);
 }
void leftback() 
{
  analogWrite(Motor_Right_Positive, 255);
  digitalWrite(Motor_Right_Negative, HIGH);
  analogWrite(Motor_Left_Positive,160);
  digitalWrite(Motor_Left_Negative, HIGH);

}
