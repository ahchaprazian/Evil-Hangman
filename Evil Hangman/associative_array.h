#ifndef ASSOCIATIVE_ARRAY_H
#define ASSOCIATIVE_ARRAY_H

#include "my_string.h"
#include "g_vector.h"

typedef void* AVL_TREE;

typedef struct node Node;
struct node
{
        int height;
        Node* left;
        Node* right;
        MY_STRING key;
        G_VECTOR words;
};

struct avl_tree
{
        Node* root;
};
typedef struct avl_tree Avl_Tree;

int get_height(Node* node);
int get_balance_factor(Node* root);
int max_tree_height(int l_height, int r_height);

G_VECTOR find_largest_word_family(AVL_TREE hTree);
void find_largest_word_family_helper(Node* root, Node** temp, int* largest);
void game_list_swap(G_VECTOR* master_list, G_VECTOR* vector);

void print_avl_possibilities(AVL_TREE hTree);
void print_avl_possibilities_helper(Node* node);

AVL_TREE avl_tree_init_default(void);

Status avl_tree_insert(AVL_TREE hTree, MY_STRING key, MY_STRING word);
Status avl_tree_insert_helper(Node** root, MY_STRING key, MY_STRING word);

Node* rotate_left(Node* node);
Node* rotate_right(Node* node);

void node_destroyer(Node* root_node);
void avl_tree_destroy(AVL_TREE* phTree);
#endif