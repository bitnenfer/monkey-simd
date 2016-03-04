#If LANG<>"cpp"
#Error "SIMD only supported on C++ targets"
#Endif

Import "native/simd.${LANG}"

Extern 

Class @Float32x4 Extends Object="SSE_Float32x4"
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
	Function SetOne:Void(destination:Float32x4)
	Function SetReverse:Void(destination:Float32x4, x:Float, y:Float, z:Float, w:Float)
	' Float32x4 Load and Store
	Function Load:Void(destination:Float32x4, source:Float[])
	Function Store:Void(destination:Float[], source:Float32x4)
	' Float32x4 Arithmetic
	Function Add:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Sub:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Mul:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Div:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Min:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function Max:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)	
	Function Sqrt:Void(destination:Float32x4, source:Float32x4)
	Function Rsqrt:Void(destination:Float32x4, source:Float32x4)
	' Float32x4 Logical Operations
	Function BAnd:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function BAndNot:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function BOr:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
	Function BXor:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4)
End

' Float32x4 Shuffle
Function SIMD_Shuffle:Void(destination:Float32x4, operandR:Float32x4, operandL:Float32x4, mask:Int) = "SIMD_SHUFFLE"
Function SIMD_ShuffleHelper:Int(x:Int, y:Int, z:Int, w:Int) = "_MM_SHUFFLE"
