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

    /*Rectangle name {{0.1,0.1},{0.5},{0.7},{0.0,0.0,1.0}};
    name.draw(win);

    Rectangle meh {{0.2,0.2},{0.4},{0.6},{0.0,1.0,0.0}};
    meh.draw(win,{1.0,0.0,0.0});

    Circle alfred {{0.3,0.3},{0.2},{0.0,1.0,0.1}};
    alfred.draw(win);

    Circle elfriede {{0.4,0.4},{0.3},{0.1,0.1,0.1}};
    elfriede.draw(win,{1.0,0.0,0.0});*/

    auto m = win.mouse_position();
    Vec2 maus{m.first,m.second}; //gibt Position des Mauszeigers im Fenster zurueck

    std::vector<Circle> circly (2);
    std::vector<Rectangle> rectangly (2);


    circly[0] = {{0.3,0.4},{0.25},{1.0,0.0,1.0}};
    circly[1] = {{0.5,0.3},{0.34},{1.0,1.0,0.0}};


    rectangly[0] = {{0.12,0.12},{0.35},{0.43},{1.0,0.0,0.0}};
    rectangly[1] = {{0.23,0.34},{0.23},{0.34},{1.0,1.0,0.0}};

    circly[0].draw(win);
    circly[1].draw(win);

    rectangly[0].draw(win);
    rectangly[1].draw(win);





   if(circly[0].is_inside(maus)){
      circly[0].draw(win,{0.0,0.0,1.0}); //malt neu 
    }

    if(circly[1].is_inside(maus)){
      circly[1].draw(win,{0.0,0.0,1.0}); //malt neu 
    }

    if(rectangly[0].is_inside(maus)){
      rectangly[0].draw(win,{0.0,0.0,1.0});
    }

    if(rectangly[1].is_inside(maus)){
      rectangly[1].draw(win,{0.0,0.0,1.0});
    }





    auto t = win.get_time();
    float x1{0.5f + 0.5f * std::sin(t)};
    float y1{0.5f + 0.5f * std::cos(t)};

    float x2{0.5f + 0.5f * std::sin(2.0f*t)};
    float y2{0.5f + 0.5f * std::cos(2.0f*t)};

    float x3{0.5f + 0.5f * std::sin(t-10.f)};
    float y3{0.5f + 0.5f * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    //auto m = win.mouse_position();
    /*win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);*/

    win.update();
  }

  return 0;
}
