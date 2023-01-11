#include <sApp.hpp>
#include <glad.c>
#include <stb_image.h>

#include <random>
#include <chrono>


namespace shb{


/*
TODO:: 
    1. Add cool logos from my windows partition to the project
    2. Comb through the rest of this and clean up a little
    3. change the pyramid to an icosohedron 
    4. Fix whatever is going on with shader handles that's making the error messages happen
    5. Add necessary functions to the sShape class 
    6. Rename sShapes class to sGameObject and make it an abstract base class
    7. Make sGUI an observer of sGameObjects 
    8. Finally have fun

*/


sApp::sApp(){}


void sApp::run(){

//»»»WINDOW«««
  //creates window and initialises glad on current context by default
  m_Window.initWindow();
//»»» GUI «««
  //provides the GUI's startup functions
  tinkerWindow.initGUI();
//»»» RANDOM SEED «««
  //seeds random number generator
  srand(time(0));

 
 //how many objects to randomly generate
  int maxPyramids = 1000;
 
 //bounds of random number generation for position of pyramids
  float xLO = -10000.f;
  float xHI = 10000.f;
  float yLO = -10000.f;
  float yHI = 10000.f;
  float zLO = -20000.f;
  float zHI = -.2f;

  //controls half the triangles scales
  float globalPyramidScale = 10.f;

 
  //generates random numbers for 1000 objects x and y coordinates and loads them in before the main loop starts
    while(pyramids.size() < maxPyramids){
    float x = xLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(xHI-xLO)));
    float y = yLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(xHI-xLO)));
    float z = zLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(zHI-zLO)));

    pyramids.push_back({x,y,z});
    pyramids.back().init();
    }
     while(icosohedrons.size() < maxPyramids){
    float x = xLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(xHI-xLO)));
    float y = yLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(xHI-xLO)));
    float z = zLO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(zHI-zLO)));

    icosohedrons.push_back({x,y,z});
    icosohedrons.back().init();
    }

/*
⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯
                                 
█▀▄▀█ ▄▀█ █ █▄░█   █░░ █▀█ █▀█ █▀█
█░▀░█ █▀█ █ █░▀█   █▄▄ █▄█ █▄█ █▀▀
    where the real business is
⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯
*/

  //»»» MAIN LOOP «««
  while (!glfwWindowShouldClose(m_Window.handle()))
  { 

   //update window, keep viewport same size as screen
    m_Window.update();
    tinkerWindow.startFrame();

    //input.getInput(&m_Camera); //TODO 
 

   //»»» DELTA TIME «««
    m_CurrentFrameTime = glfwGetTime();       //get current time
    m_DeltaTime = m_CurrentFrameTime - m_PreviousFrameTime;//get amount of time elapsed since last frame
    m_PreviousFrameTime = m_CurrentFrameTime;               //set this frames time for next iteration comparison
    m_FrameTimeInMS = m_DeltaTime *1000;


    //»»» GLOBAL 3D «««
    m_Camera.update(m_DeltaTime);


   //manipulates pyramid objects
    for(int i = 0; i < pyramids.size(); ++i){
      pyramids[i].update(m_Camera,m_DeltaTime);
    }
        for(int i = 0; i < icosohedrons.size(); ++i){
      icosohedrons[i].update(m_Camera,m_DeltaTime);
    }
  

   //imgui stuff
    tinkerWindow.update(&m_Camera, 
                        pyramids[1], 
                        m_DeltaTime,
                        globalPyramidScale
                        );
    tinkerWindow.render();

   //if Q is pressed, break out of the main loop and quit the application
    if(glfwGetKey(m_Window.handle(),GLFW_KEY_Q) == GLFW_PRESS){
      break;
    }
    
   //swap buffers
    glfwSwapBuffers(m_Window.handle()); 
   //poll events
    glfwPollEvents();           //have any window events happened? 
  }
 
  //check for errors
  checkError(__FILE__,__LINE__);
}
/*
⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯

⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯⋯⋯⋯⋯⋯⊱⊰⋯⋯⋯⋯⋯
*/

void sApp::cleanup(){
 //delete all pyramids
  for(int i = 0; i < pyramids.size(); ++i){
      pyramids[i].cleanup();
  }
 
  tinkerWindow.destroyGUI();
  m_Window.destroy();

  glfwTerminate();
}


sApp::~sApp(){
  cleanup();
}


}//namespace shb