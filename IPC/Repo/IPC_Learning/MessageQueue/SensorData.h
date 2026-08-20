#pragma once

#define MESSAGE_QUEUE_FILE_PATH "/sensor_data_queue"

class SensorData
{
    public:
        int sensorId;
        float temperature;
        char acMode[20];
};