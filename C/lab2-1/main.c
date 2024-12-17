#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_1, num_2, num_3, num_4, num_5;

    printf("Enter the First Number: ");
    scanf("%d", &num_1);

    printf("Enter the Second Number: ");
    scanf("%d", &num_2);

    printf("Enter the Third Number: ");
    scanf("%d", &num_3);

    printf("Enter the Fourth Number: ");
    scanf("%d", &num_4);

    printf("Enter the Fifth Number: ");
    scanf("%d", &num_5);

    int min = num_1;
    int max=num_1;


       if (num_2 < min) {
        min = num_2;
    }
    if (num_3 < min) {
        min = num_3;
    }
    if (num_4 < min) {
          min = num_4;
    }
    if (num_5 < min) {
        min = num_5;

    }



    printf("The Minimum Number is %d\n", min);

    if (num_2 > max){
        max = num_2;
    }
    if (num_3 > max) {
        max = num_3;
    }
    if (num_4 > max) {
        max = num_4;
    }
    if (num_5 > max){
        max = num_5;
    }

    printf("You Max Number is %d \n", max);

    return 0;

}
