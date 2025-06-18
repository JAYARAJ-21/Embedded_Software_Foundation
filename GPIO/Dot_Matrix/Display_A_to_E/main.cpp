//Uncomment if you are using Arduino
//#include <Arduino.h>
 
#define off (*out=0x00);
#define DELAY delay(2);

volatile uint8_t *ddr, *out, *ground;

void data_register_init(void);
void display_A(void);
void display_B(void);
void display_C(void);
void display_D(void);
void display_E(void);

void setup() 
{
 
 ddr=(uint8_t *)0x30; *ddr=0xff;                     //Port-F - 5v
 ddr=(uint8_t *)0x107; *ddr=0xff;                    //Port-K - Ground
 

while(1)
{ 
  display_A();
  display_B();
  display_C();
  display_D();
   
}
 

}

void loop() 
{
}


void data_register_init(void)
{
  out=(uint8_t *)0x31;                                //Port-F
  ground=(uint8_t *)0x108;                            //Port-K
}

void display_A(void)
{ 
 data_register_init();
for(volatile uint8_t i=0; i<70; i++)
{
    off; *ground=~(1<<0); *out=0x41;
  DELAY;
  off; *ground=~(1<<1); *out=0x41;
  DELAY;
  off; *ground=~(1<<2); *out=0x7f;
  DELAY;
  off; *ground=~(1<<3); *out=0x41;
  DELAY;
  off; *ground=~(1<<4); *out=0x41;
  DELAY;
  off; *ground=~(1<<5); *out=0x22;
  DELAY;
  off; *ground=~(1<<6); *out=0x14;
  DELAY;
  off; *ground=static_cast<uint8_t>(~(1<<7)); *out=0x08;
  DELAY;
}
 
}


void display_B(void)
{
  data_register_init();
  for(volatile uint8_t i=0; i<63; i++)
  { 
  off; *ground=~(1<<0); *out=0x7e;
  DELAY;
  off; *ground=~(1<<1); *out=0x41;
  DELAY;
  off; *ground=~(1<<2); *out=0x41;
  DELAY;
  off; *ground=~(1<<3); *out=0x7e;
  DELAY;
  off; *ground=~(1<<4); *out=0x41;
  DELAY;
  off; *ground=~(1<<5); *out=0x41;
  DELAY;
  off; *ground=~(1<<6); *out=0x7e;
  DELAY;

  }

}

void display_C(void)
{
  data_register_init();

  for(volatile uint8_t i=0; i<63; i++)
  {
    off; *ground=~(1<<0); *out=0x7f;
    DELAY;
    off; *ground=~(1<<1); *out=0x41;
    DELAY;
    off; *ground=~(1<<2); *out=0x40;
    DELAY;
    off; *ground=~(1<<3); *out=0x40;
    DELAY;
    off; *ground=~(1<<4); *out=0x40;
    DELAY;
    off; *ground=~(1<<5); *out=0x41;
    DELAY;
    off; *ground=~(1<<6); *out=0x7f;
    DELAY;
  }
}

void display_D(void)
{
  data_register_init();

  for(volatile uint8_t i=0; i<63; i++)
  {
    off; *ground=~(1<<0); *out=0xff;
    DELAY;
    off; *ground=~(1<<1); *out=0x21;
    DELAY;
    off; *ground=~(1<<2); *out=0x21;
    DELAY;
    off; *ground=~(1<<3); *out=0x21;
    DELAY;
    off; *ground=~(1<<4); *out=0x21;
     DELAY;
    off; *ground=~(1<<5); *out=0x21;
     DELAY;
    off; *ground=~(1<<6); *out=0xff;
     DELAY;

  }
}


void display_E(void)
{

}
/*
1.next problem do using double pointers.

*/
