
#include <Wire.h>
char c;
byte x = 0;
void setup() {
  Wire.begin();        // programı başlatmak için
  Serial.begin(9600);
}

void loop() {
  //veri istenildiğinde alt taraftaki donksiyon kullanılacak
  Wire.requestFrom(8, 17);    // 8 numaralı arduinodan 17 b---ak al
  Serial.print(c);         // karakterleri yaz
  while (Wire.available() > 1) { //----son bayt hariç tüm baytları al
    char c = Wire.read(); // baytları karakter olarak al
    Serial.print(c);         // karakterleri yaz
  }
  int c = Wire.read();  //son baytı sayı olarak yaz
  Serial.print(c);
  Serial.print("\n");
  //-----------------------------------------------------------------
  //veri gönderilmek istendiği zaman kullanılacak fonksiyon
  Wire.beginTransmission(8); // 8 numaralı arduinoyla bağlantı kur
  Wire.write("x is ");        // 5 baytlık veri gönder boşluklarda sayılıyor
  Wire.write(x);              // x'in verisini gönder 1 bayt da bu
  //Wire.write(analogRead(A1));
  Wire.endTransmission();    // bağlantıyı kapat

  x++;
  delay(500);
}
