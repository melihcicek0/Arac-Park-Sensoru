#define ekoPin 6
#define TetikPin 7
#define BuzzerPin 8

int maksimumAralik=30;
int minimumAralik=0;

void setup() {
  pinMode(ekoPin,INPUT);
  pinMode(TetikPin,OUTPUT);
  pinMode(BuzzerPin,OUTPUT);
}

void loop() {
  int olcum = uzaklik(minimumAralik,maksimumAralik);
  melodi(olcum *5);
}
int uzaklik (int minAralik,int maksAralik) {
  long zaman;
  long mesafe;

  digitalWrite(TetikPin,LOW);
  delayMicroseconds(5);
  digitalWrite(TetikPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TetikPin,LOW);

  zaman = pulseIn(ekoPin,HIGH);
  mesafe=zaman/58.2;
  delay(50);

  if(mesafe<=minAralik || maksAralik>=mesafe){
    return 0;
    return mesafe;
  }
}

int melodi(int gecikme){
  tone(BuzzerPin,400);
  delay(gecikme);
  noTone(BuzzerPin);
  delay(gecikme);
}
