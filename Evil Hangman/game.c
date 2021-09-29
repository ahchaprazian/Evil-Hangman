#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "game.h"
//#include "g_vector.h"


void clearKeyboardBuffer(void)
{
        char ch;
        scanf("%c", &ch);

        while (ch != '\n') {
                scanf("%c", &ch);
        }
}

//made to simplfy the code while checking to see if the string is not null
void string_init_validation(MY_STRING string_object)
{
        if(string_object == NULL)
        {
                printf("couldnt init the string object\n");
                exit(1);
        }
}

int get_word_length(void)
{
        int size_of_word;
       
        printf("What is the word length you want to play with\n");
        scanf("%d", &size_of_word);
        clearKeyboardBuffer();

        while(size_of_word < 1 || size_of_word > 30 || size_of_word == 23 || size_of_word == 25 || size_of_word == 26 || size_of_word == 27)
        {
                printf("That is an invalid word length.(Try from 2-22, 24, 28-29)\n");
                scanf("%d", &size_of_word);
                clearKeyboardBuffer();
        }

        return size_of_word;
}
Boolean get_running_score()
{
        Boolean status;
        char c;

        printf("Do you want a running total? (y/n)\n");
        scanf("%c", &c);
        clearKeyboardBuffer();

        while(c != 'y' && c != 'Y' && c != 'n' && c != 'N')
        {
                printf("Please enter either y or n\n");
                scanf("%c", &c);
                clearKeyboardBuffer();
        }

        if(c == 'y' || c == 'Y')
        {
                status = TRUE;
        }
        else if(c == 'n' || c ==  'N')
        {
                status = FALSE;
        }

        return status;
}
int get_num_of_guesses(void)
{
        int n;//number of guesses
        

        printf("How many guesses would you like to have?\n");
        scanf("%d", &n);
        clearKeyboardBuffer();

        while(n <= 0)
        {
                printf("Enter a number greater than 0\n");
                scanf("%d", &n);
                clearKeyboardBuffer();
        }

        return n;
}

//used to get some initial inputs starting with the ssize of the word we will use in the dictionary and seperating it into a master word list
//the input is validated for specific lengths cause the dictionary goes up to 29 characters but doesnt have a 26 character word
//then we get the number of guesses the player wants to have and validate that it is an integer above zero then the play game helper is called
void play_game(G_VECTOR g_arr, int num_of_guesses, int word_length, Boolean status)
{
        MY_STRING current_word_family = NULL;
        MY_STRING new_key = NULL;
        MY_STRING word = NULL;
        MY_STRING guessed_letters = NULL;
        AVL_TREE game_tree = NULL;
        G_VECTOR master_word_list = NULL;
        char guess;
        int sizeof_master_list;
        int random;
        int i;
        Boolean correct = FALSE;
        Boolean is_gamer_winning = FALSE;

        master_word_list = generic_verctor_init_default(my_string_assignment, my_string_destroy);
        if(master_word_list == NULL)
        {
                printf("Failed to init master_word_list\n");
                exit(1);
        }

        for(i = 0; i < generic_vector_get_size(g_arr); i++)
        {
                if(!generic_vector_push_back(master_word_list, generic_vector_at(g_arr, i)))
                {
                        printf("Failed to push back into master word list\n");
                        exit(1);
                }
        }

        guessed_letters = my_string_init_default();
        string_init_validation(guessed_letters);

        current_word_family = my_string_init_default();
        string_init_validation(current_word_family);

        for(i = 0; i < word_length; i++)
        {//this is here for display purposes when showing letters that have been guessed
                my_string_push_back(current_word_family, '-');
        }

        while(num_of_guesses != 0 && is_gamer_winning == FALSE)
        {//this loop keeps going until you have reached zero guesses or if the game has been won
                sizeof_master_list = generic_vector_get_size(master_word_list);
                
                display_game_content(num_of_guesses, guessed_letters, current_word_family);

                guess_and_check(&guess, guessed_letters);

                game_tree = avl_tree_init_default();
                if(game_tree == NULL)
                {
                        printf("The tree failed to init\n");
                        exit(1);
                }

                new_key = my_string_init_default();
                string_init_validation(new_key);

                for(i = 0; i < sizeof_master_list; i++)
                {//this updates the word mystring with each word inside of the master word list so the key can be put into the tree
                        word = generic_vector_at(master_word_list, i);
                        get_word_key_value(current_word_family, new_key, word, guess);

                        if(!avl_tree_insert(game_tree, new_key, word))
                        {//this makes sure nothing fails while inputting into the tree if it does the entire game breaks and we dont want that
                                printf("Failed to insert into the tree.");
                                exit(1);
                        }
                }
                my_string_destroy(&new_key);

                if(status == TRUE)
                {
                        print_avl_possibilities(game_tree);
                }
                
                generic_vector_destroy(&master_word_list);

                game_list_swap(&master_word_list, find_largest_word_family(game_tree));

                sizeof_master_list = generic_vector_get_size(master_word_list);
                avl_tree_destroy(&game_tree);

                if(status == TRUE)
                {
                        printf("\nThe computer has %d possibilities remaining\n\n", sizeof_master_list);
                }
                
                srand(time(0));
                random = rand() % sizeof_master_list;

                new_key = my_string_init_default();
                word = generic_vector_at(master_word_list, random);
                get_word_key_value(current_word_family, new_key, word, guess);

                my_string_assignment(&current_word_family, new_key);
                my_string_destroy(&new_key);

                for(i = 0; i < word_length; i++)
                {
                        if(*my_string_at(current_word_family, i) == guess)
                        {
                                correct = TRUE;
                        }
                }

                if(correct == TRUE)
                {
                        printf("%c was the correct guess\n\n", guess);
                        correct = FALSE;
                }
                else
                {
                        printf("You guessed incorrectly there is no %c in the word\n\n", guess);
                        num_of_guesses--;
                }
                

                if(check_if_player_won(current_word_family, word_length) == FALSE)
                {
                        is_gamer_winning = TRUE;
                        printf("Congrats you have won the game!\n");
                        printf("The word was %s\n", my_string_c_str(word));
                        break;
                }
                else if(num_of_guesses == 0)
                {
                        printf("You lost. Better luck next time\n");
                        printf("The word was %s\n", my_string_c_str(word));
                        printf("The computer had %d possiblities left when you lost\n", sizeof_master_list);
                }
                
                
                clearKeyboardBuffer();
        }

        //we need to destroy everything so we can avoid forggeting the important things
        my_string_destroy(&current_word_family);
        my_string_destroy(&guessed_letters);
        generic_vector_destroy(&master_word_list);

}

