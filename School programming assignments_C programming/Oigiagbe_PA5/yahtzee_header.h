#ifndef Yahtzee
#define Yahtzee

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//MACROS:
#define DISPLAY_RULES 1
#define START_GAME 2
#define EXIT_GAME 3

//Function declarations:
	//Menu components.
void display_menu(void);
int get_option(void);
int execute_menu_option(void);
void process_option(int option);
void print_game_rules(void);
void back(void);
int yahtzee_main(char player, int sum_score, int rounds, int *choice, int list[]);
	//Operative components.
		//Pre-scoring.
int roll_die(int die_num);
void roll_display(int list[], int size_list);
             //PRECAUTION: i must be 0.
int roll_iteration(int die1, int die2, int die3, int die4, int die5, int i, int* choice, int list[]);
void reroll_choice(int list[], int size, int reroll_num);
//int keep_dice(void);
	   //SCORING:
int yahtzee_score_chart(void);
int freq(int target, int list[], int list_size);
int reverse_freq(int target, int list[], int list_size);
int three_of_a_kind( int list[], int list_size);
int four_of_a_kind(int list[], int list_size);
int full_house(int list[], int list_size);
int small_straight(int list[], int list_size);
int large_straight(int list[], int list_size);
int yahtzee_point(int list[], int list_size);
int chance(int list[], int list_size);
int scoring_points(int list[], int *choice); //this maybe able to return *choice and score for me --> [ int scoring_points(int list[], int *score, int *choice); ]
       //Postscoring.
int score_bank(int *choice, int score, int choice_list[]);
int yahtzee_control_center(void);
char get_player_name(int position);
#endif // !Yahtzee
