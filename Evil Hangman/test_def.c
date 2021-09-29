#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);
																return FAILURE;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
																return SUCCESS;
								}
}


Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "my_string_get_size doesnt return 0", length);
																return FAILURE;
								}
								if(my_string_get_size(hString) == 0)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_get_size_on_init_default_returns_0\n", length);
																return SUCCESS;
								}
								else{
																return FAILURE;
								}
}

Status test_achapraz_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_get_capacity_on_init_returns_7\n" "my_string_get_capacity doesnt return 7", length);
																return FAILURE;
								}
								if(my_string_get_capacity(hString) == 7)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_get_capacity_on_init_refault_returns_7\n", length);
																return SUCCESS;
								}
								else{
																return FAILURE;
								}
}

Status test_achapraz_init_c_string_returns_nonNULL(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("hi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_init_c_string_returns_nonNULL\n" "my_string_init_c_string returns NULL", length);
																return FAILURE;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_init_c_string_returns_nonNULL\n", length);
																return SUCCESS;
								}
}


Status test_achapraz_get_size_on_init_c_string_returns_more_than_0(char* buffer, int length)
{

								MY_STRING hString = NULL;

								hString = my_string_init_c_string("hi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_get_size_on_init_c_string_returns_more_than_0\n" "my_string_get_size doesnt return more than 0", length);
																return FAILURE;
								}
								if(my_string_get_size(hString) > 0)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_get_size_on_init_c_string_returns_more_than_0\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_get_size_on_init_c_string_returns_more_than_0\n" "my_string_get_size doesnt return more than 0", length);
																return FAILURE;
								}
}

Status test_achapraz_get_capacity_on_init_c_string_returns_correct_value(char* buffer, int length)
{

								MY_STRING hString = NULL;

								hString = my_string_init_c_string("hi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_get_capacity_on_init_c_string_returns_7_or_more\n" "my_string_get_capacity doesnt return 7 or more", length);
																return FAILURE;
								}
								if(my_string_get_capacity(hString) == 3)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_get_capacity_on_init_default_returns_0\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_get_capacity_on_init_c_string_returns_7_or_more\n" "my_string_get_capacity doesnt return 7 or more", length);
																return FAILURE;
								}
}

Status test_achapraz_string_empty_is_empty(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz__string_empty_is_empty\n" "test_achapraz_string_empty is not empty", length);
																return FAILURE;
								}

								if(my_string_empty(hString) == TRUE)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_empty_is_empty\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz__string_empty_is_empty\n" "test_achapraz_string_empty is not empty", length);
																return FAILURE;
								}
}

Status test_achapraz_string_empty_is_not_empty(char* buffer, int length)
{

								MY_STRING hString = NULL;

								hString = my_string_init_c_string("hi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz__string_empty_is_not_empty\n" "test_achapraz_string_not_empty is empty", length);
																return FAILURE;
								}

								if(my_string_empty(hString) == FALSE)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_empty_is_not_empty\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz__string_empty_is_not_empty\n" "test_achapraz_string_empty is empty", length);
																return FAILURE;
								}
}


Status test_achapraz_my_string_compare_returns_positive(char* buffer, int length)
{
								MY_STRING hString = NULL;
								MY_STRING hString2 = NULL;

								hString = my_string_init_c_string("I taste pie");
								hString2 = my_string_init_c_string("banana");
								if(hString == NULL || hString2 == NULL)
								{
																strncpy(buffer, "test_achapraz_my_string_compare_returns_positive\n" "test_achapraz_string_compare failed to init", length);
																return FAILURE;
								}

								if(my_string_compare(hString, hString2) > 0)
								{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "\ttest_achapraz_my_string_compare_returns_positive\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "test_achapraz_my_string_compare_returns_positive\n" "test_achapraz_string_compare is not positive", length);
																return FAILURE;
								}
}

Status test_achapraz_my_string_compare_returns_0(char* buffer, int length)
{
								MY_STRING hString = NULL;
								MY_STRING hString2 = NULL;

								hString = my_string_init_c_string("cool beans");
								hString2 = my_string_init_c_string("cool beans");
								if(hString == NULL || hString2 == NULL)
								{
																strncpy(buffer, "test_achapraz_my_string_compare_returns_0\n" "test_achapraz_string_compare failed to init", length);
																return FAILURE;
								}

								if(my_string_compare(hString, hString2) == 0)
								{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "\ttest_achapraz_my_string_compare_returns_0\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "test_achapraz_my_string_compare_returns_0\n" "test_achapraz_string_compare is not 0", length);
																return FAILURE;
								}
}

Status test_achapraz_my_string_compare_returns_negative(char* buffer, int length)
{
								MY_STRING hString = NULL;
								MY_STRING hString2 = NULL;

								hString = my_string_init_c_string("karate kid");
								hString2 = my_string_init_c_string("chocolate tastes pretty fancy");
								if(hString == NULL || hString2 == NULL)
								{
																strncpy(buffer, "test_achapraz_my_string_compare_returns_negative\n" "test_achapraz_string_compare failed to init", length);
																return FAILURE;
								}

								if(my_string_compare(hString, hString2) < 0)
								{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "\ttest_achapraz_my_string_compare_returns_negative\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "test_achapraz_my_string_compare_returns_negative\n" "test_achapraz_string_compare is not negative", length);
																return FAILURE;
								}

}

