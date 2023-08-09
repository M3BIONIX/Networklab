#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdio.h>

#define OUTPUT 1

int main()
{
    int bucket_capacity;
    printf("Enter the bucket Capacity : ");
    scanf("%d",&bucket_capacity);
    int bucket_size = 0;

    while(true)
    {
        int incoming = rand() % 5;
        bucket_size += incoming;

        printf("The incoming Packets are : %d \n", incoming);

        if(bucket_size > bucket_capacity)
        {
            printf("Overflow bitch");
            bucket_size = bucket_capacity;
        }
        if(bucket_size > 0)
        {
            int outgoing = bucket_size > OUTPUT ? bucket_size : OUTPUT;
            printf("Outgoing : %d \n", outgoing);
            bucket_size -= outgoing;
        }

        sleep(1);
    }

    return 0;
}
