#include <stdio.h>
#include "dequeue.h"

void addPackageWeight(Deque *dq, int value, int index, int k)
{
    /* Remove elements outside the current window */
    while (!isEmpty(dq) &&
           getFront(dq).index <= index - k)
    {
        popFront(dq);
    }

    /* Remove elements larger than the new value */
    while (!isEmpty(dq) &&
           getBack(dq).value >= value)
    {
        popBack(dq);
    }

    pushBack(dq, value, index);

    /* Print minimum once the first complete window is formed */
    if (index >= k - 1)
    {
        printf("Minimum = %d\n", getFront(dq).value);
    }
}

int main()
{
    int n, k, value;

    printf("Enter number of readings: ");
    scanf("%d", &n);

    printf("Enter window size K: ");
    scanf("%d", &k);

    if (k <= 0 || k > n)
    {
        printf("Invalid window size.\n");
        return 0;
    }

    Deque dq;
    initDeque(&dq, n);

    printf("Enter package weights:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        addPackageWeight(&dq, value, i, k);
    }

    freeDeque(&dq);

    return 0;
}