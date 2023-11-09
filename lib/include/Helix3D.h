#ifndef HELIX3D_H
#define HELIX3D_H

#include "Curve3D.h"

class Helix3D : public Curve3D {
private:
	double radius_;
	double step_;

public:
	Helix3D(double radius, double step);

	std::string get_name() const override;
	Vector3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
};

#endif // HELIX3D_H