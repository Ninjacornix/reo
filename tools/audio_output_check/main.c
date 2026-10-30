// Compile the staged production provider in the same translation unit so the
// check can inspect the endpoint actually bound by miniaudio. No game is run.
#include "reo_audio_output.c"

static void quoted(FILE* output, const char* text) {
    fputc('"', output);
    while (*text) {
        unsigned char c = (unsigned char)*text++;
        if (c == '"' || c == '\\') fputc('\\', output);
        if (c >= 32) fputc(c, output);
    }
    fputc('"', output);
}
int main(int argc, char** argv) {
    if (argc != 4) return 2;
    _putenv_s("REO_AUDIO_DEVICE", strcmp(argv[1], "--default") == 0 ? "" : argv[1]);
    InitAudioDevice();
    int ready = IsAudioDeviceReady();
    int selected = 0;
    if (ready && AUDIO.System.context.backend == ma_backend_wasapi && AUDIO.System.device.playback.pID) {
        wchar_t id[64];
        selected = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, argv[1], -1, id, 64) &&
                   wcscmp(AUDIO.System.device.playback.id.wasapi, id) == 0;
    }
    int expected = atoi(argv[3]);
    FILE* receipt = fopen(argv[2], "wb");
    if (!receipt) { if (ready) CloseAudioDevice(); return 3; }
    fprintf(receipt, "{\"ready\":%s,\"boundSelectedEndpoint\":%s,\"name\":", ready ? "true" : "false", selected ? "true" : "false");
    quoted(receipt, ready ? AUDIO.System.device.playback.name : "");
    fprintf(receipt, ",\"passed\":%s}\n", ready && selected == expected ? "true" : "false");
    fclose(receipt);
    if (ready) CloseAudioDevice();
    return ready && selected == expected ? 0 : 1;
}
