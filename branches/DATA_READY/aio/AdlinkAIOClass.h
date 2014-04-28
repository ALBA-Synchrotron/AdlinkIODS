//=============================================================================
//
// file :         AdlinkAIOClass.h
//
// description :  Include for the AdlinkAIOClass root class.
//                This class is represents the singleton class for
//                the AdlinkAIO device class.
//                It contains all properties and methods which the 
//                AdlinkAIO requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author: rsune $
//
// $Revision: 8649 $
//
//
//
// copyleft :   CELLS/ALBA
//		Edifici Ciences Nord
//		Campus Universitari de Bellaterra
//		Universitat Autonoma de Barcelona
//		08193 Bellaterra, Barcelona, SPAIN
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//=============================================================================

#ifndef _ADLINKIODSCLASS_H
#define _ADLINKIODSCLASS_H

#include <tango.h>
#include <AdlinkAIO.h>
#include "StatsCalculator.h"

namespace AdlinkAIO_ns
{//=====================================
//=====================================
//	Define classes for attributes
//=====================================
class ChannelSpectrumAttrib: public Tango::SpectrumAttr
{
	int m_channel;
public:
	ChannelSpectrumAttrib():SpectrumAttr("ChannelSpectrum", Tango::DEV_DOUBLE, Tango::READ_WRITE, LONG_MAX), m_channel(-1) {};
	ChannelSpectrumAttrib(const char *name, long data_type, Tango::AttrWriteType w_type, long s_size, int channel):SpectrumAttr(name,data_type,w_type,s_size), m_channel(channel) {};
	~ChannelSpectrumAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_ChannelSpectrum(att, m_channel);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_ChannelSpectrum(att, m_channel);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_ChannelSpectrum_allowed(ty);}
};

class ScalarValueAttrib: public Tango::Attr
{
	int m_channel;
public:
	ScalarValueAttrib():Attr("ScalarValue", Tango::DEV_DOUBLE, Tango::READ_WRITE), m_channel(-1) {};
	ScalarValueAttrib(const char *name, long data_type, Tango::AttrWriteType w_type, int channel):Attr(name,data_type,w_type), m_channel(channel) {};
	~ScalarValueAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_ScalarValue(att, m_channel);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_ScalarValue(att, m_channel);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_ScalarValue_allowed(ty);}
};

class ScalarStatisticAttrib: public Tango::Attr
{
	Stats::SelectedOperation m_operation;
	int m_channel;
public:
	ScalarStatisticAttrib() : Attr("ScalarStatisticAttrib", Tango::DEV_DOUBLE, Tango::READ), m_operation(Stats::OperationNone), m_channel(0) {};
	ScalarStatisticAttrib(const char *name, Stats::SelectedOperation operation, int channel) : Attr(name, Tango::DEV_DOUBLE, Tango::READ), m_operation(operation), m_channel(channel) {};
	~ScalarStatisticAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_ScalarStatistic(att, m_operation, m_channel);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_ScalarStatistic_allowed(ty);}
};

class SpectrumStatisticAttrib: public Tango::SpectrumAttr
{
	Stats::SelectedOperation m_operation;
	int m_channel;
public:
	SpectrumStatisticAttrib() : SpectrumAttr("SpectrumStatisticAttrib", Tango::DEV_DOUBLE, Tango::READ, LONG_MAX), m_operation(Stats::OperationNone), m_channel(0) {};
	SpectrumStatisticAttrib(const char *name, Stats::SelectedOperation operation, int channel) : SpectrumAttr(name, Tango::DEV_DOUBLE, Tango::READ, LONG_MAX), m_operation(operation), m_channel(channel) {};
	~SpectrumStatisticAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_SpectrumStatistic(att, m_operation, m_channel);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_SpectrumStatistic_allowed(ty);}
};

