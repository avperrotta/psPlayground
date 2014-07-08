{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 6,
			"minor" : 1,
			"revision" : 6,
			"architecture" : "x86"
		}
,
		"rect" : [ 0.0, 44.0, 1390.0, 881.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"boxes" : [ 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-120",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1035.0, 810.0, 36.0, 18.0 ],
					"text" : "write"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-124",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1260.0, 915.0, 43.0, 18.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-122",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1260.0, 885.0, 72.0, 20.0 ],
					"text" : "loadmess 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1185.0, 675.0, 20.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-118",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1185.0, 705.0, 85.0, 18.0 ],
					"text" : "useReverb $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-119",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 705.0, 810.0, 36.0, 18.0 ],
					"text" : "write"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-116",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 469.5, 665.0, 52.0, 18.0 ],
					"text" : "save as"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-112",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1283.0, 435.0, 95.0, 20.0 ],
					"text" : "route loadSetup"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-109",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "int", "bang" ],
					"patching_rect" : [ 1283.0, 465.0, 46.0, 20.0 ],
					"text" : "t b i b"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-117",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 225.0, 825.0, 36.0, 18.0 ],
					"text" : "write"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-115",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 97.75, 810.0, 52.0, 18.0 ],
					"text" : "save as"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-53",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1168.0, 742.0, 223.0, 18.0 ],
					"text" : "write defaultSpatCalibration.maxpresets"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-113",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 920.0, 45.0, 155.0, 47.0 ],
					"text" : "after changing the number of speakers you must relaod the settings"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-111",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1218.0, 57.5, 123.0, 20.0 ],
					"text" : "r #1.universal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-110",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 765.0, 45.0, 150.0, 20.0 ],
					"text" : "NUMBER OF SPEAKERS"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 14.0,
					"id" : "obj-66",
					"maxclass" : "number",
					"minimum" : 0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 795.0, 70.0, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 14.0,
					"hidden" : 1,
					"id" : "obj-96",
					"linecount" : 3,
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 795.0, 128.0, 108.0, 53.0 ],
					"text" : "s #1.universal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 14.0,
					"hidden" : 1,
					"id" : "obj-108",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 795.0, 99.0, 116.0, 20.0 ],
					"text" : "numSpeakers $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-104",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 216.75, 765.0, 35.0, 18.0 ],
					"text" : "read"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-107",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 97.75, 780.0, 95.0, 18.0 ],
					"text" : "read from folder"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-98",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 448.0, 975.0, 35.0, 18.0 ],
					"text" : "read"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-95",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 371.75, 665.0, 95.0, 18.0 ],
					"text" : "read from folder"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 18.0,
					"frgb" : 0.0,
					"id" : "obj-94",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 202.75, 685.0, 221.0, 27.0 ],
					"text" : "CLICK THIS FIRST !!!! ->",
					"textcolor" : [ 1.0, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-103",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 675.0, 647.0, 150.0, 20.0 ],
					"text" : "test audio on/off"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 725.0, 593.0, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-88",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 725.0, 676.5, 41.0, 20.0 ],
					"text" : "gate~"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-79",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1125.0, 540.5, 32.5, 18.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 1125.0, 510.0, 65.0, 20.0 ],
					"text" : "closebang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-83",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1023.625, 656.0, 150.0, 33.0 ],
					"text" : "check the volume on the main patch !"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 1023.625, 607.5, 45.0, 45.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-64",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1042.5, 736.0, 150.0, 20.0 ],
					"text" : "calibration particle speed"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-12",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 987.5, 736.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-47",
					"linecount" : 2,
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1230.0, 825.0, 234.0, 31.0 ],
					"text" : "psp pSystemAccess calibration setSpeed $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-86",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1260.0, 665.0, 204.0, 18.0 ],
					"text" : "psp deleteParticleSystem calibration"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-85",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "" ],
					"patching_rect" : [ 1095.0, 593.0, 46.0, 20.0 ],
					"text" : "sel 1 0"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.0, 0.278065, 0.629843, 1.0 ],
					"bgoncolor" : [ 0.0, 0.826321, 1.0, 1.0 ],
					"bgovercolor" : [ 0.0, 0.559099, 0.835977, 1.0 ],
					"bgoveroncolor" : [ 0.0, 0.826321, 1.0, 1.0 ],
					"bordercolor" : [ 0.0, 0.4895, 1.0, 1.0 ],
					"borderoncolor" : [ 0.76378, 0.873918, 0.909957, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-78",
					"maxclass" : "textbutton",
					"mode" : 1,
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"outputmode" : 0,
					"parameter_enable" : 0,
					"patching_rect" : [ 780.0, 736.0, 180.0, 30.0 ],
					"text" : "load calibration trajectory",
					"textcolor" : [ 0.6, 0.6, 0.6, 1.0 ],
					"texton" : "delete calibration trajectory",
					"textoncolor" : [ 1.0, 0.936125, 0.997447, 1.0 ],
					"textovercolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textoveroncolor" : [ 0.956462, 0.956834, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-51",
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1095.0, 660.0, 25.0, 25.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-21",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1095.0, 630.0, 325.0, 18.0 ],
					"text" : "psp addParticleSystem spatCalibrationSystem calibration 1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 780.0, 705.0, 382.0, 20.0 ],
					"text" : "singleParticleParser #1 calibration 1 8 100 @useReverb true"
				}

			}
