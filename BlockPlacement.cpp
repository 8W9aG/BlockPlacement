/*
 BlockPlacement 1.0
 Copyright (c) 2012 Will Sackfield
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "BlockPlacement.h"

namespace BP
{
	void findNextBlockPlacement(Size square,std::vector<Size> blocks,std::vector<std::vector<Rect> >* blockPlacements,std::vector<Rect> currentPlacement)
	{
		Point startPoint = PointDefault;
		for(int i=0;i<currentPlacement.size();i++)
		{
			Rect placement = currentPlacement[i];
			if((placement.x+placement.width)%square.width > startPoint.x)
				startPoint.x = placement.x+placement.width;
			if(placement.y+placement.height > startPoint.y)
				startPoint.y = placement.y+placement.height;
		}
		
		int currentX = 0;
		for(int i=0;i<currentPlacement.size();i++)
		{
			Rect placement = currentPlacement[i];
			if(placement.y+placement.height == startPoint.y && placement.x+placement.width > currentX)
				currentX = placement.x+placement.width;
		}
		
		if(square.width == currentX && square.height == startPoint.y)
		{
			blockPlacements->push_back(currentPlacement);
			return;
		}
		
		for(int i=0;i<blocks.size();i++)
		{
			Size blockSize = blocks[i];
			if(startPoint.x+blockSize.width <= square.width && startPoint.y+blockSize.height <= square.height)
			{
				Rect blockRect(startPoint.x,startPoint.y,blockSize.width,blockSize.height);
				currentPlacement.push_back(blockRect);
				findNextBlockPlacement(square,blocks,blockPlacements,currentPlacement);
				currentPlacement.pop_back();
			}
		}
	}
	
	std::vector<std::vector<Rect> > findBlockPlacements(Size square,std::vector<Size> blocks)
	{
		std::vector<std::vector<Rect> > blockPlacements;
		findNextBlockPlacement(square,blocks,&blockPlacements,std::vector<Rect>());
		return blockPlacements;
	}
}
