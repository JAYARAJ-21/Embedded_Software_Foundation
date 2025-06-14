#include <Arduino.h>

void initialize(void);
void scan(void);

uint8_t data[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x6F};
//uint8_t common_cathode[]={0x0E, 0x0D, 0x0B, 0x07};
volatile uint8_t *ddr;
volatile uint8_t *column, *rows, *control_7seg, *display, *led;
volatile uint8_t number;

void setup() 
{ 
      initialize();
      scan();
} 
  

void loop() {
  // put your main code here, to run repeatedly:

}

/*
1.Port F 4 bits (LSB) rows 
2.Port  F MSB 4 bits column (pulled down)



3.as of now i don't use led so I didn't configure registers for port D.
*/


void initialize()
{
  ddr=(uint8_t *)0x30; *ddr=0x0F;       //Port F: MSB 4 bits columns and LSB 4 bits rows
  ddr=(uint8_t *)0x27; *ddr=0xFF;       //Port C - 7 Seg 
  ddr=(uint8_t *)0x21; *ddr=0xFF;       //Port A for 7 seg control
  ddr=(uint8_t *)0x2A; *ddr=0x0F;
  rows=(uint8_t *)0x31; column=(uint8_t *)0x2F; // Port F - Keypad
  display=(uint8_t *)0x28;              //Port C - 7 seg data
  control_7seg=(uint8_t *)0x22;              //Port A for 7 seg control 
  led=(uint8_t *)0x2B;                  //led for debugging
  //*led=255;
  *control_7seg=0x0E;
 // *display=0xFF;                       // Port C - 7seg data

}
 

void scan()
{


while(1)
  {  
   
    for(volatile uint8_t i=0; i<4; i++)
    { 
      
      *rows=1<<i;
      //Serial.println(*column/16);
      //*led=*column/16;

      if(i==3 && *column/16 != 2 )
      {
        continue;
      }
      
      if(*column/16==1)
      {
        number=i*3 + *column/16;
        *led=number;
        *display=0x00; 
        delay(10);
        *display=data[number];              // 1 to 3
      }
      
      if(*column/16==2)
      { 
        if(i==3)
        {
          number=0;
          *led=0;                           
          *display=0x00;
          delay(10); 
          *display=data[number];            // 0
          continue;
        }
        number=i*3 + *column/16;
        *led=number;
        *display=0x00;
        delay(10);
        *display=data[number];               // 4 to 6
         

      }

      if(*column/16==4)
      {
        number=i*3 + 3;
        *led=number;
        *display=0x00;
        delay(10);
        *display=data[number];             // 7 to 9
         
      }
      
      else
      {
        *led=0x00;
        
      }
   }
  }

}
