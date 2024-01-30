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

// ***** IMPLEMENT ME! *****
// ***** Feel free to add more functions if you think they will make it easier to implement split_note_and_chord.
int split_note_and_chord(char* string, char* note, char* chord) {
        int i,j;
        char hybrid_word[MAX_SUBSTRING];
        int isEqual;

        for(i = 0;i < NOTE_COUNT;i++){
            for(j = 0;j < CHORD_COUNT;j++){

                strcpy(hybrid_word,NOTES[i]);
                strcat(hybrid_word, CHORD_SUFFIXES[j]);

                isEqual = strcmp(string , hybrid_word);
                if(isEqual == 0){
                    strcpy(note, NOTES[i]);
                    strcpy(chord,CHORD_SUFFIXES[j]);
                    return 0;
                }
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
