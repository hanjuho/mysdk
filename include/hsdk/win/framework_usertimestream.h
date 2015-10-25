#pragma once



#include "../../hsdk_common.h"
#include "framework_wintimer.h"
#include <list>



namespace hsdk
{
	namespace framework
	{

		// ���� : 
		typedef BOOL(CALLBACK *CALLBACK_ALARM)(
			_In_ unsigned int _idEvent,
			_Inout_ void * _userContext);

		// ���� : 
		DLL_DECL_CLASS(Framework_UserTimeStream)
		{

			// ���� : Stores timer callback info.
			DECL_STRUCT(USERALARM_DESC)
			{

				// ���� : 
				CALLBACK_ALARM callbackTimer = nullptr;

				// ���� : 
				void * callbackUserContext = nullptr;

				// ���� : 
				float fTimeoutInSecs = 0.0f;

				// ���� : 
				float fCountdown = 0.0f;

				// ���� : 
				BOOL bEnabled = true;

				// ���� : 
				unsigned int nID = 0;

			};

		public:

			// ���� : 
			CLASS_DECL_FUNC_T(void, update_Time)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, update_Frame)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			// ���� : 
			CLASS_DECL_FUNC(add_Timer)(
				_In_ CALLBACK_ALARM _callbackTimer,
				_In_ float _fTimeoutInSecs = 1.0f,
				_In_ unsigned int * _nIDEvent = nullptr,
				_In_ void * _userContext = nullptr);

			// ���� : 
			CLASS_DECL_FUNC(remove_Timer)(
				_In_ unsigned int _nIDEvent);

			// ���� : 
			CLASS_DECL_FUNC_T(void, pause_Time)(
				_In_ BOOL _pauseTime);

			// ���� : 
			CLASS_DECL_FUNC_T(BOOL, is_Time_Paused)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(void, pause_Rendering)(
				_In_ BOOL _pauseRendering);

			// ���� : 
			CLASS_DECL_FUNC_T(BOOL, is_Rendering_Paused)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(double, get_Time)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(float, get_FPS)(
				_X_ void)const;

			// ���� : 
			CLASS_DECL_FUNC_T(void, set_ConstantFrameTime)(
				_In_ BOOL _constantFrameTime,
				_In_ float _fTimePerFrame = 0.0333f);

		private:

			// ���� : 
			BOOL my_PauseTime = false;

			// ���� : 
			BOOL my_PauseRendering = false;

			// ���� : 
			int my_PauseTimeCount = 0;

			// ���� : 
			int my_PauseRenderingCount = 0;

			// ���� : 
			BOOL my_ConstantFrameTime = false;

			// ���� : 
			float my_ConstantTimePerFrame = 0.0333f;

			// ���� : 
			double my_Time = 0.0f;

			// ���� : 
			double my_AbsoluteTime = 0.0f;

			// ���� : 
			float my_ElapsedTime = 0.0f;

			// ���� :
			float my_OneSecond = 0.0f;

			// ���� :
			unsigned int my_CountForOneSecond = 0;

			// ���� :
			float my_Fps = 0;

			// ���� :
			Framework_UserTimer my_Timer;

			// ���� :
			std::list<USERALARM_DESC> my_AlarmEvents;

		};

	}
}