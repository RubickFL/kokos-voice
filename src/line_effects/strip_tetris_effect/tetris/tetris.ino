#include <Adafruit_NeoPixel.h>
#define PIN 6
#define STRIPSIZE 60
#define DELAY 20
Adafruit_NeoPixel strip = Adafruit_NeoPixel( STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800 );



void setup(){
  strip.setBrightness( 8 );
  strip.show();
  strip.begin();
}


short int a = 0;
void loop(){
  for( short int i = STRIPSIZE; i > a; --i ){
    strip.setPixelColor( i, strip.Color(random(0, 255), random(0, 255), random(0, 255)) );
    strip.show();
    delay( DELAY );
    strip.setPixelColor( i, strip.Color(0, 0, 0) );
    strip.show();
    if( i - 1 == a ){
      strip.setPixelColor( a, strip.Color(random(0, 255), random(0, 255), random(0, 255)) );
      --i;
    }
  }
  ++a;
  if( a == 60 ) a = 0;
}
