#include <stdio.h>
#include "SevenSegment.h"

SevenSegment s1(0);  // จอแสดงผลตัวที่ 1
SevenSegment s2(4);  // จอแสดงผลตัวที่ 2

extern "C" void app_main(void)
{
    while(1)   
    {
        // ทดสอบฮาร์ดแวร์ s1 และแสดงหน้าจอว่างเปล่า
        s1.HardwareTest();
        vTaskDelay(500 / portTICK_PERIOD_MS);
        s1.DisplayBlank();
        vTaskDelay(500 / portTICK_PERIOD_MS);

        // ทดสอบฮาร์ดแวร์ s2 และแสดงหน้าจอว่างเปล่า
        s2.HardwareTest();
        vTaskDelay(500 / portTICK_PERIOD_MS);
        s2.DisplayBlank();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    } 
}
