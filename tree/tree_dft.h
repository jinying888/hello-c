#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct btnode_dfs {
	int value;
	struct btnode_dfs * left;
	struct btnode_dfs * right;
	int is_visited;
};


void insert_dfs();
void search_dfs(struct btnode_dfs *);

void inorder(struct btnode_dfs *);

void deep_first_travel(struct btnode_dfs *);
