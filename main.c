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
 #include <avr/power.h> 
#endif


#define PIN        3 

#define NUMPIXELS 30 


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 

void setup() {
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  

  pixels.begin(); 
  Serial.begin(9600);


}


void loop() {
 
int a,c,b;
  char key = keypad.waitForKey();
  

   

//BLUE

while (key=='1'){
  int x;
  a=20+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i, pixels.Color(0,0, a));
    pixels.show();   
}

x=x+10;
    
  }
//RED

while (key=='2'){
  int x;
  a=30+x;
  key=keypad.waitForKey();
for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i, pixels.Color(a,0, 0));
    pixels.show();  
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
    pixels.show();  
}


x=x+10;
    
  } 

//SHUTDOWN
 if (key=='0'){
for(int i=0; i<NUMPIXELS; i++) { 

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
    pixels.show();   

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
    pixels.show();  
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
for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(a,b, c));
    pixels.show();  

}


x=x+10;
    
  }

while (key=='*'){
  char w,e,r;
  char s,d,f;
  char x,c,v;
  int FR, FG,FB;

  if (keypad.waitForKey()=='S'){
    break;
  }
  
  char tag;
  w=keypad.waitForKey();
  if (w=='S'){
    break;
  }
  e=keypad.waitForKey();
  if (e=='S'){
    break;
  }
  r=keypad.waitForKey();
 if (r=='S'){
    break;
  }
  
  char R[4] = { w, e, r, '\0' };
  
  FR=atoi(R);
  Serial.println(FR);

  s=keypad.waitForKey();
  if (s=='S'){
    break;
  }
  d=keypad.waitForKey();
  if (d=='S'){
    break;
  }
  f=keypad.waitForKey();
  if (f=='S'){
    break;
  }
  char G[4] = { s, d, f, '\0' };
  FG=atoi(G);
  Serial.println(FG);


  x=keypad.waitForKey();
  if (x=='S'){
    break;
  }
  c=keypad.waitForKey();
  if (x=='S'){
    break;
  }
  v=keypad.waitForKey();
  if (v=='S'){
    break;
  }
  char B[4] = { x, c, v, '\0' };
  FB=atoi(B);
  Serial.println(FB);

   
  
  for(int i=0; i<NUMPIXELS; i++) { 


    
    pixels.setPixelColor(i, pixels.Color(FR,FG, FB));
    pixels.show();   
   




}
key=keypad.waitForKey();



 }
}
