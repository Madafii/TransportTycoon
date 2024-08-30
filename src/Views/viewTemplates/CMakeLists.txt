add_library(viewTemplates
    ttebuildermenubase.cpp ttebuildermenubase.h
)

target_include_directories(viewTemplates PUBLIC ".")
target_link_libraries(viewTemplates Qt6::Core Qt6::Gui Qt6::Widgets)
