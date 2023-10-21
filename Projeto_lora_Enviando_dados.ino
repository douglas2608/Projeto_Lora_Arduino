#include <SoftwareSerial.h>
#include "Ultrasonic.h"

SoftwareSerial lora (5, 4); 
//SoftwareSerial Blue (9,8);
Ultrasonic sensor1(7,6);// estaa nas portas 12 e 13

float distancia = 0;
char estado=0;
int presenca = 10;
int situacao;
int led1 = 2;
int led2=3;
unsigned long tempoagora = 0;
unsigned long tempofim = 0;
unsigned long tempoleitura1 = 0;
unsigned long tempoleitura2 = 0;
unsigned long tempoleitura3 = 0;
unsigned long tempoleitura4 = 0;
//String turon = "on";

void setup() {
Serial.begin(9600);
lora.begin(9600);
//Blue.begin(9600);
digitalWrite(presenca,INPUT);
digitalWrite(led1,OUTPUT);
digitalWrite(led2,OUTPUT);
//delay(10000);
tempoleitura1 = millis();
tempoleitura2 = millis();
tempoleitura3 = millis();
/*delay(15000);*/
}

void loop() {

/*distancia = sensor1.convert(sensor1.timing(), Ultrasonic::CM);
Serial.print(  distancia);
Serial.println(" CM ");


if(Blue.available()) {
estado = Blue.read();
Serial.print(estado);
Serial.print("\n");
}

if (distancia <=65){
lora.print("on");
delay(1000);
}else if (distancia > 65){
lora.print("off");
delay(1000);
}

}*/
/* Teste com sensor Ultrasonico e Modulo Bluethoot
*  ___________________________________________________________
*
*  codico para iniciar o bluethoot printando na tela as informações recebidas ou enviadas para serial armazenando a leitura na variavel estado do tipo char pois
*  estamos enviando caracteres de acordo com o aplicativo do celular.ultilizando Condicionais if e and para filtrar as deciões do dados enviado pelo bluethoot
*  e recebidos pelo sensor se ambos satisfazer as condições ele executa
*
*if(Blue.available()) {
estado = Blue.read();
Serial.print(estado);
Serial.print("\n");

if (distancia <= 65 and estado =='a'){
lora.print("on");
Serial.print("on");
delay(1000);
}

if (distancia <= 65 and estado =='b'){
lora.print("on");
Serial.print("on");
delay(1000);
}


if (distancia > 65 and estado =='b'){
lora.print("off");
Serial.print("off");
delay(1000);
}
if (distancia > 65 and estado =='a'){
lora.print("on");
Serial.print("on");
delay(1000);
}





}______________________________________________________________________________________*/

/*Projeto ulilizando o sensor Ultrasonico e o Sensor de movimento Pir ultilizando o MILLIS() com Delay de 6 minutos no sensor ultrasonico e sensor de movimento livre para detectar objeto
* sem travar o codigo */

/*situacao = digitalRead(presenca);

//tempoagora = millis();
//if ((tempoagora - tempoleitura1) > 1000){

//situacao = digitalRead(presenca);
if (situacao == LOW) {
lora.print("off");
Serial.print("off");
Serial.print("   não detectado sensor Pir ");
Serial.print("\n");
digitalWrite(led2, LOW);

}
if (situacao == HIGH) {
lora.print("on");
Serial.print("on");
Serial.print("   movimento detectado Sensor pir ");
Serial.print("\n");
digitalWrite(led2, HIGH);
}
tempoagora = millis();
//if ((tempoagora - tempoleitura2) > 1000){
distancia = sensor1.convert(sensor1.timing(), Ultrasonic::CM);
Serial.print(  distancia);
Serial.println(" CM ");
if (distancia <= 35){
tempoagora = millis();
if((tempoagora - tempoleitura3) < 250){
lora.print("on");
//Serial.print("on");
Serial.print("On Sensor de distancia detectado");
Serial.print("\n");
digitalWrite(led1, HIGH);
//tempoleitura3 = millis();
}
if((tempoagora - tempoleitura3) > 250){
lora.print("on");
//Serial.print("on");
Serial.print("On Sensor de distancia detectado");
Serial.print("\n");
digitalWrite(led1, 0);
//tempoleitura3 = millis();


}
if((tempoagora - tempoleitura3) > 500){
tempoleitura3 = millis();
}
}



tempoagora = millis();
if (distancia >= 35){
if((tempoagora - tempoleitura3) >= 500){
lora.print("off");
//Serial.print("off");
Serial.print("NAO DETECTADO SENSOR DE DISTANCIA");
Serial.print("\n");
digitalWrite(led1, 0);
tempoleitura3 = millis();
}
}



/*_________________________________________________________________________________________________________________________________________________________________________*/

/* projeto eficente do lora que envia dados com medindo com sensor ultrasonico com um clock mais rapido uma taxa de perda de 1% na leitura passando em velocidade*/
/*if (lora.available()>1){
String input = lora.readString();
//Serial.println(input);
//Serial.print(input);
if(input =="chegou"){
Serial.println(input);
}
}*/

tempoagora = millis();
//if ((tempoagora - tempoleitura2) > 1000){
distancia = sensor1.convert(sensor1.timing(), Ultrasonic::CM);
Serial.print(  distancia);
Serial.println(" CM ");
tempoagora = millis();
if (distancia <= 15.00){
tempoagora = millis();
if((tempoagora - tempoleitura3) >=1000){
lora.print("on");
//Serial.print("on");
Serial.print("On Sensor de distancia detectado");
Serial.print("\n");
digitalWrite(10, HIGH);
tempoleitura3 = millis();


}
}



tempoagora = millis();
if (distancia >= 16.00){
tempoagora = millis();
if((tempoagora - tempoleitura3) >= 4000){
lora.print("off");
//Serial.print("off");
Serial.print("NAO DETECTADO SENSOR DE DISTANCIA");
Serial.print("\n");
digitalWrite(10, 0);
tempoleitura3 = millis();
}
/*tempoagora = millis();
if (distancia >=110 and distancia <=114){
tempoagora = millis();
if((tempoagora - tempoleitura2) >=1000){
lora.print("pisca");
Serial.println("distancia maior que 30 e menor que 45");
tempoleitura2 = millis();
}
}*/
/*______________________novo bloco adicionado _________________________________________
if (lora.available() >1){
String input = lora.readString();
tempoagora = millis();
if (input =="1"){
if((tempoagora - tempoleitura2) >= 2000){
digitalWrite(10,HIGH);
Serial.println(input);
tempoleitura2 = millis();

}



}
tempoagora = millis();
if (input =="0"){
if((tempoagora - tempoleitura2) >= 4000){
digitalWrite(10,LOW);
Serial.println(input);
tempoleitura2 = millis();

}

}

}
_________________________Fim DO novo Bloco Adicionado______________________*/
}
}

