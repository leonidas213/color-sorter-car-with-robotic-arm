#include <Wire.h>

int x=0;
void setup() {
  Wire.begin(8);                // 8 numaralı adresle gruba katıl
  Wire.onRequest(requestEvent); // master veri istediğinde kullanılacak fonksiyon
  Wire.onReceive(receiveEvent); // master veri gönderdiğinde kullanılacak fonksiyon
  Serial.begin(9600);           
}

void loop() {
  delay(100);
}

//------------------------------------------
//master veri istendiğinde bu fonksiyon kullanılacak
void requestEvent() {
  Wire.write("hello btw x is: "); // mastera 16 baytlık veri gönder
  // bunun iyi tarafı diğerleri bu veriyi görmüyor mastera gittiğini 
  //düşündükleri için masterda bekliyor bunu zaten
  Wire.write(x);//buda son bayt
}


//-------------------------------------------------------
  // bu fonksiyon master veri gönderdiğinde çalışıcak
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // son bayt dışında tüm baytları koy
    //Wire.Avaliable() da kaç tane bayt olduğu gösteriliyor ona göre 
    //çalışıyor mesaj yoksa 0 da
    char c = Wire.read(); // baytları karakter olarak yaz
    Serial.print(c);         
  }
   x = Wire.read();    // son baytı da isayı olarak al
  Serial.println(x);         
}
