#include "Vector3.h"
#include "cube_funcs.h"

void Vector3<int64_t>::LoadFromVector3_float(Vector3<float>* vf)
{
	cube_funcs::instance()->vec3_int64_fom_vec3_float(this, vf);
};
