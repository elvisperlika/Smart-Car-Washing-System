#ifndef __LIGHT__ // Preprocessor directive: prevents multiple inclusion of this header
#define __LIGHT__

class Light {
public:
  // Declaration of pure virtual methods (without implementation)
  virtual void switchOn() = 0; // Pure virtual method to turn on the light
  virtual void switchOff() = 0; // Pure virtual method to turn off the light
};

#endif // End of the preprocessor directive
