#pragma once
#include <cmath>
#include <algorithm>

struct Vector2D {
    float x, y;

    Vector2D() : x(0.f), y(0.f) {}
    Vector2D(float X, float Y) : x(X), y(Y) {}

    Vector2D operator+(const Vector2D& o) const { return { x + o.x, y + o.y }; }
    Vector2D operator-(const Vector2D& o) const { return { x - o.x, y - o.y }; }
    Vector2D operator*(float f) const { return { x * f, y * f }; }
    
    float Length() const { return std::sqrt(x * x + y * y); }
    float Distance(const Vector2D& o) const { return (*this - o).Length(); }
};

struct Vector3D {
    float x, y, z;

    Vector3D() : x(0.f), y(0.f), z(0.f) {}
    Vector3D(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

    Vector3D operator+(const Vector3D& o) const { return { x + o.x, y + o.y, z + o.z }; }
    Vector3D operator-(const Vector3D& o) const { return { x - o.x, y - o.y, z - o.z }; }
    Vector3D operator*(float f) const { return { x * f, y * f, z * f }; }
    Vector3D operator/(float f) const { return { x / f, y / f, z / f }; }

    float Dot(const Vector3D& o) const { return x * o.x + y * o.y + z * o.z; }
    float Length() const { return std::sqrt(x * x + y * y + z * z); }
    float Length2D() const { return std::sqrt(x * x + y * y); }
    float Distance(const Vector3D& o) const { return (*this - o).Length(); }
    
    void Normalize() {
        x = std::isfinite(x) ? std::remainder(x, 360.0f) : 0.f;
        y = std::isfinite(y) ? std::remainder(y, 360.0f) : 0.f;
        z = 0.f;
    }
};

struct QAngle {
    float pitch, yaw, roll;

    QAngle() : pitch(0.f), yaw(0.f), roll(0.f) {}
    QAngle(float p, float y, float r) : pitch(p), yaw(y), roll(r) {}

    QAngle operator+(const QAngle& o) const { return { pitch + o.pitch, yaw + o.yaw, roll + o.roll }; }
    QAngle operator-(const QAngle& o) const { return { pitch - o.pitch, yaw - o.yaw, roll - o.roll }; }
    QAngle operator*(float f) const { return { pitch * f, yaw * f, roll * f }; }

    void Clamp() {
        pitch = std::clamp(pitch, -89.0f, 89.0f);
        while (yaw < -180.0f) yaw += 360.0f;
        while (yaw > 180.0f) yaw -= 360.0f;
        roll = 0.0f;
    }
};

struct Matrix3x4 {
    float data[3][4];
};

struct ViewMatrix {
    float matrix[4][4];

    Vector3D TransformPoint(const Vector3D& point) const {
        Vector3D result;
        result.x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2] + matrix[0][3];
        result.y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2] + matrix[1][3];
        float w = point.x * matrix[3][0] + point.y * matrix[3][1] + point.z * matrix[3][2] + matrix[3][3];
        if (w < 0.01f) return { 0, 0, 0 };
        float invW = 1.0f / w;
        result.x *= invW;
        result.y *= invW;
        return result;
    }
};
