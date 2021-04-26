This is the first chanllenge in the pwnables category:

The challenge is asking you to connect to `nc pwnable.hackable.ca 9993` that runs an executable that asks you to `Enter your name`, and based on your answer it should give you the correct flag.

The sourcecode of the executable is given in the challenge, (buffer_overflow1.c)


# Solution



looking at the sourcecode we notice that this is an easy buffer overflow example. 



read() and write() don't work with strings, but with buffers, and as such they don't need to know their contents, just their size.

As long as you only use the buffer to write into stdout, you won't have any overrun problems.

'\0' is only needed for strings.

The problem may come if you later treat that buffer as a string. In that case, you will most probably overrun it.
