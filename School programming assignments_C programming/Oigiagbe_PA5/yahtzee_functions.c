#include "yahtzee_header.h"

//Function Definitions:
void display_menu(void) {
	printf("1. Display rules: \n");
	printf("2. Start a game of YAHTZEE!!!.  \n");
	printf("3. Exit.\n");
	printf("\n\n\n");
}

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
	int a = 0;
	switch (option)
	{
	case DISPLAY_RULES: system("pause"); print_game_rules();  back();    
		break;
	case START_GAME:
		system("pause"); a = yahtzee_control_center(); system("pause"), printf("Thank you for playing Yahtzee...\n"); system("pause");  system("cls"); 
	case EXIT_GAME: system("pause"); printf("Thank you for playing Yahtzee...\n");  system("pause");  system("cls");
		break;
	}
}

void print_game_rules(void) {
	
	printf("\n*********\nThe Rules of Yahtzee :\nThe scorecard used for Yahtzee is composed of two sections. A upper sectionand a lower section.\nA total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\nThe upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\nIf a player rolls four 3s, then the score placed in the 3s box is the sum of the dice which is 12.\nOnce a player has chosen to score a box, it may not be changed and\nthe combination is no longer in play for future rounds.\nIf the sum of the scores in the upper section is greater than or equal to 63,\nthen 35 more points are added to the players overall score as a bonus.\n*********\n");

}

void back(void) {
	int option = 0;
	char ans = '\0';
	printf("\n****DO YOU WANT TO GO BACK TO THE MENU ??****[Y|N]\n>>>");
	scanf(" %c", &ans);
	if (ans == 'Y' || ans == 'y') {
		system("cls");
		option = execute_menu_option();
		process_option(option);
	}
	else if (ans == 'N' || ans == 'n') {
		printf("\n****\nEnd of program\n****\n");
	}
}

char get_player_name(int position) { 
	  char name = "\0";
	  printf("Enter First initial for player %d [**Do not enter a new line**]: ", position);
	  scanf(" %c", &name);
	 return name;
}

int yahtzee_control_center(void) {

	int player1 = get_player_name(1), player2 = get_player_name(2);
	int player1_score = 0, player2_score = 0;
	int player1_round = 0, player2_round = 0;
	int rounds = 14;
	int player1_temp_score = 0, player2_temp_score = 0;
	
	int player1_choices[14] = { 0 }, player2_choices[14] = { 0 };

	int player1_choice = 0, player2_choice = 0;

	for (int i = 0; i < rounds; i++) {
		

		player1_score = yahtzee_main(player1, player1_score, player1_round, &player1_choice, player1_choices);
		player1_temp_score += player1_score;
		printf("\nPlayer %c total score = %d\n", player1, player1_temp_score);
		system("pause");
		system("cls");



		player2_score = yahtzee_main(player2, player2_score, player2_round, &player2_choice, player2_choices);
		player2_temp_score += player2_score;
		printf("\nPlayer %c total score = %d\n", player2, player2_temp_score);
		system("pause");
		system("cls");




		player1_round++;
		player2_round++;

	}
	system("pause");
	system("cls");
	
	if (player1_temp_score > player2_temp_score) {
		printf("\n******************************************************************\nThe winner is PLAYER 1!!! with %d points for 13 rounds \n*********************************************************************\n", player1_temp_score);
	}
	else if(player2_temp_score > player1_temp_score)
	{
		printf("\n******************************************************************\nThe winner is PLAYER 2!!! with %d points for 13 rounds \n*********************************************************************\n", player2_temp_score);
	}

}




int yahtzee_main(char player, int sum_score, int total_rounds, int* choice, int list[]) {
	int die1 = 0, die2 = 0, die3= 0, die4= 0, die5= 0, i = 0; 
	int round_score = 0;
	char ans = '\0';
	
	
		
			printf("\n****%c *****\n*******Round %d *********\n\n ",player, (total_rounds+1));
			printf("**************************************\n**************************************\n*************\"YAHTZEEE\"*************\n**'HIT ANY KEY TO ROLL YOUR 5 DIE'**\n************************************\n");
			system("pause");
			srand((unsigned int)time(NULL));
			round_score = roll_iteration(die1, die2, die3, die4, die5, i, choice, list);
			system("pause");
			system("cls");
			system("pause");
			
		total_rounds += 1;
		printf("\nPlayer %c score for this round = %d\n", player, round_score);
		

	return round_score;
}

