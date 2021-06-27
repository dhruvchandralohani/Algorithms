#include <iostream>
using namespace std;
int count=0;
void Merge(int A[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=A[l+i];
	for(j=0;j<n2;j++)
		R[j]=A[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
		count++;
	}
	while(i<n1)
	{
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k]=R[j];
		j++;
		k++;
	}
}
void MergeSort(int A[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		MergeSort(A,l,m);
		MergeSort(A,m+1,r);
		Merge(A,l,m,r);
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
	MergeSort(A,0,n-1);
	cout<<"\nSorted:";
	for(p=0;p<n;p++)
		cout<<A[p];
	cout<<"\nNumber of Comparisons:"<<count;
}
