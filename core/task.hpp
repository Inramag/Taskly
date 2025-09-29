#pragma once

#include <string>
#include <vector>
#include <filesystem>

namespace core {
    enum struct TaskStatus : uint8_t {
	New, IsProgress, Done
    };
    
    struct Task {
	std::string name, info;
	std::vector<Task> subtasks;
	TaskStatus status;
	static Task Parse(const std::filesystem::directory_entry &);
    };
}
