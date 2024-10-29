# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.

# แนวทางการทำงาน ESP32_ESP-IDF_WiFi-STA cook book 2
### 1.ระบุตัวอย่างที่ใช้ ว่าเอามาจากตัวอย่างไหน
 ![image](https://github.com/user-attachments/assets/3fe42a91-f4c6-4e0b-acb1-eb19f0c37037)
### 2.2. ระบุว่า จะแก้ไขตรงไหนบ้าง เพื่ออะไร
สร้างไฟล์ที่ชื่อว่า idf_component.yml ที่ Folder main แล้วใส่ข้อมูลในไฟล์ดังภาพ
![image](https://github.com/user-attachments/assets/05013342-a471-46c7-a2fa-a183eb171edb)


เปลี่ยนชื่อไฟล์ main.c เป็น main.cpp และทำการแก้ไขโค้ดในไฟล์โดยแก้ไขตามโค้ดเพื่อให้ผลการทดลองเเสดงเพื่อทำให้การเปิด-ปิด segment
แต่ละตัวมีลำดับ เเละมีการกระพริบหลายครั้งก่อนการปิดทั้งหมด 
 ![image](https://github.com/user-attachments/assets/c35fad47-6c7b-4e80-9de2-e16688bca33f)


### 3.ขั้นตอนการทำ

- การเลือกเทมเพลตในแถบด้านซ้าย ภายใต้ชื่อ esp-idf-extension-1.8.1 จะมีรายการเทมเพลตต่าง ๆ ให้เลือกผู้ใช้ได้เลือก template-app เป็นเทมเพลตที่ต้องการใช้
- สร้างโปรเจ็กต์: เมื่อเลือก template-app แล้ว สามารถกดปุ่ม "Create project using template template-app" เพื่อสร้างโปรเจ็กต์ใหม่ที่ใช้เทมเพลตนี้เป็นพื้นฐาน

![image](https://github.com/user-attachments/assets/c95edcab-16bb-4b6c-9f01-cf066d655881)

สร้างไฟล์ที่ชื่อว่า idf_component.yml ที่ Folder main แล้วใส่ข้อมูลในไฟล์ดังภาพ
![image](https://github.com/user-attachments/assets/05013342-a471-46c7-a2fa-a183eb171edb)


เปลี่ยนชื่อไฟล์ main.c เป็น main.cpp และทำการแก้ไขโค้ดในไฟล์โดยแก้ไขตามโค้ดใต้รูปภาพ  
 ![image](https://github.com/user-attachments/assets/c35fad47-6c7b-4e80-9de2-e16688bca33f)


```cpp 
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



```
### 4.แสดงผลการทำ
ผลการทดลอง 
https://drive.google.com/file/d/1Vekm42afDLENbyiTBc_-TrrS07xCKjlp/view?usp=sharing


### 5.สรุปผล
การกระพริบ Segment ทั้งหมด: ในลูป for โค้ดจะกระพริบ segment ทั้งหมดพร้อมกัน 3 ครั้ง 
การเปิด-ปิดทีละ Segment ด้วยดีเลย์ที่สั้นลง: ปรับ vTaskDelay ให้สั้นลงเพื่อให้ไล่เปิด-ปิดได้เร็วขึ้น 
การกระพริบ digit_2 ก่อนปิดการทดสอบ: กระพริบ digit_2 เพื่อเป็นการจบการทดสอบ


