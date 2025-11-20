cmake_minimum_required (VERSION 4.0)
project(Races)

target_sources(Races PRIVATE
src/AirTransport.cpp
src/Boots.cpp
src/Broom.cpp
src/Camel.cpp
src/Carpet.cpp
src/Centaur.cpp
src/Eagle.cpp
src/FastCamel.cpp
src/GroundTransport.cpp
src/main.cpp
src/Race.cpp
src/Transport.cpp
)

target_include_directories(Races PUBLIC
    "include"
)