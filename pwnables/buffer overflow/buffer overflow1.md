This is the first chanllenge in the pwnables category:

The challenge is asking you to connect to `nc pwnable.hackable.ca 9993` that runs an executable that asks you to `Enter your name`, and based on your answer it should give you the correct flag.

The sourcecode of the executable is given in the challenge, (buffer_overflow1.c)


# Solution

1. Analyzing code
2. crafting our buffer overflow input

## 1. Analyzing code
Looking at the sourcecode we notice that this is an easy buffer overflow example.

1. It creates an integer variable `password` and saves in it the hex value `0xcafebabe`. It also creates a string variable `your_name` of size 100. 

```
int password = 0xcafebabe;
char your_name[100] = {0};
```
2. It prints `Enter your name` and reads the input into the variable `your_name`
```
printf("Enter your name\n");
fflush(stdout);
read(0, your_name, 0x100);
```
3. Then it compares the variable `password` to the value `0xdeadbeef` and if correct it will print the FLAG if not it asks to try again and exits.
```
if(password == 0xdeadbeef) {
    puts("GOOD WORK!\n");
    puts("FLAG{**********************}");
}
else {
    puts("Nice try :( Your name didn't meet my expectations\n");
}
```

>if we make some research about the `read` function in C we find that read() don't work with strings, but with buffers, and as such it doesn't need to know their contents, just their size. As long as it only uses the buffer, there won't be any overrun problems. The problem may come if you later treat that buffer as a string. In that case, you will most probably overrun it.


we also notice that in the `read` function it reads `0x100` bytes which is `256` bytes, however the variable `your_name` is only 100 bytes long. This means that the `read` function can lead to a buffer overflow vulnerability.

