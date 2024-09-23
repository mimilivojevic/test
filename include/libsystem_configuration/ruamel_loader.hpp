#ifndef __RUAMELLOADER_H_
#define __RUAMELLOADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "base_loader.hpp"
#include "exceptions.hpp"


namespace ncc::system_configuration{

    class RuamelLoader : public BaseLoader {
    public:
        // Custom loader for configuration files using YAML-CPP.

        // Load configuration data from the given path using YAML-CPP.
        std::map<std::string, YAML::Node> load(const std::string& configPath);

        // Save configuration data to the given path using YAML-CPP.
        void save(const std::string& configPath, const std::map<std::string, YAML::Node>& data);
    };

}
#endif