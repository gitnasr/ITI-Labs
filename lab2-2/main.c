#include <stdio.h>
#include <stdlib.h>

int main()
{    int a, b, c;
    double discriminant, root1, root2;

    // Input coefficients
    printf("Enter coefficient a: ");
    scanf("%d", &a);
    printf("Enter coefficient b: ");
    scanf("%d", &b);
    printf("Enter coefficient c: ");
    scanf("%d", &c);

    // Mantdotry Check because we can't dived by ZERO :D
    if (a == 0) {

        printf("We can't dived by ZERO :D .\n");

        return 0;
    }

    //Checks if the Under Root is 0 or -ve
    discriminant = b * b - 4 * a * c;

    if (discriminant ==0 ){
       // This means the No SQROOT because SQROOT of 0 is 0
       root1 = -b / (2*a);
       root2 = root1;
       printf("Root 1 and Root 2 are: %f", root1);
       return 0;
    }

    if (discriminant < 0) {
        // Here's we deal with Imaginary Numbers

        printf("This will be an Imaginary Solution ... ");
        return 0;
    }

    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("Root 1 = %f \n", root1);
    printf("Root 2 = %f \n", root2);
    return 0;
}
