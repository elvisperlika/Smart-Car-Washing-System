#ifndef PIN_H
#define PIN_H

enum PinType {
    GENERAL_PIN,
    INPUT_PIN,
    OUTPUT_PIN,
    SDA_PIN,
    SCL_PIN
};

class Pin {
public:
    Pin(unsigned short pinNumber, PinType type);
    Pin();
    int getPinNumber();
    PinType getPinType();

private:
    unsigned short pinNumber;
    PinType type;
};

#endif
