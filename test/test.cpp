#include <iostream>

#include "glm/gtx/string_cast.hpp"
#include "ray.h"
#include "sphere.h"

int main() {
    ray r(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    sphere s(glm::vec3(2.0f, 0.0f, 0.0f), 1.0f);
    glm::vec3 res;
    bool intersect = s.compute_intersection(r, res);
    std::cout << intersect << " " << glm::to_string(res) << '\n';

    return 0;
}