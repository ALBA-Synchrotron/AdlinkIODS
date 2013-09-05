static const char *RcsId = "$Header:  $";
//+=============================================================================
//
// file :         AdlinkIOCounter.cpp
//
// description :  C++ source for the AdlinkIOCounter and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                AdlinkIOCounter are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name|  Method name
//	----------------------------------------
//  State   |  dev_state()
//  Status  |  dev_status()
//  Reset   |  reset()
//  Start   |  start()
//
//===================================================================


#include <tango.h>
#include <AdlinkIOCounter.h>
#include <AdlinkIOCounterClass.h>

#include "CounterDeviceInterface.h"

namespace AdlinkIOCounter_ns
{


	CounterDeviceInterface & AdlinkIOCounter::device()
	{	return *static_cast<CounterDeviceInterface*>(this->m_device); }
	const CounterDeviceInterface& AdlinkIOCounter::device() const
	{	return *static_cast<const CounterDeviceInterface*>(this->m_device); }

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::AdlinkIOCounter(string &s)
// 
// description : 	constructor for simulated AdlinkIOCounter
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
AdlinkIOCounter::AdlinkIOCounter(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str())
{
	init_device();
}

AdlinkIOCounter::AdlinkIOCounter(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s)
{
	init_device();
}

AdlinkIOCounter::AdlinkIOCounter(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d)
{
	init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::delete_device()
{
	//	Delete device's allocated object

	if (this->m_device)
		AdlDeviceFactorySingleton::release(&this->m_device, AdlDeviceFactorySingleton_::ModeCounter );
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::init_device()
{
	INFO_STREAM << "AdlinkIOCounter::AdlinkIOCounter() create device " << device_name << endl;

	this->m_device = 0;
	
	// Initialise variables to default values
	//--------------------------------------------
	get_device_property();

	attr_Value_read = &this->m_value;
	attr_StatusRegister_read = &this->m_statusRegister;
	//attr_SoftwareControlGate_write;
	//attr_SoftwareControlUpDown_write;
	attr_Mode_read = &attr_Mode_write;
	attr_SourceTimeBase_read = &attr_SourceTimeBase_write;
	attr_SourceGate_read = &attr_SourceGate_write;
	attr_SourceUpDown_read = &attr_SourceUpDown_write;
	attr_PolarityLowGate_read = &attr_PolarityLowGate_write;
	attr_PolarityLowUpDown_read = &attr_PolarityLowUpDown_write;
	attr_PolarityLowClockEn_read = &attr_PolarityLowClockEn_write;
	attr_PolarityLowOutput_read = &attr_PolarityLowOutput_write;
	attr_InitialCount_read = &attr_InitialCount_write;
	attr_PulseDelay_read = &attr_PulseDelay_write;
	attr_PulseWidth_read = &attr_PulseWidth_write;

	std::stringstream bID(this->boardID);
	this->m_cardNumber = 0;
	bID >> m_cardNumber;

	this->m_boardParams = AdlDeviceFactorySingleton::get_board_params(this->boardType);
	if( (!this->m_boardParams) ) {
		this->set_state(Tango::FAULT);
		std::stringstream ss;
		ss	<< "Unsupported board type \""
			<< this->boardType
			<< "\", recheck BoardType property.";
		this->set_status(ss.str());
		return;
	}

	if ( this->counterID < 0 || this->counterID > 1 ) {
		this->set_state(Tango::FAULT);
		std::stringstream ss;
		ss	<< "Invalid CounterID \""
			<< this->counterID
			<< "\", only \"0\" and \"1\" are valid values for this property.";
		this->set_status(ss.str());
		return;
	}

	if ( NoError != AdlDeviceFactorySingleton::get(
					&this->m_device,
					this->m_boardParams->typeName,
					this->m_cardNumber,
					AdlDeviceFactorySingleton_::ModeCounter ))
	{
		this->set_state(Tango::FAULT);
		std::stringstream ss;
		ss	<<	"Error getting control to the board. Please, check that"
				" BoardID \"" << this->boardID << "\""
				" makes sense for BoardType \"" << this->boardType << "\""
				" and that no more than the maximum available counters are"
				" being used from this card.";
		this->set_status(ss.str());
		return;
	}

	try {
		device().set_counter_id(this->counterID);
		device().software_control_enable(0);
	} catch (...) {
		this->set_state(Tango::FAULT);
		this->set_status("Unexpected error finishing initialization.");
		return;
	}
	
	this->set_state(Tango::STANDBY);
	this->set_status("Card properly detected.");
}


//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::get_device_property()
// 
// description : 	Read the device properties from database.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::get_device_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read device properties from database.(Automatic code generation)
	//------------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("BoardType"));
	dev_prop.push_back(Tango::DbDatum("BoardID"));
	dev_prop.push_back(Tango::DbDatum("CounterID"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
	Tango::DbDatum	def_prop, cl_prop;
	AdlinkIOCounterClass	*ds_class =
		(static_cast<AdlinkIOCounterClass *>(get_device_class()));
	int	i = -1;

	//	Try to initialize BoardType from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  boardType;
	else {
		//	Try to initialize BoardType from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  boardType;
	}
	//	And try to extract BoardType value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  boardType;

	//	Try to initialize BoardID from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  boardID;
	else {
		//	Try to initialize BoardID from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  boardID;
	}
	//	And try to extract BoardID value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  boardID;

	//	Try to initialize CounterID from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  counterID;
	else {
		//	Try to initialize CounterID from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  counterID;
	}
	//	And try to extract CounterID value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  counterID;



	//	End of Automatic code generation
	//------------------------------------------------------------------

}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::always_executed_hook()
{
	
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
	//	Add your own code here
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_Value
// 
// description : 	Extract real attribute values for Value acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_Value(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_Value(Tango::Attribute &attr) entering... "<< endl;
	device().read(this->m_value);
	attr.set_value(attr_Value_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_StatusRegister
// 
// description : 	Extract real attribute values for StatusRegister acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_StatusRegister(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_StatusRegister(Tango::Attribute &attr) entering... "<< endl;
	this->m_statusRegister = device().status_register();
	attr.set_value(attr_StatusRegister_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PolarityLowGate
// 
// description : 	Extract real attribute values for PolarityLowGate acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PolarityLowGate(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PolarityLowGate(Tango::Attribute &attr) entering... "<< endl;

	*attr_PolarityLowGate_read = device().m_polarityLowGate;
	attr.set_value(attr_PolarityLowGate_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PolarityLowGate
// 
// description : 	Write PolarityLowGate attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PolarityLowGate(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PolarityLowGate(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_PolarityLowGate_write);
	device().m_polarityLowGate = attr_PolarityLowGate_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PolarityLowUpDown
// 
// description : 	Extract real attribute values for PolarityLowUpDown acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PolarityLowUpDown(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PolarityLowUpDown(Tango::Attribute &attr) entering... "<< endl;

	*attr_PolarityLowUpDown_read = device().m_polarityLowUpDown;
	attr.set_value(attr_PolarityLowUpDown_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PolarityLowUpDown
// 
// description : 	Write PolarityLowUpDown attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PolarityLowUpDown(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PolarityLowUpDown(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_PolarityLowUpDown_write);
	device().m_polarityLowUpDown = attr_PolarityLowUpDown_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PolarityLowClockEn
// 
// description : 	Extract real attribute values for PolarityLowClockEn acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PolarityLowClockEn(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PolarityLowClockEn(Tango::Attribute &attr) entering... "<< endl;

	*attr_PolarityLowClockEn_read = device().m_polarityLowClockEn;
	attr.set_value(attr_PolarityLowClockEn_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PolarityLowClockEn
// 
// description : 	Write PolarityLowClockEn attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PolarityLowClockEn(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PolarityLowClockEn(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_PolarityLowClockEn_write);
	device().m_polarityLowClockEn = attr_PolarityLowClockEn_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PolarityLowOutput
// 
// description : 	Extract real attribute values for PolarityLowOutput acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PolarityLowOutput(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PolarityLowOutput(Tango::Attribute &attr) entering... "<< endl;

	*attr_PolarityLowOutput_read = device().m_polarityLowOutput;
	attr.set_value(attr_PolarityLowOutput_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PolarityLowOutput
// 
// description : 	Write PolarityLowOutput attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PolarityLowOutput(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PolarityLowOutput(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_PolarityLowOutput_write);
	device().m_polarityLowOutput = attr_PolarityLowOutput_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_InitialCount
// 
// description : 	Extract real attribute values for InitialCount acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_InitialCount(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_InitialCount(Tango::Attribute &attr) entering... "<< endl;

	if (device().m_mode > 3 )
		return;
	
	*attr_InitialCount_read = device().m_initialCount;
	attr.set_value(attr_InitialCount_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_InitialCount
// 
// description : 	Write InitialCount attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_InitialCount(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_InitialCount(Tango::WAttribute &attr) entering... "<< endl;

	if (device().m_mode > 3 )
		Tango::Except::throw_exception(
				"Can't write InitialCount right now.",
				"Initial count only makes sense for modes 1~3.",
				__PRETTY_FUNCTION__ );
	
	attr.get_write_value(attr_InitialCount_write);
	device().m_initialCount = attr_InitialCount_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PulseDelay
// 
// description : 	Extract real attribute values for PulseDelay acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PulseDelay(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PulseDelay(Tango::Attribute &attr) entering... "<< endl;

	if (device().m_mode < 4 )
		return;
	
	*attr_PulseDelay_read = device().m_pulseDelay;
	attr.set_value(attr_PulseDelay_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PulseDelay
// 
// description : 	Write PulseDelay attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PulseDelay(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PulseDelay(Tango::WAttribute &attr) entering... "<< endl;

	if (device().m_mode < 4 )
		Tango::Except::throw_exception(
				"Can't write PulseDelay right now.",
				"It only makes sense for modes 4~8.",
				__PRETTY_FUNCTION__ );
		
	attr.get_write_value(attr_PulseDelay_write);
	device().m_pulseDelay = attr_PulseDelay_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_PulseWidth
// 
// description : 	Extract real attribute values for PulseWidth acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_PulseWidth(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_PulseWidth(Tango::Attribute &attr) entering... "<< endl;

	if (device().m_mode < 4 )
		return;
	
	*attr_PulseWidth_read = device().m_pulseWidth;
	attr.set_value(attr_PulseWidth_read);

}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_PulseWidth
// 
// description : 	Write PulseWidth attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_PulseWidth(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_PulseWidth(Tango::WAttribute &attr) entering... "<< endl;

	if (device().m_mode < 4 )
		Tango::Except::throw_exception(
				"Can't write PulseWidth right now.",
				"It only makes sense for modes 4~8.",
				__PRETTY_FUNCTION__ );
	
	attr.get_write_value(attr_PulseWidth_write);
	device().m_pulseWidth = attr_PulseWidth_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_Mode
// 
// description : 	Extract real attribute values for Mode acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_Mode(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_Mode(Tango::Attribute &attr) entering... "<< endl;

	*attr_Mode_read = device().m_mode;
	attr.set_value(attr_Mode_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_Mode
// 
// description : 	Write Mode attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_Mode(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_Mode(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_Mode_write);
	device().m_mode = attr_Mode_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_SourceTimeBase
// 
// description : 	Extract real attribute values for SourceTimeBase acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_SourceTimeBase(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_SourceTimeBase(Tango::Attribute &attr) entering... "<< endl;

	*attr_SourceTimeBase_read = device().m_sourceTimeBaseExternal ? 1 : 0;
	attr.set_value(attr_SourceTimeBase_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_SourceTimeBase
// 
// description : 	Write SourceTimeBase attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_SourceTimeBase(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_SourceTimeBase(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_SourceTimeBase_write);
	device().m_sourceTimeBaseExternal = attr_SourceTimeBase_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_SourceGate
// 
// description : 	Extract real attribute values for SourceGate acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_SourceGate(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_SourceGate(Tango::Attribute &attr) entering... "<< endl;
	
	*attr_SourceGate_read = device().m_sourceGateExternal ? 1 : 0;
	attr.set_value(attr_SourceGate_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_SourceGate
// 
// description : 	Write SourceGate attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_SourceGate(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_SourceGate(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_SourceGate_write);
	device().m_sourceGateExternal = attr_SourceGate_write;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_SourceUpDown
// 
// description : 	Extract real attribute values for SourceUpDown acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_SourceUpDown(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_SourceUpDown(Tango::Attribute &attr) entering... "<< endl;

	*attr_SourceUpDown_read = device().m_sourceUpDownExternal ? 1 : 0;
	attr.set_value(attr_SourceUpDown_read);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_SourceUpDown
// 
// description : 	Write SourceUpDown attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_SourceUpDown(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_SourceUpDown(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_SourceUpDown_write);
	device().m_sourceUpDownExternal = attr_SourceUpDown_write;
}


//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_SoftwareControlGate
// 
// description : 	Extract real attribute values for SoftwareControlGate acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_SoftwareControlGate(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_SoftwareControlGate(Tango::Attribute &attr) entering... "<< endl;

	assert(false);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_SoftwareControlGate
// 
// description : 	Write SoftwareControlGate attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_SoftwareControlGate(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_SoftwareControlGate(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_SoftwareControlGate_write);
	device().software_control_gate(attr_SoftwareControlGate_write);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::read_SoftwareControlUpDown
// 
// description : 	Extract real attribute values for SoftwareControlUpDown acquisition result.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::read_SoftwareControlUpDown(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::read_SoftwareControlUpDown(Tango::Attribute &attr) entering... "<< endl;

	assert(false);
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkIOCounter::write_SoftwareControlUpDown
// 
// description : 	Write SoftwareControlUpDown attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdlinkIOCounter::write_SoftwareControlUpDown(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdlinkIOCounter::write_SoftwareControlUpDown(Tango::WAttribute &attr) entering... "<< endl;

	attr.get_write_value(attr_SoftwareControlUpDown_write);
	device().software_control_updown(attr_SoftwareControlUpDown_write);
}



//+------------------------------------------------------------------
/**
 *	method:	AdlinkIOCounter::reset
 *
 *	description:	method to execute "Reset"
 *	Halts the timer/counter operation and reload the initial value of the timer/counter.
 *
 *
 */
//+------------------------------------------------------------------
void AdlinkIOCounter::reset()
{
	DEBUG_STREAM << "AdlinkIOCounter::reset(): entering... !" << endl;

	try {
		device().software_control_enable(0);
		device().reset();
	} catch(...) {
		this->set_state(Tango::FAULT);
		this->set_status("Error while trying to reset.");
		throw;
	}
	this->set_state(Tango::STANDBY);
	this->set_status("Card properly detected.");
}

//+------------------------------------------------------------------
/**
 *	method:	AdlinkIOCounter::start
 *
 *	description:	method to execute "Start"
 *	Starts measurement tasks. Counter has to be configured first!
 *
 *
 */
//+------------------------------------------------------------------
void AdlinkIOCounter::start()
{
	DEBUG_STREAM << "AdlinkIOCounter::start(): entering... !" << endl;

	try {
		device().software_control_enable(0);
		device().setup();
		device().software_control_enable(1);
	} catch(...) {
		this->set_state(Tango::FAULT);
		this->set_status("Error trying to configure the card (Start command).");
		throw;
	}
	this->set_state(Tango::RUNNING);
	this->set_status("Card is now counting.");
}


}	//	namespace