int roll_die(int die_num) {
	int roll = 0;
	roll = (rand() % 6) + 1;
	printf("rolling die... \n");
	printf("die%d: %d\n", die_num,roll);
	return roll;
}

void roll_display(int list[], int size_list) {
	int temp_list[6] = { 0 };

	printf(">>[");
	for (int i = 1; i < size_list; i++) {
		printf(" %d,", list[i]);

	}
	
	printf("]\n");
}

int roll_iteration(int die1, int die2, int die3, int die4, int die5, int i, int* choice, int list[]) {

	int score = 0, checker = 0;
	char ans = '\0';
	
	
		 while(i <= 3) {
			
			if (i == 0) {
				printf("\n");
				die1 = roll_die(1);
				die2 = roll_die(2);
				die3 = roll_die(3);
				die4 = roll_die(4);
				die5 = roll_die(5);
				printf("\n");
				 
			}
			int die_values[6] = { 100, die1, die2, die3, die4, die5 }; // I will ignore die_value[0] in my iteration.

			roll_display(die_values, 6); 
			

			printf("****Do you wish to re-roll your die?[Y|N]\nNOTE:\n***YOU CAN ONLY ROLL 3 TIMES IN TOTAL\n>>>>");  
			scanf(" %c", &ans);
			//ask for which dice to hold
				if ((ans == 'Y' || ans == 'y') && i < 3 ) {
					int reroll_num = 0;
					printf("How many dice would you like to reroll?\n\n");
					scanf("%d", &reroll_num);
					system("pause");
				    reroll_choice( die_values, 6, reroll_num);
					system("pause");
					printf("\n");
				
				}
				else if (ans == 'n' || ans == 'N') {
					printf("\n***YOU HAVE EXHAUSTED YOUR 3 ROLLING CHANCES***\n  !Proceed to scoring!\n");
					system("pause");
					system("cls");
					roll_display(die_values, 6);
					printf("\n\n");
					score = scoring_points(die_values, choice);
					checker = score_bank(choice, score, list); // checks if the section has been used before.
					return score;
				}
				
				else if (i == 3) {
					printf("\n***YOU HAVE EXHAUSTED YOUR 3 ROLLING CHANCES***\n  !Proceed to scoring!\n");
					system("pause");
					system("cls");
					roll_display(die_values, 6);
					printf("\n\n");
					score = scoring_points(die_values, choice);
					checker = score_bank(choice, score, list); // checks if the section has been used before.
					return score;
				}
				i++;
				//basically saving the reroll choices
				die1 = die_values[1];
				die2 = die_values[2];
				die3 = die_values[3];
				die4 = die_values[4];
				die5 = die_values[5];
		}
	
}



void reroll_choice(int list[], int size, int reroll_num) { 
	
	int freq_list[6] = {0};

	int choice = 0, num = 0;
	printf("Which dice would you like to reroll?\n");

	for (int i = 1; i < size; i++) {
		printf("%d. die %d: %d\n", i , i , list[i]);
	}
	
	while (num < reroll_num ) {
		printf("\n>>>");
		scanf("%d", &choice);
		list[choice] = roll_die(choice); 
		freq_list[choice]++;
		++num;
	}

	while (freq_list[choice] > 1) {
		system("cls");
		printf("\n****You broke the code because you chose the same roll multiple times in one iteration\nPlease restart the program.\n****");
		exit(0); //I got this from stdlib.h
	}

	//calling update roll_display here
	roll_display(list, size);
	printf("\n");
	return list;

}

int freq(int target, int list[], int list_size) { // gives me the sum of common dice rolls 

	int freq_list[7] = { 0 }; 
	for (int i = 1; i < list_size; i++) {

		if (target == list[i]) {
			freq_list[target]++;
		}
	}
	printf("There are %d %d's found in your roll\n", freq_list[target], target);
	return freq_list[target];
}

int reverse_freq(int target, int list[], int list_size) { // gives me the sum of different dice rolls. 

	int entry = 0;

	for (int i = 1; i < list_size; i++) {

		if (target != list[i]) {

			entry += list[i];
		}
	}

	return entry;
}

