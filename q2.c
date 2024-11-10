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

        else
        {
            n->next = list;

            list = n;
        }
    }

    int counter = 0;

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        counter++;
    }

    printf("The number of nodes: %i\n", counter);
    

    //freeing the nodes

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        node *nxt = ptr->next;

        free(ptr);

        ptr = nxt;
    }
}