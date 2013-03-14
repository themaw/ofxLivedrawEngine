# ofxLivedrawEngine OSC Command Specification
## Document Syntax
* Optional arguments are in brackets e.g. [OPTIONAL_ITEM]
* Variable or named items are in parenthesis e.g. (LAYER_NAME)
* Variables within an OSC address are group-addressable (see _OSC Message Dispatching and Pattern Matching_ in the [OSC Spec 1.0](http://opensoundcontrol.org/spec-1_0)) for more information.

## Standard Units, Scaling, etc.
* Colors and numbers are represented with an absolute 8 bit unsigned integer range (i.e. 0-255) for RGB and A channels.
* Some values can be set by issuing "normalized" commands (e.g. `anchorpointn` vs the normal `anchorpoint`).  In the case of an anchor point, for instance,  one can set normalized positions, which are determined based on the absolute pixel width / height of the image.
* Likewise, colors are normally expected in an 0-255 range, but can be set explicitly in a 0.0-1.0 range.
* Angles are represented in degrees ranging from 0-360.  Values below or above will roll over (i.e. 361 deg => 1 deg).

## Other notes.
* Often address nodes have shortcuts.  For example, `/livedraw/media/` can be shortened to `/l/m/`.  These address node aliases are noted in the documentation when available.


# /livedraw (`ld`, `l`)
The root _Livedraw_ node is the primary jumping off point for the rest of the commands.

# /livedraw/canvas (`canvas`,`can`,`c`)
The _Canvas_ is the primary location for rendering.  The canvas might occupy the entire program window, or a subsection of the window.  This is application dependent.  The basic Livedraw Engine treats the whole window as a canvas.
    
## Commands

### `position` controls the location of the rendering canvas in desktop screen space.

```
/livedraw/canvas/position X_POSITION Y_POSITION
```

### `size` controls the size (in pixels) of the rendering canvas in desktop screen space.

```
/livedraw/canvas/size WIDTH HEIGHT
```

### `background` sets the default refresh background color.

```
/livedraw/canvas/background    R G B [A]
```

### `fullscreen` toggles fullscreen mode on the rendering canvas.  This is for full-screen exclusive mode and will fill the entirety of the canvas' current context.

```
/livedraw/canvas/fullscreen B_FS
```

### `msaa` toggles multisample anti-aliasing.

```
/livedraw/canvas/msaa B_MSAA
```
    
### `fps` sets the global rendering frame rate.

```
/livedraw/canvas/fps FPS
```

# /livedraw/layers (`lay`,`l`)

Composition layers represent a set of inputs and (optionally) a corresponding set of masks.  Currently there can be pairs of input/masks per layer.  This allows A&harr;B style mixing between pairs.  Each input and mask acts as a _sink_ and must receive frames from a _source_.  Layers can have parent layers and child layers.  Child layers inherit transformation properties (like rotation, scaling, etc) from their parent layer.  At the base of the layer tree is a root layer.  Many layers can reside on the root layer and are only subject to their own transformations.  Layer render order is determined by a layer's location in the tree structure.  Layers can also be cloned -- that is -- rendered in the same location, but have multiple parents.  A layer can have many parents parent and many children.

Individual layers can be addressed by name.

## Commands
###`new` Create a new layer.

```
/livedraw/layers/new    LAYER_NAME [X_POSITION Y_POSITION [[Z_POSITION] [WIDTH] [HEIGHT]]
```

### `delete` Destroy a layer.

```
/livedraw/layers/delete    LAYER_NAME
```

### `dump` Dump layer data to the console.

```
/livedraw/layers/dump
```

### /livedraw/layers/(LAYER_NAME)/ 

Send commands to a named layer.

## Commands
### `input` controls the input sinks for the named layer.  Choose either A or B layer.

```
/livedraw/layers/(LAYER_NAME)/A/input/sink ASSET_NAME
/livedraw/layers/(LAYER_NAME)/A/input/unsink
/livedraw/layers/(LAYER_NAME)/A/input/clear
```

```
/livedraw/layers/(LAYER_NAME)/B/input/sink ASSET_NAME
/livedraw/layers/(LAYER_NAME)/B/input/unsink
/livedraw/layers/(LAYER_NAME)/B/input/clear
```


### `mask` controls the mask sinks for the named layer.  Choose either A or B layer.

```
/livedraw/layers/(LAYER_NAME)/A/mask/sink ASSET_NAME
/livedraw/layers/(LAYER_NAME)/A/mask/unsink
/livedraw/layers/(LAYER_NAME)/A/mask/clear
```

```
/livedraw/layers/(LAYER_NAME)/B/mask/sink ASSET_NAME
/livedraw/layers/(LAYER_NAME)/B/mask/unsink
/livedraw/layers/(LAYER_NAME)/B/mask/clear
```

### `xfade` Mix A/B input via a simple crossfade.

```
/livedraw/layers/(LAYER_NAME)/xfade N_XFADE
```
N_XFADE takes a value between 0.0 (full A) and 1.0 (full B);



### `swap` swaps A/B input references.

```
/livedraw/layers/(LAYER_NAME)/swap
```

### `stretchmode` controls how the input and mask relate are scaled given the layer's width and height.

```
/livedraw/layers/(LAYER_NAME)/stretchmode STRETCH_MODE 
```

Valid stretch modes are: `CENTER`, `FILL`, `FIT`, `STRETCH`;

### `lock` prevent changes to the named layer.

```
/livedraw/layers/(LAYER_NAME)/lock    B_LOCK
```

### `solo` render only the named layer.

```
/livedraw/layers/(LAYER_NAME)/solo    B_SOLO
```

### `label` give the named layer a color (only useful in a GUI context).

```
/livedraw/layers/(LAYER_NAME)/label    R G B [A]
```

### `clipping` control the layer clipping (relates to stretch mode)

```
/livedraw/layers/(LAYER_NAME)/clipping B_CLIP
```

### `order` control the input for the named layer.

```
/livedraw/layers/(LAYER_NAME)/order ORDER_NUM
/livedraw/layers/(LAYER_NAME)/order forward
/livedraw/layers/(LAYER_NAME)/order backward
/livedraw/layers/(LAYER_NAME)/order front
/livedraw/layers/(LAYER_NAME)/order back
```

### `debug` control the debug info for a given layer.

```
/livedraw/layers/(LAYER_NAME)/debug DEBUG_PARAM B_ENABLE
```
Debug params include `all`, `wireframe`, `axis`, and `info`.



# /livedraw/layers/(LAYER_NAME)/transform (`transform`, `xform`, `t`)

Layer transforms determine the position, opacity and other characteristics of how a given layer is rendered.

## Commands

### `anchorpoint` (`ap`, `a`) Set a layer's anchor point.

Layer anchor points determine the reference point in the layer for geometric transforms such as rotation, scaling and translation.

```
/livedraw/layers/(LAYER_NAME)/transform/anchorpoint X_ANCHORPOINT [Y_ANCHORPOINT [Z_ANCHORPOINT]] 
/livedraw/layers/(LAYER_NAME)/transform/anchorpoint X X_ANCHORPOINT 
/livedraw/layers/(LAYER_NAME)/transform/anchorpoint Y Y_ANCHORPOINT 
/livedraw/layers/(LAYER_NAME)/transform/anchorpoint Z Z_ANCHORPOINT 
```

### `position` (`pos`, `p`) Set a layer's position.

Layer position layer position determines the layer's placement on the rendering canvas.

```
/livedraw/layers/(LAYER_NAME)/transform/position X_POSITION [Y_POSITION [Z_POSITION]]
/livedraw/layers/(LAYER_NAME)/transform/position X X_POSITION
/livedraw/layers/(LAYER_NAME)/transform/position Y Y_POSITION
/livedraw/layers/(LAYER_NAME)/transform/position Z Z_POSITION
```

### `rotation` (`rot`,`r`) Set a layer's rotation.

Layer rotation determines the layer's rotation on the rendering canvas and given its current anchor point.

```
/livedraw/layers/(LAYER_NAME)/transform/rotate DEGREES X_AMOUNT Y_AMOUNT Z_AMOUNT
/livedraw/layers/(LAYER_NAME)/transform/rotate X_ROTATE Y_ROTATE [Z_ROTATE]
/livedraw/layers/(LAYER_NAME)/transform/rotate X X_ROTATE
/livedraw/layers/(LAYER_NAME)/transform/rotate Y Y_ROTATE
/livedraw/layers/(LAYER_NAME)/transform/rotate Z Z_ROTATE
```

### `scale` (`s`) Set a layer's scale.

Scale determines the layer's x, y, z scale on the rendering canvas given its anchor point.

```
/livedraw/layers/(LAYER_NAME)/transform/scale X_SCALE [Y_SCALE [Z_SCALE]]
/livedraw/layers/(LAYER_NAME)/transform/scale X X_SCALE
/livedraw/layers/(LAYER_NAME)/transform/scale Y Y_SCALE
/livedraw/layers/(LAYER_NAME)/transform/scale Z Z_SCALE
```

### `opacity` (`o`) Set a layer's opacity.

Layer opacity determines how transparent a given layer is on the rendering canvas.  Opacity affects the way that a given layer will blend with other layers.  Opacity ranges from 0-255.

```
/livedraw/layers/(LAYER_NAME)/transform/opacity OPACITY
```

### `opacityn` (`on`) Set a layer's opacity (normalized).

Layer opacity determines how transparent a given layer is on the rendering canvas.  Opacity affects the way that a given layer will blend with other layers.  Normalized opacity ranges from 0-1.

```
/livedraw/layers/(LAYER_NAME)/transform/opacityn OPACITY
```

### `size` (`sz`) Set a layer's size.

The layer size determines how larger the underlying frame buffer should be.

```
/livedraw/layers/(LAYER_NAME)/transform/size WIDTH HEIGHT
```

### `width` (`w`) Set a layer's width.

See `size` above.

```
/livedraw/layers/(LAYER_NAME)/transform/width WIDTH
```

### `height` (`h`) Set a layer's width.

See `size` above.

```
/livedraw/layers/(LAYER_NAME)/transform/height HEIGHT
```

