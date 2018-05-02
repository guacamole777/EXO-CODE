int in = 4;
int out = 3;


void setup() {
  Serial.begin(9600);
  pinMode(in, INPUT);
  analogWrite(out, 255);
  // put your setup code here, to run once:

}
int rate = 0;
char x = ' ';
void loop() {
  int a = digitalRead(in);
  Serial.println(a);
  
  if(Serial.available() > 0){
     x = Serial.read();
     Serial.print(x);
     rate = int(x) - '0';
     Serial.print("The rate is: "); Serial.println(rate);
     analogWrite(out, map(rate, 0, 9, 0, 255));
  }
  
  // put your main code here, to run repeatedly:

}
