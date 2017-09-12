#ifndef BOOK_H
#define BOOK_H
#include <stdio.h>
#include <stdlib.h>

//还书时，这本书的总数加一
int nums_plus(struct bookshelf *, int);
int nums_subtract(struct bookshelf *, int);

struct book get_book_by_id(struct bookshelf *, int);

//书类
struct book{
	int id;
	char * name;
	char * detail;
	int nums;
};
#endif