, 			{
				"box" : 				{
					"args" : [ "@file", -1, "@loop", 1, "@vol", 0 ],
					"id" : "obj-7",
					"maxclass" : "bpatcher",
					"name" : "demosound.maxpat",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 780.0, 593.0, 225.0, 95.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 270.0, 90.0, 225.0, 95.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.0, 0.278065, 0.629843, 1.0 ],
					"bgoncolor" : [ 0.0, 0.826321, 1.0, 1.0 ],
					"bgovercolor" : [ 0.0, 0.559099, 0.835977, 1.0 ],
					"bgoveroncolor" : [ 0.0, 0.826321, 1.0, 1.0 ],
					"bordercolor" : [ 0.0, 0.4895, 1.0, 1.0 ],
					"borderoncolor" : [ 0.76378, 0.873918, 0.909957, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-4",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"outputmode" : 0,
					"parameter_enable" : 0,
					"patching_rect" : [ 520.75, 45.0, 180.0, 30.0 ],
					"text" : "APPLY CHANGES",
					"textcolor" : [ 0.6, 0.6, 0.6, 1.0 ],
					"textoncolor" : [ 1.0, 0.936125, 0.997447, 1.0 ],
					"textovercolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textoveroncolor" : [ 0.956462, 0.956834, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 216.75, 45.0, 55.0, 18.0 ],
					"text" : "listdump"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-69",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 533.75, 676.5, 154.0, 47.0 ],
					"text" : "after reading a preset file you must click on a preset to activate it"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-50",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"patching_rect" : [ 879.0, 705.0, 100.0, 20.0 ],
					"text" : "t 1 b"
				}

			}
, 			{
				"box" : 				{
					"hidden" : 1,
					"id" : "obj-49",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 960.0, 768.0, 75.0, 18.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 1.768, -24.799999, 0, 7, "obj-2", "function", "add", 3.458, -55.799999, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 0.55, -43.399998, 0, 7, "obj-60", "function", "add", 0.9, -18.599998, 0, 7, "obj-60", "function", "add", 1.2, -6.2, 0, 7, "obj-60", "function", "add", 3.45, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 0.486, 0.6, 0, 7, "obj-76", "function", "add", 1.134, 0.85, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-12", "flonum", "float", 0.022, 5, "obj-66", "number", "int", 2 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-48",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1042.5, 736.0, 221.0, 18.0 ],
					"text" : "read defaultSpatCalibration.maxpresets"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-44",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 640.5, 768.0, 252.0, 18.0 ],
					"text" : "read #1-SpatCalibration.maxpresets"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 620.0, 736.0, 260.0, 18.0 ],
					"text" : "write #1-SpatCalibration.maxpresets"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 345.0, 718.0, 50.0, 18.0 ],
					"text" : "clearall"
				}

			}
, 			{
				"box" : 				{
					"bubblesize" : 18,
					"id" : "obj-15",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 345.0, 736.0, 257.5, 50.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, -12.4, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.7, -100.0, 0, 7, "obj-60", "function", "add", 3.464102, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.715, 0.0, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 0, 5, "obj-12", "flonum", "float", 0.0, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 2,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -3.5, 0, 7, "<invalid>", "function", "add", 0.598, -12.4, 0, 7, "<invalid>", "function", "add", 1.118, -31.0, 0, 7, "<invalid>", "function", "add", 1.69, -43.399998, 0, 7, "<invalid>", "function", "add", 3.464102, -55.799999, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 3.5, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 0.4, -18.599998, 0, 7, "<invalid>", "function", "add", 1.05, 0.0, 0, 7, "<invalid>", "function", "add", 3.464102, 12.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.324, 0.7, 0, 7, "<invalid>", "function", "add", 0.918, 0.9, 0, 7, "<invalid>", "function", "add", 1.782, 0.95, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 2.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 1, 5, "<invalid>", "flonum", "float", 0.02, 5, "<invalid>", "number", "int", 2 ]
						}
, 						{
							"number" : 3,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -12.4, 0, 7, "<invalid>", "function", "add", 1.664, -62.0, 0, 7, "<invalid>", "function", "add", 3.172, -80.599998, 0, 7, "<invalid>", "function", "add", 3.458, -100.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 1.0, -74.399994, 0, 7, "<invalid>", "function", "add", 3.464102, 0.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.594, 0.35, 0, 7, "<invalid>", "function", "add", 1.026, 0.55, 0, 7, "<invalid>", "function", "add", 1.782, 0.75, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 4.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 0, 5, "<invalid>", "flonum", "float", 0.0, 5, "<invalid>", "toggle", "int", 0, 5, "<invalid>", "number", "int", 4 ]
						}
