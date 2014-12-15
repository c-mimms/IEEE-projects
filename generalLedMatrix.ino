/*
||
 || 
 ||Chris Mimms
 
 Library in progress to draw to LED display board.
 LED Board used in Arduino Tutorials:
 arrrays, loops, control flow, memory and hardware issues with arduino.

 
 ==========================================
 */

#include "FastLED.h"    // https://github.com/FastLED/FastLED
#include <math.h>

//LED Matrix defined : numleds must be divisble by matrix_w
#define NUM_LEDS 450
#define MATRIX_W 30
#define MATRIX_H 15

#define DATA_PIN 7




// Create the LED interface, pixel buffer
CRGB leds[NUM_LEDS];
int pixel_buffer[NUM_LEDS][3];


// Provision our world
CRGB world[MATRIX_W][MATRIX_H];
int counter;
/* 
 ==========================================
 = setup()
 = Initializes needed variables and drivers, called by Arduino once during initialization.
 */

void(* resetFunc) (void) = 0;//declare reset function at address 0


byte a[] = {
  B01111110,
  B00001001,
  B00001001,
  B01111110};

byte B[] = {
  B01111111,
  B01001001,
  B01001001,
  B00110110};

byte C[] = {
  B00111110,
  B01000001,
  B01000001,
  B01000001};

byte D[] = {
  B01111111,
  B01000001,
  B01000001,
  B00111110};

byte E[] = {
  B01111111,
  B01001001,
  B01001001,
  B01000001};

byte F[] = {
  B01111111,
  B00001001,
  B00001001,
  B00000011};

byte G[] = {
  B01111111,
  B01000001,
  B01000101,
  B01100110};

byte H[] = {
  B01111111,
  B00001000,
  B00001000,
  B01111111};

byte I[] = {
  B01000001,
  B01111111,
  B01111111,
  B01000001};

byte J[] = {
  B00110001,
  B01000001,
  B00111111,
  B00000001};

byte K[] = {
  B01111111,
  B00001000,
  B00010100,
  B01100011};

byte L[] = {
  B01111111,
  B01000000,
  B01000000,
  B01100000};

byte M[] = {
  B01111111,
  B00000010,
  B00001100,
  B00000010,
  B01111111};

byte N[] = {
  B01111111,
  B00000010,
  B00011100,
  B00100000,
  B01111111};

byte O[] = {
  B00111110,
  B01000001,
  B01000001,
  B00111110};

byte P[] = {
  B01111111,
  B00001001,
  B00001001,
  B00000110};

byte Q[] = {
  B01111111,
  B01000001,
  B00100001,
  B01011111};

byte R[] = {
  B01111111,
  B00001001,
  B00001001,
  B01110110};

byte S[] = {
  B01000110,
  B01001001,
  B01001001,
  B00110001};

byte T[] = {
  B00000001,
  B01111111,
  B01111111,
  B00000001};

byte U[] = {
  B00111111,
  B01000000,
  B01000000,
  B00111111};

byte V[] = {
  B00011111,
  B01100000,
  B01100000,
  B00011111};

byte W[] = {
  B00011111,
  B01100000,
  B00011111,
  B01100000,
  B00011111};

byte X[] = {
  B01100001,
  B00010010,
  B00001000,
  B00010100,
  B01100001};

byte Y[] = {
  B00000111,
  B01111000,
  B01111000,
  B00000111};

byte Z[] = {
  B01100001,
  B01011001,
  B01001101,
  B01000011};

byte space[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000};

byte smile[] = {
  B00011100,
  B00100010,
  B01010101,
  B01010001,
  B01010101,
  B00100010,
  B00011100};

void setup() {
  // Initialize the LED interface
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));

  for ( int i = 0; i < NUM_LEDS; i++){
    leds[i] =CRGB::Black;
  }

  FastLED.show();
  delay(500);
}


/* 
 ==========================================
 = loop()
 = The main runtime heartbeat, called by Arduino once whenever the previous run of loop() completes.
 */
