project(synonymizer_lib LANGUAGES CXX)

find_package(Qt5 REQUIRED Core Network)

set(SOURCES
        DatamuseAPI.h
        DatamuseAPI.cpp
        WordRepresenter.hpp
        SettingsWrapper.hpp
        )

add_library(synonymizer_lib ${SOURCES})

set_property(TARGET synonymizer_lib PROPERTY CXX_STANDARD 17)

target_link_libraries(synonymizer_lib PRIVATE Qt5::Core Qt5::Network)