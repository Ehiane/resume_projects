# Ehiane Kelvin Oigiagbe.
# 16th October 2021.
# PA 7b
#decryption
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
    cipher_file = open(input('Enter cipher text (input) file name: '),'r')
    decipher_file = open(input('Enter decipher text(output) file name: '),'w')
    amplitude , seed = gen_amp_seed(password_attempt)
    for line in cipher_file.readlines():
        amp , seed, decipher_line = line2clear(amplitude, seed, line.strip())
        print(decipher_line, file =  decipher_file)
    print('Check cipher.txt for the result')  
    cipher_file.close()
    decipher_file.close()
        
        
        
main()    
