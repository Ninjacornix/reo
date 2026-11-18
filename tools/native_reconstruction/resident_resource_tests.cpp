#include "game/native/resources/bounded_view.hpp"
#include "game/native/audio_clip_loader/loader.hpp"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
namespace r=reo::native::resources;
namespace l=reo::native::audio_clip_loader;
namespace f=reo::native::adxt_shared_player::testing;
namespace reo::native::resources {
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView>,std::string);
bool is_resident_view(const std::shared_ptr<const ByteView>&)noexcept;
}
using namespace std::chrono_literals;
std::atomic<unsigned> checks{};
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"FAILED resident resource: %s\n",why);std::exit(1);}}
struct View:r::ByteView {
    std::vector<std::byte> bytes;
    mutable std::atomic<unsigned> sizes{},reads{};
    mutable std::atomic<std::size_t> last_read{};
    explicit View(std::size_t count):bytes(count){for(std::size_t i=0;i<count;++i)bytes[i]=std::byte(i*19u+7u);}
    std::uint64_t size()const noexcept override{++sizes;return bytes.size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        ++reads;last_read=out.size();if(at>bytes.size()||out.size()>bytes.size()-at)return{r::Status::invalid_range,0};
        std::copy_n(bytes.begin()+static_cast<std::size_t>(at),out.size(),out.begin());return{r::Status::ok,out.size()};
    }
};
struct Sized:r::ByteView {
    std::uint64_t count;mutable std::atomic<unsigned> reads{};
    explicit Sized(std::uint64_t n):count(n){}
    std::uint64_t size()const noexcept override{return count;}
    r::ReadResult read(std::uint64_t,std::span<std::byte>)const override{++reads;throw std::runtime_error("Lazy budget test must not read");}
};
void lazy_and_slices(){
    auto file=std::make_shared<View>(8192);const auto before=file->sizes.load();
    check(!r::is_resident_view(file)&&file->sizes==before&&!file->reads,"probe never invokes arbitrary source methods");
    auto view=r::retain_resident_view(file,"route-hash:asset@0:8192");check(!file->reads&&!r::is_resident_view(view),"construction lazy and unready");
    auto same=r::retain_resident_view(file,"route-hash:asset@0:8192");check(same==view,"canonical identity and size deduplicate");
    check(r::retain_resident_view(view,"already-wrapped")==view,"known lazy resident wrapper does not charge twice");
    auto slice=r::bounded_view(view,7,2048).view;auto nested=r::bounded_view(slice,11,512).view;
    check(!r::is_resident_view(slice)&&!r::is_resident_view(nested),"slice cannot claim parent ready before full copy");
    check(r::retain_resident_view(nested,"slice-identity")==nested,"existing resident slice extent preserved");
    std::array<std::byte,512> out{};check(nested->read(513,out).status==r::Status::invalid_range&&!file->reads,"invalid range never materializes");
    check(nested->read(0,out)==r::ReadResult{r::Status::ok,512},"slice reads its admitted offset");
    check(file->reads==1&&file->last_read==8192,"first read snapshots full original body");
    check(std::equal(out.begin(),out.end(),file->bytes.begin()+18),"nested slicing retains exact byte offsets");
    check(r::is_resident_view(view)&&r::is_resident_view(slice)&&r::is_resident_view(nested),"known slices inherit completed residency");
    const auto copy=file->bytes;std::weak_ptr<View> weak=file;file.reset();check(weak.expired(),"resident bytes release original provider");
    std::vector<std::byte> full(8192);check(view->read(0,full)==r::ReadResult{r::Status::ok,8192}&&full==copy,"resident contents outlive original provider");
    auto other_size=r::retain_resident_view(std::make_shared<View>(4096),"route-hash:asset@0:8192");check(other_size!=view,"size participates in cache identity");
}
void failed_body(){
    struct Failed final:r::ByteView {
        mutable std::atomic<unsigned> reads{};bool allocation{};
        std::uint64_t size()const noexcept override{return 2048;}
        r::ReadResult read(std::uint64_t,std::span<std::byte> out)const override{++reads;std::fill(out.begin(),out.end(),std::byte{0x55});if(allocation)throw std::bad_alloc();return{r::Status::source_failure,17};}
    };
    for(bool allocation:{false,true}){
        auto provider=std::make_shared<Failed>();provider->allocation=allocation;auto view=r::retain_resident_view(provider,allocation?"failure-oom":"failure-partial");
        for(unsigned i=0;i<2;++i){std::array<std::byte,32> output;output.fill(std::byte{0x33});bool badalloc{};r::ReadResult result;
            try{result=view->read(0,output);}catch(const std::bad_alloc&){badalloc=true;}
            check(allocation?badalloc:result.status==r::Status::source_failure,"preparation failure preserved");
            check(std::all_of(output.begin(),output.end(),[](auto b){return b==std::byte{0x33};}),"failed full copy never exposes partial body");
            check(!r::is_resident_view(view)&&provider->reads==1,"failed view stays unready without raw-source fallback or retry");
        }
    }
}
void concurrent_identity(){
    auto provider=std::make_shared<View>(32768);std::array<std::shared_ptr<const r::ByteView>,16> views;std::array<std::thread,16> threads;
    for(unsigned i=0;i<threads.size();++i)threads[i]=std::thread([&,i]{views[i]=r::retain_resident_view(provider,"concurrent-native-asset");});
    for(auto& thread:threads){thread.join();}
    check(std::all_of(views.begin(),views.end(),[&](const auto& p){return p==views[0];}),"concurrent constructors retain one resident object");
    for(unsigned i=0;i<threads.size();++i)threads[i]=std::thread([&,i]{std::array<std::byte,64> data{};check(views[i]->read(i,data)==r::ReadResult{r::Status::ok,64},"concurrent full-body materialization");});
    for(auto& thread:threads){thread.join();}check(provider->reads==1,"concurrent readers execute exactly one provider copy");
}
void budget_and_lifetime(){
    constexpr std::uint64_t limit=32ull*1024*1024;
    bool rejected{};try{(void)r::retain_resident_view(std::make_shared<Sized>(limit+1),"too-large");}catch(const std::length_error&){rejected=true;}
    check(rejected,"per-view32MiB admission enforced before reading");
    auto provider=std::make_shared<Sized>(limit);std::vector<std::shared_ptr<const r::ByteView>> views;
    for(unsigned i=0;i<64;++i)views.push_back(r::retain_resident_view(provider,"budget:"+std::to_string(i)));
    check(!provider->reads,"2GiB live budget test reserves lazy views without allocating bodies");
    check(r::retain_resident_view(provider,"budget:0")==views[0],"dedup at full budget needs no additional reservation");
    auto overflow=[&]{bool denied{};try{(void)r::retain_resident_view(provider,"overflow");}catch(const std::length_error&){denied=true;}return denied;};
    check(overflow(),"live2GiB admission refuses additional reserved body");
    auto slice=r::bounded_view(views[0],0,2048).view;views[0].reset();check(overflow(),"retained slice keeps whole parent reservation live");
    slice.reset();auto replacement=r::retain_resident_view(provider,"overflow");check(bool(replacement),"actual final-parent destruction returns budget");
    replacement.reset();views.clear();
    auto fresh=r::retain_resident_view(std::make_shared<View>(2048),"budget:0");std::array<std::byte,8> bytes{};
    check(fresh->read(0,bytes)==r::ReadResult{r::Status::ok,8},"expired weak entry permits a fresh different-size object");
}
void provider_destructor_reentry(){
    struct Reentrant final:View {
        std::atomic<bool>& done;
        explicit Reentrant(std::atomic<bool>& flag):View(2048),done(flag){}
        ~Reentrant()override{auto other=r::retain_resident_view(std::make_shared<View>(16),"provider-destructor-reentry");done=bool(other);}
    };
    std::atomic<bool> destroyed{};auto view=r::retain_resident_view(std::make_shared<Reentrant>(destroyed),"reentrant-parent");
    auto work=std::async(std::launch::async,[view]{std::array<std::byte,8> bytes{};return view->read(0,bytes);});
    check(work.wait_for(3s)==std::future_status::ready&&work.get()==r::ReadResult{r::Status::ok,8}&&destroyed,"provider destructor reenters cache outside registry/load locks");
}
std::shared_ptr<f::File> adx(){auto file=f::file(2,48000,20000);const auto end=96+(20000+31)/32*18*2;file->bytes.resize((end+18+2047)/2048*2048);f::be16(file->bytes,end,0x8001);f::be16(file->bytes,end+2,14);return file;}
void loader_full_body_gate(){
    struct Gate final:f::File {
        mutable std::mutex mutex;mutable std::condition_variable cv;mutable bool entered{},released{};std::atomic<bool> refuse{};
        r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
            {std::unique_lock lock(mutex);entered=true;cv.notify_all();check(cv.wait_for(lock,5s,[&]{return released;}),"gated body release deadline");}
            check(!refuse,"no provider read after resident readiness");return File::read(at,out);
        }
    };
    auto file=std::make_shared<Gate>();file->bytes=adx()->bytes;auto original=file->bytes;
    auto wrapped=r::retain_resident_view(file,"validated-cue-body@0:full");l::Loader loader,other;
    auto first=loader.prepare(wrapped);check(first.status==l::Status::accepted,"lazy resident clip submitted");
    {std::unique_lock lock(file->mutex);check(file->cv.wait_for(lock,3s,[&]{return file->entered;}),"preparation body read starts on worker");}
    check(loader.poll(first.key).status==l::Status::pending&&!r::is_resident_view(wrapped),"no clip ready before all body bytes arrive");
    auto second=other.prepare(wrapped);check(second.status==l::Status::accepted,"second loader shares canonical pending asset");
    auto unrelated=std::async(std::launch::async,[]{return r::retain_resident_view(std::make_shared<View>(2048),"unrelated-during-io");});
    check(unrelated.wait_for(1s)==std::future_status::ready&&unrelated.get(),"body I/O never holds registry lock");
    {std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}
    auto wait=[](l::Loader& owner,const l::Key& key){const auto end=std::chrono::steady_clock::now()+3s;for(;;){auto value=owner.poll(key);if(value.status!=l::Status::pending)return value;check(std::chrono::steady_clock::now()<end,"loader readiness bound");std::this_thread::yield();}};
    auto a=wait(loader,first.key),b=wait(other,second.key);check(a.status==l::Status::ready&&b.status==l::Status::ready,"both complete only after body copy");
    check(a.clip->metadata().view==wrapped&&b.clip->metadata().view==wrapped&&file->reads==1,"cue identity shares one full immutable body across loaders");
    file->refuse=true;std::vector<std::byte> copy(original.size());check(wrapped->read(0,copy)==r::ReadResult{r::Status::ok,copy.size()},"later body read is memory-only");
    check(std::equal(copy.begin(),copy.end(),original.begin(),[](std::byte a,std::uint8_t b){return std::to_integer<std::uint8_t>(a)==b;}),"all resident bytes preserved");
    check(loader.join()&&other.join(),"loader workers join");std::weak_ptr<Gate> weak=file;file.reset();check(weak.expired(),"prepared clips release original providers after body copy");
}
int main(){lazy_and_slices();failed_body();concurrent_identity();budget_and_lifetime();provider_destructor_reentry();loader_full_body_gate();std::printf("{\"checks\":%u,\"device_opened\":false,\"game_launched\":false}\n",checks.load());}
