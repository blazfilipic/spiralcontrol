#define latchPin 5
#define dataPin 16
#define clockPin 4
#define outputoff 2

//             BGR
/*#define data1 0b1011001110011111
#define data2 0b10011111
#define valC 0b001*/


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(outputoff, OUTPUT);
}

/*uint16_t combine(uint8_t a, uint8_t b)
{
    return (a << 8) | b;
}*/

uint32_t combine(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    return (a << 24 ) | (b << 16) | (c << 8) | d;
}


/*void go(byte b, byte c) {
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data2);
  shiftOut(dataPin, clockPin, MSBFIRST, data1;
  digitalWrite(latchPin, HIGH);

  delay(1000);
}*/
/*int combine(int a, int b, int c)
{
    return (data1 << 16 ) | (data2 << 8) | c;
}*/


void loop() {
  uint32_t buf = combine(2, 0, 2, 0);
  //delay(10000);
  digitalWrite(outputoff, HIGH);
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  //combine(data1, data2);
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 24);
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 16);
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 8);
  shiftOut(dataPin, clockPin, MSBFIRST, buf);
  digitalWrite(latchPin, HIGH);
  digitalWrite(outputoff, LOW);

  //delay(10000);
  //digitalWrite(outputoff, HIGH);
  //go(valB);
  //go(valC);
}
