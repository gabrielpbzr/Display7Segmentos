/*
 * Controle de dois displays de sete segmentos catodo comum
 * usando o CI 4511 multiplexado
 * Author: Gabriel P. Bezerra <gabrielpbzr@gmail.com>
 * Date: 2017-12-27
 */
const byte DISPLAY_DELAY = 10;
const int INTERVAL = 1000;
byte count = 0;
byte rem = 0;
unsigned long lastRead = 0;
unsigned long delta = 0;

void writeValue(byte value) {
  // Escreve o valor no primeiro display
  PORTB = value / 10; 
  PORTC = 1;
  delay(DISPLAY_DELAY);
  // Habilita e escreve no segundo display
  PORTB = value % 10;
  PORTC = 2;
  delay(DISPLAY_DELAY);
}

void setup() {
  DDRB = 0b00001111;
  DDRC = 0b00000011;
}


void loop() {
  unsigned long now = millis();
  delta = now - lastRead;    
  if (delta >= INTERVAL) {
    lastRead = now;
    count++;
    count = count % 60;
  }
  writeValue(count);
}







