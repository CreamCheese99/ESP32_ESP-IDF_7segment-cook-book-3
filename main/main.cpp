#include <stdio.h>
#include "LED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

LED seg_a(16);
LED seg_b(17);
LED seg_c(5);
LED seg_d(18);
LED seg_e(19);
LED seg_f(21);
LED seg_g(22);
LED digit_1(0);
LED digit_2(4);

void HardwareTest()
{
    // เปิด digit_1 และเริ่มไล่ segment ทีละตัวแบบเปิดทีละอัน
    digit_1.ON();
    digit_2.OFF();

    // ไล่เปิด segment ทีละอัน
    seg_a.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_b.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_c.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_d.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_e.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_f.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_g.ON();
    vTaskDelay(200 / portTICK_PERIOD_MS);

    // กระพริบ segment ทั้งหมดพร้อมกัน 3 ครั้ง
    for (int i = 0; i < 3; i++) {
        seg_a.OFF(); seg_b.OFF(); seg_c.OFF(); seg_d.OFF(); seg_e.OFF(); seg_f.OFF(); seg_g.OFF();
        vTaskDelay(200 / portTICK_PERIOD_MS);

        seg_a.ON(); seg_b.ON(); seg_c.ON(); seg_d.ON(); seg_e.ON(); seg_f.ON(); seg_g.ON();
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }

    // ปิดทั้งหมดและสลับไปที่ digit_2
    digit_1.OFF();
    digit_2.ON();
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // ไล่ปิด segment ทีละอัน
    seg_a.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_b.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_c.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_d.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_e.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_f.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    seg_g.OFF();
    vTaskDelay(200 / portTICK_PERIOD_MS);

    // ปิดทั้งหมดและกระพริบ digit_2 เพื่อปิดท้าย
    for (int i = 0; i < 3; i++) {
        digit_2.OFF();
        vTaskDelay(300 / portTICK_PERIOD_MS);
        digit_2.ON();
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }

    // ปิด digit_2 เมื่อจบการทดสอบ
    digit_2.OFF();
}


extern "C" void app_main(void)
{

    while(1)
    {
        HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
    } 

}