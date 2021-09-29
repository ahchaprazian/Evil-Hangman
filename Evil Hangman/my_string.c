#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"
#include "associative_array.h"

struct my_string {
        int size;
        int capacity;
        char* data;
};
typedef struct my_string My_string;


MY_STRING my_string_init_default(void)
{
        My_string* pMy_string;
        pMy_string = (My_string*)malloc(sizeof(My_string));
        if(pMy_string != NULL)
        {
                pMy_string->size = 0;
                pMy_string->capacity = 7;
                pMy_string->data = (char*)(malloc(sizeof(char)*pMy_string->capacity));
                if(pMy_string->data == NULL)
                {
                        free(pMy_string);
                        pMy_string = NULL;
                }
        }
        return (MY_STRING)pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
        int i = 0;
        int count = 0;

        My_string* pMy_string;

        while(c_string[i] != '\0')
        {
                count++;
                i++;
        }

        count = strlen(c_string);

        pMy_string = (My_string*)malloc(sizeof(My_string));
        if(pMy_string != NULL)
        {
                pMy_string->size = count;
                pMy_string->capacity = count + 1;
                pMy_string->data = (char*)(malloc(sizeof(char)*pMy_string->capacity));
                if(pMy_string->data == NULL)
                {
                        free(pMy_string);
                        return NULL;
                }


                for(i = 0; i < pMy_string->size; i++)
                {
                        pMy_string->data[i] = c_string[i];
                }
                pMy_string->data[i] = '\0';
        }

        return (MY_STRING)pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
        My_string* pMy_string = (My_string*)hMy_string;
        return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
        My_string* pMy_string = (My_string*)hMy_string;
        return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
        My_string* pLeft_string = (My_string*)hLeft_string;
        My_string* pRight_string = (My_string*)hRight_string;
        int size;
        size = pLeft_string->size < pRight_string->size ? pLeft_string->size : pRight_string->size;

        for(int i = 0; i < size; i++)
        {
                if(pLeft_string->data[i] > pRight_string->data[i])
                {
                        return 1;
                }
                else if(pLeft_string->data[i] < pRight_string->data[i])
                {
                        return -1;
                }
        }

        if(size > pLeft_string->size)
        {
                return -1;
        }
        else if(size > pRight_string->size)
        {
                return 1;
        }

        return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
        My_string* pMy_string = (My_string*)hMy_string;
        char* temp;
        char ch = fgetc(fp);
        int count = 0;
        while(ch == ' ' || ch == '\n')
        {
                ch = fgetc(fp);
        }
        while(ch != EOF && ch != ' ' && ch != '\n')
        {
                if(pMy_string->size >= pMy_string->capacity)
                {
                        temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
                        if(temp == NULL)
                        {
                                return FAILURE;
                        }

                        for(int i = 0; i < pMy_string->size; i++)
                        {
                                temp[i] = pMy_string->data[i];
                        }

                        pMy_string->capacity *= 2;
                        free(pMy_string->data);
                        pMy_string->data = temp;
                }
                pMy_string->data[count] = ch;
                count++;
                pMy_string->size = count;
                ch=fgetc(fp);

        }
        if(ch == ' ' && count != 0)
        {
                ungetc(ch, fp);
                return SUCCESS;
        }
        if(count == 0)
        {
                return FAILURE;
        }
        return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
        My_string* pMy_string = (My_string*)hMy_string;
        int i = 0;
        while(i < pMy_string->size)
        {
                fprintf(fp,"%c", pMy_string->data[i]);
                i++;
        }
        if(i == pMy_string->size)
        {
                return SUCCESS;
        }

        else{
                return FAILURE;
        }
        return FAILURE;
}


Status my_string_push_back(MY_STRING hMy_string, char item)
{
        My_string* pMy_string = (My_string*)hMy_string;
        char* temp;
        int i;

        if(pMy_string->size >= pMy_string->capacity)
        {
                temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
                if(temp == NULL)
                {
                        return FAILURE;
                }

                for(i = 0; i < pMy_string->size; i++)
                {
                        temp[i] = pMy_string->data[i];
                }
                pMy_string->capacity *= 2;
                free(pMy_string->data);
                pMy_string->data = temp;
        }

        pMy_string->data[pMy_string->size] = item;
        pMy_string->size++;
        return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
        My_string* pMy_string = (My_string*)hMy_string;

        if(pMy_string->size == 0)
        {
                return FAILURE;
        }
        pMy_string->size--;
        return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
        My_string* pMy_string = (My_string*)hMy_string;

        if(index >= 0 && index < pMy_string->size)
        {
                return &(pMy_string->data[index]);
        }
        return NULL;
}

char* my_string_c_str(MY_STRING hMy_string)
{
        My_string* pMy_string = (My_string*)hMy_string;
        char* temp;
        int i;

        if(pMy_string->size <= 0)
        {
                return NULL;
        }

        if(pMy_string->size >= pMy_string->capacity)
        {
                temp = (char*)malloc(sizeof(char) *pMy_string->capacity + 1);

                if(temp == NULL)
                {
                        return NULL;
                }

                for(i = 0; i < pMy_string->size; i++)
                {
                        temp[i] = pMy_string->data[i];
                }

                pMy_string->capacity++;
                free(pMy_string->data);
                pMy_string->data = temp;
        }

        pMy_string->data[pMy_string->size] = '\0';

        return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
        My_string* pResult = (My_string*)hResult;
        My_string* pAppend = (My_string*)hAppend;
        int i;

        for(i=0; i < pAppend->size; i++)
        {
                if(my_string_push_back(pResult, *my_string_at(pAppend, i)) == FAILURE)
                {
                        return FAILURE;
                }
        }

        return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
        My_string* pMy_string = (My_string*)hMy_string;

        if(pMy_string->size <= 0)
        {
                return TRUE;
        }
        return FALSE;
}

Status my_string_assignment(Item* Left, Item Right)
{


        if(*Left == NULL)
        {
                *Left = my_string_init_c_string("i");
        }
        if(*Left != NULL)
        {
                if(my_string_empty(*Left))
                {
                        my_string_concat(*Left, Right);
                }
                else
                {
                        while(!my_string_empty(*Left))
                        {
                                my_string_pop_back(*Left);
                        }

                        my_string_concat(*Left, Right);
                }
        }

        return SUCCESS;
}

//Precondition:current_word_family, new_key and word are all handles to valid
// MY_STRING opaque objects. guess is an alphabetical character that can be either
// upper or lower case.
//Postcondition: Returns SUCCESS after replacing the string in new_key with the key
// value formed by considering the current word family, the word and the guess.
// Returns failure in the case of a resizing problem with the new_key string.
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
        My_string* pNew_key = (My_string*)new_key;
        My_string* pWord = (My_string*)word;
        int i;

        my_string_assignment(&new_key, current_word_family);

        for(i = 0; i < pWord->size; i++)
        {
                if(guess == pWord->data[i])
                {       
                        pNew_key->data[i] = guess;
                }   
        }

        return SUCCESS;
}

void my_string_destroy(Item* pItem)
{
        My_string* pMy_string = (My_string*)*pItem;
        free(pMy_string->data);
        free(pMy_string);
        *pItem = NULL;
}
