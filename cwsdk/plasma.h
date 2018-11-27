#pragma once

#include "assert_size.h"

#include "plasma\Vector.h"
#include "plasma\Matrix.h"
#include "plasma\DiscreteAttribute.h"
#include "plasma\ContinuousAttribute.h"
#include "plasma\ContinuousArrayAttribute.h"

#include "plasma\Attribute.h"
#include "plasma\Object.h"
#include "plasma\NamedObject.h"
#include "plasma\Widget.h"
#include "plasma\Keyable.h"
#include "plasma\Shape.h"
#include "plasma\MeshShape.h"
#include "plasma\SmoothMeshShape.h"
#include "plasma\Transformation.h"
#include "plasma\Display.h"
#include "plasma\Node.h"

assert_size(plasma::Attribute, 0x48)
assert_size(plasma::Object, 0xC)
assert_size(plasma::NamedObject, 0x24)
assert_size(plasma::Node, 0xF0)
assert_size(plasma::Widget, 0x160)
assert_size(plasma::Keyable, 0x48)
assert_size(plasma::Shape, 0x5C)
assert_size(plasma::MeshShape, 0x8E4)
assert_size(plasma::SmoothMeshShape, 0xC34)
assert_size(plasma::Transformation, 0x234)
assert_size(plasma::Display, 0x210)

/*
assert_size(plasma::Attribute, 0x48)
assert_size(plasma::Object, 0xC)
    assert_size(plasma::NamedObject, 0x24)
        assert_size(plasma::Node, 0xF0)
        assert_size(plasma::Widget, 0x160)
        assert_size(plasma::Keyable, 0x48)
            assert_size(plasma::Shape, 0x5C)
                assert_size(plasma::MeshShape, 0x8E4)
                    assert_size(plasma::SmoothMeshShape, 0xC34)
            assert_size(plasma::Transformation, 0x234)
            assert_size(plasma::Display, 0x210)
*/