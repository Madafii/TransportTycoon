add_library(railNetwork

    tterailloader.h tterailloader.cpp
    tterailtype.h tterailtype.cpp
)

target_include_directories(railNetwork PUBLIC ".")
target_link_libraries(railNetwork inanimate Qt6::Core)
