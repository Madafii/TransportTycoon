add_subdirectory(rail_network)

add_library(objects
    tteobject.h tteobject.cpp
)

target_include_directories(objects PUBLIC ".")
target_link_libraries(objects Qt6::Core Qt6::Gui)
