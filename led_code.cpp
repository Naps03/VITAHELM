#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN         5
#define PIXELCOUNT  32
#define BRIGHTNESS  255      // Maximale Helligkeit
#define HEARTBEAT_MS 1000    // Dauer eines Pulszyklus (z. B. 60 bpm = 1000 ms)

Adafruit_NeoPixel strip(PIXELCOUNT, PIN, NEO_RGB + NEO_KHZ800);

int moodValue = 0;           // Aktueller Wert vom PC (0–599)
uint8_t baseRed = 0, baseGreen = 0, baseBlue = 255; // Anfangsfarbe: ruhig (blau)

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Alle LEDs aus

  Serial.begin(115200);
  while (!Serial);
  Serial.println("Start: LEDs pulsieren & reagieren auf Stimmung...");
  randomSeed(analogRead(0)); //Initialisieren der Zufallsgenerierung
}

void loop() {
  // ==== 1. Serielle Eingabe verarbeiten ====
  //if (Serial.available()) {
    moodValue = random(0, 600); // Zufallswert zwischen 0 und 600
    Serial.print("Stimmung: "); Serial.println(moodValue);
    
    //=== 2. Stimmung -> farbe umrechnen ===
    setMoodColor(moodValue);
  //}

  // ==== 2. Pulsieren simulieren ====
  unsigned long timeInCycle = millis() % HEARTBEAT_MS;
  float phase = (float)timeInCycle / HEARTBEAT_MS;          // 0.0–1.0
  float brightnessFactor = (sin(phase * TWO_PI) + 1.0) / 2.0; // 0.0–1.0
  uint8_t scaledBrightness = (uint8_t)(brightnessFactor * BRIGHTNESS);

  // LEDs setzen
  for (int i = 0; i < PIXELCOUNT; i++) {
    strip.setPixelColor(i,
      (baseRed   * scaledBrightness) / 255,
      (baseGreen * scaledBrightness) / 255,
      (baseBlue  * scaledBrightness) / 255
    );
  }
  strip.show();

  delay(800); // Smooth Animation
}

// ==== Stimmung → Farbe umrechnen ====
void setMoodColor(int value) {
  if (value < 150) {
    baseRed = 0; baseGreen = 0; baseBlue = 255;    // Ruhig → Blau
  } else if (value < 300) {
    baseRed = 0; baseGreen = 255; baseBlue = 0;    // Mittel → Grün
  } else if (value < 450) {
    baseRed = 255; baseGreen = 165; baseBlue = 0;  // Erregt → Orange
  } else {
    baseRed = 255; baseGreen = 0; baseBlue = 0;    // Sehr erregt → Rot
  }
}
