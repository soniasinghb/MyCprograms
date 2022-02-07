
_main:
	MOV SP+0, #128
;blink.c,44 :: 		void main()
;blink.c,46 :: 		keypadinit();
	LCALL _keypadinit+0
;blink.c,48 :: 		uart1_init(9600);
	MOV TH1+0, #253
	MOV TL1+0, #253
	LCALL _UART1_Init+0
;blink.c,49 :: 		lcdstart();   // Write text in first row
	LCALL _lcdstart+0
;blink.c,50 :: 		stopmotor();
	LCALL _stopmotor+0
;blink.c,51 :: 		while (1)
L_main0:
;blink.c,53 :: 		rfid();
	LCALL _rfid+0
;blink.c,54 :: 		}
	SJMP L_main0
;blink.c,55 :: 		}
	SJMP #254
; end of _main

_rfid:
;blink.c,56 :: 		void rfid(void)
;blink.c,58 :: 		if (UART1_Data_Ready())
	LCALL _UART1_Data_Ready+0
	MOV A, R0
	JZ L_rfid2
;blink.c,60 :: 		cardletter = UART1_Read();
	LCALL _UART1_Read+0
	MOV _cardletter+0, 0
;blink.c,61 :: 		card1();
	LCALL _card1+0
;blink.c,62 :: 		card2();
	LCALL _card2+0
;blink.c,63 :: 		card3();
	LCALL _card3+0
;blink.c,64 :: 		}
L_rfid2:
;blink.c,65 :: 		}
	RET
; end of _rfid

_card1:
;blink.c,68 :: 		void card1(void)//card no.1000699A58BB(PRINTED NO.10539512)
;blink.c,70 :: 		if(cardletter=='6')
	MOV A, _cardletter+0
	XRL A, #54
	JZ #3
	LJMP L_card13
;blink.c,72 :: 		while(!(UART1_Data_Ready()));
L_card14:
	LCALL _UART1_Data_Ready+0
	MOV A, R0
	JNZ L_card15
	SJMP L_card14
L_card15:
;blink.c,73 :: 		cardletter = UART1_Read();
	LCALL _UART1_Read+0
	MOV _cardletter+0, 0
;blink.c,74 :: 		if(cardletter=='C')
	MOV A, R0
	XRL A, #67
	JZ #3
	LJMP L_card16
;blink.c,77 :: 		if(user1amt>49) {user1amt= user1amt-50;
	SETB C
	MOV A, _user1amt+0
	SUBB A, #49
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, _user1amt+1
	XRL A, #128
	SUBB A, R0
	JC L_card17
	CLR C
	MOV A, _user1amt+0
	SUBB A, #50
	MOV R0, A
	MOV A, _user1amt+1
	SUBB A, #0
	MOV R1, A
	MOV _user1amt+0, 0
	MOV _user1amt+1, 1
;blink.c,78 :: 		amounttodisplay= user1amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,79 :: 		balance();   forwardmotor();
	LCALL _balance+0
	LCALL _forwardmotor+0
;blink.c,80 :: 		}
	SJMP L_card18
L_card17:
;blink.c,83 :: 		nobalance();
	LCALL _nobalance+0
;blink.c,84 :: 		keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
	LCALL _keycheck+0
	MOV _k1+0, _key+0
	MOV _k1+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #3
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,85 :: 		keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
	LCALL _keycheck+0
	MOV _k2+0, _key+0
	MOV _k2+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #4
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,86 :: 		user1amt=user1amt + k1*10 +k2;
	MOV R0, _k1+0
	MOV R1, _k1+1
	MOV R4, #10
	MOV R5, #0
	LCALL _Mul_16x16+0
	MOV A, _user1amt+0
	ADD A, R0
	MOV R0, A
	MOV A, _user1amt+1
	ADDC A, R1
	MOV R1, A
	MOV A, R0
	ADD A, _k2+0
	MOV R0, A
	MOV A, R1
	ADDC A, _k2+1
	MOV R1, A
	MOV _user1amt+0, 0
	MOV _user1amt+1, 1
