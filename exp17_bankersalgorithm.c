#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES]={3,3,2};

int maximum[MAX_PROCESSES][MAX_RESOURCES]={
{7,5,3},
{3,2,2},
{9,0,2},
{2,2,2},
{4,3,3}
};

int allocation[MAX_PROCESSES][MAX_RESOURCES]={
{0,1,0},
{2,0,0},
{3,0,2},
{2,1,1},
{0,0,2}
};

int main()
{
    printf("Banker's Algorithm Program\n");
    return 0;
}
