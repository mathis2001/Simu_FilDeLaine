int pwm1_pin = 10;
int pwm2_pin = 11;
int pwm2,pwm1;
int pot,map_pot;
int palo,map_palo;
int diff;

void setup() {
  Serial.begin(9600);
  pinMode (pwm1_pin, OUTPUT);
  pinMode (pwm2_pin, OUTPUT);
  analogWrite(pwm1_pin,0);
  analogWrite(pwm2_pin,0);
}

void loop() {
  pot = analogRead(A0);
  palo = analogRead(A1);
  Serial.print("manche:"+String(pot));
  Serial.print(" | palo:"+String(palo));
  map_pot =  map(pot, 400, 620, 0, 255);
  map_palo = map(palo, 275, 723, 255, 0);
  diff=map_pot-map_palo;
  Serial.print(" | diff:"+String(diff));
  pwm1 = 127 + diff/2;
  pwm2 = 127 - diff/2;
  if(pwm1<0)
    pwm1=0;
  if(pwm1>255)
    pwm1=255;
   if(pwm2<0)
    pwm2=0;
  if(pwm2>255)
    pwm2=255;
  Serial.println(" | pwm1:"+String(pwm1)+" | pwm2:"+String(pwm2));
  analogWrite(pwm1_pin,pwm1);
  analogWrite(pwm2_pin,pwm2);
  delay(100);
  

}
