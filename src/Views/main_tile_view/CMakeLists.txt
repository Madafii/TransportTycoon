add_library(MainViewMap
    ttemainviewmap.h ttemainviewmap.cpp
)

target_include_directories(MainViewMap PUBLIC ".")
target_link_libraries(MainViewMap tiles railNetwork streets Qt6::Core Qt6::Gui Qt6::Widgets)

