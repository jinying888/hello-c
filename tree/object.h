#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct student{
	int id;
	char name[30];
	int score[3];
	char * email;

};

struct fenshu {
	int fenzi;
	int fenmu;
};

struct Point {
	int x;
	int y;
};

struct Buffer {
	int *a;
	int *b;
	int *c;
};

struct mp3{
	char * singer;
	char * name;
	char * zhuanji;
	char * download_url;
	int times;
};

struct mp4{
	char singer[100];
	char name[100];
	char zhuanji[100];
	char download_url[100];
	int times;
};


struct circle{
	int x;
	int y;
	int radius;
};

//有电脑的学生
struct Laptop {
	char type[30];
	char color;
	float price;
};

struct AdvanStudent {
	int id;
	char name[30];
	int score[3];
	char * email;
	struct Laptop *computer;
};



struct student* findStu(struct student*  ,int  ,int );

struct fenshu* sum(struct fenshu* ,struct fenshu* , struct fenshu* );
struct fenshu* mul(struct fenshu* ,struct fenshu* , struct fenshu* );

void move_to(struct Point* ,int ,int );


