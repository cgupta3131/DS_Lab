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
	for(int i=0;i<insize;i++)
		cout << data[i] << endl;
	 
}

void Merge(int *data, int start, int end)
{
	priority_queue<int, vector<int>, greater<int> > p;

	for(int i=start;i<=end;i++)
		p.push(data[i]);

	for(int i=start;i<=end;i++)
	{
		data[i] = p.top();
		p.pop();
	}
}


void KWayMergeSort(int *data, int insize, int k, int iterations)
{
	int start = 0;
	int end = insize-1;

	int curr_size;
	int left_start;

	int stopper = 1;

	for(curr_size = 1;curr_size<=(end-start);curr_size = k*curr_size)
	{
		if(iterations == 0)
			break;

		for(left_start=0; left_start<(end-start);left_start += k*curr_size)
		{
			int right_end = min(left_start+k*curr_size-1,end-start);

			if(left_start < right_end)
				Merge(data,left_start,right_end);
		}

		if(stopper == iterations)
			break;
		else
			stopper++;
	}	
}

int main()
{	

	int k;
	cin >> k;

	int iterations;
	cin >> iterations;

	insize = 0;
	cin >> insize;

	int *input = new int[insize];
	for(int i=0;i<insize;i++)
		cin >> input[i];

	if(k == 1)
	{
		cout << "When K=1, sorting of Array not possible" << endl;
		return 0;
	}

	KWayMergeSort(input,insize,k,iterations);

	printArray(input);



	return 0 ; 

}
