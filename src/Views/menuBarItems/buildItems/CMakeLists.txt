add_library(buildItems
    tterailbuildermenu.h tterailbuildermenu.cpp
    ttestreetbuildermenu.h ttestreetbuildermenu.cpp
)

target_include_directories(buildItems PUBLIC ".")
target_link_libraries(buildItems viewTemplates railNetwork streets Qt6::Core Qt6::Widgets)

