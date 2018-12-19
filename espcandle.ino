#include <Adafruit_NeoPixel.h>
#define PIXELS 8
#define PIN 13
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, PIN, NEO_RGB + NEO_KHZ800);

int burn_time = 60;
int flame_length = 3;
int flame_base_color = strip.Color(242,125,12);
int candle_length = PIXELS - flame_length;
int candle_color = strip.Color(255,255,200);
unsigned long previousMillis = 0;  
long interval = 1000;           // interval at which to blink (milliseconds)


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int current_pixel = 0;
    for(current_pixel; current_pixel < candle_length; current_pixel ++) {
      strip.setPixelColor(current_pixel, candle_color);
      Serial.println(current_pixel);
    };
    
    for(current_pixel;  current_pixel < flame_length +candle_length; current_pixel ++) {
      strip.setPixelColor(current_pixel, flame_base_color);
      Serial.println(current_pixel);
    }
  }
  delay(10);
  strip.show();
}
