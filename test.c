#define _GNU_SOURCE
#define _XOPEN_SOURCE 700
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAP_HUGE_2MB    (21 << MAP_HUGE_SHIFT)

enum { I0 = 0x12345678 };
uint32_t* a;
//static volatile uint32_t a[4096];

int main(void) {

//   printf("calling malloc\n");
   a = (uint32_t*) malloc(sizeof(uint32_t)*(2*1024*1024));
   // a = mmap(NULL,  4198400 ,  PROT_READ |  PROT_WRITE,  MAP_PRIVATE|MAP_ANONYMOUS | MAP_HUGETLB | MAP_HUGE_2MB,  -1,  0);

   if(a == MAP_FAILED)
   {
      printf("a is null\n");
      return -1;
   } 

   for(int i=0;i<1048576;i++)
   {
      a[i] = i;
   }

   printf("vaddr %p\n", a+2);
   printf("pid %ju\n", (uintmax_t)getpid());
   while (a[2] == 2) {
      sleep(1);
   }
   printf("i %jx\n", (uintmax_t)a);
   return EXIT_SUCCESS;
}
