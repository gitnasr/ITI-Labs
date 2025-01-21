#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int id;
    int grade;

};
struct Node
{
    struct Student data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
struct Node *tail = NULL;

struct Node* create(int id, char name[], int grade);
void insert(int id, char name[], int grade, int position);
int AddNode(int id, char name[], int grade);

struct Student findById(int studentId);

struct Node* create(int id, char name[], int grade)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return NULL;
    }
    temp->data.id = id;
    strcpy(temp->data.name, name);
    temp->data.grade = grade;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

int AddNode(int id, char name[], int grade)
{
    int return_val = 0;
    struct Node* NewNode = create( id,  name,  grade);
    return_val = 1;
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;

    }
    return return_val;
}

int insertByPos(int id, char name[], int grade, int position)
{
    // Case 1: Insert at the beginning (position 0)
    if (position == 0)
    {
        struct Node* NewNode = create(id, name, grade);
        if (head == NULL)
        {
            head = NewNode;
            tail = NewNode;
        }
        else
        {
            NewNode->next = head;
            head->prev = NewNode;
            head = NewNode;
        }
        return 1;
    }

    // Case 2: Insert in the middle or end
    struct Node* cursor = head;
    int current_position = 0;

    while (cursor != NULL && current_position < position - 1)
    {
        cursor = cursor->next;
        current_position++;
    }

    if (cursor == NULL)
    {
        return AddNode(id, name, grade);
    }

    struct Node* NewNode = create(id, name, grade);

    if (cursor->next == NULL)
    {
        cursor->next = NewNode;
        NewNode->prev = cursor;
        tail = NewNode;
    }
    else
    {
        // Insert in the middle
        NewNode->next = cursor->next;
        NewNode->prev = cursor;
        cursor->next->prev = NewNode;
        cursor->next = NewNode;
    }

    return 1;
}
struct Student findById(int id)
{
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            return temp->data;
        }
        temp = temp->next;
    }

    struct Student notFound = {"", -1, -1};
    return notFound;
}




int deleteNode(int location)
{

    if (head == NULL)
    {
        return 0;
    }

    if (location == 0)
    {
        struct Node* temp = head;
        if (head->next == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        free(temp);
        return 1;
    }

    struct Node* cursor = head;
    for (int i = 0; i < location; i++)
    {
        if (cursor->next == NULL)
        {
            return 0;
        }
        cursor = cursor->next;
    }


    if (cursor->next == NULL)   // Last node
    {
        tail = cursor->prev;
        tail->next = NULL;
    }
    else     // Middle node
    {
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
    }

    free(cursor); // Free the memory
    return 1;
};

struct Student findByName(char name[50])
{
    struct Node* temp = head;
    struct Student search = {"",-1,-1};

    while (temp != NULL)
    {
        if (strcmp(temp->data.name, name) == 0)
        {
            search = temp->data;
            break;
        }
        temp = temp->next;
    }

    return search;
};

void display()
{
    struct Node* cursor = head;
    int id = 1;
    while (cursor != NULL)
    {
        printf("Displaying Student ID %d \n", id);
        printf("Student ID: %d \n", cursor->data.id);
        printf("Name: %s \n", cursor->data.name);
        printf("Grade: %d \n", cursor->data.grade);

        cursor = cursor->next;
        id++;

        printf("----------------------- \n");
    }

}

int Destroy()
{

    int return_status = 0;

    if (head == NULL){
      return  return_status ;
    }

    struct Node* curosr = head;

    while(curosr != NULL)
    {
        free(curosr);
        curosr = curosr->next;
    }

    head = NULL;
    tail=NULL;
    return_status = 1;
    return return_status;
}


int main()