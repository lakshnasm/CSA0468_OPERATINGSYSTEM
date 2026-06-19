#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;

    fd = open("sample.txt", O_RDONLY);

    if(fd < 0)
    {
        printf("File not found\n");
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    fstat(fd, &fileStat);

    printf("File Size : %ld bytes\n", fileStat.st_size);

    close(fd);

    dir = opendir(".");

    if(dir)
    {
        while((entry = readdir(dir)) != NULL)
        {
            printf("%s\n", entry->d_name);
        }

        closedir(dir);
    }

    return 0;
}
