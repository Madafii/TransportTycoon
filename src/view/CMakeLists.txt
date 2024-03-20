add_library(view
    mapview.h mapview.cpp
)

target_include_directories(view PUBLIC ".")
target_link_libraries(view Qt6::Core Qt6::Gui Qt6::Widgets)
