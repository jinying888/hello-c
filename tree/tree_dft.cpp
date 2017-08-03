#include "tree_dft.h";

struct btnode_dfs * temp_dfs = NULL;
struct btnode_dfs * root_dfs = NULL;




void insert_dfs()
{
	if(root_dfs == NULL){
		root_dfs = temp_dfs;
	}else{
		search_dfs(root_dfs);
	}
}

void search_dfs(struct btnode_dfs * root_dfs)
{
	if(temp_dfs->value < root_dfs->value && root_dfs->left == NULL){
		root_dfs->left = temp_dfs;
	}else if(temp_dfs->value < root_dfs->value && root_dfs->left != NULL){
		search_dfs(root_dfs->left);
	}else if(temp_dfs->value >= root_dfs->value && root_dfs->right == NULL){
		root_dfs->right = temp_dfs;
	}else if(temp_dfs->value >= root_dfs->value && root_dfs->right != NULL){
		search_dfs(root_dfs->right);
	}
}

void inorder(struct btnode_dfs * tree)
{
	if(tree->left != NULL){
		inorder(tree->left);
	}
	printf("%d->",tree->value);
	if(tree->right != NULL){
		inorder(tree->right);
	}
}


void deep_first_travel(struct btnode_dfs * root_dfs)
{
	temp_dfs = root_dfs;
	while(temp_dfs != NULL && temp_dfs->is_visited == 0){
		
		if(temp_dfs->left != NULL && temp_dfs->left->is_visited == 0){
			
			printf("%d-->",temp_dfs->value);
			temp_dfs = temp_dfs->left;
			
			
		}else if(temp_dfs->right != NULL && temp_dfs->right->is_visited == 0){
			
			printf("%d-->",temp_dfs->value);
			temp_dfs = temp_dfs->right;
			
			
		}else{
			temp_dfs->is_visited = 1;
			printf("%d-->",temp_dfs->value);
			temp_dfs = root_dfs;
			printf("\n");
		}

		
		
		
	}
}




