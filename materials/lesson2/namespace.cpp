#include "stdafx.h"

namespace Shapes
{
    class Shape {};

    namespace Shapes2D
    {
        class Triangle {};
        class Rectangle {};
    }

    namespace Shapes3D
    {
        class Shpere {};
        class Cube {};
    }
}

int main()
{
    Shapes::Shapes2D::Rectangle rectangle;
    Shapes::Shapes3D::Cube cube;

    return 0;
}