;blink.c,87 :: 		amounttodisplay= user1amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,88 :: 		balance();
	LCALL _balance+0
;blink.c,89 :: 		}}}}
L_card18:
L_card16:
L_card13:
	RET
; end of _card1

_card2:
;blink.c,91 :: 		void card2(void)//card no.1000699A58BB(PRINTED NO.10539512)
;blink.c,93 :: 		if(cardletter=='1')
	MOV A, _cardletter+0
	XRL A, #49
	JZ #3
	LJMP L_card29
;blink.c,95 :: 		while(!(UART1_Data_Ready()));
L_card210:
	LCALL _UART1_Data_Ready+0
	MOV A, R0
	JNZ L_card211
	SJMP L_card210
L_card211:
;blink.c,96 :: 		cardletter = UART1_Read();
	LCALL _UART1_Read+0
	MOV _cardletter+0, 0
;blink.c,97 :: 		if(cardletter=='C')
	MOV A, R0
	XRL A, #67
	JZ #3
	LJMP L_card212
;blink.c,100 :: 		if(user2amt>49) {user2amt= user2amt-50;
	SETB C
	MOV A, _user2amt+0
	SUBB A, #49
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, _user2amt+1
	XRL A, #128
	SUBB A, R0
	JC L_card213
	CLR C
	MOV A, _user2amt+0
	SUBB A, #50
	MOV R0, A
	MOV A, _user2amt+1
	SUBB A, #0
	MOV R1, A
	MOV _user2amt+0, 0
	MOV _user2amt+1, 1
;blink.c,101 :: 		amounttodisplay= user2amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,102 :: 		balance();   forwardmotor();
	LCALL _balance+0
	LCALL _forwardmotor+0
;blink.c,103 :: 		}
	SJMP L_card214
L_card213:
;blink.c,106 :: 		nobalance();
	LCALL _nobalance+0
;blink.c,107 :: 		keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
	LCALL _keycheck+0
	MOV _k1+0, _key+0
	MOV _k1+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #3
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,108 :: 		keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
	LCALL _keycheck+0
	MOV _k2+0, _key+0
	MOV _k2+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #4
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,109 :: 		user2amt=user2amt + k1*10 +k2;
	MOV R0, _k1+0
	MOV R1, _k1+1
	MOV R4, #10
	MOV R5, #0
	LCALL _Mul_16x16+0
	MOV A, _user2amt+0
	ADD A, R0
	MOV R0, A
	MOV A, _user2amt+1
	ADDC A, R1
	MOV R1, A
	MOV A, R0
	ADD A, _k2+0
	MOV R0, A
	MOV A, R1
	ADDC A, _k2+1
	MOV R1, A
	MOV _user2amt+0, 0
	MOV _user2amt+1, 1
;blink.c,110 :: 		amounttodisplay= user2amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,111 :: 		balance();
	LCALL _balance+0
;blink.c,112 :: 		}}}}
L_card214:
L_card212:
L_card29:
	RET
; end of _card2

_card3:
;blink.c,114 :: 		void card3(void)//card no.1000699A58BB(PRINTED NO.10539512)
;blink.c,116 :: 		if(cardletter=='D')
	MOV A, _cardletter+0
	XRL A, #68
	JZ #3
	LJMP L_card315
;blink.c,118 :: 		while(!(UART1_Data_Ready()));
L_card316:
	LCALL _UART1_Data_Ready+0
	MOV A, R0
	JNZ L_card317
	SJMP L_card316
L_card317:
;blink.c,119 :: 		cardletter = UART1_Read();
	LCALL _UART1_Read+0
	MOV _cardletter+0, 0
;blink.c,120 :: 		if(cardletter=='E')
	MOV A, R0
	XRL A, #69
	JZ #3
	LJMP L_card318
