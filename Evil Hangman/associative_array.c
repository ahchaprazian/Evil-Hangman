#include <stdio.h>
#include <stdlib.h>
#include "associative_array.h"
#include "g_vector.h"

int get_height(Node* node)
{//checks to see if anything is null to see if any operation can happen otherwise it will just return the height of the tree that was passed in
        if(node == NULL)
        {
                return 0;
        }

        return node->height;
}

int get_balance_factor(Node* root)
{ //to get the balance factor we need the hight of each side of the tree and find the difference between them
        return (root == NULL) ? 0 : get_height(root->right) - get_height(root->left);
}

int max_tree_height(int l_height, int r_height)
{//comparison if the left height is bigger it will return left height otherwise it will return right height
        return (l_height > r_height) ? l_height : r_height;
}

G_VECTOR find_largest_word_family(AVL_TREE hTree)
{
        Avl_Tree* pTree = (Avl_Tree*)hTree;
        Node* temp = NULL;
        int largest = 0;

        if(pTree != NULL)
        {
                find_largest_word_family_helper(pTree->root, &temp, &largest);

                if(temp != NULL)
                {
                        return &(temp->words);
                }
        }
        
        return NULL;//if the tree is null you cant continue so better stop everything by returning null
}

void find_largest_word_family_helper(Node* root, Node** temp, int* largest)
{
        if(root != NULL)
        {
                find_largest_word_family_helper(root->left, temp, largest);

                if(generic_vector_get_size(root->words) > *largest)
                {
                        *largest = generic_vector_get_size(root->words);
                        *temp = root;
                }

                find_largest_word_family_helper(root->right, temp, largest);
        }
}

void game_list_swap(G_VECTOR* master_list, G_VECTOR* vector)
{
        G_VECTOR temp;

        temp = *master_list;
        *master_list = *vector;
        *vector = temp;
}


void print_avl_possibilities(AVL_TREE hTree)
{
        Avl_Tree* pTree = (Avl_Tree*)hTree;

        if(pTree != NULL)
        {
                print_avl_possibilities_helper(pTree->root);
        }
}

void print_avl_possibilities_helper(Node* node)
{
        if(node == NULL)
        {
                return;
        }

        print_avl_possibilities_helper(node->left);
        my_string_insertion(node->key, stdout);

        printf(" %d\n", generic_vector_get_size(node->words));

        print_avl_possibilities_helper(node->right);
}

AVL_TREE avl_tree_init_default(void)
{
        Avl_Tree* pTree = (Avl_Tree*)malloc(sizeof(Avl_Tree));

        if(pTree != NULL)
        {
                pTree->root = NULL;//we need to create a tree so we malloc space then set the first node aka root to null
        }

        return (AVL_TREE)pTree;
}

Status avl_tree_insert(AVL_TREE hTree, MY_STRING key, MY_STRING word)
{
        Avl_Tree* pTree = (Avl_Tree*)hTree;

        if(pTree == NULL)
        {
                return FAILURE;
        }

        return avl_tree_insert_helper(&(pTree->root), key, word);
}

