#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Requird fo use the pid_t type
#include <sys/types.h>
// Its cotain the fork() function
#include <unistd.h>
//  Contains the declaration for wait() and related macros (like WEXITSTATUS, WIFEXITED).
#include <sys/wait.h>

// Max size of the buffer used to read fron the file    
#define BUFFER_SIZE 100

int main (  int argc, char* argv[] )
{
    // Decalre the array for the pipe file descriptors. FileDescriptor[0] is read end of the file amf FileDescriptor[1] is the write end of the file.
    int FileDescriptor[2];
    
    // hold the Process ID returned by the fork() function.
    pid_t PidID;

    //  Character array to hold the data read from the parant PIPE.
    char acBuffer[BUFFER_SIZE];

    // CReate the pipe with error handling.
    if ( pipe(FileDescriptor) == -1 )
    {
        perror("Error while creating the PIPE");
        exit(EXIT_FAILURE);
    }


    printf ( "Parent processn PID [%d]\n", getpid() );

    // CReate the new chile process.
    PidID = fork();

    if ( PidID == -1 )
    {
        perror ( "Child process creation is fail." );
        exit(EXIT_FAILURE);
    }

   // check the process ID to determine whether the current process is the child(PidID == 0) or the parent(PidID>0). 
    if( PidID == 0 )
    {
        // close the write end of the descriptor in the child process.
        close (FileDescriptor[1]);

        int i32NoOfMessageReceived = 0;

        while (1)
        {
            ++i32NoOfMessageReceived;

            ssize_t ssNumberOfBytesRead = read ( 
                                                // share the read end of the pipe with the child process.
                                                FileDescriptor[0] 
                                                , acBuffer
                                                , sizeof ( acBuffer ) - 1
                                                );

            if ( ssNumberOfBytesRead <= 0 )
            {
                break;
            }

            acBuffer[ssNumberOfBytesRead] = '\0';
            acBuffer[strcspn(acBuffer, "\n")] = '\0';

            printf ( "\n Child Process\n" );
            printf ( "Received of Proces [%d  - %d] and Data is: %s\n", i32NoOfMessageReceived, getpid(), acBuffer);

            if ( strcmp ( acBuffer, "exit" ) == 0 )
            {
                printf ( "\nChild process is Terminated by the parent process\n");
                break;
            }
        }

        // close the read file descrip[tor in the child process.]
        close (FileDescriptor[0]);
    }
    else
    {
        char acBuffer[BUFFER_SIZE];

        // Close the read end of the file deccriptor in the paranet process.
        close (FileDescriptor[0]);

        while (1)
        {
            // Sleep for 2 seconds to give the child process time to read the data from the pipe.
            sleep (1);

            printf ( "\nParent Process\n" );
            printf ( "Enter the data to send to the child process: " );

            // Read the data from the standard input.
            fgets ( acBuffer, sizeof ( acBuffer ), stdin );

            // Write the data into the pipe.
            size_t szNumberOfBytesWritten = write ( 
                                                    // share the write end of the pipe with the parent process.
                                                    FileDescriptor[1] 
                                                    , acBuffer
                                                    , strlen(acBuffer) + 1
                                                    );

            if ( !szNumberOfBytesWritten )
            {
                perror ( "Error while writing into the PIPE" );
                exit(EXIT_FAILURE);
            }
            else
            {
                printf ( "Data is sent to the child process [%d - %s]\n", getpid(), acBuffer );
            }

            if ( strcmp ( acBuffer, "exit\n" ) == 0 )
            {
                //  Wait for the child process to terminate before continuing. 
                wait ( NULL );

                printf ( "\nParent process is Terminated by the user\n");
                break;
            }
        }

        // Close the write file descriptor in the parent proces after writing the data into PIPE.
        close ( FileDescriptor[1] );
    }

    return 0;
}


