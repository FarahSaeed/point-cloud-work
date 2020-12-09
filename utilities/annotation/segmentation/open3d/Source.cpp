// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <thread>
#include "open3d/Open3D.h"
#include "VisualizerWithEditing1.h"
#include "open3d/3rdparty/GLFW/glfw3.h"
#include <stdio.h>
#include "linmath.h"
#include <stdlib.h>
#include <stdio.h>

// A simplified version of examples/cpp/Visualizer.cpp to demonstrate linking
//// an external project to Open3D.
int main(int argc, char* argv[]) {
    using namespace open3d;
    using namespace std;

    auto cloud_ptr = std::make_shared<geometry::PointCloud>(); 
    //"C:/Users/FARAH/Desktop/plant_pointnet2/0_pred (1).ply"
    //"C:/Users/FARAH/Desktop/example.pcd"
    //"E:/Work/Research_work/BSAIL/Projects/matlab/Work/Work/New folder/point cloudand segmentaion code/matlab_annotations"
   //if (io::ReadPointCloud("E:/Work/Research_work/BSAIL/Projects/matlab/Work/Work/New folder/point cloud and segmentaion code/matlab_annotations/SPL_0501_ann_f.ply", *cloud_ptr)) {
    if (io::ReadPointCloud("E:/Work/Research_work/BSAIL/Projects/annotation_tools/anns/samples/SPL_0501woc_won.pcd", *cloud_ptr)) {

     // if (io::ReadPointCloud("E:/Work/Research_work/BSAIL/Projects/matlab/Work/Work/New folder/point cloud and segmentaion code/pointCloud/SPL_0501.pcd", *cloud_ptr)) {
       // if (io::ReadPointCloud("E:/Work/Research_work/BSAIL/Projects/annotation_tools/anns/txt_files/SPL_0403.ply", *cloud_ptr)) {
        //if (io::ReadPointCloud("C:/Users/FARAH/Desktop/example.pcd", *cloud_ptr)) {
        utility::LogInfo("Successfully read {}\n", "0_pred (1).ply");
        visualization::VisualizerWithEditing1 vis;
        vis.CreateVisualizerWindow();
        vis.AddGeometry(cloud_ptr);
        //vis.RenderSomething();
        vis.Run();
        vis.DestroyVisualizerWindow();
        
    }
    return 0;
}
//
//static const struct
//{
//    float x, y;
//    float r, g, b;
//} vertices[3] =
//{
//    { -0.6f, -0.4f, 1.f, 0.f, 0.f },
//    {  0.6f, -0.4f, 0.f, 1.f, 0.f },
//    {   0.f,  0.6f, 0.f, 0.f, 1.f }
//};
//
//static const char* vertex_shader_text =
//"#version 110\n"
//"uniform mat4 MVP;\n"
//"attribute vec3 vCol;\n"
//"attribute vec2 vPos;\n"
//"varying vec3 color;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
//"    color = vCol;\n"
//"}\n";
//
//static const char* fragment_shader_text =
//"#version 110\n"
//"varying vec3 color;\n"
//"void main()\n"
//"{\n"
//"    gl_FragColor = vec4(color, 1.0);\n"
//"}\n";
//
//static void error_callback(int error, const char* description)
//{
//    fprintf(stderr, "Error: %s\n", description);
//}
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GLFW_TRUE);
//}
//
//int main(void)
//{
//    GLFWwindow* window;
//    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
//    GLint mvp_location, vpos_location, vcol_location;
//
//    glfwSetErrorCallback(error_callback);
//
//    if (!glfwInit())
//        exit(EXIT_FAILURE);
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//
//    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//
//    glfwSetKeyCallback(window, key_callback);
//
//    glfwMakeContextCurrent(window);
//    //gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//    //gladLoadGL(glfwGetProcAddress);
//    glfwSwapInterval(1);
//
//    // NOTE: OpenGL error checks have been omitted for brevity
//
//    glGenBuffers(1, &vertex_buffer);
//    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
//    glCompileShader(vertex_shader);
//
//    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
//    glCompileShader(fragment_shader);
//
//    program = glCreateProgram();
//    glAttachShader(program, vertex_shader);
//    glAttachShader(program, fragment_shader);
//    glLinkProgram(program);
//
//    mvp_location = glGetUniformLocation(program, "MVP");
//    vpos_location = glGetAttribLocation(program, "vPos");
//    vcol_location = glGetAttribLocation(program, "vCol");
//
//    glEnableVertexAttribArray(vpos_location);
//    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
//        sizeof(vertices[0]), (void*)0);
//    glEnableVertexAttribArray(vcol_location);
//    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
//        sizeof(vertices[0]), (void*)(sizeof(float) * 2));
//
//    while (!glfwWindowShouldClose(window))
//    {
//        float ratio;
//        int width, height;
//        //Eigen::Matrix4f m, p, mvp;
//        mat4x4 m, p, mvp;
//
//        glfwGetFramebufferSize(window, &width, &height);
//        ratio = width / (float)height;
//
//        glViewport(0, 0, width, height);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        mat4x4_identity(m);
//        mat4x4_rotate_Z(m, m, (float)glfwGetTime());
//        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
//        mat4x4_mul(mvp, p, m);
//
//
//        glUseProgram(program);
//        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//
//    glfwTerminate();
//    exit(EXIT_SUCCESS);
//}
//
