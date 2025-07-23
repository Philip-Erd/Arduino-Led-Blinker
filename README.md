# Arduino-Led-Blinker

Use an Arduino to blink an LED with different patterns and colors.

This library provides you with a simple class that blinks a RGB value with a provided pattern to get an effect. You can define an Idle effect and two additional triggerable effects. The triggerable effect will override the idle effect. The triggerable effect will play as long as the trigger value is true.

## dependencies

This library requires [FastLed](https://fastled.io/). It is used for the color calculations.

The examples may require additional library: [DmxSimple](https://github.com/PaulStoffregen/DmxSimple)

## Patterns

Patterns are defined as Strings with the letters `a` to `z`. `a` corresponds to zero brightness (aka off or 0) and `z` corresponds to full brightness (255).
The patterns are displayed with 10 FPS and they are looped. 

### example patterns

slow pulse: `abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba`

fast strobe: `az`

neon light flicker: `zzazazzzzazzazazaaazazzza`

## Color

For each effect you can define a color. The color is scaled by the value of the pattern to get the final color.