#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h> // Required for the open() function

#define BUFFER_SIZE 1024
#define FIFO_NAME "/tmp/NamedPipe.txt"

int main()
{
    char acBuffer[BUFFER_SIZE];

    int fd = open(FIFO_NAME, O_WRONLY);

    if (fd < 0)
    {
        perror("Error in opening FIFO for writing");
        exit(1);
    }

    while (1)
    {
        memset (acBuffer, 0, sizeof(acBuffer));

        char* pcBytesRead = fgets(acBuffer, sizeof(acBuffer) -1, stdin);
        if (pcBytesRead == NULL)
        {
            perror("Error in reading from stdin");
            break;
        }
        // int i32BytesRead = scanf ("%s", acBuffer);
        // if (i32BytesRead <= 0)
        // {
        //     perror("Error in reading from stdin");
        //     break;
        // }

        int i32BytesWritten = write(fd, acBuffer, strlen(acBuffer));
        if (i32BytesWritten < 0)
        {
            perror("Error in writing to FIFO");
            break;
        }
        else if(!strcmp(acBuffer, "exit"))
        {
            printf("Exit command received. Exiting...\n");
            break;
        }
        else
        {
            printf("Written buffer is: %s\n", acBuffer);
        }
    }


    close(fd);

    return 0;
}