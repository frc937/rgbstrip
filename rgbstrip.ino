const int r=5;
const int g=6;
const int b=3;

void setup() {
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
}

void loop() {
  analogWrite(r,255);
  analogWrite(g,255);
  analogWrite(b,-255);
}
