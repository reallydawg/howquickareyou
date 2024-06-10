#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>

// Initial game settings
int level = 1;
const int MAX_LEVELS = 5;
int score = 0;

void setup() {
CircuitPlayground.begin();
Serial.begin(9600);
  
Serial.println("Slide the switch to start the game.");
while (!CircuitPlayground.slideSwitch()) {
delay(100);
}
Serial.println("Press and hold left button to start the round.");
reactionTimeGame();
Serial.println("End of game");
}

void loop() {
if (CircuitPlayground.slideSwitch()) {
resetGame();
}
}

// Function to play a tone
void playTone(int frequency, int duration) {
CircuitPlayground.playTone(frequency, duration);
}

// Function to light up a random LED
void lightUpRandomLED(int &ledNum) {
ledNum = random(10);
CircuitPlayground.setPixelColor(ledNum, 0, 255, 0);
}

// Function to clear all LEDs
void clearLEDs() {
for (int i = 0; i < 10; i++) {
CircuitPlayground.setPixelColor(i, 0, 0, 0);
}
}

// Function to announce the final score
void announceScore(int score) {
Serial.println("Level up!");
Serial.print("Final Score: ");
Serial.println(score);
}

// Function to handle the reaction time game logic
void reactionTimeGame() {
while (level <= MAX_LEVELS) {
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
if (CircuitPlayground.leftButton()) {
unsigned long reactionTime = millis() - startTime;
clearLEDs();
Serial.print("Level ");
Serial.print(level);
Serial.print(": Reaction time = ");
Serial.print(reactionTime);
Serial.println(" ms");
        
if (reactionTime < 250) {
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

// Reset game if slide switch is toggled
while (CircuitPlayground.slideSwitch()) {
Serial.println("Slide the switch to reset the game.");
delay(1000);
}
resetGame();
}

// Function to reset the game
void resetGame() {
level = 1;
score = 0;
Serial.println("Game reset.");
setup();
}