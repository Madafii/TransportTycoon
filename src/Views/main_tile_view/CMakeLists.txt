add_library(mainTileView
    ttetilemap.h ttetilemap.cpp
)

target_include_directories(mainTileView PUBLIC ".")
target_link_libraries(mainTileView tiles Qt6::Core Qt6::Gui Qt6::Widgets)

