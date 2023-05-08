/* Code for cat automatic croquette dispenser
Motor relay connected to the pin 10
*/

/* For Arduino MINI Pro 328 5V
TX -> TX1
RX -> RX
VCC -> 5V
GND -> GND
Rst -> RESET
*/

int pinRelay=10;// Pin to command the relay
int oneFullDoseTime=120;// Time in second for a one day full dose meal
int nbMeals=7;// Number of meals wanted per day
unsigned long timeStart;
unsigned long currentTime;
const long delayFeed=oneFullDoseTime/nbMeals*1000;

void setup(){
  pinMode(pinRelay,OUTPUT);
  pinMode(13,OUTPUT); //Led serving
  pinMode(11,OUTPUT); //Led stop
  timeStart=millis();
}

void loop(){
  currentTime=millis();
  if(currentTime-timeStart<delayFeed){ // While feeding time not passed continue
    digitalWrite(pinRelay,HIGH);
    digitalWrite(13,HIGH);
  }else{ // When feeding is passed stop everything
    digitalWrite(pinRelay,LOW);
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(10000); // Wait 10 seconds
  }
  delay(500); // Temporise the loop, for more precision decrease the time
}
