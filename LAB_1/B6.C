// 6. WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS
// [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)].

#include <stdio.h>
int main()
{
   int S, H, M;
   H = 0;
   M = 0;
   printf("ENTER THE SECONDS : ");
   scanf("%d", &S);

   while (S >= 60)
   {
      M++;
      S = S - 60;
   }

   while (M >= 60)
   {
      H++;
      M = M - 60;
   }

   printf("HH:MM:SS = %d:%d:%d", H, M, S);
   return 0;
}
