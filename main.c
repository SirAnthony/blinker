
#include <iostm8s103f3.h>

#define DELAY 30000

void delay(unsigned long time)
{
   while(time--)
      asm("nop");
}

void toggle()
{
  PD_ODR_bit.ODR2 = !PD_ODR_bit.ODR2;
  PD_ODR_bit.ODR3 = !PD_ODR_bit.ODR3;
}

int main( void )
{
  // B5
  PB_DDR_bit.DDR5 = 1;
  PB_CR1_bit.C15 = 1;
  PB_ODR_bit.ODR5 = 1;
  // D2
  PD_DDR_bit.DDR2 = 1;
  PD_CR1_bit.C12 = 1;
  PD_CR2_bit.C22 = 0;
  // D3
  PD_DDR_bit.DDR3 = 1;
  PD_CR1_bit.C13 = 1;
  PD_CR2_bit.C23 = 0;
  
  // Blink led
  PB_ODR_bit.ODR5 = 0;
  delay(10000);
  PB_ODR_bit.ODR5 = 1;
  
  // Start
  PD_ODR_bit.ODR2 = 1;
  while (1)
  {
    toggle();
    delay(DELAY);
  }
  return 0;
}