;blink.c,123 :: 		if(user3amt>49) {user3amt= user3amt-50;
	SETB C
	MOV A, _user3amt+0
	SUBB A, #49
	MOV A, #0
	XRL A, #128
	MOV R0, A
	MOV A, _user3amt+1
	XRL A, #128
	SUBB A, R0
	JC L_card319
	CLR C
	MOV A, _user3amt+0
	SUBB A, #50
	MOV R0, A
	MOV A, _user3amt+1
	SUBB A, #0
	MOV R1, A
	MOV _user3amt+0, 0
	MOV _user3amt+1, 1
;blink.c,124 :: 		amounttodisplay= user3amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,125 :: 		balance();   forwardmotor();
	LCALL _balance+0
	LCALL _forwardmotor+0
;blink.c,126 :: 		}
	SJMP L_card320
L_card319:
;blink.c,129 :: 		nobalance();
	LCALL _nobalance+0
;blink.c,130 :: 		keycheck();k1=key; Lcd_Chr(2, 3, k1+0x30);
	LCALL _keycheck+0
	MOV _k1+0, _key+0
	MOV _k1+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #3
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,131 :: 		keycheck();k2=key; Lcd_Chr(2, 4, k2+0x30);
	LCALL _keycheck+0
	MOV _k2+0, _key+0
	MOV _k2+1, _key+1
	MOV FARG_Lcd_Chr_row+0, #2
	MOV FARG_Lcd_Chr_column+0, #4
	MOV A, #48
	ADD A, _key+0
	MOV FARG_Lcd_Chr_out_char+0, A
	LCALL _Lcd_Chr+0
;blink.c,132 :: 		user3amt=user3amt + k1*10 +k2;
	MOV R0, _k1+0
	MOV R1, _k1+1
	MOV R4, #10
	MOV R5, #0
	LCALL _Mul_16x16+0
	MOV A, _user3amt+0
	ADD A, R0
	MOV R0, A
	MOV A, _user3amt+1
	ADDC A, R1
	MOV R1, A
	MOV A, R0
	ADD A, _k2+0
	MOV R0, A
	MOV A, R1
	ADDC A, _k2+1
	MOV R1, A
	MOV _user3amt+0, 0
	MOV _user3amt+1, 1
;blink.c,133 :: 		amounttodisplay= user3amt;
	MOV _amounttodisplay+0, 0
	MOV _amounttodisplay+1, 1
;blink.c,134 :: 		balance();
	LCALL _balance+0
;blink.c,135 :: 		}}}}
L_card320:
L_card318:
L_card315:
	RET
; end of _card3

_balance:
;blink.c,138 :: 		void balance(void)
;blink.c,140 :: 		Lcd_Cmd(_LCD_CLEAR);      Lcd_Out(1,1,"THANK YOU USER");
	MOV FARG_Lcd_Cmd_out_char+0, #1
	LCALL _Lcd_Cmd+0
	MOV FARG_LCD_Out_row+0, #1
	MOV FARG_LCD_Out_column+0, #1
	MOV FARG_LCD_Out_text+0, #?lstr1_blink+0
	LCALL _LCD_Out+0
;blink.c,141 :: 		Lcd_Out(2,1,"BAL ");
	MOV FARG_LCD_Out_row+0, #2
	MOV FARG_LCD_Out_column+0, #1
	MOV FARG_LCD_Out_text+0, #?lstr2_blink+0
	LCALL _LCD_Out+0
;blink.c,142 :: 		Lcd_Chr_cp((amounttodisplay/100)+0x30);
	MOV R4, #100
	MOV R5, #0
	MOV R0, _amounttodisplay+0
	MOV R1, _amounttodisplay+1
	LCALL _Div_16x16_S+0
	MOV A, #48
	ADD A, R0
	MOV FARG_Lcd_Chr_CP_out_char+0, A
	LCALL _Lcd_Chr_CP+0
;blink.c,143 :: 		Lcd_Chr_cp(((amounttodisplay/10)%10)+0x30);
	MOV R4, #10
	MOV R5, #0
	MOV R0, _amounttodisplay+0
	MOV R1, _amounttodisplay+1
	LCALL _Div_16x16_S+0
	MOV R4, #10
	MOV R5, #0
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV A, #48
	ADD A, R0
	MOV FARG_Lcd_Chr_CP_out_char+0, A
	LCALL _Lcd_Chr_CP+0
