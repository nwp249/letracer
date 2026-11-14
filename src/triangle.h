class triangle : public hittable{
	public:
		triangle(const point3& a, const point3& b, const point3& c) : ta(a), tb(b), tc(c) 
			{ normal = compute_normal(*this); }

		const point3& a() const { return ta; }
		const point3& b() const { return tb; }
		const point3& c() const { return tc; }

		vec3 compute_normal(triangle t) const {
			vec3 ab = t.b() - t.a();
			vec3 ac = t.c() - t.a();
			return unit_vector(cross(ab, ac));
		}
		
		// Barycentric coordinate hit checking
		bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
			//todo
			return true;
		}

	// yeah you probably dont need to change any of this after creating the triangle
	private:
		point3 ta;
		point3 tb;
		point3 tc;
		vec3 normal;
};
