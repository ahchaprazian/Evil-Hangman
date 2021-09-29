#include <stdio.h>
#include <stdlib.h>
#include "g_vector.h"

struct g_vector
{
				int size;
				int capacity;
				Item* data;
				void (*item_destroy)(Item* phItem);
				Status (*item_assignment)(Item* pLeft, Item right);
};
typedef struct g_vector G_Vector;


G_VECTOR generic_verctor_init_default(Status (*item_assignment)(Item* pLeft, Item right), void (*item_destroy)(Item* phItem))
{
				int i;
				G_Vector* pVector = (G_Vector*)malloc(sizeof(G_Vector));

				if (pVector != NULL)
				{
								pVector->size = 0;
								pVector->capacity = 1;
								pVector->data = (Item*)malloc(sizeof(Item) * pVector->capacity);
								if (pVector->data == NULL)
								{
												free(pVector);
												return NULL;
								}

								for (i = 0; i < pVector->capacity; i++)
								{
												pVector->data[i] = NULL;
								}

								pVector->item_assignment = item_assignment;
								pVector->item_destroy = item_destroy;
				}

				return (G_VECTOR)pVector;
}

Status generic_vector_push_back(G_VECTOR hVector, Item value)
{
				G_Vector* pVector = (G_Vector*)hVector;
				Item* temp;
				int i;

				if (pVector->size >= pVector->capacity)
				{
								temp = (Item*)malloc(sizeof(Item) * pVector->capacity * 2);
								if (temp == NULL)
								{
												return FAILURE;
								}

								for (i = 0; i < pVector->size; i++)
								{
												temp[i] = pVector->data[i];
								}

								pVector->capacity *= 2;
								for (; i<pVector->capacity; i++)
								{
												temp[i] = NULL;
								}
								free(pVector->data);
								pVector->data = temp;
				}

				pVector->item_assignment(&(pVector->data[pVector->size]), value);
				pVector->size++;
				return SUCCESS;
}

int generic_vector_get_size(G_VECTOR hVector)
{
				G_Vector* pVector = (G_Vector*)hVector;

				return pVector->size;
}

int generic_vector_get_capacity(G_VECTOR hVector)
{
				G_Vector* pVector = (G_Vector*)hVector;

				return pVector->capacity;
}

Item generic_vector_at(G_VECTOR hVector, int index)
{
				G_Vector* pVector = (G_Vector*)hVector;

				if (index < 0 || index >= pVector->size)
				{
								return NULL;
				}

				return (pVector->data[index]);
}

Status generic_vector_pop_back(G_VECTOR hVector)
{
				G_Vector* pVector = (G_Vector*)hVector;

				if (generic_vector_empty(hVector))
				{
								return FAILURE;
				}

				pVector->item_destroy(&(pVector->data[pVector->size - 1]));
				pVector->size--;
				return SUCCESS;
}

Boolean generic_vector_empty(G_VECTOR hVector)
{
				G_Vector* pVector = (G_Vector*)hVector;

				if (pVector->size <= 0)
				{
								return TRUE;
				}

				return FALSE;
}

void generic_vector_destroy(G_VECTOR* phVector)
{
				G_Vector* pVector = (G_Vector*)*phVector;
				int i;

				if(pVector == NULL)
				{
					return;
				}

				for (i = 0; i < pVector->size; i++)
				{
								pVector->item_destroy(&(pVector->data[i]));
				}

				free(pVector->data);
				free(pVector);
				*phVector = NULL;
}