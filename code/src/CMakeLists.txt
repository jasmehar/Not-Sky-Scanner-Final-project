# Creating a source library
file(GLOB_RECURSE src_sources CONFIGURE_DEPENDS ./*.cpp) # Collects all files in src folder
add_library(src ${src_sources}) # Makes it into a library
target_include_directories(src PUBLIC ${src_dir}) # Lets everyone view the library