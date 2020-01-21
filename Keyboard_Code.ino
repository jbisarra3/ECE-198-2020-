#include "pitches.h"
int keyNotes[] = {2,3,4,5,6,7,8,9};

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
      char buf[20];
      sprintf(buf,"%d: %d ", i, keyPress[i]);  //format two ints into character array
      Serial.print(buf);
   
  }
  Serial.println();
  if ((keyPress[0]) == HIGH) { //Reads button state when pressed
    for (int Note = 0; Note < 1; Note++) {
      tone(11, c[Note], duration); //Plays note on pin 6, where the Buzzer is connected (change it if you connected it on another pin)
    }
  }
  if ((keyPress[1]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, d[Note], duration); 
    }
  }
  if ((keyPress[2]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, e[Note], duration);
    }
  }
  if ((keyPress[3]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, f[Note], duration);
    }
  }
  if ((keyPress[4]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, g[Note], duration);
    }
  }
  if ((keyPress[5]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, a[Note], duration);
    }
  }
  if ((keyPress[6]) == HIGH) {
    for (int Note = 0; Note < 1; Note++) {
      tone(11, b[Note], duration);
    }
  }
  if ((keyPress[7]) == HIGH) {
     for (int Note = 0; Note < 1; Note++) {
      tone(11, c2[Note], duration);
    } 
  } 
  delay(5);

}
