//
// Created by nasr on 12/10/2024.
//

#include <stdio.h>

#include <stdlib.h>

#define QUEUE_SIZE 3
struct Student
{
    char name[10];
    int id;
    int grades[QUEUE_SIZE];
};

int Current = 0;



struct Student Queue[3];

int enqueue(struct Student item)
{
    int added = 0;
      if (Current < 3)
    {

        Queue[Current] = item;
        Current++;
        added = 1;
    }

    return added;

}
struct Student dequeue()
{

    struct Student removedItem;
    if (Current == 0)
    {
        removedItem.id = -1;
    }

    if (Current > 0)
    {
        // Return first item
        removedItem = Queue[0];



        for (int i = 0; i < Current - 1; i++)
        {
            Queue[i] = Queue[i + 1];
        }

        Current--;
    }



    return removedItem;




}
