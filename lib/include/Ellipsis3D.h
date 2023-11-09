#ifndef ELLIPSIS3D_H
#define ELLIPSIS3D_H

#include "Curve3D.h"

class Ellipsis3D : public Curve3D {
private:
	double h_radius_;
	double v_radius_;

public:
	Ellipsis3D(double h_radius, double v_radius);

	std::string get_name() const override;
	Vector3D get_point(double t) const override;
	Vector3D get_first_derivative(double t) const override;
};

#endif // ELLIPSIS3D_H