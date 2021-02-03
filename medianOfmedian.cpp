#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

// selects the median of medians in an array
int select(int *arr, int start, int end, int midleIndex){
    // if the partition length is less than or equal to 5
    // we can sort and find the kth element of it
    // this way we can find the median of n/5 partitions
    if(end-start+1 <= 5){
        cout << "here we cant partitions the array in 5 as the size is less than 5" << endl;
        cout << "start as " << start <<endl;
        cout << "end as " << end <<endl;
        cout << "middle index" << midleIndex-1 <<endl ;
        sort(arr+start, arr+end);
        cout << start+midleIndex-1<<endl;
        return start+midleIndex-1;
    }
    
    // if array is bigger 
    // we partition the array in subarrays of size 5
    // no. of partitions = n/5 = (e+1)/5
    // iterate through each partition
    // and recursively calculate the median of all of them
    // and keep putting the medians in the starting of the array
    for(int i=0; i<(end+1)/5; i++){
        cout << "*********************"<<endl<<endl;
        cout << "here is ths partion number " << i + 1 <<endl; 
        int left = 5*i;
        cout << "our left is "<< left <<endl;
        int right = left + 4;
        cout << "right is " << right <<endl;
        
        if(right > end) {
            right = end;
            cout << "right is greater that end coz of +4 so right == " << right <<endl;
        };
        
        
        int median = select(arr, 5*i, 5*i+4, 3);
        cout << "recursively callled again select method " << endl;
        cout << "start as " << 5*i <<  "   end as " << 5*i+4 <<endl;
        cout << "we get the median of this partion as " << median <<endl;
        swap(arr[median], arr[i]);
    }
    
    // now we have array 
    // a[0] = median of 1st 5 sized partition
    // a[1] = median of 2nd 5 sized partition
    // and so on till n/5
    // to find out the median of these n/5 medians
    // we need to select the n/10th element of this set (i.e. middle of it)
    return select(arr, 0, (end+1)/5, (end+1)/10);
}

int main(){
    int a[] = {6,7,8,1,2,3,4,5,9,10};
    int n = 10;
    
    int mom = select(a, 0, n-1, n/2);
    cout<<"Median of Medians: " << a[mom] << endl;
    return 0;
}