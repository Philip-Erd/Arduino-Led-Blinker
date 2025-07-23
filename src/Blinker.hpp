#ifndef BLINKER_H
#define BLINKER_H

#include "Arduino.h"
#include "FastLED.h"

class Blinker{
  public:
    Blinker();

    void setPatternIdle(String pattern);
    void setPatternTrigger1(String pattern);
    void setPatternTrigger2(String pattern);

    void setColorIdle(CRGB color);
    void setColorTrigger1(CRGB color);
    void setColorTrigger2(CRGB color);

    void setTrigger1(bool value);
    void setTrigger2(bool value);

    CRGB getRGB();

    void update();

    // TODO get RGBW

  private:
    String patternIdle;
    String patternTrigger1;
    String patternTrigger2;

    CRGB colorIdle;
    CRGB colorTrigger1;
    CRGB colorTrigger2;

    CRGB outputColor;

    bool trigger1 = false;
    bool trigger2 = false;

    unsigned long step = 0;
    unsigned long lastUpdate;

};

#endif