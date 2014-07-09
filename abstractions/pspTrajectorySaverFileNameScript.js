inlets = 1;
outlets = 1;
setinletassist(0, "Some message");

function bang(){
	var p = this.patcher;
	while (p.parentpatcher){
		p = p.parentpatcher;
	}
		
	var lastIndex = p.filepath.lastIndexOf("/");
	var pathSize = p.filepath.length - (p.filepath.length - lastIndex) + 1;
	var path = p.filepath.substr(0, pathSize);
	
	
	if (jsarguments.length == 3){
		var trajName = jsarguments[1];
		var trajNum = jsarguments[2];
	}
	else{
		var trajName = "default-";
		var trajNum = "trajectory-saveFile";
	}
	
	path = path + trajName + "-" + trajNum + ".txt";
	
	outlet(0, path);
}