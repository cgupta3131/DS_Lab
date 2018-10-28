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
void Merge(int *data, int start, int end)
{
	int *mergerArray = new int[end-start+1];

	int index1 = start;
	int index2 = (end+start+2)/2;
	
	for(int i=0;i<end-start+1;i++)
	{

		if(index1 == (end+start+2)/2)
		{
			mergerArray[i] = data[index2];
			index2++;
			continue;
		}

		if(index2 == end+1)
		{
			mergerArray[i] = data[index1];
			index1++;
			continue;
		}

		if(data[index1] < data[index2])
		{
			mergerArray[i] = data[index1];
			index1++;
			continue;
		}

		if(data[index1] >= data[index2])
		{
			mergerArray[i] = data[index2];
			index2++;
			continue;
		}
	}

	for(int i=0;i<end-start+1;i++)
		data[i+start] = mergerArray[i];

	return;

}

//Iterative Merge Sort is also Bottom-Up Method

void MergeSort(int *data, int start, int end)
{
	int curr_size;
	int left_start;

	for(curr_size = 1;curr_size<=(end-start);curr_size = 2*curr_size)
	{
		for(left_start=0; left_start<(end-start);left_start += 2*curr_size)
		{
			int mid = left_start +curr_size -1;
			int right_end = min(left_start+2*curr_size-1,end-start);

			Merge(data,left_start,right_end);
		}

	}

	
}
int main()
{
	int input[]= {12, 6, 4, 9,14,43,42,3};
	//int input[]= {4,5,3,2,4,1};
	insize = sizeof(input)/sizeof(input[0]);

	printArray(input);
	MergeSort(input,0,insize-1);
	cout << "Sorted ";
	printArray(input);

	return 0 ; 

}

