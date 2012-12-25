/*
 BlockPlacement 1.0
 Copyright (c) 2012 Will Sackfield
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <vector>

namespace BP
{
	struct Size
	{
		int width;
		int height;
		Size(int _width,int _height) : width(_width), height(_height) {}
	};
	
	const Size SizeDefault(0,0);
	
	struct Point
	{
		int x;
		int y;
		Point(int _x,int _y) : x(_x), y(_y) {}
	};
	
	const Point PointDefault(0,0);
	
	struct Rect : Size,Point
	{
		Rect(int _x,int _y,int _width,int _height) : Size(_width,_height), Point(_x,_y) {}
	};
	
	const Rect RectDefault(0,0,0,0);
	
	std::vector<std::vector<Rect> > findBlockPlacements(Size square,std::vector<Size> blocks);
}
