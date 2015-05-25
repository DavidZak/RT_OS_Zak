const int pin1 =  2;
const int pin2 =  4;
const int pin3 =  7;
const int pin4 =  8;
const int pin5 =  13;

int state1 = LOW;
int state2 = LOW;
int state3 = LOW;
int state4 = LOW;
int state5 = LOW;

unsigned long previousMicros1 = 0;
unsigned long previousMicros2 = 0;
unsigned long previousMicros3 = 0;
unsigned long previousMicros4 = 0;
unsigned long previousMicros5 = 0;

const unsigned long interval1 = 500;
const unsigned long interval2 = 1000;
const unsigned long interval3 = 1500;
const unsigned long interval4 = 200000;
const unsigned long interval5 = 2000000;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void generateImpulse(int pin, int state, unsigned long currentMicros, unsigned long previousMicros, unsigned long interval) {
  if(currentMicros - previousMicros >= interval) {
    previousMicros = currentMicros;

    if (state == LOW)
     state = HIGH;
    else
      state = LOW;
    currentdigitalWrite(pin, state);
  }
}

void currentdigitalWrite(uint8_t pin, uint8_t val)
{
   uint8_t bit = digitalPinToBitMask(pin);
   if (val == LOW) {
     PORTB &= ~bit;
   } 
   else {
     PORTB |= bit;
   }
}

void loop() {
   unsigned long currentMicros = micros();

   generateImpulse(pin1, state1, currentMicros, previousMicros1, interval1);
   generateImpulse(pin2, state2, currentMicros, previousMicros2, interval2);
   generateImpulse(pin3, state3, currentMicros, previousMicros3, interval3);
   generateImpulse(pin4, state4, currentMicros, previousMicros4, interval4);
   generateImpulse(pin5, state5, currentMicros, previousMicros5, interval5);
}
