#include <immintrin.h>

#if defined(__GNUC__) || defined(__GNUG__)
#define SSE_ALIGN16 __attribute__((aligned(16)))
#elif defined(_MSC_VER)
#define SSE_ALIGN16 __declspec(align(16))
#else
#defien SSE_ALIGN16
#endif

#ifndef _MM_SHUFFLE
#define _MM_SHUFFLE(z, y, x, w) (z<<6) | (y<<4) | (x<<2) | w
#endif

struct SSE_Float32x4 : public Object
{
	// We don't have aligned allocation on
	// Monkey-X. So we must handle memory ourselfs.
	// Maybe implement a custom allocator just for 
	// SIMD types
	void* operator new (size_t size){
		++SSE_Float32x4::ref_count;
	return _aligned_malloc(size, 16);
	}
		void operator delete (void* p)
	{
		--SSE_Float32x4::ref_count;
		_aligned_free(p);
	}
	__m128 vector;
	static int ref_count;
};
int SSE_Float32x4::ref_count = 0;

struct SIMD
{
	static inline void DestroyFloat32x4(SSE_Float32x4*& pref)
	{
		delete pref;
	}
	// SSE_Float32x4 Factory
	static inline SSE_Float32x4* MakeFloat32x4(float x, float y, float z, float w)
	{
		SSE_ALIGN16 SSE_Float32x4* vector = new SSE_Float32x4;
		Set(vector, x, y, z, w);
		return vector;
	}
	static inline SSE_Float32x4* MakeFloat32x4Zero()
	{
		SSE_ALIGN16 SSE_Float32x4* vector = new SSE_Float32x4;
		SetZero(vector);
		return vector;
	}
	static inline SSE_Float32x4* MakeFloat32x4Reverse(float x, float y, float z, float w)
	{
		SSE_ALIGN16 SSE_Float32x4* vector = new SSE_Float32x4;
		SetReverse(vector, x, y, z, w);
		return vector;
	}
	static inline SSE_Float32x4* MakeFloat32x4One(float x)
	{
		SSE_ALIGN16 SSE_Float32x4* vector = new SSE_Float32x4;
		SetOne(vector, x);
		return vector;
	}
	// SSE_Float32x4 Set Operations
	static inline void Set(SSE_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		vector_ptr->vector = _mm_set_ps(x, y, z, w);
	}
	static inline void SetZero(SSE_Float32x4* vector_ptr)
	{
		vector_ptr->vector = _mm_setzero_ps();
	}
	static inline void SetOne(SSE_Float32x4* vector_ptr, float x)
	{
		vector_ptr->vector = _mm_set1_ps(x);
	}
	static inline void SetReverse(SSE_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		vector_ptr->vector = _mm_setr_ps(x, y, z, w);
	}
	// SSE_Float32x4 Load Operations
	static inline void Load(SSE_Float32x4* vector_ptr, Array<Float> monkey_array)
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
	static inline void Store(Array<Float> monkey_array, SSE_Float32x4* vector_ptr)
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
	static inline void Add(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_add_ps(operand0->vector, operand1->vector);
	}
	static inline void Sub(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_sub_ps(operand0->vector, operand1->vector);
	}
	static inline void Mul(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_mul_ps(operand0->vector, operand1->vector);
	}
	static inline void Div(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_div_ps(operand0->vector, operand1->vector);
	}
	static inline void Sqrt(SSE_Float32x4* destination, SSE_Float32x4* source)
	{
		destination->vector = _mm_sqrt_ps(source->vector);
	}
	static inline void Rsqrt(SSE_Float32x4* destination, SSE_Float32x4* source)
	{
		destination->vector = _mm_rsqrt_ps(source->vector);
	}
	static inline void Min(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_min_ps(operand0->vector, operand1->vector);
	}
	static inline void Max(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_max_ps(operand0->vector, operand1->vector);
	}
	// SSE_Float32x4 Logical Operations
	static inline void BAnd(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_and_ps(operand0->vector, operand1->vector);
	}
	static inline void BAndNot(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_andnot_ps(operand0->vector, operand1->vector);
	}
	static inline void BOr(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_or_ps(operand0->vector, operand1->vector);
	}
	static inline void BXor(SSE_Float32x4* destination, SSE_Float32x4* operand0, SSE_Float32x4* operand1)
	{
		destination->vector = _mm_xor_ps(operand0->vector, operand1->vector);
	}
	// Shuffle Macro
#define SIMD_SHUFFLE(destination, operand0, operand1, mask) destination->vector = _mm_shuffle_ps(operand0->vector, operand1->vector, mask);
	// Ref count
	static inline unsigned int GetReferenceCount()
	{
		return SSE_Float32x4::ref_count;
	}
};