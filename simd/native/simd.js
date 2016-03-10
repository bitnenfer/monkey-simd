function MONKEY_SIMD_Float32x4() {
	this.vector = null;
}

var MONKEY_SIMD = {
	MakeFloat32x4: function(x, y, z, w) {
		var temp = new MONKEY_SIMD_Float32x4();		
		temp.vector = SIMD.Float32x4(w, z, y, x);
		return temp;
	},
	MakeFloat32x4Zero: function() {
		var temp = new MONKEY_SIMD_Float32x4();
		temp.vector = SIMD.Float32x4.splat(0);
		return temp;
	},
	MakeFloat32x4Reverse: function(x, y, z, w) {
		var temp = new MONKEY_SIMD_Float32x4();
		temp.vector = SIMD.Float32x4(x, y, z, w);
		return temp;
	},
	MakeFloat32x4One: function(x) {
		var temp = new MONKEY_SIMD_Float32x4();
		temp.vector = SIMD.Float32x4.splat(x);
		return temp;
	},
	Set: function(simd_vec, x, y, z, w) {
		simd_vec.vector = SIMD.Float32x4(w, z, y, x);
	},
	SetZero: function(simd_vec) {
		simd_vec.vector = SIMD.Float32x4.splat(0);
	},
	SetOne: function(simd_vec, x) {
		simd_vec.vector = SIMD.Float32x4.splat(x);
	},
	SetReverse: function(simd_vec, x, y, z, w) {
		simd_vec.vector = SIMD.Float32x4(x, y, z, w);
	},
	Load: function(simd_vec, source) {
		simd_vec.vector = SIMD.Float32x4.load(new Float32Array(source), 0);
	},
	Store: function(destination, simd_vec) {
		var tarray = new Float32Array(4);
		SIMD.Float32x4.store(tarray, 0, simd_vec.vector);
		destination.length = 0;
		destination.push.apply(destination, Array.prototype.slice.call(tarray));
	},
	Add: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.add(operandR.vector, operandL.vector);
	},
	Sub: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.sub(operandR.vector, operandL.vector);
	},
	Mul: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.mul(operandR.vector, operandL.vector);
	},
	Min: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.min(operandR.vector, operandL.vector);
	},
	Max: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.max(operandR.vector, operandL.vector);
	},
	Sqrt: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.sqrt(operandR.vector, operandL.vector);
	},
	Rsqrt: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.reciprocalSqrtApproximation(operandR.vector, operandL.vector);
	},
	LogicAnd: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.and(operandR.vector, operandL.vector);
	},
	LogicAndNot: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.not(operandR.vector, operandL.vector);
	},
	LogicOr: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.or(operandR.vector, operandL.vector);
	},
	LogicXor: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.xor(operandR.vector, operandL.vector);
	},
	CompareEqual: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.equal(operandR.vector, operandL.vector);
	},
	CompareLowerThan: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.lessThan(operandR.vector, operandL.vector);
	},
	CompareLowerThanOrEqual: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.lessThanOrEqual(operandR.vector, operandL.vector);
	},
	CompareGreaterThan: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.greaterThan(operandR.vector, operandL.vector);
	},
	CompareGreaterThanOrEqual: function(destination, operandR, operandL) {
		destination.vector = SIMD.Float32x4.greaterThanOrEqual(operandR.vector, operandL.vector);
	},
	GetTarget: function () {return 2;}
};

function MONKEY_SIMD_SHUFFLE(destination, operandR, operandL, x, y, z, w) {
	destination.vector = SIMD.Float32x4.shuffle(operandR.vector, operandL.vector, x, y, z, w);
}