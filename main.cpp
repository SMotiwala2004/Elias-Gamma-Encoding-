#include<iostream>
#include<vector>
#include<pthread.h>
#include<unistd.h>
#include<string>

/*
Original message: AACABDDADABC
Sorted By frequency, then lexicographically : A-5, D-4, B-2, C-2
Positions in encoded message: 1, 2, 4, 8, 10, 6, 7, 9, 5, 11, 3, 12
These positions are represented as Elias-Gamma Codes 

Input: 
4 -> Number of unique characters
A 5 -> Character A with frequency 5
C 2 -> Character C with frequency 2
B 2 -> Character B with frequency 2
D 3 -> Character D with frequency 4

10100010000010000001010001100011100010010010100010110110001100 
-> Encoded message in Elias-Gamma Codes

Position values for symbols in binary are in the same order as the characters provided above.
*/

struct charData {
    char symbol;
    int frequency;
    int start_index;
    int end_index;
};

std::vector<charData> charInfo;

int main() {
    int number_of_symbols;
    std::cin >> number_of_symbols;

    for (int i = 0; i < number_of_symbols; i++)
    {
        charData newChar;;
        char symbol;
        int frequency;
        std::cin >> symbol >> frequency;

        newChar.symbol = symbol;
        newChar.frequency = frequency;
        
        charInfo.push_back(newChar);
        std::cout << charInfo[i].symbol << " " << charInfo[i].frequency << std::endl;
    }
    return 0;
    
}