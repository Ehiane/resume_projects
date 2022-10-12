/*
Name: Ehiane Oigiagbe
TA's_Name: Mac Callahan
Date_created: 17th Feb 2022
History[edits]:
Description:
Objective:
*/
#ifndef CRAPS_FUNCTIONS_H
#define CRAPS_FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>

//define MACROS 
#define DISPLAY_RULES 1
#define START_GAME 2
#define EXIT_GAME 3




//menu 
void display_menu(void);
int get_option(void);
int execute_menu_option(void);
void process_option(int option);
//end of menu

void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
void reiterate(int go_ahead); //custom function
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
double add_or_subtract(double wager, int sum_dice, int bank_balance);
void chatter_messages( int win_loss_neither, double initial_bank_balance, double current_bank_balance);
void craps_main(void);


#endif 
