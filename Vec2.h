#pragma once

#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>
#include <random>

class Vec2 {
public:
    float x, y;

    Vec2();
    Vec2(float x, float y);
    ~Vec2();

    void operator+=(const Vec2& v);
    void operator-=(const Vec2& v);
    void operator*=(float sc);
    void operator/=(float sc);

    Vec2 operator+(const Vec2& v) const;
    Vec2 operator-(const Vec2& v) const;
    Vec2 operator*(float sc) const;
    Vec2 operator/(float sc) const;

    friend Vec2 operator*(float scalar, const Vec2& v);
    friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

    constexpr float magSq() const;
    float mag() const;
    void norm();
    void setMag(float magnitude);
    void limit(float limit);
    constexpr float dot(const Vec2& v) const;
    float angleBetween(const Vec2& v) const;
    float angle() const;
    float crossProdZ(const Vec2& v) const;

    void rotatePos90();
    void rotateNeg90();
    void rotate180();
    void rotate(float angle);
    /**
    * Matrix:
    * [a b c]
    * [d e f]
    */
    void transform(float a, float b, float c, float d, float e, float f);
    /**
     * Make transform function based on matrix.
     * [a b c]
     * [d e f]
     * Example:
     * auto shear = makeTransform(1, 2, 0, 0, 1, 0); 
     * Vec2 a(3, 5);
     * shear(a);
     * std::cout << a << std::endl; //v[13, 5]
     */
    static auto makeTransform(float a, float b, float c, float d, float e, float f);
    static Vec2 fromAngle(float angle, float r = 1.0f);
    static Vec2 random2D();
    static float distBetweenSq(const Vec2& v1, const Vec2& v2);
    static float distBetween(const Vec2& v1, const Vec2& v2);

    bool operator==(const Vec2& v) const;
    bool operator!=(const Vec2& v) const;

    static constexpr float PI = 3.141592653589793f;
    static constexpr float TWO_PI = 2 * PI;
};

#endif // VEC2_H