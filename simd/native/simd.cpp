#include <immintrin.h>

#if _MSC_VER
	#define SSE_ALIGN16 __declspec(align(16))
	#define FORCE_INLINE __forceinline
#else
	#define SSE_ALIGN16 __attribute__((aligned(16)))
	#define FORCE_INLINE __attribute__((always_inline))
#endif

#ifndef _MM_SHUFFLE
#define _MM_SHUFFLE(z, y, x, w) (z<<6) | (y<<4) | (x<<2) | w
#endif

struct SSE_Float32x4 : public Object
{
	__m128 vector;
};

struct SIMD
{	// SSE_Float32x4 Factory
	FORCE_INLINE static SSE_Float32x4* MakeFloat32x4(float x, float y, float z, float w)
	{
		SSE_Float32x4* vector = new SSE_Float32x4;
		Set(vector, x, y, z, w);
		return vector;
	}
	FORCE_INLINE static SSE_Float32x4* MakeFloat32x4Zero()
	{
		SSE_Float32x4* vector = new SSE_Float32x4;
		SetZero(vector);
		return vector;
	}
	FORCE_INLINE static SSE_Float32x4* MakeFloat32x4Reverse(float x, float y, float z, float w)
	{
		SSE_Float32x4* vector = new SSE_Float32x4;
		SetReverse(vector, x, y, z, w);
		return vector;
	}
	FORCE_INLINE static SSE_Float32x4* MakeFloat32x4One(float x)
	{
		SSE_Float32x4* vector = new SSE_Float32x4;
		SetOne(vector, x);
		return vector;
	}
	// SSE_Float32x4 Set Operations
	FORCE_INLINE static void Set(SSE_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		vector_ptr->vector = _mm_set_ps(x, y, z, w);
	}
	FORCE_INLINE static void SetZero(SSE_Float32x4* vector_ptr)
	{
		vector_ptr->vector = _mm_setzero_ps();
	}
	FORCE_INLINE static void SetOne(SSE_Float32x4* vector_ptr, float x)
	{
		vector_ptr->vector = _mm_set1_ps(x);
	}
	FORCE_INLINE static void SetReverse(SSE_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		vector_ptr->vector = _mm_setr_ps(x, y, z, w);
	}
	// SSE_Float32x4 Load Operations
	FORCE_INLINE static void Load(SSE_Float32x4* vector_ptr, Array<Float> monkey_array)
	{
	#if CFG_CPP_DOUBLE_PRECISION_FLOATS
		SSE_ALIGN16 float float32_array[4];
		float32_array[0] = monkey_array[0];
		float32_array[1] = monkey_array[1];
		float32_array[2] = monkey_array[2];
		float32_array[3] = monkey_array[3];
		vector_ptr->vector = _mm_load_ps(float32_array);
	#else
		vector_ptr->vector = _mm_loadu_ps(&monkey_array[0]);
	#endif
	}
	// SSE_Float32x4 Store Operations
	FORCE_INLINE static void Store(Array<Float> monkey_array, SSE_Float32x4* vector_ptr)
	{
	#if CFG_CPP_DOUBLE_PRECISION_FLOATS
		SSE_ALIGN16 float float32_array[4];
		_mm_store_ps(float32_array, vector_ptr->vector);
		monkey_array[0] = float32_array[0];
		monkey_array[1] = float32_array[1];
		monkey_array[2] = float32_array[2];
		monkey_array[3] = float32_array[3];
	#else
		_mm_storeu_ps(&monkey_array[0], vector_ptr->vector);
	#endif
	}
	// SSE_Float32x4 Arithmetic Operations
	FORCE_INLINE static void Add(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_add_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Sub(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_sub_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Mul(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_mul_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Div(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_div_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Sqrt(SSE_Float32x4* destination, SSE_Float32x4* source)
	{
		destination->vector = _mm_sqrt_ps(source->vector);
	}
	FORCE_INLINE static void Rsqrt(SSE_Float32x4* destination, SSE_Float32x4* source)
	{
		destination->vector = _mm_rsqrt_ps(source->vector);
	}
	FORCE_INLINE static void Min(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_min_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Max(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_max_ps(operand0->vector, operand1->vector);
	}
	// SSE_Float32x4 Logical Operations
	FORCE_INLINE static void BAnd(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_and_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void BAndNot(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_andnot_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void BOr(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_or_ps(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void BXor(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_xor_ps(operand0->vector, operand1->vector);
	}
	// Shuffle Macro
#define SIMD_SHUFFLE(destination, operand0, operand1, mask) destination->vector = _mm_shuffle_ps(operand0->vector, operand1->vector, mask);
};