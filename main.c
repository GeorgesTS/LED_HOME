// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include <Keypad.h>



const byte rows = 5 ; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {'L','0','R','E'},
  {'7','8','9','S'},
  {'4','5','6','D'},
  {'1','2','3','U'},
  
  
  {'F','G','#','*'}
  

  
};
byte rowPins[rows] ={8,7,6,5,4};  //connect to the row pinouts of the keypad
byte colPins[cols] ={ 12,11,10,9}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 30 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); 
    Serial.begin(9600);
// INITIALIZE NeoPixel strip object (REQUIRED)
}


  


void loop() {
  // put your main code here, to run repeatedly:char key = keypad.getKey();
  

int a,c,b;
  char key = keypad.waitForKey();
  

    // Serial.println(key);

//BLUE

while (key=='1'){
  int x;
  a=20+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(0,0, a));

    pixels.show();   // Send the updated pixel colors to the hardware.

}

x=x+10;
    
  }
//RED

while (key=='2'){
  int x;
  a=30+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(a,0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

}

x=x+10;

    
  }


//GREEN

while (key=='3'){
  int x;
  a=20+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(1,a, 1));

    pixels.show();   // Send the updated pixel colors to the hardware.

}


x=x+10;
    
  } 

//SHUTDOWN
 if (key=='0'){
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

   pixels.clear();
    pixels.show(); 
}



    
  } 


// WHITE
while (key=='4'){
  int x;
  a=90+x;
  b=90+x;
  c=90+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(a,b, c));

    pixels.show();   // Send the updated pixel colors to the hardware.

}

x=x+20;

    
  }


//LIGHT PINk
while (key=='5'){
  int x;
  a=100+x;
  b=20;
  c=80;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(a,b,c));

    pixels.show();   // Send the updated pixel colors to the hardware.

}


x=x+10;
    
  }


//LIGHT BLUE
int x;
while (key=='6'){
  a=90-x;
  b=80-0.5*x;
  c=10-1;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(a,b, c));

    pixels.show();   // Send the updated pixel colors to the hardware.

}


x=x+10;
    
  }


  
 if (key=='*'){
  a= keypad.waitForKey();
  b =keypad.waitForKey();
  c =keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

 //a = keypad.getKey();
  //b = keypad.getKey();
  //c = keypad.getKey();
  
    
    pixels.setPixelColor(i, pixels.Color(a+50,b, c));

    pixels.show();   // Send the updated pixel colors to the hardware.
   




}
x=x-20;
}


}
