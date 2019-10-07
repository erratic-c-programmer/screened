FOR DEVELOPERS:
===============
File inclusion
--------------
all header files in \*\*/headers/ should include all neccesary things,
you should NOT include them. In all .c files(except screened.c), 
ONLY INCLUDE THE HEADER. This also applies when creating new C 
files. All standard headers should be included in include.h,
not from the header files or source files.




Double-inclusion also messes everything up real bad; so please,
in sample.h, have a `#define INCLUDE_SAMPLE` line, and in sample.c
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

Notes
-----
- All functions declared in `screenop/headers/screendraw.h` _only append
to the insert buffer_ -- you must `write()` the append buffer!
- After an output function, please set editor_status.output to 1
- For output operations, you ___must___ use the append buffer(defined
in `iomanip/headers/ibuf.h`), else program will cause segmentation fault!
This happens because `abuf_flush(abuf)` is always called after each output 
operation in `switch` in `prockeypress()`, and if you do not use the append
buffer, it will attempt to `free()` unallocated memory, _quite_ disatorous...

______________________________________________________________
_Also, please follow the laws of UNIX programming and K&R style.
Thanks for helping out!_
______________________________________________________________

FOR USERS:
==========
If you are seeing this, you are not a user. If you are, good luck
getting it working... it's not working yet. Either wait patiently
or make it into a useable text editor(and if you manage that, again,
you're no user; please refer to the 'FOR DEVELOPERS' section)

Thanks to:
==========
[This awesome tutorial](https://viewsourcecode.org/snaptoken/kilo/)
