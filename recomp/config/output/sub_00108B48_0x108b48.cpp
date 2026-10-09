#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108B48
// Address: 0x108b48 - 0x108cd0
void sub_00108B48_0x108b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108B48_0x108b48");
#endif

    switch (ctx->pc) {
        case 0x108b7cu: goto label_108b7c;
        case 0x108be4u: goto label_108be4;
        case 0x108c4cu: goto label_108c4c;
        case 0x108c98u: goto label_108c98;
        default: break;
    }

    ctx->pc = 0x108b48u;

    // 0x108b48: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x108b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x108b4c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x108b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x108b50: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x108b50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108b54: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x108b54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108b58: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x108b58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x108b5c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x108b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x108b60: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x108b60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x108b64: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x108b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x108b68: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x108b68u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108b6c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x108b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x108b70: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x108b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x108b74: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x108B74u;
    SET_GPR_U32(ctx, 31, 0x108B7Cu);
    ctx->pc = 0x108B78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108B74u;
            // 0x108b78: 0xe0a82d  daddu       $s5, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108B7Cu; }
        if (ctx->pc != 0x108B7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108B7Cu; }
        if (ctx->pc != 0x108B7Cu) { return; }
    }
    ctx->pc = 0x108B7Cu;
label_108b7c:
    // 0x108b7c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x108b7cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108b80: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x108b80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x108b84: 0x10203f  dsra32      $a0, $s0, 0
    ctx->pc = 0x108b84u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x108b88: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x108b88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x108b8c: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x108b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x108b90: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108b90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x108b94: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x108b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x108b98: 0x2038024  and         $s0, $s0, $v1
    ctx->pc = 0x108b98u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x108b9c: 0x3c03000f  lui         $v1, 0xF
    ctx->pc = 0x108b9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)15 << 16));
    // 0x108ba0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x108ba0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108ba4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x108ba4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x108ba8: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x108ba8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x108bac: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x108bacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x108bb0: 0x10953e  dsrl32      $s2, $s0, 20
    ctx->pc = 0x108bb0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 16) >> (32 + 20));
    // 0x108bb4: 0xafa40004  sw          $a0, 0x4($sp)
    ctx->pc = 0x108bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 4));
    // 0x108bb8: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x108BB8u;
    {
        const bool branch_taken_0x108bb8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x108BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108BB8u;
            // 0x108bbc: 0x26710014  addiu       $s1, $s3, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108bb8) {
            ctx->pc = 0x108BCCu;
            goto label_108bcc;
        }
    }
    ctx->pc = 0x108BC0u;
    // 0x108bc0: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x108bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x108bc4: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x108bc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x108bc8: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x108bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
label_108bcc:
    // 0x108bcc: 0x10283c  dsll32      $a1, $s0, 0
    ctx->pc = 0x108bccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 0));
    // 0x108bd0: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x108bd0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x108bd4: 0x10a0001a  beqz        $a1, . + 4 + (0x1A << 2)
    ctx->pc = 0x108BD4u;
    {
        const bool branch_taken_0x108bd4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x108BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108BD4u;
            // 0x108bd8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108bd4) {
            ctx->pc = 0x108C40u;
            goto label_108c40;
        }
    }
    ctx->pc = 0x108BDCu;
    // 0x108bdc: 0xc042062  jal         func_108188
    ctx->pc = 0x108BDCu;
    SET_GPR_U32(ctx, 31, 0x108BE4u);
    ctx->pc = 0x108BE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108BDCu;
            // 0x108be0: 0xafa50000  sw          $a1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108188u;
    if (runtime->hasFunction(0x108188u)) {
        auto targetFn = runtime->lookupFunction(0x108188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108BE4u; }
        if (ctx->pc != 0x108BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108188_0x108188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108BE4u; }
        if (ctx->pc != 0x108BE4u) { return; }
    }
    ctx->pc = 0x108BE4u;
label_108be4:
    // 0x108be4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x108be4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108be8: 0x10a0000b  beqz        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x108BE8u;
    {
        const bool branch_taken_0x108be8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x108BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108BE8u;
            // 0x108bec: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108be8) {
            ctx->pc = 0x108C18u;
            goto label_108c18;
        }
    }
    ctx->pc = 0x108BF0u;
    // 0x108bf0: 0x52023  negu        $a0, $a1
    ctx->pc = 0x108bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 5)));
    // 0x108bf4: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x108bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108bf8: 0x821004  sllv        $v0, $v0, $a0
    ctx->pc = 0x108bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x108bfc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x108bfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x108c00: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x108c00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x108c04: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x108c04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x108c08: 0xa21006  srlv        $v0, $v0, $a1
    ctx->pc = 0x108c08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x108c0c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x108C0Cu;
    {
        const bool branch_taken_0x108c0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108C0Cu;
            // 0x108c10: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108c0c) {
            ctx->pc = 0x108C20u;
            goto label_108c20;
        }
    }
    ctx->pc = 0x108C14u;
    // 0x108c14: 0x0  nop
    ctx->pc = 0x108c14u;
    // NOP
