int leds = 10; //# de leds en la conexion
int i;
int patron = 3; //El patron sera con 3 leds encendidos
int posiciones[3]; //Tiene que ser una matriz del tamaño del patron
int pos_respaldo[3]; //Una copia de "posiciones"
bool sentido = true; /*
Intercala el codigo para barrerlo de izquierda a derecha
true = a la izquierda
false = a la derecha*/

void setup()
{
Serial.begin(9600);
 /*Se declara del pin 2 al pin 11 como salida
  
Los leds deben estar conectados y acomodados en orden
Es decir, pin 2 con el primer led, pin 3 con el segundo led
y asi sucesivamente
  
NOTA:
No se usan los pines 1 y 2 porque luego no funciona bien el
led por el tipo de señal que manejan esos puertos*/
for(i=0;i<leds;i++){
    pinMode((i+2), OUTPUT);
}
  
/*Se inicializan las posiciones para el barrido
[-3 -2 -1]
Estas posiciones "invisibles" son para irlas 
actualizando en cada iteracion e indicar el pin de salida
que debe mandar encender el led
*/
for(i=0;i<patron;i++){
    posiciones[i]=-(i+1);
    pos_respaldo[i] = posiciones[i];
  }
}

void loop(){
if(sentido == true){
    izquierda();
}
  
if(sentido == false){
    derecha(); 
}   
  
//ENCENDER LOS LEDS PERTINENTES
for(i=0;i<patron;i++){
    digitalWrite(pos_respaldo[i],HIGH);
}
  
//TIEMPO DE ESPERA AL SIG. MOVIMIENTO
delay(600);
  
  
for(i=0;i<patron;i++){
    digitalWrite(pos_respaldo[i],LOW);
    }
}

void izquierda(){
for(i=0;i<patron;i++){
    posiciones[i] = posiciones[i] + 1;
    pos_respaldo[i] = posiciones[i];
}

if(posiciones[2]>(leds+2)){
    sentido = false;
    }
}

void derecha(){
    for(i=0;i<patron;i++){
    posiciones[i] = posiciones[i] - 1;
    pos_respaldo[i] = posiciones[i];
}

    if(posiciones[0]<(patron-1)){
        sentido = true;
    }
}