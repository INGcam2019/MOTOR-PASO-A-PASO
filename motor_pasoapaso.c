#INCLUDE<16f887.h>
#USE DELAY(CLOCK=4000000)
#FUSES XT,PROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE SW PORTA,1
#DEFINE LED PORTB,0
#BYTE PORTB= 6
Byte CONST horario[4]= {0b1000,0b0100,0b0010,0b0001};

VOID MAIN()
{
   INT cont;
   SET_TRIS_B(0B000000);    //Configura el puerto B
   PORTB=0;
   cont=0;
   while(TRUE){
   
   PORTB=horario[cont];
   delay_ms(200);
    cont++;
    if(cont>3){
    cont=0;};
    
   
   }
   
}

