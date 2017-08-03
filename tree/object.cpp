#include "object.h";

struct student null_stu = {0};

struct student* findStu(struct student* all,int n,int id)
{

	for(int i=0;i<n;i++){
		//all[i]用数据名+下标的方式也行
		if(all->id == id){
			//printf("i find it :%d,%s\n",all->id,all->name);
			return all;
		}
		all ++;
	}

	return &null_stu;
}

struct fenshu* sum(struct fenshu* sum,struct fenshu* a, struct fenshu* b)
{
	
	
	sum->fenzi = a->fenzi * b->fenmu + b->fenzi * a->fenmu;
	sum->fenmu = a->fenmu * b->fenmu;
	return sum;
	
}

struct fenshu* mul(struct fenshu* mul,struct fenshu* a, struct fenshu* b)
{
	
	mul->fenzi = a->fenzi * b->fenzi;
	mul->fenmu = a->fenmu * b->fenmu;
	return mul;
	
}

void move_to(struct Point* start,int x,int y)
{
	start->x = x;
	start->y = y;
}

void add1(int* a, int num)
{
	for(int i=0;i<3;i++){
		if(*a == num){
			//已包含这个数
			break;
		}else{
			a++;
		}
	}

}
