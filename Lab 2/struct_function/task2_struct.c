#include <stdio.h>


int is_perfect(int num) {
    int sum = 0; 
    for (int x = 1; x<= num/2; x++) {
        if (num % x == 0) {
            sum += x;
            
        }
    }
    return sum == num;
}


void is_in_range(int s, int e) {
    printf("Perfect numbers between %d and %d are:\n", s, e);
    for (int x = s; x <= e; x++) {
        if (is_perfect(x) )
            printf("%d\n", x);
    }
}


void interval(int *s, int *e) {
    printf("start of the interval: ");
    scanf("%d", s);
    printf("end of the interval: ");
    scanf("%d", e);
}


int main() {
    int s, e;  //start , end
    
    
    interval(&s, &e);

    is_in_range(s, e);

    return 0;
}