/*________________________________________________________________________________________________________________________________________________________________________________*/

/*Codigo com detecção em alta velocidade sem parar na frente do sensor porem se parado na frente do sensor ele nao detecta por conta da velocidade do clock
* mais em alta velocidade passando pelo sensor ele detecta
//if ((tempoagora - tempoleitura2) > 1000){
distancia = sensor1.convert(sensor1.timing(), Ultrasonic::CM);
Serial.print(  distancia);
Serial.println(" CM ");
if (distancia <= 75){
tempoagora = millis();
if((tempoagora - tempoleitura3) >100){
lora.print("on");
Serial.print("on");
Serial.print("On Sensor de distancia detectado");
Serial.print("\n");
digitalWrite(led1, HIGH);
tempoleitura3 = millis();

}
}

tempoagora = millis();
if (distancia > 75){
if((tempoagora - tempoleitura3) > 6000){
lora.print("off");
Serial.print("off");
Serial.print("NAO DETECTADO SENSOR DE DISTANCIA");
Serial.print("\n");
digitalWrite(led1, LOW);
tempoleitura3 = millis();
}
}
*/










/*if((millis() - tempoleitura3) > 6000){
tempoleitura3 = millis();
}*/


//tempoleitura2 = millis();


//}



/*if (distancia <= 25){
if((millis() - tempoleitura3) >1000){
lora.print("on");
Serial.print("on");
Serial.print("On Sensor de distancia detectado");
Serial.print("\n");
digitalWrite(led1, HIGH);
tempoleitura3 = millis();


}

}




if (distancia >= 25){
if((millis() - tempoleitura3) >1000){
lora.print("off");
Serial.print("off");
Serial.print("NAO DETECTADO SENSOR DE DISTANCIA");
Serial.print("\n");
digitalWrite(led1, LOW);
tempoleitura3 = millis();


}

}
tempoleitura2 = millis();



}*/

/*if((millis() - tempoleitura3) < 3000){
digitalWrite(led1, LOW);
lora.print("off");
Serial.print("Sensor de distancia Não detectado");


}
if((millis() - tempoleitura3) > 6000){
tempoleitura3 = millis();
}*/













//if (lora.available())
//Serial.write(lora.read());
//Serial.print(lora);
