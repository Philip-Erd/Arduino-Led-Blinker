#ifndef BLINKER_H
#define BLINKER_H

#include "Arduino.h"
#include "FastLED.h"

// predefined Patterns to use
#define BLINKER_PATTERN_FULL_BRIGHTNESS "z"
#define BLINKER_PATTERN_HALF_BRIGHTNESS "m"
#define BLINKER_PATTERN_OFF "a"
#define BLINKER_PATTERN_PULSE_SLOW "abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba"
#define BLINKER_PATTERN_PULSE_SLOW_NO_BLACK "jklmnopqrstuvwxyzyxwvutsrqponmlkj"
#define BLINKER_PATTERN_PULSE_MEDIUM "acegikmoqsuwywusqomkigeca"
#define BLINKER_PATTERN_PULSE_FAST "aeimquyugmiea"
#define BLINKER_PATTERN_STROBE_SLOW "aaaaaaaazzzzzzzz"
#define BLINKER_PATTERN_STROBE_MEDIUM "aaaazzzz"
#define BLINKER_PATTERN_STROBE_FAST "az"
#define BLINKER_PATTERN_FADE_IN_SLOW "abcdefghijklmnopqrstuvwxyz"
#define BLINKER_PATTERN_FADE_IN_MEDIUM "acegikmoqsuwy"
#define BLINKER_PATTERN_FADE_IN_FAST "aeimquy"
#define BLINKER_PATTERN_FADE_OUT_SLOW "zyxwvutsrqponmlkjihgfedcba"
#define BLINKER_PATTERN_FADE_OUT_MEDIUM "ywusqomkigeca"
#define BLINKER_PATTERN_FADE_OUT_FAST "yugmiea"
#define BLINKER_PATTERN_CANDLE_1 "wvxwzwvxvwvxvxvwx"
#define BLINKER_PATTERN_CANDLE_2 "wwwwtwwxwtwwtwwx"
#define BLINKER_PATTERN_CANDLE_3 "wuqtxyomiorxywvuomnvww"
#define BLINKER_PATTERN_NEON_FLICKER_1 "zzazazzzzazzazazaaazazzza"
#define BLINKER_PATTERN_NEON_FLICKER_2 "hhhhzzzzzzhhzzzzzhzzhzzhzzzzzzhz"
#define BLINKER_PATTERN_SHORT_FLASH_SLOW "aaaaaaaaaaaaaaaazz"
#define BLINKER_PATTERN_SHORT_FLASH_FAST "aaaaaaaazz"
#define BLINKER_PATTERN_SHORT_ELECTRICAL_FLICKER_1 "zzzzzzzzzuuzzzzzzzzzzzzzzzzzuuzzzzzzzzzuzz"
#define BLINKER_PATTERN_SHORT_ELECTRICAL_FLICKER_2 "zzzuzzuzzzzzzzzzzzzzzzuzzzzzzzzz"
#define BLINKER_PATTERN_SHORT_ELECTRICAL_FLICKER_3 "zzzuzzuzzzzzzzzzzzzzzzzzzzzzzzzuuuuu"
#define BLINKER_PATTERN_SHORT_LIGHTNING_STRIKE_1 "zzaaauuazuuaaaaaaaaaaaaaaaaaaaaaa"
#define BLINKER_PATTERN_SHORT_LIGHTNING_STRIKE_2 "uuzaazazauaaaaaaaaaaaaaaaaaaaaaaa"
#define BLINKER_PATTERN_SHORT_LIGHTNING_STRIKE_3 "zzzuaaazzaaaauuaaaaaaaaaaaaaaaaaa"

class Blinker
{
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