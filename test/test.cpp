#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    std::string file_path = "../src/shaders/rayshader.fs";
    std::ifstream stream;
    stream.open(file_path);
    std::stringstream sstream;
    sstream << stream.rdbuf();
    stream.close();

    std::cout << sstream.str() << std::endl;

    return 0;
}