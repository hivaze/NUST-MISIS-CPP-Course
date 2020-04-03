project(synonymizer_gui LANGUAGES CXX)

find_package(Qt5 REQUIRED Widgets Gui Network)

qt5_add_resources(RCC_SOURCES resources/resources.qrc)

set(SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        )

add_executable(synonymizer_gui ${RCC_SOURCES} ${SOURCES})

set_property(TARGET synonymizer_gui PROPERTY CXX_STANDARD 17)

target_link_libraries(synonymizer_gui synonymizer_lib Qt5::Widgets Qt5::Gui Qt5::Network)

install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Network> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:synonymizer_lib> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)