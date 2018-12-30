#include <Adafruit_NeoPixel.h>
#define PIN 6
#define STRIPSIZE 60
#define DELAY 80
Adafruit_NeoPixel strip = Adafruit_NeoPixel( STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800 );

void setup(){
  strip.setBrightness( 150 );
  strip.begin();
  run_random_rainbow();
}

void loop(){}


//rinbowCycle(), colorWave() - разные эффекты, способные работать вместе!!!
void run_random_rainbow(){
  while( 1 ){
    rainbowCycle();
    colorWave();
    delay( DELAY );
  }
}




void rainbowCycle(){
  for( uint16_t j = 0; j < 256 * 5; ++j ){
    for( uint16_t i = 0; i < strip.numPixels(); ++i ){
      strip.setPixelColor( i, Wheel(((i * 256 / strip.numPixels()) + j) & 255) );
    }
    strip.show();
  }
}




uint32_t Wheel( byte WheelPos ){
  if( WheelPos < 85 ){
    return strip.Color( WheelPos * 3, 255 - WheelPos * 3, 0 );
  }
  
  else if( WheelPos < 170 ){
    WheelPos -= 85;
    return strip.Color( 255 - WheelPos * 3, 0, WheelPos * 3 );
  }
  
  else{
    WheelPos -= 170;
    return strip.Color( 0, WheelPos * 3, 255 - WheelPos * 3 );
  }
}




unsigned short int tick = 0;
void colorWave(){
  unsigned short int i, j, stripsize, cycle;
  float ang, rsin, gsin, bsin, offset;

  
  stripsize = strip.numPixels();
  cycle = stripsize * 25;


  while( ++tick % cycle ){
    offset = map2PI( tick );

    for( i = 0; i < stripsize; ++i ){
      ang = map2PI( i ) - offset;
      rsin = sin( ang );
      gsin = sin( 2.0 * ang / 3.0 + map2PI(int(stripsize/6)) );
      bsin = sin( 4.0 * ang / 5.0 + map2PI(int(stripsize/3)) );
      strip.setPixelColor( i, strip.Color(trigScale(rsin), trigScale(gsin), trigScale(bsin)) );
    }


    strip.show();
  }
}




byte trigScale( float val ){
  val += 1.0;
  val *= 127.0;

  return int( val ) & 255;
}




float map2PI( short int i ){
  return PI * 2.0 * float( i ) / float( strip.numPixels() );
}
