#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>



int checkP2(int x) {
   int count = 0;
   if (x <= 0) return -1; 
   while (x != 1) {
       if (x % 2 != 0)
           return -1; 
       x /= 2;
       count += 1;
   }
   return count;
}



int *dTob(int n, int l) {
    static int arr[32];
    int i;

    for (i = 0; i < 32; i++)
        arr[i] = 0;

    i = 0; 
    while (n > 0 && i < l) {
        arr[i] = n % 2;
        n /= 2;
        i++;
    }

    return arr;
}




int bTod(int a[], int l) {
    int val = 0;
    for (int i = 0; i < l; i++) {
        val = (val << 1) + a[i];
    }
    return val;
}


int main() {
   int page_size = 4; 
   int memory_size = 32; 
   int n_of_freame = memory_size / page_size; 
   int offset_bit = log2(page_size); 
   int m = n_of_freame; 
   int page_num_bits = log2(m); 

   int logical_addrs[] = {8, 4, 3, 2, 15, 18, 25}; 
   int page_table[] = {3, 6, 8, 12, 2}; 

   printf("Page size: %d\n", page_size);
   printf("Memory size: %d\n", memory_size);
   printf("Number of frames required: %d\n", n_of_freame);
   printf("Page number bits: %d\n", page_num_bits);
   printf("Offset bits: %d\n", offset_bit);
   printf("Number of address spaces: 5 \n", m);

   printf("Page Table______\n");
   for (int i = 0; i < 5; i++)
       printf("%d -> %d\n", i, page_table[i]);

   for (int i = 0; i < 7; i++) {
       int offset = logical_addrs[i] & ((1 << offset_bit) - 1);
       int page_num = logical_addrs[i] >> offset_bit;
       if (page_num > 4) {
           printf("%d is an invalid page number\n", page_num);
           continue;
       }
       int frame_num = page_table[page_num];
       int phy_addr = (frame_num * page_size) + offset;
       if (phy_addr >= memory_size)
           printf("%d is an invalid physical address\n", phy_addr);
       else
           printf("Corresponding physical address of logical address %d: %d\n", logical_addrs[i], phy_addr);
   }

   return 0;
}