#ifndef CURVE3D_H
#define CURVE3D_H

#include <cmath>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>

constexpr double PI = 3.14159265358979323846;

struct Vector3D {
	double x;
	double y;
	double z;
};

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector);

class Curve3D {
public:
	virtual ~Curve3D() = default;

	virtual std::string get_name() const = 0;
	virtual Vector3D get_point(double t) const = 0;
	virtual Vector3D get_first_derivative(double t) const = 0;
};

#endif // CURVE3D_H