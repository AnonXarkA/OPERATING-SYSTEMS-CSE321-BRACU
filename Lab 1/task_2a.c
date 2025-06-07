#include<stdio.h>

int sub(double frst, double secnd){
    int ans;
    ans = frst - secnd;
    return ans;
}

int add(double frst , double secnd){
    int ans;
    ans = frst + secnd;
    return ans;
}

int multi(double frst , double secnd){
    int ans;
    ans = frst * secnd;
    return ans;
}


int main(){
    int first_num , second_num;

    printf("Enter first number: ");
    scanf("%d", &first_num);
    printf("Enter second number: ");
    scanf("%d", &second_num);


    if (first_num>second_num){
        printf("The result is: %d\n", sub(first_num,second_num));
    
    }

    else if(first_num<second_num){
        printf("The result is: %d\n", add(first_num,second_num));
    }

    else if(first_num==second_num){
        printf("The result is: %d\n", multi(first_num,second_num));
    }




}