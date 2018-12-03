#define analog0 0

int analogvalue = 0 ;

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600) ;
     Serial.println("Program Start")  ;
}

void loop() {
  // put your main code here, to run repeatedly:
      analogvalue = analogRead(analog0) ;
      Serial.println(analogvalue)  ;
      delay(500) ;
      
}
