#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0) return -1; // Invalid case
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int choice;
    double x, y;

    while (1) {
        printf("\nScientific Calculator in Progress\n");
        printf("1. Square Root (√x)\n");
        printf("2. Factorial (x!)\n");
        printf("3. Natural Logarithm (ln(x))\n");
        printf("4. Power (xʸ)\n");
        printf("5. Exit\n");
        printf("Please Enter your choice: "); 
        fflush(stdout); 

        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number: ");
                fflush(stdout);
                scanf("%lf", &x);
                printf("Result: %.2lf\n", sqrt(x));
                break;
            
            case 2:
                printf("Enter a non-negative integer: ");
                fflush(stdout);
                int num;
                scanf("%d", &num);
                printf("Result: %lld\n", factorial(num));
                break;
            
            case 3:
                printf("Enter number: ");
                fflush(stdout);
                scanf("%lf", &x);
                printf("Result: %.2lf\n", log(x));
                break;
            
            case 4:
                printf("Enter base (x): ");
                fflush(stdout);
                scanf("%lf", &x);
                printf("Enter exponent (y): ");
                fflush(stdout);
                scanf("%lf", &y);
                printf("Result: %.2lf\n", pow(x, y));
                break;
            
            case 5:
                printf("Exiting calculator.\n");
                return 0;
            
            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }
    }
    return 0;
}