;blink.c,144 :: 		Lcd_Chr_cp((amounttodisplay%10)+0x30);
	MOV R4, #10
	MOV R5, #0
	MOV R0, _amounttodisplay+0
	MOV R1, _amounttodisplay+1
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV A, #48
	ADD A, R0
	MOV FARG_Lcd_Chr_CP_out_char+0, A
	LCALL _Lcd_Chr_CP+0
;blink.c,148 :: 		}
	RET
; end of _balance

_nobalance:
;blink.c,149 :: 		void nobalance(void)
;blink.c,151 :: 		Lcd_Cmd(_LCD_CLEAR);  Lcd_Out(1,1,"less balance");
	MOV FARG_Lcd_Cmd_out_char+0, #1
	LCALL _Lcd_Cmd+0
	MOV FARG_LCD_Out_row+0, #1
	MOV FARG_LCD_Out_column+0, #1
	MOV FARG_LCD_Out_text+0, #?lstr3_blink+0
	LCALL _LCD_Out+0
;blink.c,152 :: 		Lcd_Out(2,1,"please recharge");Delay_ms(500);
	MOV FARG_LCD_Out_row+0, #2
	MOV FARG_LCD_Out_column+0, #1
	MOV FARG_LCD_Out_text+0, #?lstr4_blink+0
	LCALL _LCD_Out+0
	MOV R5, 4
	MOV R6, 129
	MOV R7, 121
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
;blink.c,153 :: 		Lcd_Cmd(_LCD_CLEAR);   Lcd_Out(1,1,"ENTER AMOUNT");
	MOV FARG_Lcd_Cmd_out_char+0, #1
	LCALL _Lcd_Cmd+0
	MOV FARG_LCD_Out_row+0, #1
	MOV FARG_LCD_Out_column+0, #1
	MOV FARG_LCD_Out_text+0, #?lstr5_blink+0
	LCALL _LCD_Out+0
;blink.c,154 :: 		}
	RET
; end of _nobalance

_forwardmotor:
;blink.c,156 :: 		void forwardmotor(void)
;blink.c,158 :: 		motor11=1; motor12=0;    Delay_ms(500);
	SETB P2_7_bit+0
	CLR P2_6_bit+0
	MOV R5, 4
	MOV R6, 129
	MOV R7, 121
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
;blink.c,159 :: 		stopmotor(); Delay_ms(3000);
	LCALL _stopmotor+0
	MOV R5, 22
	MOV R6, 3
	MOV R7, 229
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
;blink.c,160 :: 		motor11=0; motor12=1;    Delay_ms(500);   stopmotor();
	CLR P2_7_bit+0
	SETB P2_6_bit+0
	MOV R5, 4
	MOV R6, 129
	MOV R7, 121
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
	LCALL _stopmotor+0
;blink.c,161 :: 		}
	RET
; end of _forwardmotor

_stopmotor:
;blink.c,164 :: 		void stopmotor(void)
;blink.c,166 :: 		motor11=0; motor12=0;
	CLR P2_7_bit+0
	CLR P2_6_bit+0
;blink.c,167 :: 		}
	RET
; end of _stopmotor

_keycheck:
;blink.c,168 :: 		void keycheck(void)
;blink.c,170 :: 		key=12;
	MOV _key+0, #12
	MOV _key+1, #0
;blink.c,171 :: 		do
L_keycheck21:
;blink.c,173 :: 		C1=0;C2=1;C3=1;
	CLR P1+0
	SETB P1+0
	SETB P1+0
;blink.c,174 :: 		if(R1==0) {key=1;}
	JB P1+0, L_keycheck24
	NOP
	MOV _key+0, #1
	MOV _key+1, #0
