int S0 = 2;
int S1 = 4;
int S2 = 5;
int S3 = 6;
int out1 = 7;
int out2 = 13;
int out3 = 13;
unsigned long int r1, r2, r3, r4, r5, r6;
bool checking = true;

/*
periyot(int pin,int tekrar)
bu fonksiyonla hangi renksensörünün çalışacağını ve gelen 
verilerin ortalamasını alıyoruz.

freqscale(int)
-0 kapalı 
-1 %2
-2 %20
-3 %100
bu fonksiyon sensör hassasiyetini ayarlıyor

filtertype(int)
0 kırmızı
1 mavi
2 yeşil
3 ışık

bu fonskiyon hangi arayin çalışacağını belirliyor
*/
void setup() {
  pinMode(S0, OUTPUT);//s0 s1 hassasiye
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);//s2 s3 hangi renk
  pinMode(S3, OUTPUT);
  pinMode(out1, INPUT);
  pinMode(out2, INPUT);
  pinMode(out3, INPUT);

  Serial.begin(9600);
  freqscale(2);



}

void loop() {

colour_check();


}

//----------------------------------------------------
void filtertype(int index)//0:red 1:blue 2:green 3:clear
{
  if (index == 0) { //red
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
  }

  else if (index == 1) { //blue
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
  }

  else if (index == 2) { //green
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
  }

  else if (index == 3) { //clear
    digitalWrite(S2, HIGH);
    digitalWrite(S3, LOW);
  }
}
//-------------------------------------------------------------
void freqscale(int index)
{
  if (index == 0) //close
  {
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
  }

  if (index == 1) //%2
  {
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
  }

  if (index == 2) //%20
  {
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
  }

  if (index == 3) //%100
  {
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
  }
}
//----------------------------------------
unsigned long int periyot(int pin, int devinim)
{ int i, counted;
  long int c, T, bironceki;
  i = 0;
  T = 0;
  counted = 0;
  while (i < devinim)
  {
    c = pulseIn(pin, HIGH);
    if (i == 0) {
      c = pulseIn(pin, HIGH);
      c = c + pulseIn(pin, HIGH);
      bironceki = c / 2;
    }
    else {
      if (abs(c - bironceki) < 10)
      { counted++;
        T += c;
        bironceki = c;
      }
    } i++;
  }
  T = 2 * T / counted++;
  return T;
}
//-------------------------------------------


int colour_check() {
  
  if (checking) {
    filtertype(0);
    delay(10);
    r1 = periyot(out1, 40);

    filtertype(1);
    delay(10);
    r2 = periyot(out1, 40);

    filtertype(2);
    delay(10);
    r3 = periyot(out1, 40);
    checking = false;
  }
  delay(500);
  for (int i = 0; i < 10; i++) {

    filtertype(0);
    delay(10);
    r4 = periyot(out1, 40);

    filtertype(1);
    delay(10);
    r5 = periyot(out1, 40);

    filtertype(2);
    delay(10);
    r6 = periyot(out1, 40);
    //----------------------------
    Serial.println(r1);
    Serial.println(r2);
    Serial.println(r3);
    Serial.print("\n");
    Serial.println(r4);
    Serial.println(r5);
    Serial.println(r6);
    if (r1 - 35 <= r4 && r4 <= r1 + 35) {
      if (r2 - 35 <= r5 && r5 <= r2 + 35) {
        if (r3 - 35 <= r6 && r6 <= r3 + 35) {
          Serial.print("Same");
          Serial.print("\n");
          return 1;
          break;
        }
        else {
          Serial.print("not same");
          Serial.print("\n");
          return 0;
        }
      }
      else {
        Serial.print("not same");
        Serial.print("\n");
        return 0;
      }
    }
    else {
      Serial.print("not same");
      Serial.print("\n");
      return 0;
    }
  }
  checking = true;
}
