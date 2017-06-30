#define UtrigPin 13
#define UechoPin 12
#define LtrigPin 11
#define LechoPin 10
#define motor 7
#define Ubuzzer 6
#define Lbuzzer 5
int incomingByte = 0;
long Uduration, Udistance,Ldistance,Lduration;
void setup()
{
pinMode(A0,INPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
digitalWrite(A2,HIGH);
digitalWrite(A1,LOW);
pinMode(UtrigPin, OUTPUT);
pinMode(UechoPin, INPUT);
pinMode(LtrigPin, OUTPUT);
pinMode(LechoPin, INPUT);
pinMode(motor, OUTPUT);
pinMode(Ubuzzer,OUTPUT);
pinMode(Lbuzzer,OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
 Serial.begin(9600);
}

void loop()

{

Udistance = SonarSensor(UtrigPin,UechoPin);
Ldistance = SonarSensor(LtrigPin,LechoPin);
//
Serial.print("IR");
Serial.println(analogRead(A0));

Serial.print("Upper");
Serial.println(Udistance);

Serial.print("Lower");
Serial.println(Ldistance);
//
digitalWrite(motor,LOW);
digitalWrite(Ubuzzer,LOW);
digitalWrite(Lbuzzer,LOW);
digitalWrite(LED_BUILTIN, LOW);

if(Udistance!=0 || Ldistance!=0){
if(Udistance-Ldistance <= 70 && Udistance-Ldistance >=20){
 digitalWrite(motor,HIGH);
  delay(200);
  digitalWrite(motor,LOW);
}
else{  if(Udistance < 50)
  {
    digitalWrite(Ubuzzer,HIGH);
    digitalWrite(Lbuzzer,HIGH);
    delay(200);
    digitalWrite(Ubuzzer,LOW);
    digitalWrite(Lbuzzer,LOW);
    
  }
 else{  if(Udistance < 70 && Udistance >=50)
  { 
    digitalWrite(Ubuzzer,HIGH);
    digitalWrite(Lbuzzer,HIGH);
    delay(60);
    digitalWrite(Ubuzzer,LOW);
    digitalWrite(Lbuzzer,LOW);
    delay(20);
    digitalWrite(Ubuzzer,HIGH);
    digitalWrite(Lbuzzer,HIGH);
    delay(90);
    digitalWrite(Ubuzzer,LOW);
    digitalWrite(Lbuzzer,LOW);
    
  }
   // digitalWrite(Lbuzzer,HIGH);
  else{ if(Udistance < 100 && Udistance >=70){
    digitalWrite(Ubuzzer,HIGH);
    delay(150);
    digitalWrite(Ubuzzer,LOW);
   }
 else{ if(Udistance < 150 && Udistance >= 100){
   digitalWrite(Ubuzzer,HIGH);
    delay(40);
    digitalWrite(Ubuzzer,LOW);
    }
    //////////////////////////////////////////////////////

   
 }
  }
 }//
}//first else close//
}// not zero if close//
 if(analogRead(A0) > 500){
    digitalWrite(motor,HIGH);
    digitalWrite(Ubuzzer,HIGH);
    digitalWrite(Lbuzzer,HIGH);
    delay(200);
     }
delay(10);
}
int SonarSensor(int trigPin,int echoPin)
{
long duration,distance;  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
return distance;
}
