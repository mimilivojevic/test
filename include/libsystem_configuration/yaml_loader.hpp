#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "base_loader.hpp"
#include <yaml-cpp/yaml.h>


namespace ncc::system_configuration{

    class YAMLLoader : public BaseLoader {
    public:
        // YAML loader for configuration files using the YAML library.

        // Load configuration data from the given path using YAML.
        // Args:
        //     configPath: The path to the configuration file.
        // Returns:
        //     std::map<std::string, YAML::Node>: The loaded configuration data.
        // Throws:
        //     std::ios_base::failure: If the file cannot be read.
        //     std::invalid_argument: If the file content is invalid YAML.
        std::map<std::string, YAML::Node> load(const std::string& configPath);

        // Save configuration data to the given path using YAML.
        // Args:
        //     configPath: The path to the configuration file.
        //     data: The configuration data to save.
        // Throws:
        //     std::ios_base::failure: If the file cannot be written.
        void save(const std::string& configPath, const std::map<std::string, YAML::Node>& data);
    };
}