@tool
extends MeshInstance3D

var fsm: FSM

@export var button: bool:
	set(value):
		_do_button()

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	print("Hello")
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	pass

func _do_button():
	fsm = FSM.new()
	print(fsm.test_func())
