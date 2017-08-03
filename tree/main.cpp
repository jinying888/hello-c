#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "object.h"
#include "tree.h"
#include "tree_dft.h"

extern struct btnode * temp;
extern struct btnode * root;
extern struct btnode_dfs * temp_dfs;
extern struct btnode_dfs * root_dfs;
extern struct student null_stu;


void run_object();
void run_tree();
void run_tree_dft();

int main()
{

		//注释：先ctrl+k，然后ctrl+c
	//取消注释：先ctrl+k，然后ctrl+u

	//deep first search
	int node_arr[] = {16,2,13,6,3,11,5,7,9,20,19,15};
	for(int i=0;i<12;i++){
		temp_dfs = (struct btnode_dfs *)malloc(sizeof(struct btnode_dfs));
		temp_dfs->value = node_arr[i];
		temp_dfs->left = NULL;
		temp_dfs->right = NULL;
		temp_dfs->is_visited = 0;
		insert_dfs();
	}

	inorder(root_dfs);
	printf("\n");
	deep_first_travel(root_dfs);
	
	return 0;
}

void run_object()
{

	struct mp3 mp3_iloveu = {"iloveu","linda","love","http://www.soosososoos.com/ilove.mp3",0};


	struct mp4 mp4_iloveu = {"iloveu","linda","love","http://www.soosososoos.com/ilove.mp3",0};

	printf("mp4 is %s,%s\n",mp4_iloveu.singer,mp4_iloveu.singer);


	circle c1;
	c1.x=0;
	c1.y=0;
	c1.radius = 5;

	

	struct student st1;

	st1.id = 123;
	strcpy(st1.name, "lilis");
	st1.score[0] = 90;
	st1.score[1] = 80;
	st1.score[2] = 100;
	st1.email = "123@qq.com";


	struct student st_arr[3];

	st_arr[0].id = 123;
	strcpy(st_arr[0].name, "lilis");
	st_arr[0].score[0] = 90;
	st_arr[0].score[1] = 80;
	st_arr[0].score[2] = 100;
	st_arr[0].email = "123@qq.com";

	st_arr[1].id = 124;
	strcpy(st_arr[1].name, "alis");
	st_arr[1].score[0] = 90;
	st_arr[1].score[1] = 80;
	st_arr[1].score[2] = 98;
	st_arr[1].email = "123@qq.com";

	st_arr[2].id = 125;
	strcpy(st_arr[2].name, "bili");
	st_arr[2].score[0] = 90;
	st_arr[2].score[1] = 80;
	st_arr[2].score[2] = 100;
	st_arr[2].email = "123@qq.com";

	printf("%d,%s,%d,%d,%d,%s\n", st_arr[1].id,st_arr[1].name,st_arr[1].score[0],st_arr[1].score[1],st_arr[1].score[2],st_arr[1].email);

	struct student* stu = &st_arr[1];
	printf("%d,%s,%d,%d,%d,%s\n", stu->id,stu->name,stu->score[0],stu->score[1],stu->score[2],stu->email);

	//查找id为125的student

	struct student* find_stu;
	
	
	find_stu = findStu(st_arr,3,129);
	if(find_stu->id == 0){
		printf("i can not find it :%d\n");
	}else{
		printf("i find it :%d,%s\n",find_stu->id,find_stu->name);
	
	}

	//fenshu 结构体

	struct fenshu a = {2,3};
	struct fenshu b = {3,5};
	struct fenshu* new_fenshu;

	struct fenshu result = {0};
	new_fenshu = sum(&result,&a,&b);
	printf("%d/%d+%d/%d=%d/%d\n",a.fenzi,a.fenmu,b.fenzi,b.fenmu,new_fenshu->fenzi,new_fenshu->fenmu);
	mul(&result,&a,&b);
	printf("%d/%d+%d/%d=%d/%d\n",a.fenzi,a.fenmu,b.fenzi,b.fenmu,(&result)->fenzi,(&result)->fenmu);



	struct Laptop computer = { "007", '1', 12.5};
	struct AdvanStudent xiaoli = { 1, "xiaoli", {70,80,90},"xiaoli@qq.com",&computer};

	printf("%s's computer type is:%s",xiaoli.name,xiaoli.computer->type);

	//point

	struct Point p1 = {1,1};

		//int a[3] = {1,2,3};
	//int b[] = {3,4,5};
	//int add1(int* a, int num);

	
}


void run_tree()
{

	//注释：先ctrl+k，然后ctrl+c
	//取消注释：先ctrl+k，然后ctrl+u

	struct btnode * root = NULL;

	root = newnode(50);
	root->left = newnode(20);
	root->right = newnode(30);
	root->left->left = newnode(70);
	root->left->right = newnode(80);
	root->left->right->right = newnode(60);
	root->left->left->left = newnode(10);
	root->left->left->right = newnode(40);

	if(root == NULL){
		printf("no node to display");

	}

	printf("tree elements are \n");
	printf("\ndisplayed in inorder\n");

	inorder(root);
	printf("null");



	int node_arr[] = {16,2,13,6,3,11,5,7,9,20,19,15};
	
	for(int i=0;i<12;i++){
		temp = (struct btnode*) malloc (sizeof(struct btnode));
		temp->value = node_arr[i];
		temp->left = NULL;
		temp->right = NULL;
		insert();
	}

	printf("\n");
	inorder(root);
	printf("\n");

	preorder(root);
	printf("\n");

	postorder(root);
	printf("\n");

	int need = 0;
	need = search_data(root,7);
	if(need == 1){
		printf("search 7 sucess\n");
	}else{
		printf("search 7 faied\n");
	}
	
	//删除某个子tree或整个tree
	//delete_node(root);
	//printf("\n");
	//root = NULL;
	//if(root == NULL){
	//	printf("kong\n");
	//}

	//need = search_data(root,5);
	//if(need == 1){
	//	printf("search 5 sucess\n");
	//}else{
	//	printf("search 5 faied\n");
	//}
}








		
