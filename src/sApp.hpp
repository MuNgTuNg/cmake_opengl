#pragma once

//»»»std«««
#include <iostream>
#include <string.h>

//»»»mine«««
#include <sShapes.hpp>
#include <sShader.hpp>
#include <sWindow.hpp>
#include <sGui.hpp>
#include <sBuffer.hpp>

//»»»external«««
//glfw/glad
#include <glad/glad.h> //include glad/glad.h instead of glad.c to avoid multiple definitions of functions as glad likes to cry about this
#include <GLFW/glfw3.h> 
#include <stb_image.h>

//maths
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//
//
//
//
//
//  TODO: » abstract and clean up more
//        » change shader system to use string instead of VECTORS????
//        » 3D 3D 3D
//        » textures
//
//
//



namespace shb{

class sApp{
 public:
    sApp();
    ~sApp();
    sApp(const sApp&) = delete;
    sApp (sApp&&) = delete;

    void run();


 private:
   sWindow m_Window{1000,1000};
   TinkeringWindow tinkerWindow{m_Window};
   
   //these should be abstracted into classes
  
};


}//namespace shb