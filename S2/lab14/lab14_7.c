#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
void *data;
struct _Node *next;
} Node;
typedef struct _UnorderedList
{
Node *head;
} UnorderedList;

typedef void (*PRINT)(const void *);

void initialize_list(UnorderedList *list)
{
    list->head = NULL; 
}

void add_begin(UnorderedList *list, void *data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return;
    new_node->data = data;

    new_node->next=list->head;
    list->head=new_node;
}

void add_end(UnorderedList *list, void *data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return;
    new_node->data = data;

    Node *current=list->head;
    new_node->next=NULL;

    if(current==NULL)
    {
        list->head=new_node;
        return;
    }

    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=new_node;

}

void *delete_begin(UnorderedList *list)
{
    if(list->head==NULL)
    {
        return list;
    }
    void *tempData=list->head->data;

    Node *tempNode=list->head->next;
    free(list->head);
    list->head=tempNode;

    return tempData;
}

void *delete_end(UnorderedList *list)
{
    if(list->head==NULL)
    {
        return list;
    }

    void *tempData;

    if(list->head->next==NULL)
    {
        tempData=list->head->data;

        free(list->head);
        list->head=NULL;

        return tempData;
    }

    Node *tempNode=list->head;

    while (tempNode->next->next!=NULL)
    {
        tempNode=tempNode->next;
    }

    tempData=tempNode->next->data;
    
    free(tempNode->next);
    tempNode->next=NULL;

    return tempData;
}

void print_list(const UnorderedList *list, PRINT print)
{
    printf("LISTA:\n");
    Node *current = list->head;
    while (current != NULL)
    {
        print(current->data);
        current = current->next;
    }
}

void printdata(const void *input)
{
    const int *num=input;
    printf("%d\n",*num);
}

int main()
{
    UnorderedList list;
    initialize_list(&list); //1

    print_list(&list,printdata); //2

    int a=1,b=2,c=3;
    add_begin(&list,&a);//3

    print_list(&list,printdata);

    add_begin(&list,&b);

    print_list(&list,printdata);

    add_end(&list,&c);//4

    print_list(&list,printdata);

    delete_end(&list);//5

    print_list(&list,printdata);

    delete_begin(&list);//6

    print_list(&list,printdata);

    delete_begin(&list);

    print_list(&list,printdata);

    return 0;
}
