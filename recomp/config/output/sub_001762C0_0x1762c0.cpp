#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001762C0
// Address: 0x1762c0 - 0x176334
void sub_001762C0_0x1762c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001762C0_0x1762c0");
#endif

    switch (ctx->pc) {
        case 0x1762e4u: goto label_1762e4;
        default: break;
    }

    ctx->pc = 0x1762c0u;

    // 0x1762c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1762c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1762c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1762c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1762c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1762c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762cc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1762ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1762d0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1762d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1762d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1762d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1762d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1762dc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1762DCu;
    SET_GPR_U32(ctx, 31, 0x1762E4u);
    ctx->pc = 0x1762E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1762DCu;
            // 0x1762e0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1762E4u; }
        if (ctx->pc != 0x1762E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1762E4u; }
        if (ctx->pc != 0x1762E4u) { return; }
    }
    ctx->pc = 0x1762E4u;
label_1762e4:
    // 0x1762e4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1762e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1762e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1762e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762ec: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1762ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1762f0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1762F0u;
    {
        const bool branch_taken_0x1762f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1762F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1762F0u;
            // 0x1762f4: 0x34a50127  ori         $a1, $a1, 0x127 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)295);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1762f0) {
            ctx->pc = 0x176318u;
            goto label_176318;
        }
    }
    ctx->pc = 0x1762F8u;
    // 0x1762f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1762f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1762fc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1762fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176300: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176300u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176304: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176304u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176308: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17630c: 0x805a704  j           func_169C10
    ctx->pc = 0x17630Cu;
    ctx->pc = 0x176310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17630Cu;
            // 0x176310: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176314u;
    // 0x176314: 0x0  nop
    ctx->pc = 0x176314u;
    // NOP
label_176318:
    // 0x176318: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x176318u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17631c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17631cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176320: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176320u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176324: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176324u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176328: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17632c: 0x805d8ce  j           func_176338
    ctx->pc = 0x17632Cu;
    ctx->pc = 0x176330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17632Cu;
            // 0x176330: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176338u;
    if (runtime->hasFunction(0x176338u)) {
        auto targetFn = runtime->lookupFunction(0x176338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176338_0x176338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176334u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
