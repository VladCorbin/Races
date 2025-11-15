cmake_minimum_required (VERSION 4.0)
project(Races)
add_executable(Races)

target_sources(Races PRIVATE
    "src/AirTransport.cpp"
    "src/LandTransport.cpp"
    "src/main.cpp"
    "src/Race.cpp"
    "src/RaceManager.cpp"
    "src/Transport.cpp"
)

target_include_directories(Races PUBLIC
    "include"
)