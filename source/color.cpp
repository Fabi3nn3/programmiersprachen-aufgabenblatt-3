#include "color.hpp"
#include "window.hpp"

Color::Color():
	r_{0},
	g_{0},
	b_{0}{}

Color::Color(float r):
	r_{r},
	g_{r},
	b_{r}{}

Color::Color(float r, float g, float b):
	r_{r},
	g_{g},
	b_{b}{}

