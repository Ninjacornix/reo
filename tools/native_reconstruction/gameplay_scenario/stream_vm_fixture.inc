using StreamEvent=std::tuple<unsigned,unsigned,std::int32_t,std::int32_t,std::uint32_t,std::int32_t,std::int8_t,std::int32_t,std::uint32_t>;
std::vector<StreamEvent> original_stream_events;
struct StreamFixture;
StreamFixture* original_stream_fixture{};
struct StreamFixture final:vm::StreamBackend {
    vm::StreamChannels owner{vm::file1_stream_gain_curve()};std::array<std::int32_t,3> phases{};std::vector<StreamEvent> events;std::uint32_t tick{};
    explicit StreamFixture(unsigned profile=0,std::uint32_t game_tick=1234):tick(game_tick){vm::StreamChannelSnapshot state;
        for(unsigned i=0;i<3;++i){auto& c=state.channels[i];c.type=i==2?1:2;c.maximum=(profile&4)?63:127;c.current=(profile&8)?7:111;c.level=float(c.current);c.target=17;c.step=0.25f;state.requested_ids[i]=(profile&1)?69:42;c.paused=(profile&2)?std::int8_t(-1):0;phases[i]=std::int32_t(profile%6);}
        check(owner.restore(state)==vm::StreamStatus::completed);events.reserve(256);
    }
    void event(unsigned kind,unsigned index,std::int32_t a,std::int32_t b,std::uint32_t game_tick){const auto& s=owner.snapshot();events.emplace_back(kind,index,a,b,game_tick,s.requested_ids[index],s.channels[index].paused,s.channels[index].current,std::bit_cast<std::uint32_t>(s.channels[index].step));}
    vm::StreamValue phase(std::uint8_t c)noexcept override{event(0,c,0,0,tick);return{vm::StreamStatus::completed,phases[c]};}
    vm::StreamStatus start(std::uint8_t c,vm::StreamRequest r,std::uint32_t t)noexcept override{event(1,c,std::bit_cast<std::int32_t>(r.archive),r.member,t);return vm::StreamStatus::completed;}
    vm::StreamStatus stop(std::uint8_t c)noexcept override{event(2,c,0,0,tick);return vm::StreamStatus::completed;}
    vm::StreamStatus pause(std::uint8_t c,bool p,std::uint32_t t)noexcept override{event(3,c,p?1:0,0,t);return vm::StreamStatus::completed;}
    vm::StreamStatus attenuation(std::uint8_t c,std::int32_t a)noexcept override{event(4,c,a,0,tick);return vm::StreamStatus::completed;}
    vm::StreamStatus service(std::uint32_t)noexcept override{return vm::StreamStatus::completed;}
    void export_original(std::vector<std::uint8_t>& ram){const auto& s=owner.snapshot();
        for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& c=s.channels[i];ram[at]=std::uint8_t(c.paused);ram[at+1]=c.type;ram[at+2]=c.start_wait;ram[at+3]=c.started;
            fixture_write(ram.data(),at+4,c.current);fixture_write(ram.data(),at+8,c.maximum);fixture_write(ram.data(),at+12,std::bit_cast<std::uint32_t>(c.step));fixture_write(ram.data(),at+16,std::bit_cast<std::uint32_t>(c.level));fixture_write(ram.data(),at+20,c.target);
            fixture_write(ram.data(),0x4bae24+4*i,s.requested_ids[i]);fixture_write<std::uint32_t>(ram.data(),0x2b8dc8+4*i,0x610000+256*i);}
        fixture_write(ram.data(),0x20f3c4,tick);std::memcpy(ram.data()+0x234060,original_stream_curve.data(),512);original_stream_fixture=this;original_stream_events.clear();original_stream_events.reserve(256);
    }
    void compare_original(const std::vector<std::uint8_t>& ram){const auto& s=owner.snapshot();
        for(unsigned i=0;i<3;++i){const auto at=0x2b8d70+24*i;const auto& c=s.channels[i];check(ram[at]==std::uint8_t(c.paused));check(ram[at+1]==c.type);check(ram[at+2]==c.start_wait);check(ram[at+3]==c.started);
            check(fixture_read<std::int32_t>(ram.data(),at+4)==c.current);check(fixture_read<std::int32_t>(ram.data(),at+8)==c.maximum);check(fixture_read<std::uint32_t>(ram.data(),at+12)==std::bit_cast<std::uint32_t>(c.step));check(fixture_read<std::uint32_t>(ram.data(),at+16)==std::bit_cast<std::uint32_t>(c.level));check(fixture_read<std::int32_t>(ram.data(),at+20)==c.target);check(fixture_read<std::int32_t>(ram.data(),0x4bae24+4*i)==s.requested_ids[i]);}
        check(events==original_stream_events);
    }
};
std::uint8_t stream_original_channel(R5900Context* c){const auto handle=GPR_U32(c,4);check(handle>=0x610000&&handle<0x610300&&(handle-0x610000)%256==0);return std::uint8_t((handle-0x610000)/256);}
void stream_original_event(std::uint8_t* ram,unsigned kind,unsigned channel,std::int32_t a=0,std::int32_t b=0){const auto at=0x2b8d70+24*channel;
    original_stream_events.emplace_back(kind,channel,a,b,fixture_read<std::uint32_t>(ram,0x20f3c4),fixture_read<std::int32_t>(ram,0x4bae24+4*channel),std::bit_cast<std::int8_t>(ram[at]),fixture_read<std::int32_t>(ram,at+4),fixture_read<std::uint32_t>(ram,at+12));}
