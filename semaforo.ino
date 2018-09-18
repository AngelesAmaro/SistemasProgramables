#define ledVerde1 13
#define ledAmbar1 12
#define ledRojo1 11
#define ledVerde2 8
#define ledAmbar2 9
#define ledRojo2 10
#define push 7



//Variables
int tiempo = 2500;
int espera = 500;
boolean encendidoSemaforo1 = true;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde1,OUTPUT);
  pinMode(ledAmbar1,OUTPUT);
  pinMode(ledRojo1,OUTPUT);
  pinMode(ledVerde2,OUTPUT);
  pinMode(ledAmbar2,OUTPUT);
  pinMode(ledRojo2,OUTPUT);
  pinMode(push,INPUT);
  
  //Encender led verde en semaforo1, y led rojo en el del peaton
  //digitalWrite(ledVerde1,HIGH);
  //digitalWrite(ledRojo2,HIGH);

}

void loop() {
   int valor = analogRead(A0);
    tiempo = map(valor,0, 1023, 10, 60)*200;
    
  //Guardar el estado del boton
  int estado = digitalRead(push);
  if(estado == HIGH){
    digitalWrite(ledRojo1,HIGH);
    digitalWrite(ledRojo2,LOW);
    digitalWrite(ledVerde2,HIGH);
    delay(2000);
    digitalWrite(ledVerde2,LOW);
    digitalWrite(ledAmbar2,HIGH);
    delay(2000);
    digitalWrite(ledAmbar2,LOW);
    digitalWrite(ledRojo2,HIGH);
    digitalWrite(ledRojo1,LOW);
   // digitalWrite(ledVerde1,HIGH);


  }else{

   //encender el semaforo 1
    digitalWrite(ledRojo2,HIGH);
    digitalWrite(ledVerde1,HIGH);
    delay(tiempo);
    digitalWrite(ledVerde1,LOW);
    digitalWrite(ledAmbar1,HIGH);
    delay(1000);
    digitalWrite(ledAmbar1,LOW);
    digitalWrite(ledRojo1,HIGH);
    delay(500);
    digitalWrite(ledRojo1,LOW);

    //encender semaforo 2 aunque no se oprima el boton
//    int estado2 = digitalRead(push);
//    if(estado2 == LOW){
//      //encender el semaforo 2
//    digitalWrite(ledRojo1,HIGH);
//    digitalWrite(ledRojo2,LOW);
//    digitalWrite(ledVerde2,HIGH);
//    delay(2000);
//    digitalWrite(ledVerde2,LOW);
//    digitalWrite(ledAmbar2,HIGH);
//    delay(1000);
//    digitalWrite(ledAmbar2,LOW);
//    digitalWrite(ledRojo2,HIGH);
//    digitalWrite(ledRojo1,LOW);
//    digitalWrite(ledVerde1,HIGH);
//    }
  }
  }

  
     
  //}
