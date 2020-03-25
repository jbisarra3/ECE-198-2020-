
#include <LedControl.h>
int strobePin = 6;
int resetPin = 9;
int outPin = A3;
int level[7];


const int DATA = 2;
const int CLOCK = 3;
const int CHIP_SET = 4;
const int DEVICE_NUMBER = 1;
LedControl lc=LedControl(DATA, CLOCK, CHIP_SET, DEVICE_NUMBER);

void setup() {

   lc.shutdown(0,false); //Turn on Matrix
  lc.setIntensity(0,8); //Set Brightness
  lc.clearDisplay(0); //Clear Display
  
  // put your setup code here, to run once:

  Serial.begin(115200);
  pinMode (strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(outPin, INPUT);

  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin,LOW);
  delay(1);

  digitalWrite(resetPin, HIGH);
  delay(1);
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);
  delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int mic_voltage = analogRead(A5);
//  Serial.println(mic_voltage);
//  delay(10);

  digitalWrite(resetPin, HIGH);
  delay(1);
  digitalWrite(resetPin, LOW);

  for (int i = 0; i < 7; i++){
    digitalWrite(strobePin, LOW);
    delayMicroseconds(1000);
    level[i] = analogRead(outPin);
    digitalWrite(strobePin, HIGH);
    delayMicroseconds(1000);
  }

/*  for(int i = 0; i < 8; i++)
  {
    int lights[] = {0,1,3,7,15,31,63,127,255};
    if (level[i] > 500){
      lc.setColumn(0,i,lights[7]);
    } 
    else {
      lc.setRow(0, i, lights[0]);
    }
  }
*/
    for(int i = 7; i >= 0; i--)
    {
      int lights[] = {0,1,3,7,15,31,63,127,255};
      int currentLevel = level[i];
      int threshold = 128;
      int ledLevel = 0;
      while(currentLevel > 128)
      {
        currentLevel = currentLevel - 90;
        lc.setLed(0,i,ledLevel,1);
        ledLevel++; 
      }
      
    }
    Serial.println();
    delay(100);
    lc.clearDisplay(0);

  for (int i = 0; i < 7; i++){
   Serial.print(level[i]);
   Serial.print("  ");
  }

  Serial.println();

}
