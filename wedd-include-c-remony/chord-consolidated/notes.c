//
//  main.c
//  notes
//
//  Created by Cristian Ornelas on 4/20/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define INVALID -1
#define MAX_SUBSTRING 15
// In case your implementation needs it. It does not have to.

#include "string-plus.h"
#include "notes.h"

char *NOTES[] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"};
int NOTE_COUNT = sizeof(NOTES) / sizeof(char*);

// C has more sophisticated ways to express these structures, but at our level we
// stay with multiple arrays that have coordinated index values (i.e., the same
// index on these arrays corresopnds to the same type of chord).
char *CHORD_SUFFIXES[] = {
    "",     // major
    "m",    // minor
    "7",    // dominant 7th
    "M7",   // major 7th
    "m7",   // minor 7th
    "dim7"  // diminished 7th
};

int CHORD_COUNT = sizeof(CHORD_SUFFIXES) / sizeof(char*);

// C needs to know the maximum size of the inner array, but not the outer one 🤷🏽‍♂️
int CHORD_STEPS[][3] = {
    {4, 3},     // major
    {3, 4},     // minor
    {4, 3, 3},  // dominant 7th
    {4, 3, 4},  // major 7th
    {3, 4, 3},  // minor 7th
    {3, 3, 3}   // diminished 7th
};

// Yes, there are ways of computing this dynamically but for now we choose to list
// them explicitly to show how these arrays correspond to each other.
int CHORD_STEP_COUNT[] = {
    2,  // major
    2,  // minor
    3,  // dominant 7th
    3,  // major 7th
    3,  // minor 7th
    3   // diminished 7th
};

// ***** MOVE YOUR IMPLEMENTATIONS HERE! *****
int get_max_note_length() {int max_len=0;
    int curr_str_len;

    for(int i=0;i<NOTE_COUNT;i++){
        curr_str_len = strlen(NOTES[i]);
    
        if(max_len < curr_str_len){
            max_len = curr_str_len;
        }
    }
    return (max_len);
}

int get_max_chord_suffix_length() {
    int max_len=0;
    int curr_str_len;

    for(int i=0;i<CHORD_COUNT;i++){
        curr_str_len = strlen(CHORD_SUFFIXES[i]);
        if(max_len < curr_str_len){
            max_len = curr_str_len;
        }
    }
     return (max_len);
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

void print_chord(int note_index, int chord_index) {
    printf("%s%s: ", NOTES[note_index], CHORD_SUFFIXES[chord_index]); // Cm7:
    printf("%s ", NOTES[note_index]);
    
    for (int i = 0; i < CHORD_STEP_COUNT[chord_index] ; i++) {
        int result = note_index + CHORD_STEPS[chord_index][i];
        int next_index = result % NOTE_COUNT;
        printf("%s ",NOTES[next_index]);// Cm7: C Eb G Bb
        note_index = next_index;
    }
    puts("");
}