L_keycheck24:
;blink.c,175 :: 		if(R2==0) {key=4;}
	JB P1+0, L_keycheck25
	NOP
	MOV _key+0, #4
	MOV _key+1, #0
L_keycheck25:
;blink.c,176 :: 		if(R3==0) {key=7;}
	JB P1+0, L_keycheck26
	NOP
	MOV _key+0, #7
	MOV _key+1, #0
L_keycheck26:
;blink.c,178 :: 		C1=1;C2=0;C3=1;
	SETB P1+0
	CLR P1+0
	SETB P1+0
;blink.c,179 :: 		if(R1==0) {key=2;}
	JB P1+0, L_keycheck27
	NOP
	MOV _key+0, #2
	MOV _key+1, #0
L_keycheck27:
;blink.c,180 :: 		if(R2==0) {key=5;}
	JB P1+0, L_keycheck28
	NOP
	MOV _key+0, #5
	MOV _key+1, #0
L_keycheck28:
;blink.c,181 :: 		if(R3==0) {key=8;}
	JB P1+0, L_keycheck29
	NOP
	MOV _key+0, #8
	MOV _key+1, #0
L_keycheck29:
;blink.c,182 :: 		if(R4==0) {key=0;}
	JB P1+0, L_keycheck30
	NOP
	MOV _key+0, #0
	MOV _key+1, #0
L_keycheck30:
;blink.c,183 :: 		C1=1;C2=1;C3=0;
	SETB P1+0
	SETB P1+0
	CLR P1+0
;blink.c,184 :: 		if(R1==0) {key=3;}
	JB P1+0, L_keycheck31
	NOP
	MOV _key+0, #3
	MOV _key+1, #0
L_keycheck31:
;blink.c,185 :: 		if(R2==0) {key=6;}
	JB P1+0, L_keycheck32
	NOP
	MOV _key+0, #6
	MOV _key+1, #0
L_keycheck32:
;blink.c,186 :: 		if(R3==0) {key=9;}
	JB P1+0, L_keycheck33
	NOP
	MOV _key+0, #9
	MOV _key+1, #0
L_keycheck33:
;blink.c,188 :: 		}while(key==12);
	MOV A, #12
	XRL A, _key+0
	JNZ L__keycheck34
	MOV A, #0
	XRL A, _key+1
L__keycheck34:
	JNZ #3
	LJMP L_keycheck21
;blink.c,189 :: 		delay_ms(300);
	MOV R5, 3
	MOV R6, 26
	MOV R7, 225
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
;blink.c,190 :: 		}
	RET
; end of _keycheck

_lcdstart:
;blink.c,194 :: 		void lcdstart(void)
;blink.c,196 :: 		Lcd_Init();                        // Initialize Lcd
	LCALL _Lcd_Init+0
;blink.c,198 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOV FARG_Lcd_Cmd_out_char+0, #12
	LCALL _Lcd_Cmd+0
;blink.c,199 :: 		Lcd_Out(1,6,"haii");                 // Write text in first row
	MOV FARG_LCD_Out_row+0, #1
	MOV FARG_LCD_Out_column+0, #6
	MOV FARG_LCD_Out_text+0, #?lstr6_blink+0
	LCALL _LCD_Out+0
;blink.c,200 :: 		delay_ms(500);
	MOV R5, 4
	MOV R6, 129
	MOV R7, 121
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
	NOP
;blink.c,201 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOV FARG_Lcd_Cmd_out_char+0, #1
	LCALL _Lcd_Cmd+0
;blink.c,202 :: 		}
	RET
; end of _lcdstart

_keypadinit:
;blink.c,203 :: 		void keypadinit(void)
;blink.c,205 :: 		C1=1; C2=1;C3=1;   //pull up
	SETB P1+0
	SETB P1+0
	SETB P1+0
;blink.c,206 :: 		R1=1; R2=1;R3=1;R3=1;    //pull up
	SETB P1+0
	SETB P1+0
	SETB P1+0
	SETB P1+0
;blink.c,208 :: 		}
	RET
; end of _keypadinit
