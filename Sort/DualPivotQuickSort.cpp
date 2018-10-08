#include<bits/stdc++.h>

using namespace std;

int insize = 0;
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

class Pair{

public:
	int first;
	int second;
};

Pair partition(int *data, int left, int right)
{
	
	if(data[left] > data[right])
	{
		swapElements(data[left],data[right]);
	}

	int count1=0;
	for(int i=left;i<=right;i++)
		if(data[i]<data[left])
			count1++;

	if(count1 != 0)
		swapElements(data[count1+left],data[left]);


	int count2=0;
	for(int i=left;i<right;i++)
		if(data[i]>data[right])
			count2++;

	if(count2 != 0)
		swapElements(data[right-count2],data[right]);

	Pair Pivot_Index;
	Pivot_Index.first = left+count1;
	Pivot_Index.second = right-count2;

	int index1 = left;
	int index2 = left+count1+1;
	int index3 = right-count2+1;


	while(index1 != left+count1)
	{
		if(data[index1] > data[Pivot_Index.first] && 
			data[index1] < data[Pivot_Index.second])
		{
			while(index2 != right-count2)
			{
				if(data[index2] < data[Pivot_Index.first])
				{
					swapElements(data[index1],data[index2]);
					index1++;
					index2++;
					break;
				}

			}
		}

		else if(data[index1] > data[Pivot_Index.second])
		{
			while(index3 != right+1)
			{
				if(data[index3] < data[Pivot_Index.first])
				{
					swapElements(data[index1],data[index3]);
					index1++;
					index3++;
					break;
				}

			}
		}

		else
			index1++;
	}

	/*  for(int i=left;i<=right;i++)
		cout << data[i] << " ";
	cout << endl;  */

	index2 = left+count1+1;
	index3 = right-count2+1;

	while(index2 != right-count2)
	{
		if(data[index2] > data[right-count2])
		{
			while(index3 != right+1)
			{
				if(data[index3] < data[Pivot_Index.second])
				{
					swapElements(data[index2],data[index3]);
					index2++;
					index3++;
					break;
				}
			}
		}

		else
			index2++;
	}

	/*  for(int i=left;i<=right;i++)
		cout << data[i] << " ";
	cout << endl;  */

	return Pivot_Index;
}


void DoublePivot_QuickSort(int *data, int left, int right)
{

	if(right-left < 1)
		return;

	if(right-left == 1)
	{
		if(data[left] > data[right])
			swapElements(data[left],data[right]);
		return;
	}

	Pair partition_index = partition(data,left,right);
	//cout << partition_index.first << " " << partition_index.second << endl;

	DoublePivot_QuickSort(data,left,(partition_index.first)-1);
	DoublePivot_QuickSort(data,(partition_index.first)+1,
		(partition_index.second)-1);
	DoublePivot_QuickSort(data,(partition_index.second)+1,right);

}

int main()
{
	int input[]= {12, 6, 4, 9,14,43,42,3};
	insize = sizeof(input)/sizeof(input[0]);

	printArray(input);
	DoublePivot_QuickSort(input,0,insize-1);
	printArray(input);



	return 0 ; 

}

