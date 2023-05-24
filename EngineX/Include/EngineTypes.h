//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once
typedef unsigned char uchar;

	//-----------------------------------------------------------------
	//-----------------------------------------------------------------

	struct exVector2
	{
		float x, y;

		exVector2() : x(0.0f), y(0.0f)
		{}

		exVector2(float _x, float _y) : x(_x), y(_y)
		{}
	};

	//-----------------------------------------------------------------
	//-----------------------------------------------------------------

	struct exVector2Int
	{
		int x, y;

		exVector2Int() : x(0), y(0)
		{}

		exVector2Int(int _x, int _y) : x(_x), y(_y) 
		{}

		exVector2Int(exVector2 other) : x((int)other.x), y((int)other.y)
		{}
	};

	//-----------------------------------------------------------------
	//-----------------------------------------------------------------

	struct exColor
	{
		uchar r;
		uchar g;
		uchar b;
		uchar a;

		exColor() : r(0), g(0), b(0), a(0)
		{}

		exColor(uchar _r, uchar _g, uchar _b, uchar _a = 255)
			: r(_r), g(_g), b(_b), a(_a)
		{}
	};