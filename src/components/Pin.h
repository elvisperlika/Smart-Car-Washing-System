#ifndef PIN_H
#define PIN_H

enum PinType {
    INPUT_PIN,
    OUTPUT_PIN,
    SDA_PIN,
    SCL_PIN
};

class Pin {
public:
    Pin(int pinNumber, PinType type);
    int getPinNumber();
    PinType getPinType();

private:
    int pinNumber;
    PinType type;
};

#endif
