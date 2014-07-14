// mymatrix.js
//
// simulates a simple grid of clickable widgets (a la matrixctrl)
//
// rld, 5.04
//

// inlets and outlets
inlets = 1;
outlets = 1;

// global variables
var mouseover = 0;
var click = 0;
var drag = 0;

var vbrgb = [1.,1.,1.,1.];
var vmrgb = [0., 1., 0., 1.];
var vfrgb = [1.,0.,0.2,1.];
var textColor = [0., 0., 0., 1.];

var traj_x = new Array(2);
var traj_y = new Array(2);
var traj_state = new Array(2);

var roomWidth = 1.;
var roomLength = 1.;
var scaleView = 1.;

for(i=0; i<traj_x.length; i++){
	traj_x[i] = sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[0];
	traj_y[i] = sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[1];
	traj_state[i] = 0;
}


// set up jsui defaults to 2d
sketch.default2d();

var windowDiagonal;
windowDiagonal = Math.sqrt(sketch.size[0]*sketch.size[0] + sketch.size[1]*sketch.size[1]);

var trajRadius;
trajRadius = 40./windowDiagonal;

// initialize graphics
draw();
refresh();

// draw -- main graphics function
function draw()
{
	with (sketch) 
	{
		
		// set how the polygons are rendered
		glclearcolor(vbrgb[0],vbrgb[1],vbrgb[2],vbrgb[3]); // set the clear color
		glclear(); // erase the background
		
		
		drawRoom();
		
		for(i=0; i<traj_x.length; i++){
			moveto(traj_x[i], traj_y[i], 0.);
			
			if(traj_state[i] == 0){
				glcolor(vmrgb[0],vmrgb[1],vmrgb[2],vmrgb[3]);
			}
			else{
				glcolor(vfrgb[0],vfrgb[1],vfrgb[2],vfrgb[3]);
			}
			circle(trajRadius);
			fontsize(0.03*windowDiagonal);
			glcolor(textColor[0], textColor[1], textColor[2], textColor[3]);
			move(-20./windowDiagonal, -10./windowDiagonal, 0.);
			text((i+1).toString());
		}
		
		
		
		
		
							
	}
}

// bang -- draw and refresh display
function bang()
{
	draw();
	refresh();
	
	trajRadius = 40./windowDiagonal;
}


function reset(){

	for(i=0; i<traj_x.length; i++){
		traj_x[i] = sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[0];
		traj_y[i] = sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[1];
		traj_state[i] = 0;
	}
	
	windowDiagonal = Math.sqrt(sketch.size[0]*sketch.size[0] + sketch.size[1]*sketch.size[1]);
	trajRadius = 40./windowDiagonal;

}

reset.local = 1;

function numTrajectories(val){
	if(val < traj_x.length){
		while(traj_x.length > val){
			traj_x.pop();
			traj_y.pop();
			traj_state.pop();
		}
		reset();
	}
	if(val > traj_x.length){
		while(traj_x.length < val){
			traj_x.push(sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[0]);
			traj_y.push(sketch.screentoworld(sketch.size[0]*0.5, sketch.size[1]*0.5)[1]);
			traj_state.push(0);
		}
	}
	
	bang();
}

function roomWidth(val){
	if(arguments.length == 1){
		roomWidth = arguments[0];
	}
	bang();
}

function roomLength(val){
	if(arguments.length == 1){
		roomLength = arguments[0];
	}
	bang();
}

function scale(val){
	if(arguments.length == 1){
		scaleView = arguments[0];
	}
	bang();
}


// list -- update our state to respond to a change from Max
function list(v)
{
	if(arguments.length==3) // bail if incorrect number of arguments
	{
		
		traj_x[arguments[0] - 1] = arguments[1];
		traj_y[arguments[0] - 1] = -1.*arguments[2];
		outlet(0, arguments[0], arguments[1]*scaleView, (arguments[2])*scaleView); // echo the list out the outlet	
	}
	bang(); // draw and refresh display
}

// clear -- wipe the state clean
function clear()
{
	for(i=0;i<ncols;i++)
	{
		for(j=0;j<nrows;j++)
		{
			state[i][j]=0; // wipe the state
		}
	}
	outlet(0, "clear"); // clear the router or matrix~ downstream
	bang(); // draw and refresh display
}

