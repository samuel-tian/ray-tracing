#include "sphere.h"

sphere::sphere(glm::vec3 origin, float radius) {
    this->radius = radius;
    this->origin = origin;
}
bool sphere::compute_intersection(ray r, glm::vec3& intersection) {
    glm::vec3 hyp = this->origin - r.origin;
    float t = glm::dot(hyp, r.dir);
    glm::vec3 normal_intersection = r.origin + t * r.dir;

    float normal_radius = glm::length(this->origin - normal_intersection);
    if (normal_radius > this->radius) {
        return false;
    } else {
        float t_offset = sqrt(this->radius * this->radius - normal_radius * normal_radius);
        float t_intersect = t - t_offset;
        if (t_intersect < 0) {
            return false;
        } else {
            intersection = r.origin + t_intersect * r.dir;
            return true;
        }
    }
}