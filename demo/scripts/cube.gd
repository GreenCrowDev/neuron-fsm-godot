@tool
extends MeshInstance3D

var fsm: FSM

# FSM states transitions.
var green_to_yellow: StringName = "green_to_yellow"
var yellow_to_red: StringName = "yellow_to_red"
var red_to_green: StringName = "red_to_green"

signal _do_make_yellow
@export var make_yellow: bool:
	set(value):
		_do_make_yellow.emit()

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	_do_make_yellow.connect(func(): fsm.process_event(green_to_yellow))
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if(fsm):
		fsm.tick(delta)

func _init():
	# 1. Define states.
	
	var green_state_name: StringName = "Green"
	var green_state: FSMState = FSMState.new()
	green_state.on_process.connect(func(double): print("Green!"))
	
	var yellow_state_name: StringName = "Yellow"
	var yellow_state: FSMState = FSMState.new()
	yellow_state.on_process.connect(func(double): print("Yellow!"))
	
	var red_state_name: StringName = "Red"
	var red_state: FSMState = FSMState.new()
	red_state.on_process.connect(func(double): print("Red!"))
	
	# 2. Initialize finite state machine.
	
	fsm = FSM.new()
	
	fsm.register_state(green_state_name, green_state)
	fsm.set_starting_state(green_state_name)
	
	fsm.register_state(yellow_state_name, yellow_state)
	fsm.register_state(red_state_name, red_state)
	
	# 3. Define states transitions.
	
	fsm.add_transition(green_state_name, green_to_yellow, yellow_state_name)
	fsm.add_transition(yellow_state_name, yellow_to_red, red_state_name)
	fsm.add_transition(red_state_name, red_to_green, green_state_name)
	
	# 4. Lock and run the FSM.
	
	fsm.lock()
	fsm.start()
