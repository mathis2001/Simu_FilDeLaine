int pwm_pin = 10;
int pwm2_pin = 11;
int pwm2 = 0;
int pwm = 0;
int pot,pot2;
int palo;

void setup() {
  Serial.begin(9600);
  pinMode (pwm_pin, OUTPUT);
  pinMode (pwm2_pin, OUTPUT);
  analogWrite(pwm_pin,pwm);
  analogWrite(pwm2_pin, pwm2);

}

void loop() {
  pot = analogRead(A0);
  palo = analogRead(A1);
  Serial.print(String(pot)+" - ");
  pot2 =  map(pot, 400, 625, 255, 0);
  pot = map(pot, 400, 625, 0, 255);
  Serial.println(pot);
  pwm = pot;
  pwm2 = pot2;
  analogWrite(pwm_pin,pwm);
  analogWrite(pwm2_pin,pwm2);
  delay(100);
  

}
