void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
}
void loop() {
int sensorDegeri1 = analogRead(A0);// Arduino’nun A0 ayağına bağlanan kablodaki gerilim ölçülüyor
int sensorDegeri2 = analogRead(A1);
int sensorDegeri3 = analogRead(A2);
int sensorDegeri4 = analogRead(A3);
Serial.print("S1: ");
Serial.println(sensorDegeri1);

Serial.print("S2: ");
Serial.println(sensorDegeri2);

Serial.print("S3: "); 
Serial.println(sensorDegeri3);

Serial.print("S4: ");
Serial.println(sensorDegeri4);

Serial.print("\n");
delay(400);// Düzgün çalışabilmesi için kısa bir bekleme 
}
