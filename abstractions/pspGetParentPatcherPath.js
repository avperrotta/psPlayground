inlets = 1;
outlets = 1;
setinletassist(0, "bang or path msg");

var myOutsidePath;

function bang(){
	var p = this.patcher;
	while (p.parentpatcher){
		p = p.parentpatcher;
		
	}
	
	var pSize = p.filepath.length;
	var mSize = myOutsidePath[1].length;
	var aux;
	if(pSize < mSize){
		aux = myOutsidePath[1];
	}
	else{
		aux = p.filepath;
	}
	
	aux = myOutsidePath[1];
	var lastIndex = aux.lastIndexOf("/");
	var pathSize = aux.length - (aux.length - lastIndex) + 1;
	var path = aux.substr(0, pathSize);
	
	/*
	if (jsarguments.length == 3){
		var trajName = jsarguments[1];
		var trajNum = jsarguments[2];
	}
	else{
		var trajName = "default-";
		var trajNum = "trajectory-saveFile";
	}
	
	path = path + trajName + "-" + trajNum + ".txt";
	*/
	outlet(0, path);
}

function path()
{
	myOutsidePath = arrayfromargs(messagename, arguments);
	bang();
}