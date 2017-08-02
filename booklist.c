#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



struct book{
	int number;
	char name['20'];
};

struct node{
	struct book data;
	struct node *next;
};


int getLength(struct node *);

int insertList(struct node *, struct book);

int showList(struct node *);

int findNodeByBookName(char *);

struct node * findNodeByBookNumber(struct node *,int );

int main()
{
	int i,len;
	struct node *head;
	struct node *p;
	struct node *q;
	struct node *out;
	int find_number;

	head = NULL;

	scanf("%d",&len);

	for(i=0;i<len;i++){
		q = (struct node *) malloc ( sizeof(struct node ) );
		scanf("%d", &q->data.number);
		scanf("%s", q->data.name);

		if(head == NULL){
			head = q;
			q->next = NULL;
		}else{
			p->next = q;
			q->next = NULL;
		}

		p = q;
	}


	out = head;
	while(out != NULL){
		
		printf("%d", out->data.number);
		printf("%s", out->data.name);
		printf("\n");
		out = out->next;

	}


	printf("%d\n", getLength(head));

	struct book newbook;
	newbook.number = 100;
	char *name = "add01";
	strcpy(newbook.name,name);
	insertList(head, newbook);
	newbook.number = 101;
	name = "add01";
	strcpy(newbook.name,name);
	insertList(head, newbook);


	showList(head);


	printf("请输入要找的book的number：\n");
	scanf("%d", &find_number);
	struct node *finded = findNodeByBookNumber(head, find_number);
	if(finded == NULL){
		printf("找不到book的number：\n");
	}else{
		printf("%d", finded->data.number);
		printf("%s", finded->data.name);
		printf("\n");
	}

	getchar();getchar();

	return 0;
	
}


int getLength(struct node *head)
{
	struct node *book_list;
	book_list = head;
	int length = 0;
	
	while(book_list != NULL){
		
		length ++;
		book_list = book_list->next;

	}
	return length;
}


int insertList(struct node *insert_pos, struct book newbook)
{
	
	struct node *tmp = (struct node *) malloc ( sizeof(struct node ) );
	tmp->next = insert_pos->next;
	tmp->data = newbook;
	insert_pos->next = tmp;
	return 0;
}

struct node* findNodeByBookNumber(struct node *head, int number)
{
	struct node *out;
	out = head;
	while(out != NULL){

		if(number == out->data.number){
			return out;
		}
		out = out->next;
	}
	return NULL;
}

int findNodeByBookName(char *book_name)
{
	return 0;
}

int showList(struct node *head)
{
	struct node *out;
		out = head;
	while(out != NULL){
		
		printf("%d", out->data.number);
		printf("%s", out->data.name);
		printf("\n");
		out = out->next;

	}
	return 0;
}

