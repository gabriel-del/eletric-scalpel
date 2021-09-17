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


int sine[255];

const int led1 =  A0;
const int led2 =  A1;
const int led3 =  A2;

const int botao1 = 11;
const int botao2 =  12;
const int botao2 =  13;


void setup() 
{ Serial.begin(9600);
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT);
pinMode(7, OUTPUT); 
pinMode(8, OUTPUT); 
pinMode(9, OUTPUT); 

pinMode(led1, OUTPUT);
pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

float x; 
float y; 
for(int i=0;i<255;i++)
{
x=(float)i;
y=sin((x/255)*2*PI);
sine[i]=int(y*128)+128;

}
}



void loop() {
  // put your main code here, to run repeatedly:

for( int i=0;i<255;i++){        //Loop values
  output(sine[i]);   //Array to lookup from - Change the 'res' variable at the top too
  Serial.println(sine[i]);
  Serial.print(" ");
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
