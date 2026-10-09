#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165B48
// Address: 0x165b48 - 0x165c04
void sub_00165B48_0x165b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165B48_0x165b48");
#endif

    switch (ctx->pc) {
        case 0x165b84u: goto label_165b84;
        case 0x165bacu: goto label_165bac;
        default: break;
    }

    ctx->pc = 0x165b48u;

    // 0x165b48: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x165b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x165b4c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x165b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x165b50: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x165b50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165b54: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x165b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x165b58: 0x26130f60  addiu       $s3, $s0, 0xF60
    ctx->pc = 0x165b58u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 3936));
    // 0x165b5c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x165b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x165b60: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x165b60u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165b64: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x165b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x165b68: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x165b68u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165b6c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x165b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x165b70: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x165b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x165b74: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x165b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x165b78: 0x8e111b74  lw          $s1, 0x1B74($s0)
    ctx->pc = 0x165b78u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7028)));
    // 0x165b7c: 0xc05d99c  jal         func_176670
    ctx->pc = 0x165B7Cu;
    SET_GPR_U32(ctx, 31, 0x165B84u);
    ctx->pc = 0x165B80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165B7Cu;
            // 0x165b80: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165B84u; }
        if (ctx->pc != 0x165B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165B84u; }
        if (ctx->pc != 0x165B84u) { return; }
    }
    ctx->pc = 0x165B84u;
label_165b84:
    // 0x165b84: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x165B84u;
    {
        const bool branch_taken_0x165b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x165B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165B84u;
            // 0x165b88: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165b84) {
            ctx->pc = 0x165BE0u;
            goto label_165be0;
        }
    }
    ctx->pc = 0x165B8Cu;
    // 0x165b8c: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x165b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x165b90: 0x5443000f  bnel        $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x165B90u;
    {
        const bool branch_taken_0x165b90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x165b90) {
            ctx->pc = 0x165B94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165B90u;
            // 0x165b94: 0x8e240024  lw          $a0, 0x24($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x165BD0u;
            goto label_165bd0;
        }
    }
    ctx->pc = 0x165B98u;
    // 0x165b98: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x165b98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165b9c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x165b9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ba0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x165ba0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ba4: 0xc059702  jal         func_165C08
    ctx->pc = 0x165BA4u;
    SET_GPR_U32(ctx, 31, 0x165BACu);
    ctx->pc = 0x165BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165BA4u;
            // 0x165ba8: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165C08u;
    if (runtime->hasFunction(0x165C08u)) {
        auto targetFn = runtime->lookupFunction(0x165C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165BACu; }
        if (ctx->pc != 0x165BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165C08_0x165c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165BACu; }
        if (ctx->pc != 0x165BACu) { return; }
    }
    ctx->pc = 0x165BACu;
label_165bac:
    // 0x165bac: 0x8e240024  lw          $a0, 0x24($s1)
    ctx->pc = 0x165bacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x165bb0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x165bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165bb4: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x165bb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x165bb8: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x165BB8u;
    {
        const bool branch_taken_0x165bb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x165bb8) {
            ctx->pc = 0x165BBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165BB8u;
            // 0x165bbc: 0xae840000  sw          $a0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x165BD4u;
            goto label_165bd4;
        }
    }
    ctx->pc = 0x165BC0u;
    // 0x165bc0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x165bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x165bc4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x165bc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165bc8: 0xae230024  sw          $v1, 0x24($s1)
    ctx->pc = 0x165bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 3));
    // 0x165bcc: 0xae220028  sw          $v0, 0x28($s1)
    ctx->pc = 0x165bccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 2));
label_165bd0:
    // 0x165bd0: 0xae840000  sw          $a0, 0x0($s4)
    ctx->pc = 0x165bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 4));
label_165bd4:
    // 0x165bd4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165bd4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165bd8: 0x8e230028  lw          $v1, 0x28($s1)
    ctx->pc = 0x165bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x165bdc: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x165bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
label_165be0:
    // 0x165be0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x165be0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165be4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x165be4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165be8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x165be8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165bec: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x165becu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x165bf0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x165bf0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x165bf4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x165bf4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x165bf8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x165bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x165bfc: 0x3e00008  jr          $ra
    ctx->pc = 0x165BFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165BFCu;
            // 0x165c00: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165B84u: goto label_165b84;
            case 0x165BACu: goto label_165bac;
            case 0x165BD0u: goto label_165bd0;
            case 0x165BD4u: goto label_165bd4;
            case 0x165BE0u: goto label_165be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165C04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
