#include<iostream>
#include<algorithm>

	/*
		Array Rotation by Partition..
	*/

using namespace std;

#define M 10000000
int arr[M];

void RotateL(int noOfRotation,int SizeOfArray)
{
	
	noOfRotation%=SizeOfArray;
	int noOfSlots = __gcd(SizeOfArray,noOfRotation);
	int noOfElements = (SizeOfArray / noOfSlots);



	for(int i = 0;i<noOfSlots;i++)
	{
		int tmp = arr[i];
		int j=i;
		int k=0;
		while(1)
		{
			/*
				As We add nOfRotation to j at some point
				it will be  > SizeOfArray so take modulus 
				so that it will around back to valuwe of i.
				i.e start index of that slot...
			*/  
			k = (j+noOfRotation)%SizeOfArray;

			//break loop as we come to start index of slot.

			if(k==i)
				break;
			arr[j] = arr[k];
			j = k;
		}

		arr[j] = tmp;
	}

	for(int i=0;i<SizeOfArray;i++)
		cout<<arr[i]<<" ";
}


void RotateR(int noOfRotation,int SizeOfArray)
{
	int noOfSlots = __gcd(SizeOfArray,noOfRotation);
	int noOfElements = (SizeOfArray / noOfSlots);

	for(int i = 0;i<noOfSlots;i++)
	{
		int tmp;
		int j = i;
		int k = (j + noOfRotation)%SizeOfArray;;
		while(1)
		{
			tmp = arr[k];
			arr[k] = arr[j];
			arr[j] = tmp;
			j = k; 
			k = (j + noOfRotation)%SizeOfArray;
			if(k == i)
				break;
		}
	}

	for(int i=0;i<SizeOfArray;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int T;
	int N,R;

	cin>>T;
	while(T--)
	{
		cin>>N>>R;
		for(int i =0;i<N;i++)
			cin>>arr[i];
		RotateR(R,N);
		cout<<"\n";
	}

	return 0;
}