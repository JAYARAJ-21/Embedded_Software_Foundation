#include <Arduino.h>

#define off (*out=0x00)
#define DELAY delay(2);

void data_direction_register_init(void);
void display_a(void);
void display_b(void);
void display_c(void);
void display_d(void);
void display_e(void);



void setup() 
{
  data_direction_register_init();
  while(1)
  {
     display_a();
     display_b();
     display_c();
     display_d();
     display_e();
  }
 

}

void loop() {
  // put your main code here, to run repeatedly:

}


void data_direction_register_init(void)
{
  volatile uint8_t *ddr;
  ddr=(uint8_t *)0x30;   *ddr=0xff;        // Port F
  ddr=(uint8_t *)0x107;  *ddr=0xff;        // Port K
}

void display_a(void)
{
  volatile uint8_t *out, *ground;
  out=(uint8_t *)0x31; 
  ground=(uint8_t *)0x108;
for(volatile uint8_t i=0; i<63; i++)
{
      off; *ground=~(1<<1); *out=0x7f;
      DELAY;
      off; *ground=~(1<<2); *out=0x44;
      DELAY;
      off; *ground=~(1<<3); *out=0x44;
      DELAY;
      off; *ground=~(1<<4); *out=0x44;
      DELAY;
      off; *ground=~(1<<5); *out=0x44;
      DELAY;
      off; *ground=~(1<<6); *out=0x7c;
      DELAY; 
}
}
 

void display_b(void)
{
  volatile uint8_t *out, *ground;
  out=(uint8_t *)0x31; 
  ground=(uint8_t *)0x108;

  for(volatile uint8_t i=0; i<63; i++)
  {
      off; *ground=~(1<<0); *out=0x7e;
      DELAY;
      off; *ground=~(1<<1); *out=0x42;
      DELAY;
      off; *ground=~(1<<2); *out=0x42;
      DELAY;
      off; *ground=~(1<<3); *out=0x7e;
      DELAY;
      off; *ground=~(1<<4); *out=0x40;
      DELAY;
      off; *ground=~(1<<5); *out=0x40;
      DELAY;
      off; *ground=~(1<<6); *out=0x40;
      DELAY;
   }
}

void display_c(void)
{
   
  volatile uint8_t *out, *ground;
  out=(uint8_t *)0x31; 
  ground=(uint8_t *)0x108;

  for(volatile uint8_t i=0; i<63; i++)
  {
    
      off; *ground=~(1<<1); *out=0x1e;
      DELAY;
      off; *ground=~(1<<2); *out=0x20;
      DELAY;
      off; *ground=~(1<<3); *out=0x40;
      DELAY;
      off; *ground=~(1<<4); *out=0x40;
      DELAY;
      off; *ground=~(1<<5); *out=0x20;
      DELAY;
      off; *ground=~(1<<6); *out=0x1e;
      DELAY;
 }
}

void display_d(void)
{
    
  volatile uint8_t *out, *ground;
  out=(uint8_t *)0x31; 
  ground=(uint8_t *)0x108;

  for(volatile uint8_t i=0; i<63; i++)
  {
    
      off; *ground=~(1<<1); *out=0x3b;
      DELAY;
      off; *ground=~(1<<2); *out=0x44;
      DELAY;
      off; *ground=~(1<<3); *out=0x44;
      DELAY;
      off; *ground=~(1<<4); *out=0x3c;
      DELAY;
      off; *ground=~(1<<5); *out=0x04;
      DELAY;
      off; *ground=~(1<<6); *out=0x04;
      DELAY;
 }
}

void display_e(void)
{
   
  volatile uint8_t *out, *ground;
  out=(uint8_t *)0x31; 
  ground=(uint8_t *)0x108;

  for(volatile uint8_t i=0; i<63; i++)
  {
     // off; *ground=~(1<<0); *out=0x7e;
      //DELAY;
      off; *ground=~(1<<1); *out=0x3c;
      DELAY;
      off; *ground=~(1<<2); *out=0x40;
      DELAY;
      off; *ground=~(1<<3); *out=0x7e;
      DELAY;
      off; *ground=~(1<<4); *out=0x42;
      DELAY;
      off; *ground=~(1<<5); *out=0x3c;
      DELAY;
     
 }
}
