add_subdirectory(rail_network)
add_subdirectory(tiles)

add_library(inanimate
    tteinanimateobject.h tteinanimateobject.cpp
    tteinanimatetype.h tteinanimatetype.cpp
    tteimagesetloader.h tteimagesetloader.cpp


)

target_include_directories(inanimate PUBLIC ".")
target_link_libraries(inanimate Utils Qt6::Core Qt6::Gui)
