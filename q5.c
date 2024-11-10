#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;

    struct node *next;

} node;

node *removeDuplicates (node *lst);

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

    list = removeDuplicates(list);

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->num);
    }

    node *ptr = list;

    while (ptr != NULL)
    {
        node *nxt = ptr->next;

        free(ptr);

        ptr = nxt;
    }
}

//hashset implementation

node *removeDuplicates (node *lst)
{
    if (lst == NULL)
    {
        return lst;
    }

    node *current = lst;

    node *prev = NULL;

    int seen[1000] = {0};

    while (current != NULL)
    {
        if (seen[current->num])
        {
            //duplicate detected

            prev->next = current->next;

            free(current);
        }

        else
        {
            //mark as seen since not a duplicate yet

            seen[current->num] = 1;

            prev = current;
        }

        current = prev->next;
    }

    return lst;
}