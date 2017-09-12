#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "book.h"

int add_book(struct bookshelf *, struct book *);
int search_book(struct bookshelf *,char *, struct book *);

struct bookshelf
{
	int id;
	char name[20];
	int count;
	//all books
	struct book books[20];
};