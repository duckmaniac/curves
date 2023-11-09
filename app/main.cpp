#include <list>
#include <vector>
#include <algorithm>
#include "Circle3D.h"
#include "Ellipsis3D.h"
#include "Helix3D.h"
#include "RandomGenerator.h"
#include <omp.h>

enum CurveTypes{ Circle, Ellipsis, Helix};

constexpr int NUMBER_OF_CURVES = 1000;
IntegerRandomGenerator random_int(0, 2);
DoubleRandomGenerator random_double(0.0, 100.0);

std::shared_ptr<Curve3D> create_random_curve() {
	switch (random_int.get()) {
	case CurveTypes::Circle:
		return std::make_shared<Circle3D>(random_double.get());
	case CurveTypes::Ellipsis:
		return std::make_shared<Ellipsis3D>(random_double.get(), random_double.get());
	case CurveTypes::Helix:
		return std::make_shared<Helix3D>(random_double.get(), random_double.get());
	}
}

int main() {
	try {
		// Creating and filliing list of curves.
		std::vector<std::shared_ptr<Curve3D>> curves;
		std::generate_n(std::back_inserter(curves), NUMBER_OF_CURVES, create_random_curve);
		
		std::vector<std::shared_ptr<Circle3D>> circles;
		double t = PI / 4;
		for (std::shared_ptr<Curve3D> curve : curves) {
			// Print coordinates of points and derivatives.
			std::cout << curve->get_point(t) << ", " << curve->get_first_derivative(t) << 
				" - " << curve->get_name() << '\n';

			// Populate a second container with circles.
			auto circle = std::dynamic_pointer_cast<Circle3D>(curve);
			if (circle) {
				circles.push_back(circle);
			}
		}

		// Sort and calculate sum of circle's radiuses.
		std::sort(circles.begin(), circles.end(),
			[](std::shared_ptr<Circle3D> left, std::shared_ptr<Circle3D> right) {
				return (*left) < (*right);
			});
		double sum = 0.0;

		#pragma omp parallel for reduction(+:sum) 
		for (int i = 0; i < circles.size(); i++) {
			//std::cout << omp_get_thread_num() << " ";
			sum += circles[i]->get_radius();
		}
		std::cout << "Sum: " << sum << '\n';
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}