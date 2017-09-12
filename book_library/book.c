#include "book.h"
#include "bookshelf.h"

int nums_subtract(struct bookshelf *shelf, int book_id)
{

	int i;
	int count = shelf->count;

	if(book_id <0){
		return -1;
	}

	for(i=0;i<count;i++){
		if(shelf->books[i].id == book_id){
			shelf->books[i].nums --;
			return 0;
		}
	
	}
}

int nums_plus(struct bookshelf *shelf, int book_id)
{
	
	int i;
	int count = shelf->count;

	if(book_id <0){
		return -1;
	}

	for(i=0;i<count;i++){
		if(shelf->books[i].id == book_id){
			shelf->books[i].nums ++;
			return 0;
		}
	
	}
	return -1;
}

struct book get_book_by_id(struct bookshelf * shelf, int book_id)
{
	int i;
	int count = shelf->count;
	struct book nonbook = {0,0,0,0};
	if(book_id <0){
		
		return nonbook;
	}
	for(i=0;i<count;i++){
		if(shelf->books[i].id == book_id){
			return shelf->books[i];
		}
	}
	return nonbook;
}