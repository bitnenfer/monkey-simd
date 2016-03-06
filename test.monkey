Import simd

Function Main:Int()
	Local v0:Float32x4 = SIMD.MakeFloat32x4(1, 2, 3, 4)
	Local v1:Float32x4 = SIMD.MakeFloat32x4(5, 5, 5, 5)
	Local sv:Float[4]
	SIMD.Mul(v0, v0, v1)
	SIMD.Store(sv, v0)
	Local out:String = ""
	For Local f:Float = Eachin sv
		out += " " + f
	Next
	Print out
	Return 0
End