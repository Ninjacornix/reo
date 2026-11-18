// Offscreen real D3D11 decode / Vulkan consumer-fence check. No game or audio.
#include "tools/parallel_gs_backend/movie_runtime/native_video_graph.h"
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
namespace life=reo::native::movie_lifecycle;
struct View final:reo::native::resources::ByteView {
    std::vector<uint8_t> value;
    explicit View(std::vector<uint8_t> data):value(std::move(data)){}
    uint64_t size()const noexcept override{return value.size();}
    reo::native::resources::ReadResult read(uint64_t at,std::span<std::byte> output)const override{if(at>value.size() || output.size()>value.size()-at)return{};std::memcpy(output.data(),value.data()+at,output.size());return{reo::native::resources::Status::ok,output.size()};}
};
struct Videos final:life::VideoFactory {
    Vulkan::Device& device;ID3D11Device* decoder;std::vector<uint32_t> shader;unsigned width,height,created{};
    gpu::NativeFrameSurface::Recorder record;std::weak_ptr<gpu::NativeVideoGraph> latest;
    Videos(Vulkan::Device& d,ID3D11Device* a,std::vector<uint32_t> s,unsigned w,unsigned h):device(d),decoder(a),shader(std::move(s)),width(w),height(h){}
    std::shared_ptr<life::VideoBackend> create(std::shared_ptr<n::Context> clock,uint64_t generation)override{
        auto bridge=std::make_shared<gpu::SameOwnerMovieBridge>(device,decoder,generation,width,height,shader);
        auto graph=std::make_shared<gpu::NativeVideoGraph>(clock,generation,bridge,record);latest=graph;++created;return graph;
    }
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
    auto view=std::make_shared<View>(source);auto videos=std::make_shared<Videos>(device,decoder.Get(),shader,picture.width,picture.height);
    Vulkan::BufferCreateInfo info;info.domain=Vulkan::BufferDomain::CachedHost;info.size=uint64_t(picture.width)*picture.height*4;info.usage=VK_BUFFER_USAGE_TRANSFER_DST_BIT;auto readback=device.create_buffer(info);check(bool(readback),"Actual movie graph readback");
    videos->record=[readback,&picture](Vulkan::CommandBuffer& cmd,const Vulkan::ImageView& view,const gpu::MoviePictureIdentity&){
        const auto& image=view.get_image();cmd.image_barrier(image,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT|VK_ACCESS_2_MEMORY_WRITE_BIT,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT);
        VkImageSubresourceLayers sub{VK_IMAGE_ASPECT_COLOR_BIT,0,0,1};cmd.copy_image_to_buffer(*readback,image,0,{0,0,0},{picture.width,picture.height,1},0,0,sub);
        cmd.buffer_barrier(*readback,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_WRITE_BIT,VK_PIPELINE_STAGE_2_HOST_BIT,VK_ACCESS_2_HOST_READ_BIT);
        cmd.image_barrier(image,VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,VK_PIPELINE_STAGE_2_TRANSFER_BIT,VK_ACCESS_2_TRANSFER_READ_BIT,VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT,VK_ACCESS_2_MEMORY_READ_BIT);
    };
    life::GraphConfig config;config.video=videos;config.clock.audio=std::make_shared<Audio>();config.clock.helper=std::make_shared<Helper>();config.clock.ports=std::make_shared<Ports>();config.clock.facts.selector=1;
    auto owner=life::Session::create(std::make_shared<life::PreparedFactory>(config));auto run=owner->open({view,0,view->size()});check(run.status==life::Status::completed,"Construct actual source/timing/parser/GPU graph");
    auto movie=videos->latest.lock();n::Updates observed;observed.actual=4;observed.requested=4;check(movie->clock()->observe(observed)==n::Status::completed,"Explicit prepared scheduler observation");
    auto get=[&](life::Key key,std::shared_ptr<gpu::NativeVideoGraph> graph){n::FrameResult result;until([&]{const auto status=owner->service(key);if(status!=life::Status::completed && status!=life::Status::pending)throw std::runtime_error(std::string("Actual movie graph service: ")+graph->error());result=graph->frames()->acquire();return result.status==n::FrameStatus::completed;},"First native source-demux-decode frame");return result;};
    auto first=get(run.key,movie);check(videos->created==1,"One actual graph before rebuild");
    auto semaphore=device.request_semaphore(VK_SEMAPHORE_TYPE_TIMELINE);Gate gate{device,semaphore};auto wait=device.request_timeline_semaphore_as_binary(*semaphore,1);wait->signal_external();device.add_wait_semaphore(Vulkan::CommandBuffer::Type::Generic,std::move(wait),VK_PIPELINE_STAGE_2_TRANSFER_BIT,true);
    check(movie->frames()->present(first.key)==n::FrameStatus::completed && movie->frames()->release(first.key)==n::FrameStatus::completed,"Real reader submitted before lifecycle rebuild");
    auto old_clock=movie->clock();auto old_frames=movie->frames();movie.reset();
    check(owner->rebuild(run.key)==life::Status::pending && owner->poll().status==life::Status::pending && videos->created==1,"Unsignaled real renderer fence blocks replacement graph");
    check(owner->service(run.key)==life::Status::closed && !old_clock->snapshot().detached,"Old graph rejects work while timing/resources remain retained");
    gate.signal();life::Open second;until([&]{second=owner->poll();check(second.status==life::Status::completed || second.status==life::Status::pending,"Real retirement status");return second.status==life::Status::completed;},"Actual GPU graph rebuild");
    check(videos->created==2 && old_clock->snapshot().detached && old_frames->snapshot().closed && owner->service(run.key)==life::Status::invalid_key,"Replacement waits for old resources and gets a new incarnation");
    auto replacement=videos->latest.lock();check(replacement && replacement->clock()->observe(observed)==n::Status::completed,"Fresh native clock after rebuild");
    auto next=get(second.key,replacement);check(replacement->frames()->present(next.key)==n::FrameStatus::completed && replacement->frames()->release(next.key)==n::FrameStatus::completed,"Decoded source frame after rebuild");
    until([&]{return replacement->frames()->poll()==n::FrameStatus::completed;},"First rebuilt reader fence");
    device.wait_idle();auto mapped=static_cast<const uint8_t*>(device.map_host_buffer(*readback,Vulkan::MEMORY_ACCESS_READ_BIT));check(mapped!=nullptr,"Post-rebuild pixel readback");std::vector<uint8_t> pixels(mapped,mapped+info.size);device.unmap_host_buffer(*readback,Vulkan::MEMORY_ACCESS_READ_BIT);const auto hash=reo_gpu_movie_asset::sha256(pixels);check(hash=="4eb588549f774d0691a29edd11c5a2865636f6a591245c4ed5dd21f9f8edeaa6","Rebuilt movie decoded same owned first frame");
    n::Updates unpaced;unpaced.selector=0;check(replacement->clock()->observe(unpaced)==n::Status::completed,"Explicit unpaced offline full-stream validation");
    uint64_t presented=1;int32_t last=0;
    until([&]{
        const auto status=owner->service(second.key);if(status!=life::Status::completed && status!=life::Status::pending)throw std::runtime_error(std::string("Whole-stream service: ")+replacement->error());
        auto frame=replacement->frames()->acquire();
        if(frame.status==n::FrameStatus::completed){
            const auto snapshot=replacement->frames()->snapshot();const auto time=snapshot.pictures[static_cast<unsigned>(snapshot.current)].time;
            const auto current=std::bit_cast<int32_t>(time.numerator);check(current>=last,"Presentation timestamps remain ordered across I/P/B pictures and GOPs");last=current;
            check(replacement->frames()->present(frame.key)==n::FrameStatus::completed && replacement->frames()->release(frame.key)==n::FrameStatus::completed,"Whole-stream real GPU reader");++presented;
        }else check(frame.status==n::FrameStatus::empty || frame.status==n::FrameStatus::held,"Whole-stream output state");
        return replacement->drained();
    },"Whole native video stream drain");
    const auto decoded=replacement->decodedPictures();check(decoded==presented && decoded>1,"Every decoded movie picture reached a real renderer reader");
    replacement.reset();until([&]{const auto status=owner->close();check(status==life::Status::completed || status==life::Status::pending,"Final movie close status");return status==life::Status::completed;},"Final real GPU graph retirement");
    std::cout<<"{\"status\":\"real GPU media pipeline checks passed\",\"graphs\":"<<videos->created<<",\"pixel_sha256\":\""<<hash<<"\",\"decoded\":"<<decoded<<",\"presented\":"<<presented<<",\"whole_video_stream\":true,\"renderer_fence_blocked_rebuild\":true,\"game_run\":false,\"audio_device_opened\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<"GPU media pipeline check failed: "<<error.what()<<'\n';return 1;}}