void display_game_content(int num_of_guesses, MY_STRING guessed_letters, MY_STRING current_word_family)
{
        printf("You have %d guesses left.\n", num_of_guesses);
        printf("Used letters: ");

        print_guessed_letters(guessed_letters);

        printf("\nWord:");
        my_string_insertion(current_word_family, stdout);
}

//this function does literally what its named for. It just prints out all letters that have been used so the player knows what not to guess
void print_guessed_letters(MY_STRING guessed_letters)
{
        if(!my_string_empty(guessed_letters))
        {
                for(int i = 0; i < my_string_get_size(guessed_letters); i++)
                {
                        printf("%c, ", *my_string_at(guessed_letters, i));
                }
        }
}

void guess_and_check(char* guess, MY_STRING guessed_letters)
{
        printf("\nenter a guess: ");
        scanf("%c", guess);
        //clearKeyboardBuffer();
        *guess = tolower(*guess);//we will only deal with lowercase letters but if the player inputs a uppercase one we dont want to penalize them if its correct but the wrong size

        while(guess_validation(*guess, guessed_letters) == FALSE)
        {//a function to check wheather a letter has been guessed before or if it is a valid input
                //clearKeyboardBuffer();
                printf("You already used that or put in a non character value. Try again: ");
                scanf("%c", guess);
                clearKeyboardBuffer();
        }
        my_string_push_back(guessed_letters, *guess);
}

//condition is to return ture if the guess is valid (meaning no repeats or non char values and false if otherwise
//this goes through to check if all the letters that are currently being guess have not been used. It is checking to see if it is playable
//it comapres the guess with all the guessed letters list to see if there has been any repeatss and it also check to see if the guesses are in between
//and including a-z if not than it is not a letter and the player needs to be reprompted
Boolean guess_validation(char guess, MY_STRING guessed_letters)
{
        int i;
        for(i = 0; i < my_string_get_size(guessed_letters); i++)
        {
                if(guess == *my_string_at(guessed_letters, i))
                {
                        return FALSE;
                }
        }

        if(guess >= 'a' && guess <= 'z')
        {
                return TRUE;
        }
        else
        {
                return FALSE;
        }
}

Boolean check_if_player_won(MY_STRING current_word_family, int word_length)
{
        int i;
        
        for(i = 0; i < word_length; i++)
        {
                if(*my_string_at(current_word_family, i) == '-')
                {
                        return TRUE;
                }
        }

        return FALSE;
}