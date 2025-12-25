#include "za3.h"
#include <cmath>

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

Point::~Point()
{
}

void Point::Print() const
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

Point3D::Point3D() : Point(), z(0)
{
}

Point3D::Point3D(double x, double y, double z) : Point(x, y), z(z)
{
}

Point3D::~Point3D()
{
}

double Point3D::Distance(const Point3D& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

void Point3D::Print() const
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
