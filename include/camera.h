#pragma once

#include <glm/glm.hpp>

class camera {
   public:
    glm::vec3 origin;
    glm::vec3 dir;
	float fov;

	camera();
    camera(glm::vec3, glm::vec3, float);
};