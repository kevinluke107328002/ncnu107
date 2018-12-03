const int  buttonPin = 2;
int ledPin = 9;
int analog0 = 0;
int val = 0 ; 
int dt = 0; 
int mode= 0 ;
int buttonState = 0;
int lastButtonState = 0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) 
    {
      if (buttonState == LOW) 
      {     
        mode++;
        if (mode > 2 )
           {
            mode = 0 ; 
           }
        if (mode == 0) {ledPin = 9;}
        if (mode == 1) {ledPin = 10;}
        if (mode == 2) {ledPin = 11;}
        analogWrite(9,0);
        analogWrite(10,0);
        analogWrite(11,0);
             
      }
      delay(50);
    }
    
    lastButtonState = buttonState;
   
    val = analogRead(analog0); //val = 0 ~ 1023
    dt = val / 4 ;
    analogWrite(ledPin, dt);
    
    //印出數值檢查執行成果
    Serial.print("ledPin = ");
    Serial.print(ledPin);
    Serial.print(";   mode = ");
    Serial.print(mode);
    Serial.print(";   val = ");
    Serial.print(val);
    Serial.print(";   dt = ");
    Serial.println(dt);
}
