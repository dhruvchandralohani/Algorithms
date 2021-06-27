#include <iostream>
using namespace std;
void CountingSort(int *a1,int n)
{
	int i,x,min=a1[0],max=a1[0];
	for(i=0;i<n;i++)
	{
		if(a1[i]<min)
			min=a1[i];
		if(a1[i]>max)
			max=a1[i];
	}
	cout<<"\nMin:"<<min<<" Max:"<<max;
	int a2[(max-min)+1]={0};
	for(i=0;i<n;i++)
		a2[a1[i]-min]=1;
	int a3[(max-min)+1]={0};
	for(i=0;i<n;i++)
	{
		if(i==0)
			a3[i]=a2[i];
		else
			a3[i]=a2[i]+a2[i-1];
	}
	int a4[n];
	for(i=0;i<n;i++)
	{
		x=a3[a1[i]-min];
		a4[x-1]=a1[i];
	}
	cout<<"\nSorted:";
	for(i=0;i<n;i++)
		cout<<a4[i];
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
	CountingSort(A,n);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
}
