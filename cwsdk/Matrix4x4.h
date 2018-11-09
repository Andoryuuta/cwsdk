#pragma once

#include "Vector3.h"
#include <math.h>

struct Matrix4x4 {
	// Thrown together from 
	// https://gamedev.stackexchange.com/questions/50963/how-to-extract-euler-angles-from-transformation-matrix
	// and
	// http://nghiaho.com/?page_id=846
	union {
		struct
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;
		};
		float m[4][4];
	};
};