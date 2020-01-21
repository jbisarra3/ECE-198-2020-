const int LED = 4;
const int button = 8;
int buttonPress = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial. begin(9600); 
  pinMode (LED, OUTPUT);
  pinMode (button, INPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  buttonPress = digitalRead(button);
  if (buttonPress == HIGH)
  {
    Serial.print(buttonPress);
    digitalWrite (LED, HIGH);
  }
  else
  {
    digitalWrite (LED, LOW);
  }
  
}
