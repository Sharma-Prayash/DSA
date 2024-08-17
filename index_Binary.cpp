#include<iostream>
using namespace std;
class Binary{
	public:
		int sorting(int arr[], int n){
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					if(arr[j]>arr[j+1])
					{
						arr[j]=arr[j]+arr[j+1];
						arr[j+1]=arr[j]-arr[j+1];
						arr[j]=arr[j]-arr[j+1];
					}
				}
			}
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		int Index(int arr[], int n, int t, int p)
		{
			int start=0, end=n-1;
			while(start<=end)
			{
				int mid=start+((end-start)/2);
				if (arr[mid]==t && p==0)
				{
					if(arr[mid-1]==t && mid!=0)
						end=mid-1;
					else
						return mid;
				}
				else if (arr[mid]==t && p==1)
				{
					if(arr[mid+1]==t && mid!=n-1)
						start=mid+1;
					else
						return mid;
				}
				if(t>arr[mid])
					start=mid + 1;
				else if(t<arr[mid])
					end=mid - 1;				
			}
			return -1;
		}
};
int main(){
	Binary obj;
	int n, first=-1, last=-1, start, end, mid, target;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	obj.sorting(arr,n);
	cout<<"Enter the target number: ";
	cin>>target;
	first = obj.Index(arr, n, target, 0);
	last = obj.Index(arr, n, target, 1);
	if(first==-1 && last==-1)
		cout<<"Element not present";
	else
		cout<<"The lower and the upper limit of the element are: ("<<first<<","<<last<<")";
}
