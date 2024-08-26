add_subdirectory(buildItems)

add_library(menuBarItems

)

target_include_directories(menuBarItems PUBLIC ".")
target_link_libraries(menuBarItems Qt6::Core Qt6::Widgets)

