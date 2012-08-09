/*==============================================================================
 
 Copyright (c) 2010, 2011, 2012 Christopher Baker <http://christopherbaker.net>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 ==============================================================================*/

#pragma once

class ofxOscRouter;
class AssetManager;
class LayerManager;
class CanvasRenderer;
class EffectsManager;
class SessionManager;

class ofxLivedrawEngineInterface {
  
public:
    virtual ofxOscRouter*         getOscRouter() = 0;
    virtual const ofxOscRouter*   getOscRouter() const = 0;
    virtual AssetManager*         getAssetManager() = 0;
    virtual const AssetManager*   getAssetManager() const = 0;
    virtual LayerManager*         getLayerManager() = 0;
    virtual const LayerManager*   getLayerManager() const = 0;
    virtual CanvasRenderer*       getCanvasRenderer() = 0;
    virtual const CanvasRenderer* getCanvasRenderer() const = 0;
    virtual EffectsManager*       getEffectsManager() = 0;
    virtual const EffectsManager* getEffectsManager() const = 0;
    virtual SessionManager*       getSessionManager() = 0;
    virtual const SessionManager* getSessionManager() const = 0;
};