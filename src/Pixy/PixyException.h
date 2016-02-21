/*
 * PixyException.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXYEXCEPTION_H_
#define SRC_PIXY_PIXYEXCEPTION_H_

#include <exception>



class PixyException: public std::exception {
public:

	PixyException();				  // The java code has super(message), but I'm not quite sure what that is supposed to accomplish.
	virtual ~PixyException();

private:

};


#endif /* SRC_PIXY_PIXYEXCEPTION_H_ */
