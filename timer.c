/*
 *    Name: Hao Lu
 */
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

int totalTime, s, m;  // s and m are seconds and minutes we input, then calculate the total seconds as totalTime

QueueHandle_t xQueue; // set the time queue named xQueue

void TimeTask() {
    int countTime = totalTime;
    while(1) {
        xQueueSend(xQueue, &countTime, 0);         // send the countTime
        vTaskDelay(1000 / portTICK_RATE_MS);                                   // 1000ms = 1s delay
        countTime--;
    }
}

void DisplayTask() {
    int remainTime;                                                           // remainTime = countTime
    while(1) {
        xQueueReceive(xQueue, &remainTime, portMAX_DELAY);
        if (remainTime == 0) {
            printf("Time is up!\n");
        }
        if (remainTime != 0) {
            printf("Time remaining: %d:%02d \n", remainTime / 60, remainTime % 60);
        }
    }
}

int main() {
    // input the time
    printf("Enter minutes: ");
    scanf("%d", &m);
    printf("Enter seconds: ");
    scanf("%d", &s);
    totalTime = 60 * m + s;
    // create the queue
    setbuf(stdout, NULL);
    xQueue = xQueueCreate(10, sizeof(int));
    // run the tasks
    xTaskCreate(TimeTask, "TimeTask", 1000, NULL, 1, NULL);
    xTaskCreate(DisplayTask, "DisplayTask", 1000, NULL, 1, NULL);
    vTaskStartScheduler();
}