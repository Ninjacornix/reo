std::uint64_t activity_mode_cases{},activity_mode_refusals{};
void activity_contracts(){
    namespace session=reo::native::gameplay_session;
    session::ActivityState unknown;
    check(!session::activity_mode(0,unknown)&&!session::activity_mode(1,unknown));activity_mode_refusals+=2;
    check(session::activity_mode(2,unknown)==1&&session::activity_mode(255,unknown)==1);
    for(unsigned mode=0;mode<256;++mode)for(unsigned raw=0;raw<256;++raw){
        const auto single=std::bit_cast<std::int8_t>(std::uint8_t(raw)),online=std::bit_cast<std::int8_t>(std::uint8_t(raw^0x80));
        const auto result=session::activity_mode(std::uint8_t(mode),{single,online});check(result.has_value());
#ifdef REO_AI_ORIGINAL
        memory[0x3243f2]=std::uint8_t(mode);memory[0x83e2d5]=std::uint8_t(raw);memory[0x815d25]=std::uint8_t(raw^0x80);
        R5900Context context;PS2Runtime runtime;context.pc=0x1afe70;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);original_transform_port(memory.data(),&context,&runtime);
        check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000&&*result==std::bit_cast<std::int32_t>(GPR_U32(&context,2)));
#endif
        ++activity_mode_cases;
    }
    check(session::activity_mode(0,{std::int8_t(-128),{}})==-128&&session::activity_mode(1,{{},std::int8_t(127)})==127);
}
