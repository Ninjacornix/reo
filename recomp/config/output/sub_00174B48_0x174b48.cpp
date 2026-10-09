#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174B48
// Address: 0x174b48 - 0x174bb4
void sub_00174B48_0x174b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174B48_0x174b48");
#endif

    switch (ctx->pc) {
        case 0x174b68u: goto label_174b68;
        case 0x174b9cu: goto label_174b9c;
        default: break;
    }

    ctx->pc = 0x174b48u;

    // 0x174b48: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174b4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174b50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x174b50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174b54: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x174b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174b58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x174b58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174b5c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x174b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x174b60: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174B60u;
    SET_GPR_U32(ctx, 31, 0x174B68u);
    ctx->pc = 0x174B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174B60u;
            // 0x174b64: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174B68u; }
        if (ctx->pc != 0x174B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174B68u; }
        if (ctx->pc != 0x174B68u) { return; }
    }
    ctx->pc = 0x174B68u;
label_174b68:
    // 0x174b68: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174b68u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174b6c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x174B6Cu;
    {
        const bool branch_taken_0x174b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174B6Cu;
            // 0x174b70: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174b6c) {
            ctx->pc = 0x174B90u;
            goto label_174b90;
        }
    }
    ctx->pc = 0x174B74u;
    // 0x174b74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174b74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174b78: 0x34a50155  ori         $a1, $a1, 0x155
    ctx->pc = 0x174b78u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)341);
    // 0x174b7c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174b7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174b80: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174b80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174b84: 0x805a704  j           func_169C10
    ctx->pc = 0x174B84u;
    ctx->pc = 0x174B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174B84u;
            // 0x174b88: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x174B8Cu;
    // 0x174b8c: 0x0  nop
    ctx->pc = 0x174b8cu;
    // NOP
label_174b90:
    // 0x174b90: 0x8e242ab0  lw          $a0, 0x2AB0($s1)
    ctx->pc = 0x174b90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 10928)));
    // 0x174b94: 0xc05d2ee  jal         func_174BB8
    ctx->pc = 0x174B94u;
    SET_GPR_U32(ctx, 31, 0x174B9Cu);
    ctx->pc = 0x174B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174B94u;
            // 0x174b98: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174BB8u;
    if (runtime->hasFunction(0x174BB8u)) {
        auto targetFn = runtime->lookupFunction(0x174BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174B9Cu; }
        if (ctx->pc != 0x174B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174BB8_0x174bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174B9Cu; }
        if (ctx->pc != 0x174B9Cu) { return; }
    }
    ctx->pc = 0x174B9Cu;
label_174b9c:
    // 0x174b9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174b9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174ba0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174ba0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174ba4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174ba4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174ba8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174ba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174bac: 0x3e00008  jr          $ra
    ctx->pc = 0x174BACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174BACu;
            // 0x174bb0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174B68u: goto label_174b68;
            case 0x174B90u: goto label_174b90;
            case 0x174B9Cu: goto label_174b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174BB4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
