#include <stdio.h>
#include <stdlib.h>
#include "book.h"

int get_book(struct reader*, struct book *);
int out_book(struct reader*, struct book *);
void has_books(struct reader *);

struct reader{
	int id;
	char * name;
	struct book has_books[5];
};