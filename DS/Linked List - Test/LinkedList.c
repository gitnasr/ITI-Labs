#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
  char name[50];
  int id;
  int grade;

};
struct Node {
  struct Student data;
  struct Node *next;
  struct Node *prev;
};
struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* create(int id, char name[], int grade);
void insert(int id, char name[], int grade, int position);
int AddNode(int id, char name[], int grade);

struct Node *search(int data);

struct Node* create(int id, char name[], int grade) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if (temp == NULL) {
    return NULL;
  }
  temp->data.id = id;
  strcpy(temp->data.name, name);
  temp->data.grade = grade;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}

int AddNode(int id, char name[], int grade) {
  int return_val = 0;
  struct Node* NewNode = create( id,  name,  grade);
  return_val = 1;
  if (head == NULL) {
      head = NewNode;
      tail = NewNode;
  }
  else {
    tail->next = NewNode;
   NewNode->prev = tail;
   tail = NewNode;

  }
  return return_val;
}

void insert(int id, char name[], int grade, int position) {
  //1. Find the position by index
  int return_val = 0;
  if (position == 0) {
      if (head == NULL) {
        AddNode(id, name, grade);
      }
      else {

        struct Node* NewNode = (struct Node *)malloc(sizeof(struct Node));
        NewNode->next = head;
        NewNode->prev = NULL;
        head = NewNode;
      }
  }else{
    struct Node* NewNode = (struct Node *)malloc(sizeof(struct Node));
    if (tail->next == NULL) {
      // Inserting at the end
      AddNode(id, name, grade);
    }else{
      struct Node* NewNode = (struct Node *)malloc(sizeof(struct Node));
      struct Node* curosr = head;
      for (int i = 0; i<position-1; i++) {
          if (curosr == NULL) {
            break;
          }
          curosr = curosr->next;
      }
      NewNode->prev = curosr;
      NewNode->next = curosr->next;
      curosr->next->prev = NewNode;
      curosr->next = NewNode;



    }

  }



}

struct Node* search(int id) {
  struct Node* temp = head;
  while (temp != NULL) {
    if (temp->data.id == id) {
      return temp;
    }
  }
};

int deleteNode(int location) {
    if (location == 0) {
      // 1. Changeing the Head
      if (head == NULL) {
        return 0;
      }
      else {
        if (head->next == NULL) {
        tail=  head = NULL;

        }
      }
    }
    else {
      struct Node* curosr = head;
      for (int i = 0; i<location; i++) {
          if (curosr->next == NULL) {
            return 0;
          }
          curosr = curosr->next;
      }
      if (curosr->next == NULL) {
        tail = curosr->prev;
        tail->next = NULL;
        return 1;
        }else{
          for (int i = 0; i<location; i++) {

            curosr->prev->next = curosr->next;
            curosr->next->prev = curosr->prev;
            free(curosr);
          }
        }

    }

};

void display() {
  struct Node* cursor = head;
  int id = 1;
  while (cursor != NULL) {
        printf("Displaying Student ID %d \n", id);
    printf("Sutdent ID: %d \n", cursor->data.id);
    printf("Name: %s \n", cursor->data.name);
    printf("Grade: %d \n", cursor->data.grade);

    cursor = cursor->next;
    id++;

    printf("----------------------- \n");
  }

}

