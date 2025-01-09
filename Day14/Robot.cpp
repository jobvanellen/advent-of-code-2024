#include "Robot.hpp"

Robot::Robot(int x, int y, int vx, int vy, int lx, int ly)
    : _x(x), _y(y), _vx(vx), _vy(vy), _lx(lx), _ly(ly)
    {}

void Robot::move(int seconds)
{
    _x += _vx * seconds;
    _y += _vy * seconds;

    handleLimits();
}

void Robot::handleLimits()
{
    _x = (_x % _lx + _lx) % _lx;
    _y = (_y % _ly + _ly) % _ly;
}

int Robot::getX() const { return _x; }
int Robot::getY() const { return _y; }
int Robot::getVX() const { return _vx; }
int Robot::getVY() const { return _vy; }
