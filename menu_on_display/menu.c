/**
  ********************************************************************************************************************************************
  * @file     STM32_00_HelloWorld_01-blinkLED.c
  * @author   SPSE Havirov
  * @version  1.0
  * @date     03-March-2022 [v1.0]
  * @brief    Blikani vestavene(ych) LED v nekonecne smycce, pokud neni stisknuto uzivatelske tlacitko.
  *           Pri stisku uzivatelskeho tlacitka LED sviti.
  *
  ********************************************************************************************************************************************
  * @attention
  *
  * Otestovano na: F407, F401, G071
  *
  * Netestovano: F411, L152
  *
  ********************************************************************************************************************************************
*/

#include "stm32_kit.h"

#define KEYPAD_COLS   4                                           // Pocet sloupcu pouziteho KeyPad
#define KEYPAD_ROWS   4 

#include "stm32_kit/lcd.h"                                 				// Pripojeni konfiguracniho souboru pro praci s LCD.
#include "stm32_kit/keypad.h"                             			  // Pripojeni konfiguracniho souboru pro praci s KeyPad.

  static uint8_t KeyPad_KeyMap[KEYPAD_ROWS][KEYPAD_COLS] = {      // Defaultni rozlozeni pro 4x4 KeyPad
                            '1', '2', '3', 'A',
                            '4', '5', '6', 'B',
                            '7', '8', '9', 'C',
                            '*', '0', '#', 'D'
 };

uint8_t getkey(void) {
	uint8_t znak;
	do{
			znak = KeyPad_getKey();
		}while (!znak);
		return znak;
}

char menu[][9] = 																									//Dvoj rozmerne pole pro deklaraci menu
	{
		"1 PNEU  ",																										//Muzeme s nim pracovat jako se stringem
		"2 DIAG  ",
		"3 CHIP  ",
		"4 BALANC",
	};
char auta[][9] =
  {
		"1 AUDI  ",
		"2 BMW   ",
		"3 SKODA ",
		"4 NISSAN",
	};	
BOARD_SETUP void setup(void) 
{
  SystemCoreClockUpdate();                                      // Do SystemCoreClock se nahraje frekvence jadra.
  SysTick_Config(SystemCoreClock / 10000);                      // Konfigurace SysTick timeru.
  LCD_setup();                                                  // Pocatecni inicializace LCD, nutne pro dalsi praci s LCD.
  KeyPad_setup();                                               // Pocatecni inicializace keypadu, nutne pro dalsi praci s keypad.
}
int main(void)
{
uint8_t znak;
int i=0;	
	while (1)
	{
		uint8_t znak;
		
		LCD_set (LCD_LINE1);
		LCD_print (" SERVIS ");
		
		znak = getkey();
		
		if(znak == '6' && i!=3)																				//IF, aby jsme kontrolovali ze jsme porad v rozmeru naseho pole
			{																													
			i++;																												//Pricitani i++ posouvame se v nasem poli do prava
			}
		else if(znak =='5' && i!= 0)																	//Pri petce muzeme jet do az do i = 0
			{
				i--;																											//Odcitani i-- posouvame se v nasem poli do leva
			}
		LCD_set (LCD_LINE2);
		LCD_print(menu[i]);
			
		uint8_t volba;
		volba = getkey();
		switch (volba)
			{
			case '1':
				LCD_set(LCD_LINE2);
				LCD_print("POTVRD");
				znak = getkey();
				if(znak=='0')
					{
						do{
								LCD_set(LCD_CLR);
								LCD_set(LCD_LINE2);
								LCD_print(menu[i]);
								znak = getkey();
						  }while(znak != '#');
					}
	}
}
}