//
// Created by Nasr on 12/9/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // For _getch()
#include <windows.h>  // For gotoxy functionality

// Function to set the cursor position in the console
void gotoxy(int col, int row) {
  COORD coord;
  coord.X = col;
  coord.Y = row;
  SetConsoleCursorPosition(
      GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function prototypes
void MenuItems();
void MoveInMenu();

void MenuItems() {
  // Print menu items
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
  printf("7. Quit");
}

void MoveInMenu() {
  int currentOption = 1;  // Start at the first option
  char key;

  while (1) {
    system("cls");  // Clear the console screen
    MenuItems();

    // Highlight the current option
    for (int i = 3; i <= 9; i++) {
      gotoxy(3, i);
      if (i == currentOption + 2) {
        printf("->");  // Arrow to highlight the option
      } else {
        printf("  ");  // Blank spaces to align the menu
      }
    }

    key = _getch();  // Get keyboard input

    if (key == 72 && currentOption > 1) {  // Up arrow key
      currentOption--;
    } else if (key == 80 && currentOption < 7) {  // Down arrow key
      currentOption++;
    } else if (key == '\r') {  // Enter key
      gotoxy(5, 11);
      printf("You selected option %d\n", currentOption);
      if (currentOption == 7) {
        exit(0);  // Exit the program
      }
      system("pause");
    }
  }
}


int count = 0;
printf("Enter the number of students: ");
scanf("%d", &count);
for (int i = 0; i < count; i++) {
  int grade;
  char name[50];
  printf("Enter student %d name: ", i+1);
  scanf("%s", name);
  printf("Enter student %d grade: ", i+1);
  scanf("%d", &grade);

  AddNode(i, name, grade);

}
display();