#pragma once
#include "../native_audio/v2/aggregate.h"
#include "../native_audio/v3/aggregate.h"
#include <stdexcept>

namespace reo::native::sound_ram {
// A synchronous interface adapter, not a new source of RAM authority. The real
// RuntimeMemory owner still validates every borrow and supplies the same scoped
// CaptureSource. Neither a token nor borrowed memory escapes through this shim.
class CaptureProviderV3 final:public audio_aggregate::v3::QualifiedCaptureProvider {
    std::shared_ptr<audio_aggregate::v2::QualifiedCaptureProvider> source_;
public:
    explicit CaptureProviderV3(std::shared_ptr<audio_aggregate::v2::QualifiedCaptureProvider> source)
        :source_(std::move(source)){if(!source_)throw std::invalid_argument("Native capture owner required");}
    bank_packets::v3::MemoryIdentity identity()const noexcept override{return source_->identity();}
    bank_packets::v3::PacketResult with_packet(const audio_aggregate::v3::PacketBorrow& borrow,
                                               audio_aggregate::v3::PacketOperation& operation)noexcept override {
        struct Forward final:audio_aggregate::v2::PacketOperation {
            audio_aggregate::v3::PacketOperation& operation;
            explicit Forward(audio_aggregate::v3::PacketOperation& value):operation(value){}
            bank_packets::v3::PacketResult run(const bank_packets::v3::CaptureSource& source)noexcept override{return operation.run(source);}
        } forward(operation);
        return source_->with_packet({borrow.ram,borrow.ram_bytes,borrow.packet,borrow.packet_bytes},forward);
    }
    bank_packets::v3::Status with_bank(const audio_aggregate::v3::BankBorrow& borrow,
                                      audio_aggregate::v3::BankOperation& operation)noexcept override {
        struct Forward final:audio_aggregate::v2::BankOperation {
            audio_aggregate::v3::BankOperation& operation;
            explicit Forward(audio_aggregate::v3::BankOperation& value):operation(value){}
            bank_packets::v3::Status run(const bank_packets::v3::CaptureSource& source)noexcept override{return operation.run(source);}
        } forward(operation);
        return source_->with_bank({borrow.port,borrow.hd,borrow.hd_bytes,borrow.bd,borrow.bd_bytes,borrow.tq,borrow.tq_bytes},forward);
    }
};
} // namespace reo::native::sound_ram
