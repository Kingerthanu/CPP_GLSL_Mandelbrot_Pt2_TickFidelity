#version 330 core

out vec4 FragColor;

uniform vec2 centerOffset;
uniform float bloatScale;
uniform float time;
uniform int tick;

float mandelbrot(vec2 uv)
{
    vec2 c = (uv + centerOffset) / bloatScale;
    c = c / pow(time, 1.0) + vec2(0.32008, 0.41278);

    vec2 z = vec2(0.0, 0.0);
    int iteration = 0;
    int maxIterations = 5000 + tick;

    for (int i = 0; i < maxIterations; ++i) {
        float zx = z.x * z.x - z.y * z.y + c.x;
        float zy = 2.0 * z.x * z.y + c.y;

        if (zx * zx + zy * zy > 4.0)
            return float(i) / float(maxIterations);

        z = vec2(zx, zy);
    }

    return 0.0;
}

vec3 hash13(float m)
{
    float x = fract(sin(m/2) * 625.246);
    float y = fract(sin(m + x) * 0.986);
    float z = fract(sin(m + y+x) * 0.7952);

    return vec3(x, y, z);
}

void main()
{

    FragColor = vec4(hash13((mandelbrot((gl_FragCoord.xy))+(time/10))), 1.0);

}
