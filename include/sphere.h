#pragma once

#include "solid.h"

class sphere : public solid {
   public:
    float radius;
    glm::vec3 origin;
	sphere(glm::vec3, float);
	bool compute_intersection(ray, glm::vec3&);
};