label_108c18:
    // 0x108c18: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x108c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108c1c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x108c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_108c20:
    // 0x108c20: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x108c20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x108c24: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x108c24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108c28: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x108c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x108c2c: 0x64100a  movz        $v0, $v1, $a0
    ctx->pc = 0x108c2cu;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x108c30: 0xae240004  sw          $a0, 0x4($s1)
    ctx->pc = 0x108c30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 4));
    // 0x108c34: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x108c34u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108c38: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x108C38u;
    {
        const bool branch_taken_0x108c38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108C38u;
            // 0x108c3c: 0xae620010  sw          $v0, 0x10($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108c38) {
            ctx->pc = 0x108C60u;
            goto label_108c60;
        }
    }
    ctx->pc = 0x108C40u;
label_108c40:
    // 0x108c40: 0x27a40004  addiu       $a0, $sp, 0x4
    ctx->pc = 0x108c40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x108c44: 0xc042062  jal         func_108188
    ctx->pc = 0x108C44u;
    SET_GPR_U32(ctx, 31, 0x108C4Cu);
    ctx->pc = 0x108C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108C44u;
            // 0x108c48: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108188u;
    if (runtime->hasFunction(0x108188u)) {
        auto targetFn = runtime->lookupFunction(0x108188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108C4Cu; }
        if (ctx->pc != 0x108C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108188_0x108188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108C4Cu; }
        if (ctx->pc != 0x108C4Cu) { return; }
    }
    ctx->pc = 0x108C4Cu;
label_108c4c:
    // 0x108c4c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x108c4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x108c50: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x108c50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x108c54: 0x24450020  addiu       $a1, $v0, 0x20
    ctx->pc = 0x108c54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x108c58: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x108c58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x108c5c: 0xae640010  sw          $a0, 0x10($s3)
    ctx->pc = 0x108c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 4));
label_108c60:
    // 0x108c60: 0x12400007  beqz        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x108C60u;
    {
        const bool branch_taken_0x108c60 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x108C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108C60u;
            // 0x108c64: 0x2451021  addu        $v0, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108c60) {
            ctx->pc = 0x108C80u;
            goto label_108c80;
        }
    }
    ctx->pc = 0x108C68u;
    // 0x108c68: 0x24030035  addiu       $v1, $zero, 0x35
    ctx->pc = 0x108c68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x108c6c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x108c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x108c70: 0x2442fbcd  addiu       $v0, $v0, -0x433
    ctx->pc = 0x108c70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966221));
    // 0x108c74: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x108C74u;
    {
        const bool branch_taken_0x108c74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108C74u;
            // 0x108c78: 0xae820000  sw          $v0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108c74) {
            ctx->pc = 0x108CA0u;
            goto label_108ca0;
        }
    }
    ctx->pc = 0x108C7Cu;
    // 0x108c7c: 0x0  nop
    ctx->pc = 0x108c7cu;
    // NOP
label_108c80:
    // 0x108c80: 0x24a3fbce  addiu       $v1, $a1, -0x432
    ctx->pc = 0x108c80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966222));
    // 0x108c84: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x108c84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x108c88: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x108c88u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
    // 0x108c8c: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x108c8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x108c90: 0xc042042  jal         func_108108
    ctx->pc = 0x108C90u;
    SET_GPR_U32(ctx, 31, 0x108C98u);
    ctx->pc = 0x108C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108C90u;
            // 0x108c94: 0x8c44fffc  lw          $a0, -0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294967292)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108108u;
    if (runtime->hasFunction(0x108108u)) {
        auto targetFn = runtime->lookupFunction(0x108108u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108C98u; }
        if (ctx->pc != 0x108C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108108_0x108108(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108C98u; }
        if (ctx->pc != 0x108C98u) { return; }
    }
    ctx->pc = 0x108C98u;
label_108c98:
    // 0x108c98: 0x101940  sll         $v1, $s0, 5
    ctx->pc = 0x108c98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x108c9c: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x108c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_108ca0:
    // 0x108ca0: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x108ca0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x108ca4: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x108ca4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108ca8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x108ca8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x108cac: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x108cacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x108cb0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x108cb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x108cb4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x108cb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x108cb8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x108cb8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x108cbc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x108cbcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x108cc0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x108cc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x108cc4: 0x3e00008  jr          $ra
    ctx->pc = 0x108CC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108CC4u;
            // 0x108cc8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108B7Cu: goto label_108b7c;
            case 0x108BCCu: goto label_108bcc;
            case 0x108BE4u: goto label_108be4;
            case 0x108C18u: goto label_108c18;
            case 0x108C20u: goto label_108c20;
            case 0x108C40u: goto label_108c40;
            case 0x108C4Cu: goto label_108c4c;
            case 0x108C60u: goto label_108c60;
            case 0x108C80u: goto label_108c80;
            case 0x108C98u: goto label_108c98;
            case 0x108CA0u: goto label_108ca0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108CCCu;
    // 0x108ccc: 0x0  nop
    ctx->pc = 0x108cccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
