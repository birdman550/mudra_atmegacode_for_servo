int servopin=2;
int pulse=1500;
int pulsecw=1415;
int pulseacw=1525;

void setup ()
{
  pinMode(servopin, OUTPUT);
  Serial.begin(9600);
  Serial.print("Bring it on!");
}

void loop ()
{
  static int current = 1;
  static int faceChange = 1;
  if ( Serial.available()) {
    int v = Serial.read();
    faceChange = nextChange(current,v);
//    run(1.6,1525);
    run((abs(faceChange)*1.6),1525);
    current = v;
  }
}
void run (float n, int pulse) {
  for (float i=1; i<=n; i+=0.10){
      digitalWrite(servopin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(servopin, LOW);
      Serial.println(i);
      delay(6);
      }
}

int nextChange(int current,int required) {
  int min1,min2;
  min1 = (current + 8 -  required)%8;
  min2 = required - current;
  return (abs(min1)<abs(min2))? min1: min2;
}
