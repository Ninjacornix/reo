#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C170
// Address: 0x18c170 - 0x18c494
void sub_0018C170_0x18c170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C170_0x18c170");
#endif

    switch (ctx->pc) {
        case 0x18c1e4u: goto label_18c1e4;
        case 0x18c204u: goto label_18c204;
        case 0x18c210u: goto label_18c210;
        case 0x18c21cu: goto label_18c21c;
        case 0x18c234u: goto label_18c234;
        case 0x18c264u: goto label_18c264;
        case 0x18c284u: goto label_18c284;
        case 0x18c290u: goto label_18c290;
        case 0x18c2a4u: goto label_18c2a4;
        case 0x18c2bcu: goto label_18c2bc;
        case 0x18c2d8u: goto label_18c2d8;
        case 0x18c2f4u: goto label_18c2f4;
        case 0x18c308u: goto label_18c308;
        case 0x18c320u: goto label_18c320;
        case 0x18c334u: goto label_18c334;
        case 0x18c344u: goto label_18c344;
        case 0x18c358u: goto label_18c358;
        case 0x18c374u: goto label_18c374;
        case 0x18c3d8u: goto label_18c3d8;
        case 0x18c400u: goto label_18c400;
        case 0x18c454u: goto label_18c454;
        case 0x18c478u: goto label_18c478;
        default: break;
    }

    ctx->pc = 0x18c170u;

    // 0x18c170: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x18c170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x18c174: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x18c174u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x18c178: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18c178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18c17c: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x18c17cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x18c180: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18c180u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18c184: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x18c184u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18c188: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18c188u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18c18c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18c18cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18c190: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18c190u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18c194: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x18c194u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x18c198: 0x8c2341a0  lw          $v1, 0x41A0($at)
    ctx->pc = 0x18c198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x18c19c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18c19cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18c1a0: 0x649021  addu        $s2, $v1, $a0
    ctx->pc = 0x18c1a0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18c1a4: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x18c1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x18c1a8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C1A8u;
    {
        const bool branch_taken_0x18c1a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C1A8u;
            // 0x18c1ac: 0x8e500020  lw          $s0, 0x20($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c1a8) {
            ctx->pc = 0x18C1B8u;
            goto label_18c1b8;
        }
    }
    ctx->pc = 0x18C1B0u;
    // 0x18c1b0: 0x100000b2  b           . + 4 + (0xB2 << 2)
    ctx->pc = 0x18C1B0u;
    {
        const bool branch_taken_0x18c1b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C1B0u;
            // 0x18c1b4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c1b0) {
            ctx->pc = 0x18C47Cu;
            goto label_18c47c;
        }
    }
    ctx->pc = 0x18C1B8u;
label_18c1b8:
    // 0x18c1b8: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18c1b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18c1bc: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x18c1bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x18c1c0: 0x14400040  bnez        $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x18C1C0u;
    {
        const bool branch_taken_0x18c1c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18C1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C1C0u;
            // 0x18c1c4: 0x30820002  andi        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c1c0) {
            ctx->pc = 0x18C2C4u;
            goto label_18c2c4;
        }
    }
    ctx->pc = 0x18C1C8u;
    // 0x18c1c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18c1c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18c1cc: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x18c1ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x18c1d0: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x18c1d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x18c1d4: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x18C1D4u;
    {
        const bool branch_taken_0x18c1d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18C1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C1D4u;
            // 0x18c1d8: 0x30820002  andi        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c1d4) {
            ctx->pc = 0x18C244u;
            goto label_18c244;
        }
    }
    ctx->pc = 0x18C1DCu;
    // 0x18c1dc: 0xc0635b0  jal         func_18D6C0
    ctx->pc = 0x18C1DCu;
    SET_GPR_U32(ctx, 31, 0x18C1E4u);
    ctx->pc = 0x18D6C0u;
    if (runtime->hasFunction(0x18D6C0u)) {
        auto targetFn = runtime->lookupFunction(0x18D6C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C1E4u; }
        if (ctx->pc != 0x18C1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D6C0_0x18d6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C1E4u; }
        if (ctx->pc != 0x18C1E4u) { return; }
    }
    ctx->pc = 0x18C1E4u;
