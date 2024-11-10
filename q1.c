#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;

    struct node *next;

} node;

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int count = atoi(argv[1]);

    node *list = NULL;

    for (int i = 0; i < count; i++)
    {
        node *n = malloc(sizeof(node));

        scanf("%i", &(n->num));

        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }

        else if (n->num <= list->num)
        {
            n->next = list;

            list = n;
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

                if (n->num < ptr->next->num)
                {
                    n->next = ptr->next;

                    ptr->next = n;

                    break;
                }
            }
        }
    }

    //deleting from last node

    node *prev = NULL;

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next == NULL)
        {
            if (prev != NULL)
            {
                prev->next = NULL;
            }

            else
            {
                list = NULL;
            }

            free(ptr);

            break;
        }

        prev = ptr;
    }
    
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");

    //delete first node

    node *second = list->next;
    
    free(list);
    
    list = second;

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");
    
    //delete between nodes

    node *btw = list->next;

    if (btw != NULL)
    {
        list->next = btw->next;
        
        free(btw);
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    printf("\n");
}    
