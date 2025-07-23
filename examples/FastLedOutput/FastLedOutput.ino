#include "Blinker.hpp"
#include "FastLED.h"

// LED pixel
#define NUM_LEDS 1
#define LED_DATA_PIN 2

// trigger inputs
#define TRIGGER1_PIN A0
#define TRIGGER2_PIN A1

// create the leds and a Blinker object
CRGB leds[NUM_LEDS];
Blinker blinker;

void setup()
{

    // setup triggers
    pinMode(TRIGGER1_PIN, INPUT_PULLUP);
    pinMode(TRIGGER2_PIN, INPUT_PULLUP);

    // setup leds
    FastLED.addLeds<NEOPIXEL, LED_DATA_PIN>(leds, NUM_LEDS);

    // setup blinker
    // a is off, z is full brightness
    blinker.setPatternIdle("aazzz");   // add idle pattern
    blinker.setColorIdle(CRGB::White); // add idle color

    blinker.setPatternTrigger1("mmmmmmm"); // add pattern for trigger1
    blinker.setColorTrigger1(CRGB::Red);   // add color for trigger1

    blinker.setPatternTrigger2("abcdefghijklmnopqrstuvwxyz"); // add pattern for trigger2
    blinker.setColorTrigger2(CRGB::Green);                    // add color for trigger2
}

void loop()
{

    // set triggers according to inputs
    blinker.setTrigger1(!digitalRead(TRIGGER1_PIN));
    blinker.setTrigger2(!digitalRead(TRIGGER2_PIN));

    // update the blinker
    blinker.update();

    // read RGB color
    CRGB color = blinker.getRGB();

    // set color to the led
    leds[0] = color;
    FastLED.show();
}