#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
void partition(int *A, int lo, int hi, int &i, int &j){
    if (hi - lo <=1)
    {
        if (A[hi] < A[lo]){
            swap(A[hi], A[lo]);
        }
        i=lo;
        j=hi;
        return;
    }
    int mid=lo;
    int pivot=A[hi];
    while (mid<=hi){
        if (A[mid]<pivot)
            swap(A[lo++], A[mid++]);
        else if (A[mid] == pivot)
            mid++;
        else if (A[mid]>pivot)
            swap(A[mid], A[hi--]);
        }
        i=lo-1;
        j=mid;
}
void quicksort(int *A, int lo, int hi){
    if(lo>=hi){
            return;
    }
    int i, j;
        partition(A, lo, hi, i, j);
        quicksort(A, lo, i);
        quicksort(A, j, hi);
}
int main()
{
    int n;
    cout<<"Size of array: ";
    cin>>n;
int arr[n];
for (int i=0; i<sizeof(arr)/sizeof(int); i++)

{
    arr[i]=rand()%100+1;
}
for(int i=0; i<sizeof(arr)/sizeof(int); i++){
  cout<<arr[i]<<" ";
}
quicksort(arr, 0, n-1);
cout<<"\nSorted array: ";
for(int i=0; i<sizeof(arr)/sizeof(int); i++){
  cout<<arr[i]<<" ";
}
return 0;
}

