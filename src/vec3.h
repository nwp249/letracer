#include <cmath>
#include <iostream>

typedef double val; //test float vs double

class vec3{
	public:
		// i, j, k values (or x, y, z, or r, g, b... etc.)
		val e[3];
		
		// constructors
		vec3() : e{0,0,0} {}
		vec3(val e0, val e1, val e2) : e{e0, e1, e2} {}
	
		// getters
		val x() const { return e[0]; }
		val y() const { return e[1]; }
		val z() const { return e[2]; }
		
		// overload negation and accesses
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		val operator[](int i) const { return e[i]; }
		val& operator[](int i) { return e[i]; }
		
		//overload common 3d operations
		
		// v += u
		vec3& operator+=(const vec3& v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		
		// v *= t
		vec3& operator*=(val t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}
		
		// v /= t
		vec3& operator/=(val t){
			return *this *= 1/t;
		}
		
		// helpers
		val length() const {
			return std::sqrt(length_squared());
		}

		val length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
};

typedef vec3 point3; // use to describe points

// other functions and overloads

// standard out
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// u + v
inline vec3 operator+(const vec3& u, const vec3& v){
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// u - v
inline vec3 operator-(const vec3& u, const vec3& v){
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// u * v (not dot product)
inline vec3 operator*(const vec3& u, const vec3& v){
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// t * v
inline vec3 operator*(val t, const vec3& v){
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// v * t
inline vec3 operator*(const vec3& v, val t){
	return t * v;
}

// u / v
inline vec3 operator/(const vec3& v, val t){
	return (1/t) * v;
}

inline val dot(const vec3& u, const vec3& v){
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], 
			u.e[2] * v.e[0] - u.e[0] * v.e[2],
			u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v){
	return v / v.length();
}
