#pragma once

#include <glm/glm.hpp>

class ray {
   public:
    glm::vec3 origin;
	glm::vec3 dir;
	ray(glm::vec3, glm::vec3);
};