void loop() {

//  dispStringTop("IEEE", CRGB::Blue);
//  for(int i = 0; i < 100; i++){
//    dispStringBottom("IEEE IEEE IEEE IEEE IEEE IEEE",i, CRGB::Red);
//  }
//  wipeUp();
//
//
//  dispStringTop("HKN", CRGB::Gold);
//  for(int i = 0; i < 100; i++){
//    dispStringBottom("HKN HKN HKN HKN HKN HKN HKN HKN HKN HKN HKN", i, CRGB::Red);
//  }
//  wipeUp();
//
//
//
//  int gens = 255;
//  seedRandom(20);
//  while(gens > 0){
//    gameOfLife(gens);
//    gens--;
//    delay(10);
//  }
//
//
  
    drawSomething();
    draw();

//  seedRandom(12);
//  mazeGen(40,30);
//  wipeRight();
//  seedRandom(12);
//  mazeGen(40,30);
//  wipeUp();
//  seedRandom(12);
//  mazeGen(40,30);
//  wipeRight();
//
//  gens = 256;
//  seedRandom(20);
//  while(gens > 0){
//    HighLife(gens);
//    gens--;
//    delay(20);
//  }
//
//  resetFunc();
}

void seedRandom(int percent){
  // Plant some entropy and watch it grow!  
  for(int i = 0; i < MATRIX_W; i++){
    for(int j = 0; j < MATRIX_H; j++){
      if(random(100)<percent){
        world[i][j].setHue(0);
      }
      else{
        world[i][j] = CRGB::Black; 
      }
    }
  } 
}


void drawSomething(){
  delay(30);
  // Plant some entropy and watch it grow!  
  for(int i = 0; i < MATRIX_W; i++){
    for(int j = 0; j < MATRIX_H; j++){
      world[i][j] = CRGB::Black;
      if(((i+j)/2)%4==0){
        world[i][j]= CRGB(30,30,30);
        //.g=(50+random(-50,0));
      }
      else if(((i+j)/2)%6==0){
        world[i][j].g=(50+random(-50,0));
      }
      else{ 
        world[i][j].r=(50+(random(-50, 10)));
      }
      
    }
  } 
  drawLine(0,  0 , (MATRIX_W-1), 0, CRGB(30,30,30));
  drawLine(0,  0 , 0, (MATRIX_H-1), CRGB(30,30,30));
  drawLine((MATRIX_W-1),  0 , (MATRIX_W-1), (MATRIX_H-1), CRGB(30,30,30));
  drawLine(0,  (MATRIX_H-1), (MATRIX_W-1), (MATRIX_H-1), CRGB(30,30,30));
}



void gameOfLife(int gens){

  int next_generation[MATRIX_W][MATRIX_H];
  for (int i = 0; i < MATRIX_W; i++) {
    for (int j = 0; j < MATRIX_H; j++) {

      // Orient ourselves
      int i_up = i + 1;
      if (i_up == MATRIX_W) {
        i_up = 0;
      }
      int i_down = i - 1;
      if (i_down < 0) {
        i_down = MATRIX_W - 1;
      }
      int j_right = j + 1;
      if (j_right == MATRIX_H) {
        j_right = 0;
      }
      int j_left = j - 1;
      if (j_left < 0) {
        j_left = MATRIX_H-1;
      }

      // Let's meet the neighbors!
      int neighbors  = 0 ;
      if(world[i_up][j_right]) neighbors++;
      if(world[i_up][j]) neighbors++;
      if(world[i_up][j_left]) neighbors++;
      if(world[i][j_left] ) neighbors++;
      if(world[i_down][j_left] ) neighbors++;
      if(world[i_down][j]) neighbors++;
      if(world[i_down][j_right] ) neighbors++;
      if(world[i][j_right]) neighbors++;

      // Any live cell with fewer than two live neighbours dies, as if caused by under-population.
      if (world[i][j] && neighbors < 2) {
        next_generation[i][j] = 0;
      }
      // Any live cell with two or three live neighbours lives on to the next generation.
      if (world[i][j] && (neighbors == 2 || neighbors == 3)) {
        next_generation[i][j] = 1;
      }
      // Any live cell with more than three live neighbours dies, as if by overcrowding.
      if (world[i][j] && neighbors > 3) {
        next_generation[i][j] = 0;
      }	
      // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
      if (!world[i][j] && neighbors == 3) {
        next_generation[i][j] = 2;
      }

    }
  }
  draw();
  // Pass on the torch
  for (int i = 0; i < MATRIX_W; i++) {
    for (int j = 0; j < MATRIX_H; j++) {
      switch(next_generation[i][j]){
      case 0:       
        world[i][j] = CRGB::Black; 
        break;
      case 1: 
        break;
      case 2: 
        world[i][j].setHue(gens);
      }
    }
  }
}


