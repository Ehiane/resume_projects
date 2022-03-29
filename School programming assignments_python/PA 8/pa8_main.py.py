#Team Members for Kyle Team 2:

#Ehiane Oigiagbe
#Bas Hertogh
#Daniel Peluso
#Emma Speight
#Ivan Cruz

#Date: 12/ 08/ 2021

#Programming Assignment 8

#Creating a Meteor Shower Game.

#Description:  This code generates a replica of a meteor Shower game, in which there is one player(red) dogdeing metors(yellow) for surviaval
# which generates a total score at the end of the game.


#-----------------------------------------------------------------------------------------#
import pygame as pyg
import random as r
import tkinter as tk
#------------------------------------------------------------------------------------------#
def set_speed(score):
    '''
    A non-void function with 1 parameter, the integer score.
    sets the speed to 5. 
    The score divided by 20 increments the speed
    and then the speed is returned.
    '''
    speed = 5
    speed += (score//20)
    return speed

def draw_meteors(met_list, met_dim, screen, yellow):
    '''
    A void function with 4 parameters, the meteor position nested list,
    the size of the meteores, the game screen size and the meteor color.
    Contains a for loop that iterates the range of the meteor positions
    and draws the screen, asigns the color and draws the meteors.
    '''

    for i in range(0, len(met_list)):
        pyg.draw.rect(screen, yellow, (met_list[i][0], met_list[i][1], met_dim, met_dim))
    return

def drop_meteors(met_list, met_dim, width, score):
    '''
    A void function with 3 parameters, the nested list, the size of the meteors,
    the width of the game screen and the score.

    contains an if-elif-else conditional, that increases the speed based of the score.
    and randomizes the positions of the meteor dropping.
    '''
    if score < 100:
        r_time = r.randint(0,100)
    elif score < 200:
        r_time = r.randint(0, 50)
    elif score < 300:
        r_time = r.randint(0, 30)
    else:
        r_time = r.randint(0, 15)


    if r_time < 10:                         #condtional with random int generated
                                            #so meteor time drops are randomized
        met_x_pos = r.randrange(0,width, met_dim )
        met_list.append([met_x_pos, 0])
    return



def update_meteor_positions(met_list, height, score, speed):
    '''
    A non-void function with 3 parameters, the nested list of meteor positions, the height of the game screen,
    the score and speed.
     contains a for loop that iterates through the nested list and checks for the y coordinate if it is less than the game hieght
     it adds to the speed. If the meteor gets to the bottom, it removes the meteor and adds to the score.
    '''

    for meteor in met_list:
        if meteor[1] < height:
            meteor[1] += speed
        else:
            met_list.remove(meteor)
            score += 1
    return score



def detect_collision(player_pos, met_pos, player_dim, met_dim):
    '''
     A non- void function with 4 parameters, the player position, the nested list of positions, the player's dimensions,
     and the meteor's dimensions.
        It sets the game status to false and assigns the meteor ranges and player ranges.
        if the game status is true, then the game ends. 
    '''

    #First check x position for both
    #Then check y position
    #use nested conditional
     #   y pos is down

    #print(met_pos)

    game_status = False
    
    meteor_range_x = met_pos[0] + met_dim

    player_range_x = player_pos[0] + player_dim

    meteor_range_y = met_pos[1] + met_dim

    player_range_y = player_pos[1] + player_dim

    if player_pos[0] <= meteor_range_x <= player_range_x or player_pos[0] <= met_pos[0] <= player_range_x:
        if player_pos[1] <= meteor_range_y <= player_range_y or player_pos[1] <= met_pos[1] <= player_range_y:
            game_status = True
    else:
        game_status = False
    return game_status


def collision_check(met_list, player_pos, player_dim, met_dim):
    '''
    A non- void function  with 4 parameters, the nested list, the meteor positions, the player positions list, player's dimensions and
    Meteors dimensions.'

    has a for loop that iterates through the met_list to detect collision, if detect collision is true, then the game ends.
    '''

    game_over = False
    for meteor in met_list:
        if detect_collision(player_pos, meteor, player_dim, met_dim) == True:
            game_over = True
    return game_over















def main():
    '''
    Initialize pygame and pygame parameters.  Note that both player and meteors
    are square.  Thus, player_dim and met_dim are the height and width of the
    player and meteors, respectively.  Each line of code commented.
    '''
    pyg.init()                # initialize pygame

    width = 800               # set width of game screen in pixels
    height = 600              # set height of game screen in pixels

    

    red = (255,0,0)           # rgb color of player
    yellow = (244,208,63)     # rgb color of meteors
    background = (0,0,156)    # rgb color of sky (midnight blue)
    #background = tk.PhotoImage(file='space_back.JFIF')
    
    player_dim = 50           # player size in pixels
    player_pos = [width/2, height-2*player_dim]  # initial location of player
                                                 # at bottom middle; height
                                                 # never changes

    met_dim = 20              # meteor size in pixels
    met_list = []             # initialize list of two-element lists
                              # giving x and y meteor positions

    screen = pyg.display.set_mode((width, height)) # initialize game screen

    game_over = False         # initialize game_over; game played until
                              # game_over is True, i.e., when collision
                              # is detected

    score = 0                 # initialize score

    clock = pyg.time.Clock()  # initialize clock to track time

    my_font = pyg.font.SysFont("monospace", 35) # initialize system font

    while not game_over:                       # play until game_over == True
        for event in pyg.event.get():          # loop through events in queue
            if event.type == pyg.KEYDOWN:      # checks for key press
                x = player_pos[0]              # assign current x position
                y = player_pos[1]              # assign current y position
                if event.key == pyg.K_LEFT:    # checks if left arrow;
                    x -= player_dim            # if true, moves player left
                elif event.key == pyg.K_RIGHT: # checks if right arrow;
                    x += player_dim            # else moves player right
                player_pos = [x, y]            # reset player position
            
        screen.fill(background)                # refresh screen bg color
        drop_meteors(met_list, met_dim, width, score) # read PA prompt
        speed = set_speed(score)               # read PA prompt
        score = update_meteor_positions(met_list, height, score, speed)
                                               # read PA prompt
        text = "Score: " + str(score)              # create score text
        label = my_font.render(text, 1, yellow)    # render text into label
        screen.blit(label, (width-250, height-40)) # blit label to screen at
                                                   # given position; for our 
                                                   # purposes, just think of
                                                   # blit to mean draw
        draw_meteors(met_list, met_dim, screen, yellow) # self-explanatory;
                                                        # read PA prompt

        pyg.draw.rect(screen, red, (player_pos[0], player_pos[1], player_dim, player_dim))                                        # draw player

        if collision_check(met_list, player_pos, player_dim, met_dim):
            game_over = True                       # read PA prompt
    
        clock.tick(30)                             # set frame rate to control
                                                   # frames per second (~30); 
                                                   # slows down game

        pyg.display.update()                       # update screen characters
    # Outside while-loop now.
    print('Final score:', score)                   # final score
    pyg.quit()                                     # leave pygame

main()
