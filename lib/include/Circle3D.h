#ifndef CIRCLE3D_H
#define CIRCLE3D_H

#include "Curve3D.h"

class Circle3D : public Curve3D  {
private:
	double radius_;

public:
	Circle3D(double radius);

	std::string get_name() const override;
	Vector3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
	double get_radius() const;
};

bool operator<(const Circle3D& left, const Circle3D& right);

#endif // CIRCLE3D_H