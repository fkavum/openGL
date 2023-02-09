# Previously

- We made glew work!
- We note down some error handling like correct symbols and linking

# Tutorial 4

- We will make our triangle run with modern openGL
    -   To make it work we need to have at least VertexBuffer and Shader!
- Vertex Buffer
  -  Its just a buffer. This is a buffer memory in OpenGL so its for our GRam
  -  Concept is: A bunch of data that represent my triangle, im putting it to my VRam, then we are issuing something called drawCall.
  - Draw call is a draw command, which says, the blob of data you have in you Vram, read and draw it to the screen.
  - We also need to define how to read and interpret that data and how to put it into screen.
  - after the drawcall to say how to rasterize/draw to screen is defined by shaders!.

- Shader is just a program, runs in the GPU. (4)