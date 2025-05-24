uint8_t data[]={ 0x3F, 0x06, 0X5B, 0x4F, 0X66, 0X6D, 0x7C, 0x07, 0x7F, 0x67};

void setup() {
  volatile uint8_t *ddr;
  ddr=(uint8_t *)0x30;
  *ddr=0xFF;
  ddr=(uint8_t *)0x107;
  *ddr=0xFF;

  // put your setup code here, to run once:

}

void loop() {
  volatile uint8_t *out_F, *out_K;
  out_F=(uint8_t *)0x31;
  out_K=(uint8_t *)0x108;
  volatile uint32_t t;
  for(uint8_t i=0; i<10; i++)
  {
    *out_F=data[i];
    for(uint8_t j=0 ;j<10; j++)
    {
      *out_K=data[j];
      for(t=0; t<500000; t++);
    }
  }
   
    
 
}

