add_subdirectory(rail_network)
add_subdirectory(tiles)
add_subdirectory(streets)

add_library(inanimate
    tteinanimateobject.h tteinanimateobject.cpp
    tteinanimatetype.h tteinanimatetype.cpp
    tteimagesetloader.h tteimagesetloader.cpp
    ttebuildhelper.h ttebuildhelper.cpp
)

target_include_directories(inanimate PUBLIC ".")
target_link_libraries(inanimate Utils railNetwork tiles streets Qt6::Core Qt6::Gui Qt6::Widgets)
