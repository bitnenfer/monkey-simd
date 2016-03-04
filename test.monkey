Import simd

Function Main:Int()
	Local vector0:Float32x4 = SIMD.MakeFloat32x4(1, 2, 3, 4)
	Local copy:Float[4]
	SIMD_Shuffle(vector0, vector0, vector0, SIMD_ShuffleHelper(2, 2, 2, 2))
	SIMD.Store(copy, vector0)	
	For Local f:Float = Eachin copy
		Print "" + f
	Next
	Return 0
End