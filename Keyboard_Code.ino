#include "pitches.h"
int keyNotes[] = {2,3,4,5,6,7,8,9}; //use pins 2,3,4,5,6,7,8,9
int speaker = 11;

int c[] = {N_C5}; //Plays C Note
int d[] = {N_D5}; //Plays D Note
int e[] = {N_E5}; //Plays E Note
int f[] = {N_F5}; //Plays F Note
int g[] = {N_G5}; //Plays G Note
int a[] = {N_A5}; //Plays A Note
int b[] = {N_B5}; //Plays B Note
int c2[] = {N_C6};

int duration = 100;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
  {
    pinMode(keyNotes[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int keyPress[8];
  for(int i = 0; i < 8; i++)
  {
      keyPress[i] = digitalRead(keyNotes[i]);
  }
  if ((keyPress[0]) == HIGH) { //Reads button state when pressed
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, c[Note], duration); //Plays note on pin 6, where the Buzzer is connected (change it if you connected it on another pin)
    }
  }
  if ((keyPress[1]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, d[Note], duration); 
    }
  }
  if ((keyPress[2]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, e[Note], duration);
    }
  }
  if ((keyPress[3]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, f[Note], duration);
    }
  }
  if ((keyPress[4]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, g[Note], duration);
    }
  }
  if ((keyPress[5]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, a[Note], duration);
    }
  }
  if ((keyPress[6]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(speaker, b[Note], duration);
    }
  }
  if ((keyPress[7]) == HIGH) {
     for (int Note = 0; Note < 1; Note++) {
      tone(speaker, c2[Note], duration);
    } 
  } 
  delay(5);

}
