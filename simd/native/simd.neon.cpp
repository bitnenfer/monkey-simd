#include <arm_neon.h>

#define NEON_ALIGN16 __attribute__((aligned(16)))
#define FORCE_INLINE __attribute__((always_inline))

struct SIMD_Float32x4 : public Object
{
	float32x4_t vector;
};

struct SIMD
{
	// SIMD_Float32x4 Factory
	FORCE_INLINE static SIMD_Float32x4* MakeFloat32x4(float x, float y, float z, float w)
	{
		SIMD_Float32x4* vector = new SIMD_Float32x4;
		Set(vector, x, y, z, w);
		return vector;
	}
	FORCE_INLINE static SIMD_Float32x4* MakeFloat32x4Zero()
	{
		SIMD_Float32x4* vector = new SIMD_Float32x4;
		SetZero(vector);
		return vector;
	}
	FORCE_INLINE static SIMD_Float32x4* MakeFloat32x4Reverse(float x, float y, float z, float w)
	{
		SIMD_Float32x4* vector = new SIMD_Float32x4;
		SetReverse(vector, x, y, z, w);
		return vector;
	}
	FORCE_INLINE static SIMD_Float32x4* MakeFloat32x4One(float x)
	{
		SIMD_Float32x4* vector = new SIMD_Float32x4;
		SetOne(vector, x);
		return vector;
	}
	// SIMD_Float32x4 Set Operations
	FORCE_INLINE static void Set(SIMD_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		const float32_t ptr[4] = {x, y, z, w};
		vector_ptr->vector = vld1q_f32(ptr);
	}
	FORCE_INLINE static void SetZero(SIMD_Float32x4* vector_ptr)
	{
		vector_ptr->vector = vdupq_n_f32(0);
	}
	FORCE_INLINE static void SetOne(SIMD_Float32x4* vector_ptr, float x)
	{
		vector_ptr->vector = vdupq_n_f32(x);
	}
	FORCE_INLINE static void SetReverse(SIMD_Float32x4* vector_ptr, float x, float y, float z, float w)
	{
		const float32_t ptr[4] = {w, z, y, x};
		vector_ptr->vector = vld1q_f32(ptr);
	}
	// SIMD_Float32x4 Load Operations
	FORCE_INLINE static void Load(SIMD_Float32x4* vector_ptr, Array<Float> monkey_array)
	{
	#if CFG_CPP_DOUBLE_PRECISION_FLOATS
		NEON_ALIGN16 const float32_t float32_array[4];
		float32_array[0] = monkey_array[0];
		float32_array[1] = monkey_array[1];
		float32_array[2] = monkey_array[2];
		float32_array[3] = monkey_array[3];
		
		vector_ptr->vector = vld1_f32(float32_array);
	#else
		vector_ptr->vector = vld1_f32(&monkey_array[0]);
	#endif
	}
	// SIMD_Float32x4 Store Operations
	FORCE_INLINE static void Store(Array<Float> monkey_array, SIMD_Float32x4* vector_ptr)
	{
	#if CFG_CPP_DOUBLE_PRECISION_FLOATS
		NEON_ALIGN16 float32_t float32_array[4];
		vst1_f32(float32_array, vector_ptr->vector);
		monkey_array[0] = float32_array[0];
		monkey_array[1] = float32_array[1];
		monkey_array[2] = float32_array[2];
		monkey_array[3] = float32_array[3];
	#else
		vst1_f32(&monkey_array[0], vector_ptr->vector);
	#endif
	}
	// SIMD_Float32x4 Arithmetic Operations
	FORCE_INLINE static void Add(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = vaddq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Sub(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = vsubq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Mul(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = vmulq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Sqrt(SIMD_Float32x4* destination, SIMD_Float32x4* source)
	{
		// No implementation.
	}
	FORCE_INLINE static void Rsqrt(SIMD_Float32x4* destination, SIMD_Float32x4* source)
	{
		destination->vector = vrsqrtsq_f32(source->vector);
	}
	FORCE_INLINE static void Min(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = vminq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void Max(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = vmaxq_f32(operand0->vector, operand1->vector);
	}
	// SIMD_Float32x4 Logical Operations
	FORCE_INLINE static void LogicAnd(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vandq_s32((int32x4_t)operand0->vector, (int32x4_t)operand1->vector);
	}
	FORCE_INLINE static void LogicAndNot(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vbicq_s32((int32x4_t)operand0->vector, (int32x4_t)operand1->vector);
	}
	FORCE_INLINE static void LogicOr(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vorrq_s32((int32x4_t)operand0->vector, (int32x4_t)operand1->vector);
	}
	FORCE_INLINE static void LogicXor(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)veorq_s32((int32x4_t)operand0->vector, (int32x4_t)operand1->vector);
	}
		// Compare instructions
	FORCE_INLINE static void CompareEqual(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vceqq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void CompareLowerThan(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vcltq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void CompareLowerThanOrEqual(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vcleq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void CompareGreaterThan(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vcgtq_f32(operand0->vector, operand1->vector);
	}
	FORCE_INLINE static void CompareGreaterThanOrEqual(SIMD_Float32x4* destination, SIMD_Float32x4* operand0, SIMD_Float32x4* operand1)
	{
		destination->vector = (float32x4_t)vcgeq_f32(operand0->vector, operand1->vector);
	}
	// Shuffle Macro
	#define SIMD_SHUFFLE(destination, operand0, operand1, mask)
	#define _MM_SHUFFLE(x, y, z, w)
};