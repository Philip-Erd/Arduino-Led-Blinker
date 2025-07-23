#include "Blinker.hpp"
#include "DmxSimple.h"
#include "FastLED.h"

// dmx data pin
#define DMX_PIN 3

// trigger inputs
#define TRIGGER1_PIN A0
#define TRIGGER2_PIN A1

// a Blinker object
Blinker blinker;

void setup()
{

    // setup triggers
    pinMode(TRIGGER1_PIN, INPUT_PULLUP);
    pinMode(TRIGGER2_PIN, INPUT_PULLUP);

    // setup DMX
    DmxSimple.usePin(DMX_PIN);

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

    // write color to first 3 channels
    DmxSimple.write(1, color.r);
    DmxSimple.write(2, color.g);
    DmxSimple.write(3, color.b);

    // convert color to RGBW
    uint8_t r, g, b, w;
    rgb_2_rgbw_exact(4000, color.r, color.g, color.b, 255, 255, 255, r, g, b, w);

    // write RGBW color to channels 4 to 7
    DmxSimple.write(4, r);
    DmxSimple.write(5, g);
    DmxSimple.write(6, b);
    DmxSimple.write(7, w);
}
