static const char *RcsId = "$Header$";
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible to create
//               all class singletin for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
//
// $Author: rsune $
//
// $Revision: 7388 $
//
//
//
// copyleft :   CELLS/ALBA
//		Edifici Ciences Nord
//		Campus Universitari de Bellaterra
//		Universitat Autonoma de Barcelona
//		08193 Bellaterra, Barcelona, SPAIN
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//=============================================================================


#include <tango.h>
#include "aio/AdlinkAIOClass.h"
#include "dio/AdlinkDIOClass.h"
#include "counter/AdlinkIOCounterClass.h"

/**
 *	Create AdlinkIODSClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{
	add_class(AdlinkDIO_ns::AdlinkDIOClass::init("AdlinkDIO"));
	add_class(AdlinkAIO_ns::AdlinkAIOClass::init("AdlinkAI"));
	add_class(AdlinkAIO_ns::AdlinkAIOClass::init("AdlinkAO"));
	add_class(AdlinkIOCounter_ns::AdlinkIOCounterClass::init("AdlinkIOCounter"));
}


