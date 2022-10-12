/*
Name: Ehiane Oigiagbe
TA's_Name: Mac Callahan
Date_created: 17th Feb 2022
History[edits]:
Description:
Objective:
*/
#include "craps_functions.h"
//MENU
void display_menu(void) {
	printf("1. Display rules: \n");
	printf("2. Play craps.  \n");
	printf("3. Exit.\n");
}

//Precondition: prompt must be displayed.
int get_option(void) {

	int option = 0;
	scanf("%d", &option);
	return option;
}

int execute_menu_option(void) {
	int option = 0;
	do
	{
		display_menu();
		option = get_option();
	} while (option < DISPLAY_RULES || option > EXIT_GAME);
	return option;

}

void process_option(int option) {
	double bank_balance = 0;
	double wager = 0;

	switch (option)
	{
	case DISPLAY_RULES: print_game_rules(); 
		break;
	case START_GAME: 
		craps_main();
		break;
	case EXIT_GAME: printf("Thank you for playing CRAPS...\n"); printf("***\nIf you want to play CRAPS, close the program and start again\n***");
		break;
	}
}

// End of menu 
void print_game_rules(void) {
	printf("RULES FOR CRAPS:\nRead the instructions carefully...\n");
	printf("1.   You are to place a bet before rolling the die.  \n");
	printf("2.   After placing a bet from your wages, roll the die[pair of dice] once, if the sum of what is rolled is 7 or 11 on your first try, you win.  \n");
	printf("3.   If the sum of what you rolled is a 2, 3 or 12 on your first roll, you lose and the house wins. \n");
	printf("4.   If the sum of what you rolled is a 4,5,6,8,9 or 10, the sum becomes your point and you roll again. \n");
	printf("5.   On your second roll, if the sum reaches a 7 before reaching the previous number you gained, you lose. \n");
	printf("***\nIf you want to play CRAPS, close the program and start again\n***");
}



double get_bank_balance(void) {

	double bank_balance = 0.0;
	printf("Enter amount to deposit in game:$");
	scanf("%lf", &bank_balance); //the money inputed is assigned to bank balance  
	return bank_balance;

}


double get_wager_amount(void){ 

	double wager_amount = 0.0;
	printf("Enter betting amount on the next dice roll:$");
	scanf("%lf", &wager_amount);


	return wager_amount;
}


int check_wager_amount(double wager, double balance) {
	int go_ahead = 0;
	if (wager > balance) {
		printf("Insufficient balance, try again!!!\n");
		go_ahead = 0; 
		reiterate(go_ahead);
	}
	else if(wager <= balance) {
		
		go_ahead = 1;
	}
	return go_ahead;
}

void reiterate(int go_ahead) {
	int option = 2;
	if (go_ahead == 0) {
		process_option(option);
	}
}

int roll_die(void) {
	
	return (rand()%6)+1;
}


int calculate_sum_dice(int die1_value, int die2_value)
{  
	int sum_dice = die1_value + die2_value;
	return sum_dice;
}

int is_win_loss_or_point(int sum_dice) {

	int determiner;
	if (sum_dice == 7 || sum_dice == 11) {
		 determiner = 1;
		 return determiner;
	}
	else if (sum_dice == 2 || sum_dice== 3|| sum_dice== 12 ) {
		determiner = 0;
		return determiner;
	}
	else {
		printf("\nYou have %d points. Roll again for a chance to win.\n", sum_dice);
		determiner = -1;
		return determiner;
		
	}
}
//precondition: wager must be less than bank balance. 
double add_or_subtract(double wager, int sum_dice, int bank_balance) { 

	int determiner;
	determiner = is_win_loss_or_point(sum_dice);
	double updated_bank_balance = 0;

	if (determiner == 1) {
		updated_bank_balance=  bank_balance + wager;
		return updated_bank_balance;
	}
	else if (determiner == 0) {
		updated_bank_balance = bank_balance - wager;
		return updated_bank_balance;
	}
}


void chatter_messages( int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	printf("\tThis is your bank balance before roll :$%lf", initial_bank_balance);
	printf("\n\tThis is your new bank balance:$ %lf", current_bank_balance);

	if (win_loss_neither == 1) {
		printf("\n**YOU'RE A WINNER!!!** \n\t:)\n ");
		printf("***\nIf you want to play again close the program and start again\n***");
	}
	else if(win_loss_neither == 0)
	{
		printf("\n**SORRY FOR YOUR LOSS** \n\t:(\n");
		printf("***\nIf you want to play again close the program and start again\n***");
	}
	else if (win_loss_neither = -1)
	{
		printf("\n**Try Again**\n");
		printf("***\nIf you want to play again close the program and start again\n***");
	}


}


void craps_main(void) {
	int roll1 = 0, roll2 = 0, roll3 = 0, roll4 = 0, sum_dice1 = 0, sum_dice2 = 0, winorloss = 0, changer = 0;

	double bank_balance, new_bank_balance;
	double wager;

	bank_balance = get_bank_balance();
	wager = get_wager_amount();
	check_wager_amount(wager, bank_balance);
	srand((unsigned int)time(NULL));

	do {

		int n = 0;
		do
		{
			printf("***FIRST ROLL***\n");
			roll1 = roll_die();
			printf("rolling die..........\n");
			printf("die1: %d\n", roll1);
			printf("rolling die..........\n");
			roll2 = roll_die();
			printf("die2: %d\n", roll2);
			sum_dice1 = calculate_sum_dice(roll1, roll2);
			printf("sum of die: %d\n\n", sum_dice1);
			if (sum_dice1 == 7 || sum_dice1 == 11) {

			    winorloss = is_win_loss_or_point(sum_dice1);
				new_bank_balance = add_or_subtract(wager, sum_dice1, bank_balance);
				return chatter_messages(winorloss, bank_balance, new_bank_balance);
			

			}
			else if (sum_dice1 == 2 || sum_dice1 == 3 || sum_dice1 == 12) {
			    winorloss = is_win_loss_or_point(sum_dice1);
			    new_bank_balance = add_or_subtract(wager, sum_dice1, bank_balance);
				return chatter_messages(winorloss, bank_balance, new_bank_balance);
				
			} //end of first roll  
			n = 1;

		} while (n != 1);

		while (sum_dice1 != 0)
		{
			printf("\n***ANOTHER ROLL***\n");
			roll3 = roll_die();
			printf("rolling die..........\n");
			printf("die3: %d\n", roll3);
			printf("rolling die..........\n");
			roll4 = roll_die();
			printf("die4: %d\n", roll4);
			sum_dice2 = calculate_sum_dice(roll3, roll4);
			printf("sum of die: %d\n\n", sum_dice2);

			if (sum_dice2 == 7) {
				winorloss = is_win_loss_or_point(2);
			    new_bank_balance = add_or_subtract(wager, 2, bank_balance);
				return chatter_messages(winorloss, bank_balance, new_bank_balance);
				
	
			}
			else if (sum_dice2 == sum_dice1) {
			    winorloss = is_win_loss_or_point(7);
			    new_bank_balance = add_or_subtract(wager, 7, bank_balance);
				return chatter_messages(winorloss, bank_balance, new_bank_balance);
				

			}
		}

	} while (sum_dice2 != sum_dice1);
}
