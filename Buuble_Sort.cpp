// Bubble sort in C++

#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int nums[], int size) {

  // loop to access each nums element
  for (int step = 0; step < size; ++step) {
      
    // loop to compare nums elements
    for (int i = 0; i < size - step; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (nums[i] > nums[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;
      }
    }
  }
}

// print nums
void printnums(int nums[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << nums[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-21, 45, 10, 11, -9};
  
  // find nums's length
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Sorted nums in Ascending Order:\n";  
  printnums(data, size);
}
