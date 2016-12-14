set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_library(dog Dog.cpp)
add_executable(main main.cpp)
target_link_libraries(main dog)
