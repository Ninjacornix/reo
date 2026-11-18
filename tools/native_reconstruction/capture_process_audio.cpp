// Private validation tool: Windows process loopback, never endpoint/microphone
// capture. The target's creation time and executable must match the owned run.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <audioclient.h>
#include <mmdeviceapi.h>
#include "audioclientactivationparams.h"
#include <atomic>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace {
void require(bool ok,const char* why){if(!ok)throw std::runtime_error(why);}
void checked(HRESULT hr,const char* why){if(FAILED(hr)){std::fprintf(stderr,"HRESULT=%08lx ",static_cast<unsigned long>(hr));throw std::runtime_error(why);}}
struct Handle {HANDLE value{};~Handle(){if(value&&value!=INVALID_HANDLE_VALUE)CloseHandle(value);}};
template<class T>struct Com {T* p{};~Com(){if(p)p->Release();}T* operator->()const{return p;}};
class Completion final:public IActivateAudioInterfaceCompletionHandler,public IAgileObject {
    std::atomic<ULONG> refs{1};
public:
    Handle ready{CreateEventW(nullptr,FALSE,FALSE,nullptr)};Com<IAudioClient> client;HRESULT result{E_PENDING};
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID id,void** out)override{
        if(!out)return E_POINTER;*out=nullptr;
        if(id==IID_IUnknown||id==__uuidof(IActivateAudioInterfaceCompletionHandler))*out=static_cast<IActivateAudioInterfaceCompletionHandler*>(this);
        else if(id==__uuidof(IAgileObject))*out=static_cast<IAgileObject*>(this);else return E_NOINTERFACE;
        AddRef();return S_OK;
    }
    ULONG STDMETHODCALLTYPE AddRef()override{return refs.fetch_add(1)+1;}
    ULONG STDMETHODCALLTYPE Release()override{const auto n=refs.fetch_sub(1)-1;if(!n)delete this;return n;}
    HRESULT STDMETHODCALLTYPE ActivateCompleted(IActivateAudioInterfaceAsyncOperation* operation)override{
        Com<IUnknown> value;HRESULT activation{};result=operation->GetActivateResult(&activation,&value.p);
        if(SUCCEEDED(result))result=activation;
        if(SUCCEEDED(result))result=value->QueryInterface(__uuidof(IAudioClient),reinterpret_cast<void**>(&client.p));
        SetEvent(ready.value);return S_OK;
    }
};
struct Apartment {Apartment(){checked(CoInitializeEx(nullptr,COINIT_MULTITHREADED),"COM initialization");}~Apartment(){CoUninitialize();}};
struct File {
    Handle handle;
    explicit File(const std::filesystem::path& path):handle{CreateFileW(path.c_str(),GENERIC_WRITE,0,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr)}{require(handle.value!=INVALID_HANDLE_VALUE,"Fresh output file required");}
    void write(const void* data,DWORD size){DWORD written{};require(WriteFile(handle.value,data,size,&written,nullptr)&&written==size,"Capture file write failed");}
    void seek(DWORD offset){require(SetFilePointer(handle.value,static_cast<LONG>(offset),nullptr,FILE_BEGIN)!=INVALID_SET_FILE_POINTER,"Capture header seek failed");}
};
std::uint64_t identity(HANDLE process){FILETIME created{},exit{},kernel{},user{};require(GetProcessTimes(process,&created,&exit,&kernel,&user),"Owned process creation time unavailable");return(std::uint64_t(created.dwHighDateTime)<<32)|created.dwLowDateTime;}
}
int wmain(int argc,wchar_t** argv)try {
    require(argc==6,"pid creation-filetime executable seconds fresh.wav required");
    const auto numeric_pid=std::stoull(argv[1]);require(numeric_pid>0&&numeric_pid<=0xffffffff,"PID bounds");const auto pid=static_cast<DWORD>(numeric_pid);
    const auto creation=std::stoull(argv[2]);const auto seconds=std::stoul(argv[4]);require(seconds>0&&seconds<=900,"Capture duration bounds");
    Handle process{OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION|SYNCHRONIZE,FALSE,pid)};require(bool(process.value),"Owned process unavailable");
    wchar_t actual[32768];DWORD length=32768;require(QueryFullProcessImageNameW(process.value,0,actual,&length)&&identity(process.value)==creation,"Owned process identity mismatch");
    const auto wanted=std::filesystem::canonical(argv[3]);require(_wcsicmp(wanted.c_str(),std::wstring(actual,length).c_str())==0,"Owned executable mismatch");
    Apartment apartment;Com<Completion> callback;callback.p=new Completion;require(bool(callback->ready.value),"Activation event failed");
    AUDIOCLIENT_ACTIVATION_PARAMS activation{};activation.ActivationType=AUDIOCLIENT_ACTIVATION_TYPE_PROCESS_LOOPBACK;
    activation.ProcessLoopbackParams={pid,PROCESS_LOOPBACK_MODE_INCLUDE_TARGET_PROCESS_TREE};
    PROPVARIANT parameters{};parameters.vt=VT_BLOB;parameters.blob.cbSize=sizeof(activation);parameters.blob.pBlobData=reinterpret_cast<BYTE*>(&activation);
    Com<IActivateAudioInterfaceAsyncOperation> operation;
    checked(ActivateAudioInterfaceAsync(VIRTUAL_AUDIO_DEVICE_PROCESS_LOOPBACK,__uuidof(IAudioClient),&parameters,callback.p,&operation.p),"Process-only audio activation");
    require(WaitForSingleObject(callback->ready.value,10000)==WAIT_OBJECT_0,"Process-only activation deadline");checked(callback->result,"Process-only audio activation failed");
    auto* client=callback->client.p;WAVEFORMATEX format{WAVE_FORMAT_PCM,2,48000,192000,4,16,0};
    checked(client->Initialize(AUDCLNT_SHAREMODE_SHARED,AUDCLNT_STREAMFLAGS_LOOPBACK|AUDCLNT_STREAMFLAGS_EVENTCALLBACK|AUDCLNT_STREAMFLAGS_AUTOCONVERTPCM,0,0,&format,nullptr),"Process-only audio initialization");
    Handle event{CreateEventW(nullptr,FALSE,FALSE,nullptr)};require(bool(event.value),"Capture event failed");checked(client->SetEventHandle(event.value),"Capture event binding");
    Com<IAudioCaptureClient> capture;checked(client->GetService(__uuidof(IAudioCaptureClient),reinterpret_cast<void**>(&capture.p)),"Capture service");
    require(identity(process.value)==creation&&WaitForSingleObject(process.value,0)==WAIT_TIMEOUT,"Owned process exited before capture");
    const std::filesystem::path output=argv[5];File wave(output),packets(output.wstring()+L".packets.csv");
    const std::uint32_t header[]{0x46464952,36,0x45564157,0x20746d66,16,0x00020001,48000,192000,0x00100004,0x61746164,0};wave.write(header,sizeof(header));
    constexpr char columns[]="qpc_100ns,device_frames,frames,flags\n";packets.write(columns,sizeof(columns)-1);
    checked(client->Start(),"Capture start");std::uint64_t frames{},nonzero{},squares{},discontinuities{},timestamp_errors{};int peak{};
    const auto started=std::chrono::steady_clock::now(),deadline=started+std::chrono::seconds(seconds);bool exited=false;
    try {
        while(std::chrono::steady_clock::now()<deadline){
            HANDLE events[]{event.value,process.value};const auto wait=WaitForMultipleObjects(2,events,FALSE,100);
            if(wait==WAIT_OBJECT_0+1){exited=true;break;}require(wait==WAIT_OBJECT_0||wait==WAIT_TIMEOUT,"Capture wait failed");
            UINT32 available{};checked(capture->GetNextPacketSize(&available),"Capture packet size");
            while(available){
                BYTE* data{};UINT32 count{};DWORD flags{};UINT64 position{},qpc{};
                checked(capture->GetBuffer(&data,&count,&flags,&position,&qpc),"Capture packet");
                std::vector<std::uint8_t> zero;if(flags&AUDCLNT_BUFFERFLAGS_SILENT){zero.resize(std::size_t(count)*4);data=zero.data();}
                // Copy before releasing the OS lease. I/O errors retire this tool.
                std::vector<std::uint8_t> copy(data,data+std::size_t(count)*4);checked(capture->ReleaseBuffer(count),"Release capture packet");
                wave.write(copy.data(),static_cast<DWORD>(copy.size()));char row[160];const auto n=std::snprintf(row,sizeof(row),"%llu,%llu,%u,%lu\n",static_cast<unsigned long long>(qpc),static_cast<unsigned long long>(position),count,static_cast<unsigned long>(flags));packets.write(row,static_cast<DWORD>(n));
                for(std::size_t i=0;i<copy.size();i+=4)if(copy[i]||copy[i+1]||copy[i+2]||copy[i+3])++nonzero;
                for(std::size_t i=0;i<copy.size();i+=2){std::int16_t sample;std::memcpy(&sample,copy.data()+i,2);const auto value=static_cast<int>(sample);peak=std::max(peak,std::abs(value));squares+=static_cast<std::uint64_t>(value*value);}
                frames+=count;discontinuities+=(flags&AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY)!=0;timestamp_errors+=(flags&AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR)!=0;
                checked(capture->GetNextPacketSize(&available),"Next capture packet");
            }
        }
    }catch(...){client->Stop();throw;}
    checked(client->Stop(),"Capture stop");require(frames*4<=0xffffffff-36,"WAV capture bounds");const auto bytes=static_cast<DWORD>(frames*4),riff=bytes+36;
    wave.seek(4);wave.write(&riff,4);wave.seek(40);wave.write(&bytes,4);require(FlushFileBuffers(wave.handle.value)&&FlushFileBuffers(packets.handle.value),"Capture flush");
    std::printf("{\"scope\":\"owned-process-tree-only\",\"pid\":%lu,\"creation_filetime\":%llu,\"frames\":%llu,\"nonzero_pcm_frames\":%llu,\"peak_pcm16\":%d,\"rms_pcm16\":%.6f,\"discontinuous_packets\":%llu,\"timestamp_errors\":%llu,\"process_exited\":%s,\"elapsed_seconds\":%.6f}\n",static_cast<unsigned long>(pid),static_cast<unsigned long long>(creation),static_cast<unsigned long long>(frames),static_cast<unsigned long long>(nonzero),peak,frames?std::sqrt(static_cast<double>(squares)/(frames*2)):0,static_cast<unsigned long long>(discontinuities),static_cast<unsigned long long>(timestamp_errors),exited?"true":"false",std::chrono::duration<double>(std::chrono::steady_clock::now()-started).count());return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
