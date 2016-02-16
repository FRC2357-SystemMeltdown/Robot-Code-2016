/*
 * Pixy.h
 *
 *  Created on: Feb 12, 2016
 *      Author: Robotics
 */

#ifndef SRC_PIXY_PIXY_H_
#define SRC_PIXY_PIXY_H_

#include <SerialPort.h>
#include "PixyPacket.h"
#include "PixyException.h"
#include <bitset>

namespace std {

class Pixy: public SerialPort {
public:

	typedef bitset<8> byte;

	SerialPort pixy;
	Port port = kMXP;
	PixyException pExc;
	PixyPacket packets[7];
	string print;

	Pixy() {
		//pixy.SerialPort(19200, port);
		pixy(19200, port);
		pixy.SetReadBufferSize(14);


	}
	virtual ~Pixy();
	virtual int cvt(char upper, char lower){
		return ((static_cast<int>(upper) & 0xff) << 8) | (static_cast<int>(lower) & 0xff);
	}

	virtual void pixyReset() {
		pixy.Reset();
	}
	virtual PixyPacket readPacket(int Signature) throw (PixyException){
		int Checksum;
		int Sig;
		char rawData[32];
		int bytesRead;
		try{
				 bytesRead = pixy.Read(rawData, 32);
		} catch (runtime_error& e){

		}
		if(bytesRead < 32) {
			return nullptr;
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
					break;
				}
				packets[Sig - 1].X = cvt(rawData[i+9], rawData[i+8]);
				packets[Sig - 1].Y = cvt(rawData[i+11], rawData[i+10]);
				packets[Sig - 1].Width = cvt(rawData[i+13], rawData[i+12]);
				packets[Sig - 1].Height = cvt(rawData[i+15], rawData[i+14]);

				if (Checksum != Sig + packets[Sig - 1].X + packets[Sig - 1].Y + packets[Sig - 1].Width + packets[Sig - 1].Height){
					packets[Sig - 1] = nullptr;
					throw pExc;
				}
				break;
			}
		}

		PixyPacket pkt = packets[Signature - 1];
		packets[Signature - 1] = nullptr;
		return pkt;
	}








};

} /* namespace std */

#endif /* SRC_PIXY_PIXY_H_ */
