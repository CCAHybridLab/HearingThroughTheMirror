
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET

#define NUMPIXELS 67 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);
int sensorPin=7;
boolean val =0;

void setup() {
pinMode(sensorPin, INPUT);

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  Serial.begin (9600);
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.
uint32_t color = 0xFFFFFF;      // 'On' color (starts red)
uint32_t black = 0x000000;      // 'On' color (starts red)
// int countNumber = 1000;
int countNumberSound = 0;

void loop() {
  val =digitalRead(sensorPin);
  
  Serial.println (val);
  // Serial.println (countNumber);
  // Serial.println (countNumberSound);
  if (val==0)
  {
    // begin count
    countNumberSound += 1;
    if (countNumberSound > 100)
    {
      /* code */
      countNumberSound = 100;
    }

  }else{
    countNumberSound -= 1;
    if (countNumberSound < -100)
    {
      /* code */
      countNumberSound = -100;
    }

  }


  if (countNumberSound > 30)
  {
    /* code */
    for (int i = 0; i < NUMPIXELS; ++i)
      {
        // strip.setPixelColor(i, 255, 255, 255);
        strip.setPixelColor(i, color);
      }        
      strip.show(); 
  }
  if (countNumberSound < -30)
  {
    /* code */
          for (int x = 0; x < NUMPIXELS; ++x){
        strip.setPixelColor(x, black);

      }
      strip.show(); 

  }


//   if (countNumber < 20) {
//       // countNumber = countNumber + 1;
//       for (int i = 0; i < NUMPIXELS; ++i)
//       {
//         // strip.setPixelColor(i, 255, 255, 255);
//         strip.setPixelColor(i, color);
//       }        
//       strip.show(); 
//       countNumber += 1;
//     }
// else {
//       for (int x = 0; x < NUMPIXELS; ++x){
//         strip.setPixelColor(x, black);

//       }
//       countNumberSound = 0;
//       strip.show(); 
//     }
  }

