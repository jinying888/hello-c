#include <stdio.h>
#include <stdlib.h>


int mid_sort(int *, int , int );
int n = 13;


int obj = 17;
int main()
{
	int arr[] = {1,3,5,6,7,8,12,14,15,15,16,18,20};
	int result = mid_sort(arr,0,12);


}

int mid_sort(int *arr, int begin, int end)
{
	
	int mid = (begin + end)/2;
	if(*(arr+mid) > obj){
		end = mid - 1;
	}
	if(*(arr+mid) < obj){
		begin = mid + 1;
	}

	if(*(arr+mid) == obj){
		printf("%d",obj);
		return 0;
	}

	if(end<begin)
	{
		printf("cant find %d",obj);
		return -1;
	}

	mid_sort(arr,begin,end);

}


