# standalone ko
A simple `.c` file that can be compiled to a kernel module
without any header files.

### Build
```sh
gcc -c -o standalone.ko standalone.c
```

### Load
```sh
insmod standalone.ko
lsmod | grep 'standalone'
dmesg
```

### Portability
Designed to run on Ubuntu 18.04.
For different kernels, adjust the required values accordingly.
