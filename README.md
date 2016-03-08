# MONKEY-SIMD

About
---

SIMD module / wrapper for Monkey-X. Currently C++ target and experimental JavaScript supported. Tested with MSVC, MinGW and ARM GCC.

This module has been tested with version 85e of Monkey-X.

ARM's NEON tested only on Raspberry PI 2.

SIMD.js is still experimental technology. You can read more about it [here](https://developer.mozilla.org/es/docs/Web/JavaScript/Reference/Global_Objects/SIMD). 

Installation
---

Make a backup of the C++ native file of monkey module. It can be found at *[Monkey Directory]/modules/monkey/native/lang.cpp*.

Copy the file found on *monkey-simd/modules/monkey/native/lang.cpp* into *[Monkey Directory]/modules/monkey/native/lang.cpp*.

This modification of the lang.cpp file includes aligned memory allocations needed by SSE/AVX instructions.

If you are building a project using MinGW you should backup and replace the file *[Monkey Directory]/targets/glfw3/template/gcc_winnt/Makefile* with *monkey-simd/targets/glfw3/template/gcc_winnt/Makefile*

Important
---

The NEON code doesn't implement 

*SIMD_Shuffle*

*SIMD.Sqrt*

*SIMD.Rsqrt*

To test HTML5 target you must have [Firefox Nightly Build](https://nightly.mozilla.org/). A polyfill can be enabled for unsupported browsers using the preprocessor macro **#SIMD_JS_POLYFILL = True**.


Monkey-SIMD API Spec.
---

##### Float32x4

SIMD Plain Old Data.

##### Function SIMD.MakeFloat32x4:Float32x4(x:Float, y:Float, z:Float, w:Float)

Returns a Float32x4 with the intialized x, y, z and w values.

##### Function SIMD.MakeFloat32x4Zero:Float32x4()

Returns a Float32x4 with all values initialized to zero.

##### Function SIMD.MakeFloat32x4Reverse:Float32x4(x:Float, y:Float, z:Float, w:Float)

Returns a Float32x4 with the intialized x, y, z and w values reversed.

##### Function SIMD.MakeFloat32x4One:Float32x4(x:Float)

Returns a Float32x4 with all values initialized to x.

##### Function SIMD.Set:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)

Sets the destination vector values to x, y, z and w.

##### Function SIMD.SetZero:Void(destination:Float32x4)

Sets the destination vector values to zero.

##### Function SIMD.SetOne:Void(destination:Float32x4, x:Float)

Sets the destination vector values to x.

##### Function SIMD.SetReverse:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)

Sets the destination vector values to x, y, z and w in reverse.

##### Function SIMD.Load:Void(destination:Float32x4, source:Float[])

Loads values from a Float array to a Float32x4. The size of the array must be 4 or you might get out of range index exception.

##### Function SIMD.Store:Void(destination:Float[], source:Float32x4)

Stores values from a Float32x4 into a Float array. The size of the array must be 4 or you might get out of range index exception.

##### Function SIMD.Add:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Adds two Float32x4 and stores the result in a destination vector.

##### Function SIMD.Sub:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Subtracts two Float32x4 and stores the result in a destination vector.

##### Function SIMD.Mul:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Multiplies two Float32x4 and stores the result in a destination vector.

##### Function SIMD.Min:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Evaluates the smallest vector values and stores them in a destination vector.

##### Function SIMD.Max:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)	

Evaluates the highest vector values and stores them in a destination vector.

##### Function SIMD.Sqrt:Void(destination:Float32x4, source:Float32x4)

Evaluates the square root of a source vector and stores it at a destination vector.

##### Function SIMD.LogicAnd:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *AND* between to vectors and stores result in destination vector.

##### Function SIMD.LogicAndNot:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *AND-NOT* between to vectors and stores result in destination vector.

##### Function SIMD.LogicOr:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *OR* between to vectors and stores result in destination vector.

##### Function SIMD.LogicXor:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *XOR* between to vectors and stores result in destination vector.

##### Function SIMD.CompareEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare equality between to vectors and stores result in destination vector.

##### Function SIMD.CompareLowerThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare lower than between to vectors and stores result in destination vector.

##### Function SIMD.CompareLowerThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare lower than or equal between to vectors and stores result in destination vector.

##### Function SIMD.CompareGreaterThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare greater than between to vectors and stores result in destination vector.

##### Function SIMD.CompareGreaterThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare greater than or equal between to vectors and stores result in destination vector.

