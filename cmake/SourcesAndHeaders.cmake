set(sources
    src/main.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/libsystem_configuaration/system_configuaration.hpp
    _deps/yaml-cpp-src/include/yaml-cpp/yaml.h
)

set(test_sources
  src/config_test.cpp
)
