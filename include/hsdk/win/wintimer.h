#pragma once



#include "../../hsdk_common.h"
#include <Windows.h>



namespace hsdk
{
	namespace win
	{

		// 설명 : Performs timer operations
		DLL_DECL_CLASS(WINTimer)
		{
		public:

			// 생성자.
			CLASS_DECL_CONSTRUCTOR(WINTimer)(void);

			// 설명 : resets the timer.
			CLASS_DECL_FUNC_T(void, reset)(
				/* [x] */ void);

			// 설명 : starts the timer.
			CLASS_DECL_FUNC_T(void, start)(
				/* [x] */ void);

			// 설명 : stop (or pause) the timer.
			CLASS_DECL_FUNC_T(void, stop)(
				/* [x] */ void);

			// 설명 : advance the timer by 0.1 seconds.
			CLASS_DECL_FUNC_T(void, advance)(
				/* [x] */ void);

			// 설명 : get the absolute system time.
			CLASS_DECL_FUNC_T(double, get_AbsoluteTime)(
				/* [x] */ void);

			// 설명 : get the current time.
			CLASS_DECL_FUNC_T(double, get_Time)(
				/* [x] */ void);

			// 설명 : get the time that elapsed between GetElapsedTime() calls.
			CLASS_DECL_FUNC_T(float, get_ElapsedTime)(
				/* [x] */ void);

			// 설명 : get all time values at once.
			CLASS_DECL_FUNC_T(void, get_TimeValues)(
				_Out_ double * _fTime,
				_Out_ double * _fAbsoluteTime,
				_Out_ float * _fElapsedTime);

			// 설명 : returns true if timer stopped.
			CLASS_DECL_FUNC_T(BOOL, is_Stopped)(
				/* [x] */ void);

			// Limit the current thread to one processor (the current one). This ensures that timing code runs
			// on only one processor, and will not suffer any ill effects from power management.
			CLASS_DECL_FUNC_T(void, limit_ThreadAffinityToCurrentProc)(
				/* [x] */ void);

		protected:

			CLASS_DECL_FUNC_T(LARGE_INTEGER, get_AdjustedCurrentTime)(
				/* [x] */ void);

			// 설명 : 
			BOOL m_bUsingQPF = FALSE;

			// 설명 : 
			BOOL m_bTimerStopped = TRUE;

			// 설명 : 
			LONGLONG m_llQPFTicksPerSec = 0;

			// 설명 : 
			LONGLONG m_llStopTime = 0;

			// 설명 : 
			LONGLONG m_llLastElapsedTime = 0;

			// 설명 : 
			LONGLONG m_llBaseTime = 0;

		};

	}
}
