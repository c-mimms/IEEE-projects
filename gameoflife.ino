/*
||
 || 
 ||Chris Mimms
 
 Adapted from Dane Stayskals 1dim game of life.
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
int world[MATRIX_W][MATRIX_H];
int counter;
/* 
 ==========================================
 = setup()
 = Initializes needed variables and drivers, called by Arduino once during initialization.
 */
void setup() {
  // Initialize the LED interface
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
  // Plant some entropy and watch it grow!  
  for(int i = 0; i < MATRIX_W; i++){
    for(int j = 0; j < MATRIX_H; j++){
      if(random(10)>4){
        world[i][j] = 1;
      }
    }
  }
  counter = 0;
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
      int neighbors = (world[i_up][j_right] + world[i_up][j] + world[i_up][j_left] + 
        world[i][j_left] + world[i_down][j_left] + world[i_down][j] + 
        world[i_down][j_right] + world[i][j_right]);

      // Any live cell with fewer than two live neighbours dies, as if caused by under-population.
      if (world[i][j] >= 1 && neighbors < 2) {
        next_generation[i][j] = 0;
      }
      // Any live cell with two or three live neighbours lives on to the next generation.
      if (world[i][j] >= 1 && (neighbors == 2 || neighbors == 3)) {
        next_generation[i][j] = 1;
      }
      // Any live cell with more than three live neighbours dies, as if by overcrowding.
      if (world[i][j] >=1 && neighbors > 3) {
        next_generation[i][j] = 0;
      }	
      // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
      if (world[i][j] < 1 && neighbors == 3) {
        next_generation[i][j] = 2;
      }

    }
  }

  // Pass on the torch
  for (int i = 0; i < MATRIX_W; i++) {
    for (int j = 0; j < MATRIX_H; j++) {
      world[i][j] = next_generation[i][j];
    }
  }

  for ( int i = 1; i < NUM_LEDS; i++){
    int temp = i/MATRIX_W;
    if(temp%2 == 0){
      if(world[i%MATRIX_W][temp] == 1){
        leds[i-1] =CRGB::Green;
      }
      else if(world[i%MATRIX_W][temp] == 2 ){
        world[i%MATRIX_W][temp] =1;
        leds[i-1] =CRGB(50,0,120);
      }
      else{
        if(leds[i-1].g >50){
          leds[i-1].g -=20;
          leds[i-1].r +=80;

        }
        else{
          leds[i-1] = CRGB::Black;
        }
      }
    }
    else{
      if(world[MATRIX_W-i%MATRIX_W-1][temp] ==1){

        leds[i-1] =CRGB::Green;
      }
      if(world[MATRIX_W-i%MATRIX_W-1][temp] ==2){
        world[MATRIX_W-i%MATRIX_W-1][temp] =1;
        leds[i-1] =CRGB(50,0,120);
      }
      else{
        if(leds[i-1].g >50){
          leds[i-1].g -=50;
          leds[i-1].r +=50;

        }
        else{
          leds[i-1] = CRGB::Black;
        }
      }
    }

    // Downsample to an array that we can actually display
  }
  FastLED.show();
  delay(15);
  counter ++;
  if(counter == 200) setup();

}



