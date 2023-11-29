#ifndef BUTTONTASK_H
#define BUTTONTASK_H

#include "Task.h"
#include <Arduino.h>

class ButtonTask {
public:
    ButtonTask(Button* button); // Costruttore che prende un puntatore a un oggetto Button
    void checkButtonState(); // Metodo per controllare lo stato del bottone

private:
    Button* buttonPtr; // Puntatore all'oggetto Button
};

#endif // BUTTONTASK_H
