#pragma once



#include "../../hsdk_common.h"
#include <Windows.h>



namespace hsdk
{
	namespace framework
	{

		// ���� : Performs timer operations
		DECL_CLASS(Framework_UserTimer)
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(Framework_UserTimer)(void);

			// ���� : resets the timer.
			CLASS_DECL_FUNC_T(void, reset)(
				_X_ void);

			// ���� : starts the timer.
			CLASS_DECL_FUNC_T(void, start)(
				_X_ void);

			// ���� : stop (or pause) the timer.
			CLASS_DECL_FUNC_T(void, stop)(
				_X_ void);

			// ���� : advance the timer by 0.1 seconds.
			CLASS_DECL_FUNC_T(void, advance)(
				_X_ void);

			// ���� : get the absolute system time.
			CLASS_DECL_FUNC_T(double, get_AbsoluteTime)(
				_X_ void);

			// ���� : get the current time.
			CLASS_DECL_FUNC_T(double, get_Time)(
				_X_ void);

			// ���� : get the time that elapsed between GetElapsedTime() calls.
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				_X_ void);

			// ���� : get all time values at once.
			CLASS_DECL_FUNC_T(void, get_TimeValues)(
				_Out_ double * _fTime,
				_Out_ double * _fAbsoluteTime,
				_Out_ float * _fElapsedTime);

			// ���� : returns true if timer stopped.
			CLASS_DECL_FUNC_T(BOOL, is_Stopped)(
				_X_ void);

			// Limit the current thread to one processor (the current one). This ensures that timing code runs
			// on only one processor, and will not suffer any ill effects from power management.
			CLASS_DECL_FUNC_T(void, limit_ThreadAffinityToCurrentProc)(
				_X_ void);

		protected:

			CLASS_DECL_FUNC_T(LARGE_INTEGER, get_AdjustedCurrentTime)(
				_X_ void);

			// ���� : 
			BOOL m_bUsingQPF = FALSE;

			// ���� : 
			BOOL m_bTimerStopped = TRUE;

			// ���� : 
			LONGLONG m_llQPFTicksPerSec = 0;

			// ���� : 
			LONGLONG m_llStopTime = 0;

			// ���� : 
			LONGLONG m_llLastElapsedTime = 0;

			// ���� : 
			LONGLONG m_llBaseTime = 0;

		};

	}
}
