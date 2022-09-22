struct Vector2 {
	float x;
	float y;
	Vector2();
	Vector2(const float& x, const float& y);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);
	Vector2 operator+(const Vector2& addend);
	Vector2 operator-(const Vector2& subtrahend);
	Vector2 operator*(const float& multiplier);
	Vector2 operator/(const float& divisor);
	float magnitude();
	Vector2 normalized();
	Vector2 clampMagnitude(const float& maxMagnitude);
};