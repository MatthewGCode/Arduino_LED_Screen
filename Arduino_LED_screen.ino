#include "./letters/letterH.h"
#include "./letters/letterI.h"
#include "./letters/nonLetterCharacters.h"

#define TIMES_DRAWN 50
#define WORD_SIZE 3

const int colPins[5] = {2, 3, 4, 5, 6};
const int rowPins[8] = { A0, A1, A2, A3, A4, A5, 7, 8};

void draw(int letter[8][5]){
  for(int i = 0; i < TIMES_DRAWN; ++i){
    for(int yCounter = 0; yCounter < 8; ++yCounter){
      digitalWrite(rowPins[yCounter], HIGH);
      for(int xCounter = 0; xCounter < 5; ++xCounter){
        if(letter[yCounter][xCounter]) digitalWrite(colPins[xCounter], HIGH);
        else digitalWrite(colPins[xCounter], LOW);
      }
      delay(2); //2 millis delay makes the image look more clear 
      digitalWrite(rowPins[yCounter], LOW);
    }
  }
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
  delay(300);
  draw(letterH);
  delay(300);
  draw(letterI);
  delay(300);
  draw(charSmile);
}
