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
    int line_num = 0;

    char* char_name_buffer;
    char* char_message_buffer; 

    if (script == NULL) {
        printf("Script is missing yo.\n");
        return 1;
    }
    printf("%s%s", white_fg, black_bg);

    do {

    } while ();


    fclose(script);
    return 1;
}

int move(int direction, int distance) {
    
    return 0;
}

int talk(char* name, char* message) {
    printf(bold);
    printf("%s%s: ", bold, name);
    printf("%s%s%s\n", reset_txt , blue_fg, message);
    return 0;
}
