set(CMAKE_AUTOUIC ON)

add_library(ui
)
target_sources(ui PRIVATE



)
target_include_directories(ui PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(ui PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

