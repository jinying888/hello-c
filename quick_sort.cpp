#include <stdio.h>
#include <stdlib.h>

int arr[] = {3,15,18,17,5,8,1,2,9,4,7,6,12,15,13,21};

void quick_sort(int [], int ,int,int);

int partition(int [], int, int,int);

int main()
{
	
	quick_sort(arr,0,14,15);

	for(int i=0;i<16;i++){
		printf("\n%d",arr[i]);
	}
	

	getchar();
}

void quick_sort(int arr[],int left, int right,int pivot)
{
	//x要保存的是分隔的位置（基准的位置）
	int x;
	//当left == pivot时，说明这个子区块只一个元素，不用排序了。已经排好了。就是pivot这个位置
	if(left <pivot){
		x = partition(arr,left,right,pivot);
		quick_sort(arr,left,x-2,x-1);
		quick_sort(arr,x+1,right,pivot);
	}

}


int partition(int arr[], int left, int right, int pivot)
{
	int temp;
	while(1){
		while(arr[left] < arr[pivot] && left < pivot){
			left ++;
		}

		if(left == pivot){
			//设置新的pivot，（到这里povit是排好的）
			return pivot;
		}

		while(arr[right] > arr[pivot] && right > left){
			right --;
		}

		if(left == right){
			temp = arr[left];
			arr[left] = arr[pivot];
			arr[pivot] = temp;
			//设置新的pivot，（到这里povit是排好的）
			pivot = left;
			return pivot;
		}

		//交换值
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
}