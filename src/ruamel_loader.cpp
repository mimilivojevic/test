// Implements
#include "libsystem_configuration/ruamel_loader.hpp"
#include <iostream>
using namespace std;

namespace ncc::system_configuration{
    std::map<std::string, YAML::Node> RuamelLoader::load(const std::string& configPath) {
        try {
            YAML::Node yamlNode = YAML::LoadFile(configPath);
            return yamlNode.as<std::map<std::string, YAML::Node>>();
        } catch (const std::ifstream::failure& e) {
            throw std::ios_base::failure("Cannot read file at: " + configPath);
        } catch (const std::exception& e) {
            throw FileNotFoundError("Invalid configuration file content: " + std::string(e.what()));
            //throw std::invalid_argument("Invalid configuration file content: " + std::string(e.what()));
        }
    }

    // Save configuration data to the given path using YAML-CPP.
    void RuamelLoader::save(const std::string& configPath, const std::map<std::string, YAML::Node>& data) {
        try {
            YAML::Node yamlNode = YAML::Node(data);
            std::ofstream file(configPath);
            file << yamlNode;
        } catch (const std::ofstream::failure& e) {
            throw std::ios_base::failure("Cannot write file at: " + configPath);
        }
    }
}