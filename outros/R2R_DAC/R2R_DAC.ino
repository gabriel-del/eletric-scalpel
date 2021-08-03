//R2R DAC. May 2018
//Define DAC pins here
#define DAC0 2
#define DAC1 3
#define DAC2 4
#define DAC3 5
#define DAC4 6
#define DAC5 7
#define DAC6 8
#define DAC7 9

byte i;
byte res = 100;   //Change this to the number of values in the array lookup tables

//Lookup tables for waveform
byte sinewave[200] = {128,132,136,139,143,147,151,155,
                      159,163,167,171,174,178,182,185,
                      189,192,196,199,202,206,209,212,
                      215,218,220,223,226,228,231,233,
                      235,237,239,241,243,245,246,247,
                      249,250,251,252,253,253,254,254,
                      255,255,255,255,255,254,254,253,
                      253,252,251,250,249,247,246,245,
                      243,241,239,237,235,233,231,228,
                      226,223,220,218,215,212,209,206,
                      202,199,196,192,189,185,182,178,
                      174,171,167,163,159,155,151,147,
                      143,139,136,132,128,123,119,116,
                      112,108,104,100,96,92,88,84,
                      81,77,73,70,66,63,59,56,
                      53,49,46,43,40,37,35,32,
                      29,27,24,22,20,18,16,14,
                      12,10,9,8,6,5,4,3,
                      2,2,1,1,0,0,0,0,
                      0,1,1,2,2,3,4,5,
                      6,8,9,10,12,14,16,18,
                      20,22,24,27,29,32,35,37,
                      40,43,46,49,53,56,59,63,
                      66,70,73,77,81,84,88,92,
                      96,100,104,108,112,116,119,123,
                      };


byte triwave[101] = {5,10,15,20,26,31,36,41,
                46,51,56,61,66,71,77,82,
                87,92,97,102,107,112,117,122,
                128,133,138,143,148,153,158,163,
                168,173,179,184,189,194,199,204,
                209,214,219,224,230,235,240,245,
                250,255,250,245,240,235,230,224,
                219,214,209,204,199,194,189,184,
                179,173,168,163,158,153,148,143,
                138,133,128,122,117,112,107,102,
                97,92,87,82,77,71,66,61,
                56,51,46,41,36,31,26,20,
                15,10,5,0
                };

byte sawwave[101] = {3,5,8,10,13,15,18,20,
                 23,26,28,31,33,36,38,41,
                 43,46,48,51,54,56,59,61,
                 64,66,69,71,74,77,79,82,
                 84,87,89,92,94,97,99,102,
                 105,107,110,112,115,117,120,122,
                 125,128,130,133,135,138,140,143,
                 145,148,150,153,156,158,161,163,
                 166,168,171,173,176,179,181,184,
                 186,189,191,194,196,199,201,204,
                 207,209,212,214,217,219,222,224,
                 227,230,232,235,237,240,242,245,
                 247,250,252,255,0
                 };

byte squarewave[50] = {0,0,0,0,0,0,0,0,0,0,
                   0,0,0,0,0,0,0,0,0,0,
                   255,255,255,255,255,255,255,255,255,255,
                   255,255,255,255,255,255,255,255,255,255
                   };

byte generated[100];    //For the generated waveform (Experimental)
                   
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
for(i=2;i<10;i++){pinMode(i,OUTPUT);}    //Set pins as outputs


//Crude code here for generating a triangle wave without a lookup table
//Experimental
  byte val = 0;                   //Start with 0
  for(i=0;i<51;i++){              //Rising Edge (0 to 50);
    generated[i] = (val + 5);     //Increment by 5 (255/50 rounded)
    val = generated[i];           //Add to array
  }
    val = generated[50];          //Starting point for next routine

  for(i=51;i<100;i++){            //Start at 51 for falling edge
    generated[i] = (val -5);      //Subtract 5
    val = generated[i];           //Add to array
  }

}//setup loop



void loop() {
  // put your main code here, to run repeatedly:

for(i=0;i<res;i++){        //Loop values
  output(generated[i]);   //Array to lookup from - Change the 'res' variable at the top too
  delay(1);
}

}//loop

//Write binary to output DAC pins
void output(byte value){
  digitalWrite(DAC0, (value & 0b00000001) >>0);
  digitalWrite(DAC1, (value & 0b00000010) >>1);
  digitalWrite(DAC2, (value & 0b00000100) >>2);
  digitalWrite(DAC3, (value & 0b00001000) >>3);
  digitalWrite(DAC4, (value & 0b00010000) >>4);
  digitalWrite(DAC5, (value & 0b00100000) >>5);
  digitalWrite(DAC6, (value & 0b01000000) >>6);
  digitalWrite(DAC7, (value & 0b10000000) >>7);
}

