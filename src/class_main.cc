#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include "triangle.h"

int main(){
	int image_height = 1024;
	int image_width = 1024;

	triangle t {point3{100, 100, 0}, point3{750, 100, 0}, point3{100, 750, 0}};

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	
	for (int j = 0; j < image_height; j++){
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++) {
			ray r {point3{j + 0.5, i + 0.5, -1}, vec3{0, 0, 1}};
			auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
			write_color(std::cout, pixel_color);
		}

	}

	std::clog << "\rDone.                 \n";
}
