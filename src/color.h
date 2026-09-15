#include <iostream>

typedef vec3 color;

void write_color(std::ostream& out, const color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Translate to [0, 255]
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	// write out R G B
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
