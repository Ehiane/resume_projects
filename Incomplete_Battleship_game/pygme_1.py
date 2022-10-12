#[ I stopped at 40:04 with tech with tim.]

#pygame tutorial. 
#pygame is a 2d python library that makes you create games.
import pygame 
import os 
#it's good convention to name your constant values with All caps.
WIDTH, HEIGHT = 900, 500
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("First Game!")
WHITE = (255,255,255)
BLACK = (0,0,0)
BORDER = pygame.Rect(WIDTH/2 - 5, 0, 10, HEIGHT)
FPS = 60 #FramesPerSecond.
VEL = 2.5
SPACESHIP_WIDTH, SPACESHIP_HEIGHT = 55, 40
YELLOW_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets', 'spaceship_yellow.png'))
YELLOW_SPACESHIP = pygame.transform.rotate (pygame.transform.scale(YELLOW_SPACESHIP_IMAGE, (SPACESHIP_WIDTH, SPACESHIP_HEIGHT)), 90)
RED_SPACESHIP_IMAGE = pygame.image.load(os.path.join('Assets', 'spaceship_red.png'))
RED_SPACESHIP = pygame.transform.rotate (pygame.transform.scale(RED_SPACESHIP_IMAGE, (SPACESHIP_WIDTH,SPACESHIP_HEIGHT)), 270)

def draw_window(red, yellow):
    WIN.fill(WHITE)
    pygame.draw.rect(WIN, BLACK, BORDER)
    WIN.blit(YELLOW_SPACESHIP, (yellow.x, yellow.y)) #the images or text are surfaces to the screen, so blit() joins them to the screen.
    WIN.blit(RED_SPACESHIP, (red.x, red.y))
    pygame.display.update() #pygame requirs you to update changes manually.

def yellow_handle_movement(keys_pressed, yellow):
    if keys_pressed[pygame.K_a] and yellow.x - VEL > 0: #left for WASD
        yellow.x -= VEL
    if keys_pressed[pygame.K_d] and yellow.x + VEL + yellow.width < BORDER.x: #right for WASD
        yellow.x += VEL
    if keys_pressed[pygame.K_w] and yellow.y - VEL > 0 : #up for WASD
        yellow.y -= VEL
    if keys_pressed[pygame.K_s] and yellow.y + VEL + yellow.height < HEIGHT - 15 : #down for WASD
        yellow.y += VEL

def red_handle_movement(keys_pressed, red):
    if keys_pressed[pygame.K_LEFT] and red.x - VEL > BORDER.x + BORDER.width: #left for WASD
        red.x -= VEL
    if keys_pressed[pygame.K_RIGHT] and red.x + VEL + red.width < WIDTH: #right for WASD
        red.x += VEL
    if keys_pressed[pygame.K_UP] and red.y - VEL > 0: #up for WASD
        red.y -= VEL
    if keys_pressed[pygame.K_DOWN]  and red.y + VEL + red.height < HEIGHT - 15 : #down for WASD
        red.y += VEL

def main():
    '''
    Void function that contains a while loop for every event
    in pygame.
    '''
    red = pygame.Rect(700, 300, SPACESHIP_WIDTH, SPACESHIP_HEIGHT) #space allowed for red spaceship to move
    yellow = pygame.Rect(100, 300, SPACESHIP_WIDTH, SPACESHIP_HEIGHT) #space allowed for yellow spaceship to move


    clock = pygame.time.Clock() #controls the speed of the while loop.
    run = True
    while run:
        clock.tick(FPS) #makes the game speed consistent on all computers.
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run == False
        keys_pressed = pygame.key.get_pressed()
        yellow_handle_movement(keys_pressed, yellow)
        red_handle_movement(keys_pressed, red)
        draw_window(red, yellow)
    pygame.quit()

if __name__ == '__main__':
    '''
    This is done to prevent this program from running when 
    not directly called or imported from another file.
    '''
    main()




