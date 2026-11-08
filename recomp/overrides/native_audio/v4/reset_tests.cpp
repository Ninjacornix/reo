// Parent aggregate scenarios use explicit retained facade/device ports. The
// verifier copies them verbatim except the distinct ABI namespace/main name.
#include "parent_submix_tests.cpp"
template<class F>struct EmptyWork final:control_owner::EmptyOperation {
    F fn;explicit EmptyWork(F f):fn(std::move(f)){}
    void run(const control_owner::Quiescent& proof)noexcept override{fn(proof);}
};
void native_quiescent(){
    control_owner::Owner own(streams::control::Config{{1},{}}),foreign(streams::control::Config{{1},{}});
    Setup s(own.submix());s.install();s.load();a::ensureHostOutput();
    std::array<std::uint32_t,8> order{};
    auto expect_order=[&](unsigned expected){const auto r=s.owner->copy_order(order);check(r.status==n::pcm::Status::ok && r.value==expected);};
    a::configure(2,1,0,1,48000,256,false);expect_order(1);
    EmptyWork wrong([&](const auto& proof){check(!s.owner->reset_native(&proof));});
    check(foreign.when_empty(wrong)==control_owner::Empty::completed && s.hooks->route_resets==0);expect_order(1);
    check(!s.owner->reset_native(nullptr) && s.hooks->route_resets==0);expect_order(1);
    EmptyWork reset([&](const auto& proof){check(s.owner->reset_native(&proof));});
    check(own.when_empty(reset)==control_owner::Empty::completed && s.hooks->route_resets==1);expect_order(0);
    streams::Key key;
    ControlOperation start([&](auto& players){check(players.start_output()==streams::Status::completed);const auto made=players.create({1,{0,0,0,0}});check(made.status==streams::Status::completed);key=made.key;check(players.start(key,source(1))==streams::Status::completed);});
    check(own.run(start)==control_owner::Admission::accepted);
    bool ready{};ControlOperation service([&](auto& players){check(players.service(17)==streams::Status::completed);const auto s=players.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{check(own.run(service)==control_owner::Admission::accepted);return ready;});
    std::array<float,128> output{};check(s.provider->emit(output.data(),64));
    a::configure(2,1,0,1,48000,256,false);expect_order(1);
    check(own.when_empty(reset)==control_owner::Empty::occupied && s.hooks->route_resets==1);expect_order(1);
    bool destroyed{};ControlOperation destroy([&](auto& players){const auto r=players.destroy(key);check(r==streams::Status::completed || r==streams::Status::pending);destroyed=r==streams::Status::completed;});
    until([&]{check(own.run(destroy)==control_owner::Admission::accepted);return destroyed;});
    // A mere old API reset remains refused after the source epoch, even now
    // that it is empty. Only the canonical scoped proof admits later reset.
    a::reset();check(s.hooks->route_resets==1);expect_order(1);
    const auto bank_frame=s.owner->inspect_banks().frame_clock;
    check(own.when_empty(reset)==control_owner::Empty::completed && s.hooks->route_resets==2);expect_order(0);
    check(s.owner->inspect_banks().ports[0].loaded && s.owner->inspect_banks().frame_clock==bank_frame && s.provider->detach_calls==0);
    // New construction and actual PCM remain usable after the later reset.
    ready=false;check(own.run(start)==control_owner::Admission::accepted);
    until([&]{check(own.run(service)==control_owner::Admission::accepted);return ready;});
    check(s.provider->emit(output.data(),64));destroyed=false;
    until([&]{check(own.run(destroy)==control_owner::Admission::accepted);return destroyed;});
    check(own.when_empty(reset)==control_owner::Empty::completed && s.hooks->route_resets==3);
    check(s.owner->report().hard_failures==3 && !s.owner->report().native_submix_failures);
    check(own.join()==control_owner::Join::completed && foreign.join()==control_owner::Join::completed);s.finish();no_legacy();
}
void reset_with_callback(){
    control_owner::Owner own(streams::control::Config{{1},{}});Setup s(own.submix());s.install();s.load();
    a::configure(2,1,0,1,48000,256,false);a::ensureHostOutput();
    ControlOperation start([&](auto& players){check(players.start_output()==streams::Status::completed);});check(own.run(start)==control_owner::Admission::accepted);
    s.probe->pause=true;std::array<float,128> output{};
    std::thread callback([&]{check(s.provider->emit(output.data(),64));});s.probe->entered.wait();
    // Callback is between its raw data lock and native submix. Reset acquires
    // only the raw lock while source admission is held, without device fencing.
    EmptyWork reset([&](const auto& proof){check(s.owner->reset_native(&proof));});
    const auto result=own.when_empty(reset);const bool preserved=s.provider->detach_calls==0 && s.owner->inspect_banks().ports[0].loaded;
    s.probe->resume.signal();callback.join();check(result==control_owner::Empty::completed && preserved && s.hooks->route_resets==1);
    check(s.owner->inspect_banks().frame_clock==64 && s.provider->emit(output.data(),64));
    check(!s.owner->report().hard_failures && !s.owner->report().native_submix_failures && callback_alloc==0 && callback_free==0);
    check(own.join()==control_owner::Join::completed);s.finish();no_legacy();
}
int main(int argc,char** argv)try{
    if(argc!=2)return 2;const std::string name=argv[1];
    if(name=="native_quiescent")native_quiescent();else if(name=="reset_callback")reset_with_callback();else return aggregate3_scenarios(argc,argv);
    std::cout<<"aggregate4 "<<name<<" assertions="<<assertions.load()<<'\n';return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
