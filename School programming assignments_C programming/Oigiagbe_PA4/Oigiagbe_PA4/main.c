/*
Name: Ehiane Oigiagbe
TA's_Name: Mac Callahan
Date_created: 17th Feb 2022
History[edits]:
Description:
Objective:
*/
#include "craps_functions.h"
int main(void) {
	int option = 0, roll1 = 0, roll2 = 0,roll3= 0, roll4 =0, sum_dice1 = 0, sum_dice2= 0,  winorloss= 0, changer = 0;
	double wager= 0.0, bank_balance= 0.0; 
	//START OF THE GAME:
	printf("WELCOME TO THE CRAPS GAME!!! \n\n");
	//execute menu option
	option = execute_menu_option();
	process_option(option);
	return 0;
}