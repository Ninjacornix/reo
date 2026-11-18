#include "loader.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>

namespace reo::native::resources {
bool is_resident_view(const std::shared_ptr<const ByteView>&)noexcept;
}

namespace loader=reo::native::audio_clip_loader;
namespace fixtures=reo::native::adxt_shared_player::testing;
using Status=loader::Status;
unsigned checks{};
void check(bool value) { ++checks; if (!value) throw std::runtime_error("Clip loader check "+std::to_string(checks)); }
std::shared_ptr<fixtures::File> clip(unsigned channels=2,unsigned rate=48000,unsigned samples=20000) {
    auto file=fixtures::file(channels,rate,samples);
    const auto end=96+(samples+31)/32*18*channels;
    file->bytes.resize((end+18+2047)/2048*2048);
    fixtures::be16(file->bytes,end,0x8001);fixtures::be16(file->bytes,end+2,14);
    return file;
}
loader::Result wait(loader::Loader& owner,const loader::Key& key) {
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
    for (;;) {
        auto result=owner.poll(key);
        if (result.status!=Status::pending) return result;
        if (std::chrono::steady_clock::now()>=deadline) throw std::runtime_error("Clip preparation deadline");
        std::this_thread::yield();
    }
}
struct Gate final:fixtures::File {
    mutable std::mutex mutex;
    mutable std::condition_variable cv;
    mutable bool entered{},released{};
    mutable std::thread::id reading_thread;
    reo::native::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out) const override {
        {std::unique_lock lock(mutex);reading_thread=std::this_thread::get_id();entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}
        return File::read(at,out);
    }
    void await() const { std::unique_lock lock(mutex);check(cv.wait_for(lock,std::chrono::seconds(5),[&]{return entered;})); }
    void release() { std::lock_guard lock(mutex);released=true;cv.notify_all(); }
};
struct Release { std::shared_ptr<Gate> file; ~Release(){file->release();} };
int main() try {
    for (unsigned channels:{1u,2u}) for (unsigned rate:{24000u,44100u,48000u}) for (unsigned samples:{33u,20000u}) {
        loader::Loader owner;
        auto file=clip(channels,rate,samples);const auto request=owner.prepare(file);
        check(request.status==Status::accepted);
        auto result=wait(owner,request.key);check(result.status==Status::ready && result.detail==reo::native::adx_sequence::Status::completed && result.clip);
        check(result.clip->metadata().header.base.total_samples==samples && result.clip->metadata().header.active_channels==static_cast<int>(channels));
        check(result.clip->metadata().header.base.frequency==rate &&
              reo::native::resources::is_resident_view(result.clip->metadata().view));
        const auto original=file->bytes;
        std::vector<std::byte> copied(original.size());
        check(result.clip->metadata().view->read(0,copied)==reo::native::resources::ReadResult{reo::native::resources::Status::ok,copied.size()});
        check(std::equal(copied.begin(),copied.end(),original.begin(),[](std::byte a,std::uint8_t b){return std::to_integer<std::uint8_t>(a)==b;}));
        check(file->reads==1); // Full immutable body, not header/tail-only reads.
        check(owner.release(request.key)==Status::completed && owner.poll(request.key).status==Status::invalid_key);
        check(result.clip->metadata().header.base.total_samples==samples); // Borrow survives ticket release.
        check(owner.join() && owner.join());
        std::weak_ptr<const reo::native::resources::ByteView> prior=file;file.reset();
        check(prior.expired());
        check(result.clip->metadata().view->read(0,copied)==reo::native::resources::ReadResult{reo::native::resources::Status::ok,copied.size()});
        check(std::equal(copied.begin(),copied.end(),original.begin(),[](std::byte a,std::uint8_t b){return std::to_integer<std::uint8_t>(a)==b;}));
        const auto done=owner.snapshot();
        check(done.joined && done.closing && !done.records && !done.worker_failures && done.accepted==1 && done.finished==1 && done.preparations==1 && done.published==1 && !done.discarded);
    }
    {
        loader::Loader owner({1,1}),foreign;
        auto file=std::make_shared<Gate>();file->bytes=clip(2,48000,33)->bytes;Release release{file};
        const auto first=owner.prepare(file);check(first.status==Status::accepted);file->await();
        {std::lock_guard lock(file->mutex);check(file->reading_thread!=std::this_thread::get_id());}
        check(owner.poll(first.key).status==Status::pending && !owner.poll(first.key).clip);
        check(owner.prepare(clip()).status==Status::capacity);
        check(foreign.poll(first.key).status==Status::invalid_key && foreign.release(first.key)==Status::invalid_key);
        check(owner.release(first.key)==Status::completed);
        auto next=std::make_shared<Gate>();next->bytes=clip(1,24000,64)->bytes;Release release_next{next};
        const auto second=owner.prepare(next);check(second.status==Status::accepted);
        check(owner.poll(first.key).status==Status::invalid_key && owner.poll(second.key).status==Status::pending);
        file->release();next->await();check(owner.poll(second.key).status==Status::pending);
        next->release();auto result=wait(owner,second.key);
        check(result.status==Status::ready && result.clip->metadata().header.base.total_samples==64 && result.clip->metadata().header.active_channels==1);
        check(owner.poll(first.key).status==Status::invalid_key);
        check(owner.join());const auto done=owner.snapshot();
        check(done.accepted==2 && done.finished==2 && done.preparations==2 && done.published==1 && done.discarded==1);
        check(owner.prepare(clip()).status==Status::closed && owner.poll(second.key).status==Status::closed && owner.poll({}).status==Status::invalid_key);
    }
    {
        loader::Loader owner({2,1});auto file=std::make_shared<Gate>();file->bytes=clip()->bytes;Release release{file};
        const auto first=owner.prepare(file);check(first.status==Status::accepted);file->await();
        auto canceled=clip();const auto second=owner.prepare(canceled);check(second.status==Status::accepted);
        check(owner.release(second.key)==Status::completed);
        auto rejected=clip();check(owner.prepare(rejected).status==Status::queue_full && !rejected->reads);
        check(owner.snapshot().records==1 && owner.poll(second.key).status==Status::invalid_key);
        owner.request_stop();owner.request_stop();check(owner.poll(first.key).status==Status::closed && !owner.snapshot().joined);
        file->release();check(owner.join());const auto done=owner.snapshot();
        check(!canceled->reads && !rejected->reads && done.joined && !done.records && done.accepted==2 && done.finished==1 && done.discarded==1 && !done.published);
    }
    {
        loader::Loader owner({1,1});
        auto bad=clip();bad->bytes[0]=0;
        const auto request=owner.prepare(bad);check(request.status==Status::accepted);
        const auto result=wait(owner,request.key);check(result.status==Status::failed && result.detail==reo::native::adx_sequence::Status::unsupported_header && !result.clip);
        check(owner.release(request.key)==Status::completed);
        const auto good=owner.prepare(clip());check(good.status==Status::accepted && wait(owner,good.key).status==Status::ready);
        check(owner.join());
    }
    for (bool allocation:{false,true}) {
        struct Failed final:fixtures::File {
            bool allocation{};
            reo::native::resources::ReadResult read(std::uint64_t,std::span<std::byte>) const override {
                if (allocation) throw std::bad_alloc();
                throw std::runtime_error("Injected source error");
            }
        };
        loader::Loader owner;auto bad=std::make_shared<Failed>();bad->bytes=clip()->bytes;bad->allocation=allocation;
        const auto request=owner.prepare(bad);check(request.status==Status::accepted);
        const auto result=wait(owner,request.key);check(result.status==Status::failed && result.detail==(allocation?reo::native::adx_sequence::Status::no_memory:reo::native::adx_sequence::Status::source_failure) && !result.clip);
        check(owner.join());
    }
    {
        loader::Loader owner;
        check(owner.prepare({}).status==Status::invalid_input);
        check(owner.prepare(std::make_shared<fixtures::File>()).status==Status::invalid_input);
        auto unaligned=clip();unaligned->bytes.push_back(0);check(owner.prepare(unaligned).status==Status::invalid_input && !unaligned->reads);
        check(owner.poll({}).status==Status::invalid_key && owner.release({})==Status::invalid_key);
        check(!owner.snapshot().accepted && !owner.snapshot().records && owner.join());
    }
    {
        auto owner=std::make_unique<loader::Loader>();auto file=std::make_shared<Gate>();file->bytes=clip()->bytes;Release release{file};
        struct Probe final:reo::native::resources::ByteView {
            std::shared_ptr<Gate> file;
            explicit Probe(std::shared_ptr<Gate> value):file(std::move(value)){}
            std::uint64_t size()const noexcept override{return file->size();}
            reo::native::resources::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{return file->read(at,out);}
        };
        auto probe=std::make_shared<Probe>(file);std::weak_ptr<Probe> retained=probe;
        const auto request=owner->prepare(probe);probe.reset();check(request.status==Status::accepted);file->await();
        owner->request_stop();
        std::promise<bool> joined;auto future=joined.get_future();
        std::thread joining([&]{joined.set_value(owner->join());});
        check(future.wait_for(std::chrono::milliseconds(25))==std::future_status::timeout && !retained.expired());
        file->release();joining.join();check(future.get() && owner->snapshot().joined && retained.expired());
    }
    {
        loader::Loader owner;std::atomic<bool> destroyed{};
        struct Reentrant final:fixtures::File {
            loader::Loader* owner{};std::atomic<bool>* destroyed{};
            ~Reentrant(){(void)owner->snapshot();destroyed->store(true,std::memory_order_release);}
        };
        auto file=std::make_shared<Reentrant>();file->bytes=clip()->bytes;file->owner=&owner;file->destroyed=&destroyed;
        const auto request=owner.prepare(file);file.reset();check(request.status==Status::accepted && wait(owner,request.key).status==Status::ready);
        check(owner.release(request.key)==Status::completed);
        const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(5);
        while(!destroyed.load(std::memory_order_acquire) && std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
        check(destroyed.load(std::memory_order_acquire) && owner.join());
    }
    for (const auto config:{loader::Config{0,1},loader::Config{65,1},loader::Config{1,0},loader::Config{1,65}}) {
        bool refused{};try{loader::Loader owner(config);}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    std::cout<<checks<<" native clip loader checks\n";
    return 0;
} catch (const std::exception& error) { std::cerr<<error.what()<<'\n';return 1; }
