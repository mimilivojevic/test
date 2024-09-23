#include "gtest/gtest.h"
#include "libsystem_configuration/exceptions.hpp"
#include "libsystem_configuration/ruamel_loader.hpp"
#include "libsystem_configuration/system_configuration.hpp"
#include<iostream>
using namespace std;
using namespace ncc::system_configuration;


TEST(TestSystemConfiguration, TestGet) {
    RuamelLoader loader;
    SystemConfiguration config;
    config.set_config("config.yaml");
    config.set_loader(loader);
    EXPECT_EQ(config.get("service_name").as<std::string>(), "netico_bms");
    EXPECT_EQ(config.get("token").as<std::string>(), "adsad1131311312112ddsadad");
}

TEST(TestSystemConfiguration, TestSetGet) {
    RuamelLoader loader;
    SystemConfiguration config;
    config.set_config("config.yaml");
    config.set_loader(loader);
    config.set("station.office.host", config.getValueByKey("service_name"), true);
    EXPECT_EQ(config.get("service_name").as<std::string>(), "netico_bms");
    EXPECT_EQ(config.get("token").as<std::string>(), "adsad1131311312112ddsadad");
    EXPECT_EQ(config.getValueByKey("station.office.host").as<std::string>(), "netico_bms");
}

TEST(TestSystemConfiguration, TestSetReplaceGet) {
    RuamelLoader loader;
    SystemConfiguration config;
    config.set_config("config.yaml");
    config.set_loader(loader);
    config.set("station.office.host", config.getValueByKey("service_name"), true);
    EXPECT_EQ(config.get("service_name").as<std::string>(), "netico_bms");
    EXPECT_EQ(config.get("token").as<std::string>(), "adsad1131311312112ddsadad");
    EXPECT_EQ(config.getValueByKey("station.office.host").as<std::string>(), "netico_bms");
    config.set("station.office.host", config.getValueByKey("database.host"), true);
    EXPECT_EQ(config.getValueByKey("station.office.host").as<std::string>(), "localhost");
}

TEST(TestSystemConfiguration, TestGetMissedKey) {
    RuamelLoader loader;
    SystemConfiguration config;
    config.set_config("config.yaml");
    config.set_loader(loader);
    EXPECT_THROW(config.get("number1234").as<std::string>(), MissingKeyError);
}

TEST(TestSystemConfiguration, TestInvalidConfigPathname) {
    RuamelLoader loader;
    SystemConfiguration config;
    config.set_config("config123.yaml");
    EXPECT_THROW(config.set_loader(loader), FileNotFoundError);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
