// Small offscreen proof: the Windows native reader decodes a complete owned
// H.264 MP4 without the game's PS2 movie runtime. No window or audio device.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <stdexcept>
#include <vector>

namespace {
void checked(HRESULT result) {
    if (FAILED(result)) {
        char message[64];std::snprintf(message,sizeof(message),"HRESULT %08lx",static_cast<unsigned long>(result));
        throw std::runtime_error(message);
    }
}
template<class T>struct Com {
    T* p{};~Com(){if(p)p->Release();}
    T** out(){return &p;}T* operator->()const{return p;}
};
}
int wmain(int argc,wchar_t** argv) {
    bool com=false,mf=false;
    try {
        if(argc!=2)throw std::runtime_error("One MP4 path required");
        checked(CoInitializeEx(nullptr,COINIT_MULTITHREADED));com=true;
        checked(MFStartup(MF_VERSION));mf=true;
        {
            Com<IMFSourceReader> reader;
            checked(MFCreateSourceReaderFromURL(argv[1],nullptr,reader.out()));
            checked(reader->SetStreamSelection(MF_SOURCE_READER_ALL_STREAMS,FALSE));
            checked(reader->SetStreamSelection(MF_SOURCE_READER_FIRST_VIDEO_STREAM,TRUE));
            Com<IMFMediaType> type;checked(MFCreateMediaType(type.out()));
            checked(type->SetGUID(MF_MT_MAJOR_TYPE,MFMediaType_Video));
            checked(type->SetGUID(MF_MT_SUBTYPE,MFVideoFormat_NV12));
            checked(reader->SetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM,nullptr,type.p));
            Com<IMFMediaType> actual;checked(reader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM,actual.out()));
            UINT32 width{},height{};checked(MFGetAttributeSize(actual.p,MF_MT_FRAME_SIZE,&width,&height));
            UINT32 par_x{},par_y{};checked(MFGetAttributeRatio(actual.p,MF_MT_PIXEL_ASPECT_RATIO,&par_x,&par_y));
            const auto begin=std::chrono::steady_clock::now();std::vector<LONGLONG> times;
            std::uint64_t bytes{};bool ended=false;unsigned type_events{};
            for(unsigned calls=0;calls<20000;++calls) {
                if(std::chrono::steady_clock::now()-begin>std::chrono::seconds(60))throw std::runtime_error("Decode deadline");
                DWORD stream{},flags{};LONGLONG time{};Com<IMFSample> sample;
                checked(reader->ReadSample(MF_SOURCE_READER_FIRST_VIDEO_STREAM,0,&stream,&flags,&time,sample.out()));
                if(flags&MF_SOURCE_READERF_ERROR)throw std::runtime_error("Reader error");
                if(flags&MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED) {
                    // First decode can publish negotiated stride/alignment.
                    // Permit that event only while image geometry stays fixed.
                    Com<IMFMediaType> negotiated;checked(reader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM,negotiated.out()));
                    UINT32 w{},h{},x{},y{};GUID subtype{};
                    checked(MFGetAttributeSize(negotiated.p,MF_MT_FRAME_SIZE,&w,&h));
                    checked(MFGetAttributeRatio(negotiated.p,MF_MT_PIXEL_ASPECT_RATIO,&x,&y));
                    checked(negotiated->GetGUID(MF_MT_SUBTYPE,&subtype));
                    if(w!=width||h!=height||x!=par_x||y!=par_y||subtype!=MFVideoFormat_NV12)throw std::runtime_error("Native decoded image format changed");
                    ++type_events;
                }
                if(sample.p) {
                    if(!times.empty()&&time<=times.back())throw std::runtime_error("Unordered native decoded timestamps");
                    DWORD length{};checked(sample->GetTotalLength(&length));
                    if(!length)throw std::runtime_error("Empty decoded sample");
                    bytes+=length;times.push_back(time);
                }
                if(flags&MF_SOURCE_READERF_ENDOFSTREAM){ended=true;break;}
            }
            if(!ended||times.empty())throw std::runtime_error("No complete native video decode");
            const auto elapsed=std::chrono::duration<double>(std::chrono::steady_clock::now()-begin).count();
            std::printf("{\"status\":\"complete native MP4 decode\",\"width\":%u,\"height\":%u,\"pixel_aspect\":[%u,%u],\"negotiated_type_events\":%u,\"frames\":%zu,\"decoded_bytes\":%llu,\"elapsed_seconds\":%.6f,\"timestamps_100ns\":[",width,height,par_x,par_y,type_events,times.size(),static_cast<unsigned long long>(bytes),elapsed);
            for(std::size_t i=0;i<times.size();++i)std::printf("%s%lld",i?",":"",static_cast<long long>(times[i]));
            std::puts("],\"game_run\":false,\"audio_device_opened\":false,\"screen_presentation\":false,\"hardware_decode_claimed\":false}");
        }
        MFShutdown();CoUninitialize();return 0;
    } catch(const std::exception& error) {
        std::fprintf(stderr,"%s\n",error.what());if(mf)MFShutdown();if(com)CoUninitialize();return 1;
    }
}
