# CPP_GLSL_Mandelbrot_Pt2_TickFidelity
C++ OpenGL GLSL Program Which Uses the Mandelbrot Model With A Tick Uniform To Increase Fidelity With Runtime. Does Some Trippy Stuff. I also 
changed some constant variables to help with the pulsing push-through of colors. This one is a little flashy so please
be mindful of the eye strain this can and probably will give. _tickTimer controls our zoom and rate of change, while _tick does
fidelity. 
This program helped educate me on uniforms and GLSL optimizations. It also informed me on nuances with sin to give sudo-dynamic color patterns
as well as helped me find good usages for previously shelved tools in OpenGL like triangle_fan.
Also try being aware we are using a constant tick incremental for our fidelity so over a long time we may see some overflow as I didn't implement checks for this
it shouldn't overly stress runtime as we should gradually use less of our GPU the longer we zoom as we will lose more individual pixels.
We again will be using libraries held in (https://github.com/Kingerthanu/CPP_CellularAutomata_stage1).

<img width="802" alt="image" src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/3caa73f5-4712-4f1e-a48f-891cabed6b5e">

![tripToRotate](https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/3c08a0df-2f95-4248-9bfb-e5fd2c903fb1)
<img width="869" alt="image" src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/765f912a-b866-47c3-917c-ceaa2fe1f2f4">

![spinnyTuberHeimer-ezgif com-optimize (3)](https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/79a2f3b4-4dc3-4f1c-8c6f-ced4daf6f90c)
