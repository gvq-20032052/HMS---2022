const int l1 = 5;
const int l2 = 6;
const int l3 = 7;

int active = 0;
int i = 0;
int d = 5;
int counter;

void setup() {
  //prueba alarma
  pinMode(2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
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
    for (counter = 0; counter < 5; ++counter) {
      digitalWrite (l1, HIGH);
      delay (50);
      digitalWrite (l2, HIGH);
      delay (100);
      digitalWrite (l1, LOW);
      delay (50);
      digitalWrite (l3, HIGH);
      delay (100);
      digitalWrite (l2, LOW);
      delay(50);
      digitalWrite (l3, LOW);
    }
  }
  else{
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
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
