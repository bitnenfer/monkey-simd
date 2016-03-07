# MONKEY-SIMD

About
---

SIMD module / wrapper for Monkey-X. Currently only C++ target supported. Tested with MSVC and MinGW.

This module has been tested with version 85e of Monkey-X.

Good resource:

[Intel's Intrisics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)

Installation
---

Make a backup of the C++ native file of monkey module. It can be found at *[Monkey Directory]/modules/monkey/native/lang.cpp*.

Copy the file found on *monkey-simd/modules/monkey/native/lang.cpp* into *[Monkey Directory]/modules/monkey/native/lang.cpp*.

This modification of the lang.cpp file includes aligned memory allocations needed by SSE/AVX instructions.

If you are building a project using MinGW you should backup and replace the file *[Monkey Directory]/targets/glfw3/template/gcc_winnt/Makefile* with *monkey-simd/targets/glfw3/template/gcc_winnt/Makefile*
