# ofxLivedrawEngine OSC Command Specification
## Document Syntax
* Optional arguments are in brackets e.g. [OPTIONAL_ITEM]
* Variable or named items are in parenthesis e.g. (LAYER_NAME)
* Variables in the namespace can be addressed as groups (see _OSC Message Dispatching and Pattern Matching_ in the [OSC Spec 1.0](http://opensoundcontrol.org/spec-1_0)).

## Standard Units, Scaling, etc.
* Colors and numbers are generally in an absolute range, unless explicitly described as normalized (i.e. 0.0-1.0).  Some values can be set by issuing "normalized" commands.  For instance, when placing an anchor point, one can set normalized positions, which are determined based on the absolute width / height of the image.
* Likewise, colors are normally expected in an 0-255 range, but can be set explicitly in a 0.0-1.0 range.  
* Angles are expected degrees (0-360).
* Often namespace items have been given shortcuts.  For example, `/livedraw/media/` can be shortened to `/l/m/`.  These node aliases are noted below, but the full namespace will be used below. 

## Basic Concepts

### Media
* Media assets are loaded from a media folder, usually located in `data/media`.  * Video cameras are defined in a file called `grabbers.xml`.  In the future, these cameras will be available dynamically, rather than via the `xml` config.  This is due to a few limitations within openFrameworks.
* Streaming video (i.e. MJPEG, IPcameras, etc) are defined in a file called `streams.xml`.  MJPEG (IPCamera), RTSP and online Quicktime Movies are supported. 
* Syphon Streams are detected automatically on the local system.
* All other media assets, including video and images are detected via file name extensions.  Most common media file types are recognized.

### Assets
* An asset is any item within the Livedraw Engine world that can _sink_ or _source_ or _is playable_ (see below).  Some asset types have multiple abilities.

|Asset Type|Is Sink?|Is Source?|Is Playable?|Notes|
|:-:|:-:|:-:|:-:|:--|
|&nbsp;|*Can it receive and<br/> process shared frames?*|*Can this asset send<br/>shared frames?*|*Can this Asset Type be "Played"<br/>by a Player Asset*|&nbsp;|
|**Image Asset**  |✔|✗|✔|An image asset is simply a single shared frame, usually loaded from disk.|
|**Movie Asset**  |✗|✗|✔|A movie asset is a disk based asset that can be a source only when it is "played" with a player asset.|
|**Grabber Asset**|✗|✔|✗|A grabber is a camera or frame grabber capable of providing "live" frames to a sink.|
|**Streaming Asset** |✗|✔|✗|A streaming asset is like a grabber, but comes from a network source.|
|**Syphon Asset** |✗|✔|✗|A Syphon asset is much like a grabber or a streaming asset.|
|**Buffer Asset** |✔|✗|✔|A buffer asset is a collection of frames with a certain size and other properties.  It can _sink_ frames from any source (if it has room) and can only be a source if it is played with a _player asset_.|
|**Player Asset** |✗|✔|✗|A player asset is a controllable source, but must "play" a playable asset in order to be a valid _source_.  If no playable asset is loaded, it will deliver blank frames to all attached _sinks_.|
|**Layer Asset**  |✔|✔|✗|A composition layer asset can _sink_ frames via its inputs and masks and can also become a _source_ for other _sinks_.  This allows for complex feedback and video effects.|


### Naming
* All assets are named.  These names can be changed and allow easier access (as opposed of using long filenames, or hardware addresses).  Assets are automatically assigned names when they are loaded or created.  Users can specify specific names during creation.  If the name exists, the asset will be assigned a new name.  For instance, if the name `myimage` is already taken, the `myimage` would be changed to `myimage_0`.  Subsequently the numerical suffix is incremented.


### Sinks and Sources 
* At the core of the Livedraw Engine is a complex media and frame sharing system that seeks to increase speed by reduce unnecessary disk reads (i.e. playing a video file from disk) and leveraging the GPU.  
* To achieve this goal Livedraw Engine employs the concept of _sources_ and _sinks_.  
* _Sources_ are a smart objects that can provide shared frames that can be played, manipulated, buffered or saved.  A Webcam is a good example of a _source_ as it provides a stream of frames that can be used or ignored.  Each frame _source_ can be connected to any number of _sinks_.  Sources keep track of their attached _sinks_ and in the event of a source closing, all of the attached _sinks_ will be alerted and can take appropriate action.
* _Sinks_ are objects that can _do_ something with the shared frames that come from _sources_.  For instance, a video buffer is a _sink_ because it can _do_ something with the incoming frame -- namely it can store it in a specified way.  In Livedraw Engine a Layer also contains several _sinks_.  A layer's _sinks_ listen for incoming shared frames and _does_ something with them -- namely it composites, positions, and then renders the results to a canvas.
* Shared frames keep track of themselves.  If no _sinks_ are currently storing or using them they destroy themselves.  _Sources_ are not required to store their shared frames.  In most cases, after they have been _sinked_, the _source_ releases the frame to the care of the _sinks_ that will do something with it.
* Generally, _sinks_ cannot "_source_" (i.e. receive) shared frames from multiple _sources_, but _sources_ can "_source_" (i.e. send) their frames to an endless number of _sinks_. 

### Playable


# Livedraw
The root _Livedraw_ node is the primary jumping off point for the rest of the commands.

#### Node Aliases

	/livedraw
	/ld
	/l

# Canvas
The _Canvas_ is the primary location for rendering.  The canvas might occupy the entire program window, or a subsection of the window.  This is application dependent.  The basic ofxLivedrawEngine addon treats the whole window as a canvas.

#### Node Aliases

	/canvas
	/can
	/c
	
## Canvas Controls

Meta controls affect the entire canvas.

_Position_ controls the location of the rendering canvas in desktop screen space.

	/livedraw/canvas/position X_POSITION Y_POSITION


_Size_ controls the size (in pixels) of the rendering canvas in desktop screen space.

	/livedraw/canvas/size WIDTH HEIGHT

_Background_ sets the default refresh background color.

	/livedraw/canvas/background	R G B [A]

_Fullscreen_ toggles fullscreen mode on the rendering canvas.  This is for full-screen exclusive mode and will fill the entirety of the canvas' current context.

	/livedraw/canvas/fullscreen B_FS

_MSAA_ toggles multisample anti-aliasing.

	/livedraw/canvas/msaa B_MSAA
	
_FPS_ sets the global rendering frame rate.

	/livedraw/canvas/fps FPS


# Layers

Composition layers represent a set of inputs and (optionally) a corresponding set of masks.  Currently there can be pairs of input/masks per layer.  This allows A<->B style mixing between pairs.  Each input and mask acts as a _sink_ and must receive frames from a _source_.  Layers can have parent layers and child layers.  Child layers inherit transformation properties (like rotation, scaling, etc) from their parent layer.  At the base of the layer tree is a root layer.  Many layers can reside on the root layer and are only subject to their own transformations.  Layer render order is determined by a layer's location in the tree structure.  Layers can also be cloned -- that is -- rendered in the same location, but have multiple parents.  A layer can have many parents parent and many children.


## Layer Creation and Destruction

	/livedraw/layers/new	LAYER_NAME [X_POSITION Y_POSITION [Z_POSITION]]
	/livedraw/layers/delete	LAYER_NAME

## Layer Transforms

#### Node Aliases

	/transform
	/xform
	/t

## Anchor Point

Layer anchor points determine how a layer is stretched and rotated. *100% Complete*

	/livedraw/layers/(LAYER_NAME)/transform/anchorpoint X_ANCHORPOINT [Y_ANCHORPOINT [Z_ANCHORPOINT]] 
	/livedraw/layers/(LAYER_NAME)/transform/anchorpoint X X_ANCHORPOINT 
	/livedraw/layers/(LAYER_NAME)/transform/anchorpoint Y Y_ANCHORPOINT 
	/livedraw/layers/(LAYER_NAME)/transform/anchorpoint Z Z_ANCHORPOINT 

#### Layer Position

Layer position layer position determines the layer's placement on the rendering canvas. *100% Complete*

	/livedraw/layers/(LAYER_NAME)/transform/position X_POSITION [Y_POSITION [Z_POSITION]]
	/livedraw/layers/(LAYER_NAME)/transform/position X X_POSITION
	/livedraw/layers/(LAYER_NAME)/transform/position Y Y_POSITION
	/livedraw/layers/(LAYER_NAME)/transform/position Z Z_POSITION

#### Layer Rotation

Layer rotation determines the layer's rotation on the rendering canvas and given it's current anchor point. *100% Complete*

	/livedraw/layers/(LAYER_NAME)/transform/rotate DEGREES X_AMOUNT Y_AMOUNT Z_AMOUNT
	/livedraw/layers/(LAYER_NAME)/transform/rotate X_ROTATE Y_ROTATE [Z_ROTATE]
	/livedraw/layers/(LAYER_NAME)/transform/rotate X X_ROTATE
	/livedraw/layers/(LAYER_NAME)/transform/rotate Y Y_ROTATE
	/livedraw/layers/(LAYER_NAME)/transform/rotate Z Z_ROTATE

Layer orientation determines the layer's orientation on the rendering canvas and given it's current anchor point.  (N.B. Similar to Adobe After Effects and may be removed) *50% Complete*

> **TODO**
>
> 1. Do we need "orientation"?

	/livedraw/layers/(LAYER_NAME)/transform/orientation X_ORIENTATION [Y_ORIENTATION [Z_ORIENTATION]]
	/livedraw/layers/(LAYER_NAME)/transform/orientation X X_ORIENTATION
	/livedraw/layers/(LAYER_NAME)/transform/orientation Y Y_ORIENTATION
	/livedraw/layers/(LAYER_NAME)/transform/orientation Z Z_ORIENTATION

Scale determines the layer's scale *100% Complete*

	/livedraw/layers/(LAYER_NAME)/transform/scale X_SCALE [Y_SCALE [Z_SCALE]]
	/livedraw/layers/(LAYER_NAME)/transform/scale X X_SCALE
	/livedraw/layers/(LAYER_NAME)/transform/scale Y Y_SCALE
	/livedraw/layers/(LAYER_NAME)/transform/scale Z Z_SCALE

#### Layer Opacity

Layer opacity determines how transparent a given layer is on the rendering canvas.  Opacity affects the way that a given layer will blend. Layer rotation determines the layer's rotation on the rendering canvas and given it's current anchor point. *100% Complete*  Opacity ranges from 0-255.

	/livedraw/layers/(LAYER_NAME)/transform/opacity OPACITY



### Layer Properties

Individual layers have stacking order, they can be locked, soloed or assigned a color for easy organization. *75% Complete*

> **TODO**
>
> 1. Finish implementing in CanvasLayerManager.h/.cpp and CanvasLayer.h/.cpp.

	/livedraw/layers/(LAYER_NAME)/order ORDER_NUM
	/livedraw/layers/(LAYER_NAME)/order forward
	/livedraw/layers/(LAYER_NAME)/order backward
	/livedraw/layers/(LAYER_NAME)/order front
	/livedraw/layers/(LAYER_NAME)/order back

	/livedraw/layers/(LAYER_NAME)/solo	B_SOLO
	/livedraw/layers/(LAYER_NAME)/lock	B_LOCK
	/livedraw/layers/(LAYER_NAME)/label	R G B [A]


### Layer Source

Layers are assigned sources from the source library.  These sources each have IDs and are addressed by their individual SOURCE_ID.  SOURCE_IDs can be set and changed by the user.  Sources can also represent linked or shared between layers to improve efficiency and create multiple effects. *89% Complete*

> **TODO**
>
> 1. Finish shared stream concept and create a more generic media asset interface (in progress).
> 1. Finish "linking" interface.

	/livedraw/layers/(LAYER_NAME)/input/linked	LAYER_NAME_FROM

	/livedraw/layers/(LAYER_NAME)/input/file 	SOURCE_ID [WIDTH HEIGHT [COLORSPACE]]
	/livedraw/layers/(LAYER_NAME)/input/stream 	SOURCE_ID [WIDTH HEIGHT [COLORSPACE]]
	/livedraw/layers/(LAYER_NAME)/input/hardware 	SOURCE_ID [WIDTH HEIGHT [COLORSPACE]]
	/livedraw/layers/(LAYER_NAME)/input/syphon 	SOURCE_ID [WIDTH HEIGHT [COLORSPACE]]

### Layer Source Player

The source player is a complex playback controller/looper/sampler that is created for a given source. *95% Complete*

> **TODO**
>
> 1. "loadram" load entire video (or selection) into a sharable sampler / buffer.
> 1. "loadram" equivalent for streaming sources, such as live video into sharable sampler / buffer.
> 1. Finish player code to implement all items below.

	/livedraw/layers/(LAYER_NAME)/source buffer ASSET_ID [FROM_DISK]

	/livedraw/layers/(LAYER_NAME)/source start
	/livedraw/layers/(LAYER_NAME)/source pause
	/livedraw/layers/(LAYER_NAME)/source stop
	/livedraw/layers/(LAYER_NAME)/source loopmode	{LIVE, LOOP, PALINDROME}

	/livedraw/layers/(LAYER_NAME)/source frame	    FRAME
	/livedraw/layers/(LAYER_NAME)/source framen	    FRAME_NORM

	/livedraw/layers/(LAYER_NAME)/source looppointsn	    START_POINT_NORM END_POINT_NORM
	/livedraw/layers/(LAYER_NAME)/source looppointstartn	    START_POINT_NORM
	/livedraw/layers/(LAYER_NAME)/source looppointendn	    START_POINT_NORM

	/livedraw/layers/(LAYER_NAME)/source looppoints	    START_POINT END_POINT
	/livedraw/layers/(LAYER_NAME)/source looppointstart	    START_POINT
	/livedraw/layers/(LAYER_NAME)/source looppointsend	    START_POINT

	/livedraw/layers/(LAYER_NAME)/source looppointsn	    START_POINT_NORM END_POINT_NORM
	/livedraw/layers/(LAYER_NAME)/source looppointstartn	    START_POINT_NORM
	/livedraw/layers/(LAYER_NAME)/source looppointendn	    START_POINT_NORM

	/livedraw/layers/(LAYER_NAME)/source speed	PLAYBACK_RATE

### Layer Mask / Second Source

Layer masks are simply sources that are treated as masks / second sources.  While usually just a static image source, the mask sources can be as complex as a normal source. 90% Complete (7 Mar 11)

	/livedraw/layers/(LAYER_NAME)/mask ... (see source reference above)



### Layer Effects *10% Complete (11 Mar 11)*

Layer effects are modules that affect the visible qualities of a layer.  These are generally GPU shader-based effects. 
> **TODO**
>
> 1. Finish implementing effects
> 1. Alpha blending (shader based work exists in other sketches)

	/livedraw/layers/(LAYER_NAME)/effects/(EFFECT_NAME)/(INSTANCE_NUM)/(KEY) VALUE_0 [VALUE_1 ... VALUE_N]

e.g for a LAYER_NAME called BACKGROUND and and EFFECT_NAME called GAUSSIAN_BLUR you might use
 
	/livedraw/layers/BACKGROUND/effects/GAUSSIAN_BLUR/0/blur 50.0 40.0

Each effect will define its specific OSC addressing on the [[OSC Effects Command Set]]

TODO: Generally these effects are shaders but can also include pixel-based Freeframe plugins etc.

## Canvas Groups				

Canvas groups allow layers to be gathered into logical groupings.  Each layer can only belong to one group. *100% Complete (7 Mar 11)*

> **TODO**
>
> 1. Grouping has been removed, in favor of tagging and a full tree-structure for rendering canvas layers.  Canvas layers inherit transforms from parents.

	/livedraw/canvas/group/new   	GROUP_NAME
	/livedraw/canvas/group/delete	GROUP_NAME

## Canvas Group-wise Commands

Canvas groups can be labeled to allow easier onscreen visibility. *10% Complete (7 Mar 11)*

> **TODO**
>
> 1. Implement a tag-based system for grouping.  This affects the next few items related to "grouping" below.

	/livedraw/canvas/group/(GROUP_NAME)/label	R G B [A]

### Adding Items to Groups

Layers can be added to groups.  *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/add/layer	LAYER_NAME
	/livedraw/canvas/group/(GROUP_NAME)/add/layers	LAYER_NAME_0 ... LAYER_NAME_N

### Removing Items from Groups 

Layers can be removed from groups. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/remove/layer	LAYER_NAME

	/livedraw/canvas/group/(GROUP_NAME)/remove/layers	LAYER_NAME_0 ... LAYER_NAME_N

In later versions, groups can become subgroups of other groups. *0% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/remove/group	GROUP_NAME
	/livedraw/canvas/group/(GROUP_NAME)/remove/groups	GROUP_NAME_0 ... GROUP_NAME_N

### Group-wise Transforms

> **TODO**
>
> 1. Group-wise transformations are now carried out through the layered rendering tree.  Child nodes are subject to their parent transformations.

Group-wise transformations are applied _in addition_ to the layer-wise transformations.  Layer-wise transformations are carried out _inside_ of group-wise transformations. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/transform/show	B_SHOW [EASING_DURATION] [EASING_TYPE]

#### Group-wise Anchor Point

This is an anchor point that is measured by the offset from the upper-left-hand corner of the group's bounding box.  Thus, unless specified otherwise, the anchor point must be adjusted if new layers are added to a group. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/transform/anchorpoint X_ANCHOR [Y_ANCHOR [Z_ANCHOR]]
	/livedraw/canvas/group/(GROUP_NAME)/transform/anchorpoint X X_ANCHOR
	/livedraw/canvas/group/(GROUP_NAME)/transform/anchorpoint Y Y_ANCHOR
	/livedraw/canvas/group/(GROUP_NAME)/transform/anchorpoint Z Z_ANCHOR

Thus, to reset an anchor point you would use:

	/livedraw/canvas/group/(GROUP_NAME)/transform/anchor_point 0 0 0

#### Group-wise Position

This position is based upon the anchor point above. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/transform/position X_POSITION [Y_POSITION [Z_POSITION]]
	/livedraw/canvas/group/(GROUP_NAME)/transform/position X X_POSITION
	/livedraw/canvas/group/(GROUP_NAME)/transform/position Y Y_POSITION
	/livedraw/canvas/group/(GROUP_NAME)/transform/position Z Z_POSITION

#### Group-wise Rotation *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/transform/rotate DEGREES X_AMOUNT Y_AMOUNT Z_AMOUNT
	/livedraw/canvas/group/(GROUP_NAME)/transform/rotate X_ROTATE Y_ROTATE [Z_ROTATE]
	/livedraw/canvas/group/(GROUP_NAME)/transform/rotate X X_ROTATE
	/livedraw/canvas/group/(GROUP_NAME)/transform/rotate Y Y_ROTATE
	/livedraw/canvas/group/(GROUP_NAME)/transform/rotate Z Z_ROTATE

#### Group-wise Opacity 

Individual layer opacities are computed as a function of their group-wise opacity and their individual layer opacity. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/transform/opacity OPACITY

#### Group Level Layer Addressing

More complex control of layers can be carried out using Group-Level Layer addressing. *10% Complete (7 Mar 11)*

	/livedraw/canvas/group/(GROUP_NAME)/(LAYER_NAME)/ ...

For example, to control all groups that start with AX* and all Layers within those groups that start with BB* one might issue a command such as: *5% Complete (7 Mar 11)*

	/livedraw/canvas/group/AX*/BB*/transform/x 88

This command would move all of the selected groups' anchor points to an x-position of 88 pixels.

### Parameter Animation *5% Complete (7 Mar 11)*

> **TODO**
>
> 1. As above, we need a way to animate parameters.

Parameter animation is carried out by defining an animation recording session.  Any transform parameter on a layer or group can be animated with this syntax.  Additionally, any parameter used to control a layer effect can be similarly animated. e.g.

	/livedraw/layers/(LAYER_NAME)/transform/(PARAMETER)/animate record
	/livedraw/layers/(LAYER_NAME)/transform/(PARAMETER)/animate stop
	/livedraw/layers/(LAYER_NAME)/transform/(PARAMETER)/animate play [{NONE, LOOP, PALINDROME}]

Group parameters and layer effects follow a similar OSC pattern syntax.

For example, to animate the position and scale of a layer called MY_LAYER, the following OSC commands would be sent:

> **TODO**
>
> 1. Implement a bundle based processing.

	[begin OSC bundle]
	/livedraw/layers/MY_LAYER/transform/position/animate record
	/livedraw/layers/MY_LAYER/transform/scale/animate record
	[end OSC bundle]

	[begin OSC bundle]
	/livedraw/layers/MY_LAYER/transform/scale 1.0 1.0
	/livedraw/layers/MY_LAYER/transform/position 100.0 100.0
	[end OSC bundle]

	[begin OSC bundle]
	/livedraw/layers/MY_LAYER/transform/scale 1.1 1.1
	/livedraw/layers/MY_LAYER/transform/position 200.0 200.0
	[end OSC bundle]

	...

	[begin OSC bundle]
	/livedraw/layers/MY_LAYER/transform/scale 2.0 2.0
	/livedraw/layers/MY_LAYER/transform/position 1000.0 1000.0
	[end OSC bundle]

	[begin OSC bundle]
	/livedraw/layers/MY_LAYER/transform/scale/animate stop
	/livedraw/layers/MY_LAYER/transform/position/animate stop
	[end OSC bundle]

To replay the animation:

	/livedraw/layers/MY_LAYER/transform/scale/animate play loop
	/livedraw/layers/MY_LAYER/transform/position/animate play loop


### media
#### Aliasing 	and IDs

Normally asset IDs are set automatically and conformed to OSC namespace friendly naming specs (i.e. no ' ', #, *, , / ?  [ ] { }).  When automatically generating these source IDs, all illegal characters are replaced with underscores '_'.  e.g.

	A movie file called "Animated Robot[22].mov" would become "Animated-Robot-22-.mov".

Alternatively, if the file has associated meta-data that includes a pre-defined SOURCE_ID, that source ID will be used.

	/livedraw/media/alias	ORIGINAL_ASSET_ID NEW_ASSET_ID
	
Generated Asset Id's will follow the convention of source-type_source-name; for example:

    Animated Robot[22].mov    >>>   movie_NAME
    Mask.png                  >>>   image_NAME
    USB camera #2             >>>   grabber_NAME (use OpenFrameworks/QuickTime indexing)
    syphon source "tex69"     >>>   syphon_NAME
    IP camera named "ipcam3"  >>>   stream_NAME (use source name from streams.xml file)
    Recording Buffers         >>>   buffer_NAME
    Buffer Player             >>>   bufferplayer_NAME


### Buffers
#### Recording
	/livedraw/media/(ASSET_ID)/clear
	/livedraw/media/(ASSET_ID)/record	ASSET_ID [TYPE NUM] (TYPE : frames OR time) Time is in ms
	/livedraw/media/(ASSET_ID)/stop
	
	/livedraw/media/(ASSET_ID)/clear
	/livedraw/media/(ASSET_ID)/size   	  NEW_MAX_SIZE
	/livedraw/media/(ASSET_ID)/framerate  FRAMERATE
	/livedraw/media/(ASSET_ID)/type		  BUFFER_TYPE (FIXED, CIRCULAR, PASSTHROUGH)
	/livedraw/media/(ASSET_ID)/usetexture B_USE_TEXTURE
	
	
#### Camera Settings *90% Complete (11 Mar 11)*

Camera settings can be changed via OSC.

	/livedraw/media/(ASSET_ID)/settings [KEY VALUE_0 [VALUE_1 ... VALUE_N]]

#### Camera Capture

Camera capture is user controllable. *85% Complete (11 Mar 11)*

	/livedraw/media/(ASSET_ID)/open	[CAPTURE_WIDTH CAPTURE_HEIGHT]
	/livedraw/media/(ASSET_ID)/close
	/livedraw/media/(ASSET_ID)/size [CAPTURE_WIDTH CAPTURE_HEIGHT]

#### Assigning Metadata

All source material can be assigned meta data using the (KEY) VALUE_0 sets. *40% Complete (11 Mar 11)*

	/livedraw/media/(ASSET_ID)/metadata/add keywords	VALUE_0 [VALUE_1 ... VALUE_N]
	/livedraw/media/(ASSET_ID)/metadata/remove keywords	VALUE_0 [VALUE_1 ... VALUE_N]
	/livedraw/media/(ASSET_ID)/metadata/description "Description"
	

For example, one might set the tags associated with a given clip using the following syntax:

	/livedraw/media/VID_00982/metadata/tags	fast scary colorful people






# IN PROGRESS
---------------

# Session Control
## Presets

Session presets are useful for saving and loading all values to an external XML configuration file. *10% Complete*

> **TODO**
>
> 1. Persistence interface for all settable items (transforms, parameters, etc) 
> 1. Persistence I/O for XML, etc (will likely mirror the OSC and layer trees)
> 1. Design an XML schema for persistence.

	/livedraw/session/presets/new		PRESET_NAME
	/livedraw/session/presets/delete	PRESET_NAME
	/livedraw/session/presets/store		PRESET_NAME
	/livedraw/session/presets/load		PRESET_NAME

## Performance Creation and Storage

Performances are best thought of as a presets in motion.  During a recording session, changes to all values are recorded if recording is enabled. *10% Complete (7 Mar 11)*
> **TODO**
>
> 1. In addition to persistence items above, the persistence interface needs an "animatable" interface so each item can be animated. 

	/livedraw/session/performance/new    PERFORMANCE_NAME
	/livedraw/session/performance/delete PERFORMANCE_NAME
	/livedraw/session/performance/store  PERFORMANCE_NAME
	/livedraw/session/performance/load   PERFORMANCE_NAME

### Performance Playback and Control

Performances can be played back, recorded and navigated in very basic ways using the +goto TIMESTAMP+ syntax. *10% Complete*
> **TODO**
>
> 1. This would be built into the "animatable" interface.
 
	/livedraw/session/performance/control/record
	/livedraw/session/performance/control/play
	/livedraw/session/performance/control/stop
	/livedraw/session/performance/control/goto	TIMESTAMP


### GUI Layout

GUI layouts can be save and are addressable: *75% Complete (7 Mar 11)*

	/livedraw/layout/new	LAYOUT_NAME
	/livedraw/layout/delete	LAYOUT_NAME
	/livedraw/layout/store	LAYOUT_NAME
	/livedraw/layout/load	LAYOUT_NAME

Check out the [[Discussion items]] where we can discuss some unresolved/suggested concepts




-------

Layer parameters can be copied from on layer to another. *90% Complete*

> **TODO**
>
> 1. Interface needs to be implemented.  Could be integrated into the persistence / settings interface noted above.

	/livedraw/layers/(LAYER_NAME)/.../PARAM_NAME COPYFROM LAYER_NAME_FROM

e.g. Copy from Transform:

	/livedraw/layers/(LAYER_NAME)/transform/position X COPYFROM LAYER_NAME_FROM
or
	/livedraw/layers/(LAYER_NAME)/transform/position COPYFROM LAYER_NAME_FROM

e.g. Copy from Effect:

	/livedraw/layers/(LAYER_NAME)/effect/brcosa/brightness COPYFROM LAYER_NAME_FROM
of
	/livedraw/layers/(LAYER_NAME)/effect/brcosa COPYFROM LAYER_NAME_FROM


Layer parameters can be LINKED from on layer to another. *8% Complete (7 Mar 11)*

	/livedraw/layers/(LAYER_NAME)/.../PARAM_NAME LINKWITH LAYER_NAME_FROM

e.g. Copy from Transform:

	/livedraw/layers/(LAYER_NAME)/transform/position X LINKWITH LAYER_NAME_FROM

e.g. Copy from Effect:

	/livedraw/layers/(LAYER_NAME)/effect/brcosa/brightness LINKWITH LAYER_NAME_FROM