, 						{
							"number" : 4,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -12.4, 0, 7, "<invalid>", "function", "add", 1.664, -62.0, 0, 7, "<invalid>", "function", "add", 3.172, -80.599998, 0, 7, "<invalid>", "function", "add", 3.464102, -93.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 1.0, -74.399994, 0, 7, "<invalid>", "function", "add", 3.464102, 0.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.594, 0.35, 0, 7, "<invalid>", "function", "add", 1.026, 0.55, 0, 7, "<invalid>", "function", "add", 1.782, 0.75, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 2.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 1, 5, "<invalid>", "flonum", "float", 0.015, 5, "<invalid>", "number", "int", 2 ]
						}
, 						{
							"number" : 5,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -12.4, 0, 7, "<invalid>", "function", "add", 1.664, -62.0, 0, 7, "<invalid>", "function", "add", 3.172, -80.599998, 0, 7, "<invalid>", "function", "add", 3.464102, -93.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 0.65, -43.399998, 0, 7, "<invalid>", "function", "add", 3.464102, 0.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.54, 0.45, 0, 7, "<invalid>", "function", "add", 1.026, 0.7, 0, 7, "<invalid>", "function", "add", 1.782, 0.85, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 2.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 1, 5, "<invalid>", "flonum", "float", 0.015, 5, "<invalid>", "number", "int", 2 ]
						}
, 						{
							"number" : 6,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -12.4, 0, 7, "<invalid>", "function", "add", 1.664, -62.0, 0, 7, "<invalid>", "function", "add", 3.172, -80.599998, 0, 7, "<invalid>", "function", "add", 3.464102, -93.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 0.55, -24.799999, 0, 7, "<invalid>", "function", "add", 1.15, 0.0, 0, 7, "<invalid>", "function", "add", 1.75, 6.2, 0, 7, "<invalid>", "function", "add", 2.55, 12.0, 0, 7, "<invalid>", "function", "add", 3.464102, 12.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.54, 0.45, 0, 7, "<invalid>", "function", "add", 1.026, 0.7, 0, 7, "<invalid>", "function", "add", 1.782, 0.85, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 2.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 1, 5, "<invalid>", "flonum", "float", 0.015, 5, "<invalid>", "number", "int", 2 ]
						}
, 						{
							"number" : 7,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -12.4, 0, 7, "<invalid>", "function", "add", 3.464102, -80.599998, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 1.7, -100.0, 0, 7, "<invalid>", "function", "add", 3.464102, 0.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 1.715, 0.0, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 4.0, 5, "<invalid>", "textbutton", "mode", 1, 5, "<invalid>", "textbutton", "int", 0, 5, "<invalid>", "flonum", "float", 0.0, 5, "<invalid>", "number", "int", 4 ]
						}
, 						{
							"number" : 8,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.65, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.782, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.003, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 9,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.0, -31.0, 0, 7, "obj-60", "function", "add", 3.464102, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.242, 0.7, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.003, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 10,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.0, -31.0, 0, 7, "obj-60", "function", "add", 3.464102, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.242, 0.7, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 0, 5, "obj-12", "flonum", "float", 0.003, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 11,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.65, -74.399994, 0, 7, "obj-60", "function", "add", 2.6, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.566, 0.1, 0, 7, "obj-76", "function", "add", 2.322, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.005, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 12,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.55, -18.599998, 0, 7, "obj-60", "function", "add", 3.45, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.512, 0.8, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.005, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 13,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -80.599998, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.2, -18.599998, 0, 7, "obj-60", "function", "add", 3.45, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.134, 0.85, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.009, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 14,
							"data" : [ 4, "obj-2", "function", "clear", 7, "obj-2", "function", "add", 0.0, 0.0, 0, 7, "obj-2", "function", "add", 3.464102, -62.0, 0, 5, "obj-2", "function", "domain", 3.464102, 6, "obj-2", "function", "range", -100.0, 12.0, 5, "obj-2", "function", "mode", 0, 5, "obj-35", "flonum", "float", 0.026, 5, "obj-36", "flonum", "float", 6.2, 5, "obj-24", "flonum", "float", 1.0, 5, "obj-29", "flonum", "float", 1.0, 5, "obj-31", "flonum", "float", 1.0, 5, "obj-34", "flonum", "float", 1.732051, 4, "obj-60", "function", "clear", 7, "obj-60", "function", "add", 0.0, -100.0, 0, 7, "obj-60", "function", "add", 1.2, -18.599998, 0, 7, "obj-60", "function", "add", 3.45, 0.0, 0, 5, "obj-60", "function", "domain", 3.464102, 6, "obj-60", "function", "range", -100.0, 12.0, 5, "obj-60", "function", "mode", 0, 5, "obj-42", "flonum", "float", 0.05, 5, "obj-38", "flonum", "float", 6.2, 4, "obj-76", "function", "clear", 7, "obj-76", "function", "add", 0.0, 0.0, 0, 7, "obj-76", "function", "add", 1.134, 0.85, 0, 7, "obj-76", "function", "add", 3.464102, 1.0, 0, 5, "obj-76", "function", "domain", 3.464102, 6, "obj-76", "function", "range", 0.0, 1.0, 5, "obj-76", "function", "mode", 0, 5, "obj-73", "flonum", "float", 0.054, 5, "obj-70", "flonum", "float", 0.05, 5, "obj-13", "incdec", "float", 2.0, 5, "obj-78", "textbutton", "mode", 1, 5, "obj-78", "textbutton", "int", 1, 5, "obj-12", "flonum", "float", 0.021, 5, "obj-66", "number", "int", 2 ]
						}
