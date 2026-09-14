// 4. WAP to find the largest among the given three numbers by user :-

#include<stdio.h>
void main(){
    int a,b,c;

    printf("ENTER THE FIRST NUMBER : ");
    scanf("%d",&a);
    printf("ENTER THE SECOND NUMBER : ");
    scanf("%d",&b);
    printf("ENTER THE THIRD NUMBER : ");
    scanf("%d",&c);

    if(a>b && a>c){
    printf("A IS LARGEST.");
    }
    else if(b>a && b>c){
    printf("B IS LARGEST.");
    }
    else{
    printf("C IS LARGEST.");    
    }
}
