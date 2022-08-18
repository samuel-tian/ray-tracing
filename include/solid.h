#pragma once

#include <glm/glm.hpp>
#include "ray.h"

class solid {
   public:
	bool compute_intersection(ray, glm::vec3);
};