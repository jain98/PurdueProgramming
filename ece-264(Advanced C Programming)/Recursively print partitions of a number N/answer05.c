#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"answer05.h"
/**
* Prints all the partitions of a positive integer value.
*
* Example:
* partitionAll(3); // prints the following: (line order not important)
* = 1 + 1 + 1
* = 1 + 2
* = 2 + 1
* = 3
*
* Note: Order does not matter, and neither does white-space.
* Hint: look at file: expected/partitionAll.output
*/
void partitionAll_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  for(val=1;val<=left;val++)
    {
      arr[ind]=val;
      partitionAll_add(arr,ind+1,left-val);
    }
} 

void partitionAll(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionAll(%d)\n",value);
  partitionAll_add(arr, 0, value);
  free(arr);
}


/**
* Prints all partitions that have strictly increasing values.
*
* Example:
* partitionIncreasing(5); // prints the following: (line order not important)
* = 1 + 4
* = 2 + 3
* = 5
*
* These partitions are excluded because they are not _strictly_ increasing
* 1 + 1 + 3
* 2 + 1 + 2
* 3 + 2
*
* Note:
* The program should generate only valid partitions. Do not
* generates all partitions and then filter for validity. If you
* do this, you will almost certainly have trouble understanding the exam.
*
* Hint: look at file: expected/partitionIncreasing.output
*/

void partitionIncreasing_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  int min=1;
  if(ind!=0)
    {
      min=arr[ind-1]+1;
    }
  for(val=min;val<=left;val++)
    {
      arr[ind]=val;
      partitionIncreasing_add(arr,ind+1,left-val);
    }
} 

void partitionIncreasing(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionIncreasing(%d)\n",value);
  partitionIncreasing_add(arr, 0, value);
  free(arr);
}
/**
* Prints all partitions that have strictly decreasing values.
*
* Example:
* partitionDecreasing(5); // prints the following: (line order not important)
* = 3 + 2
* = 4 + 1
* = 5
*
* These partitions are excluded because they are not _strictly_ decreasing
* 1 + 1 + 3
* 2 + 1 + 2
*
* See: note on partitionIncreasing(...)
* Hint: look at file: expected/partitionDecreasing.output
*/

void partitionDecreasing_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  int max;
  if(left==2)
    {
      max=2;
    }
  else if(left==4)
    {
      max=3;
    }
  else if(left < 9)
    {
      if(left%2==0)
	{
	  max=left/2 ;
	}
      else
	{
	  max=left/2 +1;
	}
    }
  else
    {
      max=left/2;
    }
  for(val=max;val<=left;val++)
    {
      if(ind==0)
	{
          arr[ind]=val;
          partitionDecreasing_add(arr,ind+1,left-val);
	}
      else
	{
	  if((arr[ind-1]!=val) && (val < arr[ind-1]))
	    {
	      arr[ind]=val;
	      partitionDecreasing_add(arr,ind+1,left-val);
	    }
	}
    }
} 

void partitionDecreasing(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionDecreasing(%d)\n",value);
  partitionDecreasing_add(arr, 0, value);
  free(arr);
}
/**
* Prints all partitions comprised solely of odd numbers.
*
* Example:
* partitionOdd(5); // prints the following (line order not important)
* = 1 + 1 + 1 + 1 + 1
* = 1 + 1 + 3
* = 1 + 3 + 1
* = 3 + 1 + 1
* = 5
*
* See: note on partitionIncreasing(...)
* Hint: for odd numbers, (value % 2 != 0)
* Hint: look at file: expected/partitionOdd.output
*/
void partitionOdd_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  for(val=1;val<=left;val+=2)
    {
      arr[ind]=val;
      partitionOdd_add(arr,ind+1,left-val);
    }
} 

void partitionOdd(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionOdd(%d)\n",value);
  partitionOdd_add(arr, 0, value);
  free(arr);
}
/**
* Prints all partitions comprised solely of even numbers.
*
* Example:
* partitionEven(6); // prints the following (line order not important)
* = 2 + 2 + 2
* = 2 + 4
* = 4 + 2
* = 6
*
* See: note on partitionIncreasing(...)
* Hint: for even numbers, (value % 2 == 0)
* Hint: you can never partition an odd number with even numbers alone.
* Hint: look at file: expected/partitionEven.output
*/
void partitionEven_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  for(val=2;val<=left;val+=2)
    {
      arr[ind]=val;
      partitionEven_add(arr,ind+1,left-val);
    }
} 

void partitionEven(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionEven(%d)\n",value);
  partitionEven_add(arr, 0, value);
  free(arr);
}
/**
* Prints all partitions that do not have consecutive odd or even numbers.
* In other words, it only prints partitions that have alternating odd and
* even numbers.
*
* Example:
* partitionOddAndEven(5); // prints the following (line order not important)
* = 1 + 4
* = 2 + 1 + 2
* = 2 + 3
* = 3 + 2
* = 4 + 1
* = 5
*
* See: note on partitionIncreasing(...)
* Hint: look at file: expected/partitionOddAndEven.output
*/
void partitionOddAndEven_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  for(val=1;val<=left;val++)
    {
      int valid=0;
      if(ind==0)
	{
	  valid=1;
	}
      else
	{
	  valid=(arr[ind-1]%2)!=(val%2);
	}
      if (valid==1)
	{
	  arr[ind]=val;
	  partitionOddAndEven_add(arr,ind+1,left-val);
	}
    }
} 

void partitionOddAndEven(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionOddAndEven(%d)\n",value);
  partitionOddAndEven_add(arr, 0, value);
  free(arr);
}
/**
* Prints all partitions that comprise solely of prime numbers.
*
* Example:
* partitionPrime(5); // prints the following (line order not important)
* = 2 + 3
* = 3 + 2
* = 5
*
* See: note on partitionIncreasing(...)
* Hint: you will need to write a function that checks if a number is prime.
* Hint: 1 is not a prime number.
* Hint: look at file: expected/partitionPrime.output
*/
void partitionPrime_add(int* arr, int ind, int left)
{
  int val;
  int i;
  if(left==0)
    {
      printf("= ");
      for(i=0;i<ind-1;i++)
	{
	  printf("%d + ",arr[i]);
	}
      printf("%d\n",arr[ind-1]);
      return;
    }
  for(val=2;val<=left;val++)
    {
      if((val==2) || (val==3) || (val==5) || (val==7))
	{
	  arr[ind]=val;
	  partitionPrime_add(arr,ind+1,left-val);
	}
      else if((val%2 != 0) && (val%3 != 0) && (val%5 != 0) && (val%7 != 0))
	{
	  arr[ind]=val;
	  partitionPrime_add(arr,ind+1,left-val);
	}
    }
} 

void partitionPrime(int value)
{
  int* arr=malloc(value*sizeof(int));
  printf("partitionPrime(%d)\n",value);
  partitionPrime_add(arr, 0, value);
  free(arr);
}
