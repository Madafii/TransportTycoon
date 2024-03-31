add_library(utils
    imagereader.h imagereader.cpp
    typeobject.h typeobject.cpp
)

target_include_directories(utils PUBLIC ".")
target_link_libraries(utils PRIVATE Qt6::Core Qt6::Gui)