// frgb -- change foreground (clicked) sphere color
function frgb(r,g,b)
{
	vfrgb[0] = r/255.;
	vfrgb[1] = g/255.;
	vfrgb[2] = b/255.;
	vmrgb[0] = 0.5*(vfrgb[0]+vbrgb[0]);
	vmrgb[1] = 0.5*(vfrgb[1]+vbrgb[1]);
	vmrgb[2] = 0.5*(vfrgb[2]+vbrgb[2]);
	bang(); // draw and refresh display
}

// brgb -- change background color
function brgb(r,g,b)
{
	vbrgb[0] = r/255.;
	vbrgb[1] = g/255.;
	vbrgb[2] = b/255.;
	vmrgb[0] = 0.5*(vfrgb[0]+vbrgb[0]);
	vmrgb[1] = 0.5*(vfrgb[1]+vbrgb[1]);
	vmrgb[2] = 0.5*(vfrgb[2]+vbrgb[2]);
	bang(); // draw and refresh display
}

// onresize -- deal with a resized jsui box
function onresize(w,h)
{
	bang(); // draw and refresh display
}
onresize.local = 1; // make function private to prevent triggering from Max


function onidle(x, y, button, cmd, shift, capslock, option, ctrl){

	if(mouseover == 0){
		mouseover = 1;
	}
}
onidle.local=1;

function onidleout(x, y, button, cmd, shift, capslock, option, ctrl){
	mouseover = 0;
	if(click == 1 || drag == 1){
		//bang();
	}
}
onidleout.local=1;

// onclick -- deal with mouse click event
function onclick(x,y)
{
	
	if(mouseover){
		
		
		worldx = sketch.screentoworld(x,y)[0];
		worldy = sketch.screentoworld(x,y)[1];

		for(i=0; i<traj_x.length; i++){
		
			dist_x = worldx - traj_x[i];
			dist_y = worldy - traj_y[i];
		
			dist = Math.sqrt(dist_x*dist_x + dist_y*dist_y);
			if(dist <= trajRadius){
				traj_state[i] = 1;
				outlet(0, i+1, traj_x[i]*scaleView, 0., -1.*traj_y[i]*scaleView);
				for(j=0; j<traj_x.length; j++){
					if(j != i){
						traj_state[j] = 0;
					}
				}
				break;
			}
		}
		bang(); // draw and refresh display
	}
}
onclick.local = 1; // make function private to prevent triggering from Max


function ondrag(x, y){
	
	if(mouseover){
		worldx = sketch.screentoworld(x,y)[0];
		worldy = sketch.screentoworld(x,y)[1];
	
		for(i=0; i<traj_x.length; i++){
			if(traj_state[i] == 1){
				traj_x[i] = worldx;
				if(traj_x[i] > 1.){
					traj_x[i] = 1.
				}
				if(traj_x[i] < -1.){
					traj_x[i] = -1.;
				}
				
				traj_y[i] = worldy;
				if(traj_y[i] > 1.){
					traj_y[i] = 1.
				}
				if(traj_y[i] < -1.){
					traj_y[i] = -1.;
				}
				
				outlet(0, i+1, traj_x[i]*scaleView, 0., -1.*traj_y[i]*scaleView);
			}
		}
		bang();
	}
}



function drawRoom(){
	with(sketch){
		
		glcolor(1., 0., 0., 1.);
		linesegment(-roomWidth*0.5/scaleView, roomLength*0.5/scaleView, 0., roomWidth*0.5/scaleView, roomLength*0.5/scaleView, 0.);
		linesegment(-roomWidth*0.5/scaleView, roomLength*0.5/scaleView, 0., -roomWidth*0.5/scaleView, -roomLength*0.5/scaleView, 0.);
		linesegment(-roomWidth*0.5/scaleView, -roomLength*0.5/scaleView, 0., roomWidth*0.5/scaleView, -roomLength*0.5/scaleView, 0.);
		linesegment(roomWidth*0.5/scaleView, -roomLength*0.5/scaleView, 0., roomWidth*0.5/scaleView, roomLength*0.5/scaleView, 0.);
	}
}

drawRoom.local = 1;


	