#include <Stepper.h> 
#define STEPS 32//STEP SAYISI


Stepper stepper(STEPS, 2, 4, 3, 5);//IN1 IN3 IN2 IN4

int val = 0; //floatta kalmasın diye 0 yapıyoz

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(500);//step sayma hızı max 1500 oluyor motor hareket etmiyor
  //ondan sonra biz maksimum 400-600 kullanırız
  //hızı arttıkça torku azalıyor çünkü
  }

void loop() {

  if (Serial.available() > 0)
  {
    val = Serial.parseInt();//seriden step göndermek için
    stepper.step(val);//çalışma fonksiyonu
   
    Serial.println(val); 
  }


}
