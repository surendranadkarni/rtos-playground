# rtos-playground
## Export path 
    in my case
    $ export PATH=$PATH:/disk_1/surendra/work/software/arm_tool_chain/arm/bin

## compile
    $ make
## flash
    $ lpc21isp -control  -hex main.hex /dev/ttyUSB0 9600 14746

## test
p1.24 to 31 will be configured as output port. you may test using LED.
connect serial port0 to PC and check if PC recieves serial data.

##configuration
### check crystal and configure clock
    check #define configCPU_CLOCK_HZ


