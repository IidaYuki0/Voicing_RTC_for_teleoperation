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
    "conf.default.voice_interval", "250",

    // Widget
    "conf.__widget__.select_language", "text",
    "conf.__widget__.voice_interval", "text",
    // Constraints

    "conf.__type__.select_language", "int",
    "conf.__type__.voice_interval", "int",
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
	m_Data_inIn("Data_in", m_Data_in),
	m_Command_inIn("Command_in", m_Command_in),
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
  addInPort("Data_in", m_Data_inIn);
  addInPort("Command_in", m_Command_inIn);
  
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
	if (m_Command_inIn.isNew())
	{
		m_Command_inIn.read();

		double vy = m_Command_in.data.vy;
		double va = m_Command_in.data.va;

		if (m_select_language == 1)
		{
			if (va == -1000 && vy == 0) //右旋回指令
			{
				printf("Spin_right\n");
				m_Alarm_Sound = "Spin_right";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va < 0 && vy > 0) ////右折指令
			{
				printf("Turn_right\n");
				m_Alarm_Sound = "Turn_right.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (vy == 1000 && va == 0) //前進指令
			{
				printf("Going_forward\n");
				m_Alarm_Sound = "Move_forward.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va > 0 && vy > 0)//左折指令
			{
				printf("Turn_left\n");
				m_Alarm_Sound = "Turn_left.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va == 1000 && vy == 0)//左旋回指令
			{
				printf("Spin_left\n");
				m_Alarm_Sound = "Spin_left.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va < 0 && vy < 0) //左後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "Move_back.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (vy == -1000 && va == 0) //後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "Move_back.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va > 0 && vy < 0) //右後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "Move_back.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else  if (va == 0 && vy == 0)
			{
				//停止中
				printf("No Command\n");
				m_Alarm_Sound = "Stop_state.wav";
				sound();
				Sleep(m_voice_interval);
			}
		}
		else if (m_select_language == 2)
		{
			if (va == -1000 && vy == 0) //右旋回指令
			{
				printf("Spin_right\n");
				m_Alarm_Sound = "spin_right_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va < 0 && vy > 0) ////右折指令
			{
				printf("Turn_right\n");
				m_Alarm_Sound = "turn_right_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (vy == 1000 && va == 0) //前進指令
			{
				printf("Going_forward\n");
				m_Alarm_Sound = "moving forward_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va > 0 && vy > 0)//左折指令
			{
				printf("Turn_left\n");
				m_Alarm_Sound = "turn_left_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va == 1000 && vy == 0)//左旋回指令
			{
				printf("Spin_left\n");
				m_Alarm_Sound = "spin_left_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va < 0 && vy < 0) //左後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "moving_back_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (vy == -1000 && va == 0) //後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "moving_back_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else if (va > 0 && vy < 0) //右後退指令
			{
				printf("Moving_back\n");
				m_Alarm_Sound = "moving_back_eng.wav";
				sound();
				Sleep(m_voice_interval);
			}
			else  if (va == 0 && vy == 0)
			{
				//停止中
				printf("No Command\n");
				m_Alarm_Sound = "stopping_eng.wav";
				sound();
				Sleep(m_voice_interval);
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
/*
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
*/
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


