add_library(tiles
    tilemap.h tilemap.cpp
    tiletype.h tiletype.cpp
    tileloader.h tileloader.cpp
    tile.h tile.cpp
)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(tiles utils Qt6::Core Qt6::Gui Qt6::Widgets)
