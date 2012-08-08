{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 2.0, 44.0, 293.0, 232.0 ],
		"bglocked" : 0,
		"defrect" : [ 2.0, 44.0, 293.0, 232.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 3",
					"patching_rect" : [ 225.0, 153.0, 50.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-2",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 727.0, 71.0, 640.0, 480.0 ],
						"bglocked" : 0,
						"defrect" : [ 727.0, 71.0, 640.0, 480.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_1 100. 100.",
									"patching_rect" : [ 128.75, 58.0, 234.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new L0 100 100",
									"patching_rect" : [ 140.75, 119.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/dump",
									"patching_rect" : [ 156.75, 154.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete LAYER_0",
									"patching_rect" : [ 164.75, 217.0, 178.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100. 100.",
									"patching_rect" : [ 120.75, 91.0, 234.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 37.0, 331.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/dump",
									"patching_rect" : [ 64.75, 34.0, 124.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p basics",
					"patching_rect" : [ 93.75, 168.0, 55.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-17",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 25.0, 69.0, 283.0, 373.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 283.0, 373.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/",
									"patching_rect" : [ 72.0, 123.0, 44.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw ee",
									"patching_rect" : [ 133.0, 193.0, 73.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/hi",
									"patching_rect" : [ 94.0, 146.0, 68.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/*/pink",
									"patching_rect" : [ 110.0, 171.0, 88.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100 100",
									"patching_rect" : [ 170.0, 242.0, 247.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/sessions/abc",
									"patching_rect" : [ 155.0, 218.0, 128.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/sanity",
									"patching_rect" : [ 50.0, 100.0, 44.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 107.0, 320.0, 25.0, 25.0 ],
									"numinlets" : 1,
									"id" : "obj-16",
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p assets",
					"patching_rect" : [ 12.0, 116.0, 55.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-14",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 3.0, 328.0, 290.0, 275.0 ],
						"bglocked" : 0,
						"defrect" : [ 3.0, 328.0, 290.0, 275.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"visible" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/uncache",
									"patching_rect" : [ 88.0, 191.0, 196.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/meta/description d",
									"patching_rect" : [ 36.0, 34.0, 238.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/dump",
									"patching_rect" : [ 7.0, 9.0, 127.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/cache",
									"patching_rect" : [ 85.0, 160.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov",
									"patching_rect" : [ 79.0, 124.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/meta",
									"patching_rect" : [ 68.0, 97.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov",
									"patching_rect" : [ 50.0, 70.0, 182.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 10.0, 237.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 1",
					"patching_rect" : [ 123.0, 130.0, 50.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-12",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 0.0, 44.0, 411.0, 826.0 ],
						"bglocked" : 0,
						"defrect" : [ 0.0, 44.0, 411.0, 826.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/BUFFER_NAME/stop",
									"patching_rect" : [ 1046.0, 479.333344, 206.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-44",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/BUFFER_NAME/record ALIAS",
									"patching_rect" : [ 1046.0, 457.333344, 252.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-43",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/MY_VIDEO_NAME/cache",
									"patching_rect" : [ 1043.0, 428.333344, 228.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-42",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/stop cam",
									"patching_rect" : [ 1051.0, 587.333374, 143.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/MY_CAM_NAME/start",
									"patching_rect" : [ 1033.0, 404.333344, 210.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-30",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump contents of buffer",
									"patching_rect" : [ 1123.0, 61.0, 138.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-41",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/media/dump",
									"patching_rect" : [ 944.75, 38.0, 125.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-40",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/dump",
									"patching_rect" : [ 954.75, 64.0, 164.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-36",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump",
									"patching_rect" : [ 546.0, 146.0, 43.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-35",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER",
									"patching_rect" : [ 276.75, 174.0, 229.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump contents of asset collection.",
									"patching_rect" : [ 1075.0, 37.0, 193.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Attach it to a asset alias.  The asset can be any named thing.  If the asset is cached, then the player will get the cached version.  Otherwise, it will be offered a disk based version or a connection to a live stream.",
									"linecount" : 9,
									"patching_rect" : [ 784.0, 465.0, 152.0, 131.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-39",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Detach from video source (i.e. stop recording).  Does not turn off the source.",
									"patching_rect" : [ 684.0, 355.0, 415.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-38",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Add ability to record for specified n frames or time.  ASSET_ALIAS must point to a video source.  This can be a grabber, a live stream, a syphon source, or a video player.",
									"linecount" : 4,
									"patching_rect" : [ 688.0, 273.0, 292.0, 62.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-37",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/MY_BUFFER/stop",
									"patching_rect" : [ 451.75, 356.0, 230.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-34",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/MY_BUFFER/record ASSET_ALIAS",
									"patching_rect" : [ 363.75, 277.0, 322.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-33",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"patching_rect" : [ 608.0, 218.0, 234.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-31",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER 60 fixed",
									"patching_rect" : [ 324.75, 221.0, 273.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-32",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"patching_rect" : [ 608.0, 194.0, 234.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-29",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is a live source (grabber, stream, etc), it will stop / close",
									"patching_rect" : [ 517.0, 98.0, 323.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-28",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"patching_rect" : [ 608.0, 170.0, 234.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-27",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is a live source (grabber, stream, etc), it will start",
									"patching_rect" : [ 517.0, 76.0, 286.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-26",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is disk-based, it will uncache",
									"patching_rect" : [ 517.0, 54.0, 181.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-18",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is disk-based, it will cache",
									"patching_rect" : [ 517.0, 32.0, 167.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-17",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/uncache oh.mov",
									"patching_rect" : [ 196.0, 56.333332, 181.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-16",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/stop cam",
									"patching_rect" : [ 257.0, 120.333336, 143.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/start cam",
									"patching_rect" : [ 239.0, 96.333336, 144.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new layer called LAYER_0",
									"patching_rect" : [ 745.0, 438.0, 198.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/delete my_buffer_1",
									"patching_rect" : [ 605.75, 947.0, 202.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-25",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/my_buffer_1/type 3",
									"patching_rect" : [ 605.75, 912.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-24",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer 1 33 type",
									"patching_rect" : [ 605.75, 972.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-23",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1",
									"patching_rect" : [ 605.75, 883.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-22",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER",
									"patching_rect" : [ 298.75, 197.0, 229.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-21",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new my_buffer_1 33 type",
									"patching_rect" : [ 589.75, 818.0, 266.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-20",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer stream_ipcam2",
									"patching_rect" : [ 572.75, 785.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-19",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/alias stream_ipcam2 buttes",
									"patching_rect" : [ 542.75, 748.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer ipcam2",
									"patching_rect" : [ 476.75, 663.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-10",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer buttes",
									"patching_rect" : [ 461.75, 633.0, 283.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-9",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100.",
									"patching_rect" : [ 488.75, 438.0, 254.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0_16076",
									"patching_rect" : [ 605.75, 997.0, 258.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-15",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/mask fingers.mov",
									"patching_rect" : [ 505.75, 466.0, 272.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/cache oh.mov",
									"patching_rect" : [ 172.75, 32.0, 168.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-13",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"patching_rect" : [ 507.75, 721.0, 214.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-59",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 166.0, 510.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 957.0, 101.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-40", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-36", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-59", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-32", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-33", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-34", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p roots",
					"patching_rect" : [ 133.0, 99.0, 47.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-15",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 341.0, 60.0, 944.0, 480.0 ],
						"bglocked" : 0,
						"defrect" : [ 341.0, 60.0, 944.0, 480.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/delete my_buffer_1",
									"patching_rect" : [ 518.75, 403.0, 202.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-25",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/my_buffer_1/type 3",
									"patching_rect" : [ 480.75, 376.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-24",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer 1 33 type",
									"patching_rect" : [ 563.75, 455.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-23",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1",
									"patching_rect" : [ 481.75, 347.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-22",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1 33",
									"patching_rect" : [ 479.75, 321.0, 243.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-21",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new my_buffer_1 33 type",
									"patching_rect" : [ 463.75, 282.0, 266.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-20",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer stream_ipcam2",
									"patching_rect" : [ 446.75, 249.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-19",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/alias stream_ipcam2 buttes",
									"patching_rect" : [ 416.75, 212.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer ipcam2",
									"patching_rect" : [ 350.75, 127.0, 331.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-10",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer buttes",
									"patching_rect" : [ 307.75, 104.0, 283.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-9",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100., /livedraw/canvas/layer/LAYER_0/source/buffer video_fingers.mov",
									"patching_rect" : [ 235.75, 28.0, 597.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/ld/c/l",
									"patching_rect" : [ 131.400009, 340.0, 39.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-18",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/ld/can/lay",
									"patching_rect" : [ 127.400002, 295.0, 65.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-17",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/c/lay",
									"patching_rect" : [ 122.400002, 185.0, 94.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-16",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0_16076",
									"patching_rect" : [ 151.75, 452.0, 258.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-15",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/mask fingers.mov",
									"patching_rect" : [ 366.75, 157.0, 272.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer video_fingers.mov",
									"patching_rect" : [ 283.75, 74.0, 347.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-13",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"patching_rect" : [ 381.75, 185.0, 214.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-59",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100.",
									"patching_rect" : [ 260.75, 52.0, 268.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-29",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 339.0, 411.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer",
									"patching_rect" : [ 116.400002, 153.0, 129.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas",
									"patching_rect" : [ 102.400002, 130.0, 99.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets",
									"patching_rect" : [ 88.400002, 107.0, 96.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/effects",
									"patching_rect" : [ 74.400002, 84.0, 96.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/buffers",
									"patching_rect" : [ 60.400002, 61.0, 98.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/sessions",
									"patching_rect" : [ 46.0, 38.0, 108.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 9.0, 235.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-59", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-18", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 0",
					"patching_rect" : [ 135.0, 73.0, 50.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-11",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 162.0, 102.0, 1278.0, 781.0 ],
						"bglocked" : 0,
						"defrect" : [ 162.0, 102.0, 1278.0, 781.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Scale",
									"patching_rect" : [ 213.0, 587.0, 41.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-16",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Rotation",
									"patching_rect" : [ 209.0, 491.0, 55.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-13",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 156.5, 587.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 44.0, 658.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0.",
									"patching_rect" : [ 44.0, 613.0, 70.0, 20.0 ],
									"numinlets" : 3,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 100.5, 587.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-9",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 44.0, 587.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/scale $1 $2 $3",
									"patching_rect" : [ 44.0, 637.0, 266.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print",
									"patching_rect" : [ 788.0, 594.0, 33.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-63",
									"numoutlets" : 0,
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 826.0, 594.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-52",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "alpha",
									"patching_rect" : [ 1119.0, 528.0, 40.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-53",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "slider",
									"patching_rect" : [ 875.0, 529.0, 241.0, 18.0 ],
									"numinlets" : 1,
									"id" : "obj-54",
									"numoutlets" : 1,
									"size" : 256.0,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0. 0.",
									"patching_rect" : [ 826.0, 550.0, 79.0, 20.0 ],
									"numinlets" : 4,
									"fontname" : "Arial",
									"id" : "obj-61",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "swatch",
									"patching_rect" : [ 860.0, 422.0, 241.0, 98.0 ],
									"numinlets" : 3,
									"compatibility" : 1,
									"id" : "obj-62",
									"numoutlets" : 2,
									"outlettype" : [ "", "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/label $1 $2 $3 $4",
									"patching_rect" : [ 826.0, 573.0, 274.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Lock",
									"patching_rect" : [ 647.0, 470.0, 35.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-48",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"patching_rect" : [ 623.0, 469.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-50",
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/lock $1",
									"patching_rect" : [ 623.0, 492.0, 218.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-51",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Lock",
									"patching_rect" : [ 647.0, 408.0, 35.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-46",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Solo",
									"patching_rect" : [ 416.0, 406.0, 35.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-44",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"patching_rect" : [ 623.0, 407.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-38",
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"patching_rect" : [ 392.0, 406.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-37",
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/lock $1",
									"patching_rect" : [ 623.0, 430.0, 218.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-35",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/solo $1",
									"patching_rect" : [ 392.0, 431.0, 218.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-34",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 392.0, 532.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-33",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/order backward",
									"patching_rect" : [ 350.75, 375.0, 521.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-32",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 155.5, 491.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-31",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 42.0, 466.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-22",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Anchor Point",
									"patching_rect" : [ 158.0, 395.0, 99.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-23",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0.",
									"patching_rect" : [ 42.0, 421.0, 57.0, 20.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-24",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 102.5, 395.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-25",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 42.0, 395.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-26",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/anchorpoint $1 $2",
									"patching_rect" : [ 42.0, 445.0, 281.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-27",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 43.0, 562.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-21",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0.",
									"patching_rect" : [ 43.0, 517.0, 70.0, 20.0 ],
									"numinlets" : 3,
									"fontname" : "Arial",
									"id" : "obj-39",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 99.5, 491.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-40",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 43.0, 491.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-41",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/rotate $1 $2 $3",
									"patching_rect" : [ 43.0, 541.0, 266.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-42",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 40.0, 323.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-15",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Opacity : 0 - 255",
									"patching_rect" : [ 94.0, 322.0, 99.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-10",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"patching_rect" : [ 775.0, 91.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"patching_rect" : [ 343.0, 80.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 40.0, 370.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/opacity $1",
									"patching_rect" : [ 40.0, 346.0, 285.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create and set layers",
									"patching_rect" : [ 41.0, 123.0, 122.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-69",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "delete layers",
									"patching_rect" : [ 652.0, 126.0, 79.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-68",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_4",
									"patching_rect" : [ 734.75, 244.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-55",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_3",
									"patching_rect" : [ 719.75, 221.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-56",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_2",
									"patching_rect" : [ 699.75, 198.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-57",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_1",
									"patching_rect" : [ 676.75, 175.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-58",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"patching_rect" : [ 652.75, 151.0, 214.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-59",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 653.0, 279.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-60",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_4 500 200, /livedraw/canvas/layer/LAYER_4/input rain.mov",
									"patching_rect" : [ 122.75, 239.0, 513.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-49",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_3 400 100, /livedraw/canvas/layer/LAYER_3/input garbage.mov",
									"patching_rect" : [ 107.75, 216.0, 521.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-47",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_2 300 300, /livedraw/canvas/layer/LAYER_2/input track2.mov",
									"patching_rect" : [ 87.75, 193.0, 534.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-45",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_1 200 200, /livedraw/canvas/layer/LAYER_1/input bball.mov",
									"patching_rect" : [ 64.75, 170.0, 528.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-43",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100 100, /livedraw/canvas/layer/LAYER_0/source fingers.mov",
									"patching_rect" : [ 40.75, 146.0, 521.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-29",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 41.0, 277.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-8", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-8", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-61", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-61", 0 ],
									"hidden" : 0,
									"midpoints" : [ 869.5, 526.0, 835.5, 526.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-54", 0 ],
									"destination" : [ "obj-61", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-52", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-51", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-50", 0 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-38", 0 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-37", 0 ],
									"destination" : [ "obj-34", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-34", 0 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-39", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 0 ],
									"destination" : [ "obj-42", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-41", 0 ],
									"destination" : [ "obj-39", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-40", 0 ],
									"destination" : [ "obj-39", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-24", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-42", 0 ],
									"destination" : [ "obj-21", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-55", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-56", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-57", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-58", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-59", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-55", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-56", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-57", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-58", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-59", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-45", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-47", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-49", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-43", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-45", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-47", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-49", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p layer sources",
					"patching_rect" : [ 12.0, 89.0, 93.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-10",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 913.0, 219.0, 475.0, 528.0 ],
						"bglocked" : 0,
						"defrect" : [ 913.0, 219.0, 475.0, 528.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/effects/alphamask/alphamode 11",
									"patching_rect" : [ 99.0, 392.5, 351.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-17",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/effects/curves/lut 22",
									"patching_rect" : [ 98.75, 368.0, 285.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-15",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/input bball.mov",
									"patching_rect" : [ 91.75, 82.0, 259.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-13",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_1/mask",
									"patching_rect" : [ 163.75, 256.0, 209.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_1 100 100",
									"patching_rect" : [ 105.75, 180.0, 247.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-9",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_1",
									"patching_rect" : [ 118.75, 202.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-10",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_1/input bball.mov",
									"patching_rect" : [ 147.75, 230.0, 259.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/mask Big-Clean-Messy.jpg",
									"patching_rect" : [ 106.75, 103.0, 319.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100 100",
									"patching_rect" : [ 31.75, 9.0, 247.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"patching_rect" : [ 43.75, 32.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 2.0, 419.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/input fingers.mov",
									"patching_rect" : [ 73.75, 59.0, 270.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p transforms",
					"patching_rect" : [ 12.0, 63.0, 100.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-9",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 21.0, 586.0, 488.0, 258.0 ],
						"bglocked" : 0,
						"defrect" : [ 21.0, 586.0, 488.0, 258.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"visible" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p size",
									"patching_rect" : [ 47.0, 115.0, 61.0, 20.0 ],
									"numinlets" : 0,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"presentation_rect" : [ 47.0, 115.0, 0.0, 0.0 ],
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 940.0, 321.0, 500.0, 489.0 ],
										"bglocked" : 0,
										"defrect" : [ 940.0, 321.0, 500.0, 489.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0.",
													"patching_rect" : [ 232.0, 78.0, 57.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-5",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0,
													"presentation_rect" : [ 298.0, 187.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 292.5, 52.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-6",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0,
													"presentation_rect" : [ 358.5, 161.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 228.0, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-9",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0,
													"presentation_rect" : [ 294.0, 158.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/sz $1 $2",
													"patching_rect" : [ 232.0, 102.0, 192.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-10",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187,
													"presentation_rect" : [ 298.0, 211.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 122.0, 354.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-1",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0,
													"presentation_rect" : [ 188.0, 463.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/height $1",
													"patching_rect" : [ 122.0, 377.0, 197.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-2",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187,
													"presentation_rect" : [ 188.0, 486.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 122.0, 308.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-3",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0,
													"presentation_rect" : [ 188.0, 417.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/width $1",
													"patching_rect" : [ 122.0, 331.0, 182.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-4",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187,
													"presentation_rect" : [ 188.0, 440.0, 0.0, 0.0 ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 75.0, 244.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-29",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/height $1",
													"patching_rect" : [ 75.0, 267.0, 197.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-30",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 75.0, 198.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-27",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/width $1",
													"patching_rect" : [ 75.0, 221.0, 182.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-28",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0.",
													"patching_rect" : [ 75.0, 140.0, 57.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-16",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 135.5, 114.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-15",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 71.0, 111.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-13",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"patching_rect" : [ 8.0, 351.0, 39.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-8",
													"numoutlets" : 0,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/size $1 $2",
													"patching_rect" : [ 75.0, 164.0, 192.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-7",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-5", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-5", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-4", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-15", 0 ],
													"destination" : [ "obj-16", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-13", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-27", 0 ],
													"destination" : [ "obj-28", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-29", 0 ],
													"destination" : [ "obj-30", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-30", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0,
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"patching_rect" : [ 50.0, 138.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 2,
									"outlettype" : [ "float", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 51.0, 188.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/transform/opacity $1",
									"patching_rect" : [ 51.0, 164.0, 286.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p anchorpoint",
									"patching_rect" : [ 48.0, 9.0, 81.0, 20.0 ],
									"numinlets" : 0,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 557.0, 133.0, 503.0, 588.0 ],
										"bglocked" : 0,
										"defrect" : [ 557.0, 133.0, 503.0, 588.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 229.5, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-43",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"patching_rect" : [ 109.0, 470.0, 60.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-44",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-45",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-46",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2 $3",
													"patching_rect" : [ 109.0, 495.0, 275.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-47",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0",
													"patching_rect" : [ 109.0, 393.0, 50.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-39",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 367.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-40",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 367.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-41",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2",
													"patching_rect" : [ 109.0, 417.0, 238.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-42",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 316.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-36",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1",
													"patching_rect" : [ 109.0, 343.0, 222.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-37",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 226.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-31",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint Z $1",
													"patching_rect" : [ 109.0, 249.0, 233.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-32",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 179.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-29",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint Y $1",
													"patching_rect" : [ 109.0, 202.0, 233.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-30",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 133.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-27",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint X $1",
													"patching_rect" : [ 109.0, 156.0, 233.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-28",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 229.5, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-23",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"patching_rect" : [ 109.0, 75.0, 60.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-16",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-15",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-13",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"patching_rect" : [ 42.0, 286.0, 39.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-8",
													"numoutlets" : 0,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2 $3",
													"patching_rect" : [ 109.0, 99.0, 275.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-7",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-39", 0 ],
													"destination" : [ "obj-42", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-41", 0 ],
													"destination" : [ "obj-39", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-40", 0 ],
													"destination" : [ "obj-39", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-37", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-47", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-42", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-44", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-46", 0 ],
													"destination" : [ "obj-44", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-45", 0 ],
													"destination" : [ "obj-44", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 0 ],
													"destination" : [ "obj-44", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-32", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-31", 0 ],
													"destination" : [ "obj-32", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-30", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-29", 0 ],
													"destination" : [ "obj-30", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-27", 0 ],
													"destination" : [ "obj-28", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-23", 0 ],
													"destination" : [ "obj-16", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-15", 0 ],
													"destination" : [ "obj-16", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-13", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0,
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p rotation",
									"patching_rect" : [ 47.0, 90.0, 61.0, 20.0 ],
									"numinlets" : 0,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 961.0, 86.0, 680.0, 724.0 ],
										"bglocked" : 0,
										"defrect" : [ 961.0, 86.0, 680.0, 724.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate",
													"patching_rect" : [ 100.0, 171.0, 189.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-11",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b l",
													"patching_rect" : [ 85.0, 72.0, 32.5, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-10",
													"numoutlets" : 2,
													"outlettype" : [ "bang", "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"patching_rect" : [ 79.0, 23.0, 20.0, 20.0 ],
													"numinlets" : 1,
													"id" : "obj-9",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"patching_rect" : [ 60.0, 156.0, 20.0, 20.0 ],
													"numinlets" : 1,
													"id" : "obj-6",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/layers/%s/xform/rotate %s",
													"patching_rect" : [ 163.0, 133.0, 293.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-4",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER_0",
													"patching_rect" : [ 58.0, 107.0, 96.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-3",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "umenu",
													"types" : [  ],
													"patching_rect" : [ 60.0, 48.0, 100.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-1",
													"numoutlets" : 3,
													"outlettype" : [ "int", "", "" ],
													"fontsize" : 12.0,
													"items" : [ "LAYER_0", ",", "LAYER_1", ",", "LAYER_2", ",", "LAYER_3", ",", "LAYER_4", ",", "LAYER_5", ",", "LAYER_6", ",", "LAYER_7", ",", "LAYER_8", ",", "LAYER_9" ]
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 261.5, 618.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-43",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0. 0.",
													"patching_rect" : [ 141.0, 644.0, 70.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-44",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 201.5, 618.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-45",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 618.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-46",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1 $2 $3",
													"patching_rect" : [ 141.0, 668.0, 217.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-47",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0.",
													"patching_rect" : [ 141.0, 567.0, 57.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-39",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 201.5, 541.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-40",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 541.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-41",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1 $2",
													"patching_rect" : [ 141.0, 591.0, 201.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-42",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 490.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-36",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1",
													"patching_rect" : [ 141.0, 517.0, 185.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-37",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 400.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-31",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate Z $1",
													"patching_rect" : [ 141.0, 423.0, 195.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-32",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 353.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-29",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate Y $1",
													"patching_rect" : [ 141.0, 376.0, 195.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-30",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 141.0, 307.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-27",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate X $1",
													"patching_rect" : [ 141.0, 330.0, 196.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-28",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 261.5, 223.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-23",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0. 0.",
													"patching_rect" : [ 141.0, 249.0, 70.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-16",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 201.5, 223.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-15",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 137.0, 220.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-13",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"patching_rect" : [ 74.0, 460.0, 39.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-8",
													"numoutlets" : 0,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate DEGREES $1 $2 $3",
													"patching_rect" : [ 141.0, 273.0, 277.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-7",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 1 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 1 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-30", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-32", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-42", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-47", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-13", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-15", 0 ],
													"destination" : [ "obj-16", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-23", 0 ],
													"destination" : [ "obj-16", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-29", 0 ],
													"destination" : [ "obj-30", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-27", 0 ],
													"destination" : [ "obj-28", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-31", 0 ],
													"destination" : [ "obj-32", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-37", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 0 ],
													"destination" : [ "obj-44", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-45", 0 ],
													"destination" : [ "obj-44", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-46", 0 ],
													"destination" : [ "obj-44", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-44", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-39", 0 ],
													"destination" : [ "obj-42", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-41", 0 ],
													"destination" : [ "obj-39", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-40", 0 ],
													"destination" : [ "obj-39", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 0 ],
													"destination" : [ "obj-11", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-4", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0,
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p position",
									"patching_rect" : [ 47.0, 34.0, 62.0, 20.0 ],
									"numinlets" : 0,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 937.0, 264.0, 503.0, 588.0 ],
										"bglocked" : 0,
										"defrect" : [ 937.0, 264.0, 503.0, 588.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 229.5, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-43",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"patching_rect" : [ 109.0, 470.0, 60.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-44",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-45",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 444.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-46",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1 $2 $3",
													"patching_rect" : [ 109.0, 494.0, 322.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-47",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0",
													"patching_rect" : [ 109.0, 393.0, 50.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-39",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 367.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-40",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 367.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-41",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1 $2",
													"patching_rect" : [ 109.0, 417.0, 271.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-42",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 316.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-36",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1",
													"patching_rect" : [ 109.0, 343.0, 255.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-37",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 226.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-31",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position Z $1",
													"patching_rect" : [ 109.0, 249.0, 265.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-32",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 179.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-29",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position Y $1",
													"patching_rect" : [ 109.0, 202.0, 266.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-30",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 133.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-27",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position X $1",
													"patching_rect" : [ 109.0, 156.0, 266.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-28",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 229.5, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-23",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"patching_rect" : [ 109.0, 75.0, 60.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-16",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 169.5, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-15",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"patching_rect" : [ 109.0, 49.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-13",
													"numoutlets" : 2,
													"outlettype" : [ "int", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"patching_rect" : [ 42.0, 286.0, 39.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-8",
													"numoutlets" : 0,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_0/t/p $1 $2 $3",
													"patching_rect" : [ 109.0, 99.0, 140.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-7",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-13", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-15", 0 ],
													"destination" : [ "obj-16", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-23", 0 ],
													"destination" : [ "obj-16", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-27", 0 ],
													"destination" : [ "obj-28", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-29", 0 ],
													"destination" : [ "obj-30", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-30", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-31", 0 ],
													"destination" : [ "obj-32", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-32", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 0 ],
													"destination" : [ "obj-44", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-45", 0 ],
													"destination" : [ "obj-44", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-46", 0 ],
													"destination" : [ "obj-44", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-44", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-42", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-47", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-37", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-40", 0 ],
													"destination" : [ "obj-39", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-41", 0 ],
													"destination" : [ "obj-39", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-39", 0 ],
													"destination" : [ "obj-42", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0,
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p scale",
									"patching_rect" : [ 48.0, 61.0, 49.0, 20.0 ],
									"numinlets" : 0,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 939.0, 145.0, 501.0, 521.0 ],
										"bglocked" : 0,
										"defrect" : [ 939.0, 145.0, 501.0, 521.0 ],
										"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
										"openinpresentation" : 0,
										"default_fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"gridonopen" : 0,
										"gridsize" : [ 15.0, 15.0 ],
										"gridsnaponopen" : 0,
										"toolbarvisible" : 1,
										"boxanimatetime" : 200,
										"imprint" : 0,
										"enablehscroll" : 1,
										"enablevscroll" : 1,
										"devicewidth" : 0.0,
										"boxes" : [ 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 217.5, 425.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-48",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1. 1.",
													"patching_rect" : [ 97.0, 451.0, 68.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-49",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 157.5, 425.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-50",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 425.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-51",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2 $3",
													"patching_rect" : [ 97.0, 475.0, 215.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-52",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1.",
													"patching_rect" : [ 97.0, 374.0, 57.0, 20.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-53",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 157.5, 348.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-54",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 348.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-55",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2",
													"patching_rect" : [ 97.0, 398.0, 198.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-56",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 297.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-57",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1",
													"patching_rect" : [ 97.0, 324.0, 182.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-58",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 207.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-59",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale Z $1",
													"patching_rect" : [ 97.0, 230.0, 193.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-60",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 160.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-61",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale Y $1",
													"patching_rect" : [ 97.0, 183.0, 193.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-62",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 114.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-63",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale X $1",
													"patching_rect" : [ 97.0, 137.0, 193.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-64",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 217.5, 30.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-65",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1. 1.",
													"patching_rect" : [ 97.0, 56.0, 70.0, 20.0 ],
													"numinlets" : 3,
													"fontname" : "Arial",
													"id" : "obj-66",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 157.5, 30.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-67",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"patching_rect" : [ 97.0, 30.0, 50.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-68",
													"numoutlets" : 2,
													"outlettype" : [ "float", "bang" ],
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"patching_rect" : [ 30.0, 267.0, 39.0, 20.0 ],
													"numinlets" : 1,
													"fontname" : "Arial",
													"id" : "obj-69",
													"numoutlets" : 0,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2 $3",
													"patching_rect" : [ 97.0, 80.0, 215.0, 18.0 ],
													"numinlets" : 2,
													"fontname" : "Arial",
													"id" : "obj-70",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"fontsize" : 11.595187
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-51", 0 ],
													"destination" : [ "obj-49", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-50", 0 ],
													"destination" : [ "obj-49", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-48", 0 ],
													"destination" : [ "obj-49", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-49", 0 ],
													"destination" : [ "obj-52", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-55", 0 ],
													"destination" : [ "obj-53", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-54", 0 ],
													"destination" : [ "obj-53", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-53", 0 ],
													"destination" : [ "obj-56", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-66", 0 ],
													"destination" : [ "obj-70", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-68", 0 ],
													"destination" : [ "obj-66", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-67", 0 ],
													"destination" : [ "obj-66", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-65", 0 ],
													"destination" : [ "obj-66", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-57", 0 ],
													"destination" : [ "obj-58", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-59", 0 ],
													"destination" : [ "obj-60", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-61", 0 ],
													"destination" : [ "obj-62", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-63", 0 ],
													"destination" : [ "obj-64", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-70", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-64", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-62", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-60", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-58", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-56", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-52", 0 ],
													"destination" : [ "obj-69", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0,
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0
									}

								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "// general canvas/layer",
					"patching_rect" : [ 109.0, 35.0, 150.0, 20.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"id" : "obj-31",
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p canvas/layer",
					"patching_rect" : [ 12.0, 37.0, 88.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-32",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 675.0, 44.0, 644.0, 539.0 ],
						"bglocked" : 0,
						"defrect" : [ 675.0, 44.0, 644.0, 539.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 0 100",
									"patching_rect" : [ 72.75, 48.0, 200.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete LAYER_0_6548",
									"patching_rect" : [ 105.75, 196.0, 211.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100 100 -10",
									"patching_rect" : [ 105.75, 161.0, 233.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100 200 -10",
									"patching_rect" : [ 105.75, 132.0, 233.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-2",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete LAYER_0",
									"patching_rect" : [ 105.75, 100.0, 178.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-1",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100 100",
									"patching_rect" : [ 105.75, 76.0, 213.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-3",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 21.0, 243.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/dump",
									"patching_rect" : [ 49.75, 19.0, 124.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "// general canvas controls",
					"patching_rect" : [ 109.0, 10.0, 150.0, 20.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"id" : "obj-30",
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p canvas",
					"patching_rect" : [ 12.0, 12.0, 59.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-26",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 417.0, 241.0, 678.0, 525.0 ],
						"bglocked" : 0,
						"defrect" : [ 417.0, 241.0, 678.0, 525.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "number",
									"patching_rect" : [ 39.0, 423.0, 50.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-31",
									"numoutlets" : 2,
									"outlettype" : [ "int", "bang" ],
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "FPS",
									"patching_rect" : [ 91.0, 423.0, 34.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-17",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/fps $1",
									"patching_rect" : [ 39.0, 448.0, 131.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-26",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 39.0, 477.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-28",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "MSAA",
									"patching_rect" : [ 345.0, 116.0, 45.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-16",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Fullscreen",
									"patching_rect" : [ 345.0, 28.0, 66.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-7",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Size",
									"patching_rect" : [ 82.0, 23.0, 34.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-6",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Position",
									"patching_rect" : [ 82.0, 227.0, 53.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-5",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 322.0, 391.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-38",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "alpha",
									"patching_rect" : [ 615.0, 325.0, 40.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-37",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "slider",
									"patching_rect" : [ 371.0, 326.0, 241.0, 18.0 ],
									"numinlets" : 1,
									"id" : "obj-29",
									"numoutlets" : 1,
									"size" : 256.0,
									"outlettype" : [ "" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0 0 0 0",
									"patching_rect" : [ 322.0, 347.0, 68.0, 20.0 ],
									"numinlets" : 4,
									"fontname" : "Arial",
									"id" : "obj-27",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "swatch",
									"patching_rect" : [ 356.0, 219.0, 241.0, 98.0 ],
									"numinlets" : 3,
									"compatibility" : 1,
									"id" : "obj-35",
									"numoutlets" : 2,
									"outlettype" : [ "", "float" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/background $1 $2 $3 $4",
									"patching_rect" : [ 322.0, 370.0, 225.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-4",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"patching_rect" : [ 322.0, 117.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-9",
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/msaa $1",
									"patching_rect" : [ 322.0, 141.0, 144.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-13",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 322.0, 170.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-15",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 100.5 100.54",
									"patching_rect" : [ 82.0, 252.0, 217.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-8",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"patching_rect" : [ 322.0, 29.0, 20.0, 20.0 ],
									"numinlets" : 1,
									"id" : "obj-25",
									"numoutlets" : 1,
									"outlettype" : [ "int" ]
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/fullscreen $1",
									"patching_rect" : [ 322.0, 53.0, 165.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-23",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 322.0, 82.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-22",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 35.0, 358.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-18",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 400 400",
									"patching_rect" : [ 82.0, 324.0, 185.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-19",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 100 100",
									"patching_rect" : [ 82.0, 276.0, 202.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-20",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 200 200",
									"patching_rect" : [ 82.0, 300.0, 185.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-21",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"patching_rect" : [ 35.0, 127.0, 39.0, 20.0 ],
									"numinlets" : 1,
									"fontname" : "Arial",
									"id" : "obj-14",
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 3072 768",
									"patching_rect" : [ 82.0, 93.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-12",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 1024 768",
									"patching_rect" : [ 82.0, 47.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-11",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 2048 768",
									"patching_rect" : [ 82.0, 70.0, 172.0, 18.0 ],
									"numinlets" : 2,
									"fontname" : "Arial",
									"id" : "obj-10",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"fontsize" : 11.595187
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-38", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [ 365.5, 323.0, 331.5, 323.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-27", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-18", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r osc",
					"patching_rect" : [ 26.0, 147.0, 37.0, 20.0 ],
					"numinlets" : 0,
					"fontname" : "Arial",
					"id" : "obj-13",
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "udpsend 127.0.0.1 5433",
					"patching_rect" : [ 76.0, 198.0, 140.0, 20.0 ],
					"numinlets" : 1,
					"fontname" : "Arial",
					"id" : "obj-1",
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
