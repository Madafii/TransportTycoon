add_library(railNetwork
    rail.h rail.cpp
    railsetreader.h railsetreader.cpp
    railtype.h railtype.cpp
)

target_include_directories(railNetwork PUBLIC ".")
target_link_libraries(railNetwork objects utils Qt6::Core)
