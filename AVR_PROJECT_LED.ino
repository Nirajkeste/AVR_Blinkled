#include <avr/io.h> // include the avr library

#include <util/delay.h> // include the delay library

#define F_CPU  8000000UL; // set the frequency of your clk arduino already have 16mhz frequency so use of it , just for knowledge purpose

// here the macros is use to make the blink code more easier so that we does not always require to set and clear the bit

#define SET_BIT(PORT , BIT) ((PORT) |= (1<< (BIT)));  //SET THE CONDITION FOR LED HIGH         
#define CLEAR_BIT(PORT , BIT) ((PORT) &= ~(1<< (BIT))); //SET THE CONDITION FOR LED LOW

int main (void){

  DDRB =  DDRB | (1<<3);   // MAKING PB3 AS OUT PUT PIN
  DDRB = DDRB & (~(1<<2));  // MAKING PB2 AS INPUT PIN here for input we are using switch that is connected pin of PB2 in circuit diagram the connection shown also uno in pin out 
  PORTB = PORTB | (1<<2);    

  int pin_status;         // MAKING PIN STATUS TO MAKE LED ON AND OFF
  while(1){
    pin_status = PORTB & (1<<2);
    if(pin_status){

       SET_BIT(PORTB , 3);

    }
    else{

        CLEAR_BIT(PORTB , 3);
    }
   }
  return 0;
}