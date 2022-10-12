#Ehiane Kelvin Oigiagbe.
#18th October 2021.
#CptS 111, Fall 2021.
#Programming Assignment 5a.
#collecting data for pa5a to calculate.


def add_faves(dict_gme):
    
    '''
    A void function with one parameter that writes a video game title and scores
    for the video game to a text file. The function repeates this until the user
    enters return. The function then adds the game title as a key and the scores
    as values in a dictionary and writes this to the text file. 

    '''

#opening file for faves.    
    file_for_faves = open('faves.txt', 'w')

    while True:
#while constructed to allow return key to escape the loop. 
        print('')
#creating empty list for game scores.        
        scr_gme = []
#prompt for the game title.
        title_gme = input('Enter a video game title[return to the end]: ')

        if title_gme == '':
            break
#prompts for game attributes:
        
        visual_score = input('Visuals [hi/med/low]: ')
        scr_gme.append(visual_score[0].lower())
    
        production_score = input('Production Design [hi/med/low]: ')
        scr_gme.append(production_score[0].lower())
    
        music_score = input('Music [hi/med/low]: ')
        scr_gme.append(music_score[0].lower())
    
        sound_score = input('Sound Design [hi/med/low]: ')
        scr_gme.append(sound_score[0].lower())
    
        story_score = input('Story [hi/med/low]: ')
        scr_gme.append(story_score[0].lower())
        
        character_score = input('Characters [hi/med/low]: ')
        scr_gme.append(character_score[0].lower())
    
        gameplay_score = input('Game Play [hi/med/low]: ')
        scr_gme.append(gameplay_score[0].lower())
    
        title_gme = title_gme.lower().strip()

        dict_gme[title_gme] = scr_gme
        
    print(dict_gme, file= file_for_faves)
#closes the file.
    file_for_faves.close()

    return


    



def main():
    '''
    A void function with no parameters that asks the user if they already have a text file and if they
    do it calls add_faves() it passes the empty dictionary into the function. Otherwise, it prints an error if the user enters anything
    '''

    answer = input('Do you already have a faves.txt file [y/n]?: ')

    if answer == 'n':
        #adds the answers adds_faves function in the game_dict dictionary.
        game_dict = {}
        add_faves(game_dict)
        
    elif answer == 'y':
# if no, the new entry will overwrite the old entry.
        faves_file = open('try.txt', 'r').read()
        game_dict = eval(faves_file)
        add_faves(game_dict)

    else:
        print('Error, please try again.')







#calls the function
main()
