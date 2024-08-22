add_library(tiles
    tiletype.h tiletype.cpp
    tilemap.h tilemap.cpp
    tileloader.h tileloader.cpp
    tile.h tile.cpp
)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(tiles utils objects inanimate Qt6::Core Qt6::Gui Qt6::Widgets)
