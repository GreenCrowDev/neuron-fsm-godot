@tool
extends MeshInstance3D

var fsm: FSM

@export var button: bool:
	set(value):
		_do_button()

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	print("ready")
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func _do_button():
	fsm = FSM.new()
	print(fsm.test_func())

# States declaration.
enum ColorStates {GREEN, YELLOW, RED}

class StateConnections:
	var i

func _init():
	
	# 1. Define states.
	
	var green_state: State = State.new()
	# Use state signals and lambas to define state functions.
	green_state.on_enter.connect(func(): print("Green!"))
	
	var yellow_state: State = State.new()
	var red_state: State = State.new()
	
	# 2. Define states transitions.
	
	var green_state_pair = StateConnections.new(green_state)
	var yellow_state_pair = StateConnections.new(yellow_state)
	var red_state_pair = StateConnections.new(red_state)
	
	green_state_connections.add_connection(gsevent1, yellow_state_pair)
	
	yellow_state_connections.add_connection(ysevent2, red_state_pair)
	
	red_state_connections.add_connection(rsevent3, green_state_pair)
	
	# 3. Initialize finite state machine.
	
	fsm = FSM.new(green_state_pair)
