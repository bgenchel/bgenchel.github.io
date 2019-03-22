#include "arduinoFFT.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
 
#define SAMPLES 1024             //Must be a power of 2
#define SAMPLING_FREQUENCY 1000 //Hz, must be less than 10000 due to ADC
 
arduinoFFT FFT = arduinoFFT();


AudioPlaySdWav           playWav1;
AudioOutputAnalog        audioOutput;


AudioConnection          patchCord2(playWav1, 0, audioOutput, 0);
AudioConnection          patchCord3(playWav1, 1, audioOutput, 1);

#define SDCARD_CS_PIN    BUILTIN_SDCARD
 
unsigned int sampling_period_us;
unsigned long microseconds;
 
double vReal[SAMPLES];
double vImag[SAMPLES];
int sens = 360;
 
void setup() {
    Serial.begin(115200);
    AudioMemory(40);
    sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
    if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while(1){
    Serial.println("Unable to access the SD card");
    delay(500);
    }
    }
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(5);

  // Simply wait for the file to finish playing.
  while (playWav1.isPlaying()) {
   
  }
}




void loop() {
   
    /*SAMPLING*/
    for(int i=0; i<SAMPLES; i++)
    {
        microseconds = micros();    //Overflows after around 70 minutes!
     
        vReal[i] = analogRead(2);
        vImag[i] = 0;
     
        while(micros() < (microseconds + sampling_period_us)){
        }
    }
 
    /*FFT*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    
    /*PRINT RESULTS*/
    //Serial.println(peak);     //Print out what frequency is the most dominant.
    int note = (int) peak;
    double freq = 0;
    //Serial.println(vReal[note]);
    if (vReal[note] > sens)
    {
    Serial.println();
    Serial.print("Freq is ");
    Serial.print(peak);
    Serial.println();
    freq = peak;
    }

    //double freq = peak;

    //IF STATEMENTS
if (freq < 53.75)
{
  //Serial.printf("The note is outside of the range");
}
else if (freq >= 53.75 && freq < 56.25)
            {
              //play file 085
              playFile("0085.WAV");  // filenames are always uppercase 8.3 format
              //digitalWrite(MID, HIGH);
                  delay(300);
            }
else if (freq >= 56.25 && freq < 56.5)
            {
              //play file 096
              playFile("0096.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 56.5 && freq < 56.75)
            {
              //play file 107
              playFile("0107.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 56.75 && freq < 59.25)
            {
              //play file 106
              playFile("0085.WAV");  // filenames are always uppercase 8.3 format
                 delay(300);
            }
else if (freq >= 59.25 && freq < 60)
            {
              //play file 117
              playFile("0117.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 60 && freq < 60.75)
            {
              //play file 128
              playFile("0128.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 60.75 && freq < 63.25)
            {
              //play file 127
              playFile("0127.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 63.25 && freq < 63.5)
            {
              //play file 138
              playFile("0138.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 63.5 && freq < 63.75)
            {
              //play file 149
              playFile("0149.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 63.75 && freq < 66.25)
            {
              //play file 148
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 66.25 && freq < 67)
            {
              //play file 159
              playFile("0159.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 67 && freq < 67.75)
            {
              //play file 170
              playFile("0170.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 67.75 && freq < 70.25)
            {
              //play file 169
              playFile("0169.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 70.25 && freq < 71)
            {
              //play file 180
              playFile("0180.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
 else if (freq >= 71 && freq < 71.75)
            {
              //play file 190
              playFile("0190.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 71.75 && freq < 74.25)
            {
              //play file 189
              playFile("0189.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 74.25 && freq < 75.5)
            {
              //play file 201
              playFile("0201.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 75.5 && freq < 76.75)
            {
              //play file 223
              playFile("0212.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 76.75 && freq < 79.25)
            {
              //play file 222
              playFile("0211.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 79.25 && freq < 80)
            {
              //play file 233
              playFile("0233.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 80 && freq < 80.75)
            {
              //play file 212
              //playFile("0212.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 80.75 && freq < 83.25)
            {
              //play file 0211
              //playFile("0211.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 83.25 && freq < 84.5)
            {
              //play file 003
              //playFile("0003.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 84.5 && freq < 85.75)
            {
              //play file 002
              playFile("0001.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 85.75 && freq < 88.25)
            {
              //play file 001
              playFile("0001.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 88.25 && freq < 89.5)
            {
             //play file 012
              playFile("0012.WAV");  // filenames are always uppercase 8.3 format
                  delay(300); 
            } 
  else if (freq >= 89.5 && freq < 90)
            {
              //play file 013
              playFile("0013.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 90 && freq < 90.5)
            {
              //play file 024
              playFile("0024.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 90.5 && freq < 91.75)
            {
              //play file 023
              playFile("0023.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 91.75 && freq < 94.25)
            {
              //play file 022
              playFile("0022.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 94.25 && freq < 95.5)
            {
              //play file 033
              playFile("0033.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 95.5 && freq < 96.75)
            {
              //play file 044
              playFile("0044.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 96.75 && freq < 99.25)
            {
              //play file 043
              playFile("0043.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 99.25 && freq < 100.5)
            {
              //play file 054
              playFile("0054.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 100.5 && freq < 101)
            {
              //play file 055
              playFile("0055.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 101 && freq < 101.5)
            {
              //play file 066
              playFile("0066.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 101.5 && freq < 102.75)
            {
              //play file 065
              playFile("0065.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 102.75 && freq < 105.25)
            {
              //play file 064
              playFile("0064.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
            else if (freq >= 105.25 && freq < 106.5)
            {
              //play file 075
              playFile("0075.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 106.5 && freq < 107)
            {
              //play file 076
              playFile("0076.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 107 && freq < 107.5)
            {
              //play file 087
              playFile("0087.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 107.5 && freq < 108.75)
            {
              //play file 086
              playFile("0086.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 108.75 && freq < 111.25)
            {
              //play file 085
              playFile("0085.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 111.25 && freq < 112.5)
            {
              //play file 096
              playFile("0096.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 112.5 && freq < 113.5)
            {
              //play file 097
              playFile("0097.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 113.5 && freq < 114.5)
            {
              //play file 108
              playFile("0108.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 114.5 && freq < 115.75)
            {
              //play file 107
              playFile("0107.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 115.75 && freq < 118.25)
            {
              //play file 106
              playFile("0106.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 118.25 && freq < 119.5)
            {
              //play file 117
              playFile("0117.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 119.5 && freq < 120.5)
            {
              //play file 118
              playFile("0118.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 120.5 && freq < 121.5)
            {
              //play file 129
              playFile("0129.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 121.5 && freq < 122.75)
            {
              //play file 128
              playFile("0128.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 122.75 && freq < 125.25)
            {
              //play file 127
              playFile("0127.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 125.25 && freq < 126.5)
            {
              //play file 138
              playFile("0138.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 126.5 && freq < 127.5)
            {
              //play file 139
              playFile("0139.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 127.5 && freq < 128.5)
            {
              //play file 150
              playFile("0150.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 128.5 && freq < 129.75)
            {
              //play file 149
              playFile("0149.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 129.75 && freq < 132.25)
            {
              //play file 148
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 132.25 && freq < 133.5)
            {
              //play file 159
              playFile("0159.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 133.5 && freq < 134.75)
            {
              //play file 160
              playFile("0160.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 134.75 && freq < 135)
            {
              //play file 161
              playFile("0161.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 135 && freq < 135.25)
            {
              //play file 172
              playFile("0172.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 135.25 && freq < 136.5)
            {
              //play file 171
              playFile("0171.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 136.5 && freq < 137.75)
            {
              //play file 170
              playFile("0170.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 137.75 && freq < 140.25)
            {
              //play file 169
              playFile("0169.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            } 
  else if (freq >= 140.25 && freq < 141.5)
            {
              //play file 180
              playFile("0180.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 141.5 && freq < 142.75)
            {
              //play file 181
              playFile("0181.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 142.75 && freq < 143)
            {
              //play file 182
              playFile("0182.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 143 && freq < 143.25)
            {
              //play file 193
              playFile("0193.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 143.25 && freq < 144.5)
            {
              //play file 192
              playFile("0192.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 144.5 && freq < 145.75)
            {
              //play file 191
              playFile("0191.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 145.75 && freq < 148.25)
            {
              //play file 190
              playFile("0190.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 148.25 && freq < 149.5)
            {
              //play file 201
              playFile("0201.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 149.5 && freq < 150.75)
            {
              //play file 202
              playFile("0202.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 150.75 && freq < 151.5)
            {
              //play file 203
              playFile("0203.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 151.5 && freq < 152.25)
            {
              //play file 225
              playFile("0225.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 152.25 && freq < 153.5)
            {
              //play file 224
              playFile("0224.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 153.5 && freq < 154.75)
            {
              //play file 223
              playFile("0223.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 154.75 && freq < 157.25)
            {
              //play file 222
              playFile("0222.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 157.25 && freq < 158.5)
            {
              //play file 233
              playFile("0233.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 158.5 && freq < 159.75)
            {
              //play file 234
              playFile("0234.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 159.75 && freq < 160.5)
            {
              //play file 235
              playFile("0235.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 160.5 && freq < 161.25)
            {
              //play file 214
              playFile("0214.WAV");  // filenames are always uppercase 8.3 format
                  //delay(300);
            }
  else if (freq >= 161.25 && freq < 162.5)
            {
              //play file 213
              playFile("0213.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 162.5 && freq < 163.75)
            {
              //play file 212
              playFile("0212.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 163.75 && freq < 166.25)
            {
              //play file 211
              playFile("0211.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 166.25 && freq < 167.5)
            {
              //play file 007
              playFile("0007.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 167.5 && freq < 168.75)
            {
              //play file 006
              playFile("0006.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 168.75 && freq < 170)
            {
              //play file 005
              playFile("0005.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 170 && freq < 171.25)
            {
              //play file 004
              playFile("0004.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 171.25 && freq < 172.5)
            {
              //play file 003
              playFile("0003.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 172.5 && freq < 173.75)
            {
              //play file 002
              playFile("0002.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 173.75 && freq < 176.25)
            {
              //play file 001
              playFile("0001.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 176.25 && freq < 177.5)
            {
              //play file 012
              playFile("0012.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 177.5 && freq < 178.75)
            {
              //play file 013
              playFile("0013.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 178.75 && freq < 180)
            {
              //play file 014
              playFile("0014.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 180 && freq < 181.25)
            {
              //play file 025
              playFile("0025.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 181.25 && freq < 182.5)
            {
              //play file 024
              playFile("0024.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 182.5 && freq < 183.75)
            {
              //play file 023
              playFile("0023.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 183.75 && freq < 186.25)
            {
              //play file 022
              playFile("0022.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 186.25 && freq < 187.5)
            {
              //play file 033
              playFile("0033.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 187.5 && freq < 188.75)
            {
              //play file 034
              playFile("0034.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 188.75 && freq < 190)
            {
              //play file 035
              playFile("0035.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 190 && freq < 190.5)
            {
              //play file 036
              playFile("0036.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 190.5 && freq < 191)
            {
              //play file 047
              playFile("0047.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 191 && freq < 192.25)
            {
              //play file 046
              playFile("0046.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 192.25 && freq < 193.5)
            {
              //play file 045
              playFile("0045.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 193.5 && freq < 194.75)
            {
              //play file 044
              playFile("0044.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 194.75 && freq < 197.25)
            {
              //play file 043
              playFile("0043.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 197.25 && freq < 198.5)
            {
              //play file 054
              playFile("0054.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 198.5 && freq < 199.75)
            {
              //play file 055
              playFile("0055.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 199.75 && freq < 201)
            {
              //play file 056
              playFile("0056.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 201 && freq < 202)
            {
              //play file 057
              playFile("0057.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 202 && freq < 203)
            {
              //play file 068
              playFile("0068.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 203 && freq < 204.25)
            {
              //play file 067
              playFile("0067.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 204.25 && freq < 205.5)
            {
              //play file 066
              playFile("0066.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 205.5 && freq < 206.75)
            {
              //play file 065
              playFile("0065.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 206.75 && freq < 209.25)
            {
              //play file 064
              playFile("0064.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 209.25 && freq < 210.5)
            {
              //play file 075
              playFile("0075.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 210.5 && freq < 211.75)
            {
              //play file 076
              playFile("0076.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 211.75 && freq < 213)
            {
              //play file 077
              playFile("0077.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 213 && freq < 214)
            {
              //play file 078
              playFile("0078.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 214 && freq < 215)
            {
              //play file 089
              playFile("0089.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 215 && freq < 216.25)
            {
              //play file 088
              playFile("0088.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 216.25 && freq < 217.5)
            {
              //play file 087
              playFile("0087.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 217.5 && freq < 218.75)
            {
              //play file 086
              playFile("0086.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
else if (freq >= 218.75 && freq < 221.25)
            {
              //play file 085
              playFile("0085.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 221.25 && freq < 222.5)
            {
              //play file 096
              playFile("0096.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 222.5 && freq < 223.75)
            {
              //play file 097
              playFile("0097.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 223.75 && freq < 225)
            {
              //play file 098
              playFile("0098.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 225 && freq < 226.25)
            {
              //play file 099
              playFile("0099.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
  else if (freq >= 226.25 && freq < 227.5)
            {
              //play file 100
              playFile("0100.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 227.5 && freq < 228.75)
            {
              //play file 110
              playFile("0110.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 228.75 && freq < 230)
            {
              //play file 109
              playFile("0109.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 230 && freq < 231.25)
            {
              //play file 108
              playFile("0108.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 231.25 && freq < 231.75)
            {
              //play file 107
              playFile("0107.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 231.75 && freq < 234.25)
            {
              //play file 106
              playFile("0106.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 234.25 && freq < 235.5)
            {
              //play file 117
              playFile("0117.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 235.5 && freq < 236.75)
            {
              //play file 118
              playFile("0118.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 236.75 && freq < 238)
            {
              //play file 119
              playFile("0119.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 238 && freq < 239.25)
            {
              //play file 120
              playFile("0120.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
  else if (freq >= 239.25 && freq < 240.5)
            {
              //play file 121
              playFile("0121.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 240.5 && freq < 242)
            {
              //play file 131
              playFile("0131.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 242 && freq < 243.25)
            {
              //play file 130
              playFile("0130.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 243.25 && freq < 244.5)
            {
              //play file 129
              playFile("0129.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 244.5 && freq < 245.75)
            {
               //play file 128
               playFile("0128.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);  
            }
            else if (freq >= 245.75 && freq < 248.25)
            {
              //play file 127
              playFile("0127.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 248.25 && freq < 249.5)
            {
              //play file 138
              playFile("0138.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 249.5 && freq < 250.75)
            {
              //play file 139 
              playFile("0149.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);  
            }
            else if (freq >= 250.75 && freq < 252)
            {
              //play file 140
              playFile("0140.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);   
            }
            else if (freq >= 252 && freq < 253.25)
            {
              //play file 141
              playFile("0141.WAV");  // filenames are always uppercase 8.3 format
                 delay(300);   
            }
            else if (freq >= 253.25 && freq < 254.5)
            {
              //play file 142
              playFile("0142.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 254.5 && freq < 255.75)
            {
              //play file 153
              playFile("0153.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 255.75 && freq < 257)
            {
              //play file 152
              playFile("0152.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 257 && freq < 258.25)
            {
              //play file 151
              playFile("0151.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 258.25 && freq < 259.5)
            {
              //play file 150
              playFile("0150.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 259.5 && freq < 260.75)
            {
              //play file 149
              playFile("0149.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 260.75 && freq < 263.25)
            {
              //play file 148
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 263.25 && freq < 264.5)
            {
              //play file 159
              playFile("0159.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 264.5 && freq < 265.75)
            {
              //play file 160
              playFile("0160.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 265.75 && freq < 267)
            {
              //play file 161
              playFile("0161.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 267 && freq < 268.25)
            {
              //play file 162
              playFile("0162.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 268.25 && freq < 269.5)
            {
              //play file 163
              playFile("0163.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 269.5 && freq < 270.75)
            {
              //play file 174
              playFile("0174.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 270.75 && freq < 272)
            {
              //play file 173
              playFile("0173.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 272 && freq < 273.25)
            {
              //play file 172
              playFile("0172.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 273.25 && freq < 274.5)
            {
              //play file 171
              playFile("0171.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 274.5 && freq < 275.75)
            {
              //play file 170
              playFile("0170.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 275.75 && freq < 278.25)
            {
              //play 169
              playFile("0169.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
            }
            else if (freq >= 278.25 && freq < 279.5)
            {
              //play file 180
              playFile("0180.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 279.5 && freq < 280.75)
            {
              //play file 181
              playFile("0181.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 280.75 && freq < 282)
            {
              //play file 182
              playFile("0182.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 282 && freq < 283.25)
            {
              //play file 183
              playFile("0183.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 283.25 && freq < 284.5)
            {
              //play file 184
              playFile("0184.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 284.5 && freq < 285.5)
            {
              //play file 185
              playFile("0185.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
}
else if (freq >= 285.5 && freq < 286.5)
            {
              //play file 196
              playFile("0196.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 286.5 && freq < 287.75)
            {
              //play file 195
              playFile("0195.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 287.75 && freq < 289)
            {
              //play file 194
              playFile("0194.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 289 && freq < 290.25)
            {
              //play file 193 
              playFile("0193.WAV");  // filenames are always uppercase 8.3 format
                delay(300);  
            }
            else if (freq >= 290.25 && freq < 291.5)
            {
              //play file 192
              playFile("0192.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 291.5 && freq < 292.75)
            {
              //play file 191
              playFile("0191.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 292.75 && freq < 295.25)
            {
              //play file 190
              playFile("0190.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 295.25 && freq < 296.5)
            {
              //play file 201
              playFile("0201.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 296.5 && freq < 297.75)
            {
              //play file 202
              playFile("0202.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 297.75 && freq < 299)
            {
              //play file 203
              playFile("0203.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 299 && freq < 300.25)
            {
              //play file 204
              playFile("0204.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 300.25 && freq < 301.5)
            {
              //play file 205
              playFile("0205.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 301.5 && freq < 302.75)
            {
              //play file 206
              playFile("0206.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 302.75 && freq < 304)
            {
              //play file 228
              playFile("0206.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 304 && freq < 305.25)
            {
              //play file 227
              playFile("0227.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 305.25 && freq < 306.5)
            {
              //play file 226
              playFile("0226.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 306.5 && freq < 307.75)
            {
              //play file 225
              playFile("0225.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 307.75 && freq < 309)
            {
              //play file 224
              playFile("0224.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 309 && freq < 309.75)
            {
              //play file 223
              playFile("0223.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
  else if (freq >= 309.75 && freq < 312.25)
            {
              //play file 222
              playFile("0222.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 312.25 && freq < 313.5)
            {
              //play file 233
              playFile("0233.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 313.5 && freq < 314.75)
            {
              //play file 234
              playFile("0234.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 314.75 && freq < 316)
            {
              //play file 235
              playFile("0235.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 316 && freq < 317.25)
            {
              //play file 236
              playFile("0236.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 317.25 && freq < 318.5)
            {
              //play file 237
              playFile("0237.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 318.5 && freq < 319.75)
            {
              //play file 238
              playFile("0238.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 319.75 && freq < 320.75)
            {
              //play file 239
              playFile("0239.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 320.75 && freq < 321.75)
            {
              //play file 218
              playFile("0218.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 321.75 && freq < 323)
            {
              //play file 217
              playFile("0217.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 323 && freq < 324.25)
            {
              //play file 216
              playFile("0216.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 324.25 && freq < 325.5)
            {
              //play file 215
              playFile("0215.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 325.5 && freq < 326.75)
            {
              //play file 214
              playFile("0214.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 326.75 && freq < 328)
            {
              //play file 213
              playFile("0213.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 328 && freq < 328.75)
            {
              //play file 212
              playFile("0212.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 328.75 && freq < 331.25)
            {
              //play file 211
              playFile("0211.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 331.25 && freq < 332.5)
            {
              //play file 011
              playFile("011.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 332.5 && freq < 333.75)
            {
              //play file 011
              playFile("0011.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 333.75 && freq < 335)
            {
              //play file 011
              playFile("0011.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 335 && freq < 336.25)
            {
              //play file 010
              playFile("0010.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 336.25 && freq < 337.5)
            {
              //play file 009
              playFile("0009.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
else if (freq >= 337.5 && freq < 339.5)
            {
              //play file 008
              playFile("0008.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            } 
            else if (freq >= 339.5 && freq < 340.75)
            {
              //play file 007
              playFile("0007.WAV");  // filenames are always uppercase 8.3 format
                  delay(300);
}
else if (freq >= 340.75 && freq < 342)
            {
              //play file 006
              playFile("0006.WAV");  // filenames are always uppercase 8.3 format
                delay(300);
            }
            else if (freq >= 342 && freq < 343.25)
            {
              //play file 005
              playFile("0005.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 343.25 && freq < 344.5)
            {
              //play file 004
              playFile("0004.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 344.5 && freq < 345.75)
            {
              //play file 003
              playFile("0003.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 345.75 && freq < 347.75)
            {
              //play file 002
              playFile("0002.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


            else if (freq >= 347.75 && freq < 350.25)
            {
              //play file 001
              playFile("0001.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 350.25 && freq < 351.5)
            {
              //play file 012
              playFile("0012.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 351.5 && freq < 352.75)
            {
              //play file 013
              playFile("0013.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 352.75 && freq < 354)
            {
              //play file 014
              playFile("0014.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 354 && freq < 355.25)
            {
              //play file 015
              playFile("0015.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 355.25 && freq < 356.5)
            {
              //play file 016
              playFile("0016.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 356.5 && freq < 357.75)
            {
              //play file 017
              playFile("0017.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }

            else if (freq >= 357.75 && freq < 359.25)
            {
              //play file 018
              playFile("0018.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 359.25 && freq < 360.75)
            {
              //play file 029
              playFile("0029.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 360.75 && freq < 362)
            {
              //play file 028
              playFile("0028.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 362 && freq < 363.25)
            {
              //play file 027
              playFile("0027.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 363.25 && freq < 364.5)
            {
              //play file 026
              playFile("0026.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 364.5 && freq < 365.75)
            {
              //play file 025
              playFile("0025.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 365.75 && freq < 367)
            {
              //play file 024
              playFile("0024.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


            else if (freq >= 367 && freq < 368.75)
            {
              //play file 023
              playFile("0023.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 368.75 && freq < 371.25)
            {
              //play file 022
              playFile("0022.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 371.25 && freq < 372.5)
            {
              //play file 033
              playFile("0033.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 372.5 && freq < 373.75)
            {
              //play file 033
              playFile("0033.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 373.75 && freq < 375)
            {
              //play file 034
              playFile("0034.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 375 && freq < 376.25)
            {
              //play file 035
              playFile("0035.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 376.25 && freq < 377.5)
            {
              //play file 036
              playFile("0036.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


else if (freq >= 377.5 && freq < 378.75)
            {
              //play file 037
              playFile("0037.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 378.75 && freq < 380)
            {
              //play file 038
              playFile("0038.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 380 && freq < 380.75)
            {
              //play file 039
              playFile("0039.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 380.75 && freq < 381.5)
            {
              //play file 051
              playFile("0051.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
            else if (freq >= 381.5 && freq < 382.75)
            {
              //play file 050
              playFile("0050.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 382.75 && freq < 384)
            {
              //play file 049
              playFile("0049.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 384 && freq < 385.25)
            {
              //play file 048
              playFile("0048.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


            else if (freq >= 385.25 && freq < 386.5)
            {
              //play file 047
              playFile("0047.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 386.5 && freq < 387.75)
            {
              //play file 046
              playFile("0046.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 387.75 && freq < 389)
            {
              //play file 045
              playFile("0045.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 389 && freq < 390.25)
            {
              //play file 044
              playFile("0044.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 390.25 && freq < 393.25)
            {
              //play file 
              //playFile("00.WAV");  // filenames are always uppercase 8.3 format
                //delay(300);   
            }
  else if (freq >= 393.25 && freq < 394.5)
            {
              //play file 054
              playFile("0054.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 393.25 && freq < 394.5)
            {
              //play file 055
              playFile("0055.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


        else if (freq >= 394.5 && freq < 395.75)
            {
              //play file 056
              playFile("0056.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 395.75 && freq < 397)
            {
              //play file 057
              playFile("0057.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 397 && freq < 398.25)
            {
              //play file 058
              playFile("0058.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 398.25 && freq < 399.5)
            {
              //play file 059
              playFile("0059.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 399.5 && freq < 400.75)
            {
              //play file 060
              playFile("0060.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 400.75 && freq < 402.25)
            {
              //play file 061
              playFile("0061.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 402.25 && freq < 403.75)
            {
              //play file 074
              playFile("0074.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


            else if (freq >= 403.75 && freq < 405)
            {
              //play file 073
              playFile("0073.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 402.25 && freq < 403.75)
            {
              //play file 072
              playFile("0072.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 403.75 && freq < 405)
            {
              //play file 071
              playFile("0071.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 405 && freq < 406.25)
            {
              //play file 070
              playFile("0070.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 406.25 && freq < 407.5)
            {
              //play file 069
              playFile("0069.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 407.5 && freq < 408.75)
            {
              //play file 068
              playFile("0068.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 408.75 && freq < 410)
            {
              //play file 067
              playFile("0067.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


    else if (freq >= 410 && freq < 411.25)
            {
              //play file 066
              playFile("0066.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 411.25 && freq < 412.5)
            {
              //play file 065
              playFile("0065.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 412.5 && freq < 416.25)
            {
              //play file 064
              playFile("0064.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 416.25 && freq < 417.5)
            {
              //play file 075
              playFile("0075.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 417.5 && freq < 418.75)
            {
              //play file 076
              playFile("0076.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 418.75 && freq < 420)
            {
              //play file 076
              playFile("0076.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 420 && freq < 421.25)
            {
              //play file 077
              playFile("0077.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


else if (freq >= 421.25 && freq < 422.5)
            {
              //play file 078
              playFile("0078.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 422.5 && freq < 423.75)
            {
              //play file 079
              playFile("0079.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 423.75 && freq < 425)
            {
              //play file 080
              playFile("0080.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 425 && freq < 426.25)
            {
              //play file 081
              playFile("0081.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 426.25 && freq < 427.5)
            {
              //play file 082
              playFile("0082.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 427.5 && freq < 428.75)
            {
              //play file 083
              playFile("0083.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 428.75 && freq < 430)
            {
              //play file 093
              playFile("0093.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


else if (freq >= 430 && freq < 431.25)
            {
              //play file 092
              playFile("0092.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 431.25 && freq < 432.5)
            {
              //play file 091
              playFile("0091.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 432.5 && freq < 433.75)
            {
              //play file 090
              playFile("0090.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 433.75 && freq < 435)
            {
              //play file 089
              playFile("0089.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 435 && freq < 436.25)
            {
              //play file 088
              playFile("0088.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 436.25 && freq < 437.5)
            {
              //play file 087
              playFile("0087.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
  else if (freq >= 437.5 && freq < 438.75)
            {
              //play file 086
              playFile("0086.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }


else if (freq >= 438.75 && freq < 441.25)
            {
              //play file 085
              playFile("0085.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 441.25 && freq < 442.5)
            {
              //play file 096
              playFile("0096.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 442.5 && freq < 443.75)
            {
              //play file 097
              playFile("0097.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }          
else if (freq >= 443.75 && freq < 445)
            {
              //play file 098
              playFile("0098.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 445 && freq < 446.25)
            {
              //play file 099
              playFile("0099.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 446.25 && freq < 447.5)
            {
              //play file 100
              playFile("0100.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 447.5 && freq < 448.75)
            {
              //play file 101
              playFile("0101.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 448.75 && freq < 450)
            {
              //play file 102
              playFile("0102.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 450 && freq < 451.25)
            {
              //play file 103
              playFile("0103.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }    
else if (freq >= 451.25 && freq < 452.5)
            {
              //play file 104
              playFile("0104.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }         
else if (freq >= 452.5 && freq < 453.75)
            {
              //play file 105
              playFile("0105.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 453.75 && freq < 455)
            {
              //play file 116
              playFile("0116.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 455 && freq < 456.25)
            {
              //play file 115
              playFile("0115.WAV");  // filenames are always uppercase 8.3 format
                delay(300);  
            }
else if (freq >= 456.25 && freq < 457.5)
            {
              //play file 114
              playFile("0114.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 457.5 && freq < 458.75)
            {
              //play file 113
              playFile("0113.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 458.75 && freq < 460)
            {
              //play file 112
              playFile("0112.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 460 && freq < 461.25)
            {
              //play file 111
              playFile("0112.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 461.25 && freq < 462.5)
            {
              //play file 110
              playFile("0110.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 462.5 && freq < 463.75)
            {
              //play file 109
              playFile("0109.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 463.75 && freq < 465.75)
            {
              //play file 108
              playFile("0108.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 465.75 && freq < 468.25)
            {
              //play file 106
              playFile("0106.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 468.25 && freq < 469.5)
            {
              //play file 117
              playFile("0117.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 469.5 && freq < 470.75)
            {
              //play file 118
              playFile("0106.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 470.75 && freq < 472)
            {
              //play file 119
              playFile("0119.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 472 && freq < 473.25)
            {
              //play file 120
              playFile("0120.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 473.25 && freq < 474.5)
            {
              //play file 121
              playFile("0121.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 474.5 && freq < 475.75)
            {
              //play file 122
              playFile("0122.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 475.75 && freq < 477)
            {
              //play file 123
              playFile("0123.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 477 && freq < 478.25)
            {
              //play file 124
              playFile("0124.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 478.25 && freq < 479.5)
            {
              //play file 125
              playFile("0125.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 479.5 && freq < 480.75)
            {
              //play file 126
              playFile("0126.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 480.75 && freq < 482)
            {
              //play file 137
              playFile("0137.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 482 && freq < 483.25)
            {
              //play file 136
              playFile("0136.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 483.25 && freq < 484.5)
            {
              //play file 135
              playFile("0135.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 484.5 && freq < 485.75)
            {
              //play file 134
              playFile("0134.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 485.75 && freq < 487)
            {
              //play file 133
              playFile("0133.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 487 && freq < 488.25)
            {
              //play file 132
              playFile("0132.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 488.25 && freq < 489.5)
            {
              //play file 131
              playFile("0131.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 489.5 && freq < 490.75)
            {
              //play file 130
              playFile("0130.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 490.75 && freq < 492)
            {
              //play file 129
              playFile("0129.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 492 && freq < 492.75)
            {
              //play file 128
              playFile("0128.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 492.75 && freq < 495.25)
            {
              //play file 127
              playFile("0127.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 495.25 && freq < 496.5)
            {
              //play file 138
              playFile("0138.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 496.5 && freq < 497.75)
            {
              //play file 139
              playFile("0139.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 497.75 && freq < 499)
            {
              //play file 140
              playFile("0151.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 499 && freq < 500.25)
            {
              //play file 141
              playFile("0141.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 500.25 && freq < 501.5)
            {
              //play file 142
              playFile("0142.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 501.5 && freq < 502.75)
            {
              //play file 143
              playFile("0143.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 502.75 && freq < 504)
            {
              //play file 144
              playFile("0144.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 504 && freq < 505.25)
            {
              //play file 145
              playFile("0145.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }                                                                     
else if (freq >= 505.25 && freq < 506.5)
            {
              //play file 146
              playFile("0146.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 506.5 && freq < 509)
            {
              //play file 147
              playFile("0147.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 509 && freq < 510.25)
            {
              //play file 158
              playFile("0158.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }                                                                                                                                                                                                       
else if (freq >= 510.25 && freq < 511.5)
            {
              //play file 157
              playFile("0157.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }           
else if (freq >= 511.75 && freq < 513)
            {
              //play file 156
              playFile("0156.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            } 
else if (freq >= 513 && freq < 514.25)
            {
              //play file 155
              playFile("0155.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 514.25 && freq < 515.5)
            {
              //play file 154
              playFile("0154.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 515.5 && freq < 516.75)
            {
              //play file 153
              playFile("0153.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 516.75 && freq < 518)
            {
              //play file 152
              playFile("0152.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 518 && freq < 519.25)
            {
              //play file 151
              playFile("0151.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }             
else if (freq >= 519.25 && freq < 520.5)
            {
              //play file 150
              playFile("0150.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }          
else if (freq >= 520.5 && freq < 521.75)
            {
              //play file 149
              playFile("0149.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 521.75 && freq < 524.25)
            {
              //play file 148
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 524.25 && freq < 525.5)
            {
              //play file 159
              playFile("0159.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 525.5 && freq < 526.75)
            {
              //play file 160
              playFile("0160.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 526.75 && freq < 528.25)
            {
              //play file 161
              playFile("0161.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 528.25 && freq < 529.5)
            {
              //play file 162
              playFile("0162.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 529.5 && freq < 530.75)
            {
              //play file 163
              playFile("0163.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 530.75 && freq < 532)
            {
              //play file 164
              playFile("0164.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 532 && freq < 533.25)
            {
              //play file 165
              playFile("0165.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 533.25 && freq < 534.5)
            {
              //play file 166
              playFile("0166.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 534.5 && freq < 535.75)
            {
              //play file 167
              playFile("0167.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 535.75 && freq < 539)
            {
              //play file 168
              playFile("0168.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 539 && freq < 540.25)
            {
              //play file 179
              playFile("0179.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 540.25 && freq < 541.5)
            {
              //play file 178
              playFile("0178.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 541.5 && freq < 542.75)
            {
              //play file 177
              playFile("0177.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 542.75 && freq < 544)
            {
              //play file 176
              playFile("0176.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 544 && freq < 545.25)
            {
              //play file 175
              playFile("0175.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 545.25 && freq < 546.5)
            {
              //play file 174
              playFile("0174.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 546.5 && freq < 547.75)
            {
              //play file 173
              playFile("0173.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 547.75 && freq < 549)
            {
              //play file 172
              playFile("0172.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 549 && freq < 550.25)
            {
              //play file 171
              playFile("0171.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 550.25 && freq < 552.75)
            {
              //play file 170
              playFile("0170.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 552.75 && freq < 555.25)
            {
              //play file 169
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 555.25 && freq < 556.5)
            {
              //play file 180
              playFile("0148.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 556.5 && freq < 557.75)
            {
              //play file 181
              playFile("0181.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 557.75 && freq < 559)
            {
              //play file 182
              playFile("0182.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 559 && freq < 560.25)
            {
              //play file 183
              playFile("0183.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 560.25 && freq < 561.5)
            {
              //play file 184
              playFile("0184.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 561.5 && freq < 562.75)
            {
              //play file 185
              playFile("0185.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 562.75 && freq < 564)
            {
              //play file 186
              playFile("0186.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 564 && freq < 565.25)
            {
              //play file 187
              playFile("0187.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 565.25 && freq < 566.5)
            {
              //play file 188
              playFile("0188.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
else if (freq >= 566.5 && freq < 567.75)
            {
              //play file 189
              playFile("0189.WAV");  // filenames are always uppercase 8.3 format
                delay(300);   
            }
                                            

    //delay(1000);  //Repeat the process every second OR:
    
}