label_18c1e4:
    // 0x18c1e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18c1e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18c1e8: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x18c1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x18c1ec: 0xae42000c  sw          $v0, 0xC($s2)
    ctx->pc = 0x18c1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
    // 0x18c1f0: 0x8e44001c  lw          $a0, 0x1C($s2)
    ctx->pc = 0x18c1f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x18c1f4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C1F4u;
    {
        const bool branch_taken_0x18c1f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c1f4) {
            ctx->pc = 0x18C204u;
            goto label_18c204;
        }
    }
    ctx->pc = 0x18C1FCu;
    // 0x18c1fc: 0xc063724  jal         func_18DC90
    ctx->pc = 0x18C1FCu;
    SET_GPR_U32(ctx, 31, 0x18C204u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C204u; }
        if (ctx->pc != 0x18C204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C204u; }
        if (ctx->pc != 0x18C204u) { return; }
    }
    ctx->pc = 0x18C204u;
label_18c204:
    // 0x18c204: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c204u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c208: 0xc0627b4  jal         func_189ED0
    ctx->pc = 0x18C208u;
    SET_GPR_U32(ctx, 31, 0x18C210u);
    ctx->pc = 0x18C20Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C208u;
            // 0x18c20c: 0x27a50040  addiu       $a1, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189ED0u;
    if (runtime->hasFunction(0x189ED0u)) {
        auto targetFn = runtime->lookupFunction(0x189ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C210u; }
        if (ctx->pc != 0x18C210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189ED0_0x189ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C210u; }
        if (ctx->pc != 0x18C210u) { return; }
    }
    ctx->pc = 0x18C210u;
label_18c210:
    // 0x18c210: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c210u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c214: 0xc062784  jal         func_189E10
    ctx->pc = 0x18C214u;
    SET_GPR_U32(ctx, 31, 0x18C21Cu);
    ctx->pc = 0x18C218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C214u;
            // 0x18c218: 0x27a50040  addiu       $a1, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189E10u;
    if (runtime->hasFunction(0x189E10u)) {
        auto targetFn = runtime->lookupFunction(0x189E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C21Cu; }
        if (ctx->pc != 0x18C21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189E10_0x189e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C21Cu; }
        if (ctx->pc != 0x18C21Cu) { return; }
    }
    ctx->pc = 0x18C21Cu;
label_18c21c:
    // 0x18c21c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C21Cu;
    {
        const bool branch_taken_0x18c21c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18c21c) {
            ctx->pc = 0x18C22Cu;
            goto label_18c22c;
        }
    }
    ctx->pc = 0x18C224u;
    // 0x18c224: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x18C224u;
    {
        const bool branch_taken_0x18c224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C224u;
            // 0x18c228: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c224) {
            ctx->pc = 0x18C47Cu;
            goto label_18c47c;
        }
    }
    ctx->pc = 0x18C22Cu;
label_18c22c:
    // 0x18c22c: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x18C22Cu;
    SET_GPR_U32(ctx, 31, 0x18C234u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C234u; }
        if (ctx->pc != 0x18C234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C234u; }
        if (ctx->pc != 0x18C234u) { return; }
    }
    ctx->pc = 0x18C234u;
label_18c234:
    // 0x18c234: 0x8e430020  lw          $v1, 0x20($s2)
    ctx->pc = 0x18c234u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x18c238: 0x8e420024  lw          $v0, 0x24($s2)
    ctx->pc = 0x18c238u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x18c23c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x18C23Cu;
    {
        const bool branch_taken_0x18c23c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C23Cu;
            // 0x18c240: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c23c) {
            ctx->pc = 0x18C290u;
            goto label_18c290;
        }
    }
    ctx->pc = 0x18C244u;
label_18c244:
    // 0x18c244: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18C244u;
    {
        const bool branch_taken_0x18c244 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c244) {
            ctx->pc = 0x18C258u;
            goto label_18c258;
        }
    }
    ctx->pc = 0x18C24Cu;
    // 0x18c24c: 0x8e420024  lw          $v0, 0x24($s2)
    ctx->pc = 0x18c24cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x18c250: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x18C250u;
    {
        const bool branch_taken_0x18c250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C250u;
            // 0x18c254: 0x2028821  addu        $s1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c250) {
            ctx->pc = 0x18C290u;
            goto label_18c290;
        }
    }
    ctx->pc = 0x18C258u;
