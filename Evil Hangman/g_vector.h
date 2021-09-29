#ifndef G_VECTOR_H
#define G_VECTOR_H

#include "status.h"
#include "generic.h"

typedef void* G_VECTOR;

G_VECTOR generic_verctor_init_default(Status(*item_assignment)(Item* pLeft, Item right), void(*item_destroy)(Item* phItem));

Status generic_vector_push_back(G_VECTOR hVector, Item value);

int generic_vector_get_size(G_VECTOR hVector);

int generic_vector_get_capacity(G_VECTOR hVector);

Item generic_vector_at(G_VECTOR hVector, int index);

Status generic_vector_pop_back(G_VECTOR hVector);

Boolean generic_vector_empty(G_VECTOR hVector);

void generic_vector_destroy(G_VECTOR* phVector);

#endif
