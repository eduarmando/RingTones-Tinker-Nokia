/*
 *      File: Practica-5.c
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

#include "ToneScales.h"
#include <wiringPi.h>
#include <softTone.h>

#define SIZE 6
#define PIN 7

int main()
{
    unsigned char* string;
    unsigned char* note;
    double scale;
    char auxDelay[SIZE], auxScale[SIZE];
    int delayTime;
    bool flag;
				   
	wiringPiSetup () ;
  	softToneCreate (PIN) ;

	for (;;){
    
        /*Adams Family v1.0 (Tempo=70) <http://titoreds.tripod.com/pop.htm>*/
        //string = strdup("2#f7 4#f7 4#f7 4#f7 2b7 8#d8 2b7 8#g7 2e7 2#c8 8a7 2#a7 8#c8 2#a7 8#f7 2#d7 2b7 8#f7 2b7 8#d8 2b7 8#g7 2e7 2#c8 8b7 2#a7 8#f7 2#g7 8#a7 1b7 8#f7 2b7 8#d8 2b7 8#g7 2e7 2#c8 8a7 2#a7 8#c8 2#a7 8#f7 2#d7 2b7 8#f7 2b7 8#d8 2b7 8#g7 2e7");
        
        /*Austin Powers (Tempo=100)  <http://titoreds.tripod.com/pop.htm>*/
        string = strdup("2b6 4#c6 2#c6 4e6 4#c6 4#f6 2e6 2#c6 2e6 4g6 4e6 4a6 4g6 4e6 2e6 4e6 4e6 4b5 4d6 4e6 4b5 2d6 4e6 4b5 2d6 4e6 2d6 4e6 4e6 4d6 4e6 4g6 4a6 4g6 2b6 2b6 4d6 2b6 4d6 4e6 4e6 4e6 4d6 4b6 4a6 4g6 4d6 4e6 4b5 4d6");
        
		while((note = strsep(&string," ")) != NULL ){
			flag = false;
			for (int i=0, j=0; note[i]!='\0'; i++){
				auxDelay[i]='\0';
				auxScale[j]='\0';
				if((isdigit(note[i]) != 0) && (flag==false)){
					strcat(auxDelay,&note[i]);
				}
				else{
					 if(note[i] == '-'){
					     flag = true;
					     scale = 0.0;
					     break;
					 }
					 else{
						flag = true;
						strcat(auxScale,&note[i]);
		                j++;			         
					 }
				}
			}
			delayTime = readDelayValue(auxDelay);
			scale = readScaleValue(auxScale);
			printf("%d - %.2f\n",delayTime,scale);
		    softToneWrite (PIN, escala) ;
			delay(delayTime);
		}
    }
    return(0);
}
