#define trig 9
#define echo 10
void setup() {
  pinMode(3, OUTPUT);//motor
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(trig, OUTPUT); //trig
  pinMode(echo, INPUT); //echo
  Serial.begin(9600);
}

void loop() {
  trigger();
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  if (cm < 40) {
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
  }
}
void trigger() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}