label_18c258:
    // 0x18c258: 0x8e440028  lw          $a0, 0x28($s2)
    ctx->pc = 0x18c258u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x18c25c: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x18C25Cu;
    SET_GPR_U32(ctx, 31, 0x18C264u);
    ctx->pc = 0x18C260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C25Cu;
            // 0x18c260: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C264u; }
        if (ctx->pc != 0x18C264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C264u; }
        if (ctx->pc != 0x18C264u) { return; }
    }
    ctx->pc = 0x18C264u;
label_18c264:
    // 0x18c264: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18c264u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c268: 0x8e450034  lw          $a1, 0x34($s2)
    ctx->pc = 0x18c268u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18c26c: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c26cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c270: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c270u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c274: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x18c274u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c278: 0x8c460014  lw          $a2, 0x14($v0)
    ctx->pc = 0x18c278u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x18c27c: 0xc062cec  jal         func_18B3B0
    ctx->pc = 0x18C27Cu;
    SET_GPR_U32(ctx, 31, 0x18C284u);
    ctx->pc = 0x18C280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C27Cu;
            // 0x18c280: 0x26480060  addiu       $t0, $s2, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 18), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B3B0u;
    if (runtime->hasFunction(0x18B3B0u)) {
        auto targetFn = runtime->lookupFunction(0x18B3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C284u; }
        if (ctx->pc != 0x18C284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B3B0_0x18b3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C284u; }
        if (ctx->pc != 0x18C284u) { return; }
    }
    ctx->pc = 0x18C284u;
label_18c284:
    // 0x18c284: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c288: 0xc062fd0  jal         func_18BF40
    ctx->pc = 0x18C288u;
    SET_GPR_U32(ctx, 31, 0x18C290u);
    ctx->pc = 0x18C28Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C288u;
            // 0x18c28c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BF40u;
    if (runtime->hasFunction(0x18BF40u)) {
        auto targetFn = runtime->lookupFunction(0x18BF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C290u; }
        if (ctx->pc != 0x18C290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BF40_0x18bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C290u; }
        if (ctx->pc != 0x18C290u) { return; }
    }
    ctx->pc = 0x18C290u;
label_18c290:
    // 0x18c290: 0x8e440038  lw          $a0, 0x38($s2)
    ctx->pc = 0x18c290u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x18c294: 0x10800037  beqz        $a0, . + 4 + (0x37 << 2)
    ctx->pc = 0x18C294u;
    {
        const bool branch_taken_0x18c294 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C294u;
            // 0x18c298: 0x26450100  addiu       $a1, $s2, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c294) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C29Cu;
    // 0x18c29c: 0xc0675cc  jal         func_19D730
    ctx->pc = 0x18C29Cu;
    SET_GPR_U32(ctx, 31, 0x18C2A4u);
    ctx->pc = 0x19D730u;
    if (runtime->hasFunction(0x19D730u)) {
        auto targetFn = runtime->lookupFunction(0x19D730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2A4u; }
        if (ctx->pc != 0x18C2A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2A4u; }
        if (ctx->pc != 0x18C2A4u) { return; }
    }
    ctx->pc = 0x18C2A4u;
label_18c2a4:
    // 0x18c2a4: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c2a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c2a8: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18c2a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c2ac: 0x8e440034  lw          $a0, 0x34($s2)
    ctx->pc = 0x18c2acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18c2b0: 0x8c450014  lw          $a1, 0x14($v0)
    ctx->pc = 0x18c2b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x18c2b4: 0xc062ea8  jal         func_18BAA0
    ctx->pc = 0x18C2B4u;
    SET_GPR_U32(ctx, 31, 0x18C2BCu);
    ctx->pc = 0x18C2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C2B4u;
            // 0x18c2b8: 0x26470080  addiu       $a3, $s2, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BAA0u;
    if (runtime->hasFunction(0x18BAA0u)) {
        auto targetFn = runtime->lookupFunction(0x18BAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2BCu; }
        if (ctx->pc != 0x18C2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BAA0_0x18baa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2BCu; }
        if (ctx->pc != 0x18C2BCu) { return; }
    }
    ctx->pc = 0x18C2BCu;
label_18c2bc:
    // 0x18c2bc: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x18C2BCu;
    {
        const bool branch_taken_0x18c2bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C2BCu;
            // 0x18c2c0: 0x8e42004c  lw          $v0, 0x4C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c2bc) {
            ctx->pc = 0x18C378u;
            goto label_18c378;
        }
    }
    ctx->pc = 0x18C2C4u;
