#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
								Status (*test[])(char*, int)=
								{
																test_init_default_returns_nonNULL,
																test_get_size_on_init_default_returns_0,
																test_achapraz_get_capacity_on_init_default_returns_7,
																test_achapraz_init_c_string_returns_nonNULL,
																test_achapraz_get_size_on_init_c_string_returns_more_than_0,
																test_achapraz_get_capacity_on_init_c_string_returns_correct_value,
																test_achapraz_my_string_compare_returns_positive,
																test_achapraz_my_string_compare_returns_0,
																test_achapraz_my_string_compare_returns_negative,
																test_achapraz_string_push_back_does_push_back,
																test_achapraz_string_push_back_size_increases,
																test_achapraz_string_pop_back_does_pop,
																test_achapraz_string_pop_back_size_decreases,
																test_achapraz_string_at_returns_correct_index,
																test_achapraz_string_concat_combines_two_strings,
																test_achapraz_string_concat_resizes_after_combine,
																test_achapraz_string_empty_is_empty,
																test_achapraz_string_empty_is_not_empty,
																test_achapraz_string_extraction_pulls_from_file,
																test_achapraz_string_extraction_size_gets_bigger,
																test_achapraz_string_extraction_capacity_gets_bigger,
																test_achapraz_string_insertion_prints_out_file,
																test_achapraz_init_c_string_is_NULL_terminated,
																test_achapraz_c_str_returns_address_of_first_element,
																test_achapraz_string_destroy_makes_pointer_NULL
								};

								int number_of_functions = sizeof(test) / sizeof(test[0]);
								int i;
								char buffer[500];
								int success_count = 0;
								int failure_count = 0;

								for(i = 0; i < number_of_functions; i++)
								{
																if(test[i](buffer, 500) == FAILURE)
																{
																								printf("FAILED: Test %d failed miserably\n", i);
																								printf("\t%s\n", buffer);
																								failure_count++;
																}
																else{
																								printf("PASS: Test %d passed\n", i);
																								printf("\t%s\n", buffer);
																								success_count++;
																}
								}

								printf("Total number of tests: %d\n", number_of_functions);
								printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);

								return 0;
}
