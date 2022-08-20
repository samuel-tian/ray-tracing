#version 410 core

in vec3 pixel_pos;

out vec3 color;

/* Ray Class */
struct ray {
	vec3 origin;
	vec3 direction;
};

ray create_ray(vec3 origin, vec3 direction) {
	ray r;
	r.origin = origin;
	r.direction = normalize(direction);
	return r;
}

vec3 compute_ray_position(ray r, float t) {
	return r.origin + r.direction * t;
}

/* Solid Class */
struct solid {
	uint type;
	vec3 center;
	float scale;
};
const uint SPHERE = 1;

solid create_sphere(vec3 center, float scale) {
	solid s;
	s.type = SPHERE;
	s.center = center;
	s.scale = scale;
	return s;
}

solid solids[1];
int num_solids;

/* Computations for spheres */
bool compute_sphere_intersection(solid s, ray r, out float intersection_distance) {
	vec3 hyp = s.center - r.origin;
	float t = dot(hyp, r.direction);
	vec3 normal_intersection = compute_ray_position(r, t);

	float normal_radius = length(s.center - normal_intersection);
	if (normal_radius > s.scale) {
		return false;
	}
	else {
		float t_offset = sqrt(s.scale * s.scale - normal_radius * normal_radius);
		float t_intersect = t - t_offset;
		if (t_intersect < 0) {
			return false;
		}
		else {
			intersection_distance = t_intersect;
			return true;
		}
	}
}

vec3 compute_sphere_normal(solid s, vec3 location) {
	vec3 normal = s.center - location;

	return normalize(normal);
}

void load_objects() {
	solid sphere = create_sphere(vec3(0.0, 0.0, 0.0), 0.2);

	solids[num_solids] = sphere;
	num_solids++;
}

void main() {

	num_solids = 0;

	vec3 camera_pos = vec3(0.0f, 0.0f, -1.0f);
	vec3 camera_direction = pixel_pos - camera_pos;
	vec3 light_pos = vec3(0.0f, 1.0f, -1.0f);

	ray camera_ray = create_ray(camera_pos, camera_direction);

	load_objects();

	bool good = false;
	solid s = solids[0];
	float dist;
	good = good || (compute_sphere_intersection(s, camera_ray, dist));

	if (good) {
		color = vec3(1.0f, 1.0f, 1.0f);
		vec3 intersection_position = compute_ray_position(camera_ray, dist);
		vec3 vec_to_light = intersection_position - light_pos;
		vec3 normal = compute_sphere_normal(s, intersection_position);
		color = color * dot(normal, vec_to_light);
	}
	else {
		color = vec3(0.0f, 0.0f, 0.0f);
	}

}