## Livedraw Engine Concepts

### Media
* Media assets are loaded from a media folder, usually located in `data/media`.  * Video cameras are defined in a file called `grabbers.xml`.  In the future, these cameras will be available dynamically, rather than via the `xml` config.  This is due to a few limitations within openFrameworks.
* Streaming video (i.e. MJPEG, IPcameras, etc) are defined in a file called `streams.xml`.  MJPEG (IPCamera), RTSP and online Quicktime Movies are supported. 
* Syphon Streams are detected automatically on the local system.
* All other media assets, including video and images are detected via file name extensions.  Most common media file types are recognized.

### Assets
* An asset is any item within the Livedraw Engine world that can _sink_ or _source_ or _is playable_ (see below).  Some asset types have multiple abilities.

|Asset Type|Is Sink?|Is Source?|Is Playable?|Is Cacheable?|Notes|
|:-:|:-:|:-:|:-:|:-:|:--|
|&nbsp;|*Can it receive and<br/> process shared frames?*|*Can this asset send<br/>shared frames?*|*Can this Asset Type be "Played"<br/>by a Player Asset*|*Can this Asset Type be "Cached"<br/> in a Read Only Buffer Asset?*|&nbsp;|
|**Image Asset**  |✔|✗|✔|✗|An image asset is simply a single shared frame, usually loaded from disk.|
|**Movie Asset**  |✗|✗|✔|✔|A movie asset is a disk based asset that can be a source only when it is "played" with a player asset.|
|**Grabber Asset**|✗|✔|✗|✗|A grabber is a camera or frame grabber capable of providing "live" frames to a sink.|
|**Streaming Asset** |✗|✔|✗|✗|A streaming asset is like a grabber, but comes from a network source.|
|**Syphon Asset** |✗|✔|✗|✗|A Syphon asset is much like a grabber or a streaming asset.|
|**Buffer Asset** |✔|✗|✔|✗|A buffer asset is a collection of frames with a certain size and other properties.  It can _sink_ frames from any source (if it has room) and can only be a source if it is played with a _player asset_.|
|**Player Asset** |✗|✔|✗|✗|A player asset is a controllable source, but must "play" a playable asset in order to be a valid _source_.  If no playable asset is loaded, it will deliver blank frames to all attached _sinks_.|
|**Layer Asset _(in progress)_**  |✔|✔|✗|✗|A composition layer asset can _sink_ frames via its inputs and masks and can also become a _source_ for other _sinks_.  This allows for complex feedback and video effects.|


### Naming
* All assets are named.  These names can be changed and allow easier access (as opposed of using long filenames, or hardware addresses).  Assets are automatically assigned names when they are loaded or created.  Users can specify specific names during creation.  If the name exists, the asset will be assigned a new name.  For instance, if the name `myimage` is already taken, the `myimage` would be changed to `myimage_0`,`myimage_1`,`myimage_2`, etc.  Subsequently the numerical suffix is incremented.


### Sinks and Sources 
* At the core of the Livedraw Engine is a complex media and frame sharing system that seeks to increase speed by reducing unnecessary disk reads (i.e. playing a video file from disk) and leveraging the GPU.  
* To achieve this goal Livedraw Engine employs the concept of ___sources___ and ___sinks___.  
* ___Sources___ are smart objects that can provide shared frames that can be played, manipulated, buffered or saved.  A Webcam is a good example of a _source_.  It provides a stream of frames that can be used or ignored.  Each frame _source_ can be connected to any number of _sinks_.  Sources keep track of their attached _sinks_ and in the event of a _source_ closing, all of the attached _sinks_ will be alerted and can then take appropriate action.
* ___Sinks___ are objects that can ___do___ something with the shared frames delivered by _sources_.  For instance, a <b>Video Buffer Asset</b> is a _sink_ because it can ___do___ something with the incoming frame -- namely it can store it in pre-determined way.  A Composition Layer also contains several _sinks_.  A layer's _sinks_ listen for incoming shared frames and then _does_ something with them -- namely it composites, positions, and then renders the results to a _Canvas_.
* Shared frames keep track of which _sinks_ currently sharing them.  If no _sinks_ are currently storing or using a given frame it destroys itself, freeing memory and computing resources.  _Sources_ are not required to store their shared frames.  In most cases, after they have been _sinked_, the _source_ transfers ownership of the frame to each of its _sinks_.
* Generally, _sinks_ cannot "_source_" (i.e. receive) shared frames from multiple _sources_, but _sources_ can "_source_" (i.e. send) their frames to an endless number of _sinks_.  Once a shared frame has been allocated, there is almost no cost to use that frame in many _sinks_.

### Playable

* ___Playable___ assets are those that cannot logically act as sources without some intervention.  For instance, Video and Buffer Assets are effectively collections of individual frames.  Without a Video Player Asset, it would be impossible for a Video or Buffer Asset to know how to deliver its frames (fast? slow? all? some? ordered? random?).  Thus, playable assets require a player to select each frame as it is sourced.  Likewise, without loading a playable asset, Video Players cannot source any useful frames.  They must work together. 
