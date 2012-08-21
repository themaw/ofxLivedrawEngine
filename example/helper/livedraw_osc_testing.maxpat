{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 5,
			"minor" : 1,
			"revision" : 9
		}
,
		"rect" : [ 19.0, 564.0, 241.0, 270.0 ],
		"bglocked" : 0,
		"defrect" : [ 19.0, 564.0, 241.0, 270.0 ],
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
					"text" : "p testing",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 184.0, 170.0, 56.0, 20.0 ],
					"id" : "obj-3",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 118.0, 460.0, 1402.0, 713.0 ],
						"bglocked" : 0,
						"defrect" : [ 118.0, 460.0, 1402.0, 713.0 ],
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
									"text" : "cam",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 1023.0, 79.0, 0.0, 0.0 ],
									"patching_rect" : [ 1023.0, 79.0, 33.0, 18.0 ],
									"id" : "obj-103",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/xform/size 80 60",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 1037.75, 360.0, 0.0, 0.0 ],
									"patching_rect" : [ 1037.75, 360.0, 186.0, 18.0 ],
									"id" : "obj-72",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/xform/opacity 255",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 1007.75, 332.0, 0.0, 0.0 ],
									"patching_rect" : [ 1007.75, 332.0, 194.0, 18.0 ],
									"id" : "obj-73",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"presentation_rect" : [ 1179.0, 157.0, 0.0, 0.0 ],
									"patching_rect" : [ 1179.0, 157.0, 39.0, 20.0 ],
									"id" : "obj-81",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 1173.75, 136.0, 0.0, 0.0 ],
									"patching_rect" : [ 1173.75, 136.0, 141.0, 18.0 ],
									"id" : "obj-82",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "destroy",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"presentation_rect" : [ 1192.0, 60.0, 0.0, 0.0 ],
									"patching_rect" : [ 1192.0, 60.0, 50.0, 20.0 ],
									"id" : "obj-83",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"presentation_rect" : [ 1170.0, 61.0, 0.0, 0.0 ],
									"patching_rect" : [ 1170.0, 61.0, 20.0, 20.0 ],
									"id" : "obj-84",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 1174.0, 112.0, 0.0, 0.0 ],
									"patching_rect" : [ 1174.0, 112.0, 83.0, 20.0 ],
									"id" : "obj-85",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "$1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 948.75, 165.0, 0.0, 0.0 ],
									"patching_rect" : [ 948.75, 165.0, 32.5, 18.0 ],
									"id" : "obj-86",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l l b",
									"numoutlets" : 3,
									"fontsize" : 12.0,
									"outlettype" : [ "", "", "bang" ],
									"presentation_rect" : [ 934.0, 114.0, 0.0, 0.0 ],
									"patching_rect" : [ 934.0, 114.0, 46.0, 20.0 ],
									"id" : "obj-87",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /livedraw/layers/%s/input sink %s",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 919.0, 287.0, 0.0, 0.0 ],
									"patching_rect" : [ 919.0, 287.0, 223.0, 20.0 ],
									"id" : "obj-88",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"presentation_rect" : [ 962.0, -19.0, 0.0, 0.0 ],
									"patching_rect" : [ 962.0, -19.0, 60.0, 20.0 ],
									"id" : "obj-89",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "LAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 942.0, 9.0, 0.0, 0.0 ],
									"patching_rect" : [ 942.0, 9.0, 57.0, 18.0 ],
									"id" : "obj-90",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"presentation_rect" : [ 1012.0, 5.0, 0.0, 0.0 ],
									"patching_rect" : [ 1012.0, 5.0, 60.0, 20.0 ],
									"id" : "obj-91",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "ipcam0",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 992.0, 33.0, 0.0, 0.0 ],
									"patching_rect" : [ 992.0, 33.0, 49.0, 18.0 ],
									"id" : "obj-92",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"presentation_rect" : [ 917.0, 10.0, 0.0, 0.0 ],
									"patching_rect" : [ 917.0, 10.0, 44.0, 20.0 ],
									"id" : "obj-93",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"presentation_rect" : [ 895.0, 11.0, 0.0, 0.0 ],
									"patching_rect" : [ 895.0, 11.0, 20.0, 20.0 ],
									"id" : "obj-94",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 911.0, 69.0, 0.0, 0.0 ],
									"patching_rect" : [ 911.0, 69.0, 83.0, 20.0 ],
									"id" : "obj-95",
									"fontname" : "Arial",
									"numinlets" : 4,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 491.0, 407.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 491.0, 407.0 ],
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
													"text" : "pack s s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 168.0, 319.0, 55.0, 20.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 256.0, 38.0, 25.0, 25.0 ],
													"id" : "obj-5",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b b i i",
													"numoutlets" : 4,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int", "int" ],
													"patching_rect" : [ 92.0, 157.0, 59.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 93.0, 187.0, 50.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 169.0, 346.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-6", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 2 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"presentation_rect" : [ 969.0, 364.0, 0.0, 0.0 ],
									"patching_rect" : [ 969.0, 364.0, 39.0, 20.0 ],
									"id" : "obj-96",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack s 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 983.0, 224.0, 0.0, 0.0 ],
									"patching_rect" : [ 983.0, 224.0, 72.0, 20.0 ],
									"id" : "obj-97",
									"fontname" : "Arial",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b b",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "bang" ],
									"presentation_rect" : [ 1056.0, 150.0, 0.0, 0.0 ],
									"patching_rect" : [ 1056.0, 150.0, 34.0, 20.0 ],
									"id" : "obj-98",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"presentation_rect" : [ 1053.0, 125.0, 0.0, 0.0 ],
									"patching_rect" : [ 1053.0, 125.0, 20.0, 20.0 ],
									"id" : "obj-99",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 768",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"presentation_rect" : [ 1098.0, 182.0, 0.0, 0.0 ],
									"patching_rect" : [ 1098.0, 182.0, 75.0, 20.0 ],
									"id" : "obj-100",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 1024",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"presentation_rect" : [ 1015.0, 182.0, 0.0, 0.0 ],
									"patching_rect" : [ 1015.0, 182.0, 81.0, 20.0 ],
									"id" : "obj-101",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new $1 $2 $3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"presentation_rect" : [ 989.75, 257.0, 0.0, 0.0 ],
									"patching_rect" : [ 989.75, 257.0, 163.0, 18.0 ],
									"id" : "obj-102",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/m/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 461.75, 544.0, 123.0, 18.0 ],
									"id" : "obj-71",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 424.75, 574.0, 123.0, 18.0 ],
									"id" : "obj-70",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 610.0, 611.0, 39.0, 20.0 ],
									"id" : "obj-63",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /l/l/%s/dump",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.0, 556.0, 112.0, 20.0 ],
									"id" : "obj-64",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 705.0, 473.0, 60.0, 20.0 ],
									"id" : "obj-65",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 607.0, 529.0, 83.0, 20.0 ],
									"id" : "obj-66",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"patching_rect" : [ 651.0, 473.0, 50.0, 20.0 ],
									"id" : "obj-67",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "LAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 676.0, 501.0, 49.0, 18.0 ],
									"id" : "obj-68",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 595.0, 423.0, 20.0, 20.0 ],
									"id" : "obj-69",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/m/oh.mov/cache",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 128.75, 470.0, 149.0, 18.0 ],
									"id" : "obj-62",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/xform/size 80 60",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 543.75, 355.0, 186.0, 18.0 ],
									"id" : "obj-61",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/m/*/start",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 98.75, 403.0, 103.0, 18.0 ],
									"id" : "obj-60",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/xform/opacity 127",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 513.75, 327.0, 194.0, 18.0 ],
									"id" : "obj-59",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 415.0, 526.0, 39.0, 20.0 ],
									"id" : "obj-58",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /l/m/%s/dump",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 410.0, 471.0, 155.0, 20.0 ],
									"id" : "obj-57",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 510.0, 388.0, 60.0, 20.0 ],
									"id" : "obj-52",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 412.0, 444.0, 83.0, 20.0 ],
									"id" : "obj-53",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "PLAYER",
													"linecount" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 32.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"patching_rect" : [ 456.0, 388.0, 50.0, 20.0 ],
									"id" : "obj-54",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "PLAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 481.0, 416.0, 65.0, 18.0 ],
									"id" : "obj-55",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 400.0, 338.0, 20.0, 20.0 ],
									"id" : "obj-56",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 1.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 217.0, 293.0, 65.0, 20.0 ],
									"id" : "obj-51",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t s b",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "", "bang" ],
									"patching_rect" : [ 162.0, 273.0, 33.0, 20.0 ],
									"id" : "obj-46",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /l/m/%s/framen %f",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 69.0, 333.0, 144.0, 20.0 ],
									"id" : "obj-45",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 685.0, 152.0, 39.0, 20.0 ],
									"id" : "obj-43",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 679.75, 131.0, 141.0, 18.0 ],
									"id" : "obj-42",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "destroy",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 698.0, 55.0, 50.0, 20.0 ],
									"id" : "obj-40",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 676.0, 56.0, 20.0, 20.0 ],
									"id" : "obj-41",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 680.0, 107.0, 83.0, 20.0 ],
									"id" : "obj-39",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "$1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 454.75, 160.0, 32.5, 18.0 ],
									"id" : "obj-38",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t l l b",
									"numoutlets" : 3,
									"fontsize" : 12.0,
									"outlettype" : [ "", "", "bang" ],
									"patching_rect" : [ 440.0, 109.0, 46.0, 20.0 ],
									"id" : "obj-36",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /livedraw/layers/%s/input sink %s",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 425.0, 282.0, 223.0, 20.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 468.0, -24.0, 60.0, 20.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "LAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 448.0, 4.0, 57.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 518.0, 0.0, 60.0, 20.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "PLAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 498.0, 28.0, 65.0, 18.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 423.0, 5.0, 44.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 401.0, 6.0, 20.0, 20.0 ],
									"id" : "obj-16",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 417.0, 64.0, 83.0, 20.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 4,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 491.0, 407.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 491.0, 407.0 ],
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
													"text" : "pack s s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 168.0, 319.0, 55.0, 20.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "PLAYER",
													"linecount" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 229.0, 185.0, 50.0, 32.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 238.0, 225.0, 87.0, 20.0 ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 256.0, 38.0, 25.0, 25.0 ],
													"id" : "obj-5",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b b i i",
													"numoutlets" : 4,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int", "int" ],
													"patching_rect" : [ 92.0, 157.0, 59.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 93.0, 187.0, 50.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 169.0, 346.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-12", 2 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 3 ],
													"destination" : [ "obj-4", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 0 ],
													"destination" : [ "obj-6", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
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
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 475.0, 359.0, 39.0, 20.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack s 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 489.0, 219.0, 72.0, 20.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t b b",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "bang", "bang" ],
									"patching_rect" : [ 562.0, 145.0, 34.0, 20.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 559.0, 120.0, 20.0, 20.0 ],
									"id" : "obj-4",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 768",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 604.0, 177.0, 75.0, 20.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "random 1024",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 521.0, 177.0, 81.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new $1 $2 $3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 495.75, 252.0, 163.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 149.0, 9.0, 60.0, 20.0 ],
									"id" : "obj-37",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadmess 10",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 175.0, -53.0, 86.0, 20.0 ],
									"id" : "obj-35",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "destroy",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 80.0, -16.0, 50.0, 20.0 ],
									"id" : "obj-34",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 61.0, -42.0, 44.0, 20.0 ],
									"id" : "obj-33",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 110.0, 147.0, 39.0, 20.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/delete $1",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 112.0, 128.0, 147.0, 18.0 ],
									"id" : "obj-30",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 57.0, -15.0, 20.0, 20.0 ],
									"id" : "obj-28",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 67.0, 95.0, 83.0, 20.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "PLAYER",
													"linecount" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 32.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /l/m/%s/start",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 21.0, 270.0, 113.0, 20.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sprintf /l/m/%s/load oh.mov",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 58.0, 215.0, 210.0, 20.0 ],
									"id" : "obj-25",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t s s s",
									"numoutlets" : 3,
									"fontsize" : 12.0,
									"outlettype" : [ "", "", "" ],
									"patching_rect" : [ 51.0, 135.0, 46.0, 20.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p seq_builder",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 51.0, 65.0, 83.0, 20.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 3,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 50.0, 94.0, 255.0, 380.0 ],
										"bglocked" : 0,
										"defrect" : [ 50.0, 94.0, 255.0, 380.0 ],
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
													"text" : "t b i",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "int" ],
													"patching_rect" : [ 92.0, 157.0, 32.5, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "PLAYER",
													"linecount" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 89.0, 187.0, 50.0, 32.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 92.0, 133.0, 32.5, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf %s_%s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 102.0, 227.0, 87.0, 20.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 9",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 50.0, 100.0, 46.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-18",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 77.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-19",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "inlet",
													"numoutlets" : 1,
													"outlettype" : [ "" ],
													"patching_rect" : [ 120.0, 40.0, 25.0, 25.0 ],
													"id" : "obj-20",
													"numinlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"numoutlets" : 0,
													"patching_rect" : [ 102.0, 307.0, 25.0, 25.0 ],
													"id" : "obj-21",
													"numinlets" : 1,
													"comment" : ""
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-21", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-10", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-19", 0 ],
													"destination" : [ "obj-1", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-18", 0 ],
													"destination" : [ "obj-1", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-12", 1 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 2 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 23.0, 364.0, 39.0, 20.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"patching_rect" : [ 95.0, 9.0, 50.0, 20.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "PLAYER",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 120.0, 37.0, 65.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 39.0, -41.0, 20.0, 20.0 ],
									"id" : "obj-6",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/new player $1",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 101.0, 180.0, 172.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-103", 0 ],
									"destination" : [ "obj-95", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-99", 0 ],
									"destination" : [ "obj-98", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-98", 1 ],
									"destination" : [ "obj-100", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-98", 0 ],
									"destination" : [ "obj-101", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-100", 0 ],
									"destination" : [ "obj-97", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-101", 0 ],
									"destination" : [ "obj-97", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-97", 0 ],
									"destination" : [ "obj-102", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-94", 0 ],
									"destination" : [ "obj-95", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-91", 0 ],
									"destination" : [ "obj-92", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-92", 0 ],
									"destination" : [ "obj-95", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-89", 0 ],
									"destination" : [ "obj-90", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-90", 0 ],
									"destination" : [ "obj-95", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-95", 0 ],
									"destination" : [ "obj-87", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-87", 1 ],
									"destination" : [ "obj-86", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-86", 0 ],
									"destination" : [ "obj-97", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-87", 2 ],
									"destination" : [ "obj-99", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-87", 0 ],
									"destination" : [ "obj-88", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-102", 0 ],
									"destination" : [ "obj-96", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-88", 0 ],
									"destination" : [ "obj-96", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-84", 0 ],
									"destination" : [ "obj-85", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-82", 0 ],
									"destination" : [ "obj-81", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-85", 0 ],
									"destination" : [ "obj-82", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-90", 0 ],
									"destination" : [ "obj-85", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-73", 0 ],
									"destination" : [ "obj-96", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-72", 0 ],
									"destination" : [ "obj-96", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 1 ],
									"destination" : [ "obj-25", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-71", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-70", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-64", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-66", 0 ],
									"destination" : [ "obj-64", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-54", 0 ],
									"destination" : [ "obj-67", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-68", 0 ],
									"destination" : [ "obj-66", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-66", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-69", 0 ],
									"destination" : [ "obj-66", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-65", 0 ],
									"destination" : [ "obj-68", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-61", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 0 ],
									"destination" : [ "obj-17", 0 ],
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
									"source" : [ "obj-46", 1 ],
									"destination" : [ "obj-51", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-51", 0 ],
									"destination" : [ "obj-45", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-46", 0 ],
									"destination" : [ "obj-45", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-57", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-57", 0 ],
									"destination" : [ "obj-58", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-52", 0 ],
									"destination" : [ "obj-55", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-56", 0 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-54", 0 ],
									"destination" : [ "obj-53", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-55", 0 ],
									"destination" : [ "obj-53", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-46", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
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
									"source" : [ "obj-42", 0 ],
									"destination" : [ "obj-43", 0 ],
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
									"source" : [ "obj-29", 0 ],
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
									"source" : [ "obj-36", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-36", 2 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-38", 0 ],
									"destination" : [ "obj-10", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-36", 1 ],
									"destination" : [ "obj-38", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-36", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-13", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-13", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-19", 0 ],
									"destination" : [ "obj-20", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-13", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-10", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-10", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-22", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-22", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-24", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 2 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-17", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-27", 2 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-27", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-30", 0 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-37", 0 ],
									"destination" : [ "obj-11", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-39", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-15", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-13", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-54", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 3",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 9.0, 192.0, 50.0, 20.0 ],
					"id" : "obj-2",
					"fontname" : "Arial",
					"numinlets" : 0,
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
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 128.75, 58.0, 234.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new L0 100 100",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 140.75, 119.0, 213.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 156.75, 154.0, 213.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 164.75, 217.0, 178.0, 18.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100. 100.",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 120.75, 91.0, 234.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 37.0, 331.0, 39.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 64.75, 34.0, 124.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
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
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p basics",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 93.75, 168.0, 55.0, 20.0 ],
					"id" : "obj-17",
					"fontname" : "Arial",
					"numinlets" : 0,
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
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 72.0, 123.0, 44.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw ee",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 133.0, 193.0, 73.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/hi",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 94.0, 146.0, 68.0, 18.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/*/pink",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 110.0, 171.0, 88.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100 100",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 170.0, 242.0, 247.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/sessions/abc",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 155.0, 218.0, 128.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/sanity",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 100.0, 44.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"numoutlets" : 0,
									"patching_rect" : [ 107.0, 320.0, 25.0, 25.0 ],
									"id" : "obj-16",
									"numinlets" : 1,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-4", 0 ],
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
									"source" : [ "obj-6", 0 ],
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
									"source" : [ "obj-7", 0 ],
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
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p assets",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 12.0, 116.0, 55.0, 20.0 ],
					"id" : "obj-14",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 803.0, 60.0, 609.0, 525.0 ],
						"bglocked" : 0,
						"defrect" : [ 803.0, 60.0, 609.0, 525.0 ],
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
									"maxclass" : "newobj",
									"text" : "p grabber",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 99.0, 360.25, 63.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 715.0, 56.0, 847.0, 610.0 ],
										"bglocked" : 0,
										"defrect" : [ 715.0, 56.0, 847.0, 610.0 ],
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
													"text" : "/l/m/cam/close",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 85.0, 323.0, 87.0, 18.0 ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/m/cam/open",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 85.0, 296.0, 86.0, 18.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 275.0, 434.0, 32.5, 20.0 ],
													"id" : "obj-63",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 352.0, 99.0, 32.5, 20.0 ],
													"id" : "obj-62",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_GRABBER_%s/xform/o 127",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 313.0, 259.0, 247.0, 20.0 ],
													"id" : "obj-61",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_GRABBER_%s/input sink cam",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 256.0, 286.0, 276.0, 20.0 ],
													"id" : "obj-59",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_GRABBER_%s/xform/size 80 60",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 352.0, 224.0, 284.0, 20.0 ],
													"id" : "obj-60",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 433.0, 519.0, 40.0, 20.0 ],
													"id" : "obj-58",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 491.0, 408.0, 32.5, 20.0 ],
													"id" : "obj-52",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 469.0, 321.0, 20.0, 20.0 ],
													"id" : "obj-53",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 501.0, 371.0, 50.0, 20.0 ],
													"id" : "obj-54",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 1000",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 471.0, 346.0, 55.0, 20.0 ],
													"id" : "obj-55",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/delete LAYER_GRABBER_%s",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 427.0, 466.0, 218.0, 20.0 ],
													"id" : "obj-56",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b b",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang", "bang" ],
													"patching_rect" : [ 220.0, 451.0, 46.0, 20.0 ],
													"id" : "obj-48",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 174.0, 360.0, 20.0, 20.0 ],
													"id" : "obj-49",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 206.0, 410.0, 50.0, 20.0 ],
													"id" : "obj-50",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 15",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 176.0, 385.0, 49.0, 20.0 ],
													"id" : "obj-51",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_GRABBER_%s/input sink ipcam0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 132.0, 505.0, 276.0, 20.0 ],
													"id" : "obj-45",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_GRABBER_%s/xform/size 320 240",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 204.0, 474.0, 284.0, 20.0 ],
													"id" : "obj-46",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 370.0, 606.0, 40.0, 20.0 ],
													"id" : "obj-47",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i i i",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "int", "int" ],
													"patching_rect" : [ 372.0, 153.0, 46.0, 20.0 ],
													"id" : "obj-43",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b b",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang", "bang" ],
													"patching_rect" : [ 408.0, 124.0, 46.0, 20.0 ],
													"id" : "obj-37",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 768",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 551.0, 130.0, 72.0, 20.0 ],
													"id" : "obj-36",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 1024",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 468.0, 157.0, 79.0, 20.0 ],
													"id" : "obj-35",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 353.0, 29.0, 20.0, 20.0 ],
													"id" : "obj-34",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 385.0, 79.0, 50.0, 20.0 ],
													"id" : "obj-20",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 1000",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 355.0, 54.0, 55.0, 20.0 ],
													"id" : "obj-26",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/new LAYER_GRABBER_%s %ld %ld",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 410.0, 191.0, 253.0, 20.0 ],
													"id" : "obj-32",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 583.0, 556.0, 39.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_GRABBER/xform/size 320 240",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 31.0, 102.0, 234.0, 18.0 ],
													"id" : "obj-9",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_GRABBER/mask clear",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 91.0, 208.0, 191.0, 18.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_GRABBER/mask unsink",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 78.0, 182.0, 200.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_GRABBER/mask sink maw.gif",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 58.0, 160.0, 230.0, 18.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/delete LAYER_GRABBER",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 95.0, 236.0, 166.0, 18.0 ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_GRABBER/input sink cam",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 54.0, 126.0, 226.0, 18.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/new LAYER_GRABBER 512 384",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 11.0, 77.0, 202.0, 18.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 8.0, 355.0, 39.0, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 2 ],
													"destination" : [ "obj-36", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 1 ],
													"destination" : [ "obj-35", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 0 ],
													"destination" : [ "obj-43", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-49", 0 ],
													"destination" : [ "obj-51", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-51", 2 ],
													"destination" : [ "obj-50", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-54", 0 ],
													"destination" : [ "obj-52", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-62", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-62", 0 ],
													"destination" : [ "obj-37", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-50", 0 ],
													"destination" : [ "obj-63", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-63", 0 ],
													"destination" : [ "obj-48", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-46", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-48", 0 ],
													"destination" : [ "obj-46", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-48", 0 ],
													"destination" : [ "obj-45", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-45", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-52", 0 ],
													"destination" : [ "obj-56", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-56", 0 ],
													"destination" : [ "obj-58", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-61", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 1 ],
													"destination" : [ "obj-61", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-32", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 2 ],
													"destination" : [ "obj-32", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-35", 0 ],
													"destination" : [ "obj-32", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-32", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 0 ],
													"destination" : [ "obj-59", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-59", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-60", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 1 ],
													"destination" : [ "obj-60", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-34", 0 ],
													"destination" : [ "obj-26", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-26", 2 ],
													"destination" : [ "obj-20", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-55", 2 ],
													"destination" : [ "obj-54", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-53", 0 ],
													"destination" : [ "obj-55", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p player",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 247.0, 347.25, 53.0, 20.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 780.0, 126.0, 755.0, 490.0 ],
										"bglocked" : 0,
										"defrect" : [ 780.0, 126.0, 755.0, 490.0 ],
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
													"text" : "/livedraw/media/delete oh.mov",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 108.0, 136.0, 184.0, 18.0 ],
													"id" : "obj-34",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "comment",
													"text" : "When sinking the same source, it closes the source -- in the case of players, the player releases the source playable asset.  This is no good..  \"Close\" on the player asset should have a different behavior.  it should stop, but not \"close\".",
													"linecount" : 7,
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 432.0, 284.0, 212.0, 103.0 ],
													"id" : "obj-33",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b b b b b b b",
													"numoutlets" : 7,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "bang", "bang", "bang", "bang", "bang" ],
													"patching_rect" : [ 295.0, 51.0, 100.0, 20.0 ],
													"id" : "obj-31",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 167.0, 3.0, 20.0, 20.0 ],
													"id" : "obj-30",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b b b b",
													"numoutlets" : 4,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "bang", "bang", "bang" ],
													"patching_rect" : [ 151.0, 11.0, 59.5, 20.0 ],
													"id" : "obj-28",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/delete LAYER_1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 66.75, 436.0, 466.0, 18.0 ],
													"id" : "obj-25",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 104.0, 189.0, 50.0, 20.0 ],
													"id" : "obj-24",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/new LAYER_1 250 250, /livedraw/layers/LAYER_1/input sink PLAYER_0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 65.75, 414.0, 466.0, 18.0 ],
													"id" : "obj-22",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/PLAYER_0/speed $1",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.0, 216.0, 210.0, 18.0 ],
													"id" : "obj-17",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/PLAYER_0/stop",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 101.0, 257.0, 184.0, 18.0 ],
													"id" : "obj-15",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/PLAYER_0/start",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 84.0, 99.0, 184.0, 18.0 ],
													"id" : "obj-14",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/dump",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 64.75, 361.0, 204.0, 18.0 ],
													"id" : "obj-13",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/input dump",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 63.75, 390.0, 204.0, 18.0 ],
													"id" : "obj-11",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_0/mask sink maw.gif",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 363.75, 256.0, 174.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_0/input unsink, /l/l/LAYER_0/mask unsink, /l/l/LAYER_0/input clear, /l/l/LAYER_0/mask clear",
													"linecount" : 3,
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 363.75, 200.0, 275.0, 44.0 ],
													"id" : "obj-9",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/input sink PLAYER_0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 294.75, 127.0, 255.0, 18.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/delete LAYER_0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 339.75, 171.0, 178.0, 18.0 ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/new LAYER_0 100 100",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 369.75, 101.0, 213.0, 18.0 ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/PLAYER_0/load oh.mov",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 65.0, 79.0, 226.0, 18.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/PLAYER_0/dump",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 189.0, 332.0, 192.0, 18.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/new player PLAYER_0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 50.0, 59.0, 218.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/dump",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 11.0, 14.0, 127.0, 18.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/delete PLAYER_0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 300.0, 193.0, 18.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 13.0, 359.0, 39.0, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-34", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-31", 5 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-31", 6 ],
													"destination" : [ "obj-5", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 0 ],
													"destination" : [ "obj-31", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 1 ],
													"destination" : [ "obj-14", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 2 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-28", 3 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-30", 0 ],
													"destination" : [ "obj-28", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-25", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-24", 0 ],
													"destination" : [ "obj-17", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-22", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-15", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-13", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-11", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-4", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p movie",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 245.0, 321.25, 53.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"defrect" : [ 25.0, 69.0, 640.0, 480.0 ],
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
										"boxes" : [  ],
										"lines" : [  ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p stream",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 99.0, 391.25, 57.0, 20.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 530.0, 46.0, 847.0, 610.0 ],
										"bglocked" : 0,
										"defrect" : [ 530.0, 46.0, 847.0, 610.0 ],
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
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 213.0, 350.0, 32.5, 20.0 ],
													"id" : "obj-63",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 352.0, 99.0, 32.5, 20.0 ],
													"id" : "obj-62",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_%s/xform/o 127",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 313.0, 259.0, 184.0, 20.0 ],
													"id" : "obj-61",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_%s/input sink ipcam0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 256.0, 286.0, 213.0, 20.0 ],
													"id" : "obj-59",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_%s/xform/size 160 120",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 352.0, 224.0, 222.0, 20.0 ],
													"id" : "obj-60",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 433.0, 519.0, 40.0, 20.0 ],
													"id" : "obj-58",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "- 1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 491.0, 408.0, 32.5, 20.0 ],
													"id" : "obj-52",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 469.0, 321.0, 20.0, 20.0 ],
													"id" : "obj-53",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 501.0, 371.0, 50.0, 20.0 ],
													"id" : "obj-54",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 100",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 471.0, 346.0, 49.0, 20.0 ],
													"id" : "obj-55",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/delete LAYER_%s",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 427.0, 466.0, 156.0, 20.0 ],
													"id" : "obj-56",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b b",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang", "bang" ],
													"patching_rect" : [ 158.0, 367.0, 46.0, 20.0 ],
													"id" : "obj-48",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 112.0, 276.0, 20.0, 20.0 ],
													"id" : "obj-49",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 144.0, 326.0, 50.0, 20.0 ],
													"id" : "obj-50",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 15",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 114.0, 301.0, 49.0, 20.0 ],
													"id" : "obj-51",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_%s/input sink ipcam0",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 70.0, 421.0, 213.0, 20.0 ],
													"id" : "obj-45",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/LAYER_%s/xform/size 320 240",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 142.0, 390.0, 222.0, 20.0 ],
													"id" : "obj-46",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 308.0, 522.0, 40.0, 20.0 ],
													"id" : "obj-47",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i i i",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "int", "int" ],
													"patching_rect" : [ 372.0, 153.0, 46.0, 20.0 ],
													"id" : "obj-43",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t i b b",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang", "bang" ],
													"patching_rect" : [ 408.0, 124.0, 46.0, 20.0 ],
													"id" : "obj-37",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 768",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 551.0, 130.0, 72.0, 20.0 ],
													"id" : "obj-36",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "random 1024",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "int" ],
													"patching_rect" : [ 468.0, 157.0, 79.0, 20.0 ],
													"id" : "obj-35",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 353.0, 29.0, 20.0, 20.0 ],
													"id" : "obj-34",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 11.595187,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 385.0, 79.0, 50.0, 20.0 ],
													"id" : "obj-20",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "uzi 50",
													"numoutlets" : 3,
													"fontsize" : 11.595187,
													"outlettype" : [ "bang", "bang", "int" ],
													"patching_rect" : [ 355.0, 54.0, 46.0, 20.0 ],
													"id" : "obj-26",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/l/new LAYER_%s %ld %ld",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 410.0, 191.0, 190.0, 20.0 ],
													"id" : "obj-32",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/xform/size 80 60",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 550.0, 294.0, 200.0, 18.0 ],
													"id" : "obj-24",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/input sink ipcam0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 573.0, 318.0, 205.0, 18.0 ],
													"id" : "obj-25",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 583.0, 556.0, 39.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/xform/size 320 240",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 31.0, 102.0, 214.0, 18.0 ],
													"id" : "obj-9",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/mask clear",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 121.0, 196.0, 170.0, 18.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/mask unsink",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 108.0, 170.0, 179.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/mask sink maw.gif",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 88.0, 148.0, 210.0, 18.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/delete LAYER_IPCAM",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 125.0, 224.0, 145.0, 18.0 ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_IPCAM/input sink ipcam0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 54.0, 126.0, 205.0, 18.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/new LAYER_IPCAM 512 384",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 11.0, 77.0, 181.0, 18.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 64.0, 364.0, 39.0, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-63", 0 ],
													"destination" : [ "obj-48", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-50", 0 ],
													"destination" : [ "obj-63", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-62", 0 ],
													"destination" : [ "obj-37", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-20", 0 ],
													"destination" : [ "obj-62", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-52", 0 ],
													"destination" : [ "obj-56", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-54", 0 ],
													"destination" : [ "obj-52", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-61", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 1 ],
													"destination" : [ "obj-61", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-60", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 1 ],
													"destination" : [ "obj-60", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-34", 0 ],
													"destination" : [ "obj-26", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-26", 2 ],
													"destination" : [ "obj-20", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-55", 2 ],
													"destination" : [ "obj-54", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-53", 0 ],
													"destination" : [ "obj-55", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-59", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 0 ],
													"destination" : [ "obj-59", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-56", 0 ],
													"destination" : [ "obj-58", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-51", 2 ],
													"destination" : [ "obj-50", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-49", 0 ],
													"destination" : [ "obj-51", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-46", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-48", 0 ],
													"destination" : [ "obj-46", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-48", 0 ],
													"destination" : [ "obj-45", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-32", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-45", 0 ],
													"destination" : [ "obj-47", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-43", 2 ],
													"destination" : [ "obj-32", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 0 ],
													"destination" : [ "obj-43", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-35", 0 ],
													"destination" : [ "obj-32", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-32", 2 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 1 ],
													"destination" : [ "obj-35", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-37", 2 ],
													"destination" : [ "obj-36", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-25", 0 ],
													"destination" : [ "obj-27", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-24", 0 ],
													"destination" : [ "obj-27", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p image",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 100.0, 308.25, 53.0, 20.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 912.0, 362.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"defrect" : [ 912.0, 362.0, 640.0, 480.0 ],
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
													"text" : "/livedraw/media/maw.gif/test",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 92.0, 104.0, 161.0, 18.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 25.0, 252.0, 39.0, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p syphon",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 100.0, 419.25, 59.0, 20.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"defrect" : [ 25.0, 69.0, 640.0, 480.0 ],
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
										"boxes" : [  ],
										"lines" : [  ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p buffer",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 248.0, 375.25, 51.0, 20.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
										"bglocked" : 0,
										"defrect" : [ 25.0, 69.0, 640.0, 480.0 ],
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
													"text" : "/livedraw/media/BUFFER_0/dump",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 112.0, 113.0, 192.0, 18.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/new buffer BUFFER_0 33 pass",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 66.0, 63.0, 264.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/dump",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 37.0, 39.0, 127.0, 18.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/media/delete BUFFER_0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 92.0, 90.0, 196.0, 18.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 36.0, 339.0, 39.0, 20.0 ],
													"id" : "obj-12",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/uncache",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 88.0, 191.0, 196.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/meta/description d",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 36.0, 34.0, 238.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/dump",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 7.0, 9.0, 127.0, 18.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/cache",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 85.0, 160.0, 172.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 79.0, 124.0, 172.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov/meta",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 68.0, 97.0, 172.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/oh.mov",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 70.0, 182.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 10.0, 237.0, 39.0, 20.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
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
									"source" : [ "obj-6", 0 ],
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
									"source" : [ "obj-4", 0 ],
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
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 1",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 123.0, 130.0, 50.0, 20.0 ],
					"id" : "obj-12",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 0.0, 44.0, 1239.0, 826.0 ],
						"bglocked" : 0,
						"defrect" : [ 0.0, 44.0, 1239.0, 826.0 ],
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
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1046.0, 479.333344, 206.0, 18.0 ],
									"id" : "obj-44",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/BUFFER_NAME/record ALIAS",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1046.0, 457.333344, 252.0, 18.0 ],
									"id" : "obj-43",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/MY_VIDEO_NAME/cache",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1043.0, 428.333344, 228.0, 18.0 ],
									"id" : "obj-42",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/stop cam",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1051.0, 587.333374, 143.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/media/MY_CAM_NAME/start",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 1033.0, 404.333344, 210.0, 18.0 ],
									"id" : "obj-30",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump contents of buffer",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 1123.0, 61.0, 138.0, 20.0 ],
									"id" : "obj-41",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/media/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 944.75, 38.0, 125.0, 18.0 ],
									"id" : "obj-40",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 954.75, 64.0, 164.0, 18.0 ],
									"id" : "obj-36",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 546.0, 146.0, 43.0, 20.0 ],
									"id" : "obj-35",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 276.75, 174.0, 229.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Dump contents of asset collection.",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 1075.0, 37.0, 193.0, 20.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Attach it to a asset alias.  The asset can be any named thing.  If the asset is cached, then the player will get the cached version.  Otherwise, it will be offered a disk based version or a connection to a live stream.",
									"linecount" : 9,
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 784.0, 465.0, 152.0, 131.0 ],
									"id" : "obj-39",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Detach from video source (i.e. stop recording).  Does not turn off the source.",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 684.0, 355.0, 415.0, 20.0 ],
									"id" : "obj-38",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Add ability to record for specified n frames or time.  ASSET_ALIAS must point to a video source.  This can be a grabber, a live stream, a syphon source, or a video player.",
									"linecount" : 4,
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 688.0, 273.0, 292.0, 62.0 ],
									"id" : "obj-37",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/MY_BUFFER/stop",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 451.75, 356.0, 230.0, 18.0 ],
									"id" : "obj-34",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/MY_BUFFER/record ASSET_ALIAS",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 363.75, 277.0, 322.0, 18.0 ],
									"id" : "obj-33",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 608.0, 218.0, 234.0, 20.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER 60 fixed",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 324.75, 221.0, 273.0, 18.0 ],
									"id" : "obj-32",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 608.0, 194.0, 234.0, 20.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is a live source (grabber, stream, etc), it will stop / close",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 517.0, 98.0, 323.0, 20.0 ],
									"id" : "obj-28",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new buffer (name, nframes, type)",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 608.0, 170.0, 234.0, 20.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is a live source (grabber, stream, etc), it will start",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 517.0, 76.0, 286.0, 20.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is disk-based, it will uncache",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 517.0, 54.0, 181.0, 20.0 ],
									"id" : "obj-18",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "if it is disk-based, it will cache",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 517.0, 32.0, 167.0, 20.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/uncache oh.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 196.0, 56.333332, 181.0, 18.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/stop cam",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 257.0, 120.333336, 143.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/start cam",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 239.0, 96.333336, 144.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create a new layer called LAYER_0",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 745.0, 438.0, 198.0, 20.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/delete my_buffer_1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.75, 947.0, 202.0, 18.0 ],
									"id" : "obj-25",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/my_buffer_1/type 3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.75, 912.0, 243.0, 18.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer 1 33 type",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.75, 972.0, 243.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.75, 883.0, 243.0, 18.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new MY_BUFFER",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 298.75, 197.0, 229.0, 18.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new my_buffer_1 33 type",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 589.75, 818.0, 266.0, 18.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer stream_ipcam2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 572.75, 785.0, 331.0, 18.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/alias stream_ipcam2 buttes",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 542.75, 748.0, 331.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer ipcam2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 476.75, 663.0, 331.0, 18.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer buttes",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 461.75, 633.0, 283.0, 18.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100.",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 488.75, 438.0, 254.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0_16076",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 605.75, 997.0, 258.0, 18.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/mask fingers.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 505.75, 466.0, 272.0, 18.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/cache oh.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 172.75, 32.0, 168.0, 18.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 507.75, 721.0, 214.0, 18.0 ],
									"id" : "obj-59",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 166.0, 510.0, 39.0, 20.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 957.0, 101.0, 39.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-34", 0 ],
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
									"source" : [ "obj-32", 0 ],
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
									"source" : [ "obj-8", 0 ],
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
									"source" : [ "obj-36", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-40", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p roots",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 133.0, 99.0, 47.0, 20.0 ],
					"id" : "obj-15",
					"fontname" : "Arial",
					"numinlets" : 0,
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
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 518.75, 403.0, 202.0, 18.0 ],
									"id" : "obj-25",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/my_buffer_1/type 3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 480.75, 376.0, 243.0, 18.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer 1 33 type",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 563.75, 455.0, 243.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 481.75, 347.0, 243.0, 18.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffer my_buffer_1 33",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 479.75, 321.0, 243.0, 18.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/buffers/new my_buffer_1 33 type",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 463.75, 282.0, 266.0, 18.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer stream_ipcam2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 446.75, 249.0, 331.0, 18.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets/alias stream_ipcam2 buttes",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 416.75, 212.0, 331.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer ipcam2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 350.75, 127.0, 331.0, 18.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer buttes",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 307.75, 104.0, 283.0, 18.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100., /livedraw/canvas/layer/LAYER_0/source/buffer video_fingers.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 235.75, 28.0, 597.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/ld/c/l",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 131.400009, 340.0, 39.0, 18.0 ],
									"id" : "obj-18",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/ld/can/lay",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 127.400002, 295.0, 65.0, 18.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/c/lay",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 122.400002, 185.0, 94.0, 18.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0_16076",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 151.75, 452.0, 258.0, 18.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/mask fingers.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 366.75, 157.0, 272.0, 18.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/source/buffer video_fingers.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 283.75, 74.0, 347.0, 18.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 381.75, 185.0, 214.0, 18.0 ],
									"id" : "obj-59",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100. 100.",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 260.75, 52.0, 268.0, 18.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 339.0, 411.0, 39.0, 20.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 116.400002, 153.0, 129.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 102.400002, 130.0, 99.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/assets",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 88.400002, 107.0, 96.0, 18.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/effects",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 74.400002, 84.0, 96.0, 18.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/buffers",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 60.400002, 61.0, 98.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/sessions",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 46.0, 38.0, 108.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 9.0, 235.0, 39.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
 ],
						"lines" : [ 							{
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
									"source" : [ "obj-18", 0 ],
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
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-1", 0 ],
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
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-12", 0 ],
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
									"source" : [ "obj-7", 0 ],
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
									"source" : [ "obj-5", 0 ],
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
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-1", 0 ],
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
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p test 0",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 135.0, 73.0, 50.0, 20.0 ],
					"id" : "obj-11",
					"fontname" : "Arial",
					"numinlets" : 0,
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
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 213.0, 587.0, 41.0, 20.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Rotation",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 209.0, 491.0, 55.0, 20.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 156.5, 587.0, 50.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 44.0, 658.0, 39.0, 20.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 44.0, 613.0, 70.0, 20.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 100.5, 587.0, 50.0, 20.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 44.0, 587.0, 50.0, 20.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/scale $1 $2 $3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 44.0, 637.0, 266.0, 18.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "print",
									"numoutlets" : 0,
									"fontsize" : 11.595187,
									"patching_rect" : [ 788.0, 594.0, 33.0, 20.0 ],
									"id" : "obj-63",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 826.0, 594.0, 39.0, 20.0 ],
									"id" : "obj-52",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "alpha",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 1119.0, 528.0, 40.0, 20.0 ],
									"id" : "obj-53",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "slider",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"size" : 256.0,
									"patching_rect" : [ 875.0, 529.0, 241.0, 18.0 ],
									"id" : "obj-54",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 826.0, 550.0, 79.0, 20.0 ],
									"id" : "obj-61",
									"fontname" : "Arial",
									"numinlets" : 4
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "swatch",
									"numoutlets" : 2,
									"outlettype" : [ "", "float" ],
									"patching_rect" : [ 860.0, 422.0, 241.0, 98.0 ],
									"compatibility" : 1,
									"id" : "obj-62",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/label $1 $2 $3 $4",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 826.0, 573.0, 274.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Lock",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 647.0, 470.0, 35.0, 20.0 ],
									"id" : "obj-48",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 623.0, 469.0, 20.0, 20.0 ],
									"id" : "obj-50",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/lock $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 623.0, 492.0, 218.0, 18.0 ],
									"id" : "obj-51",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Lock",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 647.0, 408.0, 35.0, 20.0 ],
									"id" : "obj-46",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Solo",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 416.0, 406.0, 35.0, 20.0 ],
									"id" : "obj-44",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 623.0, 407.0, 20.0, 20.0 ],
									"id" : "obj-38",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 392.0, 406.0, 20.0, 20.0 ],
									"id" : "obj-37",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/lock $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 623.0, 430.0, 218.0, 18.0 ],
									"id" : "obj-35",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/solo $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 392.0, 431.0, 218.0, 18.0 ],
									"id" : "obj-34",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 392.0, 532.0, 39.0, 20.0 ],
									"id" : "obj-33",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/order backward",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 350.75, 375.0, 521.0, 18.0 ],
									"id" : "obj-32",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 155.5, 491.0, 50.0, 20.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 42.0, 466.0, 39.0, 20.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Anchor Point",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 158.0, 395.0, 99.0, 20.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 42.0, 421.0, 57.0, 20.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 102.5, 395.0, 50.0, 20.0 ],
									"id" : "obj-25",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 42.0, 395.0, 50.0, 20.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/anchorpoint $1 $2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 42.0, 445.0, 281.0, 18.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 43.0, 562.0, 39.0, 20.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0. 0. 0.",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 43.0, 517.0, 70.0, 20.0 ],
									"id" : "obj-39",
									"fontname" : "Arial",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 99.5, 491.0, 50.0, 20.0 ],
									"id" : "obj-40",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 43.0, 491.0, 50.0, 20.0 ],
									"id" : "obj-41",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/rotate $1 $2 $3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 43.0, 541.0, 266.0, 18.0 ],
									"id" : "obj-42",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 40.0, 323.0, 50.0, 20.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Opacity : 0 - 255",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 94.0, 322.0, 99.0, 20.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 775.0, 91.0, 20.0, 20.0 ],
									"id" : "obj-6",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 343.0, 80.0, 20.0, 20.0 ],
									"id" : "obj-5",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 40.0, 370.0, 39.0, 20.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/*/transform/opacity $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 40.0, 346.0, 285.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "create and set layers",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 41.0, 123.0, 122.0, 20.0 ],
									"id" : "obj-69",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "delete layers",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 652.0, 126.0, 79.0, 20.0 ],
									"id" : "obj-68",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_4",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 734.75, 244.0, 213.0, 18.0 ],
									"id" : "obj-55",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_3",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 719.75, 221.0, 213.0, 18.0 ],
									"id" : "obj-56",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 699.75, 198.0, 213.0, 18.0 ],
									"id" : "obj-57",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 676.75, 175.0, 213.0, 18.0 ],
									"id" : "obj-58",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 652.75, 151.0, 214.0, 18.0 ],
									"id" : "obj-59",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 653.0, 279.0, 39.0, 20.0 ],
									"id" : "obj-60",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_4 500 200, /livedraw/canvas/layer/LAYER_4/input rain.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 122.75, 239.0, 513.0, 18.0 ],
									"id" : "obj-49",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_3 400 100, /livedraw/canvas/layer/LAYER_3/input garbage.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 107.75, 216.0, 521.0, 18.0 ],
									"id" : "obj-47",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_2 300 300, /livedraw/canvas/layer/LAYER_2/input track2.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 87.75, 193.0, 534.0, 18.0 ],
									"id" : "obj-45",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_1 200 200, /livedraw/canvas/layer/LAYER_1/input bball.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 64.75, 170.0, 528.0, 18.0 ],
									"id" : "obj-43",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_0 100 100, /livedraw/canvas/layer/LAYER_0/source fingers.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 40.75, 146.0, 521.0, 18.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 41.0, 277.0, 39.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-49", 0 ],
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
									"destination" : [ "obj-45", 0 ],
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
									"destination" : [ "obj-29", 0 ],
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
									"source" : [ "obj-49", 0 ],
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
									"source" : [ "obj-45", 0 ],
									"destination" : [ "obj-14", 0 ],
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
									"source" : [ "obj-59", 0 ],
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
									"source" : [ "obj-57", 0 ],
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
									"source" : [ "obj-55", 0 ],
									"destination" : [ "obj-60", 0 ],
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
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-59", 0 ],
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
									"destination" : [ "obj-57", 0 ],
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
									"destination" : [ "obj-55", 0 ],
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
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-22", 0 ],
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
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-24", 0 ],
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
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-7", 0 ],
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
									"source" : [ "obj-41", 0 ],
									"destination" : [ "obj-39", 0 ],
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
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-39", 2 ],
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
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-33", 0 ],
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
									"source" : [ "obj-38", 0 ],
									"destination" : [ "obj-35", 0 ],
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
									"source" : [ "obj-51", 0 ],
									"destination" : [ "obj-33", 0 ],
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
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
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
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-61", 0 ],
									"hidden" : 0,
									"midpoints" : [ 869.5, 526.0, 835.5, 526.0 ]
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
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-8", 2 ],
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
									"source" : [ "obj-11", 0 ],
									"destination" : [ "obj-8", 0 ],
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
									"source" : [ "obj-12", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p layer sources",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 12.0, 89.0, 93.0, 20.0 ],
					"id" : "obj-10",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 965.0, 318.0, 475.0, 528.0 ],
						"bglocked" : 0,
						"defrect" : [ 965.0, 318.0, 475.0, 528.0 ],
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
									"text" : "/l/l/LAYER_0/input sink MAW.jpg",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 99.75, 103.0, 177.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/l/LAYER_0/mask sink MAW.jpg",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 129.75, 175.0, 177.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/l/LAYER_0/input sink maw.gif",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 83.75, 77.0, 170.0, 18.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/media/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 109.75, 322.0, 89.0, 18.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/effects/alphamask/alphamode 11",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 92.0, 487.5, 351.0, 18.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_0/effects/curves/lut 22",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 91.75, 463.0, 285.0, 18.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_1/mask",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 175.75, 429.0, 209.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/new LAYER_1 100 100",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 117.75, 353.0, 247.0, 18.0 ],
									"id" : "obj-9",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/delete LAYER_1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 130.75, 375.0, 213.0, 18.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/layer/LAYER_1/input bball.mov",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 159.75, 403.0, 259.0, 18.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/l/new LAYER_0 512 384",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 25.75, 11.0, 145.0, 18.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/l/l/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 43.75, 32.0, 110.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 2.0, 419.0, 39.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
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
									"source" : [ "obj-6", 0 ],
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
									"source" : [ "obj-9", 0 ],
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
									"source" : [ "obj-12", 0 ],
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
									"source" : [ "obj-15", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p transforms",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 12.0, 63.0, 100.0, 20.0 ],
					"id" : "obj-9",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 6.0, 656.0, 488.0, 258.0 ],
						"bglocked" : 0,
						"defrect" : [ 6.0, 656.0, 488.0, 258.0 ],
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
									"maxclass" : "newobj",
									"text" : "p size",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 47.0, 115.0, 61.0, 20.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 0,
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
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 232.0, 78.0, 57.0, 20.0 ],
													"id" : "obj-5",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 292.5, 52.0, 50.0, 20.0 ],
													"id" : "obj-6",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 228.0, 49.0, 50.0, 20.0 ],
													"id" : "obj-9",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/sz $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 232.0, 102.0, 192.0, 18.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 122.0, 354.0, 50.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/height $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 122.0, 377.0, 197.0, 18.0 ],
													"id" : "obj-2",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 122.0, 308.0, 50.0, 20.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/width $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 122.0, 331.0, 182.0, 18.0 ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 75.0, 244.0, 50.0, 20.0 ],
													"id" : "obj-29",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/height $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.0, 267.0, 197.0, 18.0 ],
													"id" : "obj-30",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 75.0, 198.0, 50.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/width $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.0, 221.0, 182.0, 18.0 ],
													"id" : "obj-28",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.0, 140.0, 57.0, 20.0 ],
													"id" : "obj-16",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 135.5, 114.0, 50.0, 20.0 ],
													"id" : "obj-15",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 71.0, 111.0, 50.0, 20.0 ],
													"id" : "obj-13",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 8.0, 351.0, 39.0, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/size $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 75.0, 164.0, 192.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
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
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-4", 0 ],
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
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-8", 0 ],
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
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-5", 1 ],
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
													"source" : [ "obj-5", 0 ],
													"destination" : [ "obj-10", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "float", "bang" ],
									"patching_rect" : [ 50.0, 138.0, 50.0, 20.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 51.0, 188.0, 39.0, 20.0 ],
									"id" : "obj-2",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/transform/opacity $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 51.0, 164.0, 286.0, 18.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p anchorpoint",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 48.0, 9.0, 81.0, 20.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 0,
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
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 229.5, 444.0, 50.0, 20.0 ],
													"id" : "obj-43",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 470.0, 60.0, 20.0 ],
													"id" : "obj-44",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 444.0, 50.0, 20.0 ],
													"id" : "obj-45",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 444.0, 50.0, 20.0 ],
													"id" : "obj-46",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 495.0, 275.0, 18.0 ],
													"id" : "obj-47",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 393.0, 50.0, 20.0 ],
													"id" : "obj-39",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 367.0, 50.0, 20.0 ],
													"id" : "obj-40",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 367.0, 50.0, 20.0 ],
													"id" : "obj-41",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 417.0, 238.0, 18.0 ],
													"id" : "obj-42",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 316.0, 50.0, 20.0 ],
													"id" : "obj-36",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 343.0, 222.0, 18.0 ],
													"id" : "obj-37",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 226.0, 50.0, 20.0 ],
													"id" : "obj-31",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint Z $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 249.0, 233.0, 18.0 ],
													"id" : "obj-32",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 179.0, 50.0, 20.0 ],
													"id" : "obj-29",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint Y $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 202.0, 233.0, 18.0 ],
													"id" : "obj-30",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 133.0, 50.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint X $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 156.0, 233.0, 18.0 ],
													"id" : "obj-28",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 229.5, 49.0, 50.0, 20.0 ],
													"id" : "obj-23",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 75.0, 60.0, 20.0 ],
													"id" : "obj-16",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 49.0, 50.0, 20.0 ],
													"id" : "obj-15",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 49.0, 50.0, 20.0 ],
													"id" : "obj-13",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 42.0, 286.0, 39.0, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/ld/layers/LAYER_0/xform/anchorpoint $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 99.0, 275.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
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
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p rotation",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 47.0, 90.0, 61.0, 20.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 0,
									"patcher" : 									{
										"fileversion" : 1,
										"appversion" : 										{
											"major" : 5,
											"minor" : 1,
											"revision" : 9
										}
,
										"rect" : [ 760.0, 96.0, 680.0, 724.0 ],
										"bglocked" : 0,
										"defrect" : [ 760.0, 96.0, 680.0, 724.0 ],
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
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 100.0, 171.0, 189.0, 18.0 ],
													"id" : "obj-11",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "t b l",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "bang", "" ],
													"patching_rect" : [ 85.0, 72.0, 32.5, 20.0 ],
													"id" : "obj-10",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 79.0, 23.0, 20.0, 20.0 ],
													"id" : "obj-9",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "button",
													"numoutlets" : 1,
													"outlettype" : [ "bang" ],
													"patching_rect" : [ 60.0, 156.0, 20.0, 20.0 ],
													"id" : "obj-6",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "sprintf /l/layers/%s/xform/rotate %s",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 163.0, 133.0, 293.0, 20.0 ],
													"id" : "obj-4",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "LAYER_0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 58.0, 107.0, 96.0, 18.0 ],
													"id" : "obj-3",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "umenu",
													"numoutlets" : 3,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "", "" ],
													"items" : [ "LAYER_0", ",", "LAYER_1", ",", "LAYER_2", ",", "LAYER_3", ",", "LAYER_4", ",", "LAYER_5", ",", "LAYER_6", ",", "LAYER_7", ",", "LAYER_8", ",", "LAYER_9" ],
													"types" : [  ],
													"patching_rect" : [ 60.0, 48.0, 100.0, 20.0 ],
													"id" : "obj-1",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 261.5, 618.0, 50.0, 20.0 ],
													"id" : "obj-43",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0. 0.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 644.0, 70.0, 20.0 ],
													"id" : "obj-44",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 201.5, 618.0, 50.0, 20.0 ],
													"id" : "obj-45",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 618.0, 50.0, 20.0 ],
													"id" : "obj-46",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 668.0, 217.0, 18.0 ],
													"id" : "obj-47",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 567.0, 57.0, 20.0 ],
													"id" : "obj-39",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 201.5, 541.0, 50.0, 20.0 ],
													"id" : "obj-40",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 541.0, 50.0, 20.0 ],
													"id" : "obj-41",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 591.0, 201.0, 18.0 ],
													"id" : "obj-42",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 490.0, 50.0, 20.0 ],
													"id" : "obj-36",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 517.0, 185.0, 18.0 ],
													"id" : "obj-37",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 400.0, 50.0, 20.0 ],
													"id" : "obj-31",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate Z $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 423.0, 195.0, 18.0 ],
													"id" : "obj-32",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 353.0, 50.0, 20.0 ],
													"id" : "obj-29",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate Y $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 376.0, 195.0, 18.0 ],
													"id" : "obj-30",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 141.0, 307.0, 50.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/rotate X $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 330.0, 196.0, 18.0 ],
													"id" : "obj-28",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 261.5, 223.0, 50.0, 20.0 ],
													"id" : "obj-23",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0. 0. 0.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 249.0, 70.0, 20.0 ],
													"id" : "obj-16",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 201.5, 223.0, 50.0, 20.0 ],
													"id" : "obj-15",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 137.0, 220.0, 50.0, 20.0 ],
													"id" : "obj-13",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 74.0, 460.0, 39.0, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/*/xform/rotate DEGREES $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 141.0, 273.0, 277.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-4", 0 ],
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
													"source" : [ "obj-36", 0 ],
													"destination" : [ "obj-37", 0 ],
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
													"source" : [ "obj-9", 0 ],
													"destination" : [ "obj-1", 0 ],
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
													"source" : [ "obj-10", 1 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-10", 0 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p position",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 47.0, 34.0, 62.0, 20.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 0,
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
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 229.5, 444.0, 50.0, 20.0 ],
													"id" : "obj-43",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 470.0, 60.0, 20.0 ],
													"id" : "obj-44",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 444.0, 50.0, 20.0 ],
													"id" : "obj-45",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 444.0, 50.0, 20.0 ],
													"id" : "obj-46",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 494.0, 322.0, 18.0 ],
													"id" : "obj-47",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 393.0, 50.0, 20.0 ],
													"id" : "obj-39",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 367.0, 50.0, 20.0 ],
													"id" : "obj-40",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 367.0, 50.0, 20.0 ],
													"id" : "obj-41",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 417.0, 271.0, 18.0 ],
													"id" : "obj-42",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 316.0, 50.0, 20.0 ],
													"id" : "obj-36",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 343.0, 255.0, 18.0 ],
													"id" : "obj-37",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 226.0, 50.0, 20.0 ],
													"id" : "obj-31",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position Z $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 249.0, 265.0, 18.0 ],
													"id" : "obj-32",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 179.0, 50.0, 20.0 ],
													"id" : "obj-29",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position Y $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 202.0, 266.0, 18.0 ],
													"id" : "obj-30",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 133.0, 50.0, 20.0 ],
													"id" : "obj-27",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/livedraw/layers/LAYER_0/transform/position X $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 156.0, 266.0, 18.0 ],
													"id" : "obj-28",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 229.5, 49.0, 50.0, 20.0 ],
													"id" : "obj-23",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 0 0 0",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 75.0, 60.0, 20.0 ],
													"id" : "obj-16",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 169.5, 49.0, 50.0, 20.0 ],
													"id" : "obj-15",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "number",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "int", "bang" ],
													"patching_rect" : [ 109.0, 49.0, 50.0, 20.0 ],
													"id" : "obj-13",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 42.0, 286.0, 39.0, 20.0 ],
													"id" : "obj-8",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/l/LAYER_0/t/p $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 109.0, 99.0, 140.0, 18.0 ],
													"id" : "obj-7",
													"fontname" : "Arial",
													"numinlets" : 2
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
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p scale",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 48.0, 61.0, 49.0, 20.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 0,
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
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 217.5, 425.0, 50.0, 20.0 ],
													"id" : "obj-48",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1. 1.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 451.0, 68.0, 20.0 ],
													"id" : "obj-49",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 157.5, 425.0, 50.0, 20.0 ],
													"id" : "obj-50",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 425.0, 50.0, 20.0 ],
													"id" : "obj-51",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 475.0, 215.0, 18.0 ],
													"id" : "obj-52",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 374.0, 57.0, 20.0 ],
													"id" : "obj-53",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 157.5, 348.0, 50.0, 20.0 ],
													"id" : "obj-54",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 348.0, 50.0, 20.0 ],
													"id" : "obj-55",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 398.0, 198.0, 18.0 ],
													"id" : "obj-56",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 297.0, 50.0, 20.0 ],
													"id" : "obj-57",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 324.0, 182.0, 18.0 ],
													"id" : "obj-58",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 207.0, 50.0, 20.0 ],
													"id" : "obj-59",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale Z $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 230.0, 193.0, 18.0 ],
													"id" : "obj-60",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 160.0, 50.0, 20.0 ],
													"id" : "obj-61",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale Y $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 183.0, 193.0, 18.0 ],
													"id" : "obj-62",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 114.0, 50.0, 20.0 ],
													"id" : "obj-63",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale X $1",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 137.0, 193.0, 18.0 ],
													"id" : "obj-64",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 217.5, 30.0, 50.0, 20.0 ],
													"id" : "obj-65",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "pak 1. 1. 1.",
													"numoutlets" : 1,
													"fontsize" : 12.0,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 56.0, 70.0, 20.0 ],
													"id" : "obj-66",
													"fontname" : "Arial",
													"numinlets" : 3
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 157.5, 30.0, 50.0, 20.0 ],
													"id" : "obj-67",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "flonum",
													"numoutlets" : 2,
													"fontsize" : 12.0,
													"outlettype" : [ "float", "bang" ],
													"patching_rect" : [ 97.0, 30.0, 50.0, 20.0 ],
													"id" : "obj-68",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "s osc",
													"numoutlets" : 0,
													"fontsize" : 12.0,
													"patching_rect" : [ 30.0, 267.0, 39.0, 20.0 ],
													"id" : "obj-69",
													"fontname" : "Arial",
													"numinlets" : 1
												}

											}
