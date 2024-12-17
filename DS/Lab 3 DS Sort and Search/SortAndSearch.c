//
// Created by nasr on 12/11/2024.
//

#include <stdio.h>

struct student {
    int id;
    int grades[3];
    char name[20];
};

void BubbleSort(struct student Students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Students[j].id > Students[j + 1].id) {
                struct student temp = Students[j];
                Students[j] = Students[j + 1];
                Students[j + 1] = temp;
            }
        }
    }
}


void Merge(struct student Students[], int low, int mid, int high) {
    struct student temp[5];
    int list1 = low, list2 = mid + 1, i = 0;

    while (list1 <= mid && list2 <= high) {
        if (Students[list1].id <= Students[list2].id) {
            temp[i] = Students[list1];
            i++;
            list1++;
        } else {
            temp[i] = Students[list2];
            i++;
            list2++;
        }
    }

    while (list1 <= mid) {
        temp[i] = Students[list1];
        i++;
        list1++;
    }
    while (list2 <= high) {
        temp[i] = Students[list2];
        i++;
        list2++;
    }

    for (i = 0; i < high - low + 1; i++) {
        Students[low + i] = temp[i];
    }
}


void MergeSort(struct student Students[],int LB,int UB)
{
    int middle;

    if(LB < UB)
    {
        middle = (LB + UB)/2;
        MergeSort(Students,LB,middle);
        MergeSort(Students,middle + 1,UB);
        Merge(Students,LB,middle,UB);
    }
}

int BinarySearch(struct student arr[],int key,int lb, int ub){

    int loc=-1;
    while(lb<=ub &&loc==-1){
        int mid =(lb+ub)/2;

        if(arr[mid].id==key){
            loc=mid;
        }
        else if(arr[mid].id>key){
            ub=mid-1;

        }
        else{
            lb=mid+1;
        }
    }
    return loc;
}