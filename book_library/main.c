#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "admin.h"
#include "bookshelf.h"
#include "reader.h"

struct bookshelf bookshelf1 = {1,"a book shelf",20, 0};
/*借书的整个过程*/
int borrow_book(struct reader *,struct bookshelf * , char * , struct book * );
int receive_book(struct reader *,struct bookshelf * , char * , struct book * );
int main()
{

	int n;
	int flag=0;
	struct bookshelf * bookshelf0;
	int book_id;
	struct reader reader0 = {1,"xiaoli",0};
	struct book * book_p = 0;
	/*bookname to be search*/
	char * bookname = 0;

	/*create a book start*/
	char *name_str = "php program";
	int name_len = strlen(name_str);

	char * detail_str = "a new tech book";
	int detail_len = strlen(detail_str);
	
	struct book book_info;
	struct book *book1 = 0;
	
	book1 = (struct book*)malloc(sizeof(struct book));
	book1->id = 2;
	book1->name = (char *) malloc (name_len);
	book1->detail = (char *) malloc (detail_len);

	strcpy(book1->name, name_str);
	strcpy(book1->detail, detail_str);
	book1->nums = 10;
	
	book_p = (struct book*) malloc (sizeof(struct book));
	book_p->id = 0;
	book_p->name = (char *) malloc (name_len);
	book_p->detail = (char *) malloc (detail_len);

	strcpy(book_p->name, "");
	strcpy(book_p->detail, "");
	book_p->nums = 0;
	

	bookshelf1.books[0].id = 1;
	bookshelf1.books[0].name = "c++ program";
	bookshelf1.books[0].detail = "a tech book";
	bookshelf1.books[0].nums = 10;
	
	
	bookshelf0 = &bookshelf1;
	//create a book,put it to bookshelf
	flag = add_book(bookshelf0, book1);

	//借书
	bookname = "php program";
	borrow_book(&reader0,bookshelf0,bookname,book_p);

	has_books(&reader0);

	bookname = "c++ program";
	borrow_book(&reader0,bookshelf0,bookname,book_p);

	has_books(&reader0);

	//还书
	bookname = "c++ program";
	receive_book(&reader0,bookshelf0,bookname,book_p);
	has_books(&reader0);

	book_info = get_book_by_id(bookshelf0, 3);
	
	if(book_info.id == 0){
		printf("cant find book id\n");
	}else{
		printf("find book %d,%s\n",book_info.id,book_info.name);
	}

	return 0;
}

/*借书的整个过程*/
int borrow_book(struct reader *reader0,struct bookshelf * bookshelf0, char * bookname, struct book * book_p)
{
	int book_id = 0;
	int flag = 0;
	//search book
	book_id = search_book(bookshelf0, bookname, book_p);
	//lent that book
	flag = lent_book(bookshelf0, book_id);

	//reader get that book
	get_book(reader0, book_p);
	return 0;
}

/*还书的整个过程*/
int receive_book(struct reader *reader0,struct bookshelf * bookshelf0, char * bookname, struct book * book_p)
{
	int book_id = 0;
	int flag = 0;
	//search book
	book_id = search_book(bookshelf0, bookname, book_p);
	//lent that book
	flag = return_book(bookshelf0, book_id);

	//reader get that book
	out_book(reader0, book_p);
	return 0;
}


