// 5. WAP to check for the leap year :- 

#include<stdio.h>
void main(){
    int year;
    printf("ENTER THE YEAR  : ");
    scanf("%d",&year);
    if((year%4==0 && year%100!=0)|| year %400==0){
    printf("GIVEN YEAR %d IS LEAP YEAR.",year);
    }
    else{
    printf("GIVEN YEAR %d IS NOT LEAP YEAR.",year);    
    }
}
