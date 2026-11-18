  {
   namespace t=reo::native::transform_math;
   s::CameraProjectionContext projection{640,448,640,448,t::identity(),t::identity()};
   s::CameraDisplayState camera_state;camera_state.viewport={0,0,640,448,0,1};camera_state.view=t::identity();
   s::DisplayFadeState fade_state;std::uint8_t callback_initialized{};std::int8_t display_mode{};
   struct Sink final:s::CameraDisplaySink{
    Services& services;bool fail{};explicit Sink(Services& value):services(value){}
    void viewport(const s::CameraViewport&,const s::CameraProjectionMatrices&)override{check(services.emit(0x1af780,24)==s::CutscenePlaybackStatus::completed);++display_publications;if(fail)throw std::runtime_error("Explicit renderer publication refusal");}
    void view(const t::Matrix&)override{check(services.emit(0x1af780,22)==s::CutscenePlaybackStatus::completed);++display_publications;}
   }sink(services);
   const auto make=[&](s::CutscenePlaybackState& state){return std::make_unique<s::CutsceneDisplay>(state,session->clock_mode,display_mode,projection,camera_state,fade_state,callback_initialized,sink);};
   auto foreign_display=make(foreign);check(playback.bind_display(foreign_display)==s::CutscenePlaybackStatus::unavailable&&foreign_display);
   std::uint8_t foreign_clock{};auto wrong_clock=std::make_unique<s::CutsceneDisplay>(playback.state(),foreign_clock,display_mode,projection,camera_state,fade_state,callback_initialized,sink);
   check(playback.bind_display(wrong_clock)==s::CutscenePlaybackStatus::unavailable&&wrong_clock);
   auto native_display=make(playback.state());auto* display=native_display.get();
   check(playback.bind_display(native_display)==s::CutscenePlaybackStatus::completed&&!native_display&&playback.display()==display);
   services.display_attempt=make(playback.state());check(playback.bind_display(services.display_attempt)==s::CutscenePlaybackStatus::unavailable&&services.display_attempt);
   const auto same_matrix=[&](const t::Matrix& value,unsigned address){const auto expected=transform_read<t::Matrix>(memory.data(),address);for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row)check(std::bit_cast<unsigned>(value[column][row])==std::bit_cast<unsigned>(expected[column][row]));};
   const auto same_fade=[&]{check(fade_state.phase==memory[0x316650]&&fade_state.status==transform_read<unsigned>(memory.data(),0x316654)&&fade_state.color==transform_read<unsigned>(memory.data(),0x316658)&&fade_state.alpha==transform_read<float>(memory.data(),0x31665c)&&fade_state.step==transform_read<float>(memory.data(),0x316660));};
   for(unsigned clock=0;clock<32;++clock){
    case_id=90000+clock;auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.end_frame=1000;session->clock_mode=std::uint8_t(clock);display_mode=std::int8_t(clock%3==0?0:clock%3==1?1:-1);inputs={1,2,1,1,0,false,false,0};
    check(borrowed->install(prepared)==s::CutsceneCameraStatus::completed);borrowed->parameters()={{{0,0,500},{0,0,0},{0,1,0},0},50000,1,27};
    project(memory.data(),state,world,flags,channels);put(memory.data(),0x3901a8,0xc10000u);std::memcpy(memory.data()+0xc10000,selections.data(),selections.size());std::fill_n(memory.data()+0x3900a0,32*8,0);
    for(unsigned stream=0;stream<2;++stream){put(memory.data(),0x3900a0+stream*4,0xc11000u+stream*0x100u);std::memcpy(memory.data()+0xc11000+stream*0x100,curves[stream].data(),curves[stream].size());}
    put(memory.data(),0x38ec90,0u);put(memory.data(),0x38ec94,0u);put(memory.data(),0x3240bd,std::uint8_t(255));put(memory.data(),0x3243cf,display_mode);
    put(memory.data(),0x324120,camera_state.viewport);const auto& params=borrowed->parameters();put(memory.data(),0x324138,params.pose.eye);put(memory.data(),0x324144,params.pose.aim);put(memory.data(),0x32415c,params.pose.up);put(memory.data(),0x324178,params.far_plane);put(memory.data(),0x32417c,params.near_plane);put(memory.data(),0x324180,params.lens);put(memory.data(),0x32418c,params.pose.roll);
    put(memory.data(),0x2941a8,projection.horizontal_extent);put(memory.data(),0x2941b0,projection.vertical_extent);put(memory.data(),0x2941c8,projection.width);put(memory.data(),0x2941d0,projection.height);put(memory.data(),0x70003f80,projection.first_transform);put(memory.data(),0x294dc0,projection.second_transform);put(memory.data(),0x294e00,t::identity());
    native_events.clear();source_events.clear();compare_bound_camera=compare_bound_display=true;invoke(memory.data(),0x5ee680);check(playback.tick().status==s::CutscenePlaybackStatus::completed);compare(memory.data(),state,world,channels);same_matrix(camera_state.view,0x3240e0);same_matrix(camera_state.projection.scaled,0x294d00);same_matrix(camera_state.projection.first_composite,0x294d40);same_matrix(camera_state.projection.second_composite,0x294d80);++display_ticks;
    callback_initialized=0;put(memory.data(),0xc12008,std::uint8_t(0));
    {R5900Context original;PS2Runtime runtime;original.pc=0x1bb480;SET_GPR_U32(&original,4,0xc12000);SET_GPR_U32(&original,29,0x1f00000);SET_GPR_U32(&original,31,0xabcdef);original_transform_port(memory.data(),&original,&runtime);check(original.pc==0xabcdef);}
    display->advance_fade();check(callback_initialized==memory[0xc12008]);same_fade();
    session->cutscene_requests={};session->cutscene_requests.append({0,1,1,0,0,0,0,0});state={};state.phase=2;project(memory.data(),state,world,flags,channels);
    native_events.clear();source_events.clear();invoke(memory.data(),0x5ee680);check(playback.tick().status==s::CutscenePlaybackStatus::completed);compare(memory.data(),state,world,channels);same_fade();
    native_events.clear();source_events.clear();invoke(memory.data(),0x5ee680);check(playback.tick().status==s::CutscenePlaybackStatus::waiting);compare(memory.data(),state,world,channels);
    for(unsigned step=0;step<2;++step){R5900Context original;PS2Runtime runtime;original.pc=0x1bb480;SET_GPR_U32(&original,4,0xc12000);SET_GPR_U32(&original,29,0x1f00000);SET_GPR_U32(&original,31,0xabcdef);original_transform_port(memory.data(),&original,&runtime);display->advance_fade();same_fade();}
    check(display->fade_finished()&&invoke(memory.data(),0x1bb8d0)==1);compare_bound_camera=compare_bound_display=false;
   }
   check(display_ticks==32&&display_publications==64);sink.fail=true;auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.end_frame=1000;check(borrowed->install(prepared)==s::CutsceneCameraStatus::completed);
   check(playback.tick().status==s::CutscenePlaybackStatus::unavailable&&state.frame==0);++refusals;
   check(playback.unbind_display()==s::CutscenePlaybackStatus::completed&&!playback.display());check(playback.unbind_display()==s::CutscenePlaybackStatus::completed);
   services.display_attempt.reset();session->cutscene_requests={};
  }
