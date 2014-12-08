#include "axColor.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

axColor::axColor(const axDouble& r, const axDouble& g, const axDouble& b):
		_r(r), _g(g), _b(b), _a(1.0)
{
}

axColor::axColor(const axDouble& r,
                 const axDouble& g,
                 const axDouble& b,
                 const axDouble& a):
_r(r), _g(g), _b(b), _a(a)
{
}

axColor::axColor() :
_r(0.0), _g(0.0), _b(0.0), _a(1.0)
{

}

axColor::axColor(const axColor& col)
{
    _r = col._r;
    _g = col._g;
    _b = col._b;
    _a = col._a;
}

axColor::axColor(const string& color)
{
	string c = color;

	unsigned int r_i, g_i, b_i;

	sscanf(c.substr(1, 2).c_str(), "%x", &r_i);
	sscanf(c.substr(3, 2).c_str(), "%x", &g_i);
	sscanf(c.substr(5, 2).c_str(), "%x", &b_i);

	_r = axDouble(r_i / 255.0);
	_g = axDouble(g_i / 255.0);
	_b = axDouble(b_i / 255.0);
    _a = 1.0;
}

axDouble axColor::GetRed() const
{
	return _r;
}

axDouble axColor::GetGreen() const
{
	return _g;
}

axDouble axColor::GetBlue() const
{
	return _b;
}

axDouble axColor::GetAlpha() const
{
    return _a;
}

void axColor::SetRed(const double& red)
{
    _r = axClamp<double>(red, 0.0, 1.0);
}

void axColor::SetGreen(const double& green)
{
    _g = axClamp<double>(green, 0.0, 1.0);
}

void axColor::SetBlue(const double& blue)
{
    _b = axClamp<double>(blue, 0.0, 1.0);
}

void axColor::SetAlpha(const double& alpha)
{
    _a = axClamp<double>(alpha, 0.0, 1.0);
}

// Serialization.
void axColor::SerializeOutput(fstream& out)
{
    out.write(reinterpret_cast<char*>(this), sizeof(axColor));
//    out.write(reinterpret_cast<char*>(&_r), sizeof(double));
//    out.write(reinterpret_cast<char*>(&_g), sizeof(double));
//    out.write(reinterpret_cast<char*>(&_b), sizeof(double));
//    out.write(reinterpret_cast<char*>(&_a), sizeof(double));
}

void axColor::SerializeInput(fstream& in)
{
    in.read(reinterpret_cast<char*>(this), sizeof(axColor));
//    in.read(reinterpret_cast<char*>(&_r), sizeof(double));
//    in.read(reinterpret_cast<char*>(&_g), sizeof(double));
//    in.read(reinterpret_cast<char*>(&_b), sizeof(double));
//    in.read(reinterpret_cast<char*>(&_a), sizeof(double));
}