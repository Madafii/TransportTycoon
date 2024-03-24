add_library(railNetwork
    rail.h rail.cpp
)

target_include_directories(railNetwork PUBLIC ".")
target_link_libraries(railNetwork Qt6::Core Qt6::Gui Qt6::Widgets)
