#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101E90
// Address: 0x101e90 - 0x101ee0
void sub_00101E90_0x101e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101E90_0x101e90");
#endif

    switch (ctx->pc) {
        case 0x101ea4u: goto label_101ea4;
        case 0x101ec4u: goto label_101ec4;
        case 0x101eccu: goto label_101ecc;
        default: break;
    }

    ctx->pc = 0x101e90u;

    // 0x101e90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x101e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x101e94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x101e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x101e98: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x101e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x101e9c: 0xc0407d8  jal         func_101F60
    ctx->pc = 0x101E9Cu;
    SET_GPR_U32(ctx, 31, 0x101EA4u);
    ctx->pc = 0x101EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101E9Cu;
            // 0x101ea0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101F60u;
    if (runtime->hasFunction(0x101F60u)) {
        auto targetFn = runtime->lookupFunction(0x101F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EA4u; }
        if (ctx->pc != 0x101EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101F60_0x101f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EA4u; }
        if (ctx->pc != 0x101EA4u) { return; }
    }
    ctx->pc = 0x101EA4u;
label_101ea4:
    // 0x101ea4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x101ea4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101ea8: 0x28620004  slti        $v0, $v1, 0x4
    ctx->pc = 0x101ea8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x101eac: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x101EACu;
    {
        const bool branch_taken_0x101eac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EACu;
            // 0x101eb0: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101eac) {
            ctx->pc = 0x101ED0u;
            goto label_101ed0;
        }
    }
    ctx->pc = 0x101EB4u;
    // 0x101eb4: 0x18600007  blez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x101EB4u;
    {
        const bool branch_taken_0x101eb4 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x101EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101EB4u;
            // 0x101eb8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101eb4) {
            ctx->pc = 0x101ED4u;
            goto label_101ed4;
        }
    }
    ctx->pc = 0x101EBCu;
    // 0x101ebc: 0xc0407ec  jal         func_101FB0
    ctx->pc = 0x101EBCu;
    SET_GPR_U32(ctx, 31, 0x101EC4u);
    ctx->pc = 0x101EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101EBCu;
            // 0x101ec0: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101FB0u;
    if (runtime->hasFunction(0x101FB0u)) {
        auto targetFn = runtime->lookupFunction(0x101FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EC4u; }
        if (ctx->pc != 0x101EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101FB0_0x101fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101EC4u; }
        if (ctx->pc != 0x101EC4u) { return; }
    }
    ctx->pc = 0x101EC4u;
label_101ec4:
    // 0x101ec4: 0xc0407e8  jal         func_101FA0
    ctx->pc = 0x101EC4u;
    SET_GPR_U32(ctx, 31, 0x101ECCu);
    ctx->pc = 0x101EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101EC4u;
            // 0x101ec8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101FA0u;
    if (runtime->hasFunction(0x101FA0u)) {
        auto targetFn = runtime->lookupFunction(0x101FA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ECCu; }
        if (ctx->pc != 0x101ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101FA0_0x101fa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ECCu; }
        if (ctx->pc != 0x101ECCu) { return; }
    }
    ctx->pc = 0x101ECCu;
label_101ecc:
    // 0x101ecc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101eccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101ed0:
    // 0x101ed0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x101ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_101ed4:
    // 0x101ed4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x101ed4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x101ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x101ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101ED8u;
            // 0x101edc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101EA4u: goto label_101ea4;
            case 0x101EC4u: goto label_101ec4;
            case 0x101ECCu: goto label_101ecc;
            case 0x101ED0u: goto label_101ed0;
            case 0x101ED4u: goto label_101ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