int three_of_a_kind( int list[], int list_size) {
	int  tally_1 = 0, tally_2 = 0 , tally_3 = 0, tally_4 = 0, tally_5 = 0, tally_6 = 0;
	int result = 0 ;
	tally_1 = freq(1, list, list_size);
	tally_2 = freq(2, list, list_size);
	tally_3 = freq(3, list, list_size);
	tally_4 = freq(4, list, list_size);
	tally_5 = freq(5, list, list_size);
	tally_6 = freq(6, list, list_size);



	if (tally_1 == 3) {
		result = (tally_1 * 1) + reverse_freq(1, list, 6); 
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_2 == 3) {
		result = (tally_2 * 2) + reverse_freq(2, list, 6); 
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_3 == 3) {
		result = (tally_3 * 3) + reverse_freq(3, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_4 == 3) {
		result = (tally_4 * 4) + reverse_freq(4, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_5 == 3) {
		result = (tally_5 * 5) + reverse_freq(5, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_6 == 3) {
		result = (tally_6 * 6) + reverse_freq(6, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else {
		result = 0;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}

}

int four_of_a_kind(int list[], int list_size) {

	int  tally_1 = 0, tally_2 = 0, tally_3 = 0, tally_4 = 0, tally_5 = 0, tally_6 = 0;
	int result = 0;
	tally_1 = freq(1, list, list_size);
	tally_2 = freq(2, list, list_size);
	tally_3 = freq(3, list, list_size);
	tally_4 = freq(4, list, list_size);
	tally_5 = freq(5, list, list_size);
	tally_6 = freq(6, list, list_size);

	if (tally_1 == 4) {
		result = (tally_1 * 1) + reverse_freq(1, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_2 == 4) {
		result = (tally_2 * 2) + reverse_freq(2, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_3 == 4) {
		result = (tally_3 * 3) + reverse_freq(3, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_4 == 4) {
		result = (tally_4 * 4) + reverse_freq(4, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_5 == 4) {
		result = (tally_5 * 5) + reverse_freq(5, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_6 == 4) {
		result = (tally_6 * 6) + reverse_freq(6, list, 6);
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else {
		result = 0;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}

}

int full_house(int list[], int list_size) {

	int  tally_1 = 0, tally_2 = 0, tally_3 = 0, tally_4 = 0, tally_5 = 0, tally_6 = 0;
	int result = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0, temp_4 = 0, temp_5 = 0, temp_6 = 0;
	tally_1 = freq(1, list, list_size);
	tally_2 = freq(2, list, list_size);
	tally_3 = freq(3, list, list_size);
	tally_4 = freq(4, list, list_size);
	tally_5 = freq(5, list, list_size);
	tally_6 = freq(6, list, list_size);

	temp_1 = reverse_freq(1, list, 6);
	temp_2 = reverse_freq(1, list, 6);
	temp_3 = reverse_freq(1, list, 6);
	temp_4 = reverse_freq(1, list, 6);
	temp_5 = reverse_freq(1, list, 6);
	temp_6 = reverse_freq(1, list, 6);
	

	if (tally_1 == 3 && temp_1 ) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if ( tally_2 == 3 && temp_2 ) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_3 == 3 && temp_3) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_4 == 3 && temp_4) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_5 == 3 && temp_5) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else if (tally_6 == 3 && temp_6) {
		result = 25;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}
	else {
		result = 0;
		printf("Your scored: %d for this section. \n", result);
		return result;
	}


}

int small_straight(int list[], int list_size) {

	int score = 0;
	if (   list[1] == 1 && list[2] == 2 && list[3] == 3 && list[4] == 4
		|| list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5
		|| list[1] == 3 && list[2] == 4 && list[3] == 5 && list[4] == 6
		|| list[1] == 1 && list[2] == 2 && list[3] == 3 && list[4] == 4
		|| list[1] == 2 && list[2] == 4 && list[3] == 3 && list[4] == 5
		|| list[1] == 3 && list[2] == 4 && list[3] == 5 && list[4] == 6 
		|| list[1] == 4 && list[2] == 5 && list[3] == 3 && list[4] == 2
		|| list[1] == 5 && list[2] == 4 && list[3] == 3 && list[4] == 2
		|| list[1] == 4 && list[2] == 3 && list[3] == 2 && list[4] == 1
		|| list[1] == 3 && list[2] == 4 && list[3] == 2 && list[4] == 1
		|| list[1] == 1 && list[2] == 4 && list[3] == 3 && list[4] == 2
		) {



		score = 30;
		return score;
	}
}

int large_straight(int list[], int list_size) {

	int score = 0;
	if (   list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5
		|| list[0] == 2 && list[1] == 3 && list[2] == 4 && list[3] == 5 && list[4] == 6){
		score = 40;
		return score;

	}
}

int yahtzee_point(int list[], int list_size) {

	int score = 0;

	if (   list[0] == 1 && list[1] == 1 && list[2] == 1 && list[3] == 1 && list[4] == 1
		|| list[0] == 2 && list[1] == 2 && list[2] == 2 && list[3] == 2 && list[4] == 2
		|| list[0] == 3 && list[1] == 3 && list[2] == 3 && list[3] == 3 && list[4] == 3
		|| list[0] == 4 && list[1] == 4 && list[2] == 4 && list[3] == 4 && list[4] == 4
		|| list[0] == 5 && list[1] == 5 && list[2] == 5 && list[3] == 5 && list[4] == 5
		|| list[0] == 6 && list[1] == 6 && list[2] == 6 && list[3] == 6 && list[4] == 6) {

		score = 50;
		return score;
	}
	else
	{
		return score;
	}


}

int chance(int list[], int list_size) {

	int list_sum = 0;
	for (int i = 1; i < list_size; i++) {
		list_sum += list[i];
	}
	return list_sum;
}



 int yahtzee_score_chart(void) {
	int ans = 0;
	printf("**************************************\n**************************************\n*****>>YAHTZEE SCORING CHART<<********\n**************************************\n**************************************\n");
	printf("_______________________________________\n");
	printf("*** SELECT YOUR DESIRED COMBINATION ***\n");
	printf("> 1. SUM OF 1'S\n");
	printf("> 2. SUM OF 2'S\n");
	printf("> 3. SUM OF 3'S\n");
	printf("> 4. SUM OF 4'S\n");
	printf("> 5. SUM OF 5'S\n");
	printf("> 6. SUM OF 6'S\n");
	printf("> 7. THREE-OF-A-KIND\n");
	printf("> 8. FOUR-OF-A-KIND\n");
	printf("> 9. FULL HOUSE\n");
	printf("> 10. SMALL STRAIGHT\n");
	printf("> 11. LARGE STRAIGHT\n");
	printf("> 12. ****YAHTZEE*****\n");
	printf("> 13. ------CHANCE------\n");
	printf("\n>>>");
	scanf(" %d", &ans);

	return ans;
}

 int score_bank(int *choice, int score, int choice_list[]) {
	 int choice_list_size = 14;
	 int final_score = 0;

	 if (*choice == 0) {
		 final_score += score;
		 printf("You scored: %d for this section \n", final_score);
	 }

	 for (int i = 1; i < choice_list_size; i++) { //loops through choice list

		 if (*choice > 0) { //updates choice after being used.

			 choice_list[*choice] ++;
			 
			
		 }
		 if (choice_list[*choice] > 1) {
			 printf("********You have already selected this option. **********\n********Your score is %d for this section ***********", score);
		 }
	 }

	 return final_score;
 }

int scoring_points(int list[], int* choice) {  //this should return score and choice in order to avoid scoring the same section 2x.
	int ans, redo=0, frequency= 0, score= 0, checker = 0;
	


	while (redo == 0) {
		ans = yahtzee_score_chart();
		if (ans == 1) {
			
			printf("adding score...\n");
			frequency= freq(1, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 2) {
			
			printf("adding score...\n");
			frequency = freq(2, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 3) {
	
			printf("adding score...\n");
			frequency = freq(3, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 4) {
			
			printf("adding score...\n");
			frequency = freq(4, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(0, score);
			choice++;
			redo = 1;
		}
		else if (ans == 5) {
			
			printf("adding score...\n");
			frequency = freq(5, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 6) {
		
			printf("adding score...\n");
			frequency = freq(6, list, 6);
			score = (frequency * ans);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 7) {
		
			printf("adding score...\n");
			score = three_of_a_kind(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 8) {
		
			printf("adding score...\n");
			score = four_of_a_kind(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 9) {
			
			printf("adding score...\n");
			score = full_house(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 10) {
			
			printf("adding score...\n");
			score = small_straight(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 11) {
			
			printf("adding score...\n");
			score = large_straight(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else if (ans == 12) {
			
			printf("adding score...\n");
			score = yahtzee_point(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			*choice++;
			redo = 1;
		}
		else if (ans == 13) {
			
			printf("adding score...\n");
			score = chance(list, 6);
			printf("You scored: %d for this section \n", score);//checker = score_bank(choice, score);
			choice++;
			redo = 1;
		}
		else {
			system("cls");
			printf("Incorrect selection\nchoose between [1-12]\n\n\n");
			choice = 0;
			redo = 0;
			
		}

	}

	return score;
}

