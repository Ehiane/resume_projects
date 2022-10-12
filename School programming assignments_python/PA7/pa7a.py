# Ehiane Kelvin Oigiagbe.
# 16th October 2021.
# PA 7a
#encryption
# notes... 
import os
os.chdir('C:/Users/Ehiso/OneDrive/Desktop/WSU CLASSES/CPTS111/pa7')
os.getcwd()
from cipher import *


def main():
    '''
    A void function with no parameters,
    prompts the user for a password,
    a clear text file name (input)
    a cipher text file name (output)
    it calls gen_amp_seed(),
    then for every line in the input file
    it calls line2cipher() and prints resulting ciphered text to the output file.
    '''
    password_attempt = input('Enter password: ')
    new_file = open(input('Enter clear text (input) file name: '),'r')
    new_cipher_file = open(input('Enter cipher text(output) file name: '),'w')
    amp, seed = gen_amp_seed(password_attempt)   
    for line in new_file.readlines():
        amp , seed, cipher_line = line2cipher(amp, seed, line.strip())
        print(cipher_line, file =  new_cipher_file)
    print('Check cipher.txt for the result')  
    new_file.close()
    new_cipher_file.close()
        
        
        
main()    
