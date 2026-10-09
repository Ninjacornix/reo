#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164958
// Address: 0x164958 - 0x164994
void sub_00164958_0x164958(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164958_0x164958");
#endif

    switch (ctx->pc) {
        case 0x164968u: goto label_164968;
        case 0x164970u: goto label_164970;
        case 0x164984u: goto label_164984;
        default: break;
    }

    ctx->pc = 0x164958u;

    // 0x164958: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164958u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16495c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16495cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164960: 0xc04a87a  jal         func_12A1E8
    ctx->pc = 0x164960u;
    SET_GPR_U32(ctx, 31, 0x164968u);
    ctx->pc = 0x12A1E8u;
    if (runtime->hasFunction(0x12A1E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164968u; }
        if (ctx->pc != 0x164968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1E8_0x12a1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164968u; }
        if (ctx->pc != 0x164968u) { return; }
    }
    ctx->pc = 0x164968u;
label_164968:
    // 0x164968: 0xc04b246  jal         func_12C918
    ctx->pc = 0x164968u;
    SET_GPR_U32(ctx, 31, 0x164970u);
    ctx->pc = 0x12C918u;
    if (runtime->hasFunction(0x12C918u)) {
        auto targetFn = runtime->lookupFunction(0x12C918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164970u; }
        if (ctx->pc != 0x164970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C918_0x12c918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164970u; }
        if (ctx->pc != 0x164970u) { return; }
    }
    ctx->pc = 0x164970u;
label_164970:
    // 0x164970: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x164970u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x164974: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x164974u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164978: 0x24840750  addiu       $a0, $a0, 0x750
    ctx->pc = 0x164978u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1872));
    // 0x16497c: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x16497Cu;
    SET_GPR_U32(ctx, 31, 0x164984u);
    ctx->pc = 0x164980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16497Cu;
            // 0x164980: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164984u; }
        if (ctx->pc != 0x164984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164984u; }
        if (ctx->pc != 0x164984u) { return; }
    }
    ctx->pc = 0x164984u;
label_164984:
    // 0x164984: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164984u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164988: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164988u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16498c: 0x3e00008  jr          $ra
    ctx->pc = 0x16498Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16498Cu;
            // 0x164990: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164968u: goto label_164968;
            case 0x164970u: goto label_164970;
            case 0x164984u: goto label_164984;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164994u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
