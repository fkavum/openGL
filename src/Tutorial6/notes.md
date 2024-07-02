# Previously

- The previous code in Tutorial5 can draw triangle without shader code. Its really upto GPU manifacturer. 
- You GPU manifacturer can write a simple shader code for you sometimes, for better debugging.

# Tutorial 6
## How Shaders Work in OpenGL

- Its just a program run in GPU, by program we mean blob of code.
- We need to say something to GPU to have output with the given data (vertex buffer) to GPU.


- When we issue drawCall, vertex and fragment shader get called in order then we see the result/rasterization. There are many stage in between.

### Vertex Shader
- For triangle, vertex shader will be called 3 times. (Count = vertexCount)
- primary purpose of vertex shader is specifies position of vertex (generally according to camera pos). Also, pass data to fragment shader.
- for input of vertex shader, we are defining vertex attribute data.

### Fragment Shader

- Fragment shader run once for each pixel in our triangle that needs to get rasterized.
- primary purpose determine output color for our pixel

### ToSumUp

- Frament shader generally called more that vertex shader, 
    so if you want to optimize, you can do some critical calculations in vertex shader.

