#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source, *target;
    char ch;

    source = fopen("source.txt", "r");

    if (source == NULL)
    {
        printf("Source file not found\n");
        return 1;
    }

    target = fopen("target.txt", "w");

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, target);
    }

    printf("File copied successfully\n");

    fclose(source);
    fclose(target);

    return 0;
}
