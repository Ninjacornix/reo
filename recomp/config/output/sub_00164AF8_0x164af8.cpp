#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164AF8
// Address: 0x164af8 - 0x164b70
void sub_00164AF8_0x164af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164AF8_0x164af8");
#endif

    switch (ctx->pc) {
        case 0x164b28u: goto label_164b28;
        case 0x164b4cu: goto label_164b4c;
        case 0x164b58u: goto label_164b58;
        default: break;
    }

    ctx->pc = 0x164af8u;

    // 0x164af8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x164af8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x164afc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x164afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x164b00: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x164b00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b04: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x164b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x164b08: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164b08u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b0c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x164b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x164b10: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x164b10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b14: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x164b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x164b18: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x164b18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x164b1c: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x164b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x164b20: 0xc05955e  jal         func_165578
    ctx->pc = 0x164B20u;
    SET_GPR_U32(ctx, 31, 0x164B28u);
    ctx->pc = 0x164B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164B20u;
            // 0x164b24: 0x8e111b74  lw          $s1, 0x1B74($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165578u;
    if (runtime->hasFunction(0x165578u)) {
        auto targetFn = runtime->lookupFunction(0x165578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164B28u; }
        if (ctx->pc != 0x164B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165578_0x165578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164B28u; }
        if (ctx->pc != 0x164B28u) { return; }
    }
    ctx->pc = 0x164B28u;
label_164b28:
    // 0x164b28: 0x27a70008  addiu       $a3, $sp, 0x8
    ctx->pc = 0x164b28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x164b2c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x164B2Cu;
    {
        const bool branch_taken_0x164b2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x164B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164B2Cu;
            // 0x164b30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164b2c) {
            ctx->pc = 0x164B58u;
            goto label_164b58;
        }
    }
    ctx->pc = 0x164B34u;
    // 0x164b34: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x164b34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x164b38: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x164b38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164b3c: 0x8e23003c  lw          $v1, 0x3C($s1)
    ctx->pc = 0x164b3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x164b40: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x164b40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b44: 0x60f809  jalr        $v1
    ctx->pc = 0x164B44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x164B4Cu);
        ctx->pc = 0x164B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164B44u;
            // 0x164b48: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x164B4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164B28u: goto label_164b28;
            case 0x164B4Cu: goto label_164b4c;
            case 0x164B58u: goto label_164b58;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x164B4Cu; }
            if (ctx->pc != 0x164B4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x164B4Cu;
label_164b4c:
    // 0x164b4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164b4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164b50: 0xc059570  jal         func_1655C0
    ctx->pc = 0x164B50u;
    SET_GPR_U32(ctx, 31, 0x164B58u);
    ctx->pc = 0x164B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164B50u;
            // 0x164b54: 0x8fa50008  lw          $a1, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1655C0u;
    if (runtime->hasFunction(0x1655C0u)) {
        auto targetFn = runtime->lookupFunction(0x1655C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164B58u; }
        if (ctx->pc != 0x164B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001655C0_0x1655c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164B58u; }
        if (ctx->pc != 0x164B58u) { return; }
    }
    ctx->pc = 0x164B58u;
label_164b58:
    // 0x164b58: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x164b58u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164b5c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x164b5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164b60: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x164b60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x164b64: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x164b64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x164b68: 0x3e00008  jr          $ra
    ctx->pc = 0x164B68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164B68u;
            // 0x164b6c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164B28u: goto label_164b28;
            case 0x164B4Cu: goto label_164b4c;
            case 0x164B58u: goto label_164b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164B70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
