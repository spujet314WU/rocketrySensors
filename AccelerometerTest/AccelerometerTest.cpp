#include <stdio.h>
#include "pico/stdlib.h"
#include "accel.h"
#include <iostream>

extern "C" {
    #include "i2cLib.h"
}

#define ONE_SEC_MICROS 1000000
#define SAMPLE_FREQ 10

int main()
{
    uint8_t rslt;

    stdio_init_all();
    sleep_ms(5000);

    init_i2cLib();

    printf("Starting test.\n");
    struct bmi08_dev bmi08dev;
    struct bmi08_fifo_frame fifo_frame;
    uint8_t status;
    uint8_t fifo_data[BMI08_ACC_FIFO_RAW_DATA_BUFFER_SIZE] = { 0 };
    uint16_t wml;

    unsigned long currentTime = to_us_since_boot(get_absolute_time());
    unsigned long previousTime = to_us_since_boot(get_absolute_time());
    unsigned long delTime = ONE_SEC_MICROS/SAMPLE_FREQ;
    struct bmi08_sensor_data bmi08_accel[100] = { { 0 } };
    printf("Initializing sensor.\n");
    bmi_init(&bmi08dev);
    printf("Sensor OK.\n");
    while (true) {
        currentTime = to_us_since_boot(get_absolute_time());
        if(currentTime-previousTime>delTime){
            currentTime = to_us_since_boot(get_absolute_time());
            //std::cout << "test" << std::endl;
            BMI_ACC_FIFO(&bmi08dev,&fifo_frame,&status,fifo_data,&wml,bmi08_accel);
            previousTime=currentTime;
        }
    }
}
