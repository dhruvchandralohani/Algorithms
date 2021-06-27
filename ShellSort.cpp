#include <iostream>
using namespace std;
int count=0;
void ShellSort(int A[], int n)
{
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i++)
		{
			int temp=A[i];
			int j;
			for(j=i;j>=gap && A[j-gap]>temp;j-=gap)
			{
				A[j]=A[j-gap];
				count++;
			}
			A[j]=temp;
		}
	}
}
int main()
{
	int n,p,*A;
	cout<<"Enter no. of elements:";
	cin>>n;
	A=new int[n];
	cout<<"\nEnter Elements:"<<endl;
	for(p=0;p<n;p++)
		cin>>A[p];
	ShellSort(A,n);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
	cout<<"\nCount:"<<count;
}
