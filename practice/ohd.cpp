// std::cout, std::dec, std::hex, std::oct

#include <iostream>     

typedef unsigned char byte;

int main () {
  //byte n[4];
  int n[4];
  for(int i=0;i<4;i++)
  {
    n[i]=100+i;
  }
  std::cout << std::hex << n[0] << n[1] << n[2] << n[3]<< std::dec << std::endl;
  std::cout << n[0] << n[1] << n[2] << n[3]<< std::endl;
  return 0;
}