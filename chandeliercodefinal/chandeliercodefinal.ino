#include <Adafruit_NeoPixel.h>

#define GSR_PIN A0
#define LED_PIN 6
#define LED_COUNT 60
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);

void setup() {
  strip.begin();
  strip.show(); 
  pinMode(GSR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
//add for serial monitor
Serial.begin(9600); 
}

void loop() {
  // Read the GSR sensor value
  int gsrValue = analogRead(GSR_PIN);
  //serial monitor
  Serial.print(gsrValue);
  Serial.print(",");

  float brightness = 0; 
  //long brightness = map(gsrValue,300, 500, 0, 100);

  if (gsrValue < 320) {
    brightness = 0.05;
  }
  if (gsrValue >320 && gsrValue < 340) {
   brightness = 0.1;
  }
  if (gsrValue >340 && gsrValue < 350) {
   brightness = 0.15;
  }
   if (gsrValue >350 && gsrValue < 360) {
   brightness = 0.2;
  }
    if (gsrValue >360 && gsrValue < 370) {
   brightness = 0.25;
  }
    if (gsrValue >370 && gsrValue < 450) {
   brightness = 0.35;
  }
     if (gsrValue >450) {
   brightness = 0.4;
  }



  // Set the brightness of all NeoPixels. colour overrides preconfigured brightness as they already contain specific brightnesses, so have to set colour relative to brightness
  //strip.setBrightness(brightness);
  strip.fill(strip.Color(255*brightness,222*brightness,173*brightness));//warm white
  //strip.fill(strip.Color(255,0,0));
  //strip.fill(strip.Color(brightness, 0, 255-brightness)); // colour red blue
  //strip.fill(strip.Color(brightness, brightness , brightness)); // white

  strip.show(); 

  delay(1000); 
}

