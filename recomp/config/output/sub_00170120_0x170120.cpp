#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170120
// Address: 0x170120 - 0x1701f0
void sub_00170120_0x170120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170120_0x170120");
#endif

    switch (ctx->pc) {
        case 0x170148u: goto label_170148;
        case 0x170190u: goto label_170190;
        case 0x1701ccu: goto label_1701cc;
        default: break;
    }

    ctx->pc = 0x170120u;

    // 0x170120: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x170120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x170124: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170128: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x170128u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17012c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17012cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170130: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x170130u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170134: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x170134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x170138: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x170138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17013c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17013cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x170140: 0xc05c07c  jal         func_1701F0
    ctx->pc = 0x170140u;
    SET_GPR_U32(ctx, 31, 0x170148u);
    ctx->pc = 0x170144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170140u;
            // 0x170144: 0x8e331b30  lw          $s3, 0x1B30($s1) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6960)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1701F0u;
    if (runtime->hasFunction(0x1701F0u)) {
        auto targetFn = runtime->lookupFunction(0x1701F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170148u; }
        if (ctx->pc != 0x170148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001701F0_0x1701f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170148u; }
        if (ctx->pc != 0x170148u) { return; }
    }
    ctx->pc = 0x170148u;
label_170148:
    // 0x170148: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x170148u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17014c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17014cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x170150: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x170150u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x170154: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x170154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170158: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x170158u;
    {
        const bool branch_taken_0x170158 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17015Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170158u;
            // 0x17015c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170158) {
            ctx->pc = 0x170188u;
            goto label_170188;
        }
    }
    ctx->pc = 0x170160u;
    // 0x170160: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x170160u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x170164: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170164u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170168: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170168u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17016c: 0x34a50f0e  ori         $a1, $a1, 0xF0E
    ctx->pc = 0x17016cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3854);
    // 0x170170: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x170170u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170174: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x170174u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170178: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x170178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17017c: 0x805a704  j           func_169C10
    ctx->pc = 0x17017Cu;
    ctx->pc = 0x170180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17017Cu;
            // 0x170180: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x170184u;
    // 0x170184: 0x0  nop
    ctx->pc = 0x170184u;
    // NOP
label_170188:
    // 0x170188: 0xc05c134  jal         func_1704D0
    ctx->pc = 0x170188u;
    SET_GPR_U32(ctx, 31, 0x170190u);
    ctx->pc = 0x1704D0u;
    if (runtime->hasFunction(0x1704D0u)) {
        auto targetFn = runtime->lookupFunction(0x1704D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170190u; }
        if (ctx->pc != 0x170190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001704D0_0x1704d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170190u; }
        if (ctx->pc != 0x170190u) { return; }
    }
    ctx->pc = 0x170190u;
label_170190:
    // 0x170190: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x170190u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x170194: 0x8e630070  lw          $v1, 0x70($s3)
    ctx->pc = 0x170194u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 112)));
    // 0x170198: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x170198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17019c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17019Cu;
    {
        const bool branch_taken_0x17019c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1701A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17019Cu;
            // 0x1701a0: 0x34a50f0f  ori         $a1, $a1, 0xF0F (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3855);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17019c) {
            ctx->pc = 0x1701C0u;
            goto label_1701c0;
        }
    }
    ctx->pc = 0x1701A4u;
    // 0x1701a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1701a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1701a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1701a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1701ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1701acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1701b0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1701b0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1701b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1701b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1701b8: 0x805a704  j           func_169C10
    ctx->pc = 0x1701B8u;
    ctx->pc = 0x1701BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1701B8u;
            // 0x1701bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1701C0u;
label_1701c0:
    // 0x1701c0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1701c0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1701c4: 0xc05c1c4  jal         func_170710
    ctx->pc = 0x1701C4u;
    SET_GPR_U32(ctx, 31, 0x1701CCu);
    ctx->pc = 0x1701C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1701C4u;
            // 0x1701c8: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170710u;
    if (runtime->hasFunction(0x170710u)) {
        auto targetFn = runtime->lookupFunction(0x170710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1701CCu; }
        if (ctx->pc != 0x1701CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170710_0x170710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1701CCu; }
        if (ctx->pc != 0x1701CCu) { return; }
    }
    ctx->pc = 0x1701CCu;
label_1701cc:
    // 0x1701cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1701ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1701d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1701d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1701d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1701d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1701d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1701d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1701dc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1701dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1701e0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1701e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1701e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1701E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1701E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1701E4u;
            // 0x1701e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170148u: goto label_170148;
            case 0x170188u: goto label_170188;
            case 0x170190u: goto label_170190;
            case 0x1701C0u: goto label_1701c0;
            case 0x1701CCu: goto label_1701cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1701ECu;
    // 0x1701ec: 0x0  nop
    ctx->pc = 0x1701ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