class FileNameAttrib: public Tango::Attr
{
public:
	FileNameAttrib():Attr("FileName", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~FileNameAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_FileName(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_FileName(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_FileName_allowed(ty);}
};

class DoubleDATAAttrib: public Tango::ImageAttr
{
public:
	DoubleDATAAttrib():ImageAttr("DoubleDATA", Tango::DEV_DOUBLE, Tango::READ_WRITE, LONG_MAX, 256) {};
	~DoubleDATAAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_DoubleDATA(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_DoubleDATA(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_DoubleDATA_allowed(ty);}
};

class RawDATAAttrib: public Tango::ImageAttr
{
public:
	RawDATAAttrib():ImageAttr("RawDATA", Tango::DEV_LONG, Tango::READ_WRITE, LONG_MAX, 256) {};
	~RawDATAAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_RawDATA(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_RawDATA(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_RawDATA_allowed(ty);}
};

class BufferedChannelsListAttrib: public Tango::SpectrumAttr
{
public:
	BufferedChannelsListAttrib():SpectrumAttr("BufferedChannelsList", Tango::DEV_STRING, Tango::READ_WRITE, 256) {};
	~BufferedChannelsListAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_BufferedChannelsList(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_BufferedChannelsList(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_BufferedChannelsList_allowed(ty);}
};

class BufferPeriodAttrib: public Tango::Attr
{
public:
	BufferPeriodAttrib():Attr("BufferPeriod", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~BufferPeriodAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_BufferPeriod(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_BufferPeriod(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_BufferPeriod_allowed(ty);}
};

class TriggerInfiniteAttrib: public Tango::Attr
{
public:
	TriggerInfiniteAttrib():Attr("TriggerInfinite", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~TriggerInfiniteAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_TriggerInfinite(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_TriggerInfinite(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_TriggerInfinite_allowed(ty);}
};

class TriggerModeAttrib: public Tango::Attr
{
public:
	TriggerModeAttrib():Attr("TriggerMode", Tango::DEV_USHORT, Tango::READ_WRITE) {};
	~TriggerModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_TriggerMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_TriggerMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_TriggerMode_allowed(ty);}
};

class TriggerSourcesAttrib: public Tango::Attr
{
public:
	TriggerSourcesAttrib():Attr("TriggerSources", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~TriggerSourcesAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_TriggerSources(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_TriggerSources(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_TriggerSources_allowed(ty);}
};

class TriggerLowLimitAttrib: public Tango::Attr
{
public:
	TriggerLowLimitAttrib():Attr("TriggerLowLimit", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~TriggerLowLimitAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_TriggerLowLimit(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_TriggerLowLimit(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_TriggerLowLimit_allowed(ty);}
};

class TriggerHighLimitAttrib: public Tango::Attr
{
public:
	TriggerHighLimitAttrib():Attr("TriggerHighLimit", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~TriggerHighLimitAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_TriggerHighLimit(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_TriggerHighLimit(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_TriggerHighLimit_allowed(ty);}
};

class MinRefSourceAttrib: public Tango::Attr
{
public:
	MinRefSourceAttrib():Attr("MinRefSource", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~MinRefSourceAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_MinRefSource(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_MinRefSource(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_MinRefSource_allowed(ty);}
};

class MaxRefSourceAttrib: public Tango::Attr
{
public:
	MaxRefSourceAttrib():Attr("MaxRefSource", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~MaxRefSourceAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_MaxRefSource(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_MaxRefSource(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_MaxRefSource_allowed(ty);}
};

class NumOfTriggersAttrib: public Tango::Attr
{
public:
	NumOfTriggersAttrib():Attr("NumOfTriggers", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~NumOfTriggersAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_NumOfTriggers(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_NumOfTriggers(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_NumOfTriggers_allowed(ty);}
};

class NumOfDisplayableTriggersAttrib: public Tango::Attr
{
public:
	NumOfDisplayableTriggersAttrib():Attr("NumOfDisplayableTriggers", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~NumOfDisplayableTriggersAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_NumOfDisplayableTriggers(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_NumOfDisplayableTriggers(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_NumOfDisplayableTriggers_allowed(ty);}
};

class ChannelSamplesPerTriggerAttrib: public Tango::Attr
{
public:
	ChannelSamplesPerTriggerAttrib():Attr("ChannelSamplesPerTrigger", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~ChannelSamplesPerTriggerAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_ChannelSamplesPerTrigger(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_ChannelSamplesPerTrigger(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_ChannelSamplesPerTrigger_allowed(ty);}
};

class SampleRateAttrib: public Tango::Attr
{
public:
	SampleRateAttrib():Attr("SampleRate", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~SampleRateAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_SampleRate(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_SampleRate(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_SampleRate_allowed(ty);}
};

class DelayAttrib: public Tango::Attr
{
public:
	DelayAttrib():Attr("Delay", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~DelayAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_Delay(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_Delay(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_Delay_allowed(ty);}
};

class DelaySourceAttrib: public Tango::Attr
{
public:
        DelaySourceAttrib():Attr("DelaySource", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~DelaySourceAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_DelaySource(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_DelaySource(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_DelaySource_allowed(ty);}
};

class LastValuesAttrib: public Tango::SpectrumAttr
{
public:
	LastValuesAttrib():SpectrumAttr("LastValues", Tango::DEV_DOUBLE, Tango::READ_WRITE, 256) {};
	~LastValuesAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_LastValues(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_LastValues(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_LastValues_allowed(ty);}
};

class DelayDataReadyAttrib: public Tango::Attr
{
public:
        DelayDataReadyAttrib():Attr("DelayDataReady", Tango::DEV_LONG, Tango::READ_WRITE) {};
	~DelayDataReadyAttrib() {};

	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<AdlinkAIO *>(dev))->read_DelayDataReady(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<AdlinkAIO *>(dev))->write_DelayDataReady(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<AdlinkAIO *>(dev))->is_DelayDataReady_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
class ExportFileCmd : public Tango::Command
{
public:
	ExportFileCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ExportFileCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ExportFileCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_ExportFile_allowed(any);}
};



class ImportFileCmd : public Tango::Command
{
public:
	ImportFileCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	ImportFileCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~ImportFileCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_ImportFile_allowed(any);}
};

class CalibrationLoadCmd : public Tango::Command
{
public:
	CalibrationLoadCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	CalibrationLoadCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~CalibrationLoadCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_CalibrationLoad_allowed(any);}
};

class CalibrationSaveCmd : public Tango::Command
{
public:
	CalibrationSaveCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	CalibrationSaveCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~CalibrationSaveCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_CalibrationSave_allowed(any);}
};

class CalibrationAutoCmd : public Tango::Command
{
public:
	CalibrationAutoCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	CalibrationAutoCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~CalibrationAutoCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_CalibrationAuto_allowed(any);}
};

class StopClass : public Tango::Command
{
public:
	StopClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StopClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StopClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_Stop_allowed(any);}
};



class StartCmd : public Tango::Command
{
public:
	StartCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StartCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StartCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_Start_allowed(any);}
};



class GetDataCmd : public Tango::Command
{
public:
	GetDataCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	GetDataCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~GetDataCmd() {};

	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<AdlinkAIO *>(dev))->is_GetData_allowed(any);}
};


//
// The AdlinkAIOClass singleton definition
//

class AdlinkAIOClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

	bool m_isInput;

	/// Vector added to remember which was the default Attribute list (w/out dynamic attrs)
	vector<string> default_Attribute_list;
	/// Function that diferentiates dynamic attributes from static ones
	bool isDynamicAttribute(string attrName);
	
	/// Function that removes dynamic attributes from the class attributes list
	void eraseDynamicAttributes(vector<Tango::Attr *> &att_list);
	
	/// Function that adds dynamic attributes to the devices attributes	 lists
	void addDynamicAttributes(const Tango::DevVarStringArray *devlist_ptr);
	
public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static AdlinkAIOClass *init(const char *);
	static AdlinkAIOClass *instance();
	~AdlinkAIOClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	AdlinkAIOClass(string &);
	static AdlinkAIOClass *_instanceAO;
	static AdlinkAIOClass *_instanceAI;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace AdlinkAIO_ns

#endif // _ADLINKIODSCLASS_H
