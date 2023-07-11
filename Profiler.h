#pragma once
#include <string>
#include <chrono>
#include <iostream>

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
	LogDuration UNIQ_ID(__LINE__) (message);

class LogDuration {
public:
	LogDuration(const std::string &message="") : start(std::chrono::steady_clock::now()), message_(message + ": ") {}
	~LogDuration() {
		auto finish = std::chrono::steady_clock::now();
		auto dur = finish - start;
		std::cerr << message_ << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms"<< std::endl;
	}
private:
	std::string message_;
	std::chrono::steady_clock::time_point start;

};