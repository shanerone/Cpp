cmake_minimum_required(VERSION 3.16)

project(ParkingSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#необходимые модули Qt
find_package(Qt6 REQUIRED COMPONENTS Core Quick)

set(SOURCES
    main.cpp
    parkingspot.cpp
    owner.cpp
    vehicle.cpp
    parkingsession.cpp
    parkingmanager.cpp
)

set(HEADERS
    parkingspot.h
    owner.h
    vehicle.h
    parkingsession.h
    parkingmanager.h
)

#создать исполняемый файл
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    resources.qrc
)

#подключаем библиотеки Qt
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Quick
)

#директории для поиска заголовочных файлов
target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "Parking System"
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE_COPYRIGHT "Copyright © 2025 Parking System"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.parkingsystem.app"
    )
endif()
