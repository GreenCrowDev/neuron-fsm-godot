class_name TestState
extends GdUnitTestSuite

var _state : FSMState

var _entered := false
var _processed := false
var _exited := false

func before_test():
	_state = FSMState.new()

func test_state_construction():
	assert_int(_state.on_enter.get_connections().size()).is_equal(0)
	assert_int(_state.on_process.get_connections().size()).is_equal(0)
	assert_int(_state.on_exit.get_connections().size()).is_equal(0)
	
	# Add callbacks.
	_state.on_enter.connect(_set_entered_true)
	_state.on_process.connect(_set_processed_true)
	_state.on_exit.connect(_set_exited_true)
	
	assert_int(_state.on_enter.get_connections().size()).is_equal(1)
	assert_int(_state.on_process.get_connections().size()).is_equal(1)
	assert_int(_state.on_exit.get_connections().size()).is_equal(1)
	
	# Call callbacks.
	_state.on_enter.emit()
	_state.on_process.emit()
	_state.on_exit.emit()
	
	assert_bool(_entered).is_true()
	assert_bool(_processed).is_true()
	assert_bool(_exited).is_true()
	
	# Remove callbacks.
	_state.on_enter.disconnect(_set_entered_true)
	_state.on_process.disconnect(_set_processed_true)
	_state.on_exit.disconnect(_set_exited_true)
	
	assert_int(_state.on_enter.get_connections().size()).is_equal(0)
	assert_int(_state.on_process.get_connections().size()).is_equal(0)
	assert_int(_state.on_exit.get_connections().size()).is_equal(0)

func after_test():
	pass

func _set_entered_true():
	_entered = true

func _set_processed_true():
	_processed = true

func _set_exited_true():
	_exited = true
