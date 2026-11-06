        if(audio.native()&&ps2_cri_audio::nativeSoundRamSelectedV1()){
            bool valid=false;
            if(ps2_syscalls::describeSoundDriverIopTransfer(runtime,srcAddr,size,valid)){
                using namespace ps2_cri_audio;
                NativeSoundRamCallV1 capture(audio,runtime,rdram,NativeSoundRamUseV1::status_transfer);
                if(!valid){capture.reject(NativeSoundRamStageV1::read,BankStatusV2::invalid_input);setReturnS32(ctx,-1);return;}
                if(!capture||!ps2_syscalls::prepareSoundDriverStatusTransferCaptured(srcAddr,size,runtime,capture)||
                    capture.forward(NativeSoundRamSpaceV1::iop,srcAddr,NativeSoundRamSpaceV1::ee,dstAddr,size)!=BankStatusV2::ok){setReturnS32(ctx,-1);return;}
                const NativeSoundRamWriteV1 writes[]{
                    {NativeSoundRamSpaceV1::ee,rdAddr+0x10u,{reinterpret_cast<const uint8_t*>(&srcAddr),4}},
                    {NativeSoundRamSpaceV1::ee,rdAddr+0x14u,{reinterpret_cast<const uint8_t*>(&dstAddr),4}},
                    {NativeSoundRamSpaceV1::ee,rdAddr+0x18u,{reinterpret_cast<const uint8_t*>(&size),4}}};
                if(capture.write(writes,NativeSoundRamControlV1::receive_descriptor)!=BankStatusV2::ok){setReturnS32(ctx,-1);return;}
                ps2_syscalls::finalizeSoundDriverStatusTransfer(rdram,srcAddr,dstAddr,size);
                setReturnS32(ctx,0);return;
            }
        }