label_18c2c4:
    // 0x18c2c4: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x18C2C4u;
    {
        const bool branch_taken_0x18c2c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c2c4) {
            ctx->pc = 0x18C328u;
            goto label_18c328;
        }
    }
    ctx->pc = 0x18C2CCu;
    // 0x18c2cc: 0x8e440028  lw          $a0, 0x28($s2)
    ctx->pc = 0x18c2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x18c2d0: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x18C2D0u;
    SET_GPR_U32(ctx, 31, 0x18C2D8u);
    ctx->pc = 0x18C2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C2D0u;
            // 0x18c2d4: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2D8u; }
        if (ctx->pc != 0x18C2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2D8u; }
        if (ctx->pc != 0x18C2D8u) { return; }
    }
    ctx->pc = 0x18C2D8u;
label_18c2d8:
    // 0x18c2d8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18c2d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c2dc: 0x8e430024  lw          $v1, 0x24($s2)
    ctx->pc = 0x18c2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
    // 0x18c2e0: 0x8e420028  lw          $v0, 0x28($s2)
    ctx->pc = 0x18c2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x18c2e4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x18c2e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c2e8: 0x2032021  addu        $a0, $s0, $v1
    ctx->pc = 0x18c2e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x18c2ec: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x18C2ECu;
    SET_GPR_U32(ctx, 31, 0x18C2F4u);
    ctx->pc = 0x18C2F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C2ECu;
            // 0x18c2f0: 0x23102  srl         $a2, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2F4u; }
        if (ctx->pc != 0x18C2F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2F4u; }
        if (ctx->pc != 0x18C2F4u) { return; }
    }
    ctx->pc = 0x18C2F4u;
label_18c2f4:
    // 0x18c2f4: 0x8e440038  lw          $a0, 0x38($s2)
    ctx->pc = 0x18c2f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x18c2f8: 0x1080001e  beqz        $a0, . + 4 + (0x1E << 2)
    ctx->pc = 0x18C2F8u;
    {
        const bool branch_taken_0x18c2f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C2FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C2F8u;
            // 0x18c2fc: 0x26450100  addiu       $a1, $s2, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c2f8) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C300u;
    // 0x18c300: 0xc0675cc  jal         func_19D730
    ctx->pc = 0x18C300u;
    SET_GPR_U32(ctx, 31, 0x18C308u);
    ctx->pc = 0x19D730u;
    if (runtime->hasFunction(0x19D730u)) {
        auto targetFn = runtime->lookupFunction(0x19D730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C308u; }
        if (ctx->pc != 0x18C308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C308u; }
        if (ctx->pc != 0x18C308u) { return; }
    }
    ctx->pc = 0x18C308u;
label_18c308:
    // 0x18c308: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c30c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18c30cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c310: 0x8e440034  lw          $a0, 0x34($s2)
    ctx->pc = 0x18c310u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18c314: 0x8c450014  lw          $a1, 0x14($v0)
    ctx->pc = 0x18c314u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x18c318: 0xc062ea8  jal         func_18BAA0
    ctx->pc = 0x18C318u;
    SET_GPR_U32(ctx, 31, 0x18C320u);
    ctx->pc = 0x18C31Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C318u;
            // 0x18c31c: 0x26470080  addiu       $a3, $s2, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BAA0u;
    if (runtime->hasFunction(0x18BAA0u)) {
        auto targetFn = runtime->lookupFunction(0x18BAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C320u; }
        if (ctx->pc != 0x18C320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BAA0_0x18baa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C320u; }
        if (ctx->pc != 0x18C320u) { return; }
    }
    ctx->pc = 0x18C320u;
label_18c320:
    // 0x18c320: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x18C320u;
    {
        const bool branch_taken_0x18c320 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18c320) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C328u;
label_18c328:
    // 0x18c328: 0x8e440028  lw          $a0, 0x28($s2)
    ctx->pc = 0x18c328u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x18c32c: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x18C32Cu;
    SET_GPR_U32(ctx, 31, 0x18C334u);
    ctx->pc = 0x18C330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C32Cu;
            // 0x18c330: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C334u; }
        if (ctx->pc != 0x18C334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C334u; }
        if (ctx->pc != 0x18C334u) { return; }
    }
    ctx->pc = 0x18C334u;
