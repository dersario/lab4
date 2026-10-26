#include <Keypad.h> 

char hexaKeys[4][4] = { 
  {'1','2','3','A'}, 
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
}; 

byte rowPins[4] = {5,4,3,2}; 
byte colPins[4] = {11,10,9,8}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, 4, 4); 

void setup() { 
  Serial.begin(9600);  
} 

void loop() { 
  if (customKeypad.getKeys()) { 
    for (int i = 0; i < LIST_MAX; i++) { 
      if (customKeypad.key[i].stateChanged && customKeypad.key[i].kstate == PRESSED) { 
        Serial.println(customKeypad.key[i].kchar); 
      } 
    } 
  } 
} 