#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_achapraz_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_achapraz_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_achapraz_get_size_on_init_c_string_returns_more_than_0(char* buffer, int length);
Status test_achapraz_get_capacity_on_init_c_string_returns_correct_value(char* buffer, int length);

Status test_achapraz_string_empty_is_empty(char* buffer, int length);
Status test_achapraz_string_empty_is_not_empty(char* buffer, int length);

Status test_achapraz_my_string_compare_returns_positive(char* buffer, int length);
Status test_achapraz_my_string_compare_returns_0(char* buffer, int length);
Status test_achapraz_my_string_compare_returns_negative(char* buffer, int length);

Status test_achapraz_string_push_back_does_push_back(char* buffer, int length);
Status test_achapraz_string_push_back_size_increases(char* buffer, int length);

Status test_achapraz_string_pop_back_does_pop(char* buffer, int length);
Status test_achapraz_string_pop_back_size_decreases(char* buffer, int length);

Status test_achapraz_string_at_returns_correct_index(char* buffer, int length);

Status test_achapraz_string_concat_combines_two_strings(char* buffer, int length);
Status test_achapraz_string_concat_resizes_after_combine(char* buffer, int length);

Status test_achapraz_string_extraction_pulls_from_file(char* buffer, int length);
Status test_achapraz_string_extraction_size_gets_bigger(char* buffer, int length);
Status test_achapraz_string_extraction_capacity_gets_bigger(char* buffer, int length);

Status test_achapraz_string_insertion_prints_out_file(char* buffer, int length);

Status test_achapraz_init_c_string_is_NULL_terminated(char* buffer, int length);
Status test_achapraz_c_str_returns_address_of_first_element(char* buffer, int length);

Status test_achapraz_string_destroy_makes_pointer_NULL(char* buffer, int length);
#endif
