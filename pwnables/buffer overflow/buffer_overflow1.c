#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
   int password = 0xcafebabe;
   printf("The password is: %d\n", password);
   char your_name[100] = {0};
   printf("Enter your name\n");
   fflush(stdout);
   read(0, your_name, 0x100);
   printf("The password is: %d\n", password);
   printf("It should be: %d\n", 0xdeadbeef);

   if(password == 0xdeadbeef) {
       puts("GOOD WORK!\n");
       puts("FLAG{**********************}");
   }
   else {
       puts("Nice try :( Your name didn't meet my expectations\n");
   }
}
