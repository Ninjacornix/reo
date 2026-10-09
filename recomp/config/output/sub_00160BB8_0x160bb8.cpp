#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160BB8
// Address: 0x160bb8 - 0x160c30
void sub_00160BB8_0x160bb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160BB8_0x160bb8");
#endif

    switch (ctx->pc) {
        case 0x160be0u: goto label_160be0;
        case 0x160bf0u: goto label_160bf0;
        case 0x160bfcu: goto label_160bfc;
        case 0x160c0cu: goto label_160c0c;
        default: break;
    }

    ctx->pc = 0x160bb8u;

    // 0x160bb8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160bb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x160bbc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160bc0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x160bc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160bc4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160bc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160bc8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x160bc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160bcc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x160bccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x160bd0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x160bd0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160bd4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x160bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x160bd8: 0xc05830c  jal         func_160C30
    ctx->pc = 0x160BD8u;
    SET_GPR_U32(ctx, 31, 0x160BE0u);
    ctx->pc = 0x160BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160BD8u;
            // 0x160bdc: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160C30u;
    if (runtime->hasFunction(0x160C30u)) {
        auto targetFn = runtime->lookupFunction(0x160C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BE0u; }
        if (ctx->pc != 0x160BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160C30_0x160c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BE0u; }
        if (ctx->pc != 0x160BE0u) { return; }
    }
    ctx->pc = 0x160BE0u;
label_160be0:
    // 0x160be0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x160be0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160be4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x160be4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x160be8: 0xc058324  jal         func_160C90
    ctx->pc = 0x160BE8u;
    SET_GPR_U32(ctx, 31, 0x160BF0u);
    ctx->pc = 0x160BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160BE8u;
            // 0x160bec: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160C90u;
    if (runtime->hasFunction(0x160C90u)) {
        auto targetFn = runtime->lookupFunction(0x160C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BF0u; }
        if (ctx->pc != 0x160BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160C90_0x160c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BF0u; }
        if (ctx->pc != 0x160BF0u) { return; }
    }
    ctx->pc = 0x160BF0u;
label_160bf0:
    // 0x160bf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x160bf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160bf4: 0xc058352  jal         func_160D48
    ctx->pc = 0x160BF4u;
    SET_GPR_U32(ctx, 31, 0x160BFCu);
    ctx->pc = 0x160BF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160BF4u;
            // 0x160bf8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D48u;
    if (runtime->hasFunction(0x160D48u)) {
        auto targetFn = runtime->lookupFunction(0x160D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BFCu; }
        if (ctx->pc != 0x160BFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D48_0x160d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160BFCu; }
        if (ctx->pc != 0x160BFCu) { return; }
    }
    ctx->pc = 0x160BFCu;
label_160bfc:
    // 0x160bfc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x160bfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c00: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x160c00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c04: 0xc05835a  jal         func_160D68
    ctx->pc = 0x160C04u;
    SET_GPR_U32(ctx, 31, 0x160C0Cu);
    ctx->pc = 0x160C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160C04u;
            // 0x160c08: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160D68u;
    if (runtime->hasFunction(0x160D68u)) {
        auto targetFn = runtime->lookupFunction(0x160D68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160C0Cu; }
        if (ctx->pc != 0x160C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160D68_0x160d68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160C0Cu; }
        if (ctx->pc != 0x160C0Cu) { return; }
    }
    ctx->pc = 0x160C0Cu;
label_160c0c:
    // 0x160c0c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x160c0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c10: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x160c10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160c14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160c14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160c18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160c18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160c1c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160c1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160c20: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160c20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160c24: 0x805836c  j           func_160DB0
    ctx->pc = 0x160C24u;
    ctx->pc = 0x160C28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160C24u;
            // 0x160c28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160DB0u;
    if (runtime->hasFunction(0x160DB0u)) {
        auto targetFn = runtime->lookupFunction(0x160DB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00160DB0_0x160db0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160C2Cu;
    // 0x160c2c: 0x0  nop
    ctx->pc = 0x160c2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
