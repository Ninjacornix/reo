        using RamCall=ps2_cri_audio::NativeSoundRamCallV1;
        using RamSpace=ps2_cri_audio::NativeSoundRamSpaceV1;
        using RamControl=ps2_cri_audio::NativeSoundRamControlV1;
        using RamOp=ps2_cri_audio::NativeSoundRamControlOpV1;
        using RamKind=ps2_cri_audio::NativeSoundRamControlKindV1;
        template<class T>bool capturedRead(RamCall& cap,RamSpace space,uint32_t at,T& value){
            ps2_cri_audio::NativeSoundRamReadV1 read{space,at,{reinterpret_cast<uint8_t*>(&value),sizeof(T)}};
            return cap.read({&read,1})==ps2_cri_audio::BankStatusV2::ok;
        }
        template<class T>RamOp capturedWrite(RamSpace space,uint32_t at,const T& value){
            return {RamKind::write,space,at,{reinterpret_cast<const uint8_t*>(&value),sizeof(T)},sizeof(T)};
        }
        bool checkSoundDriverMemoryCaptured(uint8_t* rdram,PS2Runtime* runtime,ps2_cri_audio::SoundCall& audio,RamCall& cap){
            if(!rdram||!runtime||!adoptSoundDriverRuntimeUnlocked(runtime,audio))return false;
            g_soundDriverIopRam=runtime->memory().getIOPRAM();if(!g_soundDriverIopRam)return false;
            if(!g_soundDriverRpcState.statusAddr){
                const uint32_t status=alignUp(kSoundDriverGuestPoolBase,kSoundDriverStatusAlignment);
                const uint32_t table=alignUp(status+kSoundDriverStatusSize,kSoundDriverAddrTableAlignment);
                const uint32_t hd=alignUp(table+kSoundDriverAddrTableEntries*sizeof(uint32_t),kSoundDriverStorageAlignment);
                const uint32_t sq=alignUp(hd+kSoundDriverHdRegionSize,kSoundDriverStorageAlignment);
                const uint32_t data=alignUp(sq+kSoundDriverSqRegionSize,kSoundDriverStorageAlignment);
                if(data+kSoundDriverDataRegionSize>kSoundDriverGuestPoolLimit)return false;
                g_soundDriverRpcState.statusAddr=status;g_soundDriverRpcState.addrTableAddr=table;
                g_soundDriverRpcState.hdBaseAddr=hd;g_soundDriverRpcState.sqBaseAddr=sq;g_soundDriverRpcState.dataBaseAddr=data;
                g_soundDriverRpcState.storageBaseAddr=hd;g_soundDriverRpcState.storageSize=data+kSoundDriverDataRegionSize-hd;
            }
            if(!g_soundDriverRpcState.initialized){
                const uint32_t addresses[]{g_soundDriverRpcState.hdBaseAddr,g_soundDriverRpcState.sqBaseAddr,g_soundDriverRpcState.dataBaseAddr};
                const RamOp ops[]{
                    {RamKind::zero,RamSpace::iop,g_soundDriverRpcState.statusAddr,{},kSoundDriverStatusSize},
                    {RamKind::zero,RamSpace::iop,g_soundDriverRpcState.addrTableAddr,{},kSoundDriverAddrTableEntries*sizeof(uint32_t)},
                    {RamKind::zero,RamSpace::iop,g_soundDriverRpcState.storageBaseAddr,{},g_soundDriverRpcState.storageSize},
                    capturedWrite(RamSpace::iop,g_soundDriverRpcState.addrTableAddr,addresses[0]),
                    capturedWrite(RamSpace::iop,g_soundDriverRpcState.addrTableAddr+4,addresses[1]),
                    capturedWrite(RamSpace::iop,g_soundDriverRpcState.addrTableAddr+8,addresses[2])};
                if(cap.control(ops,RamControl::status_arena)!=ps2_cri_audio::BankStatusV2::ok)return false;
                g_soundDriverRpcState.initialized=true;
            }
            return true;
        }
        bool backfillSoundDriverStatusCaptured(RamCall& cap){
            if(!g_soundDriverRpcState.statusAddr||!g_soundDriverCompatLayout.hasChecksumTables())return true;
            std::array<int16_t,5> se{};std::array<int16_t,4> midi{};
            auto readChecks=[&](uint32_t sa,uint32_t ma){const ps2_cri_audio::NativeSoundRamReadV1 reads[]{
                {RamSpace::ee,sa,{reinterpret_cast<uint8_t*>(se.data()),sizeof(se)}},
                {RamSpace::ee,ma,{reinterpret_cast<uint8_t*>(midi.data()),sizeof(midi)}}};
                return cap.read(reads)==ps2_cri_audio::BankStatusV2::ok;};
            const auto& layout=g_soundDriverCompatLayout;
            if(!readChecks(layout.primarySeCheckAddr,layout.primaryMidiCheckAddr))return false;
            const auto nonzero=[](const auto& values){return std::any_of(values.begin(),values.end(),[](auto x){return x!=0;});};
            if(!nonzero(se)&&!nonzero(midi)){
                const auto primarySe=se;const auto primaryMidi=midi;
                if(!readChecks(layout.fallbackSeCheckAddr,layout.fallbackMidiCheckAddr))return false;
                if(!nonzero(se)&&!nonzero(midi)){se=primarySe;midi=primaryMidi;}
            }
            std::array<int16_t,5> liveSe{};std::array<int16_t,4> liveMidi{};
            const ps2_cri_audio::NativeSoundRamReadV1 reads[]{
                {RamSpace::iop,g_soundDriverRpcState.statusAddr+kSoundDriverSeSumOffset,{reinterpret_cast<uint8_t*>(liveSe.data()),sizeof(liveSe)}},
                {RamSpace::iop,g_soundDriverRpcState.statusAddr+kSoundDriverMidiSumOffset,{reinterpret_cast<uint8_t*>(liveMidi.data()),sizeof(liveMidi)}}};
            if(cap.read(reads)!=ps2_cri_audio::BankStatusV2::ok)return false;
            std::array<RamOp,9> writes{};std::size_t n=0;
            for(unsigned i=0;i<se.size();++i)if(!liveSe[i]&&se[i])writes[n++]=capturedWrite(RamSpace::iop,g_soundDriverRpcState.statusAddr+kSoundDriverSeSumOffset+i*2,se[i]);
            for(unsigned i=0;i<midi.size();++i)if(!liveMidi[i]&&midi[i])writes[n++]=capturedWrite(RamSpace::iop,g_soundDriverRpcState.statusAddr+kSoundDriverMidiSumOffset+i*2,midi[i]);
            return !n||cap.control({writes.data(),n},RamControl::status_arena)==ps2_cri_audio::BankStatusV2::ok;
        }
        bool handleSoundDriverRpcCaptured(uint8_t* rdram,PS2Runtime* runtime,uint32_t sid,uint32_t rpcNum,
            uint32_t sendBuf,uint32_t sendSize,uint32_t recvBuf,uint32_t recvSize,uint32_t& resultPtr,
            bool& signalNowaitCompletion,ps2_cri_audio::SoundCall& audio,RamCall& cap){
            resultPtr=0;signalNowaitCompletion=false;if(!cap)return true;
            if(sid==IOP_SID_SNDDRV_COMMAND&&rpcNum==IOP_RPC_SNDDRV_SUBMIT){
                if(!sendBuf||!sendSize)return true;
                std::lock_guard<std::mutex> lock(g_rpc_mutex);
                if(!checkSoundDriverMemoryCaptured(rdram,runtime,audio,cap))return true;
                ps2_cri_audio::NativeSoundRamPacketV1 packet;
                if(cap.snapshot(sendBuf,sendSize,packet)!=ps2_cri_audio::BankStatusV2::ok)return true;
                (void)cap.log(packet); // Owned bytes only; log failure does not block game.
                if(audio.ensure_output()!=ps2_cri_audio::BankStatusV2::ok)return true;
                (void)audio.submit_packet(rdram,32u*1024u*1024u,packet.data,packet.bytes);
                return true; // Source deliberately ignores the parser bool/status.
            }
            const uint32_t query=rpcNum&255;
            if(sid==IOP_SID_SNDDRV_STATE&&(query==4||query==6||query==12)){
                uint32_t input=0,words[2]{};
                if(sendBuf&&sendSize>=4&&!capturedRead(cap,RamSpace::ee,sendBuf,input))return true;
                ps2_cri_audio::BankQueryV2 reply;
                if(query==12)reply=audio.pending_loads();else if(query==6)reply=audio.port_state(input,words[1]);
                else reply=audio.se_state((input>>16)&127,(input>>8)&127,input&127);
                if(reply.status!=ps2_cri_audio::BankStatusV2::ok){signalNowaitCompletion=true;return true;}words[0]=reply.value;
                if(recvBuf&&recvSize>=4){RamOp writes[]{capturedWrite(RamSpace::ee,recvBuf,words[0]),capturedWrite(RamSpace::ee,recvBuf+4,words[1])};
                    if(cap.control({writes,recvSize>=8?2u:1u},RamControl::query_reply)!=ps2_cri_audio::BankStatusV2::ok)return true;resultPtr=recvBuf;}
                signalNowaitCompletion=true;return true;
            }
            if(sid==IOP_SID_SNDDRV_STATE&&(rpcNum==IOP_RPC_SNDDRV_GET_STATUS_ADDR||rpcNum==IOP_RPC_SNDDRV_GET_ADDR_TABLE)){
                uint32_t word{};{std::lock_guard<std::mutex> lock(g_rpc_mutex);if(!checkSoundDriverMemoryCaptured(rdram,runtime,audio,cap)){signalNowaitCompletion=true;return true;}
                    word=rpcNum==IOP_RPC_SNDDRV_GET_STATUS_ADDR?g_soundDriverRpcState.statusAddr:g_soundDriverRpcState.addrTableAddr;}
                if(recvBuf&&recvSize>=4){RamOp writes[]{capturedWrite(RamSpace::ee,recvBuf,word),{RamKind::zero,RamSpace::ee,recvBuf+4,{},recvSize-4}};
                    if(cap.control({writes,recvSize>4?2u:1u},RamControl::query_reply)!=ps2_cri_audio::BankStatusV2::ok)return true;resultPtr=recvBuf;}
                signalNowaitCompletion=true;return true;
            }
            return false;
        }
