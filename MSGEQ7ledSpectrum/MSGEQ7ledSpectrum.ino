#include <FastLED.h>
#define strobe 11
#define rst 9
#define DataIn A0
#define LED_TYPE  PL9823
#define COLOR_ORDER RGB

int freq[7];
CRGB leds[28]; 



void setup() {
  // put your setup code here, to run once:
  pinMode(strobe, OUTPUT);
  pinMode(rst, OUTPUT);
  digitalWrite(rst, LOW);
  digitalWrite(strobe, HIGH);
  FastLED.addLeds<LED_TYPE, 2>(leds, 0, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 3>(leds, 4, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 4>(leds, 8, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 5>(leds, 12, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 6>(leds, 16, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 7>(leds, 20, 4).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, 8>(leds, 24, 4).setCorrection( TypicalLEDStrip );
  FastLED.clear();
  Serial.begin(115200);
  /*int temp = 85;
  for(int i = 0; i < 7; i++) {
    leds[i*4] = CRGB::Green;
    leds[1+i*4].setRGB(127, 255, 0);
    
  }*/
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  readMSGEQ7();
  for(int i = 0; i<7; i++) {
    Serial.println("Channel ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(freq[i]);
    Serial.println("\n");
  }
}


void readMSGEQ7(){

  digitalWrite(rst, HIGH);
  digitalWrite(rst, LOW);
  /*digitalWrite(strobe,HIGH);
  delayMicroseconds(40);
  digitalWrite(strobe,LOW);
  delayMicroseconds(40);*/
  
  for(int i = 0; i < 7; i++) {
    digitalWrite(strobe,LOW);
    delayMicroseconds(30);
    freq[i] = analogRead(A0);
    digitalWrite(strobe,HIGH);
  }
}

