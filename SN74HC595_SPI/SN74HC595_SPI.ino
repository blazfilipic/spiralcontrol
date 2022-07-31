//#define latchPin 5
#define latchPin 23
//#define dataPin 16
#define dataPin 22
//#define clockPin 4
#define clockPin 1
#define outputoff 2
#define input 4

//outputoff --> HIGH - output is disabled
//outputoff --> LOW - ouput is enabled

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(outputoff, OUTPUT);
  pinMode(input, INPUT_PULLUP);
}
uint32_t combine(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    return (a << 24 ) | (b << 16) | (c << 8) | d;
}

void loop() {
  uint32_t buf = combine(1, 0,1, 1);
  //delay(10000);
  digitalWrite(outputoff, HIGH);
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 24);
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 16);
  shiftOut(dataPin, clockPin, MSBFIRST, buf >> 8);
  shiftOut(dataPin, clockPin, MSBFIRST, buf);
  digitalWrite(latchPin, HIGH); 
  digitalWrite(outputoff, LOW); //enable output
  
  //delay(10000);
  //digitalWrite(outputoff, HIGH);
  //go(valB);
  //go(valC);
}
