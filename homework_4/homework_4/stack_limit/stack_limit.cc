#include <iostream>

int main() {
  int step = 100 * 1000 * sizeof(char);
  int size = step;
  while (true) {
    std::cerr << size << std::endl;
    double arr[size];
    arr[0] = 2;
    arr[1] = arr[0] + 4;

    size += step;
  } 

  return 0;
}