void HighLife(int gens){

  int next_generation[MATRIX_W][MATRIX_H];
  for (int i = 0; i < MATRIX_W; i++) {
    for (int j = 0; j < MATRIX_H; j++) {

      // Orient ourselves
      int i_up = i + 1;
      if (i_up == MATRIX_W) {
        i_up = 0;
      }
      int i_down = i - 1;
      if (i_down < 0) {
        i_down = MATRIX_W - 1;
      }
      int j_right = j + 1;
      if (j_right == MATRIX_H) {
        j_right = 0;
      }
      int j_left = j - 1;
      if (j_left < 0) {
        j_left = MATRIX_H-1;
      }

      // Let's meet the neighbors!
      int neighbors  = 0 ;
      if(world[i_up][j_right]) neighbors++;
      if(world[i_up][j]) neighbors++;
      if(world[i_up][j_left]) neighbors++;
      if(world[i][j_left] ) neighbors++;
      if(world[i_down][j_left] ) neighbors++;
      if(world[i_down][j]) neighbors++;
      if(world[i_down][j_right] ) neighbors++;
      if(world[i][j_right]) neighbors++;

      // Any live cell with fewer than two live neighbours dies, as if caused by under-population.
      if (world[i][j] && neighbors < 2) {
        next_generation[i][j] = 0;
      }
      // Any live cell with two or three live neighbours lives on to the next generation.
      else if (world[i][j] && (neighbors == 2 || neighbors == 3)) {
        next_generation[i][j] = 1;
      }
      // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
      else if (!world[i][j] && (neighbors == 3 || neighbors == 6)) {
        next_generation[i][j] = 2;
      }
      // Any live cell with more than three live neighbours dies, as if by overcrowding.
      else if (world[i][j] && neighbors > 3) {
        next_generation[i][j] = 0;
      }	

    }
  }
  draw();
  // Pass on the torch
  for (int i = 0; i < MATRIX_W; i++) {
    for (int j = 0; j < MATRIX_H; j++) {
      switch(next_generation[i][j]){
      case 0:       
        world[i][j] = CRGB::Black; 
        break;
      case 1: 
        break;
      case 2: 
        world[i][j].setHue((gens*6)%256);
      }
    }
  }
}


void mazeGen(int gens, int time){
  while(gens >0){
    boolean changed = false;
    int next_generation[MATRIX_W][MATRIX_H];
    for (int i = 0; i < MATRIX_W; i++) {
      for (int j = 0; j < MATRIX_H; j++) {

        // Orient ourselves
        int i_up = i + 1;
        if (i_up == MATRIX_W) {
          i_up = 0;
        }
        int i_down = i - 1;
        if (i_down < 0) {
          i_down = MATRIX_W - 1;
        }
        int j_right = j + 1;
        if (j_right == MATRIX_H) {
          j_right = 0;
        }
        int j_left = j - 1;
        if (j_left < 0) {
          j_left = MATRIX_H-1;
        }

        // Let's meet the neighbors!
        int neighbors  = 0 ;
        if(world[i_up][j_right]) neighbors++;
        if(world[i_up][j]) neighbors++;
        if(world[i_up][j_left]) neighbors++;
        if(world[i][j_left] ) neighbors++;
        if(world[i_down][j_left] ) neighbors++;
        if(world[i_down][j]) neighbors++;
        if(world[i_down][j_right] ) neighbors++;
        if(world[i][j_right]) neighbors++;

        // Any live cell with fewer than 1 or more than 5 live neighbours dies, as if caused by under-population.
        if (world[i][j] && (neighbors < 1 || neighbors > 5)) {
          next_generation[i][j] = 0;
          changed = true;
        }
        // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
        else if (!world[i][j] && neighbors == 3) {
          next_generation[i][j] = 2;
          changed = true;
        }
        else if(world[i][j]){
          next_generation[i][j] = 1;
          changed = true;
        }

      }
    }
    draw();
    // Pass on the torch
    for (int i = 0; i < MATRIX_W; i++) {
      for (int j = 0; j < MATRIX_H; j++) {
        switch(next_generation[i][j]){
        case 0:       
          world[i][j] = CRGB::Black; 
          break;
        case 1: 
          break;
        case 2: 
          world[i][j].setHue((gens*10)%256);
        }
      }
    }
    gens--;
    delay(time);
    if(!changed) break;
  }
}


void draw(){

  for ( int i = 1; i < NUM_LEDS; i++){
    int temp = i/MATRIX_W;

    if(temp%2 == 0){ //If divisble by 2 strip goes left to right
      leds[i-1] = world[i%MATRIX_W][temp];
    }
    else{ // Odd number strips go right to left
      leds[i-1] = world[MATRIX_W-i%MATRIX_W-1][temp];
    }
  }
  FastLED.show();
}