, 											{
												"box" : 												{
													"maxclass" : "message",
													"text" : "/l/layers/LAYER_0/xform/scale $1 $2 $3",
													"numoutlets" : 1,
													"fontsize" : 11.595187,
													"outlettype" : [ "" ],
													"patching_rect" : [ 97.0, 80.0, 215.0, 18.0 ],
													"id" : "obj-70",
													"fontname" : "Arial",
													"numinlets" : 2
												}

											}
 ],
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-52", 0 ],
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
													"source" : [ "obj-58", 0 ],
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
													"source" : [ "obj-62", 0 ],
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
													"source" : [ "obj-70", 0 ],
													"destination" : [ "obj-69", 0 ],
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
													"source" : [ "obj-61", 0 ],
													"destination" : [ "obj-62", 0 ],
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
													"source" : [ "obj-57", 0 ],
													"destination" : [ "obj-58", 0 ],
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
													"source" : [ "obj-67", 0 ],
													"destination" : [ "obj-66", 1 ],
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
													"source" : [ "obj-66", 0 ],
													"destination" : [ "obj-70", 0 ],
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
													"source" : [ "obj-54", 0 ],
													"destination" : [ "obj-53", 1 ],
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
													"source" : [ "obj-49", 0 ],
													"destination" : [ "obj-52", 0 ],
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
													"source" : [ "obj-50", 0 ],
													"destination" : [ "obj-49", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-51", 0 ],
													"destination" : [ "obj-49", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
										"globalpatchername" : "",
										"fontface" : 0,
										"fontsize" : 12.0,
										"default_fontface" : 0,
										"default_fontname" : "Arial",
										"fontname" : "Arial",
										"default_fontsize" : 12.0
									}

								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "// general canvas/layer",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 76.0, 34.0, 150.0, 20.0 ],
					"id" : "obj-31",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p layer",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 12.0, 37.0, 47.0, 20.0 ],
					"id" : "obj-32",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 540.0, 121.0, 900.0, 820.0 ],
						"bglocked" : 0,
						"defrect" : [ 540.0, 121.0, 900.0, 820.0 ],
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
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 169.0, 235.0, 20.0, 20.0 ],
									"id" : "obj-41",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/clipping $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 169.0, 264.0, 202.0, 18.0 ],
									"id" : "obj-44",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 543.0, 74.0, 20.0, 20.0 ],
									"id" : "obj-40",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 514.0, 24.0, 20.0, 20.0 ],
									"id" : "obj-39",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 489.0, 161.0, 39.0, 20.0 ],
									"id" : "obj-36",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 75.0, 596.0, 39.0, 20.0 ],
									"id" : "obj-38",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "alpha",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 368.0, 530.0, 40.0, 20.0 ],
									"id" : "obj-37",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "slider",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"size" : 256.0,
									"patching_rect" : [ 124.0, 531.0, 241.0, 18.0 ],
									"id" : "obj-33",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0 0 0 0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 75.0, 552.0, 68.0, 20.0 ],
									"id" : "obj-34",
									"fontname" : "Arial",
									"numinlets" : 4
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "swatch",
									"numoutlets" : 2,
									"outlettype" : [ "", "float" ],
									"patching_rect" : [ 109.0, 424.0, 241.0, 98.0 ],
									"compatibility" : 1,
									"id" : "obj-35",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/label $1 $2 $3 $4",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 75.0, 575.0, 236.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/solo $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 543.0, 100.0, 184.0, 18.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/lock $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 514.0, 50.0, 184.0, 18.0 ],
									"id" : "obj-30",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 463.0, 314.0, 39.0, 20.0 ],
									"id" : "obj-29",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 486.0, 471.0, 39.0, 20.0 ],
									"id" : "obj-28",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/front LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 552.0, 434.0, 170.0, 18.0 ],
									"id" : "obj-24",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/back LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 552.0, 407.0, 171.0, 18.0 ],
									"id" : "obj-25",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/backward LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 552.0, 380.0, 197.0, 18.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/forward LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 552.0, 353.0, 186.0, 18.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/front",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 506.0, 282.666656, 170.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/back",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 506.0, 255.666656, 171.0, 18.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/backward",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 506.0, 228.666672, 197.0, 18.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/LAYER_0/forward",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 506.0, 201.0, 186.0, 18.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 212.0, 142.0, 20.0, 20.0 ],
									"id" : "obj-16",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak s i",
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"outlettype" : [ "" ],
									"patching_rect" : [ 151.0, 169.0, 45.0, 20.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"numoutlets" : 3,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "", "" ],
									"items" : [ "all", ",", "wireframe", ",", "axis", ",", "info" ],
									"types" : [  ],
									"patching_rect" : [ 112.0, 142.0, 97.0, 20.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/debug $1 $2",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 151.0, 193.0, 212.0, 18.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "umenu",
									"numoutlets" : 3,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "", "" ],
									"items" : [ "center", ",", "fill", ",", "fit", ",", "stretch" ],
									"types" : [  ],
									"patching_rect" : [ 179.0, 306.0, 71.0, 20.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/*/stretchmode $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 179.0, 336.0, 227.0, 18.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/delete LAYER_0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 79.75, 67.0, 178.0, 18.0 ],
									"id" : "obj-1",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/new LAYER_0 100 100",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 64.75, 43.0, 213.0, 18.0 ],
									"id" : "obj-3",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 10.0, 364.0, 39.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/layers/dump",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 49.75, 19.0, 124.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-44", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-41", 0 ],
									"destination" : [ "obj-44", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-39", 0 ],
									"destination" : [ "obj-30", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-40", 0 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-30", 0 ],
									"destination" : [ "obj-36", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-36", 0 ],
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
									"source" : [ "obj-34", 0 ],
									"destination" : [ "obj-4", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-34", 0 ],
									"hidden" : 0,
									"midpoints" : [ 118.5, 528.0, 84.5, 528.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-33", 0 ],
									"destination" : [ "obj-34", 3 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-23", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-21", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-24", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-28", 0 ],
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
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-28", 0 ],
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
									"source" : [ "obj-13", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-13", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-10", 1 ],
									"destination" : [ "obj-13", 0 ],
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
									"source" : [ "obj-7", 1 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [ 214.5, 332.0, 188.5, 332.0 ]
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
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "// general canvas controls",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 76.0, 9.0, 150.0, 20.0 ],
					"id" : "obj-30",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p canvas",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 12.0, 12.0, 59.0, 20.0 ],
					"id" : "obj-26",
					"fontname" : "Arial",
					"numinlets" : 0,
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 5,
							"minor" : 1,
							"revision" : 9
						}
,
						"rect" : [ 762.0, 352.0, 678.0, 525.0 ],
						"bglocked" : 0,
						"defrect" : [ 762.0, 352.0, 678.0, 525.0 ],
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
									"numoutlets" : 2,
									"fontsize" : 12.0,
									"outlettype" : [ "int", "bang" ],
									"patching_rect" : [ 39.0, 423.0, 50.0, 20.0 ],
									"id" : "obj-31",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "FPS",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 91.0, 423.0, 34.0, 20.0 ],
									"id" : "obj-17",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/fps $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 39.0, 448.0, 131.0, 18.0 ],
									"id" : "obj-26",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 39.0, 477.0, 39.0, 20.0 ],
									"id" : "obj-28",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "MSAA",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 345.0, 116.0, 45.0, 20.0 ],
									"id" : "obj-16",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Fullscreen",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 345.0, 28.0, 66.0, 20.0 ],
									"id" : "obj-7",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Size",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 82.0, 23.0, 34.0, 20.0 ],
									"id" : "obj-6",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "Position",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 82.0, 227.0, 53.0, 20.0 ],
									"id" : "obj-5",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 322.0, 391.0, 39.0, 20.0 ],
									"id" : "obj-38",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "alpha",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 615.0, 325.0, 40.0, 20.0 ],
									"id" : "obj-37",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "slider",
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"size" : 256.0,
									"patching_rect" : [ 371.0, 326.0, 241.0, 18.0 ],
									"id" : "obj-29",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pak 0 0 0 0",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 322.0, 347.0, 68.0, 20.0 ],
									"id" : "obj-27",
									"fontname" : "Arial",
									"numinlets" : 4
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "swatch",
									"numoutlets" : 2,
									"outlettype" : [ "", "float" ],
									"patching_rect" : [ 356.0, 219.0, 241.0, 98.0 ],
									"compatibility" : 1,
									"id" : "obj-35",
									"numinlets" : 3
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/background $1 $2 $3 $4",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 322.0, 370.0, 225.0, 18.0 ],
									"id" : "obj-4",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 322.0, 117.0, 20.0, 20.0 ],
									"id" : "obj-9",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/msaa $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 322.0, 141.0, 144.0, 18.0 ],
									"id" : "obj-13",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 322.0, 170.0, 39.0, 20.0 ],
									"id" : "obj-15",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 100.5 100.54",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 252.0, 217.0, 18.0 ],
									"id" : "obj-8",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "toggle",
									"numoutlets" : 1,
									"outlettype" : [ "int" ],
									"patching_rect" : [ 322.0, 29.0, 20.0, 20.0 ],
									"id" : "obj-25",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/fullscreen $1",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 322.0, 53.0, 165.0, 18.0 ],
									"id" : "obj-23",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 322.0, 82.0, 39.0, 20.0 ],
									"id" : "obj-22",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 35.0, 358.0, 39.0, 20.0 ],
									"id" : "obj-18",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 400 400",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 324.0, 185.0, 18.0 ],
									"id" : "obj-19",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 100 100",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 276.0, 202.0, 18.0 ],
									"id" : "obj-20",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/position 200 200",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 300.0, 185.0, 18.0 ],
									"id" : "obj-21",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "s osc",
									"numoutlets" : 0,
									"fontsize" : 12.0,
									"patching_rect" : [ 35.0, 127.0, 39.0, 20.0 ],
									"id" : "obj-14",
									"fontname" : "Arial",
									"numinlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 3072 768",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 93.0, 172.0, 18.0 ],
									"id" : "obj-12",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 1024 768",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 47.0, 172.0, 18.0 ],
									"id" : "obj-11",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "/livedraw/canvas/size 2048 768",
									"numoutlets" : 1,
									"fontsize" : 11.595187,
									"outlettype" : [ "" ],
									"patching_rect" : [ 82.0, 70.0, 172.0, 18.0 ],
									"id" : "obj-10",
									"fontname" : "Arial",
									"numinlets" : 2
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-9", 0 ],
									"destination" : [ "obj-13", 0 ],
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
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-18", 0 ],
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
									"source" : [ "obj-10", 0 ],
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
									"source" : [ "obj-19", 0 ],
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
									"source" : [ "obj-20", 0 ],
									"destination" : [ "obj-18", 0 ],
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
									"source" : [ "obj-25", 0 ],
									"destination" : [ "obj-23", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
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
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [ 365.5, 323.0, 331.5, 323.0 ]
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
									"source" : [ "obj-4", 0 ],
									"destination" : [ "obj-38", 0 ],
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
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "r osc",
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"outlettype" : [ "" ],
					"patching_rect" : [ 26.0, 147.0, 37.0, 20.0 ],
					"id" : "obj-13",
					"fontname" : "Arial",
					"numinlets" : 0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "udpsend 127.0.0.1 5433",
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patching_rect" : [ 76.0, 198.0, 140.0, 20.0 ],
					"id" : "obj-1",
					"fontname" : "Arial",
					"numinlets" : 1
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-13", 0 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
