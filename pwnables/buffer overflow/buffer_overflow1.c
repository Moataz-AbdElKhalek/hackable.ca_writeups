#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
   int password = 0xcafebabe;
   char your_name[100] = {0};
   printf("Enter your name\n");
   fflush(stdout);
   read(0, your_name, 0x100);

   if(password == 0xdeadbeef) {
       puts("GOOD WORK!\n");
       puts("FLAG{**********************}");
   }
   else {
       puts("Nice try :( Your name didn't meet my expectations\n");
   }
}
