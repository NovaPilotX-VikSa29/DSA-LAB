#include <stdio.h>
#include "queue.h"


int main()
{
    queue_t q;

    int choice;
    int value;
    int deleted_value;

    queueInit(&q);

    printf("----- Queue (implemented using Deque) -----\n");

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                printf("Enter value to enqueue: ");
                scanf("%d", &value);

                queueEnqueue(&q, value);

                break;


            case 2:

                if (queueIsEmpty(&q))
                {
                    printf("Queue is empty.\n");
                }
                else
                {
                    deleted_value = queueDequeue(&q);
                    printf("Dequeued value: %d\n", deleted_value);
                }

                break;


            case 3:

                queueDisplay(&q);

                break;


            case 4:

                printf("Exiting...\n");
                return 0;


            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}