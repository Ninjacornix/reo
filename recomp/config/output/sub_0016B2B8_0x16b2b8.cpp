#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B2B8
// Address: 0x16b2b8 - 0x16b340
void sub_0016B2B8_0x16b2b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B2B8_0x16b2b8");
#endif

    switch (ctx->pc) {
        case 0x16b2d8u: goto label_16b2d8;
        case 0x16b2ecu: goto label_16b2ec;
        case 0x16b300u: goto label_16b300;
        default: break;
    }

    ctx->pc = 0x16b2b8u;

    // 0x16b2b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16b2b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16b2bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b2bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b2c0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16b2c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b2c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b2c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b2c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b2cc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16b2ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16b2d0: 0xc05acd0  jal         func_16B340
    ctx->pc = 0x16B2D0u;
    SET_GPR_U32(ctx, 31, 0x16B2D8u);
    ctx->pc = 0x16B2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B2D0u;
            // 0x16b2d4: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B340u;
    if (runtime->hasFunction(0x16B340u)) {
        auto targetFn = runtime->lookupFunction(0x16B340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2D8u; }
        if (ctx->pc != 0x16B2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B340_0x16b340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2D8u; }
        if (ctx->pc != 0x16B2D8u) { return; }
    }
    ctx->pc = 0x16B2D8u;
label_16b2d8:
    // 0x16b2d8: 0x10520013  beq         $v0, $s2, . + 4 + (0x13 << 2)
    ctx->pc = 0x16B2D8u;
    {
        const bool branch_taken_0x16b2d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x16B2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B2D8u;
            // 0x16b2dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b2d8) {
            ctx->pc = 0x16B328u;
            goto label_16b328;
        }
    }
    ctx->pc = 0x16B2E0u;
    // 0x16b2e0: 0x8e301af4  lw          $s0, 0x1AF4($s1)
    ctx->pc = 0x16b2e0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6900)));
    // 0x16b2e4: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x16B2E4u;
    SET_GPR_U32(ctx, 31, 0x16B2ECu);
    ctx->pc = 0x16B2E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B2E4u;
            // 0x16b2e8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2ECu; }
        if (ctx->pc != 0x16B2ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2ECu; }
        if (ctx->pc != 0x16B2ECu) { return; }
    }
    ctx->pc = 0x16B2ECu;
label_16b2ec:
    // 0x16b2ec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16b2ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b2f0: 0x1452000d  bne         $v0, $s2, . + 4 + (0xD << 2)
    ctx->pc = 0x16B2F0u;
    {
        const bool branch_taken_0x16b2f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        ctx->pc = 0x16B2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B2F0u;
            // 0x16b2f4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b2f0) {
            ctx->pc = 0x16B328u;
            goto label_16b328;
        }
    }
    ctx->pc = 0x16B2F8u;
    // 0x16b2f8: 0xc05ad04  jal         func_16B410
    ctx->pc = 0x16B2F8u;
    SET_GPR_U32(ctx, 31, 0x16B300u);
    ctx->pc = 0x16B410u;
    if (runtime->hasFunction(0x16B410u)) {
        auto targetFn = runtime->lookupFunction(0x16B410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B300u; }
        if (ctx->pc != 0x16B300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B410_0x16b410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B300u; }
        if (ctx->pc != 0x16B300u) { return; }
    }
    ctx->pc = 0x16B300u;
label_16b300:
    // 0x16b300: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16B300u;
    {
        const bool branch_taken_0x16b300 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B300u;
            // 0x16b304: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b300) {
            ctx->pc = 0x16B328u;
            goto label_16b328;
        }
    }
    ctx->pc = 0x16B308u;
    // 0x16b308: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b308u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b30c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b30cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b310: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16b310u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16b314: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b314u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b318: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b31c: 0x805acec  j           func_16B3B0
    ctx->pc = 0x16B31Cu;
    ctx->pc = 0x16B320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B31Cu;
            // 0x16b320: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B3B0u;
    if (runtime->hasFunction(0x16B3B0u)) {
        auto targetFn = runtime->lookupFunction(0x16B3B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016B3B0_0x16b3b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B324u;
    // 0x16b324: 0x0  nop
    ctx->pc = 0x16b324u;
    // NOP
label_16b328:
    // 0x16b328: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b328u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b32c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b32cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b330: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b330u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b334: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b334u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b338: 0x3e00008  jr          $ra
    ctx->pc = 0x16B338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B33Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B338u;
            // 0x16b33c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B2D8u: goto label_16b2d8;
            case 0x16B2ECu: goto label_16b2ec;
            case 0x16B300u: goto label_16b300;
            case 0x16B328u: goto label_16b328;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B340u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
