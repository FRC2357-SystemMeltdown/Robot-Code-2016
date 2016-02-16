/*
 * PixyController.h
 *
 *  Created on: Feb 16, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXYCONTROLLER_H_
#define SRC_PIXY_PIXYCONTROLLER_H_
#include "execinfo.h"


namespace std {

class PixyController {

	Pixy pixy;
	PixyPacket pkt;
	double error;
	const double ratio = 109;	//I assume this is the ratio of pixels to measured units at a set distance
	double objRatio = 0;
public:



	PixyController();
	virtual ~PixyController();

	double autoCenter();
};

} /* namespace std */

#endif /* SRC_PIXY_PIXYCONTROLLER_H_ */
