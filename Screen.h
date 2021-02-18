class Screen{
  public:
  int xPins[5];
  int yPins[8];
  Screen(int x0, int x1, int x2, int x3, int x4, int y0, int y1, int y2, int y3, int y4, int y5, int y6, int y7) {
    xPins[0] = x0; xPins[1] = x1; xPins[2] = x2; xPins[3] = x3; xPins[4] = x4;
    yPins[0] = y0; yPins[1] = y1; yPins[2] = y2; yPins[3] = y3; yPins[4] = y4; yPins[5] = y5; yPins[6] = y6; yPins[7] = y7; 
  }
  
  void draw(int letter[8][5], int times){ //times perameter indicates the number of times the letter is drawn which determines how long the letter is present on the screen
    for(int i = 0; i < times; ++i){
      for(int yCounter = 0; yCounter < 8; ++yCounter){
        digitalWrite(yPins[yCounter], HIGH);
        for(int xCounter = 0; xCounter < 5; ++xCounter){
          if(letter[yCounter][xCounter]) digitalWrite(xPins[xCounter], HIGH);
          else digitalWrite(xPins[xCounter], LOW);
        }
        delay(2); //0.002 second delay makes the image look clear 
        digitalWrite(yPins[yCounter], LOW);
      }
    }
  }
};