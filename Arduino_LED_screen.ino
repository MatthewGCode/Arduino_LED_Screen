#include "Screen.h"
#include "./letters/letterH.h"
#include "./letters/letterI.h"
#include "./letters/nonLetterCharacters.h"
Screen MyScreen(2, 3, 4, 5, 6, A0, A1, A2, A3, A4, A5, 7, 8); // creates screen object

int wordHello[3] = {letterH, letterI, charSmile};

void setup() {
  for(int xPin : MyScreen.xPins) pinMode(xPin, OUTPUT);
  for(int yPin : MyScreen.yPins) pinMode(yPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  for(int letter : wordHello){
    MyScreen.draw(letter, 50);
    delay(300);
  }
}
