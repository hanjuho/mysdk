#pragma once



#include "../../hsdk_common.h"
#include <Windows.h>



namespace hsdk
{
	namespace win
	{

		// ���� : Performs timer operations
		DLL_DECL_CLASS(WINTimer)
		{
		public:

			// ������.
			CLASS_DECL_CONSTRUCTOR(WINTimer)(void);

			// ���� : resets the timer.
			CLASS_DECL_FUNC_T(void, reset)(
				/* [x] */ void);

			// ���� : starts the timer.
			CLASS_DECL_FUNC_T(void, start)(
				/* [x] */ void);

			// ���� : stop (or pause) the timer.
			CLASS_DECL_FUNC_T(void, stop)(
				/* [x] */ void);

			// ���� : advance the timer by 0.1 seconds.
			CLASS_DECL_FUNC_T(void, advance)(
				/* [x] */ void);

			// ���� : get the absolute system time.
			CLASS_DECL_FUNC_T(double, get_AbsoluteTime)(
				/* [x] */ void);

			// ���� : get the current time.
			CLASS_DECL_FUNC_T(double, get_Time)(
				/* [x] */ void);

			// ���� : get the time that elapsed between GetElapsedTime() calls.
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				/* [x] */ void);

			// ���� : get all time values at once.
			CLASS_DECL_FUNC_T(void, get_TimeValues)(
				_Out_ double * _fTime,
				_Out_ double * _fAbsoluteTime,
				_Out_ float * _fElapsedTime);

			// ���� : returns true if timer stopped.
			CLASS_DECL_FUNC_T(BOOL, is_Stopped)(
				/* [x] */ void);

			// Limit the current thread to one processor (the current one). This ensures that timing code runs
			// on only one processor, and will not suffer any ill effects from power management.
			CLASS_DECL_FUNC_T(void, limit_ThreadAffinityToCurrentProc)(
				/* [x] */ void);

		protected:

			CLASS_DECL_FUNC_T(LARGE_INTEGER, get_AdjustedCurrentTime)(
				/* [x] */ void);

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
