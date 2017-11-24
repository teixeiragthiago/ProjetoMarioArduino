//Controlando servo motor com potencimetro  

#include <Servo.h> 

Servo myservo;

int angulo;
int potPin = 0; //definindo o pino de entrada do potenciometro
int pinServo = 9;

//definindo porta dos Leds
int led = 4;
int ledVerde = 3;
int ledAmarelo = 10;

//definindo a porta do buzzer
const int buzzer = 12;

//definindo a musica do mario
int melodia[] = {660,660,660,510,660,770,
380,510,380,320,440,480,450,430,380,660,760,
860,700,760,660,520,580,480,510,380,320,440,
480,450,430,380,660,760,860,700,760,660,
520,580,480,500,760,720,680,620,650,380,
430,500,430,500,570,500,760,720,680,620,650,1020,
1020,1020,380,500,760,720,680,620,650,380,
430,500,430,500,570,585,550,500,380,500,500,500,500,
760,720,680,620,650,380,430,500,430,500,570,500,760,
720,680,620,650,1020,1020,1020,
380,500,760,720,680,620,650,380,430,500,430,500,570,585,
550,500,380,500,500,500,500,500,500,500,580,660,500,430,
380,500,500,500,500,580,660,870,760,500,500,
500,500,580,660,500,430,380,660,660,660,510,660,770,380};

//duracao das notas
int duracaodasnotas[] = {100,100,100,100,100,100,100,100,
100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,
100,100,100,100,80,100,100,100,80,50,100,80,
50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,
100,100,100,100,100,150,200,80,80,80,100,100,100,100,
100,150,150,100,100,100,100,100,100,100,100,100,
100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,
200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,
100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,
60,80,80,80,80,80,80,100,100,100,100,100,100,100};



void setup() 
{ 
  // Pino de dados do servo conectado ao pino 9 do Arduino
  myservo.attach(pinServo);
  
  //definindo a porta dos Leds como saida
  pinMode(led, OUTPUT);  
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  
  //definindo a porta do buzzer como saida
  pinMode(buzzer, OUTPUT);
  
} 

void loop() 
{ 
  angulo = analogRead(potPin); //lendo os valores do potenciometro 
  angulo = map(angulo, 0, 1023, 0, 180); //mapeando os valores do angulo do potenciometro
  
  myservo.write(angulo); //escrevendo o angulo atraves do potenciometro 
  delay(0);
  
  controlarLed();
  
}


void controlarLed()
{
  if(angulo == 0 && angulo <= 32)
  {
    digitalWrite(led, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
  }  
  if(angulo == 33 && angulo <= 34)
  {
    digitalWrite(led, HIGH);
    digitalWrite(ledAmarelo, LOW);
    tone(buzzer, 2000);
  }
  if(angulo >= 35 && angulo <= 59)
  {
     digitalWrite(ledAmarelo, HIGH); 
  }
  if(angulo == 60)
  {
    digitalWrite(led, HIGH);
    digitalWrite(ledAmarelo, LOW);
    tone(buzzer, 2000);
  }
  if(angulo == 99 && angulo <= 100)
  {
    tocarMario();
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
  }
  if(angulo > 100)
  {
    digitalWrite(ledAmarelo, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(ledVerde, LOW);
    noTone(buzzer);
  }
     
}

void tocarMario()
{
       //for para tocar as 156 notas começando no 0 ate 156 ++ incrementado
        for (int nota = 0; nota < 156; nota++) {

              int duracaodanota = duracaodasnotas[nota];
              tone(buzzer, melodia[nota],duracaodanota);
              
              
              //pausa depois das notas
              int pausadepoisdasnotas[] ={150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,
              300,150,350,300,150,150,500,450,400,500,
              300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,
              100,220,300,100,150,150,300,300,300,150,
              300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,
              150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,
              300,150,150,300,150,100,420,450,420,360,300,
              300,150,300,150,300,350,150,350,150,300,150,600,150,300,
            350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};
                digitalWrite(ledVerde, HIGH);
                digitalWrite(ledAmarelo, LOW);
              delay(pausadepoisdasnotas[nota]);
          }    
          noTone(buzzer); 
 
}



