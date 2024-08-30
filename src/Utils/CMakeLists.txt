add_library(Utils
    imagereader.cpp imagereader.h
)

target_include_directories(Utils PUBLIC ".")
target_link_libraries(Utils PRIVATE Qt6::Core Qt6::Gui)

