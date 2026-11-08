#include "player.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <d3d10.h>
#include <mfapi.h>
#include <mfmediaengine.h>
#include <wincodec.h>
#include <shlwapi.h>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cwctype>
#include <limits>
#include <stdexcept>
#include <thread>
#include <utility>

namespace reo::native::host_movie {
namespace {
void check(HRESULT value,const char* operation) {
    if(FAILED(value)) {
        char message[192];std::snprintf(message,sizeof(message),"Native movie %s: HRESULT %08lx",operation,static_cast<unsigned long>(value));
        throw std::runtime_error(message);
    }
}
template<class T>class Com {
    T* value_{};
public:
    Com()=default;explicit Com(T* value):value_(value){if(value_)value_->AddRef();}
    ~Com(){reset();}
    Com(const Com&)=delete;Com& operator=(const Com&)=delete;
    Com(Com&& other)noexcept:value_(std::exchange(other.value_,nullptr)){}
    Com& operator=(Com&& other)noexcept{if(this!=&other){reset();value_=std::exchange(other.value_,nullptr);}return *this;}
    void reset()noexcept{if(auto* old=std::exchange(value_,nullptr))old->Release();}
    T* get()const noexcept{return value_;}T* operator->()const noexcept{return value_;}
    T** out(){if(value_)throw std::logic_error("Nonempty COM output");return &value_;}
};
class Notify final:public IMFMediaEngineNotify {
    std::atomic<ULONG> refs_{1};
public:
    std::atomic<std::uint64_t> events{};
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID id,void** result)override {
        if(!result)return E_POINTER;
        *result=nullptr;
        if(id!=IID_IUnknown && id!=IID_IMFMediaEngineNotify)return E_NOINTERFACE;
        *result=static_cast<IMFMediaEngineNotify*>(this);AddRef();return S_OK;
    }
    ULONG STDMETHODCALLTYPE AddRef()override{return refs_.fetch_add(1,std::memory_order_relaxed)+1;}
    ULONG STDMETHODCALLTYPE Release()override{const auto left=refs_.fetch_sub(1,std::memory_order_acq_rel)-1;if(!left)delete this;return left;}
    HRESULT STDMETHODCALLTYPE EventNotify(DWORD event,DWORD_PTR first,DWORD)override {
        if(event==MF_MEDIA_ENGINE_EVENT_NOTIFYSTABLESTATE)SetEvent(reinterpret_cast<HANDLE>(first));
        events.fetch_add(1,std::memory_order_relaxed);return S_OK;
    }
};
struct Platform {
    bool com{},mf{};
    Platform(){check(CoInitializeEx(nullptr,COINIT_MULTITHREADED),"COM initialization");com=true;
        try{check(MFStartup(MF_VERSION),"media startup");mf=true;}catch(...){CoUninitialize();throw;}}
    ~Platform(){if(mf)MFShutdown();if(com)CoUninitialize();}
};
std::wstring local_url(const std::filesystem::path& source) {
    const auto path=std::filesystem::absolute(source).lexically_normal();
    auto extension=path.extension().wstring();for(auto& ch:extension)ch=static_cast<wchar_t>(std::towlower(ch));
    if(extension!=L".mp4" || !std::filesystem::is_regular_file(path))throw std::invalid_argument("Existing local MP4 movie required");
    const auto native=path.native();
    if(native.rfind(L"\\\\",0)==0)throw std::invalid_argument("Movie source must be a local file");
    if(native.size()>32767)throw std::invalid_argument("Movie path is too long");
    std::wstring url(native.size()*3+32,L'\0');DWORD count=static_cast<DWORD>(url.size());
    check(UrlCreateFromPathW(native.c_str(),url.data(),&count,0),"local file URL");url.resize(count);return url;
}
void validate_volume(double value){if(!std::isfinite(value)||value<0||value>1)throw std::invalid_argument("Movie volume must be 0..1");}
}
struct Player::Impl {
    const std::thread::id owner=std::this_thread::get_id();
    Platform platform;
    Com<ID3D11Device> device;
    Com<IMFDXGIDeviceManager> manager;
    Com<IMFMediaEngineClassFactory> factory;
    Com<IMFMediaEngine> engine;
    Com<Notify> notify;
    Com<IWICImagingFactory> wic_factory;Com<IWICBitmap> bitmap;Com<ID3D11DeviceContext> upload;
    bool software{};std::uint32_t bitmap_width{},bitmap_height{};
    Generation current{},next{};std::uint64_t frames{};HRESULT shutdown_error{S_OK};
    explicit Impl(ID3D11Device* graphics):device(graphics) {
        constexpr auto required=D3D11_CREATE_DEVICE_VIDEO_SUPPORT|D3D11_CREATE_DEVICE_BGRA_SUPPORT;
        if(!graphics || (graphics->GetCreationFlags()&required)!=required || graphics->GetCreationFlags()&D3D11_CREATE_DEVICE_SINGLETHREADED)throw std::invalid_argument("Thread-safe native video/BGRA device required");
        Com<ID3D10Multithread> threads;check(graphics->QueryInterface(IID_PPV_ARGS(threads.out())),"device multithread interface");threads->SetMultithreadProtected(TRUE);
        UINT token{};check(MFCreateDXGIDeviceManager(&token,manager.out()),"device manager");
        check(manager->ResetDevice(graphics,token),"device manager binding");
        check(CoCreateInstance(CLSID_MFMediaEngineClassFactory,nullptr,CLSCTX_INPROC_SERVER,IID_PPV_ARGS(factory.out())),"media engine factory");
        const auto* requested=_wgetenv(L"REO_NATIVE_HOST_MOVIE_SOFTWARE");software=requested&&requested[0]==L'1'&&!requested[1];
        if(software){check(CoCreateInstance(CLSID_WICImagingFactory,nullptr,CLSCTX_INPROC_SERVER,IID_PPV_ARGS(wic_factory.out())),"native WIC factory");graphics->GetImmediateContext(upload.out());}
    }
    void thread()const{if(std::this_thread::get_id()!=owner)throw std::logic_error("Native movie call is outside its graphics owner");}
    void selected(Generation generation)const{thread();if(!engine.get()||!generation||generation!=current)throw std::invalid_argument("Stale native movie generation");}
    void close()noexcept {
        if(std::this_thread::get_id()!=owner)std::terminate();
        if(engine.get()){shutdown_error=engine->Shutdown();engine.reset();}
        notify.reset();current=0;frames=0;
    }
};
Player::Player(ID3D11Device* device):impl_(std::make_unique<Impl>(device)){}
Player::~Player(){close();}
Generation Player::open(const std::filesystem::path& path,Options options) {
    auto& p=*impl_;p.thread();validate_volume(options.volume);const auto url=local_url(path);
    if(p.next==std::numeric_limits<Generation>::max())throw std::overflow_error("Native movie generation exhausted");
    Com<Notify> notify;*notify.out()=new Notify;
    Com<IMFAttributes> attributes;check(MFCreateAttributes(attributes.out(),3),"engine attributes");
    if(!p.software)check(attributes->SetUnknown(MF_MEDIA_ENGINE_DXGI_MANAGER,p.manager.get()),"engine device");
    check(attributes->SetUnknown(MF_MEDIA_ENGINE_CALLBACK,notify.get()),"engine callback");
    check(attributes->SetUINT32(MF_MEDIA_ENGINE_VIDEO_OUTPUT_FORMAT,DXGI_FORMAT_B8G8R8A8_UNORM),"engine frame format");
    Com<IMFMediaEngine> engine;check(p.factory->CreateInstance(0,attributes.get(),engine.out()),"engine creation");
    try {
        check(engine->SetPreload(MF_MEDIA_ENGINE_PRELOAD_AUTOMATIC),"preload");
        check(engine->SetLoop(options.loop),"initial loop");check(engine->SetMuted(options.muted),"initial mute");check(engine->SetVolume(options.volume),"initial volume");
        BSTR source=SysAllocStringLen(url.data(),static_cast<UINT>(url.size()));if(!source)throw std::bad_alloc();
        const auto status=engine->SetSource(source);SysFreeString(source);check(status,"set source");
    }catch(...){engine->Shutdown();throw;}
    p.close();
    if(FAILED(p.shutdown_error)){engine->Shutdown();check(p.shutdown_error,"prior source shutdown");}
    p.engine=std::move(engine);p.notify=std::move(notify);p.current=++p.next;return p.current;
}
void Player::play(Generation generation){auto& p=*impl_;p.selected(generation);check(p.engine->Play(),"play");}
void Player::pause(Generation generation){auto& p=*impl_;p.selected(generation);check(p.engine->Pause(),"pause");}
void Player::seek(Generation generation,double seconds){auto& p=*impl_;p.selected(generation);
    if(!std::isfinite(seconds)||seconds<0||!std::isfinite(p.engine->GetDuration())||seconds>p.engine->GetDuration())throw std::invalid_argument("Movie seek outside ready duration");
    check(p.engine->SetCurrentTime(seconds),"seek");}
