#include "reader.h"
#include <string.h>

/*get book*/
void has_books(struct reader* rd)
{
	int i=0;
	for(i=0;i<5;i++){
		if(rd->has_books[i].id >0){
			printf("bookname:%s,",rd->has_books[i].name);
			
		}
		
	}
	printf("\n");
}

int get_book(struct reader* rd, struct book *abook)
{
	int i=0;
	int len;
	for(i=0;i<5;i++){
		if(rd->has_books[i].id >0){
			continue;
		}else{
			rd->has_books[i].id = abook->id;
			rd->has_books[i].nums = 1;
			len = strlen(abook->name);
			rd->has_books[i].name = ( char *) malloc ( sizeof(char) * (len + 1));
			strcpy(rd->has_books[i].name, abook->name);
			len = strlen(abook->detail);
			rd->has_books[i].detail = ( char *) malloc ( sizeof(char) * (len + 1));
			strcpy(rd->has_books[i].detail, abook->detail);
			return 0;
		}
	}
	
	return -1;
}

int out_book(struct reader * rd, struct book *abook)
{
	int i=0;
	int len;
	for(i=0;i<5;i++){
		if(rd->has_books[i].id == abook->id){
			free(rd->has_books[i].name);
			rd->has_books[i].name = 0;
			free(rd->has_books[i].detail);
			rd->has_books[i].detail = 0;

			rd->has_books[i].id = 0;
			rd->has_books[i].nums = 0;
		}else{
			continue;
		}
	}
	
	return -1;
}




