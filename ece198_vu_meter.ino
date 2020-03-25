int mic_voltage = 0;
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int bright_Pin = A2;
int brightness;
  void setup() {
    pinMode(A0, INPUT);
    pinMode(bright_Pin, INPUT);
    Serial.begin(9600);
    // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
    // Any other board, you can remove this part (but no harm leaving it):
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
     clock_prescale_set(clock_div_1);
    #endif
    // END of Trinket-specific code.

    pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  }
  int previousCounter = 0;  
  void loop() {
    pixels.clear(); // Set all pixel colors to 'off'
    int mic_voltage = analogRead(A0);
    Serial.println(mic_voltage);
    int value = mic_voltage - 504;
    int counter = 0;
    while (value > 0)
    {
      value = value - 1;
      if (value < 0)
      {
        /*pixels.setPixelColor(counter, pixels.Color(3, 3, 3));
          pixels.show();
        */
        break;
      }
      counter++;
    }
    fade(previousCounter,counter);
    previousCounter = counter;
  delay(100);
  
  

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
//for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

     //pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
//pixels.setPixelColor(i, pixels.Color(10, 10, 10));

//pixels.show();   // Send the updated pixel colors to the hardware.

//delay(DELAYVAL); // Pause before next pass through loop
//}
}

void fade(int previousCounter, int counter)
{
  brightness = map(analogRead(bright_Pin), 0, 1023, 0, 255);
  if(previousCounter > counter)
  {
     for(int i = 0; i < counter; i++)
     {
        pixels.setPixelColor(i, pixels.Color(3,3,3));
        pixels.show();
     }
     while(previousCounter > counter)
     {
          pixels.setPixelColor(previousCounter, pixels.Color(0,0,0));
        
        pixels.show();
        previousCounter--;
        delay(10);
        
     }
  }
  else if(previousCounter < counter)
  {
     for(int i = 0; i < previousCounter; i++)
     {
        pixels.setPixelColor(i, pixels.Color(3,3,3));
        pixels.show();
     }
    while(previousCounter < counter)
    {
      pixels.setPixelColor(previousCounter, pixels.Color(10,3,3));
      pixels.show();
      previousCounter++;
      delay(10);
      
    }
  }
}
