//
//  main.c
//  string-plus
//
//  Created by Cristian Ornelas on 4/20/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdbool.h>
#include <string.h>
// In case your implementation needs it. It does not have to.

// Helper function for determining if a string validly expresses a non-negative integer.
// Feel free to use where needed (and to study it as an example).
bool is_non_negative_numeral(char* numeral) {
    int numeral_length = strlen(numeral);
    for (int i = 0; i < numeral_length; i++) {
        if (numeral[i] < '0' || numeral[i] > '9') {
            return false;
        }
    }

    return true;
}

// ***** MOVE YOUR IMPLEMENTATION HERE! *****
void split_string_at_index(char* string, int index, char* left, char* right) {

    int length_of_string = strlen(string);
    int i;

    for(i = 0;i < length_of_string; i++){

            if(i < index){
                    left[i] = string[i];
            }else{
                    right[i-index] = string[i];
            }
    }
        
    left[index] = '\0';
    right[length_of_string-index] = '\0';
    return;
        
}
