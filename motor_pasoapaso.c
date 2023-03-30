#INCLUDE<16f887.h>
#INCLUDE<lcd.c>
#USE DELAY(CLOCK=4000000)
#FUSES XT,PROTECT,NOWDT,NOBROWNOUT,PUT,NOLVP
#DEFINE SW PORTC,0
#DEFINE DIP1 PORTC,1
#DEFINE DIP2 PORTC,2
#BYTE PORTB= 6
#BYTE PORTC=7
Byte CONST horario_4[4]= {0b1000,
                          0b0100,
                          0b0010,
                          0b0001};//configuracion para 4 tiempos
Byte CONST antih_4[4]={0b0001,
                    0b0010,
                    0b0100,
                    0b1000};
Byte CONST horario_8[8]= {0b1000,
                          0b1100,
                          0b0100,
                          0b0110,
                          0b0010,
                          0b0011,
                          0b0001,
                          0b1001};//configuracion para 8 tiempos
Byte CONST antih_8[8]= {0b1001,
                        0b0001,
                        0b0011,
                        0b0010,
                        0b0110,
                        0b0100,
                        0b1100,
                        0b1000};//configuracion para 8 tiempos




VOID MAIN()
{
   lcd_init();
   INT cont;
   SET_TRIS_B(0B000000);    //Configura el puerto B
   PORTB=0;
   while(TRUE){
   cont=0;
   //motor 8 pasos
   if(BIT_TEST(SW)){
      if(BIT_TEST(DIP1)){
         while(cont<8){
             // LCD_GOTOXY(5,1);
            //  LCD_PUTC("Control");
            PORTB=horario_8[cont];
            delay_ms(500);
            cont++;
         }
      }
      //motor 4 pasos
       if((BIT_TEST(DIP2)))
         while(cont<4){
         
            PORTB=horario_4[cont];
            delay_ms(500);
            cont++;
            }
       }
   
      else{
      
         if(BIT_TEST(DIP1)){
         while(cont<8){
               
            PORTB=antih_8[cont];
            delay_ms(500);
            cont++;
         }
      }
      //motor 4 pasos
       if((BIT_TEST(DIP2)))
         while(cont<4){
         
            PORTB=antih_4[cont];
            delay_ms(500);
            cont++;
            }
       }
   
      
      
      }
   }

   



