#Ehiane Kelvin Oigiagbe


def find_legendary(data_file):
    '''
    A void function with a parameter that is the .csv file, 
    opened and read in main() using .readlines() . 
    Using .readlines() creates a list, making the type of output,
    for find_legendary() a list. Each element of the list a line
    on the file. This function is to identify all legendary pokemon,
    in the file. making column 11 true. If a lengendary attribute is 
    noticed. Print the number, name and generation. 
    '''
    #Table content#
    top_header = '{title:^43}'
    bottom_headers = '{l_title:<9}{m_title:^25}{r_title:>11}'
    print('-' * 45)
    print(top_header.format(title='Legendary Pokemon'))
    print('-' * 45)
    print(bottom_headers.format(l_title= 'Number',m_title='Name', r_title= 'Generation'))
    for line in range(len(data_file)): 
        listoflines = data_file[line].split(',')
        if listoflines[11] == 'TRUE': 
            print(bottom_headers.format(l_title= listoflines[0] ,m_title=listoflines[1], r_title= listoflines[10]))
#--------------------------------------------------------------------------------------------------------           
def find_strength(data_file): 
    '''
    A void function that takes the same list of data as the previous function. 
    This function determines the total strength for each Pokemon,
     in Generation 6.
    This is very similar to the previous function except you have to check
     if the pokemon is gen 6 and you need to add the int() of points from 
     col 4 - 9 and repressent '*' as 20 pts

    ''' 
    #table contents#
    top_header = '{title:^43}'
    bottom_headers = '{l_title:^24}{r_title:^21}'
    print('-' * 60)
    print(top_header.format(title='Pokemon Generation 6 Strength [* = 20 pts]'))
    print('-' * 60)
    #End of table contents#

    #for loop#
    for line in range(len(data_file)): 
        listoflines = data_file[line].split(',')
        if listoflines[10] == '6': 
            points_sum = int(listoflines[4])+ int(listoflines[5])+ int(listoflines[6])+ int(listoflines[7])+ int(listoflines[8])+ int(listoflines[9])  
            num_stars = points_sum // 20 
            star_print = ('*' * num_stars )
            print(bottom_headers.format(l_title=listoflines[1], r_title= star_print ))  
    print()    

    
def find_ability(data_file):
    top_header = '{title:^60}'
    bottom_headers = '{l_title:<6}{m_title:^13}{r_title:^33}'
    print('-' * 75)
    print(top_header.format(title='Pokemon Generation 1 Abilities'))
    print('-' * 75)
    print(bottom_headers.format(l_title= 'Number',m_title='Name', r_title= 'Abilities'))
    print('_' * 75)
    gen1list = []
    
    for i in range(len(data_file)): 
        line = data_file[i].rstrip().replace('[','').replace(']', '').replace("", '')
        line_list = line.split(',')
        if line_list[10] == '1': 
            gen1list.append(line_list)
            
    for j in range(len(gen1list)): 
        if "'Inner Focus'" in gen1list[j]:
            print('{:<9}{:<20}'.format(gen1list[j][0].replace("'", ""), gen1list[j][1]).replace("'", ""), end= ' ') 

            for k in range(len(gen1list[j])-13):  
                print(gen1list[j][k+12].replace("'", ""), end= ', ')
            print(gen1list[j][-1].replace("'", ""))

                 

def main(): 
    pokemon = open('pokemon_13.csv', 'r')
    pokemon = pokemon.readlines()
    # task1 = find_legendary(pokemon)
    # task2 = find_strength(pokemon)
    task3 = find_ability(pokemon)
    
main()


