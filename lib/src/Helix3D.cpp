#include "Helix3D.h"

Helix3D::Helix3D(double radius, double step) : 
	radius_{ radius }, step_{ step } {}

std::string Helix3D::get_name() const {
	return "helix";
}

Vector3D Helix3D::get_point(double t) const {
	return Vector3D{ radius_ * cos(t), radius_ * sin(t), step_ * t / (2 * PI) };
}

Vector3D Helix3D::get_first_derivative(double t) const {
	return Vector3D{ -radius_ * sin(t), radius_ * cos(t), step_ / (2 * PI) };
}