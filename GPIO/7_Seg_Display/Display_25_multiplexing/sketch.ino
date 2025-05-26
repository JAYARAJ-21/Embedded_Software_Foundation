void setup() 
{
  volatile uint8_t *ddr;
  ddr=(uint8_t *)0x30;                 //Port F
  *ddr=0xFF;
  ddr=(uint8_t *)0x107;                //Port K
  *ddr=0x03;

  volatile uint8_t *out;
  volatile uint32_t t;
  while(1)
  {
      out=(uint8_t *)0x108;
      *out=0xfe;                      //0b11111110 
      out=(uint8_t *)0x31;
      *out=0x5b;                      //Digit '2'
      for(t=0; t<40000; t++);         //delay
      *out=0x00;      
      out=(uint8_t *)0x108;
      *out=0xfd;                      //0b11111101
      out=(uint8_t *)0x31;
      *out=0x6d;                      //Digit '5'
      for(t=0; t<40000; t++);         //delay
      *out=0x00;                           
  }
}

void loop() 
{

}

