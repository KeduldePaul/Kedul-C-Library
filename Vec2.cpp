#include "Vec2.h"

Vec2::Vec2() : x(0), y(0) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}
Vec2::~Vec2() {}

void Vec2::operator+=(const Vec2& v) {
    x += v.x;
    y += v.y;
}

void Vec2::operator-=(const Vec2& v) {
    x -= v.x;
    y -= v.y;
}

void Vec2::operator*=(float sc) {
    x *= sc;
    y *= sc;
}

void Vec2::operator/=(float sc) {
    if (sc == 0) throw std::invalid_argument("Division by zero");
    x /= sc;
    y /= sc;
}

Vec2 Vec2::operator+(const Vec2& v) const {
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2& v) const {
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(float sc) const {
    return Vec2(x * sc, y * sc);
}

Vec2 Vec2::operator/(float sc) const {
    if (sc == 0) throw std::invalid_argument("Division by zero");
    return Vec2(x / sc, y / sc);
}

Vec2 operator*(float scalar, const Vec2& v) {
    return Vec2(scalar * v.x, scalar * v.y);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
    os << "v[" << v.x << ", " << v.y << "]";
    return os;
}

constexpr float Vec2::magSq() const {
    return (x * x) + (y * y);
}

float Vec2::mag() const {
    return std::sqrt(magSq());
}

void Vec2::norm() {
    float magnitude = mag();
    if (magnitude != 0) *this /= magnitude;
}

void Vec2::setMag(float magnitude) {
    norm();
    *this *= magnitude;
}

void Vec2::limit(float limit) {
    if (magSq() > limit * limit) setMag(limit);
}

constexpr float Vec2::dot(const Vec2& v) const {
    return (x * v.x) + (y * v.y);
}

float Vec2::angleBetween(const Vec2& v) const {
    float m1 = mag();
    float m2 = v.mag();
    if (m1 == 0 || m2 == 0) return 0;
    return std::acos(dot(v) / (m1 * m2));
}

float Vec2::angle() const {
    return std::atan2(y, x);
}

float Vec2::crossProdZ(const Vec2& v) const {
    return (x * v.y) - (y * v.x);
}

void Vec2::rotatePos90() {
    float temp = x;
    x = -y;
    y = temp;
}

void Vec2::rotateNeg90() {
    float temp = x;
    x = y;
    y = temp;
}

void Vec2::rotate180() {
    *this *= -1;
}

void Vec2::rotate(float angle) {
    float c = std::cos(angle);
    float s = std::sin(angle);

    float xT = c * x + -s * y;
    float yT = s * x +  c * y;

    x = xT;
    y = yT;
}

void Vec2::transform(float a, float b, float c, float d, float e, float f) {
    float xT = a * x + b * y + c;
    float yT = d * x + e * y + f;

    x = xT;
    y = yT;
}

auto Vec2::makeTransform(float a, float b, float c, float d, float e, float f) {
    return [=](Vec2& v) { v.transform(a, b, c, d, e, f); };
}

Vec2 Vec2::fromAngle(float angle, float r) {
    float vx = std::cos(angle) * r;
    float vy = std::sin(angle) * r;
    return Vec2(vx, vy);
}

Vec2 Vec2::random2D() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> dis(0, TWO_PI);

    return fromAngle(dis(gen), 1);
}

float Vec2::distBetweenSq(const Vec2& v1, const Vec2& v2) {
    return (v2 - v1).magSq();
}

float Vec2::distBetween(const Vec2& v1, const Vec2& v2) {
    return (v2 - v1).mag();
}

bool Vec2::operator==(const Vec2& v) const {
    return x == v.x && y == v.y;
}

bool Vec2::operator!=(const Vec2& v) const {
    return !(*this == v);
}
