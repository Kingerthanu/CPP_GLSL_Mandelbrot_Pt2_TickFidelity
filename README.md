# CPP_GLSL_Mandelbrot_Pt2_TickFidelity
C++ OpenGL GLSL Program Which Uses the Mandelbrot Model With A Tick Uniform To Increase Fidelity With Runtime. Does Some Trippy Stuff. I also 
changed some constant variables to help with the pulsing push-through of colors. This one is a little flashy so please
be mindful of the eye strain this can and probably will give. _tickTimer controls our zoom and rate of change, while _tick does
fidelity. 

<img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/c854a82c-0a2b-41a9-8b3f-ae17b70548dc" alt="Cornstarch <3" width="55" height="59">

This program helped educate me on uniforms and GLSL optimizations. It also informed me on nuances with sin to give sudo-dynamic color patterns
as well as helped me find good usages for previously shelved tools in OpenGL like triangle_fan.
Also try being aware we are using a constant tick incremental for our fidelity so over a long time we may see some overflow as I didn't implement checks for this
it shouldn't overly stress runtime as we should gradually use less of our GPU the longer we zoom as we will lose more individual pixels.
We again will be using libraries held in (https://github.com/Kingerthanu/CPP_CellularAutomata_stage1).



----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/d7d34a00-aea1-4012-a142-7ec5ee62c3c1" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/d7d34a00-aea1-4012-a142-7ec5ee62c3c1" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/d7d34a00-aea1-4012-a142-7ec5ee62c3c1" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/d7d34a00-aea1-4012-a142-7ec5ee62c3c1" alt="Cornstarch <3" width="55" height="49"> 


**The Breakdown:**

 This C++ Program Works To Use GLSL Shader Coding To Represent The Mandlebrot Equation (But In A Cooler Way).

This Program Starts In Our C++ Driver But This Works To Create Our Shader With Our Provided Files In A Shader Class. This Will Use API Calls To Signify Which Shaders Our Given Instance Uses So We Can Hot Swap But Currnetly Are Only Using One With Our Mandlebrot Function.

 When We Launch Our Shader Code We Also Set A Tick Counter In Which Will Be Indexed In Our While Loop. This Will Send In A Uniform (Variable Reference) To The Shader TO Use And This Will Be The Magnification To Give The Illusion Of Zooming In. 

 On Top Of This Magnifier, We Will Also Include A Fidelity Counter In Which Will Move On A Seperate Rate. The Purpose Of This Fidelity Counter Is That When We Zoom In We Zoom In Relative To Our Initial Perspective So Without Increasing The Fidelity We Will Start Reaching Pixelated Color Cubes Quick. Also THough If We Increase Our Fidelity Too High We Also Are Now THen Frying Our Computer BEcause We Are Telling It THen To Instead Of Drawing A Rough Estimate At A Faaaaar Distance Is Instead Rendering Every Single Atom Of The Texture From This Distance Which Is Just Wasting Executions On Practially Useless Calls.

 On Top Of The Fidelity We Also Added A Color Shifter In Which Using The Current Tick And Sine Will Oscillate Between A Given Color Range.

 Also To Get My Specific Wants From The Renderer I May HAve Some Odd Values Placed In The Formulas If You Know Them Better Than Me But Hey It Looks Cool.

I Loved This Project As It Was Super Cool And Helped Really Solidify GPU Coding And How It Works Under The Hood Much More. Instead Of Focusing More On The VBO And All Those Problems, Focusing JUST On The Shading Program Made ME Realize Actually How Powerful It Can Be If We Can Properly Divert Traffic To It For Quick Crunching Of Data For Both Parts Of Our Pipeline. Also Creating These Low-Resistance Functions To "Shade" Our Specific Pixels Is Very Interesting To See From A Traditionally Single Thread Design Principle On Program. While A Lot Of Other Improvements Could Be Seen On The Fidelity Slider And Other Variables It Still Is In Such A Functional State And If Anything Will Do Small Fixes Like Increasing Resolution More To Infininty As Well As Adding Rotation.
 

<img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/5a500dfd-7e30-40ea-9912-05faaa71dcdf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/5a500dfd-7e30-40ea-9912-05faaa71dcdf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/5a500dfd-7e30-40ea-9912-05faaa71dcdf" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/5a500dfd-7e30-40ea-9912-05faaa71dcdf" alt="Cornstarch <3" width="55" height="49"> 

----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/91b53912-4062-4d35-99da-da91c685ba0a" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/91b53912-4062-4d35-99da-da91c685ba0a" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/91b53912-4062-4d35-99da-da91c685ba0a" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/91b53912-4062-4d35-99da-da91c685ba0a" alt="Cornstarch <3" width="55" height="49"> 


**Features:**

<img width="802" alt="image" src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/3caa73f5-4712-4f1e-a48f-891cabed6b5e">

![tripToRotate](https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/3c08a0df-2f95-4248-9bfb-e5fd2c903fb1)
<img width="869" alt="image" src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/765f912a-b866-47c3-917c-ceaa2fe1f2f4">

![spinnyTuberHeimer-ezgif com-optimize (3)](https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/79a2f3b4-4dc3-4f1c-8c6f-ced4daf6f90c)


<img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/56ba9c9a-3b93-4f98-a7da-e7449a91215b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/56ba9c9a-3b93-4f98-a7da-e7449a91215b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/56ba9c9a-3b93-4f98-a7da-e7449a91215b" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_GLSL_Mandelbrot_Pt2_TickFidelity/assets/76754592/56ba9c9a-3b93-4f98-a7da-e7449a91215b" alt="Cornstarch <3" width="55" height="49">

