#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct btnode {
	int value;
	struct btnode *left;
	struct btnode *right;
};



struct btnode * newnode(int);
void inorder(struct btnode*);
void preorder(struct btnode*);
void postorder(struct btnode*);
void insert();
void search(struct btnode *);
void delete_node(struct btnode *);
int search_data(struct btnode * , int );
