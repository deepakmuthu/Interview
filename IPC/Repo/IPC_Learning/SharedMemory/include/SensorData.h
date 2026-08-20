#pragma once

// "/sensor_memory"      // ✅
// "/my_shm"             // ✅
// "/tmp/sensor_memory"  // ❌ Invalid
// "sensor_memory"       // ❌ Invalid
#define SHM_FILE_PATH "/shm_file_path"

using namespace std;

class SensorData {

    public:
        int i32Temperature;
        int i32Mode;
        float fHuminity; 

};
