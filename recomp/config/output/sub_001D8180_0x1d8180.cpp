#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8180
// Address: 0x1d8180 - 0x1d81e0
void sub_001D8180_0x1d8180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8180_0x1d8180");
#endif

    switch (ctx->pc) {
        case 0x1d8194u: goto label_1d8194;
        case 0x1d81bcu: goto label_1d81bc;
        case 0x1d81c8u: goto label_1d81c8;
        default: break;
    }

    ctx->pc = 0x1d8180u;

    // 0x1d8180: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8184: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8188: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8188u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d818c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D818Cu;
    SET_GPR_U32(ctx, 31, 0x1D8194u);
    ctx->pc = 0x1D8190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D818Cu;
            // 0x1d8190: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8194u; }
        if (ctx->pc != 0x1D8194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8194u; }
        if (ctx->pc != 0x1D8194u) { return; }
    }
    ctx->pc = 0x1D8194u;
label_1d8194:
    // 0x1d8194: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8194u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8198: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8198u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d819c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d819cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d81a0: 0x2404004a  addiu       $a0, $zero, 0x4A
    ctx->pc = 0x1d81a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 74));
    // 0x1d81a4: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d81a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d81a8: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x1d81a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1d81ac: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d81acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d81b0: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x1d81b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d81b4: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D81B4u;
    SET_GPR_U32(ctx, 31, 0x1D81BCu);
    ctx->pc = 0x1D81B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D81B4u;
            // 0x1d81b8: 0xa430729c  sh          $s0, 0x729C($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 29340), (uint16_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D81BCu; }
        if (ctx->pc != 0x1D81BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D81BCu; }
        if (ctx->pc != 0x1D81BCu) { return; }
    }
    ctx->pc = 0x1D81BCu;
label_1d81bc:
    // 0x1d81bc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d81bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d81c0: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D81C0u;
    SET_GPR_U32(ctx, 31, 0x1D81C8u);
    ctx->pc = 0x1D81C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D81C0u;
            // 0x1d81c4: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D81C8u; }
        if (ctx->pc != 0x1D81C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D81C8u; }
        if (ctx->pc != 0x1D81C8u) { return; }
    }
    ctx->pc = 0x1D81C8u;
label_1d81c8:
    // 0x1d81c8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d81c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d81cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d81ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d81d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d81d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d81d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D81D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D81D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D81D4u;
            // 0x1d81d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8194u: goto label_1d8194;
            case 0x1D81BCu: goto label_1d81bc;
            case 0x1D81C8u: goto label_1d81c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D81DCu;
    // 0x1d81dc: 0x0  nop
    ctx->pc = 0x1d81dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
