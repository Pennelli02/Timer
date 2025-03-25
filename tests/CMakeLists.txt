# tests/CMakeLists.txt
set(TEST_NAME ${PROJECT_NAME}_test)

# Create test executable
add_executable(${TEST_NAME}
        clockwindow_test.cpp
        clockwindow_test.h)

# Link necessary Qt6 libraries
target_link_libraries(${TEST_NAME} PRIVATE
        Qt6::Core
        Qt6::Test
        Qt6::Widgets  # Required for QWidget
        Qt6::Gui
        Qt6::Multimedia
        )

# Register the test
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})