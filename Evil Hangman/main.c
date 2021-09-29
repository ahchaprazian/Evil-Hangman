#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "g_vector.h"
#include "associative_array.h"
#include "game.h"



int main(int argc, char *argv[])
{
		G_VECTOR g_arr[30] = {0};
		FILE* fp = NULL;
		MY_STRING hMy_string;
		Status status = SUCCESS;
		int i = 0;
		int word_length;
		int num_of_guesses;
		char p;

		fp = fopen("dictionary.txt", "r");
		if(fp == NULL)
		{
				printf("couldnt open file\n");
				exit(1);
		}

		for(i = 0; i < 30; i++)
		{
				g_arr[i] = generic_verctor_init_default(my_string_assignment, my_string_destroy);
				if(g_arr[i] == NULL)
				{
						printf("failed to init at index %d\n", i);
						exit(1);
				}
		}

		hMy_string = my_string_init_default();
		string_init_validation(hMy_string);

		while(my_string_extraction(hMy_string, fp))
		{
				generic_vector_push_back(g_arr[my_string_get_size(hMy_string)], hMy_string);
		}
		
		my_string_destroy(&hMy_string);
		fclose(fp);

		do {
				word_length = get_word_length();
				status = get_running_score();
				num_of_guesses = get_num_of_guesses();

				play_game(g_arr[word_length], num_of_guesses, word_length, status);

				printf("\nWould you like to play again?(y/n)\n");
				scanf("%c", &p);
				p = tolower(p);

				while(p != 'y' && p != 'n')
				{
					printf("If you would like to play again please enter y for yes or n for no\n");
					scanf("%c", &p);
					clearKeyboardBuffer();
				}

		} while(p == 'y');

		for(i = 0; i < 30; i++)
		{
				generic_vector_destroy(&g_arr[i]);
		}
				
		return 0;
}
