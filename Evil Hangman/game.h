#ifndef GAME_H
#define GAME_H

#include "my_string.h"
#include "g_vector.h"
#include "associative_array.h"

void clearKeyboardBuffer(void);
void string_init_validation(MY_STRING string_object);

int get_word_length(void);
Boolean get_running_score();
int get_num_of_guesses(void);

void play_game(G_VECTOR g_arr, int num_of_guesses, int word_length, Boolean status);
void play_game_helper(int size_of_word, int num_of_guess, G_VECTOR g_arr[]);

void display_game_content(int num_of_guesses, MY_STRING guessed_letters, MY_STRING current_word_family);
void print_guessed_letters(MY_STRING guessed_letters);

void guess_and_check(char* guess, MY_STRING guessed_letters);
Boolean guess_validation(char guess, MY_STRING guessed_letters);

Boolean check_if_player_won(MY_STRING current_word_family, int word_length);

#endif
