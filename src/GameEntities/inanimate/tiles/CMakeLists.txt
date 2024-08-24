add_library(tiles
    ttetiletype.h ttetiletype.cpp
    ttetileloader.h ttetileloader.cpp
    ttetile.h ttetile.cpp
)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(tiles inanimate Qt6::Core Qt6::Gui Qt6::Widgets)
