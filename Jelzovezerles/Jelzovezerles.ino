//Out
int out1 = 0;  //tolatasjelzo Kek feny
int out2 = 1;  //tolatasjelzo Feher feny
int out3 = 2;  //nembiztositott Zold feny
int out4 = 3;  //nembiztositott Sarga feny
int out5 = 4;
int out6 = 5;
int out7 = 6;
int out8 = 7;
int out9 = 8;
int out10 = 9;
int out11 = 10;
int out12 = 11;
int out13 = 12;
int out14 = 13;

//In
int in1 = A0; //Tolatasjelzo
int in2 = A1; //Nembiztositott
int in3 = A2;
int in4 = A3;
int in5 = A4;

//Counters
unsigned long millis1;
unsigned long millis2;
unsigned long millis3;
unsigned long millis4;
unsigned long millis5;


//Value
int value1;
byte value1last = 1;
int value2;
byte value2last = 1;
void setup() {
  //digitalWrite(out1, HIGH);
  
  Serial.begin(9600);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
  pinMode(out6, OUTPUT);
  pinMode(out7, OUTPUT);
  pinMode(out8, OUTPUT);
  pinMode(out9, OUTPUT);
  pinMode(out10, OUTPUT);
  pinMode(out11, OUTPUT);
  pinMode(out12, OUTPUT);
  pinMode(out13, OUTPUT);
  pinMode(out14, OUTPUT);

}

void loop() {
 // tolatasjelzo();
 nembiztositott();
}

void tolatasjelzo() {
  value1 = analogRead(in1);

  if ((value1==0) && (value1last==0)){ 
    digitalWrite(out1, HIGH); //Kek fel
    digitalWrite(out2, LOW); //Feher le
    value1last= 1;
    delay(30);
  }

  if ((value1>=511 && value1<520) && (value1last==1)){
     digitalWrite(out1, LOW); //Kek le
     digitalWrite(out2, HIGH); //Feher fel
    value1last= 0;
     delay(30);
  }
//Serial.println(value1);
}

void nembiztositott() {
  value2 = analogRead(in2);

  if ((value2==0) && (value2last==0)){ 
    digitalWrite(out3, HIGH); //Zold fel
    digitalWrite(out4, LOW); //Sarga le
    value2last= 1;
    delay(30);
  }

  if ((value2>=511 && value2<520) && (value2last==1)){
     digitalWrite(out3, LOW); //Zold le
     digitalWrite(out4, HIGH); //Sarga fel
    value2last= 0;
     delay(30);
  }
//Serial.println(value2);
}
