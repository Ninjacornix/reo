#include "session.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstring>
#include <deque>
#include <limits>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <thread>
#include <utility>

namespace reo::native::host_movie {
namespace {
void checked(HRESULT status,const char* what){if(FAILED(status))throw std::runtime_error(what);}
template<class T>struct Com {
    T* p{};~Com(){reset();}Com()=default;Com(const Com&)=delete;Com& operator=(const Com&)=delete;
    void reset()noexcept{if(auto* old=std::exchange(p,nullptr))old->Release();}
    T* operator->()const{return p;}
};
enum class Action {start,append,pause,loop,stop};
struct Command {Action action;Generation generation;std::vector<std::shared_ptr<const movie_assets::Asset>> assets;std::uint32_t width{512};bool value{};};
}
struct Session::Impl {
    mutable std::mutex mutex;std::condition_variable wake;
    std::deque<Command> commands;SessionSnapshot report;
    std::shared_ptr<const CpuFrame> latest;
    std::atomic<bool> closing{};Generation next{};
    std::thread worker;
    Impl():worker([this]{run();}){}
    ~Impl(){closing.store(true);wake.notify_all();if(worker.joinable())worker.join();}
    bool post(Command command){std::lock_guard lock(mutex);if(closing.load()||report.joined||commands.size()==64||!command.generation||command.generation!=report.generation)return false;commands.push_back(std::move(command));wake.notify_one();return true;}
    void run()noexcept {
        try {
            Com<ID3D11Device> device;Com<ID3D11DeviceContext> context;
            checked(D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_VIDEO_SUPPORT|D3D11_CREATE_DEVICE_BGRA_SUPPORT,nullptr,0,D3D11_SDK_VERSION,&device.p,nullptr,&context.p),"Native movie device initialization failed");
            auto player=std::make_unique<Player>(device.p),standby=std::make_unique<Player>(device.p);Com<ID3D11Texture2D> target,readback;
            std::array<std::shared_ptr<CpuFrame>,3> pool;
            std::vector<std::shared_ptr<const movie_assets::Asset>> assets;
            Generation generation{},engine_generation{};std::uint32_t width{512},height{};
            std::size_t index{};std::uint64_t completed_frames{},serial{},backpressure{};
            bool repeat{},paused{},running{};std::optional<std::int64_t> first_pts;
            std::optional<std::size_t> primed;Generation primed_generation{};
            {std::lock_guard lock(mutex);report.device_ready=true;}
            auto open=[&]{
                first_pts.reset();
                engine_generation=player->open(assets[index]->path(),{repeat&&assets.size()==1,true,0.0});player->play(engine_generation);if(paused)player->pause(engine_generation);
            };
            while(!closing.load()) {
              try {
                std::deque<Command> ready;
                {std::unique_lock lock(mutex);if(commands.empty())wake.wait_for(lock,std::chrono::milliseconds(1),[&]{return closing.load()||!commands.empty();});ready.swap(commands);}
                for(auto& command:ready) {
                    if(command.action==Action::stop){if(command.generation==generation){player->close();standby->close();primed.reset();running=false;assets.clear();target.reset();readback.reset();pool={};generation=0;}continue;}
                    {std::lock_guard lock(mutex);if(command.generation!=report.generation)continue;}
                    if(command.action==Action::start){player->close();standby->close();primed.reset();target.reset();readback.reset();pool={};height=0;assets=std::move(command.assets);generation=command.generation;width=command.width;repeat=command.value;paused=false;index=0;completed_frames=serial=backpressure=0;running=true;open();}
                    else if(generation==command.generation) {
                        switch(command.action) {
                        case Action::append:
                            if(assets.size()==256)throw std::runtime_error("Native movie playlist capacity");
                            assets.push_back(std::move(command.assets[0]));if(repeat)player->loop(engine_generation,false);break;
                        case Action::pause:paused=command.value;if(paused)player->pause(engine_generation);else player->play(engine_generation);break;
                        case Action::loop:repeat=command.value;player->loop(engine_generation,repeat&&assets.size()==1);break;
                        case Action::stop:break;
                        case Action::start:break;
                        }
                    }
                }
                if(!running)continue;
                const bool has_next=assets.size()>1&&(index+1<assets.size()||repeat);
                const auto next_index=(index+1)%assets.size();
                if(has_next&&(!primed||*primed!=next_index)){primed_generation=standby->open(assets[next_index]->path(),{false,true,0.0});primed=next_index;}
                else if(!has_next&&primed){standby->close();primed.reset();}
                auto state=player->snapshot();if(state.state==State::error)throw std::runtime_error("Native movie engine reported a source error");
                if(state.state==State::ended) {
                    if(index+1<assets.size()||repeat){completed_frames+=assets[index]->frames();index=(index+1)%assets.size();first_pts.reset();
                        if(primed&&*primed==index){player.swap(standby);engine_generation=primed_generation;standby->close();primed.reset();player->play(engine_generation);if(paused)player->pause(engine_generation);}
                        else open();
                        state=player->snapshot();}
                }
                if(state.aspect_x&&state.aspect_y&&(!target.p||height!=std::uint64_t(width)*state.aspect_y/state.aspect_x)) {
                    const auto proposed=std::uint64_t(width)*state.aspect_y/state.aspect_x;
                    if(!proposed||proposed>2048)throw std::runtime_error("Native movie output aspect bounds");
                    height=static_cast<std::uint32_t>(proposed);target.reset();readback.reset();pool={};
                    D3D11_TEXTURE2D_DESC desc{};desc.Width=width;desc.Height=height;desc.MipLevels=desc.ArraySize=desc.SampleDesc.Count=1;desc.Format=DXGI_FORMAT_B8G8R8A8_UNORM;desc.BindFlags=D3D11_BIND_RENDER_TARGET;
                    checked(device->CreateTexture2D(&desc,nullptr,&target.p),"Native movie render texture failed");desc.BindFlags=0;desc.Usage=D3D11_USAGE_STAGING;desc.CPUAccessFlags=D3D11_CPU_ACCESS_READ;
                    checked(device->CreateTexture2D(&desc,nullptr,&readback.p),"Native movie renderer handoff failed");
                    for(auto& slot:pool){slot=std::make_shared<CpuFrame>();slot->width=width;slot->height=height;slot->pitch=width*4;slot->bgra.resize(std::size_t(width)*height*4);}
                }
                if(target.p) {
                    const auto due=player->transfer(engine_generation,target.p);
                    if(due.updated) {
                        if(!first_pts)first_pts=due.pts_100ns;
                        auto free=std::find_if(pool.begin(),pool.end(),[](const auto& p){return p.use_count()==1;});
                        if(free==pool.end())++backpressure;
                        else {
                            auto& frame=**free;context->CopyResource(readback.p,target.p);D3D11_MAPPED_SUBRESOURCE mapped{};
                            checked(context->Map(readback.p,0,D3D11_MAP_READ,0,&mapped),"Native movie frame readback failed");
                            for(unsigned y=0;y<height;++y)std::memcpy(frame.bgra.data()+std::size_t(y)*frame.pitch,static_cast<const std::uint8_t*>(mapped.pData)+std::size_t(y)*mapped.RowPitch,frame.pitch);
                            context->Unmap(readback.p,0);frame.generation=generation;frame.serial=++serial;frame.pts_100ns=due.pts_100ns-*first_pts;
                            const auto relative=frame.pts_100ns<0?0:static_cast<std::uint64_t>(frame.pts_100ns);frame.ordinal=completed_frames+(relative*30000+5000000ull*1001)/(10000000ull*1001);
                            std::lock_guard lock(mutex);if(report.generation==generation)latest=*free;
                        }
                    }
                }
                {std::lock_guard lock(mutex);if(report.generation==generation){report.state=index&&latest&&state.state==State::loading?State::playing:state.state;report.paused=paused;report.loop=repeat;report.frames=serial;report.backpressure=backpressure;report.clip_index=index;report.queued_clips=assets.size();report.position_seconds=completed_frames*1001.0/30000.0+state.position_seconds;report.duration_seconds=state.duration_seconds;}}
              }catch(const std::exception& error){
                // A failed source retires its pipeline, not the control owner.
                // A later start can use the same device with a fresh engine.
                player->close();standby->close();primed.reset();running=false;
                assets.clear();target.reset();readback.reset();pool={};
                std::lock_guard lock(mutex);if(report.generation==generation){report.state=State::error;report.error=error.what();latest.reset();}
              }
            }
            player->close();standby->close();context->Flush();
        }catch(const std::exception& error){std::lock_guard lock(mutex);report.state=State::error;report.error=error.what();}
        catch(...){std::lock_guard lock(mutex);report.state=State::error;report.error="Unknown native movie worker failure";}
        std::lock_guard lock(mutex);report.joined=true;latest.reset();commands.clear();
    }
};
Session::Session():impl_(std::make_unique<Impl>()){}
Session::~Session()=default;
Generation Session::start(std::vector<std::shared_ptr<const movie_assets::Asset>> assets,bool loop,std::uint32_t width) {
    if(assets.empty()||assets.size()>256||width<16||width>2048||width%16||std::any_of(assets.begin(),assets.end(),[](const auto& p){return !p;}))throw std::invalid_argument("Prepared bounded movie playlist required");
    auto& p=*impl_;std::lock_guard lock(p.mutex);if(p.closing.load()||p.report.joined||p.commands.size()==64||p.next==std::numeric_limits<Generation>::max())throw std::runtime_error("Native movie control owner unavailable");
    const auto generation=++p.next;p.commands.push_back({Action::start,generation,std::move(assets),width,loop});const bool ready=p.report.device_ready;p.report={};p.report.device_ready=ready;p.report.generation=generation;p.report.state=State::loading;p.latest.reset();p.wake.notify_one();return generation;
}
bool Session::append(Generation generation,std::shared_ptr<const movie_assets::Asset> asset){if(!asset)return false;return impl_->post({Action::append,generation,{std::move(asset)}});}
bool Session::pause(Generation generation,bool paused){return impl_->post({Action::pause,generation,{},512,paused});}
bool Session::loop(Generation generation,bool enabled){return impl_->post({Action::loop,generation,{},512,enabled});}
bool Session::stop(Generation generation){auto& p=*impl_;std::lock_guard lock(p.mutex);if(p.closing.load()||p.report.joined||!generation||p.report.generation!=generation||p.commands.size()==64)return false;p.commands.push_back({Action::stop,generation,{}});p.report.generation=0;p.report.state=State::closed;p.latest.reset();p.wake.notify_one();return true;}
SessionSnapshot Session::snapshot()const{std::lock_guard lock(impl_->mutex);return impl_->report;}
std::shared_ptr<const CpuFrame> Session::frame(Generation generation)const{std::lock_guard lock(impl_->mutex);return generation==impl_->report.generation?impl_->latest:nullptr;}
void Session::request_stop()noexcept{impl_->closing.store(true);impl_->wake.notify_all();}
void Session::join()noexcept{request_stop();if(impl_->worker.joinable())impl_->worker.join();}
}
