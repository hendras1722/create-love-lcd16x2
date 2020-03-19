#include <Wire.h>
//#include <LCD.h>
//#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);


#define I2C_ADDR    0x27   //Masukkan sesuai alamat LCD 16x2.
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

//LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

//---------------------------- Tampung setiap slot ke dalam variable ----------------------
byte slot1[8]   = {B00000, B00000, B00000, B00000, B00111, B01111, B11111, B11111};
byte slot2[8]   = {B00000, B00000, B00000, B00000, B00000, B10001, B11011, B11111};
byte slot3[8]   = {B00011, B00111, B01111, B11111, B11111, B11111, B11111, B11111};
byte slot4[8]   = {B11000, B11100, B11110, B11111, B11111, B11111, B11111, B11110};
byte slot5[8]   = {B11111, B01111, B00111, B00011, B00001, B00000, B00000, B00000};
byte slot6[8]   = {B11111, B11111, B11111, B11111, B11111, B01111, B00001, B00000};
byte slot7[8]   = {B11111, B11111, B11111, B11110, B11100, B11100, B11100, B00010};
byte slot8[8]   = {B11110, B11100, B10000, B00000, B00000, B00000, B00000, B00000};

void setup() {
  //Konfigurasi LCD 16x2
  lcd.begin(16, 2);
//  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
//  lcd.setBacklight (HIGH);

//------------------------------------- Bentuk char untuk tiap slot -----------------------------
  lcd.createChar(1, slot1);
  lcd.createChar(2, slot2);
  lcd.createChar(3, slot3);
  lcd.createChar(4, slot4);
  lcd.createChar(5, slot5);
  lcd.createChar(6, slot6);
  lcd.createChar(7, slot7);
  lcd.createChar(8, slot8);
}

//-------------------------------------------- Bentuk Love -----------------------------------------
  void love(int x) {                     //Nilai x berfungsi untuk menentukan posisi love
    lcd.setCursor(x,0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(3);
    lcd.write(4);
    lcd.setCursor(x,1);
    lcd.write(5);
    lcd.write(6);
    lcd.write(7);
    lcd.write(8);
}

void loop() {
   love (0);                              //Tampilkan love pada kolom pertama
}
