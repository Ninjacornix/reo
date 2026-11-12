 {
  s::SceneModels models({},{});s::RoomViewMasks masks;s::FullscreenColorState color_state;s::FullscreenColor color(color_state);
  const auto make=[&](s::CutscenePlaybackState& state,const std::uint8_t& mode){return std::make_unique<s::CutsceneViewControls>(state,mode,models,masks,color);};
  s::CutscenePlaybackState foreign;auto wrong_state=make(foreign,session->clock_mode);
  check(playback.bind_view_controls(wrong_state)==s::CutscenePlaybackStatus::unavailable&&wrong_state);
  std::uint8_t foreign_mode{};auto wrong_mode=make(playback.state(),foreign_mode);
  check(playback.bind_view_controls(wrong_mode)==s::CutscenePlaybackStatus::unavailable&&wrong_mode);
  auto controls=make(playback.state(),session->clock_mode);auto* borrowed=controls.get();
  check(playback.bind_view_controls(controls)==s::CutscenePlaybackStatus::completed&&!controls&&playback.view_controls()==borrowed);
  services.view_attempt=make(playback.state(),session->clock_mode);
  check(playback.bind_view_controls(services.view_attempt)==s::CutscenePlaybackStatus::unavailable&&services.view_attempt);
  auto workspace=std::make_shared<s::CutsceneDescriptorWorkspace>();std::vector<std::byte> asset(6*40);
  const auto write=[&](unsigned index,unsigned offset,auto value){std::memcpy(asset.data()+40*index+offset,&value,sizeof value);};
  write(0,4,0u);write(1,4,1u);for(unsigned row=0;row<8;++row)write(1,8+2*row,std::uint16_t(0x55aau^row));
  write(1,24,0x87654321u);write(1,28,0x12345678u);write(2,4,2u);write(3,4,2u);write(3,2,std::uint16_t(20));
  for(unsigned lane=0;lane<4;++lane){write(2,8+2*lane,std::uint16_t(20+lane));write(3,8+2*lane,std::uint16_t(200-lane));}
  write(4,4,2u);write(4,2,std::uint16_t(65535));write(5,2,std::uint16_t(65535));
  constexpr unsigned base=0xc14000;
  for(unsigned clock=0;clock<256;++clock){
   case_id=100000+clock;auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.end_frame=1000;session->clock_mode=std::uint8_t(clock);session->single_roster_setup=1;world.mode=0;
   check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed&&borrowed->install(workspace,0,6)==s::CutsceneViewStatus::completed);
   std::fill_n(memory.data()+base,s::CutsceneDescriptorWorkspace::capacity,0);std::memcpy(memory.data()+base,asset.data(),asset.size());std::fill_n(memory.data()+base+asset.size(),4,255);
   std::memcpy(memory.data()+0x49f790,models.state().visibility.data(),128);std::memcpy(memory.data()+0x49f810,models.state().styles.data(),512);
   masks.begin_scene();put(memory.data(),0x3dddcc,*masks.first);put(memory.data(),0x3dddd0,*masks.second);
   compare_bound_view=true;
   {R5900Context original;PS2Runtime runtime;original.pc=0x1bbb10;SET_GPR_U32(&original,4,0xff987654);SET_GPR_U32(&original,29,0x1f00000);SET_GPR_U32(&original,31,0xabcdef);original_transform_port(memory.data(),&original,&runtime);check(original.pc==0xabcdef);}
   borrowed->reset_color(0xff987654);
   for(unsigned visit=0;visit<8;++visit){
    inputs={1,2,1,1,0,visit==3&&clock%2==0,visit==5&&clock%3==0,0};
    project(memory.data(),state,world,flags,channels);put(memory.data(),0x3901c0,base);put(memory.data(),0x38ecba,std::uint16_t(6));native_events.clear();source_events.clear();
    invoke(memory.data(),0x5ee680);services.playback=&playback;check(playback.tick().status==s::CutscenePlaybackStatus::completed);services.playback=nullptr;
    compare(memory.data(),state,world,channels);check(std::memcmp(models.state().visibility.data(),memory.data()+0x49f790,128)==0);
    check(std::memcmp(models.state().styles.data(),memory.data()+0x49f810,512)==0);
    check(*masks.first==transform_read<unsigned>(memory.data(),0x3dddcc)&&*masks.second==transform_read<unsigned>(memory.data(),0x3dddd0));
    check(std::memcmp(&color_state,memory.data()+0x316600,sizeof color_state)==0);
    check(std::memcmp(workspace->loaded().data(),memory.data()+base,asset.size())==0);++view_ticks;
   }
   compare_bound_view=false;
  }
  // Source subphase1 invokes the complete reset before advancing the shared
  // frame. Existing bindings are retired, with no duplicate provider callback.
  auto& state=playback.state();state={};state.phase=1;state.subphase=1;inputs={1,2,1,1,0,false,false,0};session->single_roster_setup=1;
  project(memory.data(),state,world,flags,channels);native_events.clear();source_events.clear();compare_bound_view=true;
  invoke(memory.data(),0x5ee680);check(playback.tick().status==s::CutscenePlaybackStatus::completed);compare(memory.data(),state,world,channels);
  check(!color.binding()&&std::memcmp(&color_state,memory.data()+0x316600,sizeof color_state)==0);compare_bound_view=false;
  state={};state.phase=1;state.subphase=3;state.end_frame=1000;check(workspace->load(asset)==s::DescriptorWorkspaceStatus::completed);
  check(playback.tick().status==s::CutscenePlaybackStatus::unavailable&&state.frame==0);++refusals;
  check(playback.unbind_view_controls()==s::CutscenePlaybackStatus::completed&&!playback.view_controls());
  check(playback.unbind_view_controls()==s::CutscenePlaybackStatus::completed);services.view_attempt.reset();
 }
