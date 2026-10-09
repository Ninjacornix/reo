#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B288
// Address: 0x17b288 - 0x17b360
void sub_0017B288_0x17b288(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B288_0x17b288");
#endif

    switch (ctx->pc) {
        case 0x17b2d4u: goto label_17b2d4;
        case 0x17b32cu: goto label_17b32c;
        case 0x17b344u: goto label_17b344;
        default: break;
    }

    ctx->pc = 0x17b288u;

    // 0x17b288: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b28c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b28cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b290: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17b290u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b294: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b298: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17b298u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17b29c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b29cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b2a0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17b2a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2a4: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b2a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b2a8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17b2a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2ac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17b2acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17b2b0: 0xafa60010  sw          $a2, 0x10($sp)
    ctx->pc = 0x17b2b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    // 0x17b2b4: 0x8e050044  lw          $a1, 0x44($s0)
    ctx->pc = 0x17b2b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17b2b8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b2bc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x17b2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17b2c0: 0xafa50014  sw          $a1, 0x14($sp)
    ctx->pc = 0x17b2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x17b2c4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b2c8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17b2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17b2cc: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17B2CCu;
    SET_GPR_U32(ctx, 31, 0x17B2D4u);
    ctx->pc = 0x17B2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2CCu;
            // 0x17b2d0: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B2D4u; }
        if (ctx->pc != 0x17B2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B2D4u; }
        if (ctx->pc != 0x17B2D4u) { return; }
    }
    ctx->pc = 0x17B2D4u;
label_17b2d4:
    // 0x17b2d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b2d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b2d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b2d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2dc: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x17b2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b2e0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17B2E0u;
    {
        const bool branch_taken_0x17b2e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17B2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2E0u;
            // 0x17b2e4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b2e0) {
            ctx->pc = 0x17B300u;
            goto label_17b300;
        }
    }
    ctx->pc = 0x17B2E8u;
    // 0x17b2e8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b2ec: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17b2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17b2f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17b2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17b2f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17B2F4u;
    {
        const bool branch_taken_0x17b2f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2F4u;
            // 0x17b2f8: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b2f4) {
            ctx->pc = 0x17B304u;
            goto label_17b304;
        }
    }
    ctx->pc = 0x17B2FCu;
    // 0x17b2fc: 0x0  nop
    ctx->pc = 0x17b2fcu;
    // NOP
label_17b300:
    // 0x17b300: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_17b304:
    // 0x17b304: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b304u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b308: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17b308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17b30c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17B30Cu;
    {
        const bool branch_taken_0x17b30c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b30c) {
            ctx->pc = 0x17B31Cu;
            goto label_17b31c;
        }
    }
    ctx->pc = 0x17B314u;
    // 0x17b314: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17b314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17b318: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b318u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_17b31c:
    // 0x17b31c: 0x16660006  bne         $s3, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B31Cu;
    {
        const bool branch_taken_0x17b31c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 6));
        ctx->pc = 0x17B320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B31Cu;
            // 0x17b320: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b31c) {
            ctx->pc = 0x17B338u;
            goto label_17b338;
        }
    }
    ctx->pc = 0x17B324u;
    // 0x17b324: 0xc053dfa  jal         func_14F7E8
    ctx->pc = 0x17B324u;
    SET_GPR_U32(ctx, 31, 0x17B32Cu);
    ctx->pc = 0x17B328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B324u;
            // 0x17b328: 0x8e46003c  lw          $a2, 0x3C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7E8u;
    if (runtime->hasFunction(0x14F7E8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B32Cu; }
        if (ctx->pc != 0x17B32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7E8_0x14f7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B32Cu; }
        if (ctx->pc != 0x17B32Cu) { return; }
    }
    ctx->pc = 0x17B32Cu;
label_17b32c:
    // 0x17b32c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x17B32Cu;
    {
        const bool branch_taken_0x17b32c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B32Cu;
            // 0x17b330: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b32c) {
            ctx->pc = 0x17B348u;
            goto label_17b348;
        }
    }
    ctx->pc = 0x17B334u;
    // 0x17b334: 0x0  nop
    ctx->pc = 0x17b334u;
    // NOP
label_17b338:
    // 0x17b338: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b338u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b33c: 0xc053df2  jal         func_14F7C8
    ctx->pc = 0x17B33Cu;
    SET_GPR_U32(ctx, 31, 0x17B344u);
    ctx->pc = 0x17B340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B33Cu;
            // 0x17b340: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7C8u;
    if (runtime->hasFunction(0x14F7C8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B344u; }
        if (ctx->pc != 0x17B344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7C8_0x14f7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B344u; }
        if (ctx->pc != 0x17B344u) { return; }
    }
    ctx->pc = 0x17B344u;
label_17b344:
    // 0x17b344: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17b344u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_17b348:
    // 0x17b348: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17b348u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17b34c: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17b34cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b350: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17b350u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b354: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17b354u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b358: 0x3e00008  jr          $ra
    ctx->pc = 0x17B358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B358u;
            // 0x17b35c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B2D4u: goto label_17b2d4;
            case 0x17B300u: goto label_17b300;
            case 0x17B304u: goto label_17b304;
            case 0x17B31Cu: goto label_17b31c;
            case 0x17B32Cu: goto label_17b32c;
            case 0x17B338u: goto label_17b338;
            case 0x17B344u: goto label_17b344;
            case 0x17B348u: goto label_17b348;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B360u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
