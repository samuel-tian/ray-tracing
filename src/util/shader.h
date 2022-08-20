#pragma once

#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class shader {
   public:
	unsigned int ID;
	shader(std::string, std::string);
	void use();
	void terminate();
};
