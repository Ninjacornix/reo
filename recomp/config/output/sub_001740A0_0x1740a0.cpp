#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001740A0
// Address: 0x1740a0 - 0x174100
void sub_001740A0_0x1740a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001740A0_0x1740a0");
#endif

    switch (ctx->pc) {
        case 0x1740bcu: goto label_1740bc;
        default: break;
    }

    ctx->pc = 0x1740a0u;

    // 0x1740a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1740a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1740a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1740a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1740a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1740a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1740ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1740acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1740b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1740b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1740b4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1740B4u;
    SET_GPR_U32(ctx, 31, 0x1740BCu);
    ctx->pc = 0x1740B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1740B4u;
            // 0x1740b8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1740BCu; }
        if (ctx->pc != 0x1740BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1740BCu; }
        if (ctx->pc != 0x1740BCu) { return; }
    }
    ctx->pc = 0x1740BCu;
label_1740bc:
    // 0x1740bc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1740bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1740c0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1740C0u;
    {
        const bool branch_taken_0x1740c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1740C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1740C0u;
            // 0x1740c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1740c0) {
            ctx->pc = 0x1740E0u;
            goto label_1740e0;
        }
    }
    ctx->pc = 0x1740C8u;
    // 0x1740c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1740c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1740cc: 0x34a50139  ori         $a1, $a1, 0x139
    ctx->pc = 0x1740ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)313);
    // 0x1740d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1740d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1740d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1740d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1740d8: 0x805a704  j           func_169C10
    ctx->pc = 0x1740D8u;
    ctx->pc = 0x1740DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1740D8u;
            // 0x1740dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1740E0u;
label_1740e0:
    // 0x1740e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1740e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1740e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1740e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1740e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1740e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1740ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1740ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1740f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1740f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1740f4: 0x8059b42  j           func_166D08
    ctx->pc = 0x1740F4u;
    ctx->pc = 0x1740F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1740F4u;
            // 0x1740f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166D08u;
    if (runtime->hasFunction(0x166D08u)) {
        auto targetFn = runtime->lookupFunction(0x166D08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166D08_0x166d08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1740FCu;
    // 0x1740fc: 0x0  nop
    ctx->pc = 0x1740fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
