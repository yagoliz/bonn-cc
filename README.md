# Modern C++ course

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/2ad2c9956a6b43a5a63747f33b35d5b7)](https://app.codacy.com/app/yagoliz/bonn-cc?utm_source=github.com&utm_medium=referral&utm_content=yagoliz/bonn-cc&utm_campaign=Badge_Grade_Dashboard)

This repository contains my solutions to the exercises from the [Modern C++ course](https://www.ipb.uni-bonn.de/teaching/modern-cpp/).

## Compiling
To compile an example, go inside one of the directories and do the following:
``` bash
~/bonn-c++$ cd homework_2/igg_image
~/bonn-c++/homework_2/igg_image$ mkdir build && cd build
~/bonn-c++/homework_2/igg_image/build$ cmake .. && make
```

## Running
The executable is placed under the ```bin/``` directory. To run it simply:
``` bash
~/bonn-c++$ cd homework_2/igg_image/bin
~/bonn-c++/homework_2/igg_image/bin$ ./main
```