/*
 * Pixy.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXY_H_
#define SRC_PIXY_PIXY_H_

#include "SerialPort.h"
#include "PixyPacket.h"
//#include "PixyException.h"
#include <bitset>


class Pixy {
public:

	typedef std::bitset<8> byte;

	SerialPort pixy;
	//PixyException pExc;
	PixyPacket packets[7];
	std::string print;

	Pixy();
	virtual ~Pixy();
	static int cvt(char upper, char lower);
	virtual void pixyReset();
	PixyPacket readPacket(int Signature) throw (std::exception);

};



#endif /* SRC_PIXY_PIXY_H_ */
