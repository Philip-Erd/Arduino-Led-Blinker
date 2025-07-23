#include "Arduino.h"
#include "FastLED.h"

#include "Blinker.hpp"

Blinker::Blinker()
{
  lastUpdate = millis();
}

void Blinker::setPatternIdle(String pattern)
{
  patternIdle = pattern;
}
void Blinker::setPatternTrigger1(String pattern)
{
  patternTrigger1 = pattern;
}
void Blinker::setPatternTrigger2(String pattern)
{
  patternTrigger2 = pattern;
}

void Blinker::setColorIdle(CRGB color)
{
  colorIdle = color;
}
void Blinker::setColorTrigger1(CRGB color)
{
  colorTrigger1 = color;
}
void Blinker::setColorTrigger2(CRGB color)
{
  colorTrigger2 = color;
}

void Blinker::setTrigger1(bool value)
{
  trigger1 = value;
}
void Blinker::setTrigger2(bool value)
{
  trigger2 = value;
}

CRGB Blinker::getRGB()
{
  return outputColor;
}

void Blinker::update()
{

  // update only 10 times per second
  if (millis() - lastUpdate < 100)
  {
    return;
  }
  lastUpdate = millis();

  // update
  step++;

  // get color and pattern
  CRGB color = colorIdle;
  String pattern = patternIdle;

  if (trigger1)
  {
    color = colorTrigger1;
    pattern = patternTrigger1;
  }

  if (trigger2)
  {
    color = colorTrigger2;
    pattern = patternTrigger2;
  }

  // convert pattern and color to actual color
  char value = pattern.charAt(step % pattern.length()) - 'a';

  value = map(value, 0, 25, 0, 255);
  color = color.nscale8(value);

  outputColor = color;
}