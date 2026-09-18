#include <stdio.h>
#include "pqueue.h"

int main()
{
    pqueue_t pq;

    int choice;
    int depth;
    int traffic;
    int job_id = 1;

    init_pqueue(&pq);

    printf("----- Pothole Repair Priority Queue -----\n");

    while (1)
    {
        printf("\n1. Add Pothole Job (Enqueue)\n");
        printf("2. Process Highest Priority Job (Dequeue)\n");
        printf("3. Display All Pending Jobs\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter pothole depth (1-5): ");
                scanf("%d", &depth);

                printf("Enter traffic heaviness (1-5): ");
                scanf("%d", &traffic);

                if (depth < 1 || depth > 5 ||
                    traffic < 1 || traffic > 5)
                {
                    printf("Invalid input. Values must be between 1 and 5.\n");
                    break;
                }

                enqueue(&pq, job_id, depth, traffic);

                printf("Job %d added with priority %d.\n",
                       job_id, depth + traffic);

                job_id++;
                break;


            case 2:
                dequeue(&pq);
                break;


            case 3:
                display(&pq);
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