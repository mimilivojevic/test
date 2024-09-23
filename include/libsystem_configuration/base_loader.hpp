#ifndef __BASELOADER_H_
#define __BASELOADER_H_

// Abstract base class for configuration loaders.

#include <string>
#include <map>
#include <stdexcept>
#include <yaml-cpp/yaml.h>

namespace ncc::system_configuration{
    class BaseLoader {  // pragma: no cover
    public:
        // Abstract method to load configuration data from the given path.
        virtual std::map<std::string, YAML::Node> load(const std::string& configPath) = 0;

        // Abstract method to save configuration data to the given path.
        virtual void save(const std::string& configPath, const std::map<std::string, YAML::Node>& data) = 0;

        virtual ~BaseLoader() = default; // Virtual destructor for proper cleanup
    };
}
#endif