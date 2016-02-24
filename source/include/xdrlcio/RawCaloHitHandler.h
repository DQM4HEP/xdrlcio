  /// \file RawCaloHitHandler.h
/*
 *
 * RawCaloHitHandler.h header template automatically generated by a class generator
 * Creation date : sam. f�vr. 20 2016
 *
 * This file is part of xdrlcio libraries.
 * 
 * xdrlcio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * xdrlcio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with xdrlcio.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef RAWCALOHITHANDLER_H
#define RAWCALOHITHANDLER_H

#include "xdrlcio/LCObjectHandler.h"

namespace xdrlcio
{

/** 
 *  @brief  RawCaloHitHandler class
 */ 
class RawCaloHitHandler : public LCObjectHandler 
{
public:
	/**
	 *  @brief  Destructor
	 */
	~RawCaloHitHandler() { /* np */ }

	/**
	 *  @brief  Reads cluster objects from an XDR device.
	 */
	xdrstream::Status read(xdrstream::IODevice *pDevice, EVENT::LCObject *&pLCObject);

	/**
	 *  @brief  Writes cluster objects to an SIO stream.
	 */
	xdrstream::Status write(xdrstream::IODevice *pDevice, const EVENT::LCObject *const pLCObject);
}; 

} 

#endif  //  RAWCALOHITHANDLER_H