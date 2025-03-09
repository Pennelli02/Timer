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
        REQUIRED)


add_executable(Timer main.cpp clockwindow.cpp clockwindow.h clockwindow.ui ui_ClockWIndow.h)

target_link_libraries(Timer
        Qt::Core
        Qt::Widgets
        Qt::Gui)

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
