#pragma once

#include <ftxui/component/component.hpp>

#include "task.hpp"

namespace core {
    struct TaskManager {
	std::vector<Task> tasks, progress, done;
	uint16_t &s1, &s2, &s3;
	TaskManager(uint16_t &, uint16_t &, uint16_t &);
    };
}
