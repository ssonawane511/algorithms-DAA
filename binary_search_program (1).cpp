#include <bits/stdc++.h> 
using namespace std;

 
 
int
binarySearch (int arr[], int l, int r, int searchELE) 
{
  
if (r >= l)
    {
      
int mid = l + (r - l) / 2;
      
 
 
if (arr[mid] == searchELE)
	
return mid;
      
 
 
if (arr[mid] > searchELE)
	
return binarySearch (arr, l, mid - 1, searchELE);
      
 
 
return binarySearch (arr, mid + 1, r, searchELE);
    
}
  
 
 
return -1;

}


 
int
main (void) 
{
  
int arr[100];
  
int x;
  
int n;
  
 
cout << "how may element you want to enter";
  
cin >> n;
  
cout << "enter elements in non decreasing order please  ";
  
for (int i = 0; i < n; i++)
    {
      
cin >> arr[i];
    
} 
 
cout << "your entered elements are >>" << endl;
  
for (int i = 0; i < n; i++)
    {
      
cout << arr[i] << endl;
    
 
} 
 
cout << "what element you want  to search";
  
int searchELE;
  
cin >> searchELE;
  
 
int result = binarySearch (arr, 0, n - 1, searchELE);
  
(result == -1) ? cout << "Element is not present in array" 
    : cout << "Element is present at index " << result;
  
return 0;

}
