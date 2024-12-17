//
// Created by nasr on 12/10/2024.
//
#include <stdio.h>
#include "Queue.c"
#include <string.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int col, int row)
{
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void MenuItems(int currentOption)
{
    char *menu[] = {"Add to Queue", "Get From Queue", "Exit"};
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    for (int i = 0; i < menuSize; i++)
    {
        gotoxy(5, 3 + i);
        if (i + 1 == currentOption)
        {
            printf("-> %s", menu[i]);
        }
        else
        {
            printf("   %s", menu[i]);
        }
    }
}
void AddToQueue()
{
    printf("Enter Student ID: ");
    int ID;
    scanf("%d", &ID);

    printf("Enter Student Name: ");
    char Name[50];
    scanf("%s", Name);

    int grades[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter Student Grade (%d): ", i + 1);
        scanf("%d", &grades[i]);
    }

    struct Student student;
    student.id = ID;
    strcpy(student.name, Name);
    memcpy(student.grades, grades, sizeof(grades));

   int isAdded =  enqueue(student);

   if (isAdded == 1) {
     printf("Student added to qeuue!\n");
   }else{
    printf("Sorry, Your Queue is Full");
   }

}

void PrintFromQueue()
{
    struct Student Data = dequeue();
    if (Data.id == -1)
    {
        printf("Your Queue is Empty ... \n");


    }
    else
    {
        printf("Student Name: %s \n", Data.name);
        printf("Student ID: %d \n", Data.id);

        for (int i =0; i < 3; i++)
        {
            printf("Student Grade at %d is %d \n",i+1,Data.grades[i]);
        }
    }

}
int main()
{
    int currentOption = 1;
    char key;

    while (key != 27)
    {
        system("cls");
        MenuItems(currentOption);

        key = getch();
        if (key == 72 && currentOption > 1) // Up
        {
            currentOption--;
        }
        else if (key == 80 && currentOption < 3) // Down
        {
            currentOption++;
        }
        else if (key == '\r') // Enter
        {
            system("cls");
            switch (currentOption)
            {
            case 1:
                AddToQueue();
                break;

            case 2:
                PrintFromQueue();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                break;
            }
            printf("\nPress any key to return to the menu...\n");
            getch();
        }
    }
    return 0;
};
