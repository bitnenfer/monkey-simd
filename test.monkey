#SIMD_JS_POLYFILL = True
Import simd
Import mojo

Class SimdSample Extends App

	Field v0:Float32x4 = SIMD.MakeFloat32x4(1, 2, 3, 4)
	Field v1:Float32x4 = SIMD.MakeFloat32x4(5, 5, 5, 5)
	Field sv:Float[4]
	
	Method OnCreate:Int()
		Print "Created"
		SIMD.Mul(v0, v0, v1)
		SIMD.Store(sv, v0)
		SetUpdateRate(60)
		Return 0
	End
	
	Method OnRender:Int()
		Cls()
		PushMatrix()
		Scale(2, 2)
		Local out:String = ""
		For Local f:Float = Eachin sv
			out += " " + f
		Next
		DrawText(out, 0, 0)
		If (SIMD.GetTarget() = SIMDTarget.NEON)
			DrawText("Current SIMD Target is NEON", 0, 14)
		Elseif (SIMD.GetTarget() = SIMDTarget.SSE)
			DrawText("Current SIMD Target is SSE", 0, 14)
		Elseif (SIMD.GetTarget() = SIMDTarget.SIMD_JS)
			DrawText("Current SIMD Target is SIMD JS", 0, 14)
		Else
			DrawText("Invalid", 0, 14)
		Endif
		PopMatrix()
		Return 0
	End
End

Function Main:Int()
	New SimdSample()
	Return 0
End