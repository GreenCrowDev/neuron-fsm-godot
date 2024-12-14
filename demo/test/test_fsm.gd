class_name TestFSM
extends GdUnitTestSuite

var _fsm : FSM

func before_test():
	_fsm = FSM.new()

func test_fsm_initialization():
	# Check initial state of the FSM.
	assert_bool(_fsm.is_locked()).is_false()
	assert_bool(_fsm.is_running()).is_false()
	
	# Register a state.
	var state := FSMState.new()
	var state_name := "Start"
	_fsm.register_state(state_name, state)
	
	# Check if the state was registered.
	var registered_state = _fsm.get_state(state_name)
	assert_object(registered_state).is_equal(state)
	
	# Set the starting state.
	_fsm.set_starting_state(state_name)
	assert_str(_fsm.get_starting_state_name()).is_equal(state_name)
	assert_object(_fsm.get_starting_state()).is_equal(state)

func test_fsm_cannot_lock():
	_fsm.lock()
	# FSM cannot be locked if a starting state has not been set.
	assert_bool(_fsm.is_locked()).is_false()

func test_fsm_cannot_start():
	_fsm.start()
	# FSM cannot be started if it is not locked.
	assert_bool(_fsm.is_running()).is_false()

func test_fsm_locked_behaviour():
	var start_state := FSMState.new()
	var start_state_name := "Start"
	_fsm.register_state(start_state_name, start_state)
	_fsm.set_starting_state(start_state_name)
	
	var new_state := FSMState.new()
	var new_state_name := "New state"
	_fsm.register_state(new_state_name, new_state)
	
	var start_to_new_event := "Start to New"
	_fsm.add_transition(start_state_name, start_to_new_event, new_state_name)
	
	_fsm.lock()
	assert_bool(_fsm.is_locked()).is_true()
	
	# States cannot be registered while the FSM is locked.
	var another_state := FSMState.new()
	var another_state_name := "Another State"
	_fsm.register_state(another_state_name, another_state)
	assert_object(_fsm.get_state(another_state_name)).is_null()
	
	# Running behaviour.
	
	_fsm.start()
	assert_bool(_fsm.is_running()).is_true()
	assert_str(_fsm.get_current_state_name()).is_equal(start_state_name)
	assert_object(_fsm.get_current_state()).is_equal(start_state)
	
	# Change state through an event.
	_fsm.process_event(start_to_new_event)
	assert_str(_fsm.get_current_state_name()).is_equal(new_state_name)
	assert_object(_fsm.get_current_state()).is_equal(new_state)
	
	# Change state manually.
	_fsm.change_state(start_state_name)
	assert_str(_fsm.get_current_state_name()).is_equal(start_state_name)
	assert_object(_fsm.get_current_state()).is_equal(start_state)
	
	_fsm.pause()
	assert_bool(_fsm.is_running()).is_false()
	
	_fsm.play()
	assert_bool(_fsm.is_running()).is_true()
	
	_fsm.stop()
	assert_bool(_fsm.is_running()).is_false()
	assert_str(_fsm.get_current_state_name()).is_empty()
	assert_object(_fsm.get_current_state()).is_null()
	
	_fsm.start()
	assert_bool(_fsm.is_running()).is_true()
	
	_fsm.reset()
	assert_bool(_fsm.is_running()).is_false()
	assert_str(_fsm.get_current_state_name()).is_empty()
	assert_object(_fsm.get_current_state()).is_null()
	
	_fsm.unlock()
	assert_bool(_fsm.is_locked()).is_false()

func after_test():
	pass
