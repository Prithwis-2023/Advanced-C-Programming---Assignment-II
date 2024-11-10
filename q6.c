#include <stdio.h>
#include <stdlib.h>

const int size = 5;

typedef struct node
{
    int num;

    struct node *next;

} node;

node *CreateLinkedList (node *lst, int index);

int main (void)
{
    node *list1, *list2;

    list1 = CreateLinkedList(list1, 1);

    list2 = CreateLinkedList(list2, 2);

    node dummy;

    node *tail = &dummy; //tail could also be named list3 since its the same

    dummy.next = NULL;

    node *ptr1 = list1, *ptr2 = list2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        //add node from first list

        tail->next = ptr1;

        ptr1 = ptr1->next;

        tail = tail->next;   

        //add node from second list

        tail->next = ptr2;

        ptr2 = ptr2->next;

        tail = tail->next;     
    }

    if (ptr1 != NULL)
    {
        tail->next = ptr1;
    }

    if (ptr2 != NULL)
    {
        tail->next = ptr2;
    }
    
    for (node *ptr = dummy.next; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }
}

node *CreateLinkedList (node *lst, int index)
{
    lst = NULL;

    printf("Enter the elements for list %i: ", index);

    for (int i = 0; i < size; i++)
    {
        node *n = malloc(sizeof(node));

        scanf("%i", &(n->num));

        n->next = NULL;

        if (lst == NULL)
        {
            lst = n;
        }

        else
        {
            for (node *ptr = lst; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;

                    break;
                }
            }
        }
    }

    return lst;
}