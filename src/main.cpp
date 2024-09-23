#include "libsystem_configuration/system_configuration.hpp"
#include <iostream>
using namespace std;
using namespace ncc::system_configuration;

int main(){

  SystemConfiguration config;
  config.set_config("config.yaml");
  
  RuamelLoader ruamel_loader;
  
  //load configuration
  config.set_loader(ruamel_loader);
  
  //read configuration
  cout << "token: " << config.getValueByKey("token") << std::endl;
  cout << "service_name: " << config.getValueByKey("service_name") << std::endl;
  cout << "database host: " << config.getValueByKey("database.host") << std::endl;
  cout << "logging file: " << config.getValueByKey("logging.file") << std::endl;
  cout << "service enabled: " << config.getValueByKey("service.enabled") << std::endl;
  YAML::Node servers = config.getValueByKey("servers");
  for(auto server : servers)
  {
    cout << "IP: " << server["ip"] << std::endl;
    cout << "Server name: " << server["name"] << std::endl;
  }

  //put tree childs value
  config.set("station.office.host", config.getValueByKey("database.host"), true);

  //replace value
  config.set("station.office.host", config.getValueByKey("service_name"), true);

  return 1;
}