, 						{
							"number" : 15,
							"data" : [ 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 1.768, -24.799999, 0, 7, "<invalid>", "function", "add", 3.458, -55.799999, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.026, 5, "<invalid>", "flonum", "float", 6.2, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.0, 5, "<invalid>", "flonum", "float", 1.732051, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, -100.0, 0, 7, "<invalid>", "function", "add", 0.55, -43.399998, 0, 7, "<invalid>", "function", "add", 0.9, -18.599998, 0, 7, "<invalid>", "function", "add", 1.2, -6.2, 0, 7, "<invalid>", "function", "add", 3.45, 0.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", -100.0, 12.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "flonum", "float", 6.2, 4, "<invalid>", "function", "clear", 7, "<invalid>", "function", "add", 0.0, 0.0, 0, 7, "<invalid>", "function", "add", 0.486, 0.6, 0, 7, "<invalid>", "function", "add", 1.134, 0.85, 0, 7, "<invalid>", "function", "add", 3.464102, 1.0, 0, 5, "<invalid>", "function", "domain", 3.464102, 6, "<invalid>", "function", "range", 0.0, 1.0, 5, "<invalid>", "function", "mode", 0, 5, "<invalid>", "flonum", "float", 0.054, 5, "<invalid>", "flonum", "float", 0.05, 5, "<invalid>", "incdec", "float", 2.0, 5, "<invalid>", "flonum", "float", 0.022, 5, "<invalid>", "number", "int", 2 ]
						}
 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 11,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 75.0, 870.0, 495.0, 20.0 ],
					"text" : "speakerPosition #1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1365.0, 150.0, 115.0, 20.0 ],
					"text" : "route numSpeakers"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1365.0, 57.5, 123.0, 20.0 ],
					"text" : "r #1.unparsed"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-137",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 179.0, 752.0, 37.0, 18.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-135",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 97.75, 780.0, 37.0, 18.0 ],
					"text" : "open"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-133",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 97.75, 752.0, 73.0, 18.0 ],
					"text" : "manual edit"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-89",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 179.0, 620.0, 90.0, 20.0 ],
					"text" : "speaker num"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-55",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 160.0, 725.0, 23.0, 20.0 ],
					"text" : "z"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-56",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 160.0, 695.0, 23.0, 20.0 ],
					"text" : "y"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-81",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 160.0, 665.0, 23.0, 20.0 ],
					"text" : "x"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-82",
					"maxclass" : "flonum",
					"maximum" : 0.5,
					"minimum" : -0.5,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 725.0, 62.25, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-84",
					"maxclass" : "flonum",
					"maximum" : 0.5,
					"minimum" : -0.5,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 695.0, 62.25, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-87",
					"maxclass" : "flonum",
					"maximum" : 0.5,
					"minimum" : -0.5,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 665.0, 62.25, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-52",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 67.75, 593.0, 217.25, 20.0 ],
					"text" : "speakers position (% of room size)"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-46",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1365.0, 195.0, 81.0, 20.0 ],
					"text" : "prepend max"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-45",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 130.5, 642.0, 43.0, 18.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-16",
					"maxclass" : "number",
					"maximum" : 2,
					"minimum" : 1,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 130.5, 620.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "incdec",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 620.0, 30.0, 32.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"hidden" : 1,
					"id" : "obj-6",
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 15.0, 15.0, 25.0, 25.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 97.75, 15.0, 60.0, 20.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-106",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1215.0, 345.0, 129.0, 20.0 ],
					"text" : "prepend setRoomSize"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-105",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1215.0, 315.0, 70.0, 20.0 ],
					"text" : "pak 0. 0. 0."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-102",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 765.0, 915.0, 137.0, 20.0 ],
					"text" : "s #1.unparsed"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-101",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 570.0, 630.0, 201.0, 20.0 ],
					"text" : "prepend speakerDistanceAmplitude"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-100",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 894.0, 630.0, 115.0, 20.0 ],
					"text" : "prepend reverbSize"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-99",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 371.75, 630.0, 117.0, 20.0 ],
					"text" : "prepend reverbGain"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-93",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1065.0, 333.0, 83.0, 18.0 ],
					"text" : "setdomain $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-92",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 1065.0, 298.0, 32.5, 20.0 ],
					"text" : "* 2."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-91",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 960.0, 298.0, 105.0, 20.0 ],
					"text" : "2x room diagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-90",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 345.0, 605.0, 301.0, 47.0 ],
					"text" : "after changing parameters, you must save the settings on the preset object (shift + click) and click on the \"write\" button to compute the new values."
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.501961, 0.0, 0.0, 1.0 ],
					"bgoncolor" : [ 1.0, 0.4, 0.4, 1.0 ],
					"bgovercolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"bgoveroncolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"bordercolor" : [ 0.501961, 0.0, 0.0, 1.0 ],
					"borderoncolor" : [ 1.0, 0.4, 0.4, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-80",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"outputmode" : 0,
					"parameter_enable" : 0,
					"patching_rect" : [ 464.0, 685.0, 45.0, 30.0 ],
					"text" : "Write",
					"textcolor" : [ 0.6, 0.6, 0.6, 1.0 ],
					"textoncolor" : [ 1.0, 1.0, 0.4, 1.0 ],
					"textovercolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textoveroncolor" : [ 1.0, 1.0, 0.4, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.0, 0.501961, 0.25098, 1.0 ],
					"bgoncolor" : [ 0.0, 1.0, 0.501961, 1.0 ],
					"bgovercolor" : [ 0.0, 1.0, 0.0, 1.0 ],
					"bgoveroncolor" : [ 0.0, 1.0, 0.501961, 1.0 ],
					"bordercolor" : [ 0.4, 1.0, 0.4, 1.0 ],
					"borderoncolor" : [ 0.0, 0.501961, 0.501961, 1.0 ],
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-77",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"outputmode" : 0,
					"parameter_enable" : 0,
					"patching_rect" : [ 417.5, 685.0, 45.0, 30.0 ],
					"text" : "Read",
					"textcolor" : [ 0.6, 0.6, 0.6, 1.0 ],
					"textoncolor" : [ 0.4, 1.0, 0.8, 1.0 ],
					"textovercolor" : [ 1.0, 1.0, 1.0, 1.0 ],
					"textoveroncolor" : [ 0.4, 1.0, 0.8, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-62",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 725.0, 353.0, 336.0, 20.0 ],
					"text" : "reverberation (0 - 1.) x trajectory distance from room center"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-63",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 600.0, 515.0, 21.5, 20.0 ],
					"text" : "0."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-65",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 604.0, 359.0, 45.0, 20.0 ],
					"text" : "1."
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-67",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1005.0, 533.0, 82.25, 33.0 ],
					"text" : "2x room diagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-68",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 620.0, 533.0, 25.0, 20.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-70",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 810.0, 330.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-72",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 860.0, 333.0, 83.0, 18.0 ],
					"text" : "gridstep_y $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-73",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 675.0, 330.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-74",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 725.0, 333.0, 83.0, 18.0 ],
					"text" : "gridstep_x $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-75",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 620.0, 335.0, 37.0, 18.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 0.486, 0.6, 0, 1.134, 0.85, 0, 3.464102, 1.0, 0 ],
					"bgcolor" : [ 1.0, 1.0, 0.7, 1.0 ],
					"bordercolor" : [ 0.0, 0.4, 0.0, 1.0 ],
					"cursorcolor" : [ 0.3, 0.3, 1.0, 1.0 ],
					"domain" : 3.464102,
					"grid" : 3,
					"gridcolor" : [ 0.044134, 0.0, 0.0, 1.0 ],
					"gridstep_x" : 0.054,
					"gridstep_y" : 0.05,
					"id" : "obj-76",
					"linecolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 620.0, 353.0, 430.0, 182.0 ],
					"snap2grid" : 3
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-61",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 210.0, 353.0, 316.0, 20.0 ],
					"text" : "reverb wet/dry (dB) x trajectory distance from room center"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-23",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 50.75, 515.0, 60.0, 20.0 ],
					"text" : "-100 dB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-25",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 67.75, 380.0, 45.0, 20.0 ],
					"text" : "0 dB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-27",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 480.0, 533.0, 82.25, 33.0 ],
					"text" : "2x room diagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 97.75, 533.0, 18.0, 20.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-38",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 287.75, 330.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-39",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 337.75, 333.0, 83.0, 18.0 ],
					"text" : "gridstep_y $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-42",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 152.75, 330.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 202.75, 333.0, 83.0, 18.0 ],
					"text" : "gridstep_x $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-59",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 97.75, 335.0, 37.0, 18.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, -100.0, 0, 0.55, -43.399998, 0, 0.9, -18.599998, 0, 1.2, -6.2, 0, 3.45, 0.0, 0 ],
					"bgcolor" : [ 1.0, 1.0, 0.7, 1.0 ],
					"bordercolor" : [ 0.0, 0.4, 0.0, 1.0 ],
					"cursorcolor" : [ 0.3, 0.3, 1.0, 1.0 ],
					"domain" : 3.464102,
					"grid" : 3,
					"gridcolor" : [ 0.044134, 0.0, 0.0, 1.0 ],
					"gridstep_x" : 0.05,
					"gridstep_y" : 6.2,
					"id" : "obj-60",
					"linecolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 353.0, 430.0, 182.0 ],
					"range" : [ -100.0, 12.0 ],
					"snap2grid" : 3
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-58",
					"maxclass" : "textbutton",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 97.75, 45.0, 100.0, 20.0 ],
					"text" : "load default"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"hidden" : 1,
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 6,
							"minor" : 1,
							"revision" : 6,
							"architecture" : "x86"
						}
