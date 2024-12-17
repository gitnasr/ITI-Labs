#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct Student {
  char name[50];
  int id;
  int grade;

};
// Declare your LinkedList functions here
void addNode();
int deleteNode();
void printList();
void destroyList();
struct Student findById(int studentId);
struct Student findByName(char studentName[50]);
int insertByPos(int id, char name[50], int grade, int pos );
#endif
