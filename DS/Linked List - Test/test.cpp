//
// Created by nasr on 12/9/2024.
//
struct Data{
      int id;
      float grades;
      char name[20];

 };
 struct Node{
struct Data data;
struct Node* prev;
struct Node* next;

};
struct Node* head;
struct Node* tail;
struct Node* createNode(int id,char name[],float grades){
   struct Node* ptr;
   ptr=(struct Node*)malloc(sizeof(struct Node));
   if(ptr!=NULL){
    ptr->data.id=id;
    ptr->data.grades=grades;
    strcpy(ptr->data.name,name);
   }
   return ptr;
}
int insertFront(int id,char name[],float grades){
     int flag=0;
   struct Node* ptr=createNode(id,name,grades);
   if(ptr){
        flag=1;
       if(head==NULL){
        head=tail=ptr;
       }
       else{
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
       }

   }
   return flag;

}
int insertRear(int id,char name[],float grades){
  int flag=0;
   struct Node* ptr=createNode(id,name,grades);
   if(ptr){
     if(head==NULL|| head==tail && head==NULL){
        head=tail=ptr;
       }
   else{
    tail->next=ptr;
    ptr->prev=tail;
    tail=ptr;
   }

   }
   return flag;
}
int insertMiddle(int id,char name[],float grades, int location){
  int flag=0;
   struct Node* temp=head;
   struct Node* ptr=createNode(id,name,grades);
   if(ptr){
        flag=1;
    if(location==0){
        insertFront(id,name,grades);
    }
   else{
       for(int i=0;i<location-1 && temp==NULL;i++){
        temp=temp->next;
       }
       if(temp->next==NULL){
        insertRear(id,name,grades);
       }
       else{
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next->prev=ptr;
        temp->next=ptr;
       }
   }

   }
   return flag;
}
int deleteFront(){
    if(head!=NULL){
        head->next->prev=NULL;
        head=head->next;
    }
    return 1;
}
int deleteRear(){
    if(head!=NULL){
    tail->prev->next=NULL;
    tail=tail->prev;}
    return 1;

 }
int deletel(int location){
    if(location==0){
        deleteFront();
    }
    else{
        struct Node* temp=head;
        for(int i=0;i<location&&temp!=NULL;i++){
        temp=temp->next;
       }
        if(temp->next==NULL){
        deleteRear();
        }
        else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;}

    }
    return 1;
}
void printing(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("name: %s ,id: %d,grade: %f \n",temp->data.name,temp->data.id,temp->data.grades);
        temp=temp->next;
    }
}

int main()
{
   insertFront(1, "Alice", 89.5);
    insertRear(2, "Bob", 92.0);
    insertRear(3,"ahmed",50);
    insertRear(4,"noha",49.5);
    insertRear(5,"afadi",50);
   // insertMiddle(,"mimi",60,2);
    deletel(3);
   //deleteRear();
    printing(head);

    return 0;
}