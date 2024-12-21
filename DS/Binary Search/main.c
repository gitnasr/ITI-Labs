#include <stdio.h>

int find(int *arr, int count, int target);
int main()
{
    int test[] = {
         0, 1, 3, 4, 5, 6, 8, 9, 23, 64, 90, 245, 300};
    int n = sizeof(test) / sizeof(int);
    int location = find(test, n, 9);
    printf("Location: %d, Item: %d", location, test[location]);
    return 0;
}

int find(int *arr, int count, int target)
{
    int mid = count / 2;
    int start = 0;
    int end = count -1 ;
    int location = -1;
    while (start <= end)
    {
        int mid = (start+end)/2;
          if (arr[mid] == target)
        {
            location = mid;
            return location;
        }
        if (arr[mid] < target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
   return location;
}