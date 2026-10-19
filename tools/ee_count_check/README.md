# EE Count clock checks

Run `tools\ee_count_check\run.bat`. This isolated test uses the production
`EeCountClock` header and does not rebuild or run the game, initialize graphics,
or send network traffic. Receipts go to `build-ninja/ee-count-check`.

Coverage includes exact cycle boundaries, the first uint32 wrap, independently
calculated long-duration values up to UINT64_MAX nanoseconds, and concurrent
readers of one shared clock. A consumer fixture applies the original SDK's
unsigned cycle subtraction and divide300 conversion to verify that the real
17ms send gate remains paced and eventually opens, including across a wrap.
It explicitly preserves the SDK's approximately983ms-per-host-second result.

The conversion fixture is not the complete generated gettimeofday routine;
guest dispatch, RTC initialization and actual SN@P authentication still require
the native login run.
