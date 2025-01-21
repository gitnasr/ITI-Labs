//
// Created by nasr on 12/10/2024.
//

#include <stdio.h>

#include <stdlib.h>

#define QUEUE_SIZE 64
int Queue[QUEUE_SIZE];
int Current = 0;

int enqueue(int q)
{
    int added = 0;
    if (Current < QUEUE_SIZE)
    {

        Queue[Current] = q;
        Current++;
        added = 1;
    }

    return added;
}
int dequeue()
{

    int removedItem;
    if (Current == 0)
    {
        removedItem = -1;
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
int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

   while (Current > 0)
   {
   int element = dequeue();
        if (element %2 != 0) { 
                printf("%d", element);
        }
   }
   

}