#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/*Heya*/
int ack_recursive(int m, int n) {
if (m == 0) 
    return n + 1;
if (n == 0)
    return ack_recursive(m - 1, 1);
return ack_recursive(m - 1, ack_recursive(m, n - 1));
}

int ack_nonrecursive(int m, int n, int *status) 
{
int value[n];
size_t size = 0;
for (;;) 
{
if (m == 0) 
{
    n++;
    if (size-- == 0) 
    {
        *status = EXIT_SUCCESS;
        break;
    }
    m = value[size];
    continue;
}
if (n == 0) 
{
    m--;
    n = 1;
    continue;
}
size_t index = size++;
value[index] = m - 1;
n--;
}
return n;
}

int main(void) 
{
for (int m = 0; m < 2; m++)
    for (int n = 0; n < 2; n++) 
    {
        int status;
            assert(ack_recursive(m, n) == ack_nonrecursive(m, n, &status) && status == EXIT_SUCCESS);
    }
printf("%d",ack_recursive(1,2));
}
