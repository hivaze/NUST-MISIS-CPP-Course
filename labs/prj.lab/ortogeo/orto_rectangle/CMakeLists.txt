#add_executable(orto_rectangle rectangle.cpp)

add_library(orto_rectangle rectangle.h rectangle.cpp)
set_property(TARGET orto_rectangle PROPERTY CXX_STANDARD 17)