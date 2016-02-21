/*
 * PixyPacket.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXYPACKET_H_
#define SRC_PIXY_PIXYPACKET_H_

class PixyPacket {
public:
	static const PixyPacket UNINITIALIZED;

	int X;
	int Y;
	int Width;
	int Height;

	PixyPacket()
		: X(-1), Y(-1), Width(-1), Height(-1)
	{
	}

	PixyPacket(int x, int y, int width, int height) : X(x), Y(y), Width(width), Height(height)
	{

	}

	bool operator==(const PixyPacket& that)
	{
		return (this->X == that.X &&
				this->Y == that.Y &&
				this->Width == that.Width &&
				this->Height == that.Height);
	}

	int getX();
};


#endif /* SRC_PIXY_PIXYPACKET_H_ */
