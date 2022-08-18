#include "ray.h"

ray::ray(glm::vec3 origin, glm::vec3 dir) {
    this->origin = origin;
    this->dir = glm::normalize(dir);
}