Status test_achapraz_string_push_back_does_push_back(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("Bananas");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_push_back_does_push_back\n" "string_push_back failed to init", length);
																return FAILURE;
								}

								if(my_string_push_back(hString, 'f') == SUCCESS)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_push_back_does_push_back\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_string_push_back_does_push_back\n" "string_push_back does not pushback", length);
																return FAILURE;
								}
}

Status test_achapraz_string_push_back_size_increases(char* buffer, int length)
{
								MY_STRING hString = NULL;
								int size;

								hString = my_string_init_c_string("Chocolate");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_push_back_size_inceases\n" "push back size increase failed to init", length);
																return FAILURE;
								}

								size = my_string_get_size(hString);
								my_string_push_back(hString, 'f');

								if(my_string_get_size(hString) == (size + 1))
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_push_back_size_increases\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_string_push_back_size_increases\n" "push_back_size_increase did not increase in size", length);
																return FAILURE;
								}

}

Status test_achapraz_string_pop_back_does_pop(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("Cheese");
								if(hString == NULL)
								{
																strncpy(buffer, "test_string_pop_back_does_pop_back\n" "string_pop_back failed to init", length);
																return FAILURE;
								}

								if(my_string_pop_back(hString) == SUCCESS)
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_pop_back_does_pop_back\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_string_pop_back_does_pop_back\n" "test_string_deos_pop_back does not pop back", length);
																return FAILURE;
								}
}

Status test_achapraz_string_pop_back_size_decreases(char* buffer, int length)
{
								MY_STRING hString = NULL;
								int size;

								hString = my_string_init_c_string("Cheese");
								if(hString == NULL)
								{
																strncpy(buffer, "test_string_pop_size_decreases\n" "string_pop_back_size_decreases failed to init", length);
																return FAILURE;
								}

								size = my_string_get_size(hString);
								my_string_pop_back(hString);

								if(my_string_get_size(hString) == (size - 1))
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_pop_back_size_decreases\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_string_pop_back_size_decreases\n" "string_pop_back_size does not decrease", length);
																return FAILURE;
								}
}

Status test_achapraz_string_at_returns_correct_index(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("abcdefghijklmnopqrstuvwxyz");
								if(hString == NULL)
								{
																strncpy(buffer, "test_string_At_returns_correct_index\n" "test_strin_at_returns_correct_index fails to init", length);
																return FAILURE;
								}

								if(*my_string_at(hString, 6) == 'g')
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_string_at_returns_correct_index\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_string_at_returns_correct_index\n" "string_at does not return correct index", length);
																return FAILURE;
								}

}

Status test_achapraz_string_concat_combines_two_strings(char* buffer, int length)
{
								MY_STRING hString = NULL;
								MY_STRING hString2 = NULL;

								hString = my_string_init_c_string("Hello");
								hString2 = my_string_init_c_string("World!");
								if(hString == NULL || hString2 == NULL)
								{
																strncpy(buffer,"test_achapraz_string_concat_combines_two_strings\n" "concat_combines_two_strings failed to init", length);
																return FAILURE;
								}

								if(my_string_concat(hString, hString2) == SUCCESS)
								{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "\ttest_achapraz_string_concat_combines_two_strings\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "test_achapraz_string_concat_comvines_two_strings\n" "concat_combines_two_strings does not combine the strings", length);
																return FAILURE;
								}
}

Status test_achapraz_string_concat_resizes_after_combine(char* buffer, int length)
{
								MY_STRING hString = NULL;
								MY_STRING hString2 = NULL;
								int size;

								hString = my_string_init_c_string("Hello");
								hString2 = my_string_init_c_string("World!");
								if(hString == NULL || hString2 == NULL)
								{
																strncpy(buffer,"test_achapraz_string_concat_resizes_after_combine\n" "concat_resizes failed to init", length);
																return FAILURE;
								}

								size = my_string_get_size(hString);
								my_string_concat(hString, hString2);

								if(my_string_get_size(hString) != size)
								{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer, "\ttest_achapraz_string_concat_resizes_after_combine\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																my_string_destroy(&hString2);
																strncpy(buffer,"test_achapraz_string_concat_resizes_after_combine\n" "concat_resizes doesnt resize", length);
																return FAILURE;
								}
}

