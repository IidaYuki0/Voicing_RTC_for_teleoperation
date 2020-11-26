// -*- C++ -*-
/*!
 * @file  Vouce_output_ver2.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Vouce_output_ver2.h"
#include<iostream>
#include <thread>

std::string m_Alarm_Sound;

// Module specification
// <rtc-template block="module_spec">
static const char* vouce_output_ver2_spec[] =
  {
    "implementation_id", "Vouce_output_ver2",
    "type_name",         "Voice_output_ver2",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "IidaYuki",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.select_language", "1",
    "conf.default.voice_interval", "500",

    // Widget
    "conf.__widget__.select_language", "text",
    "conf.__widget__.voice_interval", "text",
    // Constraints

    "conf.__type__.select_language", "int",
    "conf.__type__.voice_interval", "int",
	"conf.__constraints__.select_language", "(JPN,ENG,CHN)",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Vouce_output_ver2::Vouce_output_ver2(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_voice_inIn("voice_in", m_voice_in),
    m_Data_inIn("Data_in", m_Data_in),
    m_Data_outOut("Data_out", m_Data_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Vouce_output_ver2::~Vouce_output_ver2()
{
}



RTC::ReturnCode_t Vouce_output_ver2::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("voice_in", m_voice_inIn);
  addInPort("Data_in", m_Data_inIn);
  
  // Set OutPort buffer
  addOutPort("Data_out", m_Data_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("select_language", m_select_language, "1");
  bindParameter("voice_interval", m_voice_interval, "500");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Vouce_output_ver2::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Vouce_output_ver2::onActivated(RTC::UniqueId ec_id)
{
	printf("Activated\n");

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Vouce_output_ver2::onDeactivated(RTC::UniqueId ec_id)
{
	printf("Deactivated\n");

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Vouce_output_ver2::onExecute(RTC::UniqueId ec_id)
{
	//音声出力
	if (m_voice_inIn.isNew())
	{
		if (m_select_language == 1) {
			m_voice_inIn.read();
			std::cout << "con" << m_voice_in.data << std::endl;
			double con = m_voice_in.data;

			//1番は前進
			if (con == 1) {
				//std::cout << "OK" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Move_forward.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			
			}
			else if (con == 2) {//2番は右折
				//std::cout << "OK2" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Turn_right.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 3) {//3番は左折
				//std::cout << "OK3" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Turn_left.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 4) {//4番は後退
				//std::cout << "OK4" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Move_back.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 5) {//5番は停止
				//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Stop_state.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 6) {//6は後方確認;
				m_Alarm_Sound = "Back_Object.wav";
				sound();
				wait(m_voice_interval);
			}
			else if (con == 7) {//7番は右旋回
				//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Spin_right";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 8) {//8番は左旋回
				//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "Spin_left.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 9) {//9番は減速
				m_Alarm_Sound = "dec.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 10) {//10番は加速
				m_Alarm_Sound = "Acc.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
		}
		//中国語ver	
		else if (m_select_language == 3)
		{
			m_voice_inIn.read();
			std::cout << "con" << m_voice_in.data << std::endl;
			double con = m_voice_in.data;

			//1番は前進
			if (con == 1) {
				//std::cout << "OK" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "moving_forward_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;

			}
			else if (con == 2) {//2番は右折
								//std::cout << "OK2" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "turn_right_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 3) {//3番は左折
								//std::cout << "OK3" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "turn_left_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 4) {//4番は後退
								//std::cout << "OK4" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "moving_back_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 5) {//5番は停止
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "stopping_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 6) {//6は後方確認;
				m_Alarm_Sound = "Back_Object.wav";
				sound();
				wait(m_voice_interval);
			}
			else if (con == 7) {//7番は右旋回
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "spin_right_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 8) {//8番は左旋回
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "spin_left_chi.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
		}
		//英語ver
		else if (m_select_language == 2)
		{
			m_voice_inIn.read();
			std::cout << "con" << m_voice_in.data << std::endl;
			double con = m_voice_in.data;

			//1番は前進
			if (con == 1) {
				//std::cout << "OK" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "moving forward_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;

			}
			else if (con == 2) {//2番は右折
								//std::cout << "OK2" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "turn_right_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 3) {//3番は左折
								//std::cout << "OK3" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "turn_left_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 4) {//4番は後退
								//std::cout << "OK4" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "moving_back_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 5) {//5番は停止
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "stopping_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 6) {//6は後方確認;
				m_Alarm_Sound = "Back_Object.wav";
				sound();
				wait(m_voice_interval);
			}
			else if (con == 7) {//7番は右旋回
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "spin_right_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
			else if (con == 8) {//8番は左旋回
								//std::cout << "OK5" << a_flag << "con" << m_voice_in.data << std::endl;
				m_Alarm_Sound = "spin_left_eng.wav";
				sound();
				wait(m_voice_interval);
				con = 0;
			}
		}
		else printf("select language\n");
	}
	return RTC::RTC_OK;
} 

/*
RTC::ReturnCode_t Vouce_output_ver2::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Vouce_output_ver2::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


//アラームを鳴らす関数
void Vouce_output_ver2::sound()
{
	PlaySound(_T(m_Alarm_Sound.c_str()), NULL, SND_FILENAME);
}

void Vouce_output_ver2::wait(int time)
{
	clock_t end_wait = 0;
	clock_t start_wait = 0;

	start_wait = clock();

	while (1) {
		//約time秒間繰り返す（実行周期1000なのでtime/1000秒間）
		end_wait = clock();
		if ((end_wait - start_wait) > time) break;
	}
}
extern "C"
{
 
  void Vouce_output_ver2Init(RTC::Manager* manager)
  {
    coil::Properties profile(vouce_output_ver2_spec);
    manager->registerFactory(profile,
                             RTC::Create<Vouce_output_ver2>,
                             RTC::Delete<Vouce_output_ver2>);
  }
  
};


