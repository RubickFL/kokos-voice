#include <Adafruit_NeoPixel.h>
#define PIN 6
#define STRIPSIZE 60
#define DELAY 850
Adafruit_NeoPixel strip = Adafruit_NeoPixel( STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800 );




void setup(){
  strip.setBrightness( 8 );
  strip.begin();
  strip.show();
  run_rainbow2();
}
void loop()
{}



void run_rainbow2(){
  while( 1 ){
    unsigned short int a = 1;
    for( unsigned short int i = 0; i < STRIPSIZE; ++i ){
      for( unsigned short int j = i; j < i + 6; ++j ){
        switch( a ){
        case 1:
          strip.setPixelColor( j, strip.Color(255, 0, 0) );
          break;
        
        case 2:
          strip.setPixelColor( j, strip.Color(255, 127, 0) );
          break;
        
        case 3:
          strip.setPixelColor( j, strip.Color(255, 255, 0) );
          break;
        
        case 4:
          strip.setPixelColor( j, strip.Color(127, 255, 0) );
          break;
        
        case 5:
          strip.setPixelColor( j, strip.Color(0, 127, 255) );
          break;
        
        case 6:
          strip.setPixelColor( j, strip.Color(0, 0, 255) );
          break;
        
        case 7:
          strip.setPixelColor( j, strip.Color(127, 0, 255) );
          break;
        }
      }
      delay( DELAY );
      strip.show();
      ++a;
      if( a == 8 ) a = 1;
      delay( 20 );
      }
   }
}
