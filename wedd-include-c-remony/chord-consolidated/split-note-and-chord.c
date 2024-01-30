//
//  main.c
//  split-note-and-chord
//
//  Created by Cristian Ornelas on 4/8/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "notes.h"

#define MAX_SUBSTRING 15
#define INVALID -1

    int main(int argc, char** argv) {
        if(argc != 2){
            printf("This program requires exactly one command line argument.\n");
        return 1;
         }

        char *input = argv[1];
        char note[MAX_SUBSTRING];
        char chord[MAX_SUBSTRING];

        int ret = split_note_and_chord(input, note, chord);
        
        if ( ret == INVALID){
             printf("%s is not a valid chord.\n", input);
        }else{
             printf("[%s] [%s]\n", note, chord);
        }

        return 0;
}
