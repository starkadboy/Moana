#pragma once
#include "PrecompiledHeaders.h"
#include "Logger.h"

namespace Moana {
	#ifdef MOA_DEBUG
	#define moa_assert(e)			MoanaAssert((bool)e, __FILE__, __LINE__, #e)
	#define moa_assert_msg(e, msg)	MoanaAssert((bool)e, __FILE__, __LINE__, msg)
	#endif

	inline void
	MoanaAssert(bool bCondition, const char* pFile, int line, const char* pMessage) {
	#ifndef MOA_NO_ASSERTS
		if (!bCondition) {
			MOA_LOG_ERROR_ENGINE(CLogger::eEngineLoggers::LOGGER_ASSERT, "Assert in {0}:{1}: {2}", pFile, line, pMessage);
		#ifdef MOA_WINDOWS
			__debugbreak();
		#endif
		}
	#endif
	}
}