,
						"rect" : [ 25.0, 69.0, 293.0, 256.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"boxes" : [ 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-7",
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 30.0, 210.0, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-6",
									"maxclass" : "newobj",
									"numinlets" : 1,
									"numoutlets" : 3,
									"outlettype" : [ "float", "float", "float" ],
									"patching_rect" : [ 30.0, 90.0, 207.0, 20.0 ],
									"text" : "unpack 0. 0. 0."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-5",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 30.0, 60.0, 109.0, 20.0 ],
									"text" : "pak 0. 0. 0."
								}

							}
, 							{
								"box" : 								{
									"fontname" : "Arial",
									"fontsize" : 12.0,
									"id" : "obj-4",
									"maxclass" : "newobj",
									"numinlets" : 3,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 30.0, 165.0, 207.0, 20.0 ],
									"text" : "expr sqrt($f1*$f1 + $f2*$f2 + $f3*$f3)"
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-3",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"patching_rect" : [ 120.0, 15.0, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-2",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"patching_rect" : [ 75.0, 15.0, 25.0, 25.0 ]
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-1",
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "float" ],
									"patching_rect" : [ 30.0, 15.0, 25.0, 25.0 ]
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-2", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-5", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-3", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-7", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-4", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-6", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-5", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 2 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 2 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 1 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-4", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-6", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 1215.0, 255.0, 115.0, 20.0 ],
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"default_fontsize" : 12.0,
						"description" : "",
						"digest" : "",
						"fontface" : 0,
						"fontname" : "Arial",
						"fontsize" : 12.0,
						"globalpatchername" : "",
						"tags" : ""
					}
