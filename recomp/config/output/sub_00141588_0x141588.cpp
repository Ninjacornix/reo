#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141588
// Address: 0x141588 - 0x1416d0
void sub_00141588_0x141588(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141588_0x141588");
#endif

    switch (ctx->pc) {
        case 0x1415b8u: goto label_1415b8;
        case 0x141608u: goto label_141608;
        case 0x1416a4u: goto label_1416a4;
        case 0x1416b8u: goto label_1416b8;
        default: break;
    }

    ctx->pc = 0x141588u;

    // 0x141588: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141588u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14158c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x14158cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x141590: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x141590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x141594: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x141594u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141598: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x141598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x14159c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x14159cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1415a0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1415a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1415a4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1415a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1415a8: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1415a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1415ac: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1415acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1415b0: 0xc04e518  jal         func_139460
    ctx->pc = 0x1415B0u;
    SET_GPR_U32(ctx, 31, 0x1415B8u);
    ctx->pc = 0x1415B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1415B0u;
            // 0x1415b4: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1415B8u; }
        if (ctx->pc != 0x1415B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1415B8u; }
        if (ctx->pc != 0x1415B8u) { return; }
    }
    ctx->pc = 0x1415B8u;
label_1415b8:
    // 0x1415b8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1415b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1415bc: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1415bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1415c0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1415c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1415c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1415C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1415C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1415C4u;
            // 0x1415c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1415CCu;
    // 0x1415cc: 0x0  nop
    ctx->pc = 0x1415ccu;
    // NOP
    // 0x1415d0: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x1415d0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1415d4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1415d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1415d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1415D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1415DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1415D8u;
            // 0x1415dc: 0xa4820002  sh          $v0, 0x2($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1415E0u;
    // 0x1415e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1415e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1415e4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1415e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1415e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1415e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1415ec: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1415ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1415f0: 0x244249e0  addiu       $v0, $v0, 0x49E0
    ctx->pc = 0x1415f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18912));
    // 0x1415f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1415f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1415f8: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1415F8u;
    {
        const bool branch_taken_0x1415f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1415FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1415F8u;
            // 0x1415fc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1415f8) {
            ctx->pc = 0x141630u;
            goto label_141630;
        }
    }
    ctx->pc = 0x141600u;
    // 0x141600: 0x60f809  jalr        $v1
    ctx->pc = 0x141600u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x141608u);
        ctx->pc = 0x141604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141600u;
            // 0x141604: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141608u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141608u; }
            if (ctx->pc != 0x141608u) { return; }
        }
        }
    }
    ctx->pc = 0x141608u;
label_141608:
    // 0x141608: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141608u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x14160c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x14160cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x141610: 0x2444a5f4  addiu       $a0, $v0, -0x5A0C
    ctx->pc = 0x141610u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944244));
    // 0x141614: 0x2463a5f0  addiu       $v1, $v1, -0x5A10
    ctx->pc = 0x141614u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944240));
    // 0x141618: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x141618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14161c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14161Cu;
    {
        const bool branch_taken_0x14161c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14161c) {
            ctx->pc = 0x141620u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14161Cu;
            // 0x141620: 0xac900000  sw          $s0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141624u;
            goto label_141624;
        }
    }
    ctx->pc = 0x141624u;
label_141624:
    // 0x141624: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x141624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x141628: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x141628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x14162c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x14162cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_141630:
    // 0x141630: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141634: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x141634u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141638: 0x3e00008  jr          $ra
    ctx->pc = 0x141638u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14163Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141638u;
            // 0x14163c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141640u;
    // 0x141640: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141644: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x141644u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141648: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x14164c: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x14164cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x141650: 0x8e2249e8  lw          $v0, 0x49E8($s1)
    ctx->pc = 0x141650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 18920)));
    // 0x141654: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141658: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x141658u;
    {
        const bool branch_taken_0x141658 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14165Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141658u;
            // 0x14165c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141658) {
            ctx->pc = 0x1416B8u;
            goto label_1416b8;
        }
    }
    ctx->pc = 0x141660u;
    // 0x141660: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141660u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141664: 0x2442a5f0  addiu       $v0, $v0, -0x5A10
    ctx->pc = 0x141664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944240));
    // 0x141668: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x141668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14166c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x14166cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x141670: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x141670u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x141674: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x141674u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x141678: 0x1480000c  bnez        $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x141678u;
    {
        const bool branch_taken_0x141678 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x14167Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141678u;
            // 0x14167c: 0x262349e8  addiu       $v1, $s1, 0x49E8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 18920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141678) {
            ctx->pc = 0x1416ACu;
            goto label_1416ac;
        }
    }
    ctx->pc = 0x141680u;
    // 0x141680: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x141680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x141684: 0x2450a5f4  addiu       $s0, $v0, -0x5A0C
    ctx->pc = 0x141684u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944244));
    // 0x141688: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x141688u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14168c: 0x10660005  beq         $v1, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x14168Cu;
    {
        const bool branch_taken_0x14168c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        if (branch_taken_0x14168c) {
            ctx->pc = 0x1416A4u;
            goto label_1416a4;
        }
    }
    ctx->pc = 0x141694u;
    // 0x141694: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141694u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141698: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x141698u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14169c: 0xc050600  jal         func_141800
    ctx->pc = 0x14169Cu;
    SET_GPR_U32(ctx, 31, 0x1416A4u);
    ctx->pc = 0x1416A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14169Cu;
            // 0x1416a0: 0x2484dba8  addiu       $a0, $a0, -0x2458 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141800u;
    if (runtime->hasFunction(0x141800u)) {
        auto targetFn = runtime->lookupFunction(0x141800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1416A4u; }
        if (ctx->pc != 0x1416A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141800_0x141800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1416A4u; }
        if (ctx->pc != 0x1416A4u) { return; }
    }
    ctx->pc = 0x1416A4u;
label_1416a4:
    // 0x1416a4: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1416a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1416a8: 0x262349e8  addiu       $v1, $s1, 0x49E8
    ctx->pc = 0x1416a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 18920));
label_1416ac:
    // 0x1416ac: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1416acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1416b0: 0x40f809  jalr        $v0
    ctx->pc = 0x1416B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1416B8u);
        ctx->pc = 0x1416B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1416B0u;
            // 0x1416b4: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1416B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1416B8u; }
            if (ctx->pc != 0x1416B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1416B8u;
label_1416b8:
    // 0x1416b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1416b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1416bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1416bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1416c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1416c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1416c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1416C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1416C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1416C4u;
            // 0x1416c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1415B8u: goto label_1415b8;
            case 0x141608u: goto label_141608;
            case 0x141624u: goto label_141624;
            case 0x141630u: goto label_141630;
            case 0x1416A4u: goto label_1416a4;
            case 0x1416ACu: goto label_1416ac;
            case 0x1416B8u: goto label_1416b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1416CCu;
    // 0x1416cc: 0x0  nop
    ctx->pc = 0x1416ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
