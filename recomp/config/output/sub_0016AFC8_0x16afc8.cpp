#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016AFC8
// Address: 0x16afc8 - 0x16b040
void sub_0016AFC8_0x16afc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016AFC8_0x16afc8");
#endif

    switch (ctx->pc) {
        case 0x16affcu: goto label_16affc;
        case 0x16b00cu: goto label_16b00c;
        case 0x16b01cu: goto label_16b01c;
        default: break;
    }

    ctx->pc = 0x16afc8u;

    // 0x16afc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16afc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16afcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16afccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16afd0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16afd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16afd4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16afd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16afd8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16afd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16afdc: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16afdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16afe0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16afe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16afe4: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x16afe4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16afe8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16afe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16afec: 0x26301ae4  addiu       $s0, $s1, 0x1AE4
    ctx->pc = 0x16afecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 6884));
    // 0x16aff0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16aff0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aff4: 0xc059f38  jal         func_167CE0
    ctx->pc = 0x16AFF4u;
    SET_GPR_U32(ctx, 31, 0x16AFFCu);
    ctx->pc = 0x16AFF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AFF4u;
            // 0x16aff8: 0x8e050018  lw          $a1, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CE0u;
    if (runtime->hasFunction(0x167CE0u)) {
        auto targetFn = runtime->lookupFunction(0x167CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AFFCu; }
        if (ctx->pc != 0x16AFFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CE0_0x167ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AFFCu; }
        if (ctx->pc != 0x16AFFCu) { return; }
    }
    ctx->pc = 0x16AFFCu;
label_16affc:
    // 0x16affc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16affcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b000: 0x8e050014  lw          $a1, 0x14($s0)
    ctx->pc = 0x16b000u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16b004: 0xc059f38  jal         func_167CE0
    ctx->pc = 0x16B004u;
    SET_GPR_U32(ctx, 31, 0x16B00Cu);
    ctx->pc = 0x16B008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B004u;
            // 0x16b008: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CE0u;
    if (runtime->hasFunction(0x167CE0u)) {
        auto targetFn = runtime->lookupFunction(0x167CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B00Cu; }
        if (ctx->pc != 0x16B00Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CE0_0x167ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B00Cu; }
        if (ctx->pc != 0x16B00Cu) { return; }
    }
    ctx->pc = 0x16B00Cu;
label_16b00c:
    // 0x16b00c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16b00cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b010: 0x8e05001c  lw          $a1, 0x1C($s0)
    ctx->pc = 0x16b010u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16b014: 0xc059f38  jal         func_167CE0
    ctx->pc = 0x16B014u;
    SET_GPR_U32(ctx, 31, 0x16B01Cu);
    ctx->pc = 0x16B018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B014u;
            // 0x16b018: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CE0u;
    if (runtime->hasFunction(0x167CE0u)) {
        auto targetFn = runtime->lookupFunction(0x167CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B01Cu; }
        if (ctx->pc != 0x16B01Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CE0_0x167ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B01Cu; }
        if (ctx->pc != 0x16B01Cu) { return; }
    }
    ctx->pc = 0x16B01Cu;
label_16b01c:
    // 0x16b01c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16b01cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b020: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16b020u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b024: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16b024u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b028: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b028u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b02c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b02cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b030: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b030u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b034: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16b034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16b038: 0x805c6e6  j           func_171B98
    ctx->pc = 0x16B038u;
    ctx->pc = 0x16B03Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B038u;
            // 0x16b03c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171B98u;
    if (runtime->hasFunction(0x171B98u)) {
        auto targetFn = runtime->lookupFunction(0x171B98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00171B98_0x171b98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
