#include<bits/stdc++.h>

using namespace std;

double upper_Load_Factor;

class MapNode
{

public:
	int key;
	MapNode* next;

	MapNode(int key)
	{
		this->key = key;
		next = NULL;
	}

};


class ourmap
{
	MapNode** buckets; //is an array which will store the head of Linked List, Hence double pointer!!
	int count;
	int numBuckets;

public:
	ourmap(int bucket_count)
	{
		count = 0;
		numBuckets = bucket_count;
		buckets = new MapNode*[numBuckets]; //initializing the array of head of LL

		for(int i=0;i<numBuckets;i++)
			buckets[i] = NULL;
	}
private:
	int size(){
		return count;
	}


	int getBucketIndex(int key)
	{
		return key % numBuckets;
	}


	
	void rehash()
	{
		MapNode **temp = buckets;
		buckets = new MapNode*[3*numBuckets];

		for(int i=0;i<3*numBuckets;i++)
			buckets[i] = NULL;

		int oldBucketCount = numBuckets;
		numBuckets *= 3;
		count = 0;

		for(int i=0;i<oldBucketCount;i++)
		{
			MapNode *head = temp[i];

			while(head != NULL)
			{
				int key = head->key;
				insert(key);

				head = head->next;
			}
		}

		for(int i=0;i<oldBucketCount ; i++)
		{
			MapNode*head = temp[i];
			delete head; //fist deleting the Linked Lists in temp[i]
		}

		delete [] temp;	//then delete the whole temp array
	}

public:
	void insert(int key)
	{

		int bucketIndex = getBucketIndex(key);
		MapNode *head = buckets[bucketIndex];

		while(head != NULL)
		{
			if(head->key == key)
			{
				displayStatus(key);
				return;
			}

			head = head->next;
		}

		head = buckets[bucketIndex];

		MapNode* node = new MapNode(key);

		if(head == NULL)
			buckets[bucketIndex] = node;

		else
		{
			while(head->next != NULL)
				head = head->next;
			head->next = node;
		}
		
		count++;

		double loadFactor = 1.0*count/numBuckets;
		if(loadFactor > upper_Load_Factor)
			rehash();
	}

private:
	void displayStatus(int key)
	{	
		cout << "Key " << key << " already present in the hash table. Status of the hash table." << endl;

		cout << "Number of keys: " << count << endl;
		cout << "Number of Buckets: " << numBuckets << endl;

		for(int i=0;i<numBuckets;i++)
		{	
			cout << "Bucket " << i << ":\t";
			MapNode *head = buckets[i];

			if(head == NULL)
			{
				cout << endl;
				continue;
			}

			while(head->next != NULL)
			{	
				cout << head->key << ", ";
				head = head->next;
			}

			cout << head->key << endl;
		}

		cout << endl;
	}
	
};


int main()
{
	cin >> upper_Load_Factor;

	int Bucket_Count;
	cin >> Bucket_Count;

	ourmap *mymap = new ourmap(Bucket_Count);

	int key;
	while(cin >> key)
	{
		mymap->insert(key);
	}


}