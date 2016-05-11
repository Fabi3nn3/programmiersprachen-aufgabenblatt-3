#include "window.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include <utility>
#include <cmath>
#include <vector>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

   Circle zwulf[4];
   zwulf[0]={{0.05,0.5},0.005,{0.0,0.0,0.0}};
   zwulf[1]={{0.95,0.5},0.005,{0.0,0.0,0.0}};
   zwulf[2]={{0.5,0.05},0.005,{0.0,0.0,0.0}};
   zwulf[3]={{0.5,0.95},0.005,{0.0,0.0,0.0}};

  auto t = win.get_time();

   Circle ziffernblatt{{0.5,0.5},{0.45},{0.0,0.75,0.25}};
   ziffernblatt.draw(win);
   zwulf[0].draw(win);
   zwulf[1].draw(win);
   zwulf[2].draw(win);
   zwulf[3].draw(win);


   //Vector mp{0.5,0.5};
   //mp.draw_point(win);

   float bogenmass = M_PI*2/60;

   float sec = t;
   float min = t/60;
   float hou = t/(12*60);

   win.draw_line(0.5,0.5, 0.5+sin(bogenmass*sec)*0.45, 0.5+cos(bogenmass*sec)*0.45, 0.0,0.0,0.0);
   win.draw_line(0.5,0.5, 0.5+sin(bogenmass*min)*0.35, 0.5+cos(bogenmass*min)*0.35, 0.0,0.0,0.0);
   win.draw_line(0.5,0.5, 0.5+sin(bogenmass*hou)*0.25, 0.5+cos(bogenmass*hou)*0.25, 0.0,0.0,0.0);





    win.update();
  }

  return 0;
}
