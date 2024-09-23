// Implements
#include <yaml-cpp/yaml.h>
#include "libsystem_configuration/exceptions.hpp"
#include "libsystem_configuration/yaml_loader.hpp"
#include <iostream>
using namespace std;


namespace ncc::system_configuration{

    std::map<std::string, YAML::Node> YAMLLoader::load(const std::string& configPath) {
        try {
            std::ifstream file(configPath);
            if (!file.is_open()) {
                throw std::ios_base::failure("Cannot read file at: " + configPath);
            }
            YAML::Node config = YAML::Load(file);
            return config.as<std::map<std::string, YAML::Node>>();
        } catch (const YAML::Exception& e) {
            throw std::invalid_argument("Invalid YAML configuration file content");
        }
    }

    void YAMLLoader::save(const std::string& configPath, const std::map<std::string, YAML::Node>& data) {
        try {
            std::ofstream file(configPath);
            if (!file.is_open()) {
                throw std::ios_base::failure("Cannot write file at: " + configPath);
            }
            YAML::Node yamlNode = YAML::Node(data);
            file << yamlNode;
        } catch (const std::ios_base::failure& e) {
            throw std::ios_base::failure("Cannot write file at: " + configPath);
        }
    }
}