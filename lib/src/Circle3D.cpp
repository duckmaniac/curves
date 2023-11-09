#include "Circle3D.h"

Circle3D::Circle3D(double radius) : radius_{radius} {
	if (radius_ < 0) {
		throw std::runtime_error("Radius of circle must be positive!");
	}
}

std::string Circle3D::get_name() const {
	return "circle";
}

Vector3D Circle3D::get_point(double t) const {
	return Vector3D{ radius_ * cos(t), radius_ * sin(t), 0 };
}

Vector3D Circle3D::get_first_derivative(double t) const {
	return Vector3D{ -radius_ * sin(t), radius_ * cos(t), 0 };
}

double Circle3D::get_radius() const {
	return radius_;
}

bool operator<(const Circle3D& left, const Circle3D& right) {
	return left.get_radius() < right.get_radius();
}