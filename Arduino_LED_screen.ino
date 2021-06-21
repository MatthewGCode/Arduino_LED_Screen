#include "./letters/letterH.h"
#include "./letters/letterE.h"
#include "./letters/letterL.h"
#include "./letters/letterO.h"
#include "./letters/nonLetterCharacters.h"

#define TIMES_DRAWN 50

const uint8_t colPins[5] = {2, 3, 4, 5, 6};
const uint8_t rowPins[8] = { A0, A1, A2, A3, A4, A5, 7, 8};

void draw(uint8_t letter[8]){
  for(uint8_t i = 0; i < TIMES_DRAWN; ++i){
    for(uint8_t rowCounter = 0; rowCounter < 8; ++rowCounter){
      digitalWrite(rowPins[rowCounter], HIGH);

      uint8_t currPixel = 0b10000;
      for(uint8_t colCounter = 0; colCounter < 5; ++colCounter){
        if(letter[rowCounter] & (currPixel>>colCounter)) digitalWrite(colPins[colCounter], HIGH);
        else digitalWrite(colPins[colCounter], LOW);
      }
      delay(2); //2 millis delay makes the image look more clear 
      digitalWrite(rowPins[rowCounter], LOW);
    }
  }
  delay(300);
}

void setup() {
  //col pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  //row pins
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  draw(letterH);
  draw(letterE);
  draw(letterL);
  draw(letterL);
  draw(letterO);
  draw(charSmile);
}
