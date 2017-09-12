#include "admin.h"
#include "bookshelf.h"

/*amdin lent book to reader*/
int lent_book(struct bookshelf * shelf, int book_id)
{
	int flag;
	if(book_id > 0 ){
		flag = nums_subtract(shelf, book_id);
		if(flag == 0 ){
			return 0;
		}else{
			return -1;
		}
	}

}

int return_book(struct bookshelf * shelf, int book_id)
{
	int flag;
	if(book_id > 0 ){
		flag = nums_plus(shelf, book_id);
		if(flag == 0 ){
			return 0;
		}else{
			return -1;
		}
	}
}