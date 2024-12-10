#include "log.h"
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot::nfsmg {

void print_line(const char *cstr) {
	UtilityFunctions::print(cstr);
}

void print_warning(const char *warning, const char *func, const char *file, int line) {
	_err_print_error(func, file, line, warning, true, true);
}

void print_error(const char *error, const char *func, const char *file, int line) {
	_err_print_error(func, file, line, error);
}

void print_error(const char *error, const char *msg, const char *func, const char *file, int line) {
	_err_print_error(func, file, line, error, msg);
}

void flush_stdout() {
	_err_flush_stdout();
}

} // namespace godot::nfsmg
