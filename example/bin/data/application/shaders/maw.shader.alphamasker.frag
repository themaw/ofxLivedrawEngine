//these are our texture names, set in openFrameworks on the shader object in set up
uniform sampler2DRect sourceTexture;
uniform sampler2DRect maskTexture; 

// LUT
// http://http.developer.nvidia.com/GPUGems2/gpugems2_chapter24.html

// http://stackoverflow.com/questions/596216/formula-to-determine-brightness-of-rgb-color
const vec3 lumcoeff = vec3(0.299,0.587,0.114);

uniform int   alphaMode;
const   int   ALPHA_RED         = 0; // uses the RED channel of the mask as the alpha
const   int   ALPHA_BLUE        = 1; // uses the BLUE channel of the mask as the alpha
const   int   ALPHA_GREEN       = 2; // uses the GREEN channel of the mask as the alpha
const   int   ALPHA_ALPHA       = 3; // uses the ALPHA channel of the mask as the alpha
const   int   ALPHA_LUMA        = 4; // uses the calculated LUMINANCE of the mask as the alpha
const   int   ALPHA_LUMA_SMOOTH = 5; // uses the calculated LUMINANCE w/ TANH smoothing of the mask as the alpha

// boolean vars
uniform int invertMask;     // 0 = dark=>alpha, 1 = light=>alpha
uniform int invertSource;   // invert the source image, 0 or 1

// float vars
uniform float thresh; // the luminance threshold
uniform float spread; // the tanh smoothing spread
uniform float gain;   // the output gain, 0-1000


// TANH Function (Hyperbolic Tangent) used for liminace smoothing
float tanh(float val)  
{  
    float tmp = exp(val);  
    return (tmp - 1.0 / tmp) / (tmp + 1.0 / tmp);
} 


void main (void)
{
	
	// sample both textures
	vec4 a = texture2DRect(sourceTexture, gl_TexCoord[0].st); // source texture
	vec4 b = texture2DRect(maskTexture, gl_TexCoord[1].st); // mask texture
    
    // TODO: INVERT SOURCE SHOULD GO IN ANOTHER SHADER ...

    // invert source
    if(invertSource == 1) a = (1.0-a);
    // invert mask
    if(invertMask == 1) b = (1.0-b);

    float alpha = 1.0;
       
    if(alphaMode < ALPHA_LUMA) {
        alpha = b[alphaMode]; // channel based
    } else { 
        alpha = dot(b.rgb, lumcoeff); // luminance value
        // smooth it?
        if(alphaMode == ALPHA_LUMA_SMOOTH) {
            // TODO: more MAD? (multiply then add?)
            float t = tanh( ( alpha - thresh ) / spread );
            alpha = (0.5 * t) + .5; // MAD
        } 
    } 
    
    // set new alpha
    a = vec4(a.rgb, alpha);

    // apply gain
    a *= gain;

    // send it out!
	gl_FragColor = a;  

}




