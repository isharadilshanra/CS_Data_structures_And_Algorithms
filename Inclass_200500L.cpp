#include <iostream>
#include <chrono> //to mesure the time for execution

#include <cstdlib>// for randome arrays
#include <ctime>
#include <vector>
#include <stack>

using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n-1; i++) { //increse the length of sorted array
        minIndex = i;
        for (j = i+1; j < n; j++) {
          //find the index of minimum value 
            if (arr[minIndex]>arr[j]) {
                minIndex = j;
            }
        }
        // swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> merged_arr(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            merged_arr[k] = arr[i];
            i++;
        } else {
            merged_arr[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        merged_arr[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= high) {
        merged_arr[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = low; i <= high; i++) {
        arr[i] = merged_arr[i - low];
    }
}

void merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    
    int mid = low + (high - low) / 2;
    
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    
    merge(arr, low, mid, high);
}


void insSort( int arr[], int n){
  int i,hole,val;
    for ( i = 1; i < n; i++){
      hole=i;
      val=arr[i];
      while((val< arr[hole-1])&&(hole>=0)){
        arr[hole]=arr[hole-1];
        hole--;
      }
    arr[hole] =val;
    //i++;
    }
    
}

void bubleSort(int arr[], int n){
  int i,j,temp;
  for  (i = 0; i < n; i++){
    for (j = 0; j < n-1; j++){
      if (arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    
  }
  
}

void bubleSortOp(int arr[], int n){
  int i,j,temp;
  for  (i = 0; i < n; i++){
    for (j = 0; j < n-i-1; j++){
      if (arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    
  }
  
}



void quickSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int pivot = arr[n-1];
    int i = -1;

    for (int j = 0; j < n-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = pivot;
    arr[n-1] = temp;

    quickSort(arr, i+1);
    quickSort(arr+i+1, n-i-1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  /*
    srand(time(NULL)); // Seed the random number generator with the current time
    int n=0;
    for (int i = 0; i < 5; i++) {
    auto start = high_resolution_clock::now();
    
        // Generate a random length between 5000 and 20000
         n = n+ 5000; 
        // Dynamically allocate an array of the chosen length
        int* arr = new int[n]; 
        
        // Fill the array with random integers between -10 and 10
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 20 - 10;
        }
        quickSort(arr,n);
        //bubleSortOp(arr, n);
        //return 0;
        
        //delete[] arr; // Deallocate the memory used by the array
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by code (Quick_sort_Recursive): " << duration.count() << " MilliSeconds _________"<<"number of elements : "<< n << endl;
    } 

    //////////////////////////////////////////////////////////////////
    cout << endl;
    int n1=0;
    for (int i = 0; i < 5; i++) {
    auto start1 = high_resolution_clock::now();
    
        // Generate a random length between 5000 and 20000
         n1 = n1 + 5000; 
        // Dynamically allocate an array of the chosen length
        int* arr = new int[n1]; 
        
        // Fill the array with random integers between -10 and 10
        for (int j = 0; j < n1; j++) {
            arr[j] = rand() % 20 - 10;
        }
        quickSortIter(arr, 0,n1-1);
        //return 0;
        
        //delete[] arr; // Deallocate the memory used by the array
    
    auto stop1 = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop1 - start1);
    cout << "Time taken by code (quick_Sort_Iterative): " << duration.count() << " MilliSeconds _________"<<"number of elements : "<< n1 << endl;
    } 
    //////////////////////////////////////////////////////////////////
    */
    
    
    int n=0;
    cout << "enter length of array : " ;
    cin>>n;
    cout << "Enter " << n << " integers:" << endl;
    int array[n];
    //cout << "Enter " << size << " integers:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        
        insSort( array, i+1);
    if ((i+1)%2==1){
      cout << "new median " ;
      cout<<array[(i+1)/2]<<endl;

    }
    // else if(i==0){
    //   cout << "new median " ;
    //   cout<<array[n/2]<<endl; 
    //}
    else{
      double mid=0.0;
      mid=(array[(((i+1))/2)-1]+array[(((i+1))/2)])*0.5;
      cout << "new median " ;
      cout<<mid<<endl;
    }
        
    }

    
}
