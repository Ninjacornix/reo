#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176FA0
// Address: 0x176fa0 - 0x177024
void sub_00176FA0_0x176fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176FA0_0x176fa0");
#endif

    switch (ctx->pc) {
        case 0x176fc4u: goto label_176fc4;
        default: break;
    }

    ctx->pc = 0x176fa0u;

    // 0x176fa0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176fa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176fa4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176fa8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x176fa8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176fac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176facu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176fb0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x176fb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176fb4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x176fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x176fb8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x176fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x176fbc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x176FBCu;
    SET_GPR_U32(ctx, 31, 0x176FC4u);
    ctx->pc = 0x176FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176FBCu;
            // 0x176fc0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176FC4u; }
        if (ctx->pc != 0x176FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176FC4u; }
        if (ctx->pc != 0x176FC4u) { return; }
    }
    ctx->pc = 0x176FC4u;
label_176fc4:
    // 0x176fc4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x176fc4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x176fc8: 0x26060cc0  addiu       $a2, $s0, 0xCC0
    ctx->pc = 0x176fc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x176fcc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x176fccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176fd0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x176FD0u;
    {
        const bool branch_taken_0x176fd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176FD0u;
            // 0x176fd4: 0x34a50125  ori         $a1, $a1, 0x125 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)293);
        ctx->in_delay_slot = false;
        if (branch_taken_0x176fd0) {
            ctx->pc = 0x176FF0u;
            goto label_176ff0;
        }
    }
    ctx->pc = 0x176FD8u;
    // 0x176fd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176fd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176fdc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176fdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176fe0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x176fe0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176fe4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x176fe4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x176fe8: 0x805a704  j           func_169C10
    ctx->pc = 0x176FE8u;
    ctx->pc = 0x176FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176FE8u;
            // 0x176fec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176FF0u;
label_176ff0:
    // 0x176ff0: 0x8cc3026c  lw          $v1, 0x26C($a2)
    ctx->pc = 0x176ff0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 620)));
    // 0x176ff4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x176ff4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x176ff8: 0xacd10274  sw          $s1, 0x274($a2)
    ctx->pc = 0x176ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 628), GPR_U32(ctx, 17));
    // 0x176ffc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x176ffcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x177000: 0xacd20270  sw          $s2, 0x270($a2)
    ctx->pc = 0x177000u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 624), GPR_U32(ctx, 18));
    // 0x177004: 0xacc3026c  sw          $v1, 0x26C($a2)
    ctx->pc = 0x177004u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 620), GPR_U32(ctx, 3));
    // 0x177008: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177008u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17700c: 0xae040044  sw          $a0, 0x44($s0)
    ctx->pc = 0x17700cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x177010: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177010u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177014: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177014u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177018: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x177018u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17701c: 0x3e00008  jr          $ra
    ctx->pc = 0x17701Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17701Cu;
            // 0x177020: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176FC4u: goto label_176fc4;
            case 0x176FF0u: goto label_176ff0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177024u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
