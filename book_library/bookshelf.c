#include "bookshelf.h"



int add_book(struct bookshelf * shelf, struct book * new_book)
{
	int i;
	int count = shelf->count;
	for(i=0;i<count;i++){
		if(shelf->books[i].id == 0){
			shelf->books[i].id = new_book->id;
			shelf->books[i].name = (char *)malloc( strlen(new_book->name) + 1);
			strcpy(shelf->books[i].name, new_book->name);
			shelf->books[i].nums = new_book->nums;
			shelf->books[i].detail = (char *)malloc( strlen(new_book->detail) + 1);
			strcpy(shelf->books[i].detail, new_book->detail);
			break;
		}

	}
	
	return 0;

}

/**
	search book using bookname
*/
int search_book(struct bookshelf * shelf, char * book_name, struct book *book_p)
{
	int i;
	int count = shelf->count;
	for(i=0;i<count;i++){
		if(shelf->books[i].id == 0){
			continue;
		}
		if(0 == strcmp(shelf->books[i].name,book_name)){
			
			book_p->id = shelf->books[i].id;
			strcpy(book_p->name, shelf->books[i].name);
			strcpy(book_p->detail, shelf->books[i].name);
			book_p->nums = shelf->books[i].nums;

			return shelf->books[i].id;
		}
	}
	
	return 0;
}