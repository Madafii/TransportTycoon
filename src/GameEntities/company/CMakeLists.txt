add_library(ttecompany
    ttecompany.h ttecompany.cpp
)

target_include_directories(ttecompany PUBLIC ".")
target_link_libraries(ttecompany Qt6::Core Qt6::Gui Qt6::Widgets)
