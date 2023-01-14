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
    int name_done = 0;

    if (script == NULL) {
        printf("Script is missing yo.\n");
        return 1;
    }
    // fprintf(stderr, "Script loaded.\n");

    printf("%s%s", white_fg, black_bg);

    int i = 0;
    // fprintf(stderr, "Starting main loop.\n");
    do {
        name_buffer = malloc(20);
        message_buffer = malloc(256); 
        // separate character name from line
        //fprintf(stderr, "Reading character name.\n");
        for (i = 0; char_buf != ':'; i++) {
            char_buf = fgetc(script);
            *(name_buffer + i) = char_buf;
        }
        *(name_buffer + i++) = '\0';
        
        //here comes the line 
        //fprintf(stderr, "Reading message.\n");
        for (i = 0; char_buf != '\n'; i++) {
            char_buf = fgetc(script);
            *(message_buffer + i) = char_buf;
        }
        *(message_buffer + i++) = '\0';
        //fprintf(stderr, "Message read.\n");
        talk(name_buffer, message_buffer);
        free(name_buffer);
        free(message_buffer);
    } while (char_buf != EOF);

    // we're done here
    fclose(script);
    printf("%s", no_fmt);
    return EXIT_SUCCESS;
}

int move(int direction, int distance) {
    // move cursor or something idk
    return 0;
}

int talk(char* name, char* message) {;
    printf("%s%s%s", bold, white_fg, name);
    printf("%s%s%s\n", reset_txt , blue_fg, message);
    return 0;
}
