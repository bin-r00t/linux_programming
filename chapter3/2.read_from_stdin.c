#include <unistd.h>
#include <stdlib.h>

int main()
{

  char buffer[20]; // read 20 bytes
  int nread;

  nread = read(0, buffer, 20);
  if (nread == -1)
  {
    /** something went wrong, check <errno> */
    write(2, "A read error has occurred\n", 26);
  }

  if ((write(1, buffer, nread)) != nread)
  {
    write(2, "A write error has occurred\n", 27);
  }

  /*
    $ echo hello languageC | ./a.out
    or
    $ ./a.out < some.txt
    or
    $ ./a.out
    then enter something
    try 24 characters:
    liubin@ubuntu18:~/Documents/coding/linux_programming/chapter3$ ./a.out
      111122223333444455556666
      11112222333344445555liubin@ubuntu18:~/Documents/coding/linux_programming/chapter3$ 6666
      6666: command not found
  */

  exit(0);
}