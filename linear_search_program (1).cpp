#include <iostream> 
using namespace std; 
  
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
// Driver code 
int main(void) 
{ 
    int arr[100] ; 
    int x ; 
    int n ; 
    
    cout << "how may element you want to enter";
    cin >> n ; 
    cout << "enter elements please ";
    for(int i= 0 ; i< n ; i++){
        cin >> arr[i];
    }
    cout << "your entered elements are >>"<<endl;
    for ( int i= 0 ; i< n ; i++) {
        cout << arr[i] << endl;
    }
    
    cout << "what element you want  to search";
    int searchELE;
    cin >> searchELE ;
    
    // Function call 
    int result = search(arr, n, searchELE);
    (result == -1) 
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result; 
    return 0; 
}