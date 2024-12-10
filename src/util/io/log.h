#ifndef NEURON_FSM_GODOT_LOG_H
#define NEURON_FSM_GODOT_LOG_H

#define NFSMG_PRINT_ERROR(msg) print_error(msg, __FUNCTION__, __FILE__, __LINE__);

namespace godot::nfsmg {

void print_line(const char *cstr);

void print_warning(const char *warning, const char *func, const char *file, int line);

void print_error(const char *error, const char *func, const char *file, int line);
void print_error(const char *error, const char *msg, const char *func, const char *file, int line);

void flush_stdout();

} // namespace godot::nfsmg

#endif // NEURON_FSM_GODOT_LOG_H
