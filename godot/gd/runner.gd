extends Node

func _ready():
	var args := OS.get_cmdline_args();
	var iters := 10000;
	var type := "cpp";
	var main:MainNode = get_node("/root/MainNode");
	
	for i in args.size():
		if(args[i] == "--iters" && i+1 < args.size()):
			iters = int(args[i+1]);
		if(args[i] == "--type" && i+1 < args.size()):
			type = args[i+1];
	print("측정 시작!");
	var avg_us:int;
	if(type == "cpp"):
		var varint = VariantBench.new();
		avg_us = varint.run(iters);
	elif(type == "gd"):
		avg_us = run_gd(iters);
	else:
		printerr("올바른 타입을 선택하세요 (cpp, gd)");
		return;
	main.saveData(type, "%d,%d" % [iters, avg_us]);
	print("측정 완료");
	get_tree().quit();

func run_gd(iters: int) -> int:
	var a = 1;
	var start := Time.get_ticks_usec()
	for i in iters:
		match typeof(a):
			TYPE_INT:                 a = 0.1
			TYPE_FLOAT:               a = Vector2()
			TYPE_VECTOR2:             a = Vector3()
			TYPE_VECTOR3:             a = Color()
			TYPE_COLOR:               a = ""
			TYPE_STRING:              a = PackedStringArray()
			TYPE_PACKED_STRING_ARRAY: a = 1
			_:                        a = 1
	return Time.get_ticks_usec() - start
