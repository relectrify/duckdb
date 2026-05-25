#include "core_functions/scalar/date_functions.hpp"

namespace duckdb {

namespace {

/*
 * Get UTC-TAI offset in seconds for Unix time point in seconds from the Unix
 * epoch of 1 Jan 1970 00:00:00.
 */
int tai_utc_offset_from_unix(int64_t unix_secs) {
	if (unix_secs >= 1483228800) return 37;	// 1 Jan 2017
	if (unix_secs >= 1435708800) return 36;	// 1 Jul 2015
	if (unix_secs >= 1341100800) return 35;	// 1 Jul 2012
	if (unix_secs >= 1230768000) return 34;	// 1 Jan 2009
	if (unix_secs >= 1136073600) return 33;	// 1 Jan 2006
	if (unix_secs >= 915148800) return 32;	// 1 Jan 1999
	if (unix_secs >= 867715200) return 31;	// 1 Jul 1997
	if (unix_secs >= 820454400) return 30;	// 1 Jan 1996
	if (unix_secs >= 773020800) return 29;	// 1 Jul 1994
	if (unix_secs >= 741484800) return 28;	// 1 Jul 1993
	if (unix_secs >= 709948800) return 27;	// 1 Jul 1992
	if (unix_secs >= 662688000) return 26;	// 1 Jan 1991
	if (unix_secs >= 631152000) return 25;	// 1 Jan 1990
	if (unix_secs >= 567993600) return 24;	// 1 Jan 1988
	if (unix_secs >= 489024000) return 23;	// 1 Jul 1985
	if (unix_secs >= 425865600) return 22;	// 1 Jul 1983
	if (unix_secs >= 394329600) return 21;	// 1 Jul 1982
	if (unix_secs >= 362793600) return 20;	// 1 Jul 1981
	if (unix_secs >= 315532800) return 19;	// 1 Jan 1980
	if (unix_secs >= 283996800) return 18;	// 1 Jan 1979
	if (unix_secs >= 252460800) return 17;	// 1 Jan 1978
	if (unix_secs >= 220924800) return 16;	// 1 Jan 1977
	if (unix_secs >= 189302400) return 15;	// 1 Jan 1976
	if (unix_secs >= 157766400) return 14;	// 1 Jan 1975
	if (unix_secs >= 126230400) return 13;	// 1 Jan 1974
	if (unix_secs >= 94694400) return 12;	// 1 Jan 1973
	if (unix_secs >= 78796800) return 11;	// 1 Jul 1972
	if (unix_secs >= 63072000) return 10;	// 1 Jan 1972
	throw ConversionException("Conversion from UTC to TAI is not possible before 1 Jan 1972");
}

/*
 * Get TAI-UTC offset in seconds for TAI time point in seconds from the Unix
 * epoch of 1 Jan 1970 00:00:00 TAI.
 */
int tai_utc_offset_from_tai(int64_t tai_secs) {
	if (tai_secs >= 1483228837) return 37;	// 1 Jan 2017
	if (tai_secs >= 1435708836) return 36;	// 1 Jul 2015
	if (tai_secs >= 1341100835) return 35;	// 1 Jul 2012
	if (tai_secs >= 1230768034) return 34;	// 1 Jan 2009
	if (tai_secs >= 1136073633) return 33;	// 1 Jan 2006
	if (tai_secs >= 915148832) return 32;	// 1 Jan 1999
	if (tai_secs >= 867715231) return 31;	// 1 Jul 1997
	if (tai_secs >= 820454430) return 30;	// 1 Jan 1996
	if (tai_secs >= 773020829) return 29;	// 1 Jul 1994
	if (tai_secs >= 741484828) return 28;	// 1 Jul 1993
	if (tai_secs >= 709948827) return 27;	// 1 Jul 1992
	if (tai_secs >= 662688026) return 26;	// 1 Jan 1991
	if (tai_secs >= 631152025) return 25;	// 1 Jan 1990
	if (tai_secs >= 567993624) return 24;	// 1 Jan 1988
	if (tai_secs >= 489024023) return 23;	// 1 Jul 1985
	if (tai_secs >= 425865622) return 22;	// 1 Jul 1983
	if (tai_secs >= 394329621) return 21;	// 1 Jul 1982
	if (tai_secs >= 362793620) return 20;	// 1 Jul 1981
	if (tai_secs >= 315532819) return 19;	// 1 Jan 1980
	if (tai_secs >= 283996818) return 18;	// 1 Jan 1979
	if (tai_secs >= 252460817) return 17;	// 1 Jan 1978
	if (tai_secs >= 220924816) return 16;	// 1 Jan 1977
	if (tai_secs >= 189302415) return 15;	// 1 Jan 1976
	if (tai_secs >= 157766414) return 14;	// 1 Jan 1975
	if (tai_secs >= 126230413) return 13;	// 1 Jan 1974
	if (tai_secs >= 94694412) return 12;	// 1 Jan 1973
	if (tai_secs >= 78796811) return 11;	// 1 Jul 1972
	if (tai_secs >= 63072010) return 10;	// 1 Jan 1972
	throw ConversionException("Conversion from TAI to UTC is not possible before 1 Jan 1972");
}

void TaiToTs(DataChunk &input, ExpressionState &state, Vector &result) {
	D_ASSERT(input.ColumnCount() == 1);
	auto func = [](int64_t tai_secs) -> timestamp_sec_t {
		return timestamp_sec_t(tai_secs - tai_utc_offset_from_tai(tai_secs));
	};
	UnaryExecutor::Execute<int64_t, timestamp_sec_t>(input.data[0], result, input.size(), func);
}

void TaiMsToTs(DataChunk &input, ExpressionState &state, Vector &result) {
	D_ASSERT(input.ColumnCount() == 1);
	auto func = [](int64_t tai_millis) -> timestamp_ms_t {
		return timestamp_ms_t(tai_millis - tai_utc_offset_from_tai(tai_millis / 1000) * 1000);
	};
	UnaryExecutor::Execute<int64_t, timestamp_ms_t>(input.data[0], result, input.size(), func);
}

void TaiEpoch(DataChunk &input, ExpressionState &state, Vector &result) {
	D_ASSERT(input.ColumnCount() == 1);
	auto func = [](timestamp_tz_t ts) -> int64_t {
		if (ts == ts.infinity()) {
			throw ConversionException("Attempting to calculate TAI epoch on infinite timestamp");
		}
		auto unix_secs = static_cast<int64_t>(ts) / 1000000;
		return unix_secs + tai_utc_offset_from_unix(unix_secs);
	};
	UnaryExecutor::Execute<timestamp_tz_t, int64_t>(input.data[0], result, input.size(), func);
}

void TaiEpochMs(DataChunk &input, ExpressionState &state, Vector &result) {
	D_ASSERT(input.ColumnCount() == 1);
	auto func = [](timestamp_tz_t ts) -> int64_t {
		if (ts == ts.infinity()) {
			throw ConversionException("Attempting to calculate TAI epoch on infinite timestamp");
		}
		auto unix_secs = static_cast<int64_t>(ts) / 1000000;
		auto unix_millis = static_cast<int64_t>(ts) / 1000;
		return unix_millis + tai_utc_offset_from_unix(unix_secs) * 1000;
	};
	UnaryExecutor::Execute<timestamp_tz_t, int64_t>(input.data[0], result, input.size(), func);
}

} // namespace

ScalarFunction MakeTimestampFromTaiFun::GetFunction() {
	ScalarFunction f({LogicalType::BIGINT}, LogicalType::TIMESTAMP_S, TaiToTs);
	f.SetFallible();
	return f;
}

ScalarFunction MakeTimestampFromTaiMsFun::GetFunction() {
	ScalarFunction f({LogicalType::BIGINT}, LogicalType::TIMESTAMP_MS, TaiMsToTs);
	f.SetFallible();
	return f;
}

ScalarFunction TaiEpochFun::GetFunction() {
	ScalarFunction f({LogicalType::TIMESTAMP_TZ}, LogicalType::BIGINT, TaiEpoch);
	f.SetFallible();
	return f;
}

ScalarFunction TaiEpochMsFun::GetFunction() {
	ScalarFunction f({LogicalType::TIMESTAMP_TZ}, LogicalType::BIGINT, TaiEpochMs);
	f.SetFallible();
	return f;
}

} // namespace duckdb
