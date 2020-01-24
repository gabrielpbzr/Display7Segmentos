/*
 * Controle de dois displays de sete segmentos catodo comum
 * usando o CI 4511 multiplexado.
 * Author: Gabriel P. Bezerra <gabrielpbzr@gmail.com>
 * Date: 2017-12-27
 */
const byte DISPLAY_DELAY_MS = 10;
const int INTERVAL_MS = 1000;
byte count = 0;
byte rem = 0;
unsigned long lastRead = 0;
unsigned long delta = 0;

void writeValue(byte value) {
  // Escreve o valor das dezenas no primeiro display
  PORTB = value / 10; 
  // Habilita o display 1
  PORTC = 1;
  // Aguarda o tempo para mostrar o digito
  delay(DISPLAY_DELAY_MS);
  
  // Escreve o valor das unidades no segundo display
  PORTB = value % 10;
  // Habilita o display 2
  PORTC = 2;
  // Aguarda o tempo para mostrar o digito
  delay(DISPLAY_DELAY_MS);
}

void setup() {
  // Configura o registrador PORTB
  DDRB = 0b00001111;
  // Configura o registrador PORTC
  DDRC = 0b00000011;
}


void loop() {
  unsigned long now = millis();
  // Calcula a diferenca no tempo da ultima leitura
  delta = now - lastRead;
  /*
   * Se a diferenca for igual ou maior o intervalo especificado, 
   * atualize o contador
   */
  if (delta >= INTERVAL_MS) {
    lastRead = now;
    count++;
    count = count % 60;
  }
  writeValue(count);
}







