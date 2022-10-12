/*
Name: Ehiane Oigiagbe.
TA's Name: Mac Callahan.
Date created: 11th March 2022. [FRI]
History:	| 11/03/2022:  [FRT]
            *Created a 3 file format for the Yahtzee game. 
            *Implemented The menu components.
 -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            | 12/03/2022: [SAT]
            *Implemented the system pause and system clear functions to the process option function.
            *Created and implemented the back function that reiterates the process function from print rules. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------                 
            |13/03/2022: [SUN]
            *Created a roll die function and initialized an srand to randomize the rolls, I made the roll_die(num) fuction to be more specific. 
            *Created roll_display() function that shows the dice values gotten in a set box.
            *Implemented the logic of only having 3 rolls before scoring. 
            *Created roll_iteration which contains the logic of how the dice is supposed to roll.
            *Created & partially implemented the yahtzee_score_chart() function. I was able to print out the options and ask for an input.
            *Created the scoring_points() function to hold the mathematical componenets of the scoring aspect of the game. 
            *Not implemented the scoring_points() function fully. 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            |14/03/2022: [MON]
            *Figured out that my logic for rolling was flawed.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
            |15/03/2022: [TUE]
            * implemented the correct logic on roll iteration, but the choice of die to reroll isn't changing in my list.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            |16/03/2022: [WED]
            * The choice of the die reroll isnt still changing...
            * started working on the scoring logic.
            * implemented a re-iteration of the question if answer is not between 1-12. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            |17/03/2022: [THUR]
            * Created a frequency function that tells the amount of similar dice a roll has. 
            * Implemented it into the scoring points function.
            * Implemented the 13 rounds after scoring.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            |18/03/2022 [FRI]
            * Created [reverse frequency] function to acquire non-common rolls in an array, and implemented it to the scores of 3 of a kind and 4 of a kind.
            * Created the [3 of a kind] function that collects 3 of a kind of any roll and adds to the sum of uncommon rolls using my reverse_frequency function. 
            * Created the [4 of a kind] function that collects 4 of a kind of any roll and adds to the sum of uncommon rolls using my reverse_frequency function. 
            * Created the [full house]  function that checks if 3 of the die rolled are the same and if 2 of the non-alike die rolled are the same.
            * Created the [Small straight] function that checks if the rolls in the array are continously progressive for 4 values ... i.e (1,2,3,4) or (2,3,4,5) or (3,4,5,6) and assigns 40 to a score.
            * Created the [large straight] function that checks if the rolls in the array are continously progressive for 4 values ... i.e (1,2,3,4,5) or (2,3,4,5).
            * Created the [yahtzee] function that checks if all the rolled are of the same value. 
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |19/03/2022 [SAT]
           * Made minor edits to roll_display function... this requires the function to return a void output and can be called in any funtion. 
           * Implemented the round and the player thing {but my logic might be flawed} .  
           * Created Chance function for scoring.. and implemented it to my scoring_points() function. 
           *  #finding a way to return both score and choice from scoring_points().. also clarifying if it's rounds per game or per person.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |20/ 03/2022 [SUN]
           * TOOK A BREAK
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |21/03/2022 [MON]
           *Figured out that reroll die is working but it's not displaying in roll_display.
           *Finally fixed the reroll_choice function and cleaned it up!
           *Corrected the score bank algorithim... I just have to implement it with two different players and actually keep their score. 
           * Figured out that I can return the score and choice form scoring points to roll_iteration...Therefore i would need to return score from roll iteration to yahtzee main.
           * return score from yahtzee main. then in the actual main. make 2 players and make them function to yahtzee main... asin p1 = yahtzeemain(), p2 = yahtzeemain() . 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |22/ 03/2022 [TUE]
           *Fixed the reroll choice function now you can successfully reroll a die.
           *Made yahtzee_main return the total score for a round. 
           *Created a function that houses both players which would be able to access yahtzee main. 
           *The code Isn't switching between them. --> find solution in yahtzee main curly brace.
 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |23/ 03/2022 [WED]
           *Realised that the program ends after player 1 rolls because of the return function, so I tried to implement a pointer but the compiler gave a null ptr error.
           *My present iteration currently goes for player 1 and 2 once and stops after round one of player 2
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |24/03/2022 [THUR]
           *Succesfully Iterated the rounds between the players.
           * ---All  I need to do is not allow the same section to be scored twice and not allow the same die to be rerolled more than once in a reroll round.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
           |25/03/2022 [FRI]
           *Implemented the logic to make you only choose one section but still not working
           *Should put final score at the end of control center.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Objective: to Build a dice based game using score cards and certain instances to determine your score. 
           In the build of this project I will make use of: 
           loops, arrays, pointers and other data structures that would be needed to score different dice values and 
           assign different points to certain scores,
           based on a collection of dice rolls.


Description: 
*/
#include "yahtzee_header.h"


int main(void) {
    int option = 0;
    //START OF THE GAME:
    printf("WELCOME TO YAHTZEE !!! \n\n");
    //execute menu option
    option = execute_menu_option();
    process_option(option);


    return 0;
}
