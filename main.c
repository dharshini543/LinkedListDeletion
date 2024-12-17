#include <stdio.h>
#include <stdlib.h>

enum returnvalue
{
    Failure = 0,
    Success
};

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(struct node *head)
{
    struct node *newnode, *temp;
    int choice,count = 0;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return Failure;
        }
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != 0)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        ++count;
        printf("Want to continue... press 1 else 0\n");
        scanf("%d",&choice);
    }
    return head;
}

int displayList(struct node *head)
{
    struct node *temp = head;
    if(temp == 0)
    {
        printf("List is empty\n");
        return Failure;
    }
    else
    {
        while(temp != 0)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        return Success;
    }
}

struct node *deleteFromTheBegginning(struct node *head)
{
    struct node* temp = head->next;
    free(head);
    printf("First Node deleted successfully\n");
    head = temp;
    return head;
}

struct node *deleteFromTheEnd(struct node *head)
{
    struct node* temp = head;
    struct node *prev = NULL;
    while(temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    printf("Last Node deleted successfully\n");
    return head;
}

struct node *deleteFromTheSpecificPosition(struct node *head,int pos)
{
    struct node* temp = head;
    struct node *prev = NULL;
    int i = 1;
    if(pos == 1)
    {
        temp = head->next;
        free(head);
        printf("Node deleted successfully\n");
        head = temp;
        return head;
    }
    while(i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully\n");
    return head;
}

struct node *DeleteASpecificNodeByValue(struct node *head,int value)
{
    struct node* temp = head;
    struct node *prev = NULL;
    int i = 1;
    if(value == temp->data)
    {
        temp = head->next;
        free(head);
        printf("Node deleted successfully\n");
        head = temp;
        return head;
    }
    while(temp->data != value)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully\n");
    return head;
}


int main()
{
    struct node *head = 0;
    int option,True = 1;
    while(True)
    {
        printf("Enter\n1.Create Node\n2.Display List\n3.Delete from the Beggining\n4.Delete from the End\n5.Delete from  a specific position\n6.Delete a specific node by value:");
        scanf("%d",&option);
        switch(option)
        {
            int pos,value;
        case 1:
            head = createNode(head);
            break;
        case 2:
            displayList(head);
            printf("List displayed\n");
            break;
        case 3:
            head = deleteFromTheBegginning(head);
            break;
        case 4:
            head = deleteFromTheEnd(head);
            break;
        case 5:
            printf("Enter position to delete\n");
            scanf("%d",&pos);
            head = deleteFromTheSpecificPosition(head,pos);
            break;
        case 6:
            printf("Enter value of a specific node to delete\n");
            scanf("%d",&value);
            head = DeleteASpecificNodeByValue(head,value);
        }
    }
}
