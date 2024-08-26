add_library(sample
    sample.h sample.cpp   	
)

target_include_directories(sample PUBLIC ".")
target_link_libraries(sample Qt6::Core)

