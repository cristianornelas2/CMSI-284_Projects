//
//  main.c
//  chord
//
//  Created by Cristian Ornelas on 4/9/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_SUBSTRING 15
#define INVALID -1
#include "notes.h"

// ***** Feel free to add more functions if you think they will make it easier to implement this program.
int note_and_chord(char* string, char* note, char* chord) {
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

int get_chord_index(char* string) {
        int isEqual;

        for(int i=0;i<CHORD_COUNT;i++){
                isEqual = strcmp(CHORD_SUFFIXES[i], string);
                if(isEqual == 0 ){
                        return i;
                }
        }

    return INVALID;
}

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
    char note[MAX_SUBSTRING];
    char chord[MAX_SUBSTRING];
    
            int ret = note_and_chord(input, note, chord);
            if ( ret == INVALID){
             printf("%s is not a valid chord.\n", input);
            } else {
                printf("%s%s: ", note, chord); // Cm7
                printf("%s ", note); // C
                int chord_index = get_chord_index(chord);
                int note_index = get_note_index(note);
                for (int i = 0; i < CHORD_STEP_COUNT[chord_index] ; i++) {
                                   int result = note_index + CHORD_STEPS[chord_index][i];
                                   int next_index = result % NOTE_COUNT;
                                   printf("%s ",NOTES[next_index]);// Cm7: C Eb G Bb
                                   note_index = next_index;
                               }
                puts("");
            }
    
        return 0;
}
