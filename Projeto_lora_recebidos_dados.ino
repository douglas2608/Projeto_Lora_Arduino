#include <SoftwareSerial.h>;
SoftwareSerial lora(5,4);

int recebido;
int presenca = 10;
int situacao;
/* Novo bloco inserido*/
unsigned long tempoagora = 0;
unsigned long tempofim = 0;
unsigned long tempoleitura1 = 0;
unsigned long tempoleitura2 = 0;
unsigned long tempoleitura3 = 0;
unsigned long tempoleitura4 = 0;
/* fim novo bloco*/
void setup() {
  pinMode(presenca, INPUT);
  pinMode(7,OUTPUT);// estava no pino 5 foi trocado para o 7 
  pinMode(8,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  lora.begin(9600);
  digitalWrite(7,HIGH);
  
}

void loop() {
  
  /*tempoagora = millis();
  if ((tempoagora - tempoleitura3) > 1000){
    lora.print("chegou");
    tempoleitura3 = millis();
  }*/
/*_____________________________codigo eficiente______________________________*/
  /*if (lora.available() >1){
    String input = lora.readString();
    //Serial.println(input);
    //Serial.print(input);

    if (input =="on"){
      digitalWrite(7,LOW);
      Serial.println(input);
      delay(19000);
    }
    if (input =="off"){
      Serial.println(input);
      digitalWrite(7,HIGH);
      
    }
  }*/
 /* ____________________________________final_____________*/

  /*if (lora.available() >1){
      String input = lora.readString();
      //Serial.println(input);
      //Serial.print(input);

      if (input =="on"){
      digitalWrite(7,LOW);
      Serial.println(input);
      tempoagora = millis();
      }
      if (input =="off"){
        if((millis() - tempoagora)>=19000){
          Serial.println(input);
          digitalWrite(7,HIGH);
          /*tempoagora = millis();*/
        
        
      /*}
  }
  }*/

  /*____________________________________________________*/

  if (lora.available()){
      String input = lora.readStringUntil('\n');
      //Serial.println(input);
      //Serial.print(input);
      

      if (input =="on"){
      digitalWrite(7,LOW);
      Serial.println(input);
      tempoagora = millis();
      }
      if (input =="off"){
        if((millis() - tempoagora)>=19000){
          Serial.println(input);
          digitalWrite(7,HIGH);
          /*tempoagora = millis();*/
        
        
      }
  }
  }
  
      
      
  
 
  
    /*tempoagora = millis();
    if(input =="off"){
      if((tempoagora - tempoleitura3) >=1000){
      lora.print("desligada");
      //Serial.print("on");
      Serial.print("On detectado");
      Serial.print("\n");
      tempoleitura3 = millis();
           
  
  }
    }
    tempoagora = millis();
    if(input =="on"){
      if((tempoagora - tempoleitura3) >=1000){
        lora.print("Ligada");
        //Serial.print("on");
        tempoleitura3 = millis();
      
    }

    
  
}
  }*/
}
