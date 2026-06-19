#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char buffer[100];

    fd = creat("sample.txt", S_IRWXU);

    if(fd==-1)
    {
        perror("create");
        exit(1);
    }

    printf("File created successfully.\n");
    close(fd);

    fd = open("sample.txt", O_WRONLY | O_APPEND);

    write(fd,"Hello, World!\n",14);

    close(fd);

    fd = open("sample.txt", O_RDONLY);

    int bytesRead = read(fd,buffer,sizeof(buffer));

    write(STDOUT_FILENO,buffer,bytesRead);

    close(fd);

    remove("sample.txt");

    return 0;
}
