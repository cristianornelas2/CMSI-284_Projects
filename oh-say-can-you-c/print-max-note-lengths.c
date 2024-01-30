//
//  main.c
//  print-max-note-lengths
//
//  Created by Cristian Ornelas on 4/8/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "notes.h"

// ***** IMPLEMENT ME! *****
int get_max_note_length() {
    int max_len=0;
    int curr_str_len;

    for(int i=0;i<NOTE_COUNT;i++){
        curr_str_len = strlen(NOTES[i]);
    
        if(max_len < curr_str_len){
            max_len = curr_str_len;
        }
    }
    return (max_len);
}

// ***** IMPLEMENT ME! *****
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

int main(int argc, char** argv) {
    // ***** Yes, now you get to implement this too. *****
     int note = get_max_note_length();
     int suff = get_max_chord_suffix_length();
    printf("The longest NOTES string is %d characters long and the longest CHORD_SUFFIXES string is %d characters long.\n", note, suff);
    return 0;
}

