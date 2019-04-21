#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; // Количество строк
const byte COLS = 4; // Количество столбцов

// Объявление раскладки клавиатуры
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// yte rowPins[ROWS] = {9, 8, 7, 6}; // Назначение пинов Arduino Uno для строк
// byte colPins[COLS] = {5, 4, 3, 2}; // назначение пинов Arduino Uno для столбцов

byte rowPins[ROWS] = {29, 27, 25, 23}; // назначение пинов Arduino Mega2560 для строк
byte colPins[COLS] = {37, 35, 33, 31}; // Назначение пинов Arduino Mega2560 для столбцов

// Объявление переменной для матричной клавиатуры(Раскладка, Пины для строк, Пины для столбцов, Количество строк, Количество столбцов)
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);  

// Объявление переменной для экрана(Адрес экрана, Количество символов в строке, Количество строк)
// Для определения адреса экрана необходимо воспользоваться программой I2C-scanner:
// https://github.com/AndrePim/I2C_Scanner
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup(){
  lcd.backlight(); // Включение подсветки экрана
  lcd.init(); // Инициализация экрана
}

void loop(){
  char customKey = customKeypad.getKey(); // Переменная для записи нажатой клавиши
  // При нажатии клавиши
  if (customKey){ 
    lcd.clear(); // Очистка экрана
    lcd.setCursor(0, 0); // Установка курсора на 1 строку на 1 символ
    lcd.print(customKey); // Вывод на экран нажатой клавиши
  }
}
