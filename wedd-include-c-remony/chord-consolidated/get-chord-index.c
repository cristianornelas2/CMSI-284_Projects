//
//  main.c
//  get-chord-index
//
//  Created by Cristian Ornelas on 4/8/20.
//  Copyright © 2020 Cristian Ornelas. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "notes.h"

#define INVALID -1

int main(int argc, char** argv) {
    if(argc != 2){
        printf("This program requires exactly one command line argument.\n");
        return 1;
     }

    char *input = argv[1];
    int ret = get_chord_index(input);

    if ( ret == INVALID){
         printf("%s is not a valid chord.\n", input);
    }else{
         printf("%s is at CHORD_SUFFIXES index %d.\n", input, ret);
    }
    return 0;
}

