// define our rectangular texture samplers 
uniform sampler2DRect   sourceTexture;       // the texture that is being adjusted
uniform sampler1D       LUT;        // the 
uniform int             LUT_LENGTH; // the number of entries in the LUT

// ESSENTIAL reading:
// http://http.developer.nvidia.com/GPUGems2/gpugems2_chapter24.html

float adjustedLUTCoordinate(float lenLUT, float coord) {
    return (lenLUT - 1.0) / lenLUT * coord + 1.0 / (2.0 * lenLUT);
}

void main (void) 
{ 
	vec4 inputColor = texture2DRect(sourceTexture, gl_TexCoord[0].st);
    
	vec4 colorout;
    
    // cast it so we can keep our uniform variables under control
    float LUT_LENGTH_F = float(LUT_LENGTH);
    
    // adjust the LUT coordinates (see the gpugems2 link above)
    float rIndex = adjustedLUTCoordinate(LUT_LENGTH_F, inputColor.r);
    float gIndex = adjustedLUTCoordinate(LUT_LENGTH_F, inputColor.g);
    float bIndex = adjustedLUTCoordinate(LUT_LENGTH_F, inputColor.b);

    // do the color lookups with the LUT adjusted coordinates
	colorout.r = texture1D(LUT, rIndex).r;
	colorout.g = texture1D(LUT, gIndex).g;
	colorout.b = texture1D(LUT, bIndex).b;
	colorout.a = inputColor.a; // use the input image alpha
	
    // send it along!
	gl_FragColor = colorout;
}