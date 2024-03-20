set(CMAKE_AUTOMOC ON)

add_library(tiles
    tilemap.h tilemap.cpp
    tiletype.h tiletype.cpp
    tileloader.h tileloader.cpp
    maptile.h maptile.cpp
)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(tiles Qt6::Core Qt6::Gui Qt6::Widgets)
