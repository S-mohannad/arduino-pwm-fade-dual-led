int x=0;
void setup() {
pinMode(8,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(8,1);
}
void loop() {
analogWrite (10,x);
delay(150);
if (x<255) {x=x+5;}
else
{x=0; delay(300);
analogWrite (10,x);
delay(3000);}
}