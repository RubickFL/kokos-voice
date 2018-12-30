#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel( 60, 6, NEO_GRB + NEO_KHZ800 );


void setup(){
  strip.setBrightness( 100 );
  strip.begin();
  strip.show();
}


void loop(){
  strip.setPixelColor( random(0, 59), strip.Color(random(0, 255), random(0, 255), random(0, 255)) );
  delay( 5 );
  strip.show();
}
