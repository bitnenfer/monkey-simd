Import simd

Class Matrix4

	Field vecs:Float32x4[4]

	Method New(a:Float = 1.0, b:Float = 0.0, c:Float = 0.0, d:Float = 0.0,
				e:Float = 0.0, f:Float = 1.0, g:Float = 0.0, h:Float = 0.0,
				i:Float = 0.0, j:Float = 0.0, k:Float = 1.0, l:Float = 0.0,
				m:Float = 0.0, n:Float = 0.0, o:Float = 0.0, p:Float = 1.0)
		vecs[0] = SIMD.MakeFloat32x4(a, b, c, d)
		vecs[1] = SIMD.MakeFloat32x4(e, f, g, h)
		vecs[2] = SIMD.MakeFloat32x4(i, j, k, l)
		vecs[3] = SIMD.MakeFloat32x4(m, n, o, p)
	End
	
	Method Add:Void(other:Matrix4)
		SIMD.Add(vecs[0], vecs[0], other.vecs[0])
		SIMD.Add(vecs[1], vecs[1], other.vecs[1])
		SIMD.Add(vecs[2], vecs[2], other.vecs[2])
		SIMD.Add(vecs[3], vecs[3], other.vecs[3])
	End
	
	Method ToString:String()
		Local out:String = ""
		
		Local f0:Float[4]
		Local f1:Float[4]
		Local f2:Float[4]
		Local f3:Float[4]
		
		SIMD.Store(f0, vecs[0])
		SIMD.Store(f1, vecs[1])
		SIMD.Store(f2, vecs[2])
		SIMD.Store(f3, vecs[3])
		
		For Local f:Float = Eachin f0
			out += " " + f
		Next
		out += "~n"
		For Local f:Float = Eachin f1
			out += " " + f
		Next
		out += "~n"
		For Local f:Float = Eachin f2
			out += " " + f
		Next
		out += "~n"
		For Local f:Float = Eachin f3
			out += " " + f
		Next
		out += "~n"
		
		Return out
	End
	
	Method Destroy:Void()
		SIMD.DestroyFloat32x4(vecs[0])
		SIMD.DestroyFloat32x4(vecs[1])
		SIMD.DestroyFloat32x4(vecs[2])
		SIMD.DestroyFloat32x4(vecs[3])
	End
	
End

Function Main:Int()
	Local m0:Matrix4 = New Matrix4()
	Local m1:Matrix4 = New Matrix4()
	
	m0.Add(m1)
	
	Print m0.ToString()
	
	If SIMD.GetReferenceCount() <> 0
		Error("All SIMD vecs must be destroyed")
	Endif
	Return 0
End