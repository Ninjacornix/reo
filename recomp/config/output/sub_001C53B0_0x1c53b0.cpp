#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C53B0
// Address: 0x1c53b0 - 0x1c5410
void sub_001C53B0_0x1c53b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C53B0_0x1c53b0");
#endif

    switch (ctx->pc) {
        case 0x1c53dcu: goto label_1c53dc;
        case 0x1c53f8u: goto label_1c53f8;
        default: break;
    }

    ctx->pc = 0x1c53b0u;

    // 0x1c53b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c53b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c53b4: 0x3c010002  lui         $at, 0x2
    ctx->pc = 0x1c53b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)2 << 16));
    // 0x1c53b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c53b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c53bc: 0x3c050036  lui         $a1, 0x36
    ctx->pc = 0x1c53bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
    // 0x1c53c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c53c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c53c4: 0x3421fbc0  ori         $at, $at, 0xFBC0
    ctx->pc = 0x1c53c4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)64448);
    // 0x1c53c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c53c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c53cc: 0x24a5f080  addiu       $a1, $a1, -0xF80
    ctx->pc = 0x1c53ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963328));
    // 0x1c53d0: 0x2012021  addu        $a0, $s0, $at
    ctx->pc = 0x1c53d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
    // 0x1c53d4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C53D4u;
    SET_GPR_U32(ctx, 31, 0x1C53DCu);
    ctx->pc = 0x1C53D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C53D4u;
            // 0x1c53d8: 0x34068000  ori         $a2, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C53DCu; }
        if (ctx->pc != 0x1C53DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C53DCu; }
        if (ctx->pc != 0x1C53DCu) { return; }
    }
    ctx->pc = 0x1C53DCu;
label_1c53dc:
    // 0x1c53dc: 0x3c010003  lui         $at, 0x3
    ctx->pc = 0x1c53dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)3 << 16));
    // 0x1c53e0: 0x3c050037  lui         $a1, 0x37
    ctx->pc = 0x1c53e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)55 << 16));
    // 0x1c53e4: 0x34217bc0  ori         $at, $at, 0x7BC0
    ctx->pc = 0x1c53e4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)31680);
    // 0x1c53e8: 0x24a5f080  addiu       $a1, $a1, -0xF80
    ctx->pc = 0x1c53e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963328));
    // 0x1c53ec: 0x2012021  addu        $a0, $s0, $at
    ctx->pc = 0x1c53ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
    // 0x1c53f0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C53F0u;
    SET_GPR_U32(ctx, 31, 0x1C53F8u);
    ctx->pc = 0x1C53F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C53F0u;
            // 0x1c53f4: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C53F8u; }
        if (ctx->pc != 0x1C53F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C53F8u; }
        if (ctx->pc != 0x1C53F8u) { return; }
    }
    ctx->pc = 0x1C53F8u;
label_1c53f8:
    // 0x1c53f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c53f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c53fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c53fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5400: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5400u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5400u;
            // 0x1c5404: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C53DCu: goto label_1c53dc;
            case 0x1C53F8u: goto label_1c53f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5408u;
    // 0x1c5408: 0x0  nop
    ctx->pc = 0x1c5408u;
    // NOP
    // 0x1c540c: 0x0  nop
    ctx->pc = 0x1c540cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
