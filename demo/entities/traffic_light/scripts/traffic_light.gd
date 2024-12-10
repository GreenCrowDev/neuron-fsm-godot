extends Node3D

var fsm: FSM
var green_emission = preload("res://entities/traffic_light/materials/green_emission.tres")
var yellow_emission = preload("res://entities/traffic_light/materials/yellow_emission.tres")
var red_emission = preload("res://entities/traffic_light/materials/red_emission.tres")
var emission_value: float = 10

@onready
var timer: Timer = $Timer

# FSM states transitions and callables.
var green_to_yellow: StringName = "green_to_yellow"
var yellow_to_red: StringName = "yellow_to_red"
var red_to_green: StringName = "red_to_green"
var green_to_yellow_call: Callable = func(): fsm.process_event(green_to_yellow)
var yellow_to_red_call: Callable = func(): fsm.process_event(yellow_to_red)
var red_to_green_call: Callable = func(): fsm.process_event(red_to_green)

func _process(delta: float) -> void:
	if(fsm):
		fsm.tick(delta)

func _ready() -> void:
	green_emission.emission_energy_multiplier = 0
	yellow_emission.emission_energy_multiplier = 0
	red_emission.emission_energy_multiplier = 0
	
	# 1. Define states.
	
	var green_state_name: StringName = "Green"
	var green_state: FSMState = FSMState.new()
	green_state.on_enter.connect(func():
		timer.timeout.connect(green_to_yellow_call)
		green_emission.emission_energy_multiplier = emission_value
		)
	green_state.on_process.connect(func(_double): print("Green!"))
	green_state.on_exit.connect(func():
		timer.timeout.disconnect(green_to_yellow_call)
		green_emission.emission_energy_multiplier = 0
		)
	
	var yellow_state_name: StringName = "Yellow"
	var yellow_state: FSMState = FSMState.new()
	yellow_state.on_enter.connect(func():
		timer.timeout.connect(yellow_to_red_call)
		yellow_emission.emission_energy_multiplier = emission_value
		)
	yellow_state.on_process.connect(func(_double): print("Yellow!"))
	yellow_state.on_exit.connect(func():
		timer.timeout.disconnect(yellow_to_red_call)
		yellow_emission.emission_energy_multiplier = 0
		)
	
	var red_state_name: StringName = "Red"
	var red_state: FSMState = FSMState.new()
	red_state.on_enter.connect(func():
		timer.timeout.connect(red_to_green_call)
		red_emission.emission_energy_multiplier = emission_value
		)
	red_state.on_process.connect(func(_double): print("Red!"))
	red_state.on_exit.connect(func():
		timer.timeout.disconnect(red_to_green_call)
		red_emission.emission_energy_multiplier = 0
		)
	
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
