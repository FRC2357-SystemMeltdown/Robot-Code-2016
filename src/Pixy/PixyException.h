/*
 * PixyException.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXYEXCEPTION_H_
#define SRC_PIXY_PIXYEXCEPTION_H_

#include <exception>

namespace std {

class PixyException: public exception {
public:

	PixyException(){
		message = exception().what(); // Not sure what this file is trying to accomplish.
	}								  // The java code has super(message), but I'm not quite sure what that is supposed to accomplish.
	virtual ~PixyException();

private:

	const string message;
};

} /* namespace std */

#endif /* SRC_PIXY_PIXYEXCEPTION_H_ */
