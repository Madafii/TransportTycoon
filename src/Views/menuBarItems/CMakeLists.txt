add_library(menuBarItems
    tterailbuildermenu.h tterailbuildermenu.cpp tterailbuildermenu.ui
)

target_include_directories(menuBarItems PUBLIC ".")
target_link_libraries(menuBarItems  Qt6::Core Qt6::Widgets)

