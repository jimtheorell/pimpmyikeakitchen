/*
  Pimp my IKEA micro
  
  circuit:
  - speaker on digital pin 8
  - speaker on digital pin 9
  - leds on digital pin 7
  - knapp on digital pin 2

  Jim Theorell
*/

#include "Tone.h"
#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    8

CRGB leds[NUM_LEDS];
Tone tone1;
Tone tone2;
unsigned long time;
bool done;
const int buttonPin = 2;     // the number of the pushbutton pin
const int pippippiplength = 400;
const int pippippippause = 200;
const int microtime = 5000; 

void setLedColor(CRGB color) {
  for (int i = 0; i <= 7; i++) {
      leds[i] = color;
    }
    FastLED.show();
}

void setup() {
  // iterate over the notes of the melody:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  tone1.begin(8);
  tone2.begin(9);
  time = millis();
  done = true;
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  setLedColor(CRGB::Black);
}

void loop() {
  // no need to repeat the melody.
  
    if(digitalRead(buttonPin) == HIGH) {
      tone1.play(NOTE_CS1, microtime);
      tone2.play(NOTE_E6, 200);
      time = millis();
      done = false;
      setLedColor(CRGB::White);
    }

    if (time + microtime < millis() & !done) {
      tone2.play(NOTE_E6, pippippiplength);
      setLedColor(CRGB::Green);
      delay(pippippiplength);
      setLedColor(CRGB::Black);
      delay(pippippippause);
      tone2.play(NOTE_E6, pippippiplength);
      setLedColor(CRGB::Green);
      delay(pippippiplength);
      setLedColor(CRGB::Black);
      delay(pippippippause);
      tone2.play(NOTE_E6, pippippiplength);
      setLedColor(CRGB::Green);
      delay(pippippiplength);
      setLedColor(CRGB::Black);
      delay(pippippippause);
      done = true;
    }
    
}
