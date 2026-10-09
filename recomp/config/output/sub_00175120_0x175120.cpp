#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175120
// Address: 0x175120 - 0x175210
void sub_00175120_0x175120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175120_0x175120");
#endif

    switch (ctx->pc) {
        case 0x175150u: goto label_175150;
        case 0x175188u: goto label_175188;
        default: break;
    }

    ctx->pc = 0x175120u;

    // 0x175120: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x175120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x175124: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175128: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x175128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17512c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17512cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175130: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x175130u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x175134: 0x26540d2c  addiu       $s4, $s2, 0xD2C
    ctx->pc = 0x175134u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), 3372));
    // 0x175138: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17513c: 0x26512ab4  addiu       $s1, $s2, 0x2AB4
    ctx->pc = 0x17513cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 10932));
    // 0x175140: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x175140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x175144: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x175144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x175148: 0xc059f74  jal         func_167DD0
    ctx->pc = 0x175148u;
    SET_GPR_U32(ctx, 31, 0x175150u);
    ctx->pc = 0x17514Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175148u;
            // 0x17514c: 0x8e502ab0  lw          $s0, 0x2AB0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 10928)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167DD0u;
    if (runtime->hasFunction(0x167DD0u)) {
        auto targetFn = runtime->lookupFunction(0x167DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175150u; }
        if (ctx->pc != 0x175150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DD0_0x167dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175150u; }
        if (ctx->pc != 0x175150u) { return; }
    }
    ctx->pc = 0x175150u;
label_175150:
    // 0x175150: 0x54400028  bnel        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x175150u;
    {
        const bool branch_taken_0x175150 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x175150) {
            ctx->pc = 0x175154u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175150u;
            // 0x175154: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1751F4u;
            goto label_1751f4;
        }
    }
    ctx->pc = 0x175158u;
    // 0x175158: 0x8e020d98  lw          $v0, 0xD98($s0)
    ctx->pc = 0x175158u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3480)));
    // 0x17515c: 0x1c400010  bgtz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x17515Cu;
    {
        const bool branch_taken_0x17515c = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x175160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17515Cu;
            // 0x175160: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17515c) {
            ctx->pc = 0x1751A0u;
            goto label_1751a0;
        }
    }
    ctx->pc = 0x175164u;
    // 0x175164: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x175164u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x175168: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x175168u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x17516c: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17516Cu;
    {
        const bool branch_taken_0x17516c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x175170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17516Cu;
            // 0x175170: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17516c) {
            ctx->pc = 0x175178u;
            goto label_175178;
        }
    }
    ctx->pc = 0x175174u;
    // 0x175174: 0x8e110dc0  lw          $s1, 0xDC0($s0)
    ctx->pc = 0x175174u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3520)));
label_175178:
    // 0x175178: 0x622000a  bltzl       $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x175178u;
    {
        const bool branch_taken_0x175178 = (GPR_S64(ctx, 17) < 0);
        if (branch_taken_0x175178) {
            ctx->pc = 0x17517Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175178u;
            // 0x17517c: 0x8e020d9c  lw          $v0, 0xD9C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3484)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1751A4u;
            goto label_1751a4;
        }
    }
    ctx->pc = 0x175180u;
    // 0x175180: 0xc05d484  jal         func_175210
    ctx->pc = 0x175180u;
    SET_GPR_U32(ctx, 31, 0x175188u);
    ctx->pc = 0x175184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175180u;
            // 0x175184: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175210u;
    if (runtime->hasFunction(0x175210u)) {
        auto targetFn = runtime->lookupFunction(0x175210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175188u; }
        if (ctx->pc != 0x175188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175210_0x175210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175188u; }
        if (ctx->pc != 0x175188u) { return; }
    }
    ctx->pc = 0x175188u;
label_175188:
    // 0x175188: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x175188u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17518c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17518cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x175190: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x175190u;
    {
        const bool branch_taken_0x175190 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x175194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175190u;
            // 0x175194: 0x2231021  addu        $v0, $s1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175190) {
            ctx->pc = 0x1751A0u;
            goto label_1751a0;
        }
    }
    ctx->pc = 0x175198u;
    // 0x175198: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x175198u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17519c: 0xae020d98  sw          $v0, 0xD98($s0)
    ctx->pc = 0x17519cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3480), GPR_U32(ctx, 2));
label_1751a0:
    // 0x1751a0: 0x8e020d9c  lw          $v0, 0xD9C($s0)
    ctx->pc = 0x1751a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 3484)));
label_1751a4:
    // 0x1751a4: 0x1c400008  bgtz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1751A4u;
    {
        const bool branch_taken_0x1751a4 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1751a4) {
            ctx->pc = 0x1751C8u;
            goto label_1751c8;
        }
    }
    ctx->pc = 0x1751ACu;
    // 0x1751ac: 0x8e820020  lw          $v0, 0x20($s4)
    ctx->pc = 0x1751acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 32)));
    // 0x1751b0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1751B0u;
    {
        const bool branch_taken_0x1751b0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1751b0) {
            ctx->pc = 0x1751C8u;
            goto label_1751c8;
        }
    }
    ctx->pc = 0x1751B8u;
    // 0x1751b8: 0xae020d9c  sw          $v0, 0xD9C($s0)
    ctx->pc = 0x1751b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3484), GPR_U32(ctx, 2));
    // 0x1751bc: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1751bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1751c0: 0x8e820024  lw          $v0, 0x24($s4)
    ctx->pc = 0x1751c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 36)));
    // 0x1751c4: 0xae020da0  sw          $v0, 0xDA0($s0)
    ctx->pc = 0x1751c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 3488), GPR_U32(ctx, 2));
label_1751c8:
    // 0x1751c8: 0x12600009  beqz        $s3, . + 4 + (0x9 << 2)
    ctx->pc = 0x1751C8u;
    {
        const bool branch_taken_0x1751c8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1751CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1751C8u;
            // 0x1751cc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1751c8) {
            ctx->pc = 0x1751F0u;
            goto label_1751f0;
        }
    }
    ctx->pc = 0x1751D0u;
    // 0x1751d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1751d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1751d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1751d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1751d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1751d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1751dc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1751dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1751e0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1751e0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1751e4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1751e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1751e8: 0x805d496  j           func_175258
    ctx->pc = 0x1751E8u;
    ctx->pc = 0x1751ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1751E8u;
            // 0x1751ec: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175258u;
    if (runtime->hasFunction(0x175258u)) {
        auto targetFn = runtime->lookupFunction(0x175258u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175258_0x175258(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1751F0u;
label_1751f0:
    // 0x1751f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1751f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1751f4:
    // 0x1751f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1751f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1751f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1751f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1751fc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1751fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175200: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x175200u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x175204: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x175204u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x175208: 0x3e00008  jr          $ra
    ctx->pc = 0x175208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17520Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175208u;
            // 0x17520c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175150u: goto label_175150;
            case 0x175178u: goto label_175178;
            case 0x175188u: goto label_175188;
            case 0x1751A0u: goto label_1751a0;
            case 0x1751A4u: goto label_1751a4;
            case 0x1751C8u: goto label_1751c8;
            case 0x1751F0u: goto label_1751f0;
            case 0x1751F4u: goto label_1751f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175210u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
