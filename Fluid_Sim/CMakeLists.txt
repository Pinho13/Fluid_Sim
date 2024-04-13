# CMakeList.txt : CMake project for Fluid_Sim, include source and define
# project specific logic here.
#

find_package(SDL2 REQUIRED)

# Add source to this project's executable.
add_executable (Fluid_Sim "Fluid_Sim.cpp" "Fluid_Sim.h")

target_link_libraries(Fluid_Sim SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Fluid_Sim PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
