#include <stdlib.h>
#include <stdio.h>
#include "book.h"

int lent_book(struct bookshelf *, int);
int return_book(struct bookshelf *, int);

struct admin
{
	int id;
	char * name;
};
