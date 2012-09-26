### Layer Properties

### Layer Source Player

```
/livedraw/layers/(LAYER_NAME)/source buffer ASSET_ID [FROM_DISK]

/livedraw/layers/(LAYER_NAME)/source start
/livedraw/layers/(LAYER_NAME)/source pause
/livedraw/layers/(LAYER_NAME)/source stop
/livedraw/layers/(LAYER_NAME)/source loopmode     {LIVE, LOOP, PALINDROME}

/livedraw/layers/(LAYER_NAME)/source frame              FRAME
/livedraw/layers/(LAYER_NAME)/source framen             FRAME_NORM

/livedraw/layers/(LAYER_NAME)/source looppointsn        START_POINT_NORM END_POINT_NORM
/livedraw/layers/(LAYER_NAME)/source looppointstartn   START_POINT_NORM
/livedraw/layers/(LAYER_NAME)/source looppointendn     START_POINT_NORM

/livedraw/layers/(LAYER_NAME)/source looppoints        START_POINT END_POINT
/livedraw/layers/(LAYER_NAME)/source looppointstart    START_POINT
/livedraw/layers/(LAYER_NAME)/source looppointsend     START_POINT

/livedraw/layers/(LAYER_NAME)/source looppointsn       START_POINT_NORM END_POINT_NORM
/livedraw/layers/(LAYER_NAME)/source looppointstartn   START_POINT_NORM
/livedraw/layers/(LAYER_NAME)/source looppointendn     START_POINT_NORM

/livedraw/layers/(LAYER_NAME)/source speed    PLAYBACK_RATE
```

### Layer Mask / Second Source

Layer masks are simply sources that are treated as masks / second sources.  While usually just a static image source, the mask sources can be as complex as a normal source. 90% Complete (7 Mar 11)

```
/livedraw/layers/(LAYER_NAME)/mask ... (see source reference above)
```


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

    /livedraw/canvas/group/new       GROUP_NAME
    /livedraw/canvas/group/delete    GROUP_NAME

## Canvas Group-wise Commands

Canvas groups can be labeled to allow easier onscreen visibility. *10% Complete (7 Mar 11)*

> **TODO**
>
> 1. Implement a tag-based system for grouping.  This affects the next few items related to "grouping" below.

    /livedraw/canvas/group/(GROUP_NAME)/label    R G B [A]

### Adding Items to Groups

Layers can be added to groups.  *10% Complete (7 Mar 11)*

    /livedraw/canvas/group/(GROUP_NAME)/add/layer    LAYER_NAME
    /livedraw/canvas/group/(GROUP_NAME)/add/layers    LAYER_NAME_0 ... LAYER_NAME_N

### Removing Items from Groups 

Layers can be removed from groups. *10% Complete (7 Mar 11)*

    /livedraw/canvas/group/(GROUP_NAME)/remove/layer    LAYER_NAME

    /livedraw/canvas/group/(GROUP_NAME)/remove/layers    LAYER_NAME_0 ... LAYER_NAME_N

In later versions, groups can become subgroups of other groups. *0% Complete (7 Mar 11)*

    /livedraw/canvas/group/(GROUP_NAME)/remove/group    GROUP_NAME
    /livedraw/canvas/group/(GROUP_NAME)/remove/groups    GROUP_NAME_0 ... GROUP_NAME_N

### Group-wise Transforms

> **TODO**
>
> 1. Group-wise transformations are now carried out through the layered rendering tree.  Child nodes are subject to their parent transformations.

Group-wise transformations are applied _in addition_ to the layer-wise transformations.  Layer-wise transformations are carried out _inside_ of group-wise transformations. *10% Complete (7 Mar 11)*

    /livedraw/canvas/group/(GROUP_NAME)/transform/show    B_SHOW [EASING_DURATION] [EASING_TYPE]

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
#### Aliasing     and IDs

Normally asset IDs are set automatically and conformed to OSC namespace friendly naming specs (i.e. no ' ', #, *, , / ?  [ ] { }).  When automatically generating these source IDs, all illegal characters are replaced with underscores '_'.  e.g.

    A movie file called "Animated Robot[22].mov" would become "Animated-Robot-22-.mov".

Alternatively, if the file has associated meta-data that includes a pre-defined SOURCE_ID, that source ID will be used.

    /livedraw/media/alias    ORIGINAL_ASSET_ID NEW_ASSET_ID
    
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
    /livedraw/media/(ASSET_ID)/record    ASSET_ID [TYPE NUM] (TYPE : frames OR time) Time is in ms
    /livedraw/media/(ASSET_ID)/stop
    
    /livedraw/media/(ASSET_ID)/clear
    /livedraw/media/(ASSET_ID)/size         NEW_MAX_SIZE
    /livedraw/media/(ASSET_ID)/framerate  FRAMERATE
    /livedraw/media/(ASSET_ID)/type          BUFFER_TYPE (FIXED, CIRCULAR, PASSTHROUGH)
    /livedraw/media/(ASSET_ID)/usetexture B_USE_TEXTURE
    
    
#### Camera Settings *90% Complete (11 Mar 11)*

Camera settings can be changed via OSC.

    /livedraw/media/(ASSET_ID)/settings [KEY VALUE_0 [VALUE_1 ... VALUE_N]]

#### Camera Capture

Camera capture is user controllable. *85% Complete (11 Mar 11)*

    /livedraw/media/(ASSET_ID)/open    [CAPTURE_WIDTH CAPTURE_HEIGHT]
    /livedraw/media/(ASSET_ID)/close
    /livedraw/media/(ASSET_ID)/size [CAPTURE_WIDTH CAPTURE_HEIGHT]

#### Assigning Metadata

All source material can be assigned meta data using the (KEY) VALUE_0 sets. *40% Complete (11 Mar 11)*

    /livedraw/media/(ASSET_ID)/metadata/add keywords    VALUE_0 [VALUE_1 ... VALUE_N]
    /livedraw/media/(ASSET_ID)/metadata/remove keywords    VALUE_0 [VALUE_1 ... VALUE_N]
    /livedraw/media/(ASSET_ID)/metadata/description "Description"
    

For example, one might set the tags associated with a given clip using the following syntax:

    /livedraw/media/VID_00982/metadata/tags    fast scary colorful people






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

    /livedraw/session/presets/new        PRESET_NAME
    /livedraw/session/presets/delete    PRESET_NAME
    /livedraw/session/presets/store        PRESET_NAME
    /livedraw/session/presets/load        PRESET_NAME

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
    /livedraw/session/performance/control/goto    TIMESTAMP


### GUI Layout

GUI layouts can be save and are addressable: *75% Complete (7 Mar 11)*

    /livedraw/layout/new    LAYOUT_NAME
    /livedraw/layout/delete    LAYOUT_NAME
    /livedraw/layout/store    LAYOUT_NAME
    /livedraw/layout/load    LAYOUT_NAME

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


