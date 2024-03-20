set(CMAKE_AUTOUIC ON)

add_library(ui

)

target_include_directories(tiles PUBLIC ".")
target_link_libraries(ui PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

