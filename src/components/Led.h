#ifndef __LED__ // Header guard to prevent multiple inclusion of this header file
#define __LED__

#include "Light.h" // Including the Light header file

class Led : public Light { // Defining a class Led that inherits from the Light class
public:
  Led(int pin); // Constructor for the Led class that takes the pin number as an argument
  void switchOn(); // Method to switch on the LED
  void switchOff(); // Method to switch off the LED    
protected:
  int pin;  // Protected member variable to hold the pin number associated with the LED
};

#endif // End of the header guard
