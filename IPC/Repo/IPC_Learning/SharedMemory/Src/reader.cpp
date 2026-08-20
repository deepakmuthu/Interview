#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include <sys/mman.h>
#include <cstring>

#include <SensorData.h>

int main()
{
    int i32Shm_fd = shm_open ( SHM_FILE_PATH, O_RDONLY, 0666  );

    if ( i32Shm_fd == -1 )
    {
        perror ( "Shm file descriptor creation is fail" );
        exit (1);
    }

    SensorData* objSensorData = ( SensorData* ) mmap (
                                    nullptr
                                    , sizeof ( SensorData )
                                    , PROT_READ
                                    , MAP_SHARED
                                    , i32Shm_fd
                                    , 0
                                );

    if ( nullptr == objSensorData )
    {
        perror ( "Map memory is fail" );
        close (i32Shm_fd);
        exit(1);
    }

    cout << "Reader is start" << endl;

    while (1)
    {
        cout << "Temperature : " << objSensorData->i32Temperature << endl;
        cout << "i32Mode : " << objSensorData->i32Mode << endl;
        cout << "fHuminity : " << objSensorData->fHuminity << endl;

        sleep (3);
    }

    munmap ( objSensorData, sizeof ( SensorData ) );
    close ( i32Shm_fd );

    return 0;
}