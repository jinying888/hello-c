#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <stdlib.h>

//����ʱ���Ȿ���������һ
int nums_plus(struct bookshelf *, int);
int nums_subtract(struct bookshelf *, int);

struct book get_book_by_id(struct bookshelf *, int);

//����
struct book{
	int id;
	char * name;
	char * detail;
	int nums;
};
#endif