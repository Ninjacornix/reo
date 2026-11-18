    // Companion-only builtin sound transport. The legacy SifCallRpc body below
    // remains the default when this separately versioned companion is absent.
    bool tryNativeSoundRamRpc(uint8_t* rdram,R5900Context* ctx,PS2Runtime* runtime)
    {
        if(!ps2_cri_audio::nativeSoundRamSelectedV1())return false;
        const uint32_t cp=getRegU32(ctx,4),rpc=getRegU32(ctx,5),mode=getRegU32(ctx,6),send=getRegU32(ctx,7);
        uint32_t sid{},mapped{};
        {std::lock_guard<std::mutex> lock(g_rpc_mutex);auto it=g_rpc_clients.find(cp);
            if(it==g_rpc_clients.end()||(it->second.sid!=IOP_SID_SNDDRV_COMMAND&&it->second.sid!=IOP_SID_SNDDRV_STATE))return false;
            sid=it->second.sid;auto server=g_rpc_servers.find(sid);
            if(sid&&server!=g_rpc_servers.end())mapped=server->second.sd_ptr;}
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);ps2_cri_audio::SoundCallScope scope(audio);
        RamCall cap(audio,runtime,rdram,sid==IOP_SID_SNDDRV_COMMAND?ps2_cri_audio::NativeSoundRamUseV1::command:ps2_cri_audio::NativeSoundRamUseV1::query);
        const auto early=[&]{setReturnS32(ctx,-1);return true;};
        if(!audio||!cap)return early(); // No client reads or guessed completion.
        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpc)){
            cap.reject(ps2_cri_audio::NativeSoundRamStageV1::read,ps2_cri_audio::BankStatusV2::unsupported);return early();}
        uint32_t stack[6]{};const uint32_t sp=getRegU32(ctx,29);
        ps2_cri_audio::NativeSoundRamReadV1 reads[6]{};
        const uint32_t offsets[]{0,0x10,0x14,0x18,0x1c,0x20};
        for(unsigned i=0;i<6;++i)reads[i]={RamSpace::ee,sp+offsets[i],{reinterpret_cast<uint8_t*>(&stack[i]),4}};
        if(cap.read(reads)!=ps2_cri_audio::BankStatusV2::ok)return early();
        const auto pointer=[](uint32_t v){const auto n=v&0x1fffffffu;return !v||(n>=0x10000u&&n<PS2_RAM_SIZE);};
        const auto plausible=[&](uint32_t n,uint32_t b,uint32_t m,uint32_t f){return n<=0x2000000u&&pointer(b)&&m<=0x2000000u&&pointer(f);};
        const uint32_t nr=getRegU32(ctx,8),br=getRegU32(ctx,9),mr=getRegU32(ctx,10),fr=getRegU32(ctx,11);
        const bool reg=plausible(nr,br,mr,fr),stk=plausible(stack[1],stack[2],stack[3],stack[4]);
        const bool useReg=reg||!stk||((fr&&pointer(fr))&&!(stack[4]&&pointer(stack[4])));
        const uint32_t n=useReg?nr:stack[1],recv=useReg?br:stack[2],rn=useReg?mr:stack[3];
        const uint32_t end=useReg?fr:stack[4],param=useReg?stack[0]:stack[5];
        t_SifRpcClientData client{};if(!capturedRead(cap,RamSpace::ee,cp,client))return early();
        const uint32_t serverPtr=mapped?mapped:client.server;
        t_SifRpcServerData sd{};
        if(serverPtr&&!capturedRead(cap,RamSpace::ee,serverPtr,sd))return early();
        // A builtin service with an EE server callback is outside this profile.
        // Descriptor overlap would make original sequential pointer reads
        // self-mutating; refuse before metadata/transport/core effects.
        const uint64_t c=cp&0x1fffffffu,s=serverPtr&0x1fffffffu;
        const uint64_t dest=sd.buf&0x1fffffffu,copyBytes=std::min<std::size_t>(n,1u<<20);
        const auto overlap=[](uint64_t a,uint64_t n1,uint64_t b,uint64_t n2){return n1&&n2&&a<b+n2&&b<a+n1;};
        const bool transportMetadata=serverPtr&&sd.buf&&send&&n&&
            (overlap(dest,copyBytes,c,sizeof(client))||overlap(dest,copyBytes,s,sizeof(sd)));
        if((serverPtr&&sd.func)||(serverPtr&&c<s+sizeof(sd)&&s<c+sizeof(client))||transportMetadata){
            cap.reject(ps2_cri_audio::NativeSoundRamStageV1::read,ps2_cri_audio::BankStatusV2::unsupported);return early();}
        uint32_t sema=static_cast<uint32_t>(client.hdr.sema_id);bool semaKnown=true;
        const auto completionId=[&]{return sema==0xffffffffu||!sema?param:sema;};
        const auto refreshSema=[&]{semaKnown=capturedRead(cap,RamSpace::ee,cp+offsetof(t_SifRpcClientData,hdr)+offsetof(t_SifRpcHeader,sema_id),sema);return semaKnown;};
        bool effected=false;
        const auto finish=[&](bool ok){
            if(effected){std::lock_guard<std::mutex> lock(g_rpc_mutex);g_rpc_clients[cp].busy=false;}
            if(!ok&&effected&&semaKnown)(void)signalRpcCompletionSema(completionId());
            setReturnS32(ctx,ok?0:-1);return true;
        };
        const auto put=[&](uint32_t at,const auto& value){const auto op=capturedWrite(RamSpace::ee,at,value);return cap.control({&op,1},RamControl::rpc_metadata)==ps2_cri_audio::BankStatusV2::ok;};
        const RamOp metadata[]{
            capturedWrite(RamSpace::ee,cp+offsetof(t_SifRpcClientData,command),rpc),
            capturedWrite(RamSpace::ee,cp+offsetof(t_SifRpcClientData,end_function),end),
            capturedWrite(RamSpace::ee,cp+offsetof(t_SifRpcClientData,end_param),param),
            capturedWrite(RamSpace::ee,cp+offsetof(t_SifRpcClientData,hdr)+offsetof(t_SifRpcHeader,mode),mode)};
        if(cap.control(metadata,RamControl::rpc_metadata)!=ps2_cri_audio::BankStatusV2::ok)return early();
        effected=true;
        {std::lock_guard<std::mutex> lock(g_rpc_mutex);g_rpc_clients[cp].busy=true;g_rpc_clients[cp].last_rpc=rpc;}
        if(mapped&&client.server!=mapped&&!put(cp+offsetof(t_SifRpcClientData,server),mapped))return finish(false);
        if(serverPtr){
            // No metadata struct overlap admitted; pkt_addr was unchanged by
            // the four original client field writes above.
            const uint32_t rmode=((mode&kSifRpcModeNowait)&&!end)?0:1,zero=0;
            const RamOp writes[]{
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,client),cp),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,pkt_addr),client.hdr.pkt_addr),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,rpc_number),rpc),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,size),n),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,recvbuf),recv),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,rsize),rn),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,rmode),rmode),
                capturedWrite(RamSpace::ee,serverPtr+offsetof(t_SifRpcServerData,rid),zero)};
            if(cap.control(writes,RamControl::rpc_metadata)!=ps2_cri_audio::BankStatusV2::ok)return finish(false);
            // The original reads buf after its metadata writes. Distinct fields
            // make the value unchanged under the admitted descriptor domain.
            if(sd.buf&&send&&n){
                if(cap.forward(RamSpace::ee,send,RamSpace::ee,sd.buf,std::min<std::size_t>(n,1u<<20))!=ps2_cri_audio::BankStatusV2::ok)return finish(false);
                semaKnown=false; // Only a successful copy can change metadata.
                if(!refreshSema())return finish(false);
            }
        }
        runtime->iop().init(rdram);
        uint32_t result{};bool signal=false;
        const bool handled=handleSoundDriverRpcCaptured(rdram,runtime,sid,rpc,send,n,recv,rn,result,signal,audio,cap);
        if(!handled||!cap)return finish(false);
        // Query replies can alias client metadata; observe completion only
        // after those writes, through the same read capability.
        if(!refreshSema())return finish(false);
        if(signal&&(mode&kSifRpcModeNowait))(void)signalRpcCompletionSema(completionId());
        if(end){
            bool invoked=rpcInvokeFunction(rdram,ctx,runtime,end,param,0,0,0,nullptr);
            if(!invoked&&end>=0x10000u&&runtime->hasFunction(end-0x10000u))invoked=rpcInvokeFunction(rdram,ctx,runtime,end-0x10000u,param,0,0,0,nullptr);
            PS2SoundDriverCompatLayout compat{};{std::lock_guard<std::mutex> lock(g_rpc_mutex);compat=g_soundDriverCompatLayout;}
            if(!refreshSema())return finish(false);
            if(compat.matchesCompletionCallback(end)){
                (void)signalRpcCompletionSema(completionId());
                if(compat.busyFlagAddr&&compat.matchesClearBusyCallback(end)){
                    const uint32_t zero=0;if(!put(compat.busyFlagAddr,zero))return finish(false);
                }
            }
            if(!invoked){
                // The compat busy word can alias client.hdr.sema_id. Original
                // fallback observes it again AFTER that write.
                if(!refreshSema())return finish(false);
                (void)signalRpcCompletionSema(completionId());
            }
        }
        return finish(true);
    }
