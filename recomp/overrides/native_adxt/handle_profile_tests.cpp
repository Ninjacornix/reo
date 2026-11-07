#include "handle_profile.h"
#include <iostream>
#include <stdexcept>
#include <vector>
namespace n=reo::native::adxt_binding;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Handle profile check "+std::to_string(checks));}
template<class T>void store(std::vector<std::uint8_t>& ram,std::uint32_t at,T value){std::memcpy(ram.data()+at,&value,sizeof(value));}
std::uint32_t at(n::Pool pool,unsigned slot){return pool.base+pool.stride*slot;}
struct Fixture {
    std::vector<std::uint8_t> ram=std::vector<std::uint8_t>(n::ram_bytes);
    std::uint32_t handle{},decoder{},file{},rna{},input{};
    std::array<std::uint32_t,2> dtr{},psj{},output{},destination{};
    Fixture(unsigned slot=5,unsigned channels=2){
        handle=at(n::handles,slot);decoder=at(n::decoders,(slot+7)%16);file=at(n::files,(slot+23)%40);rna=at(n::rnas,(slot+11)%16);input=0x1a00000+slot*0x1000;
        ram[handle]=ram[decoder]=ram[file]=ram[rna]=1;ram[handle+3]=ram[decoder+2]=static_cast<std::uint8_t>(channels);
        store(ram,handle+4,decoder);store(ram,handle+8,file);store(ram,handle+12,rna);store(ram,handle+0x10,input);store(ram,decoder+8,input);store(ram,file+4,input);store(ram,rna+4,channels);store(ram,rna+0x20,0x1e0000u+slot*0x80);store(ram,0x221438,32u);
        for(unsigned channel=0;channel<channels;++channel){
            const auto index=slot*2+channel;dtr[channel]=at(n::transfers,index);psj[channel]=at(n::paired,index);output[channel]=0x1b00000+slot*0x1000+channel*0x80;destination[channel]=0x1c00000+index*0x80;
            ram[dtr[channel]]=ram[psj[channel]]=1;store(ram,handle+0x18+channel*4,output[channel]);store(ram,decoder+0xc+channel*4,output[channel]);store(ram,rna+0x18+channel*4,output[channel]);
            store(ram,rna+0x10+channel*4,dtr[channel]);store(ram,rna+8+channel*4,psj[channel]);store(ram,dtr[channel]+4,output[channel]);store(ram,dtr[channel]+8,destination[channel]);store(ram,psj[channel]+8,destination[channel]);
        }
    }
    n::HandleResult inspect(){return n::inspect_handle(ram,handle);}
};
template<class F>void refuse(n::HandleStatus expected,F&& change){Fixture f;change(f);const auto before=f.ram;auto result=f.inspect();check(result.status==expected);check(f.ram==before && !result.value.address);}
int main()try{
    for(unsigned slot=0;slot<16;++slot)for(unsigned channels:{1u,2u}){
        Fixture f(slot,channels);const auto before=f.ram;const auto result=f.inspect();check(result.status==n::HandleStatus::ready);
        const auto& h=result.value;check(h.address==f.handle && h.slot==slot && h.channels==channels && h.decoder_slot==(slot+7)%16 && h.file_slot==(slot+23)%40 && h.rna_slot==(slot+11)%16 && h.route==0x1e0000+slot*0x80 && h.input==f.input);
        for(unsigned channel=0;channel<channels;++channel)check(h.transfer[channel]==f.dtr[channel] && h.transfer_slot[channel]==slot*2+channel && h.output[channel]==f.output[channel] && h.paired_record[channel]==f.psj[channel]);
        check(f.ram==before);
    }
    refuse(n::HandleStatus::wrong_ram,[](auto& f){f.ram.pop_back();});
    refuse(n::HandleStatus::invalid_handle,[](auto& f){f.handle+=4;});
    refuse(n::HandleStatus::invalid_handle,[](auto& f){f.handle=UINT32_MAX;});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.handle]=0;});
    refuse(n::HandleStatus::unsupported_channels,[](auto& f){f.ram[f.handle+3]=0;});
    refuse(n::HandleStatus::unsupported_channels,[](auto& f){f.ram[f.handle+3]=3;});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.handle+4,at(n::decoders,16));});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.handle+8,f.file+4);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.handle+8,at(n::files,40));});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.handle+12,0x80000000u|f.rna);});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.decoder]=0;});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.rna]=0;});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.file]=0;});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){f.ram[f.decoder+2]=1;});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){store(f.ram,f.rna+4,1u);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.handle+0x10,0u);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.decoder+8,f.input+4);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.file+4,f.input+4);});
    for(std::uint32_t route:{0u,0x1e0001u,0x1eff00u})refuse(n::HandleStatus::invalid_route,[route](auto& f){store(f.ram,f.rna+0x20,route);});
    for(std::uint32_t count:{0u,33u})refuse(n::HandleStatus::invalid_child,[count](auto& f){store(f.ram,0x221438,count);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,0x221438,1u);});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){store(f.ram,f.rna+0x1c,f.output[0]);});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){store(f.ram,f.decoder+0x10,0u);});
    refuse(n::HandleStatus::invalid_child,[](auto& f){store(f.ram,f.rna+0x14,0u);});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.dtr[1]]=0;});
    refuse(n::HandleStatus::inactive,[](auto& f){f.ram[f.psj[1]]=0;});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){store(f.ram,f.dtr[1]+4,f.output[0]);});
    refuse(n::HandleStatus::channel_mismatch,[](auto& f){store(f.ram,f.dtr[1]+8,f.destination[0]);});
    refuse(n::HandleStatus::unsupported_transfers,[](auto& f){const auto replacement=at(n::transfers,31);f.ram[replacement]=1;store(f.ram,replacement+4,f.output[1]);store(f.ram,replacement+8,f.destination[1]);store(f.ram,f.rna+0x14,replacement);});
    Fixture mono(15,1);store(mono.ram,mono.rna+0x10,at(n::transfers,31));mono.ram[at(n::transfers,31)]=1;store(mono.ram,at(n::transfers,31)+4,mono.output[0]);store(mono.ram,at(n::transfers,31)+8,mono.destination[0]);check(mono.inspect().status==n::HandleStatus::ready && mono.inspect().value.transfer_slot[0]==31);
    Fixture tail;const auto last_file=at(n::files,39);tail.ram[last_file]=1;store(tail.ram,last_file+4,tail.input);store(tail.ram,tail.handle+8,last_file);check(tail.inspect().status==n::HandleStatus::ready && tail.inspect().value.file_slot==39);
    std::cout<<"File1 handle admission checks="<<checks<<"; declared RAM fixture only\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
