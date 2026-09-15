class triangle {
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

	private:
		point3 ta;
		point3 tb;
		point3 tc;
		vec3 normal;
};
