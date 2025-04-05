# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Timer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Timer_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\Timer_lib_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Timer_lib_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\Timer_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Timer_test_autogen.dir\\ParseCache.txt"
  "Timer_autogen"
  "Timer_lib_autogen"
  "Timer_test_autogen"
  )
endif()
