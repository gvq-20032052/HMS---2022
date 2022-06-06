void setup() {
  //prueba alarma
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int LDR = analogRead(A0);
  Serial.println(LDR);
  //500
  if(LDR < 900)
  {
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(4, LOW);
  }
}
