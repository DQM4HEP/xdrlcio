  /// \file LCRelationHandler.cc
/*
 *
 * LCRelationHandler.cc source template automatically generated by a class generator
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


#include "xdrlcio/LCRelationHandler.h"

#include "IOIMPL/LCRelationIOImpl.h"
#include "IMPL/LCFlagImpl.h"
#include "EVENT/LCIO.h"

namespace xdrlcio
{

class XdrLCRelation : public IOIMPL::LCRelationIOImpl
{
	friend class LCRelationHandler;
};

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

xdrstream::Status LCRelationHandler::read(xdrstream::IODevice *pDevice, EVENT::LCObject *&pLCObject)
{
	XdrLCRelation *pLCRelation = new XdrLCRelation();
	pLCObject = pLCRelation;

	XDR_STREAM( pDevice->readPointerReference( (void **) & pLCRelation->_from ) )
	XDR_STREAM( pDevice->readPointerReference( (void **) & pLCRelation->_to ) )

	if( IMPL::LCFlagImpl( m_lcFlag ).bitSet(  EVENT::LCIO::LCREL_WEIGHTED ) )
		XDR_STREAM( pDevice->read( & pLCRelation->_weight ) )

	return xdrstream::XDR_SUCCESS;
}

//----------------------------------------------------------------------------------------------------

xdrstream::Status LCRelationHandler::write(xdrstream::IODevice *pDevice, const EVENT::LCObject *const pLCObject)
{
	const EVENT::LCRelation *const pLCRelation
		= dynamic_cast< const EVENT::LCRelation * const>( pLCObject );

	XDR_STREAM( pDevice->writePointerReference( pLCRelation->getFrom() ) )
	XDR_STREAM( pDevice->writePointerReference( pLCRelation->getTo() ) )

	if( IMPL::LCFlagImpl( m_lcFlag ).bitSet(  EVENT::LCIO::LCREL_WEIGHTED ) )
	{
		float weight = pLCRelation->getWeight();
		XDR_STREAM( pDevice->write( & weight ) )
	}

	return xdrstream::XDR_SUCCESS;
}

} 

