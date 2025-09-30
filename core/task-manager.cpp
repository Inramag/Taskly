#include <fstream>
#include <iostream>
#include <filesystem>

#include "task-manager.hpp"

namespace core {
    TaskManager::TaskManager(uint16_t &s1, uint16_t &s2, uint16_t &s3) : s1(s1), s2(s2), s3(s3) {
	tasks = {};
	progress = {};
	done = {};
	for (auto &file : std::filesystem::directory_iterator("./tasks")) {
	    if (!file.is_regular_file()) continue;
	    if (file.path().extension() != ".tsk") continue;
	    
	    auto task = Task::Parse(file);
	    switch (task.status) {
	    case TaskStatus::New: tasks.push_back(task); break;
	    case TaskStatus::IsProgress: progress.push_back(task); break;
	    case TaskStatus::Done: done.push_back(task); break;
	    }
	}
    }
}
