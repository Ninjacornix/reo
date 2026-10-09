#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BE38
// Address: 0x15be38 - 0x15bef0
void sub_0015BE38_0x15be38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BE38_0x15be38");
#endif

    switch (ctx->pc) {
        case 0x15be64u: goto label_15be64;
        case 0x15be74u: goto label_15be74;
        case 0x15be84u: goto label_15be84;
        case 0x15be8cu: goto label_15be8c;
        default: break;
    }

    ctx->pc = 0x15be38u;

    // 0x15be38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x15be38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x15be3c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15be3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15be40: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x15be40u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x15be44: 0x27a70008  addiu       $a3, $sp, 0x8
    ctx->pc = 0x15be44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x15be48: 0x27a8000c  addiu       $t0, $sp, 0xC
    ctx->pc = 0x15be48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x15be4c: 0x27a90010  addiu       $t1, $sp, 0x10
    ctx->pc = 0x15be4cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x15be50: 0x27aa0014  addiu       $t2, $sp, 0x14
    ctx->pc = 0x15be50u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    // 0x15be54: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x15be54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x15be58: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x15be58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x15be5c: 0xc056ee8  jal         func_15BBA0
    ctx->pc = 0x15BE5Cu;
    SET_GPR_U32(ctx, 31, 0x15BE64u);
    ctx->pc = 0x15BE60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE5Cu;
            // 0x15be60: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BBA0u;
    if (runtime->hasFunction(0x15BBA0u)) {
        auto targetFn = runtime->lookupFunction(0x15BBA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE64u; }
        if (ctx->pc != 0x15BE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BBA0_0x15bba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE64u; }
        if (ctx->pc != 0x15BE64u) { return; }
    }
    ctx->pc = 0x15BE64u;
label_15be64:
    // 0x15be64: 0x27a50018  addiu       $a1, $sp, 0x18
    ctx->pc = 0x15be64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x15be68: 0x27a6001c  addiu       $a2, $sp, 0x1C
    ctx->pc = 0x15be68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
    // 0x15be6c: 0xc056f36  jal         func_15BCD8
    ctx->pc = 0x15BE6Cu;
    SET_GPR_U32(ctx, 31, 0x15BE74u);
    ctx->pc = 0x15BE70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE6Cu;
            // 0x15be70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BCD8u;
    if (runtime->hasFunction(0x15BCD8u)) {
        auto targetFn = runtime->lookupFunction(0x15BCD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE74u; }
        if (ctx->pc != 0x15BE74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BCD8_0x15bcd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE74u; }
        if (ctx->pc != 0x15BE74u) { return; }
    }
    ctx->pc = 0x15BE74u;
label_15be74:
    // 0x15be74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15be74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15be78: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x15be78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x15be7c: 0xc056f84  jal         func_15BE10
    ctx->pc = 0x15BE7Cu;
    SET_GPR_U32(ctx, 31, 0x15BE84u);
    ctx->pc = 0x15BE80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE7Cu;
            // 0x15be80: 0x27a60024  addiu       $a2, $sp, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BE10u;
    if (runtime->hasFunction(0x15BE10u)) {
        auto targetFn = runtime->lookupFunction(0x15BE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE84u; }
        if (ctx->pc != 0x15BE84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BE10_0x15be10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE84u; }
        if (ctx->pc != 0x15BE84u) { return; }
    }
    ctx->pc = 0x15BE84u;
label_15be84:
    // 0x15be84: 0xc056f8c  jal         func_15BE30
    ctx->pc = 0x15BE84u;
    SET_GPR_U32(ctx, 31, 0x15BE8Cu);
    ctx->pc = 0x15BE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BE84u;
            // 0x15be88: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BE30u;
    if (runtime->hasFunction(0x15BE30u)) {
        auto targetFn = runtime->lookupFunction(0x15BE30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE8Cu; }
        if (ctx->pc != 0x15BE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BE30_0x15be30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BE8Cu; }
        if (ctx->pc != 0x15BE8Cu) { return; }
    }
    ctx->pc = 0x15BE8Cu;
label_15be8c:
    // 0x15be8c: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x15be8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15be90: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x15be90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15be94: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x15be94u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x15be98: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x15be98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x15be9c: 0x8fa40018  lw          $a0, 0x18($sp)
    ctx->pc = 0x15be9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15bea0: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x15bea0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15bea4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x15bea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x15bea8: 0x8fa80010  lw          $t0, 0x10($sp)
    ctx->pc = 0x15bea8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15beac: 0x24630040  addiu       $v1, $v1, 0x40
    ctx->pc = 0x15beacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
    // 0x15beb0: 0x8fa5001c  lw          $a1, 0x1C($sp)
    ctx->pc = 0x15beb0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x15beb4: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x15beb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x15beb8: 0x8fa70014  lw          $a3, 0x14($sp)
    ctx->pc = 0x15beb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15bebc: 0xc83021  addu        $a2, $a2, $t0
    ctx->pc = 0x15bebcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x15bec0: 0x24840040  addiu       $a0, $a0, 0x40
    ctx->pc = 0x15bec0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
    // 0x15bec4: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x15bec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x15bec8: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x15bec8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x15becc: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x15beccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15bed0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x15bed0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x15bed4: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x15bed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15bed8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x15bed8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x15bedc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x15bedcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x15bee0: 0x24620800  addiu       $v0, $v1, 0x800
    ctx->pc = 0x15bee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2048));
    // 0x15bee4: 0x3e00008  jr          $ra
    ctx->pc = 0x15BEE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BEE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BEE4u;
            // 0x15bee8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BE64u: goto label_15be64;
            case 0x15BE74u: goto label_15be74;
            case 0x15BE84u: goto label_15be84;
            case 0x15BE8Cu: goto label_15be8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BEECu;
    // 0x15beec: 0x0  nop
    ctx->pc = 0x15beecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
