/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void swap(int* a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}



int partition (int arr[],int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1 );
    for (int j = low ; j  <= high -1 ; j++){
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        
    }
    swap(&arr[i+1],&arr[high]);
    return (i + 1);
}



void Quicksort( int a[], int p, int r) {
    
    if(p < r) {
        int q;
        q = partition(a,p,r);
        Quicksort(a,p,q-1);
        Quicksort(a,q+1,r);
    }
    
}
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
}


int main()
{
    int n;
    cout<<"Enter the size of array::";
    cin>>n;
    int randArray[n];
    for(int i=0;i<n;i++)
    randArray[i]=rand()%100; //Generate number between 0 to 99
    
    cout << "input array is ==>" <<endl;
    printArray(randArray,n);
    
    // after sorting 
    auto start1 = high_resolution_clock::now();
    Quicksort(randArray,0,n-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << duration1.count() <<"  microseconds taken for quick sort    "<< endl;
    cout << "sorted arry is =>>" <<endl;
    printArray(randArray,n);
    return 0;
}
