//RX PIN 10  (P3_0)      //RFID(EM-18 MODULE)
//TX PIN 11 (P3_1)
int user1amt=45, user2amt=50,user3amt=70,amounttodisplay;
int k1,k2;
char cardletter;//rfid variable


//lcd connections
sbit LCD_RS at P2_3_bit;
sbit LCD_EN at P2_2_bit;
sbit LCD_D4 at P2_1_bit;
sbit LCD_D5 at P2_0_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D7 at P2_5_bit;
//motor
sbit motor11 at P2_7_bit;
sbit motor12 at P2_6_bit;
//KEYPAD CONNECTIONS
#define R1 P1.F0  //pin 1
#define R2 P1.F1  //pin 2
#define R3 P1.F2  //pin 3
#define R4 P1.F3  //pin 4
#define C1 P1.F4  //pin 13
#define C2 P1.F5  //pin 14
#define C3 P1.F6  //pin 15


int key=12;
void keydelay(void);
void keypadinit(void);
void keycheck(void);


void card1(void);
void card2(void);
 void card3(void);
void rfid(void);

void forwardmotor(void) ;
void stopmotor(void);
void nobalance(void);
void balance(void);
void lcdstart(void);
void main() 
{
keypadinit();

uart1_init(9600);
lcdstart();   // Write text in first row
stopmotor();
while (1)
{
rfid();
}
}
void rfid(void)
{
  if (UART1_Data_Ready())
   {
cardletter = UART1_Read();
card1();
card2();
 card3();
}
}


 void card1(void)//card no.1000699A58BB(PRINTED NO.10539512)
{
if(cardletter=='6')
{
while(!(UART1_Data_Ready()));
cardletter = UART1_Read();
if(cardletter=='C')
{ 

if(user1amt>49) {user1amt= user1amt-50;
 amounttodisplay= user1amt;
 balance();   forwardmotor();
 }
else
 {
nobalance();
keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
user1amt=user1amt + k1*10 +k2;
 amounttodisplay= user1amt;
 balance();
 }}}}
 
void card2(void)//card no.1000699A58BB(PRINTED NO.10539512)
{
if(cardletter=='1')
{
while(!(UART1_Data_Ready()));
cardletter = UART1_Read();
if(cardletter=='C')
{

if(user2amt>49) {user2amt= user2amt-50;
 amounttodisplay= user2amt;
 balance();   forwardmotor();
 }
else
 {
nobalance();
keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
user2amt=user2amt + k1*10 +k2;
 amounttodisplay= user2amt;
 balance();
 }}}}
 
void card3(void)//card no.1000699A58BB(PRINTED NO.10539512)
{
if(cardletter=='D')
{
while(!(UART1_Data_Ready()));
cardletter = UART1_Read();
if(cardletter=='E')
{

if(user3amt>49) {user3amt= user3amt-50;
 amounttodisplay= user3amt;
 balance();   forwardmotor();
 }
else
 {
nobalance();
keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
user3amt=user3amt + k1*10 +k2;
 amounttodisplay= user3amt;
 balance();
 }}}}
 

void balance(void)
{
Lcd_Cmd(_LCD_CLEAR);      Lcd_Out(1,1,"THANK YOU USER");
Lcd_Out(2,1,"BAL ");
Lcd_Chr_cp((amounttodisplay/100)+0x30);
Lcd_Chr_cp(((amounttodisplay/10)%10)+0x30);
Lcd_Chr_cp((amounttodisplay%10)+0x30);

  

}
void nobalance(void)
{
 Lcd_Cmd(_LCD_CLEAR);  Lcd_Out(1,1,"less balance");
  Lcd_Out(2,1,"please recharge");Delay_ms(500);
  Lcd_Cmd(_LCD_CLEAR);   Lcd_Out(1,1,"ENTER AMOUNT");
}

void forwardmotor(void)
{
 motor11=1; motor12=0;    Delay_ms(500);
 stopmotor(); Delay_ms(3000);
   motor11=0; motor12=1;    Delay_ms(500);   stopmotor();
}


void stopmotor(void)
{
 motor11=0; motor12=0;
}
void keycheck(void)
{
key=12;
do
{
C1=0;C2=1;C3=1;
if(R1==0) {key=1;}
if(R2==0) {key=4;}
if(R3==0) {key=7;}
//if(R4==0) {key=10;}
C1=1;C2=0;C3=1;
if(R1==0) {key=2;}
if(R2==0) {key=5;}
if(R3==0) {key=8;}
if(R4==0) {key=0;}
C1=1;C2=1;C3=0;
if(R1==0) {key=3;}
if(R2==0) {key=6;}
if(R3==0) {key=9;}
//if(R4==0) {key=11;}
}while(key==12);
delay_ms(300);
}



void lcdstart(void)
{
  Lcd_Init();                        // Initialize Lcd
              // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,6,"haii");                 // Write text in first row
  delay_ms(500);
   Lcd_Cmd(_LCD_CLEAR);               // Clear display
}
void keypadinit(void)
{
C1=1; C2=1;C3=1;   //pull up
R1=1; R2=1;R3=1;R3=1;    //pull up

}