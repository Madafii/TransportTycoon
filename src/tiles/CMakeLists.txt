add_library(tiles
    tilemap.h tilemap.cpp
    tiletype.h tiletype.cpp
    tile.h tile.cpp
    tileloader.h tileloader.cpp
)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(tiles Qt6::Core Qt6::Gui)
