int active = 0;
int i = 0;
int d = 5;

void setup() {
  //prueba alarma
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void siren(int a) {
  if (a == 1){
    for(i=700;i<800;i++){
      tone(2,i);
      delay(15);
    }
    for(i=800;i>700;i--){
      tone(2,i);
      delay(15);
    }
  }
  else{
    noTone(2);
  }
}

void blink(int a) {
  if (a == 1){
      digitalWrite(4, HIGH);
      delay(10);
      digitalWrite(4, LOW);
      delay(5);
  }
  else{
    digitalWrite(4, LOW);
  }
}

void loop() {
  int LDR = analogRead(A0);
  Serial.println(LDR);
  //500
  if(LDR < 900)
  {
    //digitalWrite(4, HIGH);
    siren(1);
    blink(1);
  }
  else
  {
    //digitalWrite(4, LOW);
    siren(0);
    blink(0);
  }
}
