#pragma once 
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

// »»» VERTICES ««« 
 //vertices
 namespace shb{

//todo implement
struct sVertex{
  float x,y,z;
  float r,g,b;
  float tx,ty;
};

class sShape {
 public:
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
};


class sTriangle : public sShape{
 public:
    std::vector<GLfloat> vertices = 
  {
    -0.5f,     -0.5f * float(sqrt(3)) / 3,     0.0f,   0.5f, 0.0f, 0.5f,    0.0f, 0.0f, //lower left
     0.5f,     -0.5f * float(sqrt(3)) / 3,     0.0f,   0.0f, 0.5f, 0.5f,    0.0f, 1.0f, //lower right
     0.0f,      0.5f * float(sqrt(3)) *2/3,    0.0f,   0.0f, 0.0f, 1.0f,    1.0f, 1.0f,//upper right

    -0.5f/2,   0.5f * float(sqrt(3)) / 6,     0.0f,    0.5f, 0.0f, 0.5f,    0.0f, 0.0f,//inner left
     0.5f/2,   0.5f * float(sqrt(3)) / 6,     0.0f,    0.0f, 0.0f, 0.5f,   0.0f,1.0f,//inner right
     0.0f,    -0.5f * float(sqrt(3)) / 3,     0.0f,    0.0f, 0.0f, 0.5f,   1.0f, 1.0f

  
  };

    std::vector<GLuint> indices = 
  {
    0, 3, 5, //lower left
    3, 2, 4, //lower right
    5, 4, 1


  };

};



class sSquare : public sShape{
 public:
    std::vector<GLfloat> vertices = 
  { //           COORDS      / /     //    COLORS   //   TEX COORDS   //
     -0.5f,  -0.5f,  0.0f,      0.5f, 0.0f, 0.5f,      0.0f, 0.0f, //lower left
     -0.5f,   0.5f,  0.0f,      0.0f, 0.5f, 0.5f,      0.0f, 1.0f,//lower right
      0.5f,   0.5f,  0.0f,      0.0f, 0.0f, 1.0f,      1.0f, 1.0f,//upper right
      0.5f,  -0.5f,  0.0f,      1.0f, 0.0f, 1.0f,      1.0f, 0.0f //upper left
   
  
  };

    std::vector<GLuint> indices = 
  {
    0,2,1, //upper triangle
    0,3,2 //lower triangle


  };
};


}
 