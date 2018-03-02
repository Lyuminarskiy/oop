namespace Shapes
{
    class Shape {};

    namespace Shapes2D
    {
        class Shape2D : public Shape {};
        class Triangle : public Shape2D {};
        class Rectangle : public Shape2D {};
    }

    namespace Shapes3D
    {
        class Shape3D : public Shape {};
        class Shpere : public Shape3D {};
        class Cube : public Shape3D {};
    }
}

using namespace Shapes;

int main()
{
    Shapes2D::Rectangle rectangle;
    Shapes3D::Cube cube;

    return 0;
}