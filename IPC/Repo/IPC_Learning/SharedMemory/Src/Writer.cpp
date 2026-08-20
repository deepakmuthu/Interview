#include <iostream>
#include <unistd.h>
#include <fcntl.h>

// shared memory related APIs, structures and constants are defined in the sys/mman.h header file. 
#include <sys/mman.h>
#include <cstring>

#include <SensorData.h>

int main()
{
    
    // Create the file shared file descriptor with the shm_open() API and user specified path by create and Read and Write mode with permission.
    int i32Shm_fd = shm_open ( SHM_FILE_PATH, O_CREAT | O_RDWR, 0666 );

    // Verify the shm_open status
    if ( i32Shm_fd == -1 )
    {
        perror ( "Shared memory file descriptor creation is fail" );
        exit(1);
    }

    // Set the shared memory file size.
    if ( -1 == ftruncate ( i32Shm_fd, sizeof ( SensorData ) ) )
    {
        perror ( "Shared memory file truncation is fail" );
        close ( i32Shm_fd );
        exit (1);
    }

    // Map the shared memory
    SensorData *objSensordata = (SensorData*) mmap (
                                        // choose the memory address were staert. Null means the Kernel is select the most efficient virtual memory space.
                                        nullptr
                                        // Specify the size of memory mapping. Kernel usually round this to usually page size(4KB). 
                                        , sizeof ( SensorData )
                                        // set the memory permission mode for mapped region.
                                        , PROT_READ | PROT_WRITE
                                        // Determine the how update the memory region are shared and save.
                                        , MAP_SHARED
                                        // Specify the file descriptor
                                        , i32Shm_fd
                                        // Set the starting points, inside of the file. 0 means start from 0 bytes of map.  
                                        , 0
                                ); 

    if ( MAP_FAILED == objSensordata )
    {
        perror ( "mmap action is failed" );
        close ( i32Shm_fd );
        exit (1);
    }

    std::cout << "Write action is start\n";

    while (1)
    {
        cout << "Enter the Temperature value: ";
        std::cin >> objSensordata->i32Temperature;

        cout << "Enter the Mode: ";
        cin >> objSensordata->i32Mode;

        cout << "Enter the Huminity: ";
        cin >> objSensordata->fHuminity;

        cout << "Data are writtened\n";

        if ( objSensordata->i32Mode == 0 )
        {
            cout << "Quit the parent process !!!" << endl;
            break;
        } 
    }

    munmap ( objSensordata, sizeof ( SensorData ) );
    close ( i32Shm_fd );

    // Optional: Writer process only required to unlink process. They are owner of the file.
    // If the process is terminate or no need the shared memory file to use, only do the shm_unlink action.
    shm_unlink ( SHM_FILE_PATH );

    return 0;
}

// deepakm@deepakm-HP-Laptop-15s-fq2xxx:~/Documents/Interview/Programming/IPC/Repo/IPC_Learning/SharedMemory$