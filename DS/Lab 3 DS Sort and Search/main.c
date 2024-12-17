//
// Created by nasr on 12/11/2024.
//

#include "SortAndSearch.c"

#include <stdio.h>


struct student TakeInput() {
  struct student std;
  printf("Enter Student ID: \n");
  scanf("%d", &std.id);
  printf("Enter Student Name: \n");
  scanf("%s", std.name);
  for (int i = 0; i < 3; i++) {
    printf("Enter Student Grade (%d) :\n", i + 1);
    scanf("%d", &std.grades[i]);
  }
  return std;
}

void PrintMyArray(struct student Students[]) {
  for (int i = 0; i < 5; i++) {
    printf(" id -> %d \n", Students[i].id);
    printf(" Name -> %s \n", Students[i].name);
  }
}
void initialize_students_hardcoded(struct student Students[]) {
  // Hardcoded student data for development
  struct student hardcoded_students[5] = {
    {5, {85, 90, 95}, "John Doe"},
    {6, {75, 80, 85}, "Jane Smith"},
    {12, {90, 92, 88}, "Mike Johnson"},
    {1, {65, 70, 75}, "Sarah Williams"},
    {3, {95, 97, 93}, "Emily Brown"}
  };

  // Copy hardcoded data to the input array
  for (int i = 0; i < 5; i++) {
    Students[i] = hardcoded_students[i];
  }
}

int main() {
  struct student Students[5];
  for (int i = 0; i < 5; i++) {
    Students[i] = TakeInput();
  }

  // MergeSort(Students, 0, 4);
  BubbleSort(Students,5);

  int isFound = BinarySearch(Students,8,0,4);
  if (isFound == -1) {
    printf("Student not found\n");

  }else {
    printf("Student found at position %d\n",isFound);
  }
  PrintMyArray(Students);

  return 0;
}
