#include "LcdI2C.h"
#include "../Component.h"

LcdI2C::LcdI2C(unsigned short I2CAddress = 0x27, int columns = 16, int rows = 2, unsigned short sdaPin = A4, unsigned short sclPin = A5) : Component() {
        this->lcd = LiquidCrystal_I2C(I2CAddress, columns, rows);
        this->lcd.init();
        this->lcd.backlight();

        Pin pins[2] = { Pin(sdaPin, OUTPUT_PIN), Pin(sclPin, OUTPUT_PIN) };
        LcdI2C(pins, 2);
}

LcdI2C::LcdI2C(Pin pins[], int numPins) : Component(pins, numPins) { }

void LcdI2C::displayText(const char* text) {
        this->lcd.setCursor(col, row);
        lcd.print(text);
    }

void LcdI2C::newLine() {
    this->lcd.setCursor(0, ++col);
}

void LcdI2C::clearScreen() {
    lcd.clear();
    col = 0;
    row = 0;
}