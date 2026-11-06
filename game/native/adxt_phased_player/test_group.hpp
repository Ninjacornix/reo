#pragma once
#include "player.hpp"
#include "../adxt_transfer_groups/transfer_groups.hpp"
#include <stdexcept>

namespace reo::native::adxt_phased_player::testing {
namespace g=adxt_service_group;
namespace t=adxt_transfer_groups;
struct Guards final:g::Guards,t::ChunkGuard {
    int cri{},rna{},chunk{};bool fault{};std::uint64_t dtx_scans{};
    void enter(g::Domain d)noexcept override{if(d==g::Domain::cri)++cri;else ++rna;}
    void leave(g::Domain d)noexcept override{if(d==g::Domain::cri)--cri;else --rna;if(cri<0 || rna<0)fault=true;}
    void enter()noexcept override{++chunk;++dtx_scans;}
    void leave()noexcept override{--chunk;if(chunk<0)fault=true;}
};
// An explicitly serialized offline control driver. The owned ports themselves
// are production module types; guards model the declared control exclusion.
// Device rendering is an independent explicit step in the test provider.
struct Driver {
    std::shared_ptr<clock::Shared> shared=std::make_shared<clock::Shared>();
    std::shared_ptr<Guards> guards=std::make_shared<Guards>();
    std::shared_ptr<t::DtxGroup> dtx=std::make_shared<t::DtxGroup>(guards);
    std::shared_ptr<t::DtrGroup> dtr=std::make_shared<t::DtrGroup>(dtx);
    g::Group group{shared,guards,dtr,dtx};
    struct Indices{std::uint32_t decoder{},stream{},rna{},transfer{};};
    struct Binding{std::shared_ptr<Player> player;Ports ports;Indices indices;};
    void attach(Binding& b,std::shared_ptr<Player> player,Indices indices){
        if(indices.decoder>=16 || indices.stream>=16 || indices.rna>=16 || indices.transfer>=32 || b.player)throw std::invalid_argument("Prepared group binding");
        auto ports=player->make_ports(); // Allocate all four before table effects.
        if(!group.set_decoder(indices.decoder,ports.decoder) || !group.set_stream(indices.stream,ports.stream) ||
           !group.set_rna(indices.rna,ports.rna) || !dtr->set(indices.transfer,ports.transfer))throw std::logic_error("Prepared slots");
        b={std::move(player),std::move(ports),indices};
    }
    void detach(Binding& b){
        if(!b.player)return;
        if(!group.set_decoder(b.indices.decoder,{}) || !group.set_stream(b.indices.stream,{}) ||
           !group.set_rna(b.indices.rna,{}) || !dtr->set(b.indices.transfer,{}))throw std::logic_error("Owned slots");
        b.ports={};b.player.reset();
    }
};
} // namespace reo::native::adxt_phased_player::testing