Status avl_tree_insert_helper(Node** root, MY_STRING key, MY_STRING word)
{//inserts the nodes of the tree using pass by reference
        Node* temp;
        int compare_value;
        int tree_balance;

        if(*root == NULL)
        {
                temp = (Node*)malloc(sizeof(Node));
                if(temp != NULL)
                {
                        temp->left = NULL;
                        temp->right = NULL;
                        temp->height = 1;
                        temp->key = my_string_init_default();
                        if(temp->key == NULL)
                        {
                                return FAILURE;
                        }

                        temp->words = generic_verctor_init_default(my_string_assignment, my_string_destroy);
                        if(temp->words == NULL)
                        {
                                return FAILURE;
                        }

                        my_string_assignment(&(temp->key), key);
                        generic_vector_push_back(temp->words, word);

                        *root = temp;

                        return SUCCESS;
                }
                else
                {
                        return FAILURE;
                }
        }

        compare_value = my_string_compare(key, (*root)->key);
        if(compare_value > 0)
        {
                if(!avl_tree_insert_helper(&((*root)->right), key, word))
                {
                        return FAILURE;
                }
        }
        else if(compare_value < 0)
        {
                if(!avl_tree_insert_helper(&((*root)->left), key, word))
                {
                        return FAILURE;
                }
        }
        else//if the comparison is a 0 balance
        {
                generic_vector_push_back((*root)->words, word);
        }

        (*root)->height = max_tree_height(get_height((*root)->left), get_height((*root)->right)) + 1;

        tree_balance = get_balance_factor(*root);

        if(tree_balance < -1 && my_string_compare(key, (*root)->left->key) < 0)//left left
        {//if the left is heavy then we need a right roation
                *root = rotate_right(*root);
                return SUCCESS;
        }
        if(tree_balance > 1 && my_string_compare(key, (*root)->right->key) > 0)//right right
        {//if the right is heavy then we need a left rotation
                *root = rotate_left(*root);
                return SUCCESS;
        }

        if(tree_balance < -1 && my_string_compare(key, (*root)->left->key) > 0)//left right
        {
                (*root)->left = rotate_left((*root)->left);
                *root = rotate_right(*root);
                return SUCCESS;
        }
        if(tree_balance > 1 && my_string_compare(key, (*root)->right->key) < 0)//right left
        {
                (*root)->right = rotate_right((*root)->right);
                *root = rotate_left(*root);
                return SUCCESS;
        }

        return SUCCESS;
}

Node* rotate_left(Node* node)
{
        Node* a;
        Node* b;

        //set the left segment of the tree to a
        a = node->right;
        b = a->left;//if the left tree has any right nodes we need to hold onto it with b or else we will lose it

        //finally we make the new rotation and attach the what ever is in node to the right of a completing the rotation
        a->left = node;
        //rotation starts and we put the right of a into the left of node
        node->right = b;
        
        node->height = max_tree_height(get_height(node->left), get_height(node->right)) + 1;
        a->height = max_tree_height(get_height(a->left), get_height(a->right)) + 1;

        return a; //return completed rotation 
       
}

Node* rotate_right(Node* node)
{//works exactly like in rotate_left but for the right
        Node* a;
        Node* b;

        a = node->left;
        b = a->right;

        a->right = node;
        node->left = b;

        node->height = max_tree_height(get_height(node->left), get_height(node->right)) + 1;
        a->height = max_tree_height(get_height(a->left), get_height(a->right)) + 1;//update height

        return a;
}

void node_destroyer(Node* root_node)
{
        //if the root is not null there is something to destroy
        if(root_node != NULL)
        {
                //recursivly call node_destroyer so we can traverse through the entire tree
                node_destroyer(root_node->left);
                node_destroyer(root_node->right);
                //if the generic vector is not null then we must empty it to avoid mem leak
                if(root_node->words != NULL)
                {
                        generic_vector_destroy(&(root_node->words));
                }

                //we also need to destroy the key and we know that there is always going to be a key somewhere
                my_string_destroy(&(root_node->key));
                //finally free the root itself
                free(root_node);
        }
        return;
}

void avl_tree_destroy(AVL_TREE* phTree)
{
        Avl_Tree* pTree = (Avl_Tree*)*phTree;

        //if not null there might be a danglaing pointer
        //but means there is something to be destroied
     
                //if the known type cast is not null then there is definitly something we need to destroy
                if(pTree != NULL)
                {
                        //node_destroyers entire purpose in life is to help destroy the nodes in the
                        //tree otherwise ther would be a massive mem leak
                        node_destroyer(pTree->root);//this empties the entire tree

                        //now we need to destroy the tree frame so we just free pTree aka the known type
                        free(pTree);
                        *phTree = NULL;//finally we must avoid dangaling pointers so we set the pointer handle to null
                }
}
