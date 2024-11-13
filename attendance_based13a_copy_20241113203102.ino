//Santhosh Kumar
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial sim(3, 2);
String number = "+9196320110xx";
String number1 = "+9193430244xx";
String number2 = "+91";
String number3 = "+91";
String number4 = "+91";
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;
#define buzzerPin 4
#define yellow 5
#define green 6
 
String page = "";
char input[12];
int count = 0;
int a;
double total = 0;
int count_prod = 0;
 
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  sim.begin(9600);
 
  pinMode(buzzerPin, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
 
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("TO OUR PROJECT");
  delay(4000);
  lcd.clear();
}
 
void loop() {
  rfid();
}
 
void rfid() {
  if (Serial.available()) {
    count = 0;
    while (Serial.available() && count < 12) {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
    if (count == 12) {
      if ((strncmp(input, "03007BFA20A2", 12) == 0) && (state1 == 0)) {
        beepON();
        digitalWrite(green, HIGH);
        delay(2000);
        digitalWrite(green, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Prateek");
        lcd.setCursor(11, 1);
        lcd.print("001");
        info();
        SendPrateek();
        state1 = 1;
      } else if ((strncmp(input, "03007BFA20A2", 12) == 0) && (state1 == 1)) {
        beepON();
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Prateek");
        lcd.setCursor(11, 1);
        lcd.print("001");
        info();
        SendPrateek();
        state1 = 0;
      } else if ((strncmp(input, "03007C2DA0F2", 12) == 0) && (state1 == 0)) {
        beepON();
        digitalWrite(green, HIGH);
        delay(2000);
        digitalWrite(green, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Sonu");
        lcd.setCursor(11, 1);
        lcd.print("002");
        info();
        SendSonu();
        state2 = 1;
      } else if ((strncmp(input, "03007C2DA0F2", 12) == 0) && (state1 == 1)) {
        beepON();
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Sonu");
        lcd.setCursor(11, 1);
        lcd.print("002");
        info();
        SendSonu();
        state2 = 0;
      } else if ((strncmp(input, "03007C8531CB", 12) == 0) && (state1 == 0)) {
        beepON();
        digitalWrite(green, HIGH);
        delay(2000);
        digitalWrite(green, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Punit");
        lcd.setCursor(11, 1);
        lcd.print("003");
        info();
        SendPunit();
        state3 = 1;
      } else if ((strncmp(input, "03007C8531CB", 12) == 0) && (state1 == 1)) {
        beepON();
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Punit");
        lcd.setCursor(11, 1);
        lcd.print("003");
        info();
        SendPunit();
        state3 = 0;
      } else if ((strncmp(input, "03007CBE41B0", 12) == 0) && (state1 == 0)) {
        beepON();
        digitalWrite(green, HIGH);
        delay(2000);
        digitalWrite(green, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Ram");
        lcd.setCursor(11, 1);
        lcd.print("004");
        info();
        SendRam();
        state4 = 1;
      } else if ((strncmp(input, "03007CBE41B0", 12) == 0) && (state1 == 1)) {
        beepON();
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        lcd.clear();
        lcd.setCursor(7, 0);
        lcd.print("Ram");
        lcd.setCursor(11, 1);
        lcd.print("003");
        info();
        SendRam();
        state3 = 0;
      }
 
      else {
        digitalWrite(buzzerPin, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("ID : ");
        lcd.print("Unknown");
        lcd.setCursor(0, 1);
        lcd.print("Access denied");
        Serial.println(" Access denied");
        delay(1500);
        digitalWrite(buzzerPin, LOW);
        lcd.clear();
      }
    }
  }
}
 
void smsSend() {
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  for (int x = 11; x < 16; x++) {
    lcd.setCursor(x, 0);
    lcd.print(".");
    delay(1000);
    lcd.clear();
  }
}
void beepON() {
  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(buzzerPin, LOW);
  delay(100);
}
void info() {
  lcd.setCursor(0, 0);
  lcd.print("Name : ");
  lcd.setCursor(0, 1);
  lcd.print("Roll No : ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Authorized Access");
  delay(1000);
  lcd.clear();
}