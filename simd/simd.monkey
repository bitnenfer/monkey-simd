#If LANG<>"cpp"
#Error "SIMD only supported on C++ targets"
#Endif

#CPP_MEM_ALIGNMENT = 16
#CPP_USE_ALIGNED_ALLOC = True
' Enable sse for gcc/mingw

#If TARGET="android" Or TARGET="ios"
' Use ARM's NEON
#CC_OPTS = "-mfpu=neon"
Import "native/simd.neon.cpp"
#Else
' Use SSE/AVX
#CC_OPTS = "-msse"
Import "native/simd.cpp"
#Endif

Extern 

Class @Float32x4 Extends Object="SIMD_Float32x4"
End

Class SIMD
	' Float32x4 Factory
	Function MakeFloat32x4:Float32x4(x:Float, y:Float, z:Float, w:Float)
	Function MakeFloat32x4Zero:Float32x4()
	Function MakeFloat32x4Reverse:Float32x4(x:Float, y:Float, z:Float, w:Float)
	Function MakeFloat32x4One:Float32x4(x:Float)
	' Float32x4 Set Operations
	Function Set:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)
	Function SetZero:Void(destination:Float32x4)
	Function SetOne:Void(destination:Float32x4, x:Float)
	Function SetReverse:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)
	' Float32x4 Load and Store
	Function Load:Void(destination:Float32x4, source:Float[])
	Function Store:Void(destination:Float[], source:Float32x4)
	' Float32x4 Arithmetic
	Function Add:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Sub:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Mul:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Min:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Max:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)	
	Function Sqrt:Void(destination:Float32x4, source:Float32x4)
	Function Rsqrt:Void(destination:Float32x4, source:Float32x4)
	' Float32x4 Logical Operations
	Function LogicAnd:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function LogicAndNot:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function LogicOr:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function LogicXor:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	' Float32x4 Compare Operations
	Function CompareEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function CompareLowerThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function CompareLowerThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function CompareGreaterThan:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function CompareGreaterThanOrEqual:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
End

' Float32x4 Shuffle.
Function SIMD_Shuffle:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4, mask:Int) = "SIMD_SHUFFLE"
Function SIMD_ShuffleHelper:Int(x:Int, y:Int, z:Int, w:Int) = "_MM_SHUFFLE"
