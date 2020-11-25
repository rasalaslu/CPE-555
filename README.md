CPE-555 Real-Time and Embedded Systems

FreeRTOS; C language

Lab 1 - Coordinates: Write a program in C which converts latitude and longitude expressed in decimal degrees to degrees/minutes/seconds format.

Lab 2 - timer: Write a program using FreeRTOSthat performs the following:  
               •The user should enter the number of minutes and seconds desired for the program to count down. The program will act like an alarm clock or countdown timer.  
               •The program has two tasks: TimeTask, DisplayTask.  
							 •The program has one queue that is shared by all ofthe tasks: timeQueue.  
               •TimeTask will keep track of seconds remaining. Once every second, this task should send the number of seconds remaining to the DisplayTaskvia the timeQueue.  
               •DisplayTaskshould retrieve numbers from timeQueueand print the value in the format of minutes and seconds.