//Rename if mounting on wall
void wipeRight(){

  for(int i = 0; i < MATRIX_H; i++){
    for(int j = 0; j < MATRIX_W; j++){
      world[j][i] = CRGB::Black; 
    }
    draw();
    delay(30);

  }
}

void wipeUp(){

  for(int i = 0; i < MATRIX_W; i++){
    for(int j = 0; j < MATRIX_H; j++){
      world[i][j] = CRGB::Black; 
    }
    draw();
    delay(30);

  }
}

void dispStringTop(String words, CRGB color){
  int pos = 0;
  int stringPos = 0;
  words.toUpperCase();
  int strlen = words.length();
  while(stringPos < strlen){
    char curChar = words.charAt(stringPos);
    byte* curByteMap;
    int charWidth = 4;
    Serial.println(curChar);
    switch(curChar){
    case 'A' :  
      curByteMap = a; 
      break;
    case 'B' :  
      curByteMap = B; 
      break;
    case 'C' :  
      curByteMap = C; 
      break;
    case 'D' :  
      curByteMap = D; 
      break;
    case 'E' :  
      curByteMap = E; 
      break;
    case 'F' :  
      curByteMap = F; 
      break;
    case 'G' :  
      curByteMap = G; 
      break;
    case 'H' :  
      curByteMap = H; 
      break;
    case 'I' :  
      curByteMap = I; 
      break;
    case 'J' :  
      curByteMap = J; 
      break;
    case 'K' :  
      curByteMap = K; 
      break;
    case 'L' :  
      curByteMap = L; 
      break;
    case 'M' :  
      curByteMap = M; 
      charWidth = 5; 
      break;
    case 'N' :  
      curByteMap = N;  
      charWidth = 5; 
      break;
    case 'O' :  
      curByteMap = O; 
      break;
    case 'P' :  
      curByteMap = P; 
      break;
    case 'Q' :  
      curByteMap = Q; 
      break;
    case 'R' :  
      curByteMap = R; 
      break;
    case 'S' :  
      curByteMap = S; 
      break;
    case 'T' :  
      curByteMap = T; 
      break;
    case 'U' :  
      curByteMap = U; 
      break;
    case 'V' :  
      curByteMap = V; 
      break;
    case 'W' :  
      curByteMap = W;  
      charWidth = 5; 
      break;
    case 'X' :  
      curByteMap = X;  
      charWidth = 5; 
      break;
    case 'Y' :  
      curByteMap = Y; 
      break;
    case 'Z' :  
      curByteMap = Z; 
      break;
    case '1' :  
      curByteMap = smile; 
      charWidth = 7; 
      break;
    case 32 :  
      curByteMap = space; 
      break;

    }
    for(int i = 0; i< charWidth; i++){
      for(int height = 0; height < 7; height++){
        if(bitRead(curByteMap[i],height)){
          world[pos][height] = color; 
        }
        else{
          world[pos][height] = CRGB::Black; 
        }

      }
      pos++;


    }
    pos++;
    stringPos ++;


  }
  draw();
}

void dispStringBottom(String words, CRGB color){
  int pos = 0;
  int stringPos = 0;
  words.toUpperCase();
  int strlen = words.length();
  while(stringPos < strlen){
    char curChar = words.charAt(stringPos);
    byte* curByteMap;
    int charWidth = 4;
    switch(curChar){
    case 'A' :  
      curByteMap = a; 
      break;
    case 'B' :  
      curByteMap = B; 
      break;
    case 'C' :  
      curByteMap = C; 
      break;
    case 'D' :  
      curByteMap = D; 
      break;
    case 'E' :  
      curByteMap = E; 
      break;
    case 'F' :  
      curByteMap = F; 
      break;
    case 'G' :  
      curByteMap = G; 
      break;
    case 'H' :  
      curByteMap = H; 
      break;
    case 'I' :  
      curByteMap = I; 
      break;
    case 'J' :  
      curByteMap = J; 
      break;
    case 'K' :  
      curByteMap = K; 
      break;
    case 'L' :  
      curByteMap = L; 
      break;
    case 'M' :  
      curByteMap = M; 
      charWidth = 5; 
      break;
    case 'N' :  
      curByteMap = N;  
      charWidth = 5; 
      break;
    case 'O' :  
      curByteMap = O; 
      break;
    case 'P' :  
      curByteMap = P; 
      break;
    case 'Q' :  
      curByteMap = Q; 
      break;
    case 'R' :  
      curByteMap = R; 
      break;
    case 'S' :  
      curByteMap = S; 
      break;
    case 'T' :  
      curByteMap = T; 
      break;
    case 'U' :  
      curByteMap = U; 
      break;
    case 'V' :  
      curByteMap = V; 
      break;
    case 'W' :  
      curByteMap = W;  
      charWidth = 5; 
      break;
    case 'X' :  
      curByteMap = X;  
      charWidth = 5; 
      break;
    case 'Y' :  
      curByteMap = Y; 
      break;
    case 'Z' :  
      curByteMap = Z; 
      break;
    case '1' :  
      curByteMap = smile; 
      charWidth = 7; 
      break;
    case 32 :  
      curByteMap = space; 
      break;

    }
    for(int i = 0; i< charWidth; i++){
      for(int height = 0; height < 7; height++){
        if(bitRead(curByteMap[i],height)){
          world[pos][height+8] = color; 
        }
        else{
          world[pos][height+8] = CRGB::Black; 
        }


      }

      pos++;

    }
    stringPos++;
    pos++;

  }
  draw();
}

