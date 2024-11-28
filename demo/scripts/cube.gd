@tool
extends MeshInstance3D

var fsm: FSM

signal _do_make_yellow
@export var make_yellow: bool:
	set(value):
		_do_make_yellow.emit()
		_do_button()

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	print("ready")
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if(fsm):
		# fsm.tick()
		pass
	pass

func _do_button():
	print(make_yellow)
	fsm = FSM.new()
	print(fsm.test_func())

class StateConnections:
	var i

func _init():
	
	# 1. Define states.
	
	var green_behaviour: StateBehaviour = StateBehaviour.new()
	green_behaviour.on_process.connect(func(): print("Green!"))
	
	var yellow_behaviour: StateBehaviour = StateBehaviour.new()
	yellow_behaviour.on_process.connect(func(): print("Yellow!"))
	
	var red_behaviour: StateBehaviour = StateBehaviour.new()
	red_behaviour.on_process.connect(func(): print("Red!"))
	
	# 2. Define states transitions.
	
	var green_state = State.new()
	var yellow_state = State.new()
	var red_state = State.new()
	
	green_state.set_behaviour(green_behaviour)
	green_state.add_signal_connection(_do_make_yellow, yellow_state)
	
	yellow_state.set_behaviour(yellow_behaviour)
	yellow_state.add_connection(func(): true, red_state)
	
	red_state.set_behaviour(red_behaviour)
	red_state.add_connection(func(): true, green_state)
	
	# 3. Initialize finite state machine.
	
	fsm = FSM.new()
	fsm.set_state(green_state)
