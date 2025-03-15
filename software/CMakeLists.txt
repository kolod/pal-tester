cmake_minimum_required(VERSION 3.22)

project(pal-tester-gui VERSION 0.1 LANGUAGES CXX)

set(PROJECT_NAME "PAL-Tester-GUI")
set(PROJECT_DESCRIPTION "The GUI for the PAL tester on pico.")
set(PROJECT_AUTHOR "Oleksandr Kolodkin")
set(PROJECT_URL "https://github.com/kolod/pal-tester")

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts SerialBus SerialPort LinguistTools)
qt_standard_project_setup()

set(TS_FILES
    translations/pal-tester-gui_uk.ts
)

set(SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
)

if(WIN32)
    list(APPEND SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resources.rc")
endif()

qt6_add_resources(SOURCES resources.qrc)
qt6_add_executable(pal-tester-gui MANUAL_FINALIZATION ${SOURCES})
qt6_add_lupdate(pal-tester-gui TS_FILES ${TS_FILES} OPTIONS -locations relative -no-obsolete)
qt6_add_lrelease(pal-tester-gui TS_FILES ${TS_FILES} QM_FILES_OUTPUT_VARIABLE QM_FILES OPTIONS -compress -removeidentical)

target_link_libraries(pal-tester-gui PRIVATE
    Qt6::Widgets
    Qt6::Charts
    Qt6::SerialBus
    Qt6::SerialPort
)

set_target_properties(pal-tester-gui PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER oleksandr.kolodkin.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS pal-tester-gui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(pal-tester-gui)
