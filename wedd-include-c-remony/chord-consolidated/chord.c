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

int note_and_chord(char* string, char* note, char* chord);

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
                int note_index = get_note_index(note);
                int chord_index = get_chord_index(chord);
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