void Player::loop(Generation generation,bool enabled){auto& p=*impl_;p.selected(generation);check(p.engine->SetLoop(enabled),"loop");}
void Player::volume(Generation generation,double value){auto& p=*impl_;p.selected(generation);validate_volume(value);check(p.engine->SetVolume(value),"volume");}
void Player::muted(Generation generation,bool enabled){auto& p=*impl_;p.selected(generation);check(p.engine->SetMuted(enabled),"mute");}
Snapshot Player::snapshot()const {
    const auto& p=*impl_;p.thread();Snapshot out;out.generation=p.current;out.shutdown_error=p.shutdown_error;out.transferred_frames=p.frames;
    if(!p.engine.get())return out;
    out.events=p.notify->events.load(std::memory_order_relaxed);
    Com<IMFMediaError> error;check(p.engine->GetError(error.out()),"error query");
    if(error.get()){out.state=State::error;out.error_code=error->GetErrorCode();out.extended_error=error->GetExtendedErrorCode();return out;}
    const auto ready=p.engine->GetReadyState();out.position_seconds=p.engine->GetCurrentTime();out.duration_seconds=p.engine->GetDuration();
    out.has_audio=p.engine->HasAudio()!=FALSE;out.seeking=p.engine->IsSeeking()!=FALSE;out.loop=p.engine->GetLoop()!=FALSE;
    if(ready>=MF_MEDIA_ENGINE_READY_HAVE_METADATA) {
        DWORD width{},height{},aspect_x{},aspect_y{};
        check(p.engine->GetNativeVideoSize(&width,&height),"video dimensions");
        check(p.engine->GetVideoAspectRatio(&aspect_x,&aspect_y),"display aspect");
        out.display_width=width;out.display_height=height;out.aspect_x=aspect_x;out.aspect_y=aspect_y;
    }
    out.state=p.engine->IsEnded()?State::ended:ready<MF_MEDIA_ENGINE_READY_HAVE_FUTURE_DATA?State::loading:
        !p.engine->IsPaused()?State::playing:out.position_seconds>0?State::paused:State::ready;
    return out;
}
Frame Player::transfer(Generation generation,ID3D11Texture2D* target) {
    auto& p=*impl_;p.selected(generation);if(!target)throw std::invalid_argument("Native movie render target required");
    Com<ID3D11Device> device;target->GetDevice(device.out());
    D3D11_TEXTURE2D_DESC desc{};target->GetDesc(&desc);
    if(device.get()!=p.device.get()||!desc.Width||!desc.Height||desc.Width>16384||desc.Height>16384||desc.Format!=DXGI_FORMAT_B8G8R8A8_UNORM||
        desc.SampleDesc.Count!=1||desc.ArraySize!=1||desc.MipLevels!=1||!(desc.BindFlags&D3D11_BIND_RENDER_TARGET))throw std::invalid_argument("Movie target must be same-device BGRA8 render texture");
    LONGLONG pts{};const auto ready=p.engine->OnVideoStreamTick(&pts);check(ready,"video stream tick");
    if(ready==S_FALSE)return{false,generation,0};
    RECT destination{0,0,static_cast<LONG>(desc.Width),static_cast<LONG>(desc.Height)};MFARGB border{0,0,0,255};
    if(p.software){
        if(!p.bitmap.get()||p.bitmap_width!=desc.Width||p.bitmap_height!=desc.Height){p.bitmap.reset();check(p.wic_factory->CreateBitmap(desc.Width,desc.Height,GUID_WICPixelFormat32bppBGRA,WICBitmapCacheOnLoad,p.bitmap.out()),"native CPU video bitmap");p.bitmap_width=desc.Width;p.bitmap_height=desc.Height;}
        check(p.engine->TransferVideoFrame(p.bitmap.get(),nullptr,&destination,&border),"native software video transfer");
        WICRect rect{0,0,static_cast<INT>(desc.Width),static_cast<INT>(desc.Height)};Com<IWICBitmapLock> locked;check(p.bitmap->Lock(&rect,WICBitmapLockRead,locked.out()),"native CPU video lock");
        UINT pitch{},bytes{};BYTE* pixels{};check(locked->GetStride(&pitch),"native CPU video stride");check(locked->GetDataPointer(&bytes,&pixels),"native CPU video data");
        if(pitch<desc.Width*4||bytes<std::uint64_t(pitch)*(desc.Height-1)+std::uint64_t(desc.Width)*4)throw std::runtime_error("Native CPU video bitmap bounds");
        p.upload->UpdateSubresource(target,0,nullptr,pixels,pitch,0);
    }else check(p.engine->TransferVideoFrame(target,nullptr,&destination,&border),"video frame transfer");
    ++p.frames;return{true,generation,pts};
}
void Player::close()noexcept{if(impl_)impl_->close();}
}
