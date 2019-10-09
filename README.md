# FOR DEVELOPERS:
## Programming
### File inclusion
all header files in `**/headers/` should include all neccesary things,
you should NOT include them. In all .c files(except `screened.c`), 
ONLY INCLUDE THE HEADER. This also applies when creating new C 
files. All standard headers should be included in `include.h`,
not from the header files or source files.

Double-inclusion also messes everything up real bad; so please,
in sample.h, have a `#define INCLUDE_SAMPLE` line, and in `sample.c`
have
```c
#ifndef INCLUDE_SAMPLE
#include "headers/sample.h"
#endif
```
to prevent double-inclusion.



```c
#ifndef INCLUDE_TESTFEATURE
#include "headers/testfeature.h"
#endif

int testfeature()
{
...
...
}
```

This file should not contain any other `#include` lines!



```c
#include "...whatever header files needed by newfeatures/testfeature.c"
#include "../../include.h"
#define INCLUDE_TESTFEATURE
int testfeature();
```

### Notes(important, please read!)
- All functions declared in `screenop/headers/screendraw.h` _only append
to the insert buffer_ -- you must `write()` the append buffer!
- After any output function, you ___must___ set `editor_status.output` to 1
- For output operations, you ___must___ use the append buffer(defined
in `iomanip/headers/ibuf.h`), else program will cause segmentation fault!
This happens because `abuf_flush(abuf)` is always called after each output 
operation in `switch` in `prockeypress()`, and if you do not use the append
buffer, it will attempt to `free()` unallocated memory, _quite_ disatorous...

## Compiling
_This may fit better under the 'FOR USERS' section, but to me, users usually
do not compile their own programs. So I decided to put this bit here instead._
### Operating system
This program is designed to run under UNIX-like operating systems(specifically
Linux, thought I'm not so sure abouut the BSDs and MacOS), not Windows! to compile
and run for Windows, you can either:
1. Install Linux alongside Windows, then compile and runon the new Linux system.
2. Wipe you hard drive and free it of Microsoft cruft, then install Linux(This
is the preferred method). Then, compile and run on the new Linux system.
3. Install [Cygwin](https://cygwin.com) (This is the least preferred method as 
there may be some incompatibilities, and it's alsp __much__ slower), note that 
MinGW is not enough!
4. Use WSL. This is specific to Windows 10.

If you chose option 3 or 4, you should seriously consider options 1 and 2
first.  2 can almost completely free you from Micro$oft's grasp, but if you
don't like the idea of entirely overwriting your hard drive, then at
least try 1...

### Running `make`
_All compiling and linking done with GNU GCC 9.2.0, static library
creation done with GNU ar 2.32. This is GNU make 4.2.1._

There is already a `Makefile` included. It basically does a few things:
1. compile sources in `iomanip/` to object files located in `iomanip/objects`
2. compile sources in `screenop/` to object files located in `screenop/objects`
3. use object files in `iomanip/objects` to create static
library `lib/iomanip.a`
4. use object files in `screenop/objects` to create static
library `lib/screenop.a`
5. compile screened.c to object file screened.o
6. link screened.o with static libraries in lib/ to produce binary executable
screened
______________________________________________________________
_Also, please follow the laws of UNIX programming and K&R style.
Thanks for helping out!_
______________________________________________________________

# FOR USERS:
If you are seeing this, you are not a user. If you are, good luck
getting it working... it's not working yet. Either wait patiently
or make it into a useable text editor(and if you manage that, again,
you're no user; please refer to the 'FOR DEVELOPERS' section)

# Thanks to:
[This awesome tutorial](https://viewsourcecode.org/snaptoken/kilo/)