label_18c334:
    // 0x18c334: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c338: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18c338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c33c: 0xc062fd0  jal         func_18BF40
    ctx->pc = 0x18C33Cu;
    SET_GPR_U32(ctx, 31, 0x18C344u);
    ctx->pc = 0x18C340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C33Cu;
            // 0x18c340: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BF40u;
    if (runtime->hasFunction(0x18BF40u)) {
        auto targetFn = runtime->lookupFunction(0x18BF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C344u; }
        if (ctx->pc != 0x18C344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BF40_0x18bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C344u; }
        if (ctx->pc != 0x18C344u) { return; }
    }
    ctx->pc = 0x18C344u;
label_18c344:
    // 0x18c344: 0x8e440038  lw          $a0, 0x38($s2)
    ctx->pc = 0x18c344u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x18c348: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C348u;
    {
        const bool branch_taken_0x18c348 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C34Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C348u;
            // 0x18c34c: 0x26450100  addiu       $a1, $s2, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c348) {
            ctx->pc = 0x18C358u;
            goto label_18c358;
        }
    }
    ctx->pc = 0x18C350u;
    // 0x18c350: 0xc0675cc  jal         func_19D730
    ctx->pc = 0x18C350u;
    SET_GPR_U32(ctx, 31, 0x18C358u);
    ctx->pc = 0x19D730u;
    if (runtime->hasFunction(0x19D730u)) {
        auto targetFn = runtime->lookupFunction(0x19D730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C358u; }
        if (ctx->pc != 0x18C358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C358u; }
        if (ctx->pc != 0x18C358u) { return; }
    }
    ctx->pc = 0x18C358u;
label_18c358:
    // 0x18c358: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c358u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c35c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c35cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c360: 0x8e450034  lw          $a1, 0x34($s2)
    ctx->pc = 0x18c360u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18c364: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x18c364u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c368: 0x8c460014  lw          $a2, 0x14($v0)
    ctx->pc = 0x18c368u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x18c36c: 0xc062cec  jal         func_18B3B0
    ctx->pc = 0x18C36Cu;
    SET_GPR_U32(ctx, 31, 0x18C374u);
    ctx->pc = 0x18C370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C36Cu;
            // 0x18c370: 0x26480060  addiu       $t0, $s2, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 18), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B3B0u;
    if (runtime->hasFunction(0x18B3B0u)) {
        auto targetFn = runtime->lookupFunction(0x18B3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C374u; }
        if (ctx->pc != 0x18C374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B3B0_0x18b3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C374u; }
        if (ctx->pc != 0x18C374u) { return; }
    }
    ctx->pc = 0x18C374u;
