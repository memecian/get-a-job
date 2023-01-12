#include <stdio.h>
#include <stdlib.h>
#include "maybe.h"

#define white_fg "\033[37m"
#define blue_fg "\033[34m"
#define black_bg "\033[40m"
#define bold "\033[1m"
#define reset_txt "\033[0m\033[40m"
#define no_fmt "\033[0m"



int main(void) {
    FILE *script = fopen("SCRIPT.txt", "r");

    char* name_buffer;
    char* message_buffer; 
    char char_buf = 0;

    if (script == NULL) {
        printf("Script is missing yo.\n");
        return 1;
    }
    printf("%s%s", white_fg, black_bg);

    do {
        
        char_buf = fgetc(script);
        // separate character name from line
        for (int i = 0; char_buf != ' '; i++) {
            (name_buffer + i) = char_buf;
        }
        
        //here comes the line 
        for (int i = 0; char_buf != '\n'; i++) {
            (message_buffer + i) = char_buf;
        }

        talk(name_buffer, message_buffer);

    } while (char_buf != EOF);

    // we're done here
    fclose(script);
    return EXIT_SUCCESS;
}

int move(int direction, int distance) {
    // move cursor or something idk
    return 0;
}

int talk(char* name, char* message) {
    printf(bold);
    printf("%s%s: ", bold, name);
    printf("%s%s%s\n", reset_txt , blue_fg, message);
    return 0;
}
