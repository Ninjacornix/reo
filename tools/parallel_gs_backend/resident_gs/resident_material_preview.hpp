#pragma once
#include "gs_interface.hpp"
#include "resident_material.hpp"
#include "fence.hpp"
#include <memory>
#include <vector>
namespace reo_gpu_mixed_material {class SourceCertificate;}
namespace ParallelGS {
struct ResidentMaterialGroupCommand {
    enum class Kind:uint32_t {Init=0,Geometry=1,AD6=2};
    Kind kind=Kind::Init;
    uint32_t mainPRIM=0,sourceVertices=0;
    std::array<uint32_t,28> rawAD{};
    // CPU RAW envelope/Echo only on input. Preview replaces words16..31 with
    // actual captured same-Device scissor/material metadata.
    std::array<uint32_t,112> sourceParameters{};
};

// Only the concrete source-certificate adapter can mint this association from
// the actual Output. Public primitive views cannot replace its owned banks.
class ResidentMaterialGroupOutputBinding final {
    friend class GSInterface;
    friend class reo_gpu_mixed_material::SourceCertificate;
    ResidentMaterialGroupOutputBinding()=default;
    struct View {uint32_t job=0,chunk=0;ResidentPrimitiveInputs inputs;};
    Vulkan::Device* owner_=nullptr;uint64_t epoch_=0;uint32_t generation_=0,jobs_=0;
    std::array<Vulkan::BufferHandle,5> banks_;
    std::vector<View> views_;
};
using ResidentMaterialGroupOutputBindingHandle=std::shared_ptr<const ResidentMaterialGroupOutputBinding>;

class ResidentMaterialGroupPreview final {
    friend class GSInterface;

    GSInterface* gs_=nullptr;Vulkan::Device* device_=nullptr;
    std::shared_ptr<const uint8_t> ownerIdentity_;
    uint64_t epoch_=0,revision_=0;uint32_t generation_=0;
    uint64_t initialCounter_=0,committedCounter_=0;
    RegisterState initial_{},terminal_{},committedRegisters_{};
    PrivRegisterState initialPriv_{};
    std::vector<ResidentMaterialGroupCommand> commands_;
    std::vector<ResidentMaterial> materials_;
    std::vector<uint64_t> capturedCounters_;
    std::vector<std::array<uint32_t,112>> expectedParameters_;
    ResidentMaterialGroupOutputBindingHandle outputBinding_;size_t nextView_=0;
    Vulkan::BufferHandle privateSourceClaim_;bool sourceCertificateRecorded_=false;
    Vulkan::BufferHandle integerHost_,sourceCompletion_,sourceCertificates_;
    Vulkan::Fence ownReceipt_;
    bool receiptSubmitted_=false,committed_=false,closed_=false;
    uint32_t lastGeometry_=~0u;bool finalADQReset_=false;
public:
    const Vulkan::Device* owner()const{return device_;}
    uint64_t epoch()const{return epoch_;}uint32_t generation()const{return generation_;}
    uint32_t jobs()const{return uint32_t(commands_.size());}
    const ResidentMaterialGroupCommand& command(uint32_t job)const{return commands_.at(job);}
    const ResidentMaterial* material(uint32_t job)const{return commands_.at(job).kind==ResidentMaterialGroupCommand::Kind::Geometry?&materials_.at(job):nullptr;}
    const std::array<uint32_t,112>& parameters(uint32_t job)const{return expectedParameters_.at(job);}
    bool committed()const{return committed_;}
};
}