label_18c374:
    // 0x18c374: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c378:
    // 0x18c378: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x18c378u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x18c37c: 0x24e7fd40  addiu       $a3, $a3, -0x2C0
    ctx->pc = 0x18c37cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294966592));
    // 0x18c380: 0x8e450034  lw          $a1, 0x34($s2)
    ctx->pc = 0x18c380u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18c384: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18c384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18c388: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x18c388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c38c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18c38cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c390: 0x8c480014  lw          $t0, 0x14($v0)
    ctx->pc = 0x18c390u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x18c394: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x18c394u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x18c398: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x18c398u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x18c39c: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x18c39cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18c3a0: 0xe83821  addu        $a3, $a3, $t0
    ctx->pc = 0x18c3a0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x18c3a4: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x18c3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18c3a8: 0x8ce30000  lw          $v1, 0x0($a3)
    ctx->pc = 0x18c3a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x18c3ac: 0x210c2  srl         $v0, $v0, 3
    ctx->pc = 0x18c3acu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 3));
    // 0x18c3b0: 0xac22fda0  sw          $v0, -0x260($at)
    ctx->pc = 0x18c3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966688), GPR_U32(ctx, 2));
    // 0x18c3b4: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x18c3b4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x18c3b8: 0x8e42004c  lw          $v0, 0x4C($s2)
    ctx->pc = 0x18c3b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c3bc: 0x2238021  addu        $s0, $s1, $v1
    ctx->pc = 0x18c3bcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x18c3c0: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x18c3c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x18c3c4: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x18c3c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x18c3c8: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x18c3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x18c3cc: 0xa31823  subu        $v1, $a1, $v1
    ctx->pc = 0x18c3ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c3d0: 0x40f809  jalr        $v0
    ctx->pc = 0x18C3D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x18C3D8u);
        ctx->pc = 0x18C3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C3D0u;
            // 0x18c3d4: 0x328c2  srl         $a1, $v1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 3), 3));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x18C3D8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C1B8u: goto label_18c1b8;
            case 0x18C1E4u: goto label_18c1e4;
            case 0x18C204u: goto label_18c204;
            case 0x18C210u: goto label_18c210;
            case 0x18C21Cu: goto label_18c21c;
            case 0x18C22Cu: goto label_18c22c;
            case 0x18C234u: goto label_18c234;
            case 0x18C244u: goto label_18c244;
            case 0x18C258u: goto label_18c258;
            case 0x18C264u: goto label_18c264;
            case 0x18C284u: goto label_18c284;
            case 0x18C290u: goto label_18c290;
            case 0x18C2A4u: goto label_18c2a4;
            case 0x18C2BCu: goto label_18c2bc;
            case 0x18C2C4u: goto label_18c2c4;
            case 0x18C2D8u: goto label_18c2d8;
            case 0x18C2F4u: goto label_18c2f4;
            case 0x18C308u: goto label_18c308;
            case 0x18C320u: goto label_18c320;
            case 0x18C328u: goto label_18c328;
            case 0x18C334u: goto label_18c334;
            case 0x18C344u: goto label_18c344;
            case 0x18C358u: goto label_18c358;
            case 0x18C374u: goto label_18c374;
            case 0x18C378u: goto label_18c378;
            case 0x18C3D8u: goto label_18c3d8;
            case 0x18C400u: goto label_18c400;
            case 0x18C454u: goto label_18c454;
            case 0x18C478u: goto label_18c478;
            case 0x18C47Cu: goto label_18c47c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x18C3D8u; }
            if (ctx->pc != 0x18C3D8u) { return; }
        }
        }
    }
    ctx->pc = 0x18C3D8u;
label_18c3d8:
    // 0x18c3d8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18c3d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c3dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18c3dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18c3e0: 0x8e430048  lw          $v1, 0x48($s2)
    ctx->pc = 0x18c3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 72)));
    // 0x18c3e4: 0x8c22fd9c  lw          $v0, -0x264($at)
    ctx->pc = 0x18c3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966684)));
    // 0x18c3e8: 0x1043001a  beq         $v0, $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x18C3E8u;
    {
        const bool branch_taken_0x18c3e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x18C3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C3E8u;
            // 0x18c3ec: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c3e8) {
            ctx->pc = 0x18C454u;
            goto label_18c454;
        }
    }
    ctx->pc = 0x18C3F0u;
    // 0x18c3f0: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x18c3f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x18c3f4: 0xac23fd9c  sw          $v1, -0x264($at)
    ctx->pc = 0x18c3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966684), GPR_U32(ctx, 3));
    // 0x18c3f8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x18C3F8u;
    SET_GPR_U32(ctx, 31, 0x18C400u);
    ctx->pc = 0x18C3FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C3F8u;
            // 0x18c3fc: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C400u; }
        if (ctx->pc != 0x18C400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C400u; }
        if (ctx->pc != 0x18C400u) { return; }
    }
    ctx->pc = 0x18C400u;
