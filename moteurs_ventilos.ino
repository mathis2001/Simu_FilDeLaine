int pwm_pin = 10;
int pwm2_pin = 11;
int pwm = 0;

void setup() {
  pinMode (pwm_pin, OUTPUT);
  pinMode (pwm2_pin, OUTPUT);
  analogWrite(pwm_pin,pwm);
  analogWrite(pwm2_pin,pwm);
  Serial.begin(9600);
}

void loop() {
  
  while(pwm <=255){
    pwm = pwm+5;
    Serial.println(pwm);
    if (pwm >= 255) {
      pwm = 0;
      analogWrite(pwm_pin, pwm);
      analogWrite(pwm2_pin,pwm);
      delay(5000);
    }
    else{
      analogWrite(pwm_pin, pwm);
      analogWrite(pwm2_pin, pwm);
    }
    
    delay(100);
  }
  


}
