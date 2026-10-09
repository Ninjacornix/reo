#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176198
// Address: 0x176198 - 0x176210
void sub_00176198_0x176198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176198_0x176198");
#endif

    switch (ctx->pc) {
        case 0x1761bcu: goto label_1761bc;
        default: break;
    }

    ctx->pc = 0x176198u;

    // 0x176198: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17619c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17619cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1761a0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1761a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1761a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1761a8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1761a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1761acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1761b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1761b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1761b4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1761B4u;
    SET_GPR_U32(ctx, 31, 0x1761BCu);
    ctx->pc = 0x1761B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1761B4u;
            // 0x1761b8: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1761BCu; }
        if (ctx->pc != 0x1761BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1761BCu; }
        if (ctx->pc != 0x1761BCu) { return; }
    }
    ctx->pc = 0x1761BCu;
label_1761bc:
    // 0x1761bc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1761bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1761c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1761c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761c4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1761c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761c8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1761C8u;
    {
        const bool branch_taken_0x1761c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1761CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1761C8u;
            // 0x1761cc: 0x34a50121  ori         $a1, $a1, 0x121 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)289);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1761c8) {
            ctx->pc = 0x1761F0u;
            goto label_1761f0;
        }
    }
    ctx->pc = 0x1761D0u;
    // 0x1761d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1761d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1761d4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1761d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1761d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1761dc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1761dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1761e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1761e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1761e4: 0x805a704  j           func_169C10
    ctx->pc = 0x1761E4u;
    ctx->pc = 0x1761E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1761E4u;
            // 0x1761e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1761ECu;
    // 0x1761ec: 0x0  nop
    ctx->pc = 0x1761ecu;
    // NOP
label_1761f0:
    // 0x1761f0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1761f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1761f4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1761f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1761f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1761f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1761fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1761fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176200: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176200u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176204: 0x805d884  j           func_176210
    ctx->pc = 0x176204u;
    ctx->pc = 0x176208u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176204u;
            // 0x176208: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176210u;
    if (runtime->hasFunction(0x176210u)) {
        auto targetFn = runtime->lookupFunction(0x176210u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176210_0x176210(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17620Cu;
    // 0x17620c: 0x0  nop
    ctx->pc = 0x17620cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