label_18c400:
    // 0x18c400: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x18c400u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x18c404: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x18c404u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
    // 0x18c408: 0x34640001  ori         $a0, $v1, 0x1
    ctx->pc = 0x18c408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
    // 0x18c40c: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x18c40cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x18c410: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x18c410u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x18c414: 0x3c03f000  lui         $v1, 0xF000
    ctx->pc = 0x18c414u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61440 << 16));
    // 0x18c418: 0x8e48004c  lw          $t0, 0x4C($s2)
    ctx->pc = 0x18c418u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x18c41c: 0x34630001  ori         $v1, $v1, 0x1
    ctx->pc = 0x18c41cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
    // 0x18c420: 0x24460020  addiu       $a2, $v0, 0x20
    ctx->pc = 0x18c420u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x18c424: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x18c424u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x18c428: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18c428u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c42c: 0x24e7f6f0  addiu       $a3, $a3, -0x910
    ctx->pc = 0x18c42cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
    // 0x18c430: 0x8d080000  lw          $t0, 0x0($t0)
    ctx->pc = 0x18c430u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x18c434: 0xac480004  sw          $t0, 0x4($v0)
    ctx->pc = 0x18c434u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 8));
    // 0x18c438: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x18c438u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x18c43c: 0xac430020  sw          $v1, 0x20($v0)
    ctx->pc = 0x18c43cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
    // 0x18c440: 0xac400024  sw          $zero, 0x24($v0)
    ctx->pc = 0x18c440u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 0));
    // 0x18c444: 0xfc400028  sd          $zero, 0x28($v0)
    ctx->pc = 0x18c444u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 0));
    // 0x18c448: 0x7c400030  sq          $zero, 0x30($v0)
    ctx->pc = 0x18c448u;
    WRITE128(ADD32(GPR_U32(ctx, 2), 48), GPR_VEC(ctx, 0));
    // 0x18c44c: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x18C44Cu;
    SET_GPR_U32(ctx, 31, 0x18C454u);
    ctx->pc = 0x18C450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C44Cu;
            // 0x18c450: 0x7c400010  sq          $zero, 0x10($v0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 2), 16), GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C454u; }
        if (ctx->pc != 0x18C454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C454u; }
        if (ctx->pc != 0x18C454u) { return; }
    }
    ctx->pc = 0x18C454u;
label_18c454:
    // 0x18c454: 0x11193c  dsll32      $v1, $s1, 4
    ctx->pc = 0x18c454u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 4));
    // 0x18c458: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x18c458u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x18c45c: 0x3193e  dsrl32      $v1, $v1, 4
    ctx->pc = 0x18c45cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
    // 0x18c460: 0x3c025000  lui         $v0, 0x5000
    ctx->pc = 0x18c460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20480 << 16));
    // 0x18c464: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x18c464u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c468: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18c468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c46c: 0x622825  or          $a1, $v1, $v0
    ctx->pc = 0x18c46cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c470: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x18C470u;
    SET_GPR_U32(ctx, 31, 0x18C478u);
    ctx->pc = 0x18C474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18C470u;
            // 0x18c474: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C478u; }
        if (ctx->pc != 0x18C478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C478u; }
        if (ctx->pc != 0x18C478u) { return; }
    }
    ctx->pc = 0x18C478u;
label_18c478:
    // 0x18c478: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18c478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18c47c:
    // 0x18c47c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18c47cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18c480: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18c480u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18c484: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18c484u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18c488: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18c488u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18c48c: 0x3e00008  jr          $ra
    ctx->pc = 0x18C48Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C48Cu;
            // 0x18c490: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C1B8u: goto label_18c1b8;
            case 0x18C1E4u: goto label_18c1e4;
            case 0x18C204u: goto label_18c204;
            case 0x18C210u: goto label_18c210;
            case 0x18C21Cu: goto label_18c21c;
            case 0x18C22Cu: goto label_18c22c;
            case 0x18C234u: goto label_18c234;
            case 0x18C244u: goto label_18c244;
            case 0x18C258u: goto label_18c258;
            case 0x18C264u: goto label_18c264;
            case 0x18C284u: goto label_18c284;
            case 0x18C290u: goto label_18c290;
            case 0x18C2A4u: goto label_18c2a4;
            case 0x18C2BCu: goto label_18c2bc;
            case 0x18C2C4u: goto label_18c2c4;
            case 0x18C2D8u: goto label_18c2d8;
            case 0x18C2F4u: goto label_18c2f4;
            case 0x18C308u: goto label_18c308;
            case 0x18C320u: goto label_18c320;
            case 0x18C328u: goto label_18c328;
            case 0x18C334u: goto label_18c334;
            case 0x18C344u: goto label_18c344;
            case 0x18C358u: goto label_18c358;
            case 0x18C374u: goto label_18c374;
            case 0x18C378u: goto label_18c378;
            case 0x18C3D8u: goto label_18c3d8;
            case 0x18C400u: goto label_18c400;
            case 0x18C454u: goto label_18c454;
            case 0x18C478u: goto label_18c478;
            case 0x18C47Cu: goto label_18c47c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C494u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