void dispStringBottom(String words, int offset, CRGB color){
  int pos = 0;
  int stringPos = 0;
  words.toUpperCase();
  int strlen = words.length();
  while(stringPos < strlen){
    if((pos-offset)<MATRIX_W){ 
      Serial.println(pos - offset);
      char curChar = words.charAt(stringPos);
      byte* curByteMap;
      int charWidth = 4;
      switch(curChar){
      case 'A' :  
        curByteMap = a; 
        break;
      case 'B' :  
        curByteMap = B; 
        break;
      case 'C' :  
        curByteMap = C; 
        break;
      case 'D' :  
        curByteMap = D; 
        break;
      case 'E' :  
        curByteMap = E; 
        break;
      case 'F' :  
        curByteMap = F; 
        break;
      case 'G' :  
        curByteMap = G; 
        break;
      case 'H' :  
        curByteMap = H; 
        break;
      case 'I' :  
        curByteMap = I; 
        break;
      case 'J' :  
        curByteMap = J; 
        break;
      case 'K' :  
        curByteMap = K; 
        break;
      case 'L' :  
        curByteMap = L; 
        break;
      case 'M' :  
        curByteMap = M; 
        charWidth = 5; 
        break;
      case 'N' :  
        curByteMap = N;  
        charWidth = 5; 
        break;
      case 'O' :  
        curByteMap = O; 
        break;
      case 'P' :  
        curByteMap = P; 
        break;
      case 'Q' :  
        curByteMap = Q; 
        break;
      case 'R' :  
        curByteMap = R; 
        break;
      case 'S' :  
        curByteMap = S; 
        break;
      case 'T' :  
        curByteMap = T; 
        break;
      case 'U' :  
        curByteMap = U; 
        break;
      case 'V' :  
        curByteMap = V; 
        break;
      case 'W' :  
        curByteMap = W;  
        charWidth = 5; 
        break;
      case 'X' :  
        curByteMap = X;  
        charWidth = 5; 
        break;
      case 'Y' :  
        curByteMap = Y; 
        break;
      case 'Z' :  
        curByteMap = Z; 
        break;
      case '1' :  
        curByteMap = smile; 
        charWidth = 7; 
        break;
      case 32 :  
        curByteMap = space; 
        break;

      }



      for(int i = 0; i< charWidth; i++){
        if((pos-offset) >= 0 && (pos-offset)<MATRIX_W){
          for(int height = 0; height < 7; height++){
            if(bitRead(curByteMap[i],height)){
              world[pos-offset][height+8] = color; 
            }
            else{
              world[pos-offset][height+8] = CRGB::Black; 
            }


          }
        }
        pos++;

      }
      if((pos-offset) >= 0 && (pos-offset)<MATRIX_W){
        for(int height = 0; height < 7; height++){
          world[pos-offset][height+8] = CRGB::Black; 
        }
      }

      pos++;
      stringPos++;

    }
    else break;
  }
  draw();
}



void drawLine(int x1 ,  int y1 , int x2, int y2, CRGB color){


  int xdif = x2-x1;
  int ydif = y2-y1;


  int steps = max(abs(xdif),abs(ydif));

  double xStep = (double)xdif / (double)steps;
  double yStep  = (double)ydif / (double)steps;

  for(int i = 0; i <steps+1; i++){
    world[x1+(int)round(xStep*i)][y1+(int)round(yStep*i)] = color; 
  }  
 // draw();
}


void fillBox(int x1 ,  int y1 , int x2, int y2, CRGB color){


  for(int i = x1; i <x2; i++){
    for(int j = y1; j <y2; j++){

      world[i][j] = color; 
    }
  }  
  draw();
}




























