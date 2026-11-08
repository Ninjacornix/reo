// Offline source-profile replay. Does not replay original timing or mix order.
#include "recomp/overrides/native_adxt/source_profile.h"
#include "game/native/adxt_instances/instances.hpp"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <thread>

namespace n=reo::native::adxt_instances;
namespace b=reo::native::adxt_binding;
namespace m=reo::native::resources::win32;
void require(bool value,const char* message){if(!value)throw std::runtime_error(message);}
bool accepted(n::Status s){return s==n::Status::completed || s==n::Status::pending;}
int main(int argc,char** argv)try{
    require(argc==4,"data, plan and result paths required");
    auto mounted=m::MountedResources::open_file1_windows(std::filesystem::path(argv[1]));
    require(mounted.status==m::MountStatus::ok,"actual immutable mount failed");
    std::ifstream plan(argv[2]);std::ofstream report(argv[3]);require(bool(plan)&&bool(report),"plan/result open failed");
    n::Instances players(n::control::Config{{3},{}});require(players.start_output()==n::Status::completed,"external submix start failed");
    std::array<n::Key,3> keys;
    for(unsigned i=0;i<3;++i){const auto opened=players.create({i==2?1u:2u,{i,i,i,i*2}});require(opened.status==n::Status::completed,"stable instance creation failed");keys[i]=opened.key;}
    // Only ONE source plays at a time. This order is a fixture choice and is
    // deliberately not claimed to reproduce original unordered-map summation.
    require(players.set_order(keys)==n::Status::completed,"fixture order rejected");
    unsigned line,slot,start,count,channels,rate,total,loop,divisor;std::string member,path;unsigned done{};
    while(plan>>line>>slot>>path>>start>>count>>channels>>rate>>total>>loop>>divisor>>member){
        require(slot<keys.size(),"invalid captured handle slot");
        report<<"{\"line\":"<<line<<",\"member\":\""<<member<<"\",\"loop_enabled\":"<<loop;
        try{
            const auto prepared=b::prepare_file_source(mounted.mount,{path,0,start,count});
            require(prepared.status==b::FileStatus::ready,"captured source preparation failed");
            require(players.set_service_divisor(keys[slot],static_cast<std::int32_t>(divisor))==n::Status::completed,"captured divisor rejected");
            require(players.set_loop_enabled(keys[slot],loop!=0)==n::Status::completed,"captured loop rejected");
            n::Source source;source.input=prepared.view;source.player.decoder.channels=channels;
            source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(prepared.bytes);
            require(accepted(players.start(keys[slot],std::move(source))),"captured start rejected");
            const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(90);
            std::optional<n::control::player::Snapshot> final;
            std::array<float,1024> output{};std::uint32_t tick{};
            while(std::chrono::steady_clock::now()<deadline){
                require(accepted(players.service(++tick)),"native group service failed");
                auto state=players.inspect(keys[slot]);require(state.status==n::Status::completed && state.source && !state.source->fault,"native source fault");
                const auto& s=*state.source;
                if(s.configured)require(s.decoder.header.base.frequency==rate && s.decoder.header.base.total_samples==total,"captured header differs from inventory");
                if((!loop && s.playback.phase==reo::native::adxt_playback::Phase::ended) || (loop && s.decoder.loop.iterations>=2)) {final=state.source;break;}
                if(s.output.voice.playing && s.output.channel[0].samples>=512){output.fill(0);require(players.submix()->render_add(output.data(),512)==n::control::output::Status::completed,"native output drain failed");}
                if(s.decoder.source.in_flight)std::this_thread::yield();
            }
            require(final && final->configured,"captured source did not reach bounded terminal observation");
            require(final->first_payload_samples==total,"first payload sample count differs");
            require(!final->output.voice.skipped_samples,"unexpected native skipped samples");
            if(!loop){const auto ratio=players.ratio(keys[slot],reo::native::adxt_integer_clock::Query::decoded_minus_queued);require(ratio.status==n::control::Status::completed && ratio.value.ratio.numerator==total && ratio.value.ratio.denominator==rate,"finite terminal clock differs");}
            require(accepted(players.stop(keys[slot])),"source stop failed");
            bool joined{};
            while(std::chrono::steady_clock::now()<deadline){require(accepted(players.service(++tick)),"source join service failed");const auto stopped=players.inspect(keys[slot]);if(stopped.phase==n::Phase::idle){joined=stopped.source && stopped.source->decoder.source.joined && stopped.source->output_retired;break;}std::this_thread::yield();}
            require(joined,"source join/output fence incomplete");
            report<<",\"samples\":"<<final->first_payload_samples<<",\"byte_digest\":["<<final->first_payload_digest[0]<<','<<final->first_payload_digest[1]<<"],\"request_samples\":"<<final->playback.request_samples<<",\"loop_iterations\":"<<final->decoder.loop.iterations<<",\"joined\":true,\"status\":\"passed\"}\n";report.flush();
        }catch(const std::exception& e){report<<",\"status\":\"failed\",\"error\":\""<<e.what()<<"\"}\n";report.flush();throw;}
        ++done;std::cout<<done<<" captured sources completed\n"<<std::flush;
    }
    require(plan.eof(),"malformed captured plan");
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);bool joined{};
    while(std::chrono::steady_clock::now()<deadline){const auto status=players.join();require(accepted(status),"canonical session join failed");if(status==n::Status::completed){joined=true;break;}std::this_thread::yield();}
    require(joined && done,"canonical session did not join or empty replay");
    require(players.snapshot().session.output.statistics.underrun_frames==0,"unexpected native fixture underrun");
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
