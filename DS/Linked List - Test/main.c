//
// Created by Nasr on 12/9/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "LinkedList.c"
// Function to set the cursor position in the console
void gotoxy(int col, int row) {
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MenuItems();
void MoveInMenu();

void MenuItems() {
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

void MoveInMenu() {

}


int main() {
    int currentOption = 1;
    char key;

    while (1) {
        system("cls");
        MenuItems();

        for (int i = 3; i <= 10; i++) {
            gotoxy(3, i);
            if (i == currentOption + 2) {
                printf("->");
            } else {
                printf("  ");
            }
        }

        key = getch();
        if (key == 72 && currentOption > 1) {
            currentOption--;
        } else if (key == 80 && currentOption < 8) {
            currentOption++;
        } else if (key == '\r') {
            gotoxy(5, 11);
            switch (currentOption){
                case 1:
                    printf("Chhoise");
                default:
                    printf("CCC");

            }

            if (currentOption == 8) {
                exit(0);  // Exit the program
            }
            system("pause");
        }
    }
}
