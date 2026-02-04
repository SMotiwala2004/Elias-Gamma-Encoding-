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
    // Input character data from input up to number of symbols provided 
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

    std::string bits;
    std::cin >> bits;

    // auto& allows me to refer each element and modify it directly
    int bitIndex = 0;

    for(auto& charInfo : charInfo) {
        // Assign start index for each seperate character
        charInfo.start_index = bitIndex;
        // Calculate end index for each character 
        for(int i = 0;  i < charInfo.frequency; i++) {
            // N is the number of leading zeros
            int N = 0;
            // Count number of leading zeros
            while(bits[bitIndex] == '0') {
                N++;
                bitIndex++;
            }
            // Move bitIndex to number of 0s + 1
            bitIndex += (N + 1);

        }

        charInfo.end_index = bitIndex - 1;
    }
    return 0;
    
}