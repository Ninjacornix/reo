#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016ACA8
// Address: 0x16aca8 - 0x16ad80
void sub_0016ACA8_0x16aca8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016ACA8_0x16aca8");
#endif

    switch (ctx->pc) {
        case 0x16acfcu: goto label_16acfc;
        case 0x16ad28u: goto label_16ad28;
        case 0x16ad48u: goto label_16ad48;
        case 0x16ad58u: goto label_16ad58;
        default: break;
    }

    ctx->pc = 0x16aca8u;

    // 0x16aca8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16aca8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16acac: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x16acacu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16acb0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16acb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16acb4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16acb4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16acb8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16acb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16acbc: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x16acbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16acc0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16acc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16acc4: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x16acc4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16acc8: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16acc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16accc: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x16acccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16acd0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16acd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16acd4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16acd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16acd8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16acd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16acdc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16acdcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ace0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16ace0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16ace4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ace4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ace8: 0x8ea31b00  lw          $v1, 0x1B00($s5)
    ctx->pc = 0x16ace8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 6912)));
    // 0x16acec: 0x1068001b  beq         $v1, $t0, . + 4 + (0x1B << 2)
    ctx->pc = 0x16ACECu;
    {
        const bool branch_taken_0x16acec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 8));
        ctx->pc = 0x16ACF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16ACECu;
            // 0x16acf0: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16acec) {
            ctx->pc = 0x16AD5Cu;
            goto label_16ad5c;
        }
    }
    ctx->pc = 0x16ACF4u;
    // 0x16acf4: 0xc059bd8  jal         func_166F60
    ctx->pc = 0x16ACF4u;
    SET_GPR_U32(ctx, 31, 0x16ACFCu);
    ctx->pc = 0x166F60u;
    if (runtime->hasFunction(0x166F60u)) {
        auto targetFn = runtime->lookupFunction(0x166F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ACFCu; }
        if (ctx->pc != 0x16ACFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F60_0x166f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ACFCu; }
        if (ctx->pc != 0x16ACFCu) { return; }
    }
    ctx->pc = 0x16ACFCu;
label_16acfc:
    // 0x16acfc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16acfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad00: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x16ad00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ad04: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x16ad04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad08: 0x8fb20004  lw          $s2, 0x4($sp)
    ctx->pc = 0x16ad08u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16ad0c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ad0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ad10: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x16ad10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad14: 0x8fb30008  lw          $s3, 0x8($sp)
    ctx->pc = 0x16ad14u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16ad18: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x16AD18u;
    {
        const bool branch_taken_0x16ad18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD18u;
            // 0x16ad1c: 0x8fb4000c  lw          $s4, 0xC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ad18) {
            ctx->pc = 0x16AD5Cu;
            goto label_16ad5c;
        }
    }
    ctx->pc = 0x16AD20u;
    // 0x16ad20: 0xc05ab60  jal         func_16AD80
    ctx->pc = 0x16AD20u;
    SET_GPR_U32(ctx, 31, 0x16AD28u);
    ctx->pc = 0x16AD80u;
    if (runtime->hasFunction(0x16AD80u)) {
        auto targetFn = runtime->lookupFunction(0x16AD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AD28u; }
        if (ctx->pc != 0x16AD28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AD80_0x16ad80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AD28u; }
        if (ctx->pc != 0x16AD28u) { return; }
    }
    ctx->pc = 0x16AD28u;
label_16ad28:
    // 0x16ad28: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16ad28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ad2c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ad2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ad30: 0x5622000a  bnel        $s1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16AD30u;
    {
        const bool branch_taken_0x16ad30 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x16ad30) {
            ctx->pc = 0x16AD34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD30u;
            // 0x16ad34: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AD5Cu;
            goto label_16ad5c;
        }
    }
    ctx->pc = 0x16AD38u;
    // 0x16ad38: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x16AD38u;
    {
        const bool branch_taken_0x16ad38 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD38u;
            // 0x16ad3c: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ad38) {
            ctx->pc = 0x16AD48u;
            goto label_16ad48;
        }
    }
    ctx->pc = 0x16AD40u;
    // 0x16ad40: 0x240f809  jalr        $s2
    ctx->pc = 0x16AD40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 18);
        SET_GPR_U32(ctx, 31, 0x16AD48u);
        ctx->pc = 0x16AD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD40u;
            // 0x16ad44: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16AD48u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ACFCu: goto label_16acfc;
            case 0x16AD28u: goto label_16ad28;
            case 0x16AD48u: goto label_16ad48;
            case 0x16AD58u: goto label_16ad58;
            case 0x16AD5Cu: goto label_16ad5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16AD48u; }
            if (ctx->pc != 0x16AD48u) { return; }
        }
        }
    }
    ctx->pc = 0x16AD48u;
label_16ad48:
    // 0x16ad48: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x16AD48u;
    {
        const bool branch_taken_0x16ad48 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD48u;
            // 0x16ad4c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ad48) {
            ctx->pc = 0x16AD58u;
            goto label_16ad58;
        }
    }
    ctx->pc = 0x16AD50u;
    // 0x16ad50: 0x260f809  jalr        $s3
    ctx->pc = 0x16AD50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 19);
        SET_GPR_U32(ctx, 31, 0x16AD58u);
        ctx->pc = 0x16AD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD50u;
            // 0x16ad54: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16AD58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ACFCu: goto label_16acfc;
            case 0x16AD28u: goto label_16ad28;
            case 0x16AD48u: goto label_16ad48;
            case 0x16AD58u: goto label_16ad58;
            case 0x16AD5Cu: goto label_16ad5c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16AD58u; }
            if (ctx->pc != 0x16AD58u) { return; }
        }
        }
    }
    ctx->pc = 0x16AD58u;
label_16ad58:
    // 0x16ad58: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x16ad58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16ad5c:
    // 0x16ad5c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16ad5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ad60: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16ad60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ad64: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16ad64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ad68: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16ad68u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ad6c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16ad6cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ad70: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16ad70u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16ad74: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16ad74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16ad78: 0x3e00008  jr          $ra
    ctx->pc = 0x16AD78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AD78u;
            // 0x16ad7c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16ACFCu: goto label_16acfc;
            case 0x16AD28u: goto label_16ad28;
            case 0x16AD48u: goto label_16ad48;
            case 0x16AD58u: goto label_16ad58;
            case 0x16AD5Cu: goto label_16ad5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AD80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