Status test_achapraz_string_extraction_pulls_from_file(char* buffer, int length)
{
								MY_STRING hString = NULL;
								FILE* fp;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_pulls_from_file\n" "extraction_pulls failed to init", length);
																return FAILURE;
								}
								fp = fopen("dictionary.txt", "r");
								if(fp == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_pulls_from_file\n" "extraction_pulls file failed to open", length);
																return FAILURE;
								}

								while(my_string_extraction(hString, fp))
								{
																if(my_string_get_size(hString) == 29)
																{
																								my_string_destroy(&hString);
																								fclose(fp);
																								strncpy(buffer, "\ttest_achapraz_string_extraction_pulls_from_file\n", length);
																								return SUCCESS;
																}
								}

								my_string_destroy(&hString);
								fclose(fp);
								strncpy(buffer, "test_achapraz_string_extraction_pulls_from_file\n" "extraction_pulls doesnt pull from file", length);
								return FAILURE;

}

Status test_achapraz_string_extraction_size_gets_bigger(char* buffer, int length)
{
								MY_STRING hString = NULL;
								FILE* fp;
								int size;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_size_gets_bigger\n" "extraction_size failed to init", length);
																return FAILURE;
								}
								fp = fopen("dictionary.txt", "r");
								if(fp == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_size_gets_bigger\n" "extraction_size file failed to open", length);
																return FAILURE;
								}

								size = my_string_get_size(hString);

								while(my_string_extraction(hString, fp))
								{
																if(my_string_get_size(hString) != size)
																{
																								my_string_destroy(&hString);
																								fclose(fp);
																								strncpy(buffer, "\ttest_achapraz_string_extraction_size_gets_bigger\n", length);
																								return SUCCESS;
																}
								}

								my_string_destroy(&hString);
								fclose(fp);
								strncpy(buffer, "test_achapraz_string_extraction_size_gets_bigger\n" "string_extraction_size does not change", length);
								return FAILURE;
}

Status test_achapraz_string_extraction_capacity_gets_bigger(char* buffer, int length)
{
								MY_STRING hString = NULL;
								FILE* fp;
								int capacity;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_capacity_gets_bigger\n" "extraction_capacity failed to init", length);
																return FAILURE;
								}
								fp = fopen("dictionary.txt", "r");
								if(fp == NULL)
								{
																strncpy(buffer, "test_achapraz_string_extraction_capacity_gets_bigger\n" "extraction_capacity file failed to open", length);
																return FAILURE;
								}

								capacity = my_string_get_capacity(hString);

								while(my_string_extraction(hString, fp))
								{
																if(my_string_get_capacity(hString) != capacity)
																{
																								my_string_destroy(&hString);
																								fclose(fp);
																								strncpy(buffer, "\ttest_achapraz_string_extraction_capacity_gets_bigger\n", length);
																								return SUCCESS;
																}
								}

								my_string_destroy(&hString);
								fclose(fp);
								strncpy(buffer, "test_achapraz_string_extraction_capacity_gets_bigger\n" "string_extraction_capacity does not change", length);
								return FAILURE;
}

Status test_achapraz_string_insertion_prints_out_file(char* buffer, int length)
{
								MY_STRING hString;

								hString = my_string_init_c_string("Hello There, General Kenobi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_insertion_prints_out\n" "insetion_prints_out doesnt print anything out", length);
																return FAILURE;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer,"\ttest_achapraz_string_insertion_prints_out_file\n", length);
																return SUCCESS;
								}

}


Status test_achapraz_init_c_string_is_NULL_terminated(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("hi");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_c_str_is_NULL_terminated\n" "c_str_is failed to init", length);
																return FAILURE;
								}

								my_string_push_back(hString, '\0');
								if(*my_string_at(hString, my_string_get_size(hString) - 1))
								{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_c_str_is_NULL_terminated\n" "c_str_is_NULL is not NULL terminated", length);
																return FAILURE;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_c_str_is_NULL_terminated\n", length);
																return SUCCESS;
								}
}

Status test_achapraz_c_str_returns_address_of_first_element(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_c_string("abcdefghijklmnopqrstuvwxyz");
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_c_str_returns_address_of_first_element" "c_str_returns_address failed to init", length);
																return FAILURE;
								}

								if(*my_string_c_str(hString) == 'a')
								{
																my_string_destroy(&hString);
																strncpy(buffer, "\ttest_achapraz_c_str_returns_address_of_first_element\n", length);
																return SUCCESS;
								}
								else{
																my_string_destroy(&hString);
																strncpy(buffer, "test_achapraz_c_str_returns_address_of_first_elemen\n" "c_str_returns_address does not return address", length);
																return FAILURE;
								}
}

Status test_achapraz_string_destroy_makes_pointer_NULL(char* buffer, int length)
{
								MY_STRING hString = NULL;

								hString = my_string_init_default();
								if(hString == NULL)
								{
																strncpy(buffer, "test_achapraz_string_destroy_makes_pointer_NULL\n" "test_string_destroy doesnt init", length);
																return FAILURE;
								}

								my_string_destroy(&hString);
								if(hString == NULL)
								{
																strncpy(buffer, "\ttest_achapraz_string_destroy_makes_pointer_NULL\n", length);
																return SUCCESS;
								}
								else{
																strncpy(buffer, "test_achapraz_string_destroy_makes_pointer_NULL\n" "test_string_destroy doesnt destroy", length);
																return FAILURE;
								}
}
