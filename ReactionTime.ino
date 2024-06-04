#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>

// Initial game settings
int level = 1;
const int maxLevels = 5;
int score = 0;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  
  Serial.println("Press left button to start the game.");
  while (!CircuitPlayground.leftButton()) {
    delay(100);
  }

  Serial.println("Start game");
  reactionTimeGame();
  Serial.println("End of game");
}

void loop() {
  // Main loop does nothing, everything is in the reactionTimeGame function
}

void playTone(int frequency, int duration) {
  CircuitPlayground.playTone(frequency, duration);
}

void lightUpRandomLED(int &ledNum) {
  ledNum = random(10);
  CircuitPlayground.setPixelColor(ledNum, 0, 255, 0);
}

void clearLEDs() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 0, 0, 0);
  }
}

void announceScore(int score) {
  Serial.println("Level up!");
  Serial.print("Final Score: ");
  Serial.println(score);
}

void reactionTimeGame() {
  while (level <= maxLevels) {
    Serial.print("Start level ");
    Serial.println(level);
    
    playTone(262, 500);
    delay(500);
    playTone(294, 500);
    delay(500);
    playTone(330, 500);

    float randomDelay = random(1000, 3000) / 1000.0 - (level * 0.2);
    delay(randomDelay * 1000);
    
    int ledNum;
    lightUpRandomLED(ledNum);

    unsigned long startTime = millis();
    while (true) {
      if (CircuitPlayground.rightButton()) {
        unsigned long reactionTime = millis() - startTime;
        clearLEDs();
        Serial.print("Level ");
        Serial.print(level);
        Serial.print(": Reaction time = ");
        Serial.print(reactionTime);
        Serial.println(" ms");
        
        if (reactionTime < 500) {
          score += 10;
        } else {
          score += 5;
        }
        playTone(440, 500);
        break;
      }
      delay(10);
    }

    level++;
    delay(1000);
  }

  announceScore(score);
}