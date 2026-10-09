#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174C28
// Address: 0x174c28 - 0x174cc8
void sub_00174C28_0x174c28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174C28_0x174c28");
#endif

    switch (ctx->pc) {
        case 0x174c5cu: goto label_174c5c;
        case 0x174c74u: goto label_174c74;
        case 0x174c88u: goto label_174c88;
        case 0x174ca8u: goto label_174ca8;
        default: break;
    }

    ctx->pc = 0x174c28u;

    // 0x174c28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x174c28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x174c2c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x174c2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c30: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x174c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x174c34: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x174c34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c38: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x174c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x174c3c: 0x24502ab0  addiu       $s0, $v0, 0x2AB0
    ctx->pc = 0x174c3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 10928));
    // 0x174c40: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x174c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x174c44: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x174c44u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c48: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x174c48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x174c4c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x174c4cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c50: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x174c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x174c54: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174C54u;
    SET_GPR_U32(ctx, 31, 0x174C5Cu);
    ctx->pc = 0x174C58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174C54u;
            // 0x174c58: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C5Cu; }
        if (ctx->pc != 0x174C5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C5Cu; }
        if (ctx->pc != 0x174C5Cu) { return; }
    }
    ctx->pc = 0x174C5Cu;
label_174c5c:
    // 0x174c5c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x174c5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c60: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174C60u;
    {
        const bool branch_taken_0x174c60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174C60u;
            // 0x174c64: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174c60) {
            ctx->pc = 0x174C80u;
            goto label_174c80;
        }
    }
    ctx->pc = 0x174C68u;
    // 0x174c68: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x174c68u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174c6c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x174C6Cu;
    SET_GPR_U32(ctx, 31, 0x174C74u);
    ctx->pc = 0x174C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174C6Cu;
            // 0x174c70: 0x34a50156  ori         $a1, $a1, 0x156 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)342);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C74u; }
        if (ctx->pc != 0x174C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C74u; }
        if (ctx->pc != 0x174C74u) { return; }
    }
    ctx->pc = 0x174C74u;
label_174c74:
    // 0x174c74: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x174C74u;
    {
        const bool branch_taken_0x174c74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x174C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174C74u;
            // 0x174c78: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174c74) {
            ctx->pc = 0x174CB0u;
            goto label_174cb0;
        }
    }
    ctx->pc = 0x174C7Cu;
    // 0x174c7c: 0x0  nop
    ctx->pc = 0x174c7cu;
    // NOP
label_174c80:
    // 0x174c80: 0xc05d2ee  jal         func_174BB8
    ctx->pc = 0x174C80u;
    SET_GPR_U32(ctx, 31, 0x174C88u);
    ctx->pc = 0x174C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174C80u;
            // 0x174c84: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174BB8u;
    if (runtime->hasFunction(0x174BB8u)) {
        auto targetFn = runtime->lookupFunction(0x174BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C88u; }
        if (ctx->pc != 0x174C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174BB8_0x174bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174C88u; }
        if (ctx->pc != 0x174C88u) { return; }
    }
    ctx->pc = 0x174C88u;
label_174c88:
    // 0x174c88: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x174c88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c8c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x174c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x174c90: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x174c90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c94: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x174c94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174c98: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x174C98u;
    {
        const bool branch_taken_0x174c98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x174C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174C98u;
            // 0x174c9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174c98) {
            ctx->pc = 0x174CACu;
            goto label_174cac;
        }
    }
    ctx->pc = 0x174CA0u;
    // 0x174ca0: 0xc05d332  jal         func_174CC8
    ctx->pc = 0x174CA0u;
    SET_GPR_U32(ctx, 31, 0x174CA8u);
    ctx->pc = 0x174CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174CA0u;
            // 0x174ca4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174CC8u;
    if (runtime->hasFunction(0x174CC8u)) {
        auto targetFn = runtime->lookupFunction(0x174CC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174CA8u; }
        if (ctx->pc != 0x174CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174CC8_0x174cc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x174CA8u; }
        if (ctx->pc != 0x174CA8u) { return; }
    }
    ctx->pc = 0x174CA8u;
label_174ca8:
    // 0x174ca8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174ca8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_174cac:
    // 0x174cac: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x174cacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_174cb0:
    // 0x174cb0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x174cb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x174cb4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x174cb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x174cb8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x174cb8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x174cbc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x174cbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x174cc0: 0x3e00008  jr          $ra
    ctx->pc = 0x174CC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x174CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174CC0u;
            // 0x174cc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x174C5Cu: goto label_174c5c;
            case 0x174C74u: goto label_174c74;
            case 0x174C80u: goto label_174c80;
            case 0x174C88u: goto label_174c88;
            case 0x174CA8u: goto label_174ca8;
            case 0x174CACu: goto label_174cac;
            case 0x174CB0u: goto label_174cb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174CC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
