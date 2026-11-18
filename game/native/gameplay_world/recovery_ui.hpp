#pragma once
namespace reo::native::gameplay_world {
class World;
// Shared actual6E1430 consumer. InventoryUi owns the source-cleared profile;
// active inventory presentation remains a separate explicit capability.
class RecoveryUi {
public:
    virtual ~RecoveryUi()=default;
    virtual bool bound_to(const World&)const noexcept=0;
    virtual bool close()=0;
};
}
