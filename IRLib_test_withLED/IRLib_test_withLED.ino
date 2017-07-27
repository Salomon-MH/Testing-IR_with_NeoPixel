#include <Adafruit_NeoPixel.h>
#include <IRLibAll.h>
 
IRrecv myReceiver(3);//receiver on pin 3
IRdecode myDecoder;//Decoder object
 
//One NeoPixel connected to pin 2
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8,2,NEO_GRB + NEO_KHZ800);
 
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  myReceiver.enableIRIn(); // Start the receiver
}


/* This is a NOT WORKING example. It does not work as it just sends a "0"
 * to the serial monitor when recieving ANY IR signal. 
 * The actual signal information is lost.
 */

 
void loop() {
  if (myReceiver.getResults()) {
    myDecoder.decode();
    Serial.println(myDecoder.value, HEX);

    
    myReceiver.enableIRIn(); //Restart the receiver
    
  }
  
  //Do anything with NeoPixel. Dont forget show()!
  strip.setPixelColor(5, strip.Color(255, 255, 255));
  strip.show();
  
}
