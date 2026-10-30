#pragma once
// Included after miniaudio by the source-preserving raylib audio transform.
// Endpoint IDs are opaque Windows strings, passed only to this child process.
static const ma_device_id* reoAudioOutputDevice(ma_context* context, ma_device_id* selected) {
#if defined(_WIN32)
    const wchar_t* requested = _wgetenv(L"REO_AUDIO_DEVICE");
    if (!requested || !*requested) return NULL;
    if (context->backend != ma_backend_wasapi) {
        fprintf(stderr, "[AUDIO-OUTPUT] WASAPI unavailable; using default output\n");
        return NULL;
    }
    if (wcslen(requested) >= 64) {
        fprintf(stderr, "[AUDIO-OUTPUT] Invalid endpoint ID; using default output\n");
        return NULL;
    }
    ma_device_info* playback = NULL;
    ma_uint32 count = 0;
    if (ma_context_get_devices(context, &playback, &count, NULL, NULL) == MA_SUCCESS) {
        for (ma_uint32 i = 0; i < count; ++i) {
            if (wcscmp(playback[i].id.wasapi, requested) == 0) {
                *selected = playback[i].id;
                fprintf(stderr, "[AUDIO-OUTPUT] Selected %s\n", playback[i].name);
                return selected;
            }
        }
    }
    fprintf(stderr, "[AUDIO-OUTPUT] Saved output unavailable; using default output\n");
#else
    (void)context; (void)selected;
#endif
    return NULL;
}
static ma_result reoAudioInitDevice(ma_context* context, ma_device_config* config, ma_device* device) {
    ma_result result = ma_device_init(context, config, device);
    if (result != MA_SUCCESS && config->playback.pDeviceID != NULL) {
        fprintf(stderr, "[AUDIO-OUTPUT] Selected output could not open; retrying Windows default\n");
        config->playback.pDeviceID = NULL;
        result = ma_device_init(context, config, device);
    }
    return result;
}
