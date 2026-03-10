#include <avr/io.h> // include the avr library

#include <util/delay.h> // include the delay library

#define F_CPU  8000000UL; // set the frequency of your clk arduino already have 16mhz frequency so no use of it , just for knowledge purpose

// here the macros is use to make the blink code more easier so that we does not always require to set and clear the bit

#define SET_BIT(PORT , BIT) ((PORT) |= (1<< (BIT)));  //SET THE CONDITION FOR LED HIGH, here we have define for set bit that is when the switch is low the led will blink that means our output port PB3 will set to 1
#define CLEAR_BIT(PORT , BIT) ((PORT) &= ~(1<< (BIT))); //SET THE CONDITION FOR LED LOW, these is inverse o fhigh when switch is high the led is off 

int main (void){

  DDRB =  DDRB | (1<<3);   // MAKING PB3 AS OUT PUT PIN
  DDRB = DDRB & (~(1<<2));  // MAKING PB2 AS INPUT PIN here for input we are using switch that is connected pin of PB2 in circuit diagram the connection shown also uno in pin out 
  PORTB = PORTB | (1<<2);    

  int pin_status;         // MAKING PIN STATUS TO MAKE LED ON AND OFF
  while(1){
    pin_status = PORTB & (1<<2); // here we set pin status set to 1 (then what is 2 it is the port i.e is PB2) we are applying condition for switch 
                                // that is when switch is high the led is off and switch is low the led is on
                        
    if(pin_status){

       CLEAR_BIT(PORTB , 3);  // SWITCH IS HIGH SO LED IS OFF

    }
    else{

        SET_BIT(PORTB , 3); // WHEN SWITCH IS PRESSED THE LED WILL BECOME HIGH
    }
   }
  return 0;
}
