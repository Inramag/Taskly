 cmake_minimum_required(VERSION 3.14)
 project(Taskly LANGUAGES CXX)

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/ftxui)

add_executable(taskly
	main.cpp
)

target_include_directories(taskly PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(taskly
	PRIVATE
		ftxui::screen
		ftxui::dom
		ftxui::component
)
