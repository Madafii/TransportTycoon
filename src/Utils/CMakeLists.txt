add_library(Utils
    imagereader.h imagereader.cpp
)

target_include_directories(Utils PUBLIC ".")
target_link_libraries(Utils PRIVATE Qt6::Core Qt6::Gui)

