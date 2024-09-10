add_library(streets
    ttestreettype.h ttestreettype.cpp
    ttestreet.h ttestreet.cpp
    ttestreetloader.h ttestreetloader.cpp
)

target_include_directories(streets PUBLIC ".")
target_link_libraries(streets inanimate Qt6::Core)

