#pragma once
#include <cstdint>


template <typename T>
class Vector3
{
public:
	T X = 0;
	T Y = 0;
	T Z = 0;

	Vector3() {};
	Vector3(T x, T y, T z) : X(x), Y(y), Z(z) {};
	~Vector3() {};
};

/*
// Class specialization for int64_t, mainly used for world positions, so special functions on there.
template <>
class Vector3<int64_t> {
public:
	int64_t X = 0;
	int64_t Y = 0;
	int64_t Z = 0;
	Vector3() {};
	Vector3(int64_t x, int64_t y, int64_t z) : X(x), Y(y), Z(z) {}
	~Vector3() {};
	void LoadFromVector3_float(Vector3<float>* vf);
};
*/



