#define analog0 0
#define led1 9
#define led2 10
#define led3 11
const int buttonPin = 2; // the number of the pushbutton pin
int analogvalue = 0 ;
int buttonState; // the current reading from the input pin
int lastButtonState = HIGH; // the previous reading from the input pin
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers
int mode= 0 ;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600) ;
Serial.println("Program Start") ;
pinMode(buttonPin, INPUT);
}

void loop() {
int reading = digitalRead(buttonPin);
if (reading != lastButtonState) 
{
// reset the debouncing timer
lastDebounceTime = millis();
}

if ((millis() - lastDebounceTime) > debounceDelay) 
{
// whatever the reading is at, it's been there for longer than the debounce
// delay, so take it as the actual current state:

// if the button state has changed:
if (reading != buttonState) 
{
buttonState = reading;

// only toggle the LED if the new button state is HIGH
if (buttonState == LOW)
{
//ledState = !ledState;
mode ++ ;
if (mode >2 )
{
mode = 0 ;
}
}
}
}



//--------------------------------
// put your main code here, to run repeatedly:
analogvalue = analogRead(analog0) ;
if(mode==0)
{
mode=0,led1=9 ;  
}  
if(mode==1)
{
mode=1,led2=10 ;  
} 
if(mode==2)
{
mode=2,led3=11 ;  
}   
analogWrite(led1,analogvalue /4) ;
//Serial.println(analogvalue) ;
// delay(200) ;
}
