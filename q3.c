#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;

    struct node *next;

} node;

int main (int argc, char* argv[])
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
                if (ptr->next ==  NULL)
                {
                    ptr->next = n;

                    break;
                }

                else if (n->num < ptr->next->num)
                {
                    n->next = ptr->next;

                    ptr->next = n;

                    break;
                }
            }
        }
    }

    int n;

    printf("Enter the number to search: ");

    scanf("%i", &n);

    int found = 0;

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (n == ptr->num)
        {
            printf("Found!\n");

            found = 1;

            break;
        }
    }

    if (!found)
    {
        printf("Not Found!\n");
    }
    
    node *ptr = list;

    while (ptr != NULL)
    {
        node *nxt = ptr->next;

        free(ptr);

        ptr = nxt;
    }
}