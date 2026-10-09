#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137558
// Address: 0x137558 - 0x137608
void sub_00137558_0x137558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137558_0x137558");
#endif

    switch (ctx->pc) {
        case 0x137594u: goto label_137594;
        case 0x1375e0u: goto label_1375e0;
        default: break;
    }

    ctx->pc = 0x137558u;

    // 0x137558: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x137558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13755c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13755cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137560: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x137560u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137564: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x137564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x137568: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x137568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13756c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13756cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x137570: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x137570u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137574: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x137574u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x137578: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x137578u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13757c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13757cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x137580: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x137580u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137584: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x137584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x137588: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x137588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13758c: 0xc0505c0  jal         func_141700
    ctx->pc = 0x13758Cu;
    SET_GPR_U32(ctx, 31, 0x137594u);
    ctx->pc = 0x137590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13758Cu;
            // 0x137590: 0xc0a82d  daddu       $s5, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137594u; }
        if (ctx->pc != 0x137594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137594u; }
        if (ctx->pc != 0x137594u) { return; }
    }
    ctx->pc = 0x137594u;
label_137594:
    // 0x137594: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x137594u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x137598: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x137598u;
    {
        const bool branch_taken_0x137598 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13759Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137598u;
            // 0x13759c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137598) {
            ctx->pc = 0x1375B0u;
            goto label_1375b0;
        }
    }
    ctx->pc = 0x1375A0u;
    // 0x1375a0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1375A0u;
    {
        const bool branch_taken_0x1375a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1375A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1375A0u;
            // 0x1375a4: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1375a0) {
            ctx->pc = 0x1375B0u;
            goto label_1375b0;
        }
    }
    ctx->pc = 0x1375A8u;
    // 0x1375a8: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1375A8u;
    {
        const bool branch_taken_0x1375a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1375a8) {
            ctx->pc = 0x1375D8u;
            goto label_1375d8;
        }
    }
    ctx->pc = 0x1375B0u;
label_1375b0:
    // 0x1375b0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1375b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1375b4: 0xae120030  sw          $s2, 0x30($s0)
    ctx->pc = 0x1375b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 18));
    // 0x1375b8: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1375b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1375bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1375bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1375c0: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1375c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1375c4: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x1375c4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1375c8: 0xae110018  sw          $s1, 0x18($s0)
    ctx->pc = 0x1375c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 17));
    // 0x1375cc: 0xfe130020  sd          $s3, 0x20($s0)
    ctx->pc = 0x1375ccu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 32), GPR_U64(ctx, 19));
    // 0x1375d0: 0xfe150028  sd          $s5, 0x28($s0)
    ctx->pc = 0x1375d0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 40), GPR_U64(ctx, 21));
    // 0x1375d4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1375d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_1375d8:
    // 0x1375d8: 0xc0505de  jal         func_141778
    ctx->pc = 0x1375D8u;
    SET_GPR_U32(ctx, 31, 0x1375E0u);
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1375E0u; }
        if (ctx->pc != 0x1375E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141778_0x141778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1375E0u; }
        if (ctx->pc != 0x1375E0u) { return; }
    }
    ctx->pc = 0x1375E0u;
label_1375e0:
    // 0x1375e0: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x1375e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1375e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1375e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1375e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1375e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1375ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1375ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1375f0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1375f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1375f4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1375f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1375f8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1375f8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1375fc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1375fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x137600: 0x3e00008  jr          $ra
    ctx->pc = 0x137600u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137600u;
            // 0x137604: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137594u: goto label_137594;
            case 0x1375B0u: goto label_1375b0;
            case 0x1375D8u: goto label_1375d8;
            case 0x1375E0u: goto label_1375e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137608u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
