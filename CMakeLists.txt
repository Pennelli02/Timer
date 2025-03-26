cmake_minimum_required(VERSION 3.21)
project(Timer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)  # Abilita AUTOMOC
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS REQUIRED
        Core
        Widgets
        Gui
        Multimedia
        Test
        REQUIRED)


add_executable(Timer main.cpp clockwindow.cpp clockwindow.h clockwindow.ui ui_ClockWIndow.h timerwindow.cpp timerwindow.h timerwindow.ui ui_TimerWindow.h timeritem.cpp timeritem.h timeritem.ui titledialog.cpp titledialog.h titledialog.ui ui_TitleDIalog.h)

target_link_libraries(Timer
        Qt::Core
        Qt::Widgets
        Qt::Gui
        Qt6::Multimedia)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET Timer POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:Timer>/plugins/platforms/")
        add_custom_command(TARGET Timer POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:Timer>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets Test)
        add_custom_command(TARGET Timer POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:Timer>")
    endforeach ()
endif ()

# Definisci il percorso della cartella sounds
set(SOUNDS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sounds)

# Copia i file audio nella directory di build
add_custom_command(TARGET Timer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SOUNDS_DIR} $<TARGET_FILE_DIR:Timer>/sounds
        )
# ... [previous content remains the same until the testing section] ...

# Testing
enable_testing()

# Create a library with the code you want to test
add_library(Timer_lib
        clockwindow.cpp clockwindow.h
        timerwindow.cpp timerwindow.h
        timeritem.cpp timeritem.h
        titledialog.cpp titledialog.h)

target_link_libraries(Timer_lib
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia)

# Link the main executable to the library
target_link_libraries(Timer Timer_lib)

# Test executable
add_executable(Timer_test
        tests/clockwindow_test.cpp
        tests/clockwindow_test.h)

set_target_properties(Timer_test PROPERTIES AUTOMOC ON)

target_link_libraries(Timer_test
        Timer_lib  # Link to the library instead of the executable
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Multimedia
        Qt6::Test)

target_include_directories(Timer_test PRIVATE
        "${CMAKE_BINARY_DIR}"
        "${CMAKE_SOURCE_DIR}")

add_test(NAME Timer_test COMMAND Timer_test)
