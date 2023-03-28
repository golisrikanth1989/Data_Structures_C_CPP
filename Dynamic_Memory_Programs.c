#include<stdio.h>
#include<stdlib.h>

// int main()
// {
//     int i,n;
//     printf("Enter the number of digits to store: \n");
//     scanf("%d",&n);
//     int *ptr = (int *)malloc(n*sizeof(int));

//     if (ptr == NULL)
//     {
//        printf("Memory is not Available and allocated\n");
//        exit(1);
//     }

//     for(i=0;i<n;i++)
//     {
//         printf("%d\n",*(ptr+i));
//     } 

//     for(i=0;i<n;i++)
//     {
//         printf("Enter %d element\n",i);
//         scanf("%d",ptr+i);
//     }

//     for(i=0;i<n;i++)
//     {
//         printf("%d\n",*(ptr+i));
//     }     

// MALLOC and FREE
int *input()
{
    int *ptr, i;
    ptr = (int*)malloc(5*sizeof(int));
    printf("Enter 5 numbers:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",ptr+i);
    } 
    return ptr;
}
int main()
{
  int i, sum=0;
  int *ptr = input();
  for(i=0;i<5;i++)
  {
    sum +=*(ptr+i);
  }
  printf("Sum is %d",sum);
  free(ptr);
  ptr = NULL;
  return 0;
}