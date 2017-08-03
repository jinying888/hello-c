#include "tree.h";

struct btnode * temp = NULL;
struct btnode * root = NULL;

void insert()
{
	if(root == NULL){
		root = temp;
	}else{
		//�ҵ�tempӦ�÷ŵ�λ�ã����ҷŵ�
		search(root);
	}
}

void search(struct btnode * root_node)
{
	if(temp->value >= root_node->value && root_node->right == NULL){
		root_node->right = temp;
	}else if(temp->value >= root_node->value && root_node->right != NULL){
		search(root_node->right);
	}else if(temp->value <= root_node->value && root_node->left == NULL){
		root_node->left = temp;
	}else if(temp->value <= root_node->value && root_node->left != NULL){
		search(root_node->left);
	}

}


//�½�һ���ڵ�
struct btnode * newnode(int value)
{
	struct btnode * node = (struct btnode *)malloc(sizeof(struct btnode));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void inorder(struct btnode * tree)
{
	if(tree->left != NULL){
		inorder(tree->left);
	}
	printf("%d->",tree->value);
	if(tree->right != NULL){
		inorder(tree->right);
	}
}

void preorder(struct btnode * tree)
{
	printf("%d->",tree->value);
	if(tree->left != NULL){
		preorder(tree->left);
	}
	if(tree->right != NULL){
		preorder(tree->right);
	}
}

void postorder(struct btnode * tree)
{
	if(tree->left != NULL){
		postorder(tree->left);
	}
	if(tree->right != NULL){
		postorder(tree->right);
	}
	printf("%d->",tree->value);
}

void delete_node(struct btnode * node)
{
	if(node != NULL){
		if(node->left != NULL){
			delete_node(node->left);
		}
		if(node->right != NULL){
			delete_node(node->right);
		}
		printf("del-%d----",node->value);
		free(node);
		node = NULL;
		//���Ǵ���ĸ��ڵ�û������ΪNULL������������������Ѹ�����Ϊ�վ�����
	}
}

int search_data(struct btnode * root_data, int need)
{
	if(root_data == NULL){
		return 0;
	}

	if(root_data->value > need){
		//�����Ҫ���ҵ����ȸ��ڵ�С��ֻ��������������������������Ҳ�����ȵģ��������Ķ�NULL�ˣ������Ҳ�����
		search_data(root_data->left,need);
	}else if(root_data->value < need){
		search_data(root_data->right,need);
	}else{
		return 1;
	}

}



