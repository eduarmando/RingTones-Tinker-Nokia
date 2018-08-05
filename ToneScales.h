/*
 *      File: ToneScales.h
 *      Practica #05 Microcomputadoras
 *      Reproductor de Ring Tones Nokia
 *      gcc -o Practica-5 Practica-5.c -lwiringPi && sudo ./Practica-5
 *      Repo: <https://github.com/eduarmando/RingTones-Tinker-Nokia>
 */

/*  
 *      LED Pin - wiringPi pin 0 is ASSU_PI_GPIO 164 = 11
 *      LED Pin - wiringPi pin 1 is ASSU_PI_GPIO 184 = 12
 *      LED Pin - wiringPi pin 2 is ASSU_PI_GPIO 166 = 13
 *      LED Pin - wiringPi pin 3 is ASSU_PI_GPIO 167 = 15
 *      LED Pin - wiringPi pin 4 is ASSU_PI_GPIO 162 = 16
 *      LED Pin - wiringPi pin 5 is ASSU_PI_GPIO 163 = 18
 *      LED Pin - wiringPi pin 6 is ASSU_PI_GPIO 171 = 22
 *      LED Pin - wiringPi pin 7 is ASSU_PI_GPIO 17  = 7
 *      LED Pin - wiringPi pin 21 is ASSU_PI_GPIO 165 = 29
 */
 
#ifndef TONESCALES_H
#define TONESCALES_H
 
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define ROW_SIZE 12
#define COLUMN_SIZE 9
#define ARRAY_SIZE 6

double nokiaScales[ROW_SIZE][COLUMN_SIZE] = {  
   {16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01} ,
   {17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92} , 
   {18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.64} , 
   {19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03} , 
   {20.60, 41.20, 82.41, 164.81, 329.63, 659.26, 1318.51, 2637.02, 0} , 
   {21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 0} , 
   {23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96, 0} , 
   {24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 0} , 
   {25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44, 0} ,
   {27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 0} ,
   {29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 0} ,
   {30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.00, 0} 
};


/*Notas:
*   C – Do / D – Re / E – Mi / F – Fa / G – Sol / A – La / B – Si
*   # - Sostenidos
*/

const char *notes[ROW_SIZE][COLUMN_SIZE] = {  
   {"c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9"} ,
   {"#c1", "#c2", "#c3", "#c4", "#c5", "#c6", "#c7", "#c8", "#c9"} ,
   {"d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9"} ,
   {"#d1", "#d2", "#d3", "#d4", "#d5", "#d6", "#d7", "#d8", "#d9"} ,
   {"e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", "null"} ,
   {"f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "null"} ,
   {"#f1", "#f2", "#f3", "#f4", "#f5", "#f6", "#f7", "#f8", "null"} ,
   {"g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8", "null"} ,
   {"#g1", "#g2", "#g3", "#g4", "#g5", "#g6", "#g7", "#g8", "null"} ,
   {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "null"} ,
   {"#a1", "#a2", "#a3", "#a4", "#a5", "#a6", "#a7", "#a8", "null"} ,
   {"b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "null"} 
};
 

const char *timeNoteValue[ARRAY_SIZE] = {"1", "2", "4", "8", "16", "32"};

int timeDelayValue[ARRAY_SIZE] = {1000, 500, 250, 125, 62, 31};

double readScaleValue(unsigned char *value){
    double scale = 0.00;
	for (int i=0; i<ROW_SIZE; i++) {
		for (int j=0; j<COLUMN_SIZE; j++) {
			if (strcmp( notes[i][j], value ) == 0){
				scale = nokiaScales[i][j];
				break;
			}
		}
	}
	return scale;
}

int readDelayValue(unsigned char *value){
    int delayValue = 0;
	for (int i=0; i<ARRAY_SIZE; i++) {
		if (strcmp( timeNoteValue[i], value) == 0){
			delayValue = timeDelayValue[i];
			break;
		}
	}
	return delayValue;
}

#endif