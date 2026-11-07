// Offscreen real D3D11 decode / Vulkan consumer-fence check. No game or audio.
#include "tools/parallel_gs_backend/movie_runtime/native_frame_surface.h"
#include "tools/parallel_gs_backend/movie_runtime/mpeg2_stream.h"
#include "vulkan/context.hpp"
#include "thread_id.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
namespace gpu=reo_gpu_movie;
namespace n=reo::native::movie_timing_context;
unsigned checks{};
void check(bool value,const char* detail){++checks;if(!value)throw std::runtime_error(detail);}
std::vector<uint8_t> bytes(const char* name){std::ifstream file(name,std::ios::binary|std::ios::ate);if(!file)throw std::runtime_error("Fixture asset open");auto size=file.tellg();if(size<1 || size>32*1024*1024)throw std::runtime_error("Fixture asset bound");std::vector<uint8_t> value(static_cast<size_t>(size));file.seekg(0);file.read(reinterpret_cast<char*>(value.data()),size);if(!file)throw std::runtime_error("Fixture asset read");return value;}
struct Audio final:n::audio::ControlledSource {
    uint32_t paused{};
    n::audio::ProviderStatus status(uint8_t& value)noexcept override{value=3;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{value={0,48000};return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus sample_frequency(uint32_t& value)noexcept override{value=48000;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus pause(uint32_t value)noexcept override{paused=value;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus discard(uint32_t,uint32_t& value)noexcept override{value=0;return n::audio::ProviderStatus::completed;}
};
struct Helper final:n::audio::HelperClock {
    n::audio::ProviderStatus counter(uint64_t& value)noexcept override{value=0;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(uint64_t& value)noexcept override{value=576000;return n::audio::ProviderStatus::completed;}
};
struct Ports final:n::Ports {n::Reply call(n::pause::Call,const n::View&)noexcept override{return{};}};
template<class F>void until(F&& done,const char* message){auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){if(std::chrono::steady_clock::now()>deadline)throw std::runtime_error(message);std::this_thread::yield();}}
struct Gate {
    Vulkan::Device& device;Vulkan::Semaphore semaphore;bool signaled{};
    void signal()noexcept{if(signaled)return;VkSemaphoreSignalInfo info{VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO};info.semaphore=semaphore->get_semaphore();info.value=1;(void)device.get_device_table().vkSignalSemaphore(device.get_device(),&info);signaled=true;}
    ~Gate(){if(!signaled){signal();device.wait_idle();}} // Signal BEFORE scoped frame/device cleanup on failure.
};
int main(int argc,char** argv){try{
    if(argc!=3)throw std::runtime_error("Expected owned program-stream slice and certified CSC shader");
    const auto source=bytes(argv[1]);gpu::Mpeg2ElementaryStream elementary;gpu::MpegProgramStream program(elementary);
    for(size_t at=0;at<source.size() && !elementary.hasPicture();){const auto count=std::min<size_t>(4096,source.size()-at);program.feed(at,std::span<const uint8_t>(source).subspan(at,count));at+=count;}
    check(elementary.hasPicture(),"No complete owned MPEG picture");const auto picture=elementary.picture();
    check(picture.kind==1 && picture.progressive && picture.timestamp && picture.timestamp->hasPts,"Expected independent progressive I picture with observed PES PTS");
    auto shaderBytes=bytes(argv[2]);check(shaderBytes.size()%4==0,"CSC word alignment");std::vector<uint32_t> shader(shaderBytes.size()/4);std::memcpy(shader.data(),shaderBytes.data(),shaderBytes.size());
    Util::register_thread_index(0);check(Vulkan::Context::init_loader(nullptr),"Vulkan loader");Vulkan::Context context;context.set_num_thread_indices(1);
    check(context.init_instance_and_device(nullptr,0,nullptr,0,Vulkan::CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT),"Vulkan device");Vulkan::Device device;device.set_context(context);device.init_frame_contexts(4);
    const auto& features=device.get_device_features();check(features.vk11_props.deviceLUIDValid,"Actual Vulkan device LUID");
    Microsoft::WRL::ComPtr<IDXGIFactory1> factory;check(SUCCEEDED(CreateDXGIFactory1(IID_PPV_ARGS(&factory))),"DXGI factory");Microsoft::WRL::ComPtr<IDXGIAdapter1> adapter;DXGI_ADAPTER_DESC1 description{};
    for(UINT index=0;;++index){Microsoft::WRL::ComPtr<IDXGIAdapter1> candidate;auto result=factory->EnumAdapters1(index,&candidate);if(result==DXGI_ERROR_NOT_FOUND)break;check(SUCCEEDED(result),"Adapter enumeration");DXGI_ADAPTER_DESC1 d{};check(SUCCEEDED(candidate->GetDesc1(&d)),"Adapter description");if(!(d.Flags&DXGI_ADAPTER_FLAG_SOFTWARE) && !std::memcmp(&d.AdapterLuid,features.vk11_props.deviceLUID,VK_LUID_SIZE)){adapter=std::move(candidate);description=d;break;}}
    check(bool(adapter),"Matching hardware adapter");Microsoft::WRL::ComPtr<ID3D11Device> decoder;D3D_FEATURE_LEVEL level{};D3D_FEATURE_LEVEL levels[]{D3D_FEATURE_LEVEL_11_1,D3D_FEATURE_LEVEL_11_0};
    check(SUCCEEDED(D3D11CreateDevice(adapter.Get(),D3D_DRIVER_TYPE_UNKNOWN,nullptr,D3D11_CREATE_DEVICE_VIDEO_SUPPORT|D3D11_CREATE_DEVICE_BGRA_SUPPORT,levels,2,D3D11_SDK_VERSION,&decoder,&level,nullptr)),"Actual D3D11 decoder device");
    auto bridge=std::make_shared<gpu::SameOwnerMovieBridge>(device,decoder.Get(),1,picture.width,picture.height,shader);
    auto audio=std::make_shared<Audio>();n::Config settings;settings.audio=audio;settings.helper=std::make_shared<Helper>();settings.ports=std::make_shared<Ports>();settings.facts.selector=1;settings.facts.rate=5;settings.buffering=n::Buffering{};settings.buffering->audio=1;settings.audio_commands=n::AudioCommands{};
    auto clock=n::Context::create(settings);auto frames=n::VideoFrames::create(clock,1);gpu::NativeVideoFrames pipeline(bridge,frames);
    Vulkan::BufferCreateInfo info;info.domain=Vulkan::BufferDomain::CachedHost;info.size=uint64_t(picture.width)*picture.height*4;info.usage=VK_BUFFER_USAGE_TRANSFER_DST_BIT;auto readback=device.create_buffer(info);check(bool(readback),"Owned GPU readback target");
    auto record=[readback,&picture](Vulkan::CommandBuffer& cmd,const Vulkan::ImageView& view,const gpu::MoviePictureIdentity&){
        const auto& image=view.get_image();cmd.image_barrier(image,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);
        VkImageSubresourceLayers sub{VK_IMAGE_ASPECT_COLOR_BIT,0,0,1};cmd.copy_image_to_buffer(*readback,image,0,{0,0,0},{picture.width,picture.height,1},0,0,sub);
        cmd.buffer_barrier(*readback,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_WRITE_BIT,VK_PIPELINE_STAGE_2_HOST_BIT,VK_ACCESS_2_HOST_READ_BIT);
        cmd.image_barrier(image,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT);
    };
    auto submission=picture.submission();submission.picture.wDecodedPictureIndex=0;submission.picture.wForwardRefPictureIndex=submission.picture.wBackwardRefPictureIndex=0xffff;
    gpu::MoviePictureIdentity identity;identity.generation=1;identity.picture=1;identity.compressedBegin=picture.begin;identity.compressedEnd=picture.end;identity.sofdec=1;identity.work=2;identity.truePictureBoundaries=true;identity.truePlayerPts=true;identity.pts90k=static_cast<int64_t>(picture.timestamp->pts33);
    auto decoded=pipeline.decode(identity,submission,0,0,n::Words{0,90000},record);check(decoded.status==n::FrameStatus::completed || decoded.status==n::FrameStatus::pending,"Joined native decode publication");
    until([&]{const auto status=frames->poll();check(status==n::FrameStatus::completed || status==n::FrameStatus::pending,"Real producer poll");return frames->peek().status==n::FrameStatus::completed;},"Producer fence did not complete");
    auto acquired=frames->acquire();check(acquired.status==n::FrameStatus::completed,"Clock-admitted native frame");
    auto semaphore=device.request_semaphore(VK_SEMAPHORE_TYPE_TIMELINE);check(bool(semaphore),"Real host-signaled consumer gate");Gate gate{device,semaphore};
    auto wait=device.request_timeline_semaphore_as_binary(*semaphore,1);wait->signal_external();device.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic,std::move(wait),VK_PIPELINE_STAGE_2_TRANSFER_BIT,true);
    check(frames->present(acquired.key)==n::FrameStatus::completed && frames->release(acquired.key)==n::FrameStatus::completed,"Actual Vulkan consumer submission and logical release");
    check(frames->poll()==n::FrameStatus::pending && frames->snapshot().resources==1 && frames->reserve().status==n::FrameStatus::pending,"Unsignaled real renderer fence prevents physical reuse");
    gate.signal();until([&]{return frames->poll()==n::FrameStatus::completed;},"Renderer fence did not retire");check(frames->snapshot().resources==0,"Physical export released after real render fence");
    auto mapped=static_cast<const uint8_t*>(device.map_host_buffer(*readback,Vulkan::MEMORY_ACCESS_READ_BIT));check(mapped!=nullptr,"Completed GPU readback map");std::vector<uint8_t> pixels(mapped,mapped+info.size);device.unmap_host_buffer(*readback,Vulkan::MEMORY_ACCESS_READ_BIT);
    check(std::any_of(pixels.begin(),pixels.end(),[](auto byte){return byte!=0;}),"GPU consumer copied actual pixels");
    const auto pixelHash=reo_gpu_movie_asset::sha256(pixels);
    identity.picture=2;auto future=pipeline.decode(identity,submission,0,0,n::Words{3000,90000},record);check(future.status==n::FrameStatus::completed || future.status==n::FrameStatus::pending,"Export slot safely reused for a new incarnation");
    until([&]{(void)frames->poll();return frames->peek().status==n::FrameStatus::completed;},"Second producer fence");check(frames->acquire().status==n::FrameStatus::held,"Future picture held by shared clock");
    n::Input pause;pause.value=1;check(clock->execute(n::Operation::pause,pause).status==n::Status::completed,"Pause joined clock/audio model");pause.value=2;check(clock->execute(n::Operation::pause,pause).status==n::Status::completed && clock->execute(n::Operation::tick).status==n::Status::completed,"Original frame-step and ordinary cached-clock refresh");
    check(frames->acquire().status==n::FrameStatus::completed && audio->paused==1,"Frame step admits GPU frame while audio remains paused");check(frames->present(future.key)==n::FrameStatus::completed && frames->release(future.key)==n::FrameStatus::completed,"Second real GPU consumer");
    until([&]{return frames->poll()==n::FrameStatus::completed;},"Second render fence");
    // Withhold the PES/player timestamp deliberately to exercise the adapter's
    // deferred-observation protocol. This is an authored timing case, not a
    // claim that this particular owned I picture lacked a PES timestamp.
    identity.picture=3;identity.truePlayerPts=false;identity.pendingPlayerPts=true;identity.pts90k=gpu::UnboundMoviePts;identity.originalHeaderSerial=1;identity.originalReferenceMetadata=0x1234;
    auto pending=pipeline.decode(identity,submission,0,0,std::nullopt,record);check(pending.status==n::FrameStatus::pending && frames->peek().status==n::FrameStatus::empty,"No publication before timing observation");
    check(pipeline.publishTime(pending.key,{1600,48000})==n::FrameStatus::invalid_input,"Missing timing authority refuses");
    until([&]{const auto status=pipeline.publishTime(pending.key,{1600,48000},gpu::NativeVideoFrames::PlayerTime{0x1234,static_cast<int64_t>(picture.timestamp->pts33),false});check(status==n::FrameStatus::completed || status==n::FrameStatus::pending,"Late player time binding");return frames->peek().status==n::FrameStatus::completed;},"Deferred producer/player observation");
    check(frames->acquire().status==n::FrameStatus::completed,"Bound deferred frame admitted");
    check(frames->release(pending.key)==n::FrameStatus::completed,"Deferred frame logical release");
    until([&]{return frames->poll()==n::FrameStatus::completed;},"Deferred producer retirement");
    identity.picture=4;
    auto untimed=pipeline.decode(identity,submission,0,0,std::nullopt,record);
    check(untimed.status==n::FrameStatus::pending,"Retain untimed producer for close");
    until([&]{const auto status=pipeline.close();check(status==n::FrameStatus::completed || status==n::FrameStatus::pending,"Pending-timestamp close polls real producer fence");return status==n::FrameStatus::completed;},"Untimed producer close");
    check(pipeline.publishTime(untimed.key,{1600,48000})==n::FrameStatus::closed && pipeline.decode(identity,submission,0,0,std::nullopt,record).status==n::FrameStatus::closed,"Closed adapter refuses new publication and decode");
    check(pipeline.close()==n::FrameStatus::completed && frames->snapshot().resources==0,"Idempotent adapter close retains no GPU surfaces");
    bridge->shutdown();device.wait_idle();
    std::cout<<"{\"status\":\"real GPU video ownership checks passed\",\"checks\":"<<checks<<",\"width\":"<<picture.width<<",\"height\":"<<picture.height<<",\"vendor\":"<<description.VendorId<<",\"device\":"<<description.DeviceId<<",\"pixel_sha256\":\""<<pixelHash<<"\",\"real_renderer_gate_prevented_reuse\":true,\"game_run\":false,\"audio_device_opened\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<"GPU ownership check failed: "<<error.what()<<'\n';return 1;}}
