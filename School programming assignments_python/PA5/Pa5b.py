#Ehiane Kelvin Oigiagbe.
#18th October 2021.
#CptS 111, Fall 2021.
#Programming Assignment 5b.
#getting the score of the list created in pa5a.

def score_faves(scr_gme):
    '''
    A non-void function that iterates through a list of scores
    for the user's chosen game and calculates the total score for the game
    '''
#initialises the score point for attributes to 0.  
    scr_total = 0
#loops through each attribute to assign scores to the game title
    for i in scr_gme:

        if i == 'h':
            scr_total += 5
        elif i == 'm':
            scr_total += 3
        elif i == 'l':
            scr_total += 1
        else:
            return 'incalculable'
    return scr_total

def main():
    '''
    A void function that opens the text file for the progam to read and detects
    the game the user wants to score and reads the game title and its scores from the text
    file. The program then prints the game's total score.
    '''
#opens the file for faves but in a readable format(no editing).
    file_for_faves = open('faves.txt', 'r').read()
#assigns dictonary of game to the evaluation of file for faves.
    dict_gme = eval(file_for_faves)
# prompt for accessing score of desired game title
    title_gme = input('Enter the game title you want to score: ')
# assigns title of game to the lowercase and clears space.
    title_gme = title_gme.lower().strip()
    print('')   
#searches for the title of game in the dictionary.
    if title_gme in dict_gme:
        
        scr_gme = score_faves(dict_gme[title_gme])
        #prints the score of the ratings.
        print('Your score for {} is {}.'.format(title_gme.title(), scr_gme))

    else:
        print('Game title not found in database.')





#calls the function.
main()





