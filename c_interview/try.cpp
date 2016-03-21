#include <stdio.h>
#include <string>
using namespace std;

int main ()
{
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  string buffer2=buffer;
  printf ("[%s] is a string %d chars long\n",buffer2.c_str(),n);
  return 0;
}
