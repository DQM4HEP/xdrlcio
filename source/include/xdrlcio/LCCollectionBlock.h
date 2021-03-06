  /// \file LCCollectionBlock.h
/*
 *
 * LCCollectionBlock.h header template automatically generated by a class generator
 * Creation date : ven. f�vr. 12 2016
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


#ifndef LCCOLLECTIONBLOCK_H
#define LCCOLLECTIONBLOCK_H

#include "xdrstream/xdrstream.h"

#include "EVENT/LCCollection.h"
#include "IOIMPL/LCEventIOImpl.h"

namespace xdrlcio
{

class LCObjectHandler;
class XdrLCEvent;

/** 
 *  @brief  LCCollectionBlock class
 */ 
class LCCollectionBlock : public xdrstream::Block
{
public:
	/**
	 *  @brief  Constructor
	 */
	LCCollectionBlock(xdrstream::XdrStream *pXdrStream,
			const std::string &name, const std::string &type, LCObjectHandler *pLCObjectHandler);

	/**
	 *  @brief  Destructor
	 */
	~LCCollectionBlock();

	/**
	 *  @brief  Perform read / write operation
	 */
	xdrstream::Status stream(xdrstream::StreamingMode mode, xdrstream::IODevice *pDevice, xdrstream::xdr_version_t version);

	/**
	 *  @brief  Get the block version. Written in the device
	 */
	xdrstream::xdr_version_t getVersion() const;

	/**
	 *  @brief  Set the collection to write
	 */
	void setCollection(const EVENT::LCCollection *pLCCollection);

	/**
	 *  @brief  Set the event ptr to fill the collection with
	 */
	void setEventPtr(XdrLCEvent **pLCEventPtr);

protected:
	std::string                             m_type;
	const EVENT::LCCollection              *m_pLCCollection;
	XdrLCEvent                            **m_pLCEventPtr;
	LCObjectHandler                        *m_pLCObjectHandler;
}; 

} 

#endif  //  LCCOLLECTIONBLOCK_H
