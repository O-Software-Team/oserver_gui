file(GLOB_RECURSE SOURCES src/*.c)
add_library(oserver_gui STATIC ${SOURCES})
