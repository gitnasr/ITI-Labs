#include <string.h>

struct Student
{
    char name[50];
    int id;
    int grades[3];

};
struct Node
{
    struct Student data;
    struct Node *prev;

};


struct Node *tail = NULL;




struct Node* create(struct Student student)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return NULL;
    }
    temp->data.id = student.id;
    strcpy(temp->data.name, student.name);
    memcpy(temp->data.grades, student.grades, sizeof(student.grades));
    temp->prev = NULL;

    return temp;
}
int addToStack(struct Student studentData)
{
    struct Node * NewNode = create( studentData);
    int added = 0;

    if (NewNode)
    {

        if (tail == NULL)
        {


            tail = NewNode;


        }
        else
        {
            NewNode->prev = tail;
            tail = NewNode;

        }
        added = 1;

    }

    return added;

}


struct Student getData()
{
    struct Node * temp = tail;


    struct Student student;

    if (temp)
    {
        student = temp->data;
        tail = tail->prev;
        free(temp);
    }
    else
    {
        student.id = -1;
    }

    return student;
}


struct Student RetriveFromStack()
{
    struct Node * temp = tail;
    struct Student DataToReturn;

    if (temp)
    {

        DataToReturn = temp->data;

        tail = tail->prev;


    }else{
    DataToReturn.id = -1;
    }

    return DataToReturn;
}
