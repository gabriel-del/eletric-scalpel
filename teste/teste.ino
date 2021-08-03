
const int led1 =  11;
const int led2 =  12;
const int led3 =  13;

const int botao1 = A5;
const int botao2 =  A1;
const int botao3 =  A2;

boolean estadobotao1;
boolean estadobotao2;
boolean estadobotao3;

int blend = 0;
int blendaux = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(botao1, INPUT);
pinMode(botao2, INPUT);
pinMode(botao3, INPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
    estadobotao1 = analogRead(botao1);   
    estadobotao2 = analogRead(botao2);  
    estadobotao3 = analogRead(botao3);  
    Serial.print("Botão 1: ");
    Serial.print(estadobotao1);
    Serial.print(", Botão 2: ");
    Serial.print(estadobotao2);
    Serial.print(", Botão 3: ");
    Serial.print(estadobotao3);
    Serial.print(", Blend: ");
    Serial.print(blend);
    Serial.print(", Blendaux: ");
    Serial.println(blendaux);
    delay(500);


  // verifica se o botao esta pressionado.
  // em caso positivo, buttonState e HIGH:


  if (estadobotao1 > 0) {    
    // liga o LED:    
    //Serial.println(analogRead(botao1));
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);  
    delay(200);
  } else if (estadobotao2 > 0)  {
    digitalWrite(led1, LOW);  
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);  
 //   amplitude=1;
    
//    pulsos=10;
    delay(200);
   } else if (estadobotao3 > 0 || blendaux==0) {
    
    
    switch (blend) {
     case 0:
     blendaux = 1;
     blend++; 
     delay(3000);
     case 1:
    digitalWrite(led1, LOW);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, HIGH);  
      break;
     case 2:
    digitalWrite(led1, LOW);  
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, HIGH);  
      break;
     case 3:
    digitalWrite(led1, HIGH);  
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, HIGH);  
    blend = 0;
    break;     
    }
    
   } else {
    blendaux = 0;
    digitalWrite(led1, LOW);  
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);  
   }
   
  
  delay(200);


  

}
