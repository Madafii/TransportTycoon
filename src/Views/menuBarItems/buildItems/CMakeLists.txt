add_library(buildItems
    tterailbuildermenu.h tterailbuildermenu.cpp tterailbuildermenu.ui


)

target_include_directories(buildItems PUBLIC ".")
target_link_libraries(buildItems Qt6::Core Qt6::Widgets)

