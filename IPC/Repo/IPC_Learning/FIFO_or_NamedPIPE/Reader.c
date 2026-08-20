#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// its required for the mkfifo() function to create a named pipe (FIFO).
#include <sys/stat.h>

#include <fcntl.h> // Required for the open() function

#define BUFFER_SIZE 1024
#define FIFO_NAME "/tmp/NamedPipe.txt"

int main()
{
    // Use the mkfifo() function to create a named pipe (FIFO) and use 0666 as the permission mode. 
    // mkfifo is avaibale in <sys/stat.h> header file.
    mkfifo(FIFO_NAME, 0666);

    // Use the pointer for the buffer rad the data from the FIFO.
    char acBuffer[BUFFER_SIZE];

    //  Open the FIFO fiel in Read mode. open() 
    int fd = open(FIFO_NAME, O_RDONLY);

    if ( fd < 0)
    {
        perror("Error in opening FIFO for reading");

        // Unlink the FIFO to remove it from the filesystem before exiting.
        unlink(FIFO_NAME);
        exit(1);
    }

    while (1)
    {
        memset(acBuffer, 0, sizeof(acBuffer));

        int i32Bytesread = read ( fd, acBuffer, sizeof(acBuffer));


        if ( i32Bytesread < 0)
        {
            perror("Error in reading from FIFO");
            break;
        }
        else if ( i32Bytesread == 0)
        {
            printf("No more data to read. Continuing...\n");
            break;
        }

        acBuffer[i32Bytesread] = '\0';
        acBuffer[strcspn(acBuffer, "\n")] = '\0';

        {
            printf("Readed buffer is: %s\n", acBuffer);
        }

        if ( !strcmp( acBuffer, "exit" ) )
        {
            printf("Exit command received. Exiting...\n");
            break;
        }

    }

    close(fd);
    unlink(FIFO_NAME);

    return 0;
}