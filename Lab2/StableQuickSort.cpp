#include<bits/stdc++.h>
using namespace std;

int insize ;
void swapElements(int &v1, int &v2)
{

	int temp = v1;
	v1 = v2;
	v2 = temp;

}

void printArray(int *data)
{
	cout << "Array is: ";

	for(int i=0;i<insize;i++)
		cout << data[i] << " ";
	cout << endl; 


}


int partition(int *data, int left, int right)
{
	int *helper = new int[right-left+1];
	int x = 0;


	for(int i=left+1;i<=right;i++)
	{
		if(data[i] < data[left] )
		{
			helper[x] = data[i];
			x++;
		}
	}

	int pivotId = x+left;
	helper[x] = data[left];
	x++;

	for(int i=left+1;i<=right;i++)
	{
		if(data[i] >= data[left] )
		{
			helper[x] = data[i];
			x++;
		}
	}

	for(int i=left;i<=right;i++)
		data[i] = helper[i-left];	

	delete [] helper;

	return pivotId;

}

int y = 0;
void QuickSortStable(int *data, int left, int right)
{


	if(( right-left) < 1) return;

	int partition_index = partition(data,left,right);


	QuickSortStable(data,left,partition_index-1);
	QuickSortStable(data,partition_index+1,right);
}


int main()
{
	//int input[]= {12, 6, 4, 9,14,43,42,15,16,18,19,20,21,3,100};
	int input[]= {4,5,3,2,4,1};
	insize = sizeof(input)/sizeof(input[0]);

	printArray(input);
	QuickSortStable(input,0,insize-1);
	cout << "Sorted ";
	printArray(input);


	return 0 ; 

}