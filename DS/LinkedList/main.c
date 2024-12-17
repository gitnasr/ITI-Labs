#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "LinkedList.h"
void gotoxy(int col, int row)
{
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MenuItems();
void MoveInMenu();

void MenuItems()
{
    gotoxy(5, 2);
    printf("Menu Items:");
    gotoxy(5, 3);
    printf("1. Add New");
    gotoxy(5, 4);
    printf("2. Delete");
    gotoxy(5, 5);
    printf("3. Print");
    gotoxy(5, 6);
    printf("4. Insert At Position");
    gotoxy(5, 7);
    printf("5. Find By ID");
    gotoxy(5, 8);
    printf("6. Find By Name");
    gotoxy(5, 9);
    printf("7. Destroy List");
    gotoxy(5, 10);
    printf("8. Quit");
}



void AddItemsByCountAtEnd()
{
    int count = 0;
    printf("Enter the number of students: ");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        int grade;
        char name[50];
        int id;

        printf("Enter student %d name: ", i+1);
        scanf("%s", name);
        printf("Enter student %d grade: ", i+1);
        scanf("%d", &grade);
        printf("Enter Student ID: ");
        scanf("%d", &id);

        AddNode(id, name, grade);

    }
    printf("Nodes Added Successfully ... \n");
}

void addAtLocation()
{
    char name[50];
    int id, location, grade;

    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter student grade: ");
    scanf("%d", &grade);
    printf("Enter Student ID: ");
    scanf("%d", &id);

    printf("Enter Desired Location of new Item: ");
    scanf("%d", &location);

    insertByPos(id,name,grade,location);


}

void DeleteByLocation()
{
    int location = 0;
    printf("Enter Location to Delete :");
    scanf("%d", &location);

    int DeleteResult =  deleteNode(location);

    if (DeleteResult == 1)
    {
        printf("Node Found and Deleted Successfully .. \n");
    }
    else
    {
        printf("Error while Deleting... You Went out of boundries \n");
    }
}
void SearchById()
{
    int id=0;
    printf("Enter ID to Get :");
    scanf("%d", &id);

    struct Student Result = findById(id);

    if (Result.id == -1)
    {
        printf("ID Not Found \n");
    }
    else
    {
        printf("Student Found !! \n");
        printf("Student ID: %d \n", Result.id);
        printf("Student Name: %s \n", Result.name);
        printf("Student Grade: %d \n", Result.grade);

    }

};
void SearchByName()
{
    printf("Enter Name to Get :");
    char name[50];
    scanf("%s",name);


    struct Student Result = findByName(name);
    if (Result.id == -1)
    {
        printf("Student Not Found \n");
    }
    else
    {
        printf("Student Found !! \n");
        printf("Student ID: %d \n", Result.id);
        printf("Student Name: %s \n", Result.name);
        printf("Student Grade: %d \n", Result.grade);

    }


}

void DeleteAll() {
  int result =  Destroy();
  if (result ==1){
    printf("The List has been destroyed sucessfully \n");
  }else{
  printf("List does NOT exist to Destroy! \n");
  }
}


int main()
{
    int currentOption = 1;
    char key;

    while (1)
    {
        system("cls");
        MenuItems();

        for (int i = 3; i <= 10; i++)
        {
            gotoxy(3, i);
            if (i == currentOption + 2)
            {
                printf("->");
            }
            else
            {
                printf("  ");
            }
        }

        key = getch();
        if (key == 72 && currentOption > 1)
        {
            currentOption--;
        }
        else if (key == 80 && currentOption < 8)
        {
            currentOption++;
        }
        else if (key == '\r')
        {
            gotoxy(0, 13);
            switch (currentOption)
            {

            case 1:

                AddItemsByCountAtEnd();
                break;
            case 2:
                DeleteByLocation();
                break;
            case 3:

                display();
                break;

            case 5:
                SearchById();
                break;
            case 6:
                SearchByName();
                break;
            case 4:
                addAtLocation();
                break;
            case 7:
                DeleteAll();
                break;
            }

            if (currentOption == 8)
            {
                exit(0);
            }
            system("pause");
        }
    }
}
