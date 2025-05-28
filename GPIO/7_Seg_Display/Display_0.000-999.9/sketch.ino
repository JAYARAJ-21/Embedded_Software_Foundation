 
uint8_t data[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
void setup() 
{
  volatile uint8_t *ddr;
  ddr=(uint8_t *)0x30;           //Port F
  *ddr=0xFF;
  ddr=(uint8_t *)0x107;          //Port K
  *ddr=0x0F;
  
  volatile uint8_t *out;
  uint8_t a=0, b=0, c=0, i=0, flag=0;
  while(1)
  {
       
      for(i=0; i<10; i++)
      {
       out=(uint8_t *)0x108;             // 1st digit
      *out=0xFE;                         
      out=(uint8_t *)0x31;
      *out=data[a];                       
      delay(20);
      *out=0x00;

      out=(uint8_t *)0x108;             // 2nd digit
      *out=0xFD;                      
      out=(uint8_t *)0x31;
      *out=data[b]; 
      delay(20);
      *out=0x00;
      
      
      out=(uint8_t *)0x108;             // 3rd digit
      *out=0xFB;
      out=(uint8_t *)0x31;
      *out=data[c];
      delay(20);
      *out=0x00;

      out=(uint8_t *)0x108;           // 4th digit
      *out=0xF7;
      out=(uint8_t *)0x31;
      *out=data[i];
      delay(20);
      *out=0x00;



      if(flag==0)
      {
        out=(uint8_t *)0x108;
        *out=0xfe;
        out=(uint8_t *)0x31;
        *out=0x80;
        delay(20);
        *out=0x00;

      }
      else if(flag==1)
      {
        out=(uint8_t *)0x108;
        *out=0xfd;
        out=(uint8_t *)0x31;
        *out=0x80;
        delay(20);
        *out=0x00;
      }
      else if(flag==2)
      {
        out=(uint8_t *)0x108;
        *out=0xFB;
        out=(uint8_t *)0x31;
        *out=0x80;
        delay(20);
        *out=0x00;
      }

      }
      
       
       if(a==9 && b==9 && c==9 && i==10)
      {
         
        a=1; b=0; c=0; i=0;
        flag++;
        continue; 

      }

      if(i==10)
      {
        c++;
      }
      if(c==10)
      {
        b++;
        c=0;
      }
      if(b==10)
      { 
        a++;
        b=0;
      }

     
                                                         // not only a and i, all should be included
      
       
      
     

  }
  
}

void loop() 
{

  
}

