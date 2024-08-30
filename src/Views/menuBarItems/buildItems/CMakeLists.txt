add_library(buildItems
    tterailbuildermenu.h tterailbuildermenu.cpp
)

target_include_directories(buildItems PUBLIC ".")
target_link_libraries(buildItems viewTemplates Qt6::Core Qt6::Widgets)

