#include "Curve3D.h"

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector) {
    stream << std::fixed << std::setprecision(3);
    stream << "{" << vector.x << ", " << vector.y << ", " << vector.z << "}";
    return stream;
}