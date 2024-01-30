//
//  main.c
//  get-note-index
//
//  Created by Cristian Ornelas on 4/8/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "notes.h"

#define INVALID -1

// ***** IMPLEMENT ME! *****
int get_note_index(char* string) {
        int isEqual;

        for(int i=0;i<NOTE_COUNT;i++){
                isEqual = strcmp(NOTES[i], string);
                if(isEqual == 0 ){
                        return i;
                }
        }

    return INVALID;
}

int main(int argc, char** argv) {
    if(argc != 2){
        printf("This program requires exactly one command line argument.\n");
        return 1;
     }

    char *input = argv[1];
    int ret = get_note_index(input);

    if ( ret == INVALID){
         printf("%s is not a valid note.\n", input);
    }else{
         printf("%s is at NOTES index %d.\n", input, ret);
    }
    return 0;
}

