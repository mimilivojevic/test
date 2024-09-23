//Implement
#include "libsystem_configuration/system_configuration.hpp"
#include <regex>
#include <iostream>
using namespace std;

namespace ncc::system_configuration{

    SystemConfiguration::SystemConfiguration(){}

    SystemConfiguration::SystemConfiguration(
        const std::optional<std::string>& config_path_,
        const std::optional<std::string>& env_var,
        BaseLoader& loader
    ){
        std::string env_str = env_var.has_value() ? "" : env_var.value();
        this->config_path = config_path_.has_value() ? (std::getenv(env_str.c_str())) : config_path_.value();
        if (this->config_path.empty()) {
            throw ConfigurationError("Configuration path must be provided either as an argument, or through the '" + env_var.value_or("") + "' environment variable.");
        }

        this->current_loader = &loader;

        try {
            this->config_data = this->current_loader->load(this->config_path);
        } catch (const std::ios_base::failure&) {
            throw FileNotFoundError(this->config_path);
        } catch (const std::exception&) {
            throw InvalidConfigError();
        }
    }

    YAML::Node SystemConfiguration::get(string key){ 
        if(config_data.find(key) == config_data.end()){
        throw MissingKeyError("Missing key error");
        }
        else{
        return config_data[key];
        }
    }
    
    void SystemConfiguration::addOrReplaceKey(YAML::Node& root, const std::vector<std::string>& keys, const YAML::Node& value) {
        YAML::Node* currentNode = &root;

        for (size_t i = 0; i < keys.size(); ++i) {
            const std::string& key = keys[i];
            
            if (i == keys.size() - 1) {
                // If it's the last key, set the value
                (*currentNode)[key] = value;
            } else {
                // Navigate to the next node
                if (!(*currentNode)[key]) {
                    (*currentNode)[key] = YAML::Node(YAML::NodeType::Map);
                }
                *currentNode = (*currentNode)[key];
            }
        }
    }

    void SystemConfiguration::set(string key, YAML::Node value, bool _save){
        if(key.find(".") != std::string::npos || config_data.find(key) != config_data.end()){
            std::vector<std::string> keys = splitString(key, '.');
            string first = keys[0];
            std::reverse(keys.begin(), keys.end());
            YAML::Node yamlNode;
            for (const auto& pair : config_data) {
                yamlNode[pair.first] = pair.second;
            }
            YAML::Node root;
            for (int i =0; i<keys.size()-1;i++) 
            { 
                YAML::Node node;
                if(i==0){
                    root[keys[i]]=value;
                }
                else{
                    node[keys[i]] = root;
                    root = node;
                }
            } 
            yamlNode[first] = root;
            
            config_data = yamlNode.as<std::map<std::string, YAML::Node>>();
        }
        else{
            config_data.insert({key,value});
        }
         
        current_loader->save(config_path, config_data);
    }

    void SystemConfiguration::set_loader(BaseLoader& loader){
        current_loader = &loader;
        config_data = current_loader->load(config_path);
    }
    
    void SystemConfiguration::set_config(string path){
        config_path = path;
    }

    string SystemConfiguration::get_config(){
        return config_path;
    }

    YAML::Node SystemConfiguration::getRecursiveValueByKey(const YAML::Node& node, const std::vector<std::string>& keys, size_t index){
        if (index >= keys.size()) { 
            return node;
        }

        const std::string& key = keys[index];
        if (node[key]) {
            return getRecursiveValueByKey(node[key], keys, index + 1); 
        } else {
            throw std::runtime_error("Key not found: " + key);
        }
       
    }

    YAML::Node SystemConfiguration::getValueByKey(const std::string& keyPath) {

        YAML::Node config = YAML::LoadFile(get_config());
        std::vector<std::string> keys;
        size_t start = 0;
        size_t end = keyPath.find('.');
        while (end != std::string::npos) {
            keys.push_back(keyPath.substr(start, end - start));
            start = end + 1;
            end = keyPath.find('.', start);
        }
        keys.push_back(keyPath.substr(start));

        YAML::Node result = getRecursiveValueByKey(config, keys, 0);
        
        return result;
    }

    std::vector<std::string> SystemConfiguration::splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);

        while (end != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(delimiter, start);
        }

        tokens.push_back(str.substr(start)); // Add the last token
        return tokens;
    }


}