#pragma once

#include "core.h"
#include "sink.h"
#include "details/stream.h"

namespace lwlog::sinks
{
	class LWLOG_API stderr_sink : public sink, public details::stream
	{
	public:
		stderr_sink();
		void sink_it(std::string_view message) override;
	};

	inline stderr_sink::stderr_sink()
		: details::stream(stderr)
	{
		disable_color();
	}

	inline void stderr_sink::sink_it(std::string_view message)
	{
		details::stream::write(message);
	}
}