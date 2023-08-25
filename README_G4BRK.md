## Build and debug g4brk code

build libs in ~/github/HL2IOBoard_G4BRK/g4brk_lib/build

build main in ~/github/HL2IOBoard_G4BRK/g4brk_k3band/build

> cmake ..
> 
> make

Restart pico with boot button pressed (no pwr on HL2), 
then drag the .uf2 created into the pico drive that gets mounted


To debug using printfs, install minicom, then connect to the pico using the
same USB lead.

sudo apt install minicom

minicom -b 115200 -o -D /dev/ttyACM0

your tty port may vary!

