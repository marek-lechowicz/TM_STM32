/*
* functions.c
*
*  Created on: Dec 3, 2021
*      Author: student
*/
#include "gpio.h"
#include "functions.h"

void get_color(double temperature) {
	// wejście LED1
	GPIO_InitTypeDef Led1_in;
	Led1_in.Pin = LED1_Pin;
	Led1_in.Pull = GPIO_NOPULL;
	Led1_in.Mode = GPIO_MODE_INPUT;

	// wyjście dla LED1
	GPIO_InitTypeDef Led1_out;
	Led1_out.Pin = LED1_Pin;
	Led1_out.Pull = GPIO_NOPULL;
	Led1_out.Mode = GPIO_MODE_OUTPUT_PP;

	// wejście LED2
	GPIO_InitTypeDef Led2_in;
	Led2_in.Pin = LED2_Pin;
	Led2_in.Pull = GPIO_NOPULL;
	Led2_in.Mode = GPIO_MODE_INPUT;

	// wyjście dla LED2
	GPIO_InitTypeDef Led2_out;
	Led2_out.Pin = LED2_Pin;
	Led2_out.Pull = GPIO_NOPULL;
	Led2_out.Mode = GPIO_MODE_OUTPUT_PP;

	// wejście LED3
	GPIO_InitTypeDef Led3_in;
	Led3_in.Pin = LED3_Pin;
	Led3_in.Pull = GPIO_NOPULL;
	Led3_in.Mode = GPIO_MODE_INPUT;

	// wyjście dla LED3
	GPIO_InitTypeDef Led3_out;
	Led3_out.Pin = LED3_Pin;
	Led3_out.Pull = GPIO_NOPULL;
	Led3_out.Mode = GPIO_MODE_OUTPUT_PP;

	// wejście LED4
	GPIO_InitTypeDef Led4_in;
	Led4_in.Pin = LED4_Pin;
	Led4_in.Pull = GPIO_NOPULL;
	Led4_in.Mode = GPIO_MODE_INPUT;

	// wyjście dla LED4
	GPIO_InitTypeDef Led4_out;
	Led4_out.Pin = LED4_Pin;
	Led4_out.Pull = GPIO_NOPULL;
	Led4_out.Mode = GPIO_MODE_OUTPUT_PP;

	char color;
	if (temperature < 18) {
		color = 'W';
	}
	else if (temperature < 20) {
		color = 'A';
	}
	else if (temperature < 22) {
		color = 'B';
	}
	else if (temperature < 24) {
		color = 'G';
	}
	else if (temperature < 26) {
		color = 'Y';
	}
	else if (temperature > 26) {
		color = 'R';
	}
	switch (color) {
		case 'W':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_out);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_out);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_out);   // R
			break;
		case 'A':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_out);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_out);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_in);   // R
			break;
		case 'B':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_out);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_in);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_in);   // R
			break;
		case 'G':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_in);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_out);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_in);   // R
			break;
		case 'Y':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_in);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_out);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_out);   // R
			break;
		case 'R':
			HAL_GPIO_Init(LED1_GPIO_Port, &Led1_out);
			HAL_GPIO_Init(LED2_GPIO_Port, &Led2_in);	// B
			HAL_GPIO_Init(LED3_GPIO_Port, &Led3_in);	// G
			HAL_GPIO_Init(LED4_GPIO_Port, &Led4_out);   // R
			break;
	}
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
}

void digit(int digit) {
  switch (digit) {
	  case 0:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		  break;

	  case 1:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		  break;

	  case 2:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 3:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 4:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 5:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 6:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 7:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_RESET);
		  break;

	  case 8:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

	  case 9:
		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, GPIO_PIN_SET);
		  break;

  };
}

//	void display_digit(auto& port, auto& pin, int digit, int delay_between_digits) {
//	  digit(digit);
//	  HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
//	  HAL_Delay(delay_between_digits);
//	  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
//	}



int * convert_into_digits(int number) {
	int *digits = malloc(4 * sizeof(int));
	digits[0] = (int) number / 1000;
	digits[1] = (int) (number - digits[0] * 1000) / 100;
	digits[2] = (int) (number - digits[0] * 1000 - digits[1] * 100) / 10;
	digits[3] = (int) (number - digits[0] * 1000 - digits[1] * 100 - digits[2] * 10);
	return digits;
}

void display_number(int number, int delay_between_digits) {
	int *arr_num = convert_into_digits(number);
	digit(arr_num[0]);
	HAL_GPIO_WritePin(COM1_GPIO_Port, COM1_Pin, GPIO_PIN_RESET);
	HAL_Delay(delay_between_digits);
	HAL_GPIO_WritePin(COM1_GPIO_Port, COM1_Pin, GPIO_PIN_SET);

	digit(arr_num[1]);
	HAL_GPIO_WritePin(COM2_GPIO_Port, COM2_Pin, GPIO_PIN_RESET);
	HAL_Delay(delay_between_digits);
	HAL_GPIO_WritePin(COM2_GPIO_Port, COM2_Pin, GPIO_PIN_SET);

	digit(arr_num[2]);
	HAL_GPIO_WritePin(COM3_GPIO_Port, COM3_Pin, GPIO_PIN_RESET);
	HAL_Delay(delay_between_digits);
	HAL_GPIO_WritePin(COM3_GPIO_Port, COM3_Pin, GPIO_PIN_SET);

	digit(arr_num[3]);
	HAL_GPIO_WritePin(COM4_GPIO_Port, COM4_Pin, GPIO_PIN_RESET);
	HAL_Delay(delay_between_digits);
	HAL_GPIO_WritePin(COM4_GPIO_Port, COM4_Pin, GPIO_PIN_SET);
}


