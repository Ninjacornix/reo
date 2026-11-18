// Read-only owned-import admission audit. No game, audio device or guest RAM.
#include "game/native/audio_clip_loader/loader.hpp"
#include "recomp/overrides/native_adxt/source_profile.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

namespace loading=reo::native::audio_clip_loader;
namespace source=reo::native::adxt_binding;
int main(int argc,char** argv) try {
    if(argc!=3)throw std::runtime_error("owned imported-data and cue plan required");
    const auto opened=reo::native::resources::win32::MountedResources::open_file1_windows(argv[1]);
    if(opened.status!=reo::native::resources::win32::MountStatus::ok)throw std::runtime_error("Verified native File1 mount required");
    std::ifstream plan(argv[2]);if(!plan)throw std::runtime_error("Cue plan unavailable");
    loading::Loader loader({1,1});
    std::uint32_t index{},start{},count{};std::string container;std::uint64_t rows{};
    while(plan>>index>>container>>start>>count) {
        const auto prepared=source::prepare_file_source(opened.mount,{container,0,start,count});
        if(prepared.status!=source::FileStatus::ready) {
            std::cout<<"{\"index\":"<<index<<",\"status\":\"file_refused\",\"file_status\":"<<unsigned(prepared.status)<<"}\n";continue;
        }
        const auto ticket=loader.prepare(prepared.view);
        if(ticket.status!=loading::Status::accepted)throw std::runtime_error("Native clip preparation admission failed");
        const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);
        loading::Result result;
        do {
            result=loader.poll(ticket.key);
            if(result.status!=loading::Status::pending)break;
            if(std::chrono::steady_clock::now()>=deadline)throw std::runtime_error("Native clip preparation deadline");
            std::this_thread::yield();
        }while(true);
        if(result.status!=loading::Status::ready && result.status!=loading::Status::failed)throw std::runtime_error("Unexpected native preparation result");
        std::cout<<"{\"index\":"<<index<<",\"status\":\""<<(result.status==loading::Status::ready?"ready":"refused")<<"\",\"clip_status\":"<<unsigned(result.detail);
        if(result.clip) {
            const auto& h=result.clip->metadata().header;
            std::cout<<",\"channels\":"<<h.active_channels<<",\"frequency\":"<<h.base.frequency<<",\"samples\":"<<h.base.total_samples;
        }
        std::cout<<"}\n";++rows;
        if(loader.release(ticket.key)!=loading::Status::completed)throw std::runtime_error("Preparation ticket release failed");
    }
    if(!plan.eof())throw std::runtime_error("Invalid cue plan");
    if(!loader.join())throw std::runtime_error("Preparation worker did not join");
    const auto done=loader.snapshot();
    if(done.worker_failures || done.records || done.accepted!=rows || done.finished!=rows || done.published!=rows)throw std::runtime_error("Preparation accounting mismatch");
    std::cerr<<"Native cue admission audit joined: "<<rows<<" preparations\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
