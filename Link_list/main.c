#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* root =NULL;
int len;
void APPEND(void);
void ADDatBegin (void);
void ADDatafter(void);
int Length(void);
void Display(void);
void Delete(void);
int main(){
    int ch;
    while(1){
        printf("SINGLE LIN0KEDLIST operation :- \n");
        printf("1. APPEND: \n");
        printf("2. ADDatBegin: \n");
        printf("3. ADDatafter : \n");
        printf("4. Length : \n");
        printf("5. Display : \n");
        printf("6. Delete : \n");
        printf("7. Quit : \n");
        
        printf("Enter your choices: \n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1 : APPEND();
            break;
            case 2 : ADDatBegin();
            break;
            case 3 : ADDatafter();
            break;
            case 4 : len=Length();
            printf("Length %d \n\n :",len);
            break;
            case 5 : Display();
            break;
            case 6 : Delete();
            break;
            
            default : printf("invalid input: \n\n");
            
            
            
        }
        
    }
     
}
void APPEND(){
    struct node* temp;
    temp=(struct node*)(malloc(sizeof (struct node*)));
    printf("enter the node value: \n");
    scanf("%d",&temp->data);
    temp->link=NULL;   
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
      struct node* p;
      p=root;
      while(p->link != NULL);
      {
          p = p->link;
          p->link = temp;
          
      }
      
    }
}
int Length()

{
    struct node* temp;
    int count =0;
    temp=root;
    
    while(temp != NULL)
    {
      count++;
      temp = temp->data;
    }
    return count;
}
void Display()
{
    struct node* temp;
    temp=root;
    if (temp == NULL)
    {
        printf("list is Empty \n\n : ");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->link;
        }
        printf("\n\n");
    }
    
}
void ADDatBegin (void)
{
    
}
void ADDatafter(void)
{
    
}
void Delete(void)
{
    
}