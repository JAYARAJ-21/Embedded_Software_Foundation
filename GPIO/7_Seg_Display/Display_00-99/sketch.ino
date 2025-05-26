uint8_t data[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x67};

void setup()
{
  volatile uint8_t *ddr;
  volatile uint8_t *out;
  uint8_t z=0;
  ddr=(uint8_t *)0x30;                 //Port F;
  *ddr=0xFF;
  ddr=(uint8_t *)0x107;                //Port K;
  *ddr=0x03;
 while(1)
 {
   
  for(uint8_t i=0; i<10; i++)
  { 
    out=(uint8_t *)0x108;
    *out=0xFE;
    out=(uint8_t *)0x31;
    *out=data[z];
    delay(100);
     *out=0x00;
     out=(uint8_t *)0x108;
      *out=0xFD;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(100);
    *out=0x00;

    out=(uint8_t *)0x108;
    *out=0xFE;
    out=(uint8_t *)0x31;
    *out=data[z];
    delay(100);
     *out=0x00;
     out=(uint8_t *)0x108;
      *out=0xFD;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(100);
    *out=0x00;


    out=(uint8_t *)0x108;
    *out=0xFE;
    out=(uint8_t *)0x31;
    *out=data[z];
    delay(100);
     *out=0x00;
     out=(uint8_t *)0x108;
      *out=0xFD;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(100);
    *out=0x00;


    out=(uint8_t *)0x108;
    *out=0xFE;
    out=(uint8_t *)0x31;
    *out=data[z];
    delay(100);
     *out=0x00;
     out=(uint8_t *)0x108;
      *out=0xFD;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(100);
    *out=0x00;


    out=(uint8_t *)0x108;
    *out=0xFE;
    out=(uint8_t *)0x31;
    *out=data[z];
    delay(100);
     *out=0x00;
     out=(uint8_t *)0x108;
      *out=0xFD;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(100);
    *out=0x00;
 
  }
  if(z==9)
  {
    z=0;
    continue;
  }
  z++;

 }
}

void loop()
{

}
