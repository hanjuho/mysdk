#pragma once



#include "../../hsdk_common.h"
#include "framework_wintimer.h"
#include <list>



namespace hsdk
{
	namespace framework
	{

		// 설명 : 
		typedef BOOL(CALLBACK *CALLBACK_ALARM)(
			_In_ unsigned int _idEvent,
			_Inout_ void * _userContext);

		// 설명 : 
		DLL_DECL_CLASS(Framework_UserTimeStream)
		{

			// 설명 : Stores timer callback info.
			DECL_STRUCT(USERALARM_DESC)
			{

				// 설명 : 
				CALLBACK_ALARM callbackTimer = nullptr;

				// 설명 : 
				void * callbackUserContext = nullptr;

				// 설명 : 
				float fTimeoutInSecs = 0.0f;

				// 설명 : 
				float fCountdown = 0.0f;

				// 설명 : 
				BOOL bEnabled = true;

				// 설명 : 
				unsigned int nID = 0;

			};

		public:

			// 설명 : 
			CLASS_DECL_FUNC_T(void, update_Time)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, update_Frame)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			// 설명 : 
			CLASS_DECL_FUNC(add_Timer)(
				_In_ CALLBACK_ALARM _callbackTimer,
				_In_ float _fTimeoutInSecs = 1.0f,
				_In_ unsigned int * _nIDEvent = nullptr,
				_In_ void * _userContext = nullptr);

			// 설명 : 
			CLASS_DECL_FUNC(remove_Timer)(
				_In_ unsigned int _nIDEvent);

			// 설명 : 
			CLASS_DECL_FUNC_T(void, pause_Time)(
				_In_ BOOL _pauseTime);

			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Time_Paused)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(void, pause_Rendering)(
				_In_ BOOL _pauseRendering);

			// 설명 : 
			CLASS_DECL_FUNC_T(BOOL, is_Rendering_Paused)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(double, get_Time)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(float, get_FPS)(
				_X_ void)const;

			// 설명 : 
			CLASS_DECL_FUNC_T(void, set_ConstantFrameTime)(
				_In_ BOOL _constantFrameTime,
				_In_ float _fTimePerFrame = 0.0333f);

		private:

			// 설명 : 
			BOOL my_PauseTime = false;

			// 설명 : 
			BOOL my_PauseRendering = false;

			// 설명 : 
			int my_PauseTimeCount = 0;

			// 설명 : 
			int my_PauseRenderingCount = 0;

			// 설명 : 
			BOOL my_ConstantFrameTime = false;

			// 설명 : 
			float my_ConstantTimePerFrame = 0.0333f;

			// 설명 : 
			double my_Time = 0.0f;

			// 설명 : 
			double my_AbsoluteTime = 0.0f;

			// 설명 : 
			float my_ElapsedTime = 0.0f;

			// 설명 :
			float my_OneSecond = 0.0f;

			// 설명 :
			unsigned int my_CountForOneSecond = 0;

			// 설명 :
			float my_Fps = 0;

			// 설명 :
			Framework_UserTimer my_Timer;

			// 설명 :
			std::list<USERALARM_DESC> my_AlarmEvents;

		};

	}
}