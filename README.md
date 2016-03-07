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

SIMD API Spec.
---

#### Float32x4

SIMD Pure old data.

#### Function MakeFloat32x4:Float32x4(x:Float, y:Float, z:Float, w:Float)

Returns a Float32x4 with the intialized x, y, z and w values.

#### Function MakeFloat32x4Zero:Float32x4()

Returns a Float32x4 with all values initialized to zero.

#### Function MakeFloat32x4Reverse:Float32x4(x:Float, y:Float, z:Float, w:Float)

Returns a Float32x4 with the intialized x, y, z and w values reversed.

#### Function MakeFloat32x4One:Float32x4(x:Float)

Returns a Float32x4 with all values initialized to x.

#### Function Set:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)

Sets the destination vector values to x, y, z and w.

#### Function SetZero:Void(destination:Float32x4)

Sets the destination vector values to zero.

#### Function SetOne:Void(destination:Float32x4, x:Float)

Sets the destination vector values to x.

#### Function SetReverse:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)

Sets the destination vector values to x, y, z and w in reverse.

#### Function Load:Void(destination:Float32x4, source:Float[])

Loads values from a Float array to a Float32x4. The size of the array must be 4 or you might get out of range index exception.

#### Function Store:Void(destination:Float[], source:Float32x4)

Stores values from a Float32x4 into a Float array. The size of the array must be 4 or you might get out of range index exception.

#### Function Add:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Adds two Float32x4 and stores the result in a destination vector.

#### Function Sub:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Subtracts two Float32x4 and stores the result in a destination vector.

#### Function Mul:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Multiplies two Float32x4 and stores the result in a destination vector.

#### Function Div:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Divides two Float32x4 and stores the result in a destination vector.

#### Function Min:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Evaluates the smallest vector values and stores them in a destination vector.

#### Function Max:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)	

Evaluates the highest vector values and stores them in a destination vector.

#### Function Sqrt:Void(destination:Float32x4, source:Float32x4)

Evaluates the square root of a source vector and stores it at a destination vector.

#### Function LogicAnd:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *AND* between to vectors and stores result in destination vector.

#### Function LogicAndNot:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *AND-NOT* between to vectors and stores result in destination vector.

#### Function LogicOr:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *OR* between to vectors and stores result in destination vector.

#### Function LogicXor:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Computes a logical *XOR* between to vectors and stores result in destination vector.

#### Function CompareEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare equality between to vectors and stores result in destination vector.

#### Function CompareLowerThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare lower than between to vectors and stores result in destination vector.

#### Function CompareLowerThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare lower than or equal between to vectors and stores result in destination vector.

#### Function CompareGreaterThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare greater than between to vectors and stores result in destination vector.

#### Function CompareGreaterThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare greater than or equal between to vectors and stores result in destination vector.

#### Function CompareNotEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare not equal between to vectors and stores result in destination vector.

#### Function CompareNotLessThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare not less than between to vectors and stores result in destination vector.

#### Function CompareNotLessThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare not less than or equal between to vectors and stores result in destination vector.

#### Function CompareNotGreaterThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare not greater than between to vectors and stores result in destination vector.

#### Function CompareNotGreaterThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)

Compare not greater than or equal between to vectors and stores result in destination vector.
