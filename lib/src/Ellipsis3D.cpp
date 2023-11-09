#include "Ellipsis3D.h"

Ellipsis3D::Ellipsis3D(double h_radius, double v_radius) : 
	h_radius_{ h_radius }, v_radius_{ v_radius } {
	if (h_radius_ < 0 || v_radius_ < 0) {
		throw std::runtime_error("Both radii of ellipsis must be positive!");
	}
}

std::string Ellipsis3D::get_name() const {
	return "ellipsis";
}

Vector3D Ellipsis3D::get_point(double t) const {
	return Vector3D{ h_radius_ * cos(t), v_radius_ * sin(t), 0 };
}

Vector3D Ellipsis3D::get_first_derivative(double t) const {
	return Vector3D{ -h_radius_ * sin(t), v_radius_ * cos(t), 0 };
}