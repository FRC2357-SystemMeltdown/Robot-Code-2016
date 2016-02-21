/*
 * Pixy.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: Robotics
 */

#include "Pixy.h"

Pixy::Pixy()
	:pixy(19200, SerialPort::kMXP)
	{
		pixy.SetReadBufferSize(14);
	}

Pixy::~Pixy(){

}

int Pixy::cvt(char upper, char lower){
	return ((static_cast<int>(upper) & 0xff) << 8) | (static_cast<int>(lower) & 0xff);
}

void Pixy::pixyReset(){
	pixy.Reset();
}

PixyPacket Pixy::readPacket(int signature) throw (std::exception){
	int Checksum;
	int Sig;
	char rawData[32];
	int bytesRead;
	try{
			 bytesRead = pixy.Read(rawData, 32);
	} catch (std::runtime_error& e){

	}
	if(bytesRead < 32) {
		return PixyPacket::UNINITIALIZED;
	}
	for (int i = 0; i <= 16; i++) {
		int syncWord = cvt(rawData[i+1], rawData[i+0]);
		if (syncWord == 0xaa55){
			syncWord = cvt(rawData[i+3], rawData[i+2]);

			if(syncWord != 0xaa55){
				i -=2;
			}

			Checksum = cvt(rawData[i+5], rawData[i+4]);
			Sig  = cvt(rawData[i+7], rawData[i+6]);
			if(Sig <= 0 || Sig > (sizeof(packets)/sizeof(*packets))){
				//std::cout << "Breaking" << std::endl;
				break;
			}
			packets[Sig - 1].X = cvt(rawData[i+9], rawData[i+8]);
			packets[Sig - 1].Y = cvt(rawData[i+11], rawData[i+10]);
			packets[Sig - 1].Width = cvt(rawData[i+13], rawData[i+12]);
			packets[Sig - 1].Height = cvt(rawData[i+15], rawData[i+14]);

			if (Checksum != Sig + packets[Sig - 1].X + packets[Sig - 1].Y + packets[Sig - 1].Width + packets[Sig - 1].Height){
				packets[Sig - 1] = PixyPacket::UNINITIALIZED;
				//throw std::exception->;
			}
			break;
		}
	}

	PixyPacket pkt = packets[signature - 1];
	packets[signature - 1] = PixyPacket::UNINITIALIZED;
	return pkt;
}
