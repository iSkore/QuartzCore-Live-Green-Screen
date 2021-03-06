/*
A Core Image kernel routine that computes a multiply effect.
The code looks up the source pixel in the sampler and then multiplies it by the value passed to the routine.
*/

kernel vec4 greenScreen(sampler image)
{
	vec4 color = sample(image, samplerCoord(image));

	// HIGHLY SELECTIVE
	color.a = ( color.r <= 0.2 && color.g <= 0.35 && color.g >= 0.2 && color.b <= 0.275 && color.b >= 0.05 ) ? 0.0 : 1.0;
	
	// MID SELECTIVE
	color.a = ( color.r <= 0.175 && color.g <= 0.35 && color.g >= 0.15 && color.b <= 0.25 && color.b >= 0.05 ) ? 0.0 : 1.0;
	
	// LESS SELECTIVE
	color.a = ( color.r <= 0.155 && color.g <= 0.35 && color.g >= 0.135 && color.b <= 0.2175 && color.b >= 0.0375 ) ? 0.0 : 1.0;

	return color;
}
