#pragma once

#include <glm/glm.hpp>

class light {
	// todo: add color, intensity
   public:
	glm::vec3 origin;
	light();
	light(glm::vec3);
};