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

const int led1 =  11; const int led2 =  12; const int led3 =  13;
const int botao1 = A0; const int botao2 =  A1; const int botao3 =  A2;
boolean estadobotao1; boolean estadobotao2; boolean estadobotao3;
int estado = 0; int sine[255];
float amplitude; int baixa; int saida = 1;

void setup() { Serial.begin(9600);
pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT); 
pinMode(led1, OUTPUT); pinMode(led2, OUTPUT); pinMode(led3, OUTPUT); pinMode(botao1, INPUT); pinMode(botao2, INPUT); pinMode(botao3, INPUT);

float x; float y; 
for(int i=0;i<255;i++) {
x=(float)i;
y=sin((x/255)*2*PI);
sine[i]=int(y*128)+128; }
}



void loop() {
    estadobotao1 = analogRead(botao1); estadobotao2 = analogRead(botao2);  estadobotao3 = analogRead(botao3);  
    if ( estadobotao1 == 1 && estadobotao2 == 0 && estadobotao3 == 0) { estado = 1; }
    if ( estadobotao1 == 0 && estadobotao2 == 1 && estadobotao3 == 0) { estado = 2; }
    if ( estadobotao1 == 0 && estadobotao2 == 0 && estadobotao3 == 1) { estado = 3; }
    if ( estadobotao1 == 0 && estadobotao2 == 1 && estadobotao3 == 1) { estado = 4; }
    if ( estadobotao1 == 1 && estadobotao2 == 1 && estadobotao3 == 1) { estado = 5; }
    //estado = 1;
    if (saida == 1 ) {
    Serial.print("Botão 1: ");  Serial.print(estadobotao1);
    Serial.print(", Botão 2: ");Serial.print(estadobotao2);
    Serial.print(", Botão 3: ");Serial.print(estadobotao3);
    Serial.print(", Estado: "); Serial.println(estado); }
    switch (estado) {
      case 1: 
      digitalWrite(led1, HIGH); digitalWrite(led2, LOW); digitalWrite(led3, LOW);  
      if (saida == 1 ) { Serial.println(", Nome: Puro corte");}
      amplitude = 0.5 ; baixa = 0; break;
      case 2: 
      digitalWrite(led1, LOW); digitalWrite(led2, HIGH); digitalWrite(led3, LOW);  
      if (saida == 1 ) { Serial.println(", Nome: Blend 1");}
      amplitude = 0.7 ; baixa = 10; break;
      case 3: 
      digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, HIGH);  
      if (saida == 1 ) { Serial.println(", Nome: Blend 2");}
      amplitude = 0.9 ; baixa = 12; break;
      case 4: 
      digitalWrite(led1, LOW); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH);  
      if (saida == 1 ) { Serial.println(", Nome: Blend 3");}
      amplitude = 1.0 ; baixa = 15; break;
      case 5: 
      digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH);  
      if (saida == 1 ) { Serial.println(", Nome: Coagulação");}
      amplitude = 1.1 ; baixa = 19; break;

    }

   
  
int alta = 20 - baixa;  
//baixa = 138*baixa;
for(int n=0;n<alta;n++){ for( int i=0;i<255;i++){  output(sine[i]*amplitude);  
  if (saida == 0 ) { Serial.println(sine[i]*amplitude); Serial.print(" "); }
}}
for(int n=0;n<baixa;n++){ for( int i=0;i<255;i++){  output(128*amplitude);  
  if (saida == 0 ) { Serial.println(127*amplitude); Serial.print(" "); }
}}
//delay(baixa);
}


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
