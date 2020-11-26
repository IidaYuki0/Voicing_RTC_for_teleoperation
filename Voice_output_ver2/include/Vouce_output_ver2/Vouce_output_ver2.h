// -*- C++ -*-
/*!
 * @file  Vouce_output_ver2.h
 * @brief ModuleDescription
 * @date  $Date$
 *
 * $Id$
 */

#ifndef VOUCE_OUTPUT_VER2_H
#define VOUCE_OUTPUT_VER2_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include <string.h>
#include <MMSystem.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

#pragma comment(lib,"WinMM.Lib")

//âπê∫ÉtÉ@ÉCÉãÇÃì«Ç›çûÇ›
#define FILENAME "Move_forward.wav"
#define FILENAME "Turn_right.wav"
#define FILENAME "Turn_left.wav"
#define FILENAME "Move_back.wav"
#define FILENAME "Stop_state.wav"
#define FILENAME "Spin_right.wav"
#define FILENAME "Spin_left.wav"
#define FILENAME "Acc.wav"
#define FILENAME "dec.wav"
//âpåÍ
#define FILENAME "moving forward_eng.wav"
#define FILENAME "turn_right_eng.wav"
#define FILENAME "turn_left_eng.wav"
#define FILENAME "moving_back_eng.wav"
#define FILENAME "stopping_eng.wav"
#define FILENAME "spin_right_eng.wav"
#define FILENAME "spin_left_eng.wav"
//íÜçëåÍ
#define FILENAME "moving_forward_chi.wav"
#define FILENAME "turn_right_chi.wav"
#define FILENAME "turn_left_chi.wav"
#define FILENAME "moving_back_chi.wav"
#define FILENAME "stopping_chi.wav"
#define FILENAME "spin_right_chi.wav"
#define FILENAME "spin_left_chi.wav"

using namespace RTC;

/*!
 * @class Vouce_output_ver2
 * @brief ModuleDescription
 *
 */
class Vouce_output_ver2
  : public RTC::DataFlowComponentBase
{
 public:

	 int count;
	 int flag;
	 char filename[80];
	 _TCHAR** ok;
	 TimedString Image_Name[80];
	 void sound();
	 void wait(int time);

  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  Vouce_output_ver2(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~Vouce_output_ver2();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  stop_interval
   * - DefaultValue: 500
   */
  int  m_select_language;
  /*!
   * 
   * - Name:  voice_interval
   * - DefaultValue: 500
   */
  int m_voice_interval;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedLong m_voice_in;
  /*!
   */
  InPort<RTC::TimedLong> m_voice_inIn;
  RTC::TimedDoubleSeq m_Data_in;
  /*!
   */
  InPort<RTC::TimedDoubleSeq> m_Data_inIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedDoubleSeq m_Data_out;
  /*!
   */
  OutPort<RTC::TimedDoubleSeq> m_Data_outOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void Vouce_output_ver2Init(RTC::Manager* manager);
};

#endif // VOUCE_OUTPUT_VER2_H
