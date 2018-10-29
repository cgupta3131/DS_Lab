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

void BubbleSort(int *data)
{
	for(int i = (insize-1); i>0 ; i--)
		for(int j=0;j<i;j++)
			if(data[j]>data[j+1])
				swapElements(data[j],data[j+1]);
}


void InsertionSort(int *data)
{

	for(int i=1;i<insize;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(data[j]>data[i])
			{	
				int temp = data[i];
				for(int k=j;k<i;k++)
					swapElements(data[k],data[i]);
				continue;
			}
		}
	}
}

void InsertionSort2(int *data)
{

	for(int i=1;i<insize;i++)
	{
		int temp = data[i];
		int j;
		for(j=i-1;j>=0;j--)
		{
			if(data[j] > temp)
				data[j+1] = data[j];
			else
				break;
		}

		data[j+1] = temp;
	}
}


void SelectionSort(int *data)
{

	for(int i=0;i<insize-1;i++)
	{
		int min_index = i;
		for(int j=i+1;j<insize;j++)
		{
			if(data[j] <= data[min_index])
				min_index = j;
		}
		swapElements(data[i],data[min_index]);
		//printArray(data);
	}
}

//For Stable Selection Sort, instead of swapping the elements, just push 
//the elements forward, that is maintaing the order(cyclicity) and 
//then place data[min_index] at data[i];
void SelectionSort_Stable(int *data)
{
	for(int i=0;i<insize-1;i++)
	{
		int min_index = i;
		for(int j=i+1;j<insize;j++)
		{
			if(data[j] <= data[min_index])
				min_index = j;
		}
		int min_value = data[min_index];
		for(int j=min_index-1;j>=i;j--)
			data[j+1] = data[j];
		data[i] = min_value;

	}

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


void MergeSort(int *data, int start, int end)
{
	/*  cout << start << " " << end << endl;
	cout << data[2] << " " << data[3] << endl;  */
	if((end-start) < 1)
		return;

	if(end-start<4) //Switiching to Insertion Sort when size is less than 4
	{	
		InsertionSort(data);
		return;
	}
	

	MergeSort(data,start,(end+start)/2);
	MergeSort(data,(end+start+2)/2,end);

	Merge(data,start,end);

	
}


int partition(int *data, int left, int right)
{
	int Pivot_Element = data[left];
	int Pivot_Index = left;

	int count=0;
	for(int i=left+1;i<=right;i++)
		if(data[i]<Pivot_Element)
			count++;

	if(count != 0)
		swapElements(data[count+left],data[left]);

	Pivot_Index = count+left;

	int index1 = left;
	int index2 = right;

	while(index1 != Pivot_Index)
	{
		if(data[index1] < Pivot_Element)
		{
			index1++;
			continue;
		}
		
		//data[index1] > Pivot_Element
		while(index2 != Pivot_Index)
		{
			if(data[index2] < Pivot_Element)
			{
				swapElements(data[index1],data[index2]);
				index2--;
				break;
			}
			else
				index2--;
		}

		index1++;
	}

	//cout << "Element: " << Pivot_Element << endl;
	return Pivot_Index;


}


void QuickSort(int *data, int left, int right)
{

	if(right-left < 1)
		return;

	if(right-left<4) //Switiching to Insertion Sort when size is less than 4
	{	
		InsertionSort(data);
		return;
	}

	int partition_index = partition(data,left,right);

	QuickSort(data,left,partition_index-1);
	QuickSort(data,partition_index+1,right);

}



int main()
{
	int input[]= {12, 6, 4, 9,14,43,42,15,16,18,19,20,21,3,100};
	//int input[]= {4,5,3,2,4,1};
	insize = sizeof(input)/sizeof(input[0]);

	printArray(input);

	//BubbleSort(input);
	//InsertionSort(input);
	//InsertionSort2(input);
	//SelectionSort_Stable(input);
	MergeSort(input,0,insize-1);
	//QuickSort(input,0,insize-1);

	cout << "Sorted ";
	printArray(input);


	return 0 ; 

}

