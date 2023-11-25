#ifndef __BUTTONIMPL__ // Header guard to prevent multiple inclusion of this header file
#define __BUTTONIMPL__

#include "Button.h" // Include the Button class header file

class ButtonImpl : public Button { // ButtonImpl class inherits from the Button class
 
public: 
  ButtonImpl(int pin); // Constructor for ButtonImpl class, taking a pin as a parameter

  bool isClicked(); // Overrides the isClicked() method from the base class Button

private:
  int pin;      // Member variable to hold the pin number associated with the button
  bool clicked; // Member variable to track the click state of the button
};

#endif // End of the header guard
