#pragma once

class Robot
{
    public:
        Robot(int x, int y, int vx, int vy, int lx, int ly);

        ~Robot() = default;

        void move(int seconds);

        int getX() const;
        int getY() const;
        int getVX() const;
        int getVY() const;

    private:
        void handleLimits();

        int _x;
        int _y;

        const int _vx;
        const int _vy;

        const int _lx;
        const int _ly;

};