,
					"text" : "p calculateDiagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-40",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1065.0, 235.0, 60.0, 20.0 ],
					"text" : "diagonal"
				}

			}
, 			{
				"box" : 				{
					"cantchange" : 1,
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-34",
					"ignoreclick" : 1,
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1065.0, 255.0, 105.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1065.0, 175.0, 75.0, 20.0 ],
					"text" : "room lenght"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-31",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1065.0, 195.0, 105.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1065.0, 130.0, 75.0, 20.0 ],
					"text" : "room height"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1065.0, 150.0, 105.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-26",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1065.0, 85.0, 75.0, 20.0 ],
					"text" : "room width"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-24",
					"maxclass" : "flonum",
					"maximum" : 1.0,
					"minimum" : 0.0,
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1065.0, 105.0, 105.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-22",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 58.0, 267.0, 60.0, 20.0 ],
					"text" : "-100 dB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-20",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 75.0, 132.0, 45.0, 20.0 ],
					"text" : "0 dB"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-18",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 780.0, 105.0, 330.0, 20.0 ],
					"text" : "amplitude (dB) x trajectory to speaker distance"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-11",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 535.0, 298.0, 90.0, 20.0 ],
					"text" : "room diagonal"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"frgb" : 0.0,
					"id" : "obj-9",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 105.0, 298.0, 18.0, 20.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-36",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 295.0, 82.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 345.0, 85.0, 83.0, 18.0 ],
					"text" : "gridstep_y $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 160.0, 82.0, 50.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 210.0, 85.0, 83.0, 18.0 ],
					"text" : "gridstep_x $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 105.0, 87.0, 37.0, 18.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"addpoints" : [ 0.0, 0.0, 0, 1.768, -24.799999, 0, 3.458, -55.799999, 0 ],
					"bgcolor" : [ 1.0, 1.0, 0.7, 1.0 ],
					"bordercolor" : [ 0.0, 0.4, 0.0, 1.0 ],
					"cursorcolor" : [ 0.3, 0.3, 1.0, 1.0 ],
					"domain" : 3.464102,
					"grid" : 3,
					"gridcolor" : [ 0.044134, 0.0, 0.0, 1.0 ],
					"gridstep_x" : 0.026,
					"gridstep_y" : 6.2,
					"id" : "obj-2",
					"linecolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"maxclass" : "function",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "float", "", "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 105.0, 105.0, 945.0, 193.0 ],
					"range" : [ -100.0, 12.0 ],
					"snap2grid" : 3
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 36.0, 107.25, 36.0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1374.5, 182.0, 1374.5, 182.0 ],
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 903.5, 663.0, 912.0, 663.0, 912.0, 900.0, 774.5, 900.0 ],
					"source" : [ "obj-100", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 579.5, 855.0, 774.5, 855.0 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 10 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-104", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-106", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1224.5, 336.0, 1224.5, 336.0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1224.5, 900.0, 774.5, 900.0 ],
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-104", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-107", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-108", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1306.0, 610.0, 354.5, 610.0 ],
					"source" : [ "obj-109", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1292.5, 486.0, 1182.0, 486.0, 1182.0, 30.0, 530.25, 30.0 ],
					"source" : [ "obj-109", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-77", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1319.5, 584.5, 427.0, 584.5 ],
					"source" : [ "obj-109", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1227.5, 135.0, 1374.5, 135.0 ],
					"source" : [ "obj-111", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-112", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-119", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 10 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 1 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-118", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-119", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-47", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-120", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-118", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-124", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-122", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-124", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 654.0, 84.0, 654.0, 84.0, 585.0, 140.0, 585.0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-135", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 771.0, 107.25, 771.0 ],
					"source" : [ "obj-133", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 10 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 855.0, 560.5, 855.0 ],
					"source" : [ "obj-135", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 10 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 188.5, 855.0, 560.5, 855.0 ],
					"source" : [ "obj-137", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 560.5, 900.0, 774.5, 900.0 ],
					"source" : [ "obj-14", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 84.5, 891.0, 72.0, 891.0, 72.0, 585.0, 140.0, 585.0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 441.5, 900.0, 60.0, 900.0, 60.0, 720.0, 107.25, 720.0 ],
					"source" : [ "obj-14", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 322.5, 900.0, 60.0, 900.0, 60.0, 690.0, 107.25, 690.0 ],
					"source" : [ "obj-14", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 203.5, 900.0, 60.0, 900.0, 60.0, 660.0, 107.25, 660.0 ],
					"source" : [ "obj-14", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 513.5, 798.0, 279.0, 798.0, 279.0, 585.0, 140.0, 585.0 ],
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 434.0, 795.0, 714.25, 795.0, 714.25, 35.0, 226.25, 35.0 ],
					"source" : [ "obj-15", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 513.5, 810.0, 84.0, 810.0, 84.0, 720.0, 107.25, 720.0 ],
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 513.5, 810.0, 84.0, 810.0, 84.0, 690.0, 107.25, 690.0 ],
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 513.5, 810.0, 84.0, 810.0, 84.0, 660.0, 107.25, 660.0 ],
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 513.5, 798.0, 261.0, 798.0, 261.0, 723.0, 198.0, 723.0, 198.0, 651.0, 330.0, 651.0, 330.0, 588.0, 734.5, 588.0 ],
					"source" : [ "obj-15", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 140.0, 660.0, 84.5, 660.0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 140.0, 642.0, 140.0, 642.0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 731.833313, 315.0, 636.0, 315.0, 636.0, 330.0, 579.5, 330.0 ],
					"source" : [ "obj-2", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 126.0, 1152.0, 126.0, 1152.0, 135.0, 1200.0, 135.0, 1200.0, 300.0, 1224.5, 300.0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 4 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 497.0, 274.899994, 497.0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 126.0, 1152.0, 126.0, 1152.0, 135.0, 1224.5, 135.0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 1 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 171.0, 1152.0, 171.0, 1152.0, 180.0, 1200.0, 180.0, 1200.0, 300.0, 1250.0, 300.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 5 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 171.0, 1152.0, 171.0, 1152.0, 180.0, 1182.0, 180.0, 1182.0, 855.0, 322.5, 855.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 1 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 171.0, 1152.0, 171.0, 1152.0, 180.0, 1272.5, 180.0 ],
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 114.5, 105.0, 114.5, 105.0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 2 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 225.0, 1200.0, 225.0, 1200.0, 300.0, 1275.5, 300.0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 6 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 216.0, 1062.0, 216.0, 1062.0, 285.0, 1158.0, 285.0, 1158.0, 855.0, 370.100006, 855.0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 2 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 225.0, 1320.5, 225.0 ],
					"source" : [ "obj-31", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 219.5, 105.0, 207.0, 105.0, 207.0, 102.0, 144.0, 102.0, 144.0, 84.0, 102.0, 84.0, 102.0, 102.0, 114.5, 102.0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-92", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 276.0, 1074.5, 276.0 ],
					"source" : [ "obj-34", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 169.5, 102.0, 156.0, 102.0, 156.0, 78.0, 219.5, 78.0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 304.5, 69.0, 354.5, 69.0 ],
					"source" : [ "obj-36", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 354.5, 69.0, 102.0, 69.0, 102.0, 102.0, 114.5, 102.0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 297.25, 327.0, 347.25, 327.0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 347.25, 315.0, 135.0, 315.0, 135.0, 330.0, 93.0, 330.0, 93.0, 348.0, 107.25, 348.0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 530.25, 75.0, 438.0, 75.0, 438.0, 30.0, 226.25, 30.0 ],
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-34", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1224.5, 285.0, 1062.0, 285.0, 1062.0, 252.0, 1074.5, 252.0 ],
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 162.25, 351.0, 147.0, 351.0, 147.0, 315.0, 212.25, 315.0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 629.5, 798.0, 330.0, 798.0, 330.0, 732.0, 354.5, 732.0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 650.0, 798.0, 330.0, 798.0, 330.0, 732.0, 354.5, 732.0 ],
					"source" : [ "obj-44", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 140.0, 660.0, 84.0, 660.0, 84.0, 615.0, 107.25, 615.0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1374.5, 394.5, 140.0, 394.5 ],
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1239.5, 858.0, 1215.0, 858.0, 1215.0, 735.0, 1239.0, 735.0, 1239.0, 660.0, 1122.0, 660.0, 1122.0, 657.0, 1104.5, 657.0 ],
					"source" : [ "obj-47", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1006.833313, 795.0, 573.416687, 795.0, 573.416687, 610.0, 140.0, 610.0 ],
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 988.166687, 798.0, 1239.0, 798.0, 1239.0, 375.0, 1182.0, 375.0, 1182.0, 30.0, 226.25, 30.0 ],
					"source" : [ "obj-49", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1006.833313, 810.0, 84.0, 810.0, 84.0, 720.0, 107.25, 720.0 ],
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1006.833313, 810.0, 84.0, 810.0, 84.0, 690.0, 107.25, 690.0 ],
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1006.833313, 810.0, 84.0, 810.0, 84.0, 660.0, 107.25, 660.0 ],
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1006.833313, 786.0, 1239.0, 786.0, 1239.0, 660.0, 1173.0, 660.0, 1173.0, 648.0, 1080.0, 648.0, 1080.0, 579.0, 734.5, 579.0 ],
					"source" : [ "obj-49", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 226.25, 63.0, 207.0, 63.0, 207.0, 78.0, 102.0, 78.0, 102.0, 102.0, 114.5, 102.0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 226.25, 63.0, 207.0, 63.0, 207.0, 78.0, 45.0, 78.0, 45.0, 348.0, 107.25, 348.0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 226.25, 207.5, 629.5, 207.5 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-50", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 888.5, 735.0, 945.0, 735.0, 945.0, 765.0, 969.5, 765.0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-49", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1177.5, 723.0, 981.0, 723.0, 981.0, 732.0, 957.0, 732.0, 957.0, 762.0, 969.5, 762.0 ],
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 212.25, 315.0, 135.0, 315.0, 135.0, 330.0, 93.0, 330.0, 93.0, 348.0, 107.25, 348.0 ],
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 66.0, 36.0, 66.0, 36.0, 585.0, 879.0, 585.0, 879.0, 690.0, 888.5, 690.0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 107.25, 354.0, 107.25, 354.0 ],
					"source" : [ "obj-59", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-112", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 24.5, 42.0, 84.0, 42.0, 84.0, 0.0, 1200.0, 0.0, 1200.0, 420.0, 1292.5, 420.0 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 381.25, 549.0, 474.0, 549.0, 474.0, 615.0, 381.25, 615.0 ],
					"source" : [ "obj-60", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-108", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-66", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 1 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 819.5, 327.0, 869.5, 327.0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 869.5, 315.0, 636.0, 315.0, 636.0, 330.0, 615.0, 330.0, 615.0, 348.0, 629.5, 348.0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 684.5, 351.0, 672.0, 351.0, 672.0, 315.0, 734.5, 315.0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 734.5, 315.0, 636.0, 315.0, 636.0, 330.0, 615.0, 330.0, 615.0, 348.0, 629.5, 348.0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"midpoints" : [ 629.5, 354.0, 629.5, 354.0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-100", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 903.5, 549.0, 996.0, 549.0, 996.0, 615.0, 903.5, 615.0 ],
					"source" : [ "obj-76", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 7 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 427.0, 855.0, 417.700012, 855.0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-44", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 427.0, 717.0, 615.0, 717.0, 615.0, 765.0, 650.0, 765.0 ],
					"source" : [ "obj-77", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1134.5, 579.0, 1017.0, 579.0, 1017.0, 693.0, 777.0, 693.0, 777.0, 729.0, 789.5, 729.0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-97", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1134.5, 579.0, 734.5, 579.0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1374.5, 105.0, 1374.5, 105.0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 8 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 473.5, 855.0, 465.299988, 855.0 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 473.5, 717.0, 629.5, 717.0 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 3 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 747.0, 84.0, 747.0, 84.0, 855.0, 227.300003, 855.0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 2 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 717.0, 84.0, 717.0, 84.0, 855.0, 179.699997, 855.0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1118.0, 636.0, 1269.5, 636.0 ],
					"source" : [ "obj-85", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-51", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1269.5, 678.0, 1131.0, 678.0, 1131.0, 657.0, 1104.5, 657.0 ],
					"source" : [ "obj-86", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 1 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 107.25, 687.0, 84.0, 687.0, 84.0, 855.0, 132.100006, 855.0 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-17", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-88", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 318.0, 1074.5, 318.0 ],
					"source" : [ "obj-92", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 360.0, 594.5, 360.0, 594.5, 95.0, 114.5, 95.0 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 351.5, 107.25, 351.5 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 1074.5, 351.0, 1050.0, 351.0, 1050.0, 330.0, 870.0, 330.0, 870.0, 315.0, 636.0, 315.0, 636.0, 330.0, 615.0, 330.0, 615.0, 348.0, 629.5, 348.0 ],
					"source" : [ "obj-93", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-95", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"source" : [ "obj-97", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 457.5, 993.0, 582.0, 993.0, 582.0, 798.0, 330.0, 798.0, 330.0, 732.0, 354.5, 732.0 ],
					"source" : [ "obj-98", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"disabled" : 0,
					"hidden" : 1,
					"midpoints" : [ 381.25, 855.0, 774.5, 855.0 ],
					"source" : [ "obj-99", 0 ]
				}

			}
 ]
	}

}
