#include <stdio.h>
void countExecution()
{
    static int count=0;
    count++;
    printf("Function executed %d times\n",count);
}
int main()
{
    countExecution();
    countExecution();
    countExecution();
    return 0;
}
