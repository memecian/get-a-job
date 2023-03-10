#include <stdio.h>
#include <stdlib.h>
#include "maybe.h"
#include <SDL2/SDL_mixer.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define white_fg "\033[37m"
#define blue_fg "\033[34m"
#define black_bg "\033[40m"
#define bold "\033[1m"
#define italics "\033[3m"
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

    // init audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Error initializing SDL_mixer: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Music *music = Mix_LoadMUS("conversation.mp3");
    if (!music) {
        printf("Error loading music: %s\n", Mix_GetError());
        return 1;
    }

    Mix_PlayMusic(music, 1);
    printf("%sYou enter a bathroom in the UNATCO HQ. The door closes behind you.\n\n", italics);
    #ifdef _WIN32
    Sleep(10000);
    #else
    sleep(10);
    #endif
    
    printf("You walk up to the mirror and see a reflection of yourself.\n\n");
    #ifdef _WIN32
    Sleep(10000);
    #else
    sleep(10);
    #endif
    
    printf("You look at the reflection and admire your neat sunglasses,\n\nwhen suddenly it starts speaking to you...%s\n\n", reset_txt);
    #ifdef _WIN32
    Sleep(5000);
    #else
    sleep(5);
    #endif
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
            if (char_buf == EOF) goto end;
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
        #ifdef _WIN32
        Sleep(3000);
        #else
        sleep(3);
        #endif
end:
        free(name_buffer);
        free(message_buffer);
    } while (char_buf != EOF);

    // we're done here
    Mix_FadeOutMusic(3000);
    while (Mix_PlayingMusic()) {
        // Wait for music to finish
    }
    Mix_CloseAudio();
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
