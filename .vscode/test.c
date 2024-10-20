#include <stdio.h>
#include "time.h"


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


int main(){

//for (size_t i = 0; i < 100; i++)
//{
    printf("Bruh");
    //delay(1000);
//}


return 0;
}
