#ifndef PIN_H
#define PIN_H

class Pin {
public:
    Pin(unsigned short pinNumber, unsigned short type);
    Pin();
    int getPinNumber();
    unsigned short getPinType();

private:
    unsigned short pinNumber;
    unsigned short type;
};

#endif
