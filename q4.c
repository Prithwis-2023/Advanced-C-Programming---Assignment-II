#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int num;

    struct node *next;

} node;

node *CreateSortedList (node *list, int count);

node *MergeSortedLists (node *lst1, node *lst2);

int main (void)
{
    int count1, count2;

    printf("Enter the number of elements for  first linked list: ");

    scanf("%i", &count1);

    printf("Enter the elements for the first linked list: \n");

    node *list1;

    node *list1_mod = CreateSortedList(list1, count1);

    printf("Enter the number of elements for second linked list: ");

    scanf("%i", &count2);

    printf("Enter the elements for the second linked list: \n");

    node *list2;

    node *list2_mod = CreateSortedList(list2, count2);

    printf("First Sorted Linked List: ");

    for (node *ptr = list1_mod; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");

    printf("Second Sorted Linked List: ");

    for (node *ptr = list2_mod; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");

    node *list3 = MergeSortedLists(list1_mod, list2_mod);

    printf("Merged Sorted List: ");

    node *ptr = list3;

    while (ptr != NULL)
    {
        printf("%i ", ptr->num);

        ptr = ptr->next;
    }

    printf("\n");
}

node *CreateSortedList (node *list, int count)
{
    list = NULL;

    for (int i = 0; i < count; i++)
    {
        node *n = malloc(sizeof(node));

        scanf("%i", &(n->num));

        n->next= NULL;

        if (list == NULL)
        {
            list = n;
        }

        else if (n->num <= list->num)
        {
            n->next = list;
            
            list= n;
        }

        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;

                    break;
                }

                else if (n->num <= ptr->next->num)
                {
                    n->next = ptr->next;

                    ptr->next = n;

                    break;
                }
            }
        }
    }

    return list;
}

node *MergeSortedLists (node *lst1, node *lst2) 
{ 
    node dummy; 
    
    dummy.next = NULL; 
    
    node *tail = &dummy; 
    
    while (lst1 != NULL && lst2 != NULL) 
    { 
        if (lst1->num <= lst2->num) 
        { 
            tail->next = lst1; 
            
            lst1 = lst1->next; 
        } 
        else 
        { 
            tail->next = lst2; 
            
            lst2 = lst2->next; 
        } 
        
        tail = tail->next;
    } 
    
    if (lst1 != NULL) 
    { 
        tail->next = lst1; 
    } 
    else
    { 
        tail->next = lst2; 
    } 
    
    return dummy.next;

}    