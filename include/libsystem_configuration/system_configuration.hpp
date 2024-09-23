#ifndef __CONFIG_H_
#define __CONFIG_H_
#include "ruamel_loader.hpp"
#include<iostream>
#include <optional>
#include <string>
#include <regex>
#include <cstdlib>
#include <memory>

#include <iostream>
using namespace std;


namespace ncc::system_configuration{

    class SystemConfiguration{
      public:
        SystemConfiguration();

        SystemConfiguration(
          const std::optional<std::string>& config_path_,
          const std::optional<std::string>& env_var,
          BaseLoader& loader
        );

        YAML::Node get(string key);

        void set(string key, YAML::Node value, bool _save);

        void set_loader(BaseLoader& loader);
        
        void set_config(string path);

        string get_config();

        YAML::Node getRecursiveValueByKey(const YAML::Node& node, const std::vector<std::string>& keys, size_t index);
        YAML::Node getValueByKey(const std::string& keyPath);
        std::vector<std::string> splitString(const std::string& str, char delimiter);
        void addOrReplaceKey(YAML::Node& root, const std::vector<std::string>& keys, const YAML::Node& value);

      private:
          std::string config_path;
          BaseLoader* current_loader;
          std::map<string, YAML::Node> config_data;
      };
}

#endif  
