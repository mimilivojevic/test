#ifndef __EXCEPTIONS_H_
#define __EXCEPTIONS_H_

#include <exception>
#include <string>

namespace ncc::system_configuration{
    class ConfigError : public std::exception {
    public:
        // Base class for all configuration-related exceptions.
        virtual const char* what() const noexcept override {
            return "Base configuration error";
        }
    };

    class ConfigurationError : public ConfigError {
    public:
        // Raised when the configuration file contains invalid data or is empty.
        ConfigurationError(const std::string& message = "Configuration error") {
            errorMessage = message;
        }

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

    private:
        std::string errorMessage;
    };

    class FileNotFoundError : public ConfigError {
    public:
        // Raised when the configuration file is not found.
        FileNotFoundError(const std::string& configPath) {
            errorMessage = "Configuration file not found: " + configPath;
        }

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

    private:
        std::string errorMessage;
    };

    class InvalidConfigError : public ConfigError {
    public:
        // Raised when the configuration file contains invalid data or is empty.
        InvalidConfigError(const std::string& message = "Invalid configuration data") {
            errorMessage = message;
        }

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

    private:
        std::string errorMessage;
    };

    class MissingKeyError : public ConfigError {
    public:
        // Raised when a requested key is not found in the configuration.
        MissingKeyError(const std::string& key) {
            errorMessage = "Configuration key not found: " + key;
        }

        const char* what() const noexcept override {
            return errorMessage.c_str();
        }

    private:
        std::string errorMessage;
    };
}
#endif