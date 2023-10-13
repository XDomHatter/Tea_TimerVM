# Tea_TimerVM

A new language like Java but without any more code!

## Compile

### Environment

First, you need CMake(>=3.21) and CPP environment.

+ CPP environment
  First, run `g++ -v` to detect if CPP environment is already installed.
  If system cannot find `g++` command, you should install it.
  - Windows
    MinGW - [Downloads - MinGW-w64](https://www.mingw-w64.org/downloads/)
  - MacOS
    You can install xcode for CPP environment, [Download XCode here](https://developer.apple.com/download).
  - Unix/Linux
    Simplest, you can run these command to install GCC.
    ```bash
    # debian
    sudo apt install gcc
    # centos
    sudo yum install gcc
    # arch
    sudo pacman -S gcc
    ```

+ CMake

  Run `cmake -v` to detect if CMake is installed.
  if not,go to website to [Download CMake](https://cmake.org/download/).

### Compile

```bash
cd path/to/src # cd to working dictionary
mkdir bin && cd bin
cmake -G"XXXX" .. # Choose the makefile format you like
cmake --build .
```

When you choose the makefiles format:

+ Unix/Linux/MacOS => "CodeBlocks - Unix Makefiles"
+ Windows => "CodeBlocks - MinGW Makefiles"

Then, you have got the Tea_TimerVM release!