#include <stdio.h>

int binarysearch(int arr[], int high, int low, int tbf)
{
    
    while(low <= high){
        
        int mid = low+(high-low);
        
        if(arr[mid]==tbf){return mid;}

        else if(arr[mid]>tbf){
            low = mid+1;
            // mid = (low+high)/2; // tbf to be found integer
            // printf("IN THE ELSE IF STATEMENT THIS IS THE VALUE OF LOW MID AND HIGH %d %d %d \n",low,mid,high);
        }
        else if(arr[mid] < tbf){
            high = mid - 1;
            // mid = (low+high)/2;
        }
    }
}

int main()
{
    int arrsize, high, low, tbf;
    printf("Enter the size of array you want to create\n");
    scanf("%d", &arrsize);

    high = arrsize - 1;
    low = 0;
    int arr[arrsize];

    for (int i = 0; i < arrsize; i++)
    {
        printf("Enter number at index %d\n", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be found out\n");
    scanf("%d", &tbf);

    int result= binarysearch(arr, high, low, tbf);
    printf("Found at %d",result);

    return 0;
}
