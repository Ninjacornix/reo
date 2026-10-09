#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C4390
// Address: 0x1c4390 - 0x1c4970
void sub_001C4390_0x1c4390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C4390_0x1c4390");
#endif

    switch (ctx->pc) {
        case 0x1c441cu: goto label_1c441c;
        case 0x1c444cu: goto label_1c444c;
        case 0x1c4468u: goto label_1c4468;
        case 0x1c44b8u: goto label_1c44b8;
        case 0x1c4508u: goto label_1c4508;
        case 0x1c4510u: goto label_1c4510;
        case 0x1c451cu: goto label_1c451c;
        case 0x1c453cu: goto label_1c453c;
        case 0x1c455cu: goto label_1c455c;
        case 0x1c4568u: goto label_1c4568;
        case 0x1c45e8u: goto label_1c45e8;
        case 0x1c4608u: goto label_1c4608;
        case 0x1c4678u: goto label_1c4678;
        case 0x1c46d8u: goto label_1c46d8;
        case 0x1c4710u: goto label_1c4710;
        case 0x1c4718u: goto label_1c4718;
        case 0x1c47a4u: goto label_1c47a4;
        case 0x1c47e0u: goto label_1c47e0;
        case 0x1c47e8u: goto label_1c47e8;
        case 0x1c47f4u: goto label_1c47f4;
        case 0x1c483cu: goto label_1c483c;
        case 0x1c4888u: goto label_1c4888;
        case 0x1c4914u: goto label_1c4914;
        case 0x1c4934u: goto label_1c4934;
        case 0x1c4948u: goto label_1c4948;
        case 0x1c4950u: goto label_1c4950;
        default: break;
    }

    ctx->pc = 0x1c4390u;

    // 0x1c4390: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c4390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c4394: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c4394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c4398: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c4398u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c439c: 0x80850002  lb          $a1, 0x2($a0)
    ctx->pc = 0x1c439cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c43a0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c43a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c43a4: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1c43a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c43a8: 0x10a4015c  beq         $a1, $a0, . + 4 + (0x15C << 2)
    ctx->pc = 0x1C43A8u;
    {
        const bool branch_taken_0x1c43a8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C43ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43A8u;
            // 0x1c43ac: 0x24030005  addiu       $v1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43a8) {
            ctx->pc = 0x1C491Cu;
            goto label_1c491c;
        }
    }
    ctx->pc = 0x1C43B0u;
    // 0x1c43b0: 0x10a30152  beq         $a1, $v1, . + 4 + (0x152 << 2)
    ctx->pc = 0x1C43B0u;
    {
        const bool branch_taken_0x1c43b0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C43B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43B0u;
            // 0x1c43b4: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43b0) {
            ctx->pc = 0x1C48FCu;
            goto label_1c48fc;
        }
    }
    ctx->pc = 0x1C43B8u;
    // 0x1c43b8: 0x10a2011e  beq         $a1, $v0, . + 4 + (0x11E << 2)
    ctx->pc = 0x1C43B8u;
    {
        const bool branch_taken_0x1c43b8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c43b8) {
            ctx->pc = 0x1C4834u;
            goto label_1c4834;
        }
    }
    ctx->pc = 0x1C43C0u;
    // 0x1c43c0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c43c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c43c4: 0x10a200f5  beq         $a1, $v0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x1C43C4u;
    {
        const bool branch_taken_0x1c43c4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C43C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43C4u;
            // 0x1c43c8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43c4) {
            ctx->pc = 0x1C479Cu;
            goto label_1c479c;
        }
    }
    ctx->pc = 0x1C43CCu;
    // 0x1c43cc: 0x10a2008c  beq         $a1, $v0, . + 4 + (0x8C << 2)
    ctx->pc = 0x1C43CCu;
    {
        const bool branch_taken_0x1c43cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C43D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43CCu;
            // 0x1c43d0: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43cc) {
            ctx->pc = 0x1C4600u;
            goto label_1c4600;
        }
    }
    ctx->pc = 0x1C43D4u;
    // 0x1c43d4: 0x10a60014  beq         $a1, $a2, . + 4 + (0x14 << 2)
    ctx->pc = 0x1C43D4u;
    {
        const bool branch_taken_0x1c43d4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 6));
        if (branch_taken_0x1c43d4) {
            ctx->pc = 0x1C4428u;
            goto label_1c4428;
        }
    }
    ctx->pc = 0x1C43DCu;
    // 0x1c43dc: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C43DCu;
    {
        const bool branch_taken_0x1c43dc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c43dc) {
            ctx->pc = 0x1C43ECu;
            goto label_1c43ec;
        }
    }
    ctx->pc = 0x1C43E4u;
    // 0x1c43e4: 0x10000156  b           . + 4 + (0x156 << 2)
    ctx->pc = 0x1C43E4u;
    {
        const bool branch_taken_0x1c43e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C43E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43E4u;
            // 0x1c43e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43e4) {
            ctx->pc = 0x1C4940u;
            goto label_1c4940;
        }
    }
    ctx->pc = 0x1C43ECu;
label_1c43ec:
    // 0x1c43ec: 0x8e020040  lw          $v0, 0x40($s0)
    ctx->pc = 0x1c43ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1c43f0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C43F0u;
    {
        const bool branch_taken_0x1c43f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c43f0) {
            ctx->pc = 0x1C4404u;
            goto label_1c4404;
        }
    }
    ctx->pc = 0x1C43F8u;
    // 0x1c43f8: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c43f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c43fc: 0x1000014f  b           . + 4 + (0x14F << 2)
    ctx->pc = 0x1C43FCu;
    {
        const bool branch_taken_0x1c43fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C43FCu;
            // 0x1c4400: 0xae030034  sw          $v1, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c43fc) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4404u;
label_1c4404:
    // 0x1c4404: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1c4404u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1c4408: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1c4408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1c440c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c440cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c4410: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c4410u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c4414: 0xc0701c4  jal         func_1C0710
    ctx->pc = 0x1C4414u;
    SET_GPR_U32(ctx, 31, 0x1C441Cu);
    ctx->pc = 0x1C4418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4414u;
            // 0x1c4418: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0710u;
    if (runtime->hasFunction(0x1C0710u)) {
        auto targetFn = runtime->lookupFunction(0x1C0710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C441Cu; }
        if (ctx->pc != 0x1C441Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0710_0x1c0710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C441Cu; }
        if (ctx->pc != 0x1C441Cu) { return; }
    }
    ctx->pc = 0x1C441Cu;
label_1c441c:
    // 0x1c441c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c441cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c4420: 0x10000146  b           . + 4 + (0x146 << 2)
    ctx->pc = 0x1C4420u;
    {
        const bool branch_taken_0x1c4420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4420u;
            // 0x1c4424: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4420) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4428u;
label_1c4428:
    // 0x1c4428: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1c4428u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c442c: 0x1046000c  beq         $v0, $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x1C442Cu;
    {
        const bool branch_taken_0x1c442c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C4430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C442Cu;
            // 0x1c4430: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c442c) {
            ctx->pc = 0x1C4460u;
            goto label_1c4460;
        }
    }
    ctx->pc = 0x1C4434u;
    // 0x1c4434: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C4434u;
    {
        const bool branch_taken_0x1c4434 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4434) {
            ctx->pc = 0x1C4444u;
            goto label_1c4444;
        }
    }
    ctx->pc = 0x1C443Cu;
    // 0x1c443c: 0x1000013f  b           . + 4 + (0x13F << 2)
    ctx->pc = 0x1C443Cu;
    {
        const bool branch_taken_0x1c443c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c443c) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4444u;
label_1c4444:
    // 0x1c4444: 0xc070114  jal         func_1C0450
    ctx->pc = 0x1C4444u;
    SET_GPR_U32(ctx, 31, 0x1C444Cu);
    ctx->pc = 0x1C0450u;
    if (runtime->hasFunction(0x1C0450u)) {
        auto targetFn = runtime->lookupFunction(0x1C0450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C444Cu; }
        if (ctx->pc != 0x1C444Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0450_0x1c0450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C444Cu; }
        if (ctx->pc != 0x1C444Cu) { return; }
    }
    ctx->pc = 0x1C444Cu;
label_1c444c:
    // 0x1c444c: 0xae0000e0  sw          $zero, 0xE0($s0)
    ctx->pc = 0x1c444cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
    // 0x1c4450: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1c4450u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c4454: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c4454u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c4458: 0x10000138  b           . + 4 + (0x138 << 2)
    ctx->pc = 0x1C4458u;
    {
        const bool branch_taken_0x1c4458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C445Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4458u;
            // 0x1c445c: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4458) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4460u;
label_1c4460:
    // 0x1c4460: 0xc07049c  jal         func_1C1270
    ctx->pc = 0x1C4460u;
    SET_GPR_U32(ctx, 31, 0x1C4468u);
    ctx->pc = 0x1C1270u;
    if (runtime->hasFunction(0x1C1270u)) {
        auto targetFn = runtime->lookupFunction(0x1C1270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4468u; }
        if (ctx->pc != 0x1C4468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1270_0x1c1270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4468u; }
        if (ctx->pc != 0x1C4468u) { return; }
    }
    ctx->pc = 0x1C4468u;
label_1c4468:
    // 0x1c4468: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C4468u;
    {
        const bool branch_taken_0x1c4468 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C446Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4468u;
            // 0x1c446c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4468) {
            ctx->pc = 0x1C44A0u;
            goto label_1c44a0;
        }
    }
    ctx->pc = 0x1C4470u;
    // 0x1c4470: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4470u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c4474: 0xae0400e0  sw          $a0, 0xE0($s0)
    ctx->pc = 0x1c4474u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 4));
    // 0x1c4478: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c4478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c447c: 0x90234476  lbu         $v1, 0x4476($at)
    ctx->pc = 0x1c447cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c4480: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c4480u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c4484: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4484u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c4488: 0xa0234476  sb          $v1, 0x4476($at)
    ctx->pc = 0x1c4488u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c448c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c448cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c4490: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c4490u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c4494: 0xae040034  sw          $a0, 0x34($s0)
    ctx->pc = 0x1c4494u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 4));
    // 0x1c4498: 0x10000128  b           . + 4 + (0x128 << 2)
    ctx->pc = 0x1C4498u;
    {
        const bool branch_taken_0x1c4498 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C449Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4498u;
            // 0x1c449c: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4498) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C44A0u;
label_1c44a0:
    // 0x1c44a0: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c44a0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c44a4: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x1c44a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x1c44a8: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x1C44A8u;
    {
        const bool branch_taken_0x1c44a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c44a8) {
            ctx->pc = 0x1C4594u;
            goto label_1c4594;
        }
    }
    ctx->pc = 0x1C44B0u;
    // 0x1c44b0: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C44B0u;
    SET_GPR_U32(ctx, 31, 0x1C44B8u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C44B8u; }
        if (ctx->pc != 0x1C44B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C44B8u; }
        if (ctx->pc != 0x1C44B8u) { return; }
    }
    ctx->pc = 0x1C44B8u;
label_1c44b8:
    // 0x1c44b8: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1c44b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1c44bc: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c44bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c44c0: 0x1440002e  bnez        $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x1C44C0u;
    {
        const bool branch_taken_0x1c44c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C44C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C44C0u;
            // 0x1c44c4: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c44c0) {
            ctx->pc = 0x1C457Cu;
            goto label_1c457c;
        }
    }
    ctx->pc = 0x1C44C8u;
    // 0x1c44c8: 0x8e03003c  lw          $v1, 0x3C($s0)
    ctx->pc = 0x1c44c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x1c44cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c44ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c44d0: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1C44D0u;
    {
        const bool branch_taken_0x1c44d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C44D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C44D0u;
            // 0x1c44d4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c44d0) {
            ctx->pc = 0x1C4544u;
            goto label_1c4544;
        }
    }
    ctx->pc = 0x1C44D8u;
    // 0x1c44d8: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C44D8u;
    {
        const bool branch_taken_0x1c44d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c44d8) {
            ctx->pc = 0x1C4524u;
            goto label_1c4524;
        }
    }
    ctx->pc = 0x1C44E0u;
    // 0x1c44e0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C44E0u;
    {
        const bool branch_taken_0x1c44e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c44e0) {
            ctx->pc = 0x1C44F0u;
            goto label_1c44f0;
        }
    }
    ctx->pc = 0x1C44E8u;
    // 0x1c44e8: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1C44E8u;
    {
        const bool branch_taken_0x1c44e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c44e8) {
            ctx->pc = 0x1C4568u;
            goto label_1c4568;
        }
    }
    ctx->pc = 0x1C44F0u;
label_1c44f0:
    // 0x1c44f0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c44f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c44f4: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1c44f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1c44f8: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c44f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c44fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c44fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4500: 0xc07158c  jal         func_1C5630
    ctx->pc = 0x1C4500u;
    SET_GPR_U32(ctx, 31, 0x1C4508u);
    ctx->pc = 0x1C4504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4500u;
            // 0x1c4504: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5630u;
    if (runtime->hasFunction(0x1C5630u)) {
        auto targetFn = runtime->lookupFunction(0x1C5630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4508u; }
        if (ctx->pc != 0x1C4508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5630_0x1c5630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4508u; }
        if (ctx->pc != 0x1C4508u) { return; }
    }
    ctx->pc = 0x1C4508u;
label_1c4508:
    // 0x1c4508: 0xc071504  jal         func_1C5410
    ctx->pc = 0x1C4508u;
    SET_GPR_U32(ctx, 31, 0x1C4510u);
    ctx->pc = 0x1C450Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4508u;
            // 0x1c450c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5410u;
    if (runtime->hasFunction(0x1C5410u)) {
        auto targetFn = runtime->lookupFunction(0x1C5410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4510u; }
        if (ctx->pc != 0x1C4510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5410_0x1c5410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4510u; }
        if (ctx->pc != 0x1C4510u) { return; }
    }
    ctx->pc = 0x1C4510u;
label_1c4510:
    // 0x1c4510: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c4510u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c4514: 0xc070274  jal         func_1C09D0
    ctx->pc = 0x1C4514u;
    SET_GPR_U32(ctx, 31, 0x1C451Cu);
    ctx->pc = 0x1C4518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4514u;
            // 0x1c4518: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C09D0u;
    if (runtime->hasFunction(0x1C09D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C09D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C451Cu; }
        if (ctx->pc != 0x1C451Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C09D0_0x1c09d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C451Cu; }
        if (ctx->pc != 0x1C451Cu) { return; }
    }
    ctx->pc = 0x1C451Cu;
label_1c451c:
    // 0x1c451c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1C451Cu;
    {
        const bool branch_taken_0x1c451c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c451c) {
            ctx->pc = 0x1C4568u;
            goto label_1c4568;
        }
    }
    ctx->pc = 0x1C4524u;
label_1c4524:
    // 0x1c4524: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c4524u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c4528: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x1c4528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1c452c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c452cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c4530: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c4530u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c4534: 0xc070370  jal         func_1C0DC0
    ctx->pc = 0x1C4534u;
    SET_GPR_U32(ctx, 31, 0x1C453Cu);
    ctx->pc = 0x1C4538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4534u;
            // 0x1c4538: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0DC0u;
    if (runtime->hasFunction(0x1C0DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1C0DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C453Cu; }
        if (ctx->pc != 0x1C453Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0DC0_0x1c0dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C453Cu; }
        if (ctx->pc != 0x1C453Cu) { return; }
    }
    ctx->pc = 0x1C453Cu;
label_1c453c:
    // 0x1c453c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C453Cu;
    {
        const bool branch_taken_0x1c453c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c453c) {
            ctx->pc = 0x1C4568u;
            goto label_1c4568;
        }
    }
    ctx->pc = 0x1C4544u;
label_1c4544:
    // 0x1c4544: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c4544u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c4548: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1c4548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1c454c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c454cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c4550: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c4550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4554: 0xc071504  jal         func_1C5410
    ctx->pc = 0x1C4554u;
    SET_GPR_U32(ctx, 31, 0x1C455Cu);
    ctx->pc = 0x1C4558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4554u;
            // 0x1c4558: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5410u;
    if (runtime->hasFunction(0x1C5410u)) {
        auto targetFn = runtime->lookupFunction(0x1C5410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C455Cu; }
        if (ctx->pc != 0x1C455Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5410_0x1c5410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C455Cu; }
        if (ctx->pc != 0x1C455Cu) { return; }
    }
    ctx->pc = 0x1C455Cu;
label_1c455c:
    // 0x1c455c: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c455cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c4560: 0xc070274  jal         func_1C09D0
    ctx->pc = 0x1C4560u;
    SET_GPR_U32(ctx, 31, 0x1C4568u);
    ctx->pc = 0x1C4564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4560u;
            // 0x1c4564: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C09D0u;
    if (runtime->hasFunction(0x1C09D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C09D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4568u; }
        if (ctx->pc != 0x1C4568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C09D0_0x1c09d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4568u; }
        if (ctx->pc != 0x1C4568u) { return; }
    }
    ctx->pc = 0x1C4568u;
label_1c4568:
    // 0x1c4568: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c4568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c456c: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c456cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c4570: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x1c4570u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x1c4574: 0x100000f1  b           . + 4 + (0xF1 << 2)
    ctx->pc = 0x1C4574u;
    {
        const bool branch_taken_0x1c4574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4574u;
            // 0x1c4578: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4574) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C457Cu;
label_1c457c:
    // 0x1c457c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c457cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c4580: 0x90234476  lbu         $v1, 0x4476($at)
    ctx->pc = 0x1c4580u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c4584: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c4584u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c4588: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4588u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c458c: 0x100000f1  b           . + 4 + (0xF1 << 2)
    ctx->pc = 0x1C458Cu;
    {
        const bool branch_taken_0x1c458c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C458Cu;
            // 0x1c4590: 0xa0234476  sb          $v1, 0x4476($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c458c) {
            ctx->pc = 0x1C4954u;
            goto label_1c4954;
        }
    }
    ctx->pc = 0x1C4594u;
label_1c4594:
    // 0x1c4594: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c4594u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c4598: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C4598u;
    {
        const bool branch_taken_0x1c4598 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4598) {
            ctx->pc = 0x1C45ACu;
            goto label_1c45ac;
        }
    }
    ctx->pc = 0x1C45A0u;
    // 0x1c45a0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c45a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c45a4: 0x100000e5  b           . + 4 + (0xE5 << 2)
    ctx->pc = 0x1C45A4u;
    {
        const bool branch_taken_0x1c45a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C45A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C45A4u;
            // 0x1c45a8: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c45a4) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C45ACu;
label_1c45ac:
    // 0x1c45ac: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x1c45acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1c45b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C45B0u;
    {
        const bool branch_taken_0x1c45b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C45B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C45B0u;
            // 0x1c45b4: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c45b0) {
            ctx->pc = 0x1C45C8u;
            goto label_1c45c8;
        }
    }
    ctx->pc = 0x1C45B8u;
    // 0x1c45b8: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c45b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c45bc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C45BCu;
    {
        const bool branch_taken_0x1c45bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c45bc) {
            ctx->pc = 0x1C45E0u;
            goto label_1c45e0;
        }
    }
    ctx->pc = 0x1C45C4u;
    // 0x1c45c4: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1c45c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
label_1c45c8:
    // 0x1c45c8: 0x104000dc  beqz        $v0, . + 4 + (0xDC << 2)
    ctx->pc = 0x1C45C8u;
    {
        const bool branch_taken_0x1c45c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c45c8) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C45D0u;
    // 0x1c45d0: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c45d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c45d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c45d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c45d8: 0x146200d8  bne         $v1, $v0, . + 4 + (0xD8 << 2)
    ctx->pc = 0x1C45D8u;
    {
        const bool branch_taken_0x1c45d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c45d8) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C45E0u;
label_1c45e0:
    // 0x1c45e0: 0xc071660  jal         func_1C5980
    ctx->pc = 0x1C45E0u;
    SET_GPR_U32(ctx, 31, 0x1C45E8u);
    ctx->pc = 0x1C5980u;
    if (runtime->hasFunction(0x1C5980u)) {
        auto targetFn = runtime->lookupFunction(0x1C5980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C45E8u; }
        if (ctx->pc != 0x1C45E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5980_0x1c5980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C45E8u; }
        if (ctx->pc != 0x1C45E8u) { return; }
    }
    ctx->pc = 0x1C45E8u;
label_1c45e8:
    // 0x1c45e8: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c45e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c45ec: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c45ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c45f0: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c45f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c45f4: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c45f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c45f8: 0x100000d0  b           . + 4 + (0xD0 << 2)
    ctx->pc = 0x1C45F8u;
    {
        const bool branch_taken_0x1c45f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C45FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C45F8u;
            // 0x1c45fc: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c45f8) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4600u;
label_1c4600:
    // 0x1c4600: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C4600u;
    SET_GPR_U32(ctx, 31, 0x1C4608u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4608u; }
        if (ctx->pc != 0x1C4608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4608u; }
        if (ctx->pc != 0x1C4608u) { return; }
    }
    ctx->pc = 0x1C4608u;
label_1c4608:
    // 0x1c4608: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c4608u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c460c: 0x104300cb  beq         $v0, $v1, . + 4 + (0xCB << 2)
    ctx->pc = 0x1C460Cu;
    {
        const bool branch_taken_0x1c460c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c460c) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4614u;
    // 0x1c4614: 0x10400032  beqz        $v0, . + 4 + (0x32 << 2)
    ctx->pc = 0x1C4614u;
    {
        const bool branch_taken_0x1c4614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4614u;
            // 0x1c4618: 0x2403ff05  addiu       $v1, $zero, -0xFB (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4614) {
            ctx->pc = 0x1C46E0u;
            goto label_1c46e0;
        }
    }
    ctx->pc = 0x1C461Cu;
    // 0x1c461c: 0x10430030  beq         $v0, $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1C461Cu;
    {
        const bool branch_taken_0x1c461c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c461c) {
            ctx->pc = 0x1C46E0u;
            goto label_1c46e0;
        }
    }
    ctx->pc = 0x1C4624u;
    // 0x1c4624: 0x2403ff02  addiu       $v1, $zero, -0xFE
    ctx->pc = 0x1c4624u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c4628: 0x10430020  beq         $v0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1C4628u;
    {
        const bool branch_taken_0x1c4628 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C462Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4628u;
            // 0x1c462c: 0x2403ff00  addiu       $v1, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4628) {
            ctx->pc = 0x1C46ACu;
            goto label_1c46ac;
        }
    }
    ctx->pc = 0x1C4630u;
    // 0x1c4630: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C4630u;
    {
        const bool branch_taken_0x1c4630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C4634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4630u;
            // 0x1c4634: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4630) {
            ctx->pc = 0x1C4680u;
            goto label_1c4680;
        }
    }
    ctx->pc = 0x1C4638u;
    // 0x1c4638: 0x2403ff03  addiu       $v1, $zero, -0xFD
    ctx->pc = 0x1c4638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
    // 0x1c463c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C463Cu;
    {
        const bool branch_taken_0x1c463c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c463c) {
            ctx->pc = 0x1C464Cu;
            goto label_1c464c;
        }
    }
    ctx->pc = 0x1C4644u;
    // 0x1c4644: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1C4644u;
    {
        const bool branch_taken_0x1c4644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4644) {
            ctx->pc = 0x1C4718u;
            goto label_1c4718;
        }
    }
    ctx->pc = 0x1C464Cu;
label_1c464c:
    // 0x1c464c: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1c464cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1c4650: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c4650u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4654: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c4654u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c4658: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c4658u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c465c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c465cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4660: 0xa2030003  sb          $v1, 0x3($s0)
    ctx->pc = 0x1c4660u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c4664: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1c4664u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1c4668: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1c4668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1c466c: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c466cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c4670: 0xc070114  jal         func_1C0450
    ctx->pc = 0x1C4670u;
    SET_GPR_U32(ctx, 31, 0x1C4678u);
    ctx->pc = 0x1C4674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4670u;
            // 0x1c4674: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0450u;
    if (runtime->hasFunction(0x1C0450u)) {
        auto targetFn = runtime->lookupFunction(0x1C0450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4678u; }
        if (ctx->pc != 0x1C4678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0450_0x1c0450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4678u; }
        if (ctx->pc != 0x1C4678u) { return; }
    }
    ctx->pc = 0x1C4678u;
label_1c4678:
    // 0x1c4678: 0x100000b0  b           . + 4 + (0xB0 << 2)
    ctx->pc = 0x1C4678u;
    {
        const bool branch_taken_0x1c4678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C467Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4678u;
            // 0x1c467c: 0xae0000e0  sw          $zero, 0xE0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4678) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4680u;
label_1c4680:
    // 0x1c4680: 0x24040016  addiu       $a0, $zero, 0x16
    ctx->pc = 0x1c4680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1c4684: 0x90254476  lbu         $a1, 0x4476($at)
    ctx->pc = 0x1c4684u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c4688: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c4688u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c468c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c468cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4690: 0x38a50001  xori        $a1, $a1, 0x1
    ctx->pc = 0x1c4690u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x1c4694: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c4698: 0xa0254476  sb          $a1, 0x4476($at)
    ctx->pc = 0x1c4698u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 5));
    // 0x1c469c: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1c469cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1c46a0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c46a0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c46a4: 0x100000a5  b           . + 4 + (0xA5 << 2)
    ctx->pc = 0x1C46A4u;
    {
        const bool branch_taken_0x1c46a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C46A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C46A4u;
            // 0x1c46a8: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c46a4) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C46ACu;
label_1c46ac:
    // 0x1c46ac: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1c46acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1c46b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c46b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c46b4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c46b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c46b8: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c46b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c46bc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c46bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c46c0: 0xa2030003  sb          $v1, 0x3($s0)
    ctx->pc = 0x1c46c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c46c4: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x1c46c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
    // 0x1c46c8: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1c46c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1c46cc: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c46ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c46d0: 0xc070114  jal         func_1C0450
    ctx->pc = 0x1C46D0u;
    SET_GPR_U32(ctx, 31, 0x1C46D8u);
    ctx->pc = 0x1C46D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C46D0u;
            // 0x1c46d4: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0450u;
    if (runtime->hasFunction(0x1C0450u)) {
        auto targetFn = runtime->lookupFunction(0x1C0450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C46D8u; }
        if (ctx->pc != 0x1C46D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0450_0x1c0450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C46D8u; }
        if (ctx->pc != 0x1C46D8u) { return; }
    }
    ctx->pc = 0x1C46D8u;
label_1c46d8:
    // 0x1c46d8: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1C46D8u;
    {
        const bool branch_taken_0x1c46d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C46DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C46D8u;
            // 0x1c46dc: 0xae0000e0  sw          $zero, 0xE0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c46d8) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C46E0u;
label_1c46e0:
    // 0x1c46e0: 0x24020013  addiu       $v0, $zero, 0x13
    ctx->pc = 0x1c46e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1c46e4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c46e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c46e8: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c46e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c46ec: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c46ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c46f0: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c46f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c46f4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c46f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c46f8: 0xa2040003  sb          $a0, 0x3($s0)
    ctx->pc = 0x1c46f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c46fc: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x1c46fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
    // 0x1c4700: 0xae040030  sw          $a0, 0x30($s0)
    ctx->pc = 0x1c4700u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 4));
    // 0x1c4704: 0xae040038  sw          $a0, 0x38($s0)
    ctx->pc = 0x1c4704u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
    // 0x1c4708: 0xc070114  jal         func_1C0450
    ctx->pc = 0x1C4708u;
    SET_GPR_U32(ctx, 31, 0x1C4710u);
    ctx->pc = 0x1C470Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4708u;
            // 0x1c470c: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0450u;
    if (runtime->hasFunction(0x1C0450u)) {
        auto targetFn = runtime->lookupFunction(0x1C0450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4710u; }
        if (ctx->pc != 0x1C4710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0450_0x1c0450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4710u; }
        if (ctx->pc != 0x1C4710u) { return; }
    }
    ctx->pc = 0x1C4710u;
label_1c4710:
    // 0x1c4710: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x1C4710u;
    {
        const bool branch_taken_0x1c4710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4710u;
            // 0x1c4714: 0xae0000e0  sw          $zero, 0xE0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4710) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4718u;
label_1c4718:
    // 0x1c4718: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4718u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c471c: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c471cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c4720: 0x90254476  lbu         $a1, 0x4476($at)
    ctx->pc = 0x1c4720u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c4724: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1c4724u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1c4728: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c4728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c472c: 0x38a50001  xori        $a1, $a1, 0x1
    ctx->pc = 0x1c472cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x1c4730: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4730u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c4734: 0xa0254476  sb          $a1, 0x4476($at)
    ctx->pc = 0x1c4734u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 5));
    // 0x1c4738: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c4738u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c473c: 0xae030034  sw          $v1, 0x34($s0)
    ctx->pc = 0x1c473cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 3));
    // 0x1c4740: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1c4740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c4744: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C4744u;
    {
        const bool branch_taken_0x1c4744 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c4744) {
            ctx->pc = 0x1C4790u;
            goto label_1c4790;
        }
    }
    ctx->pc = 0x1C474Cu;
    // 0x1c474c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c474cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c4750: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C4750u;
    {
        const bool branch_taken_0x1c4750 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C4754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4750u;
            // 0x1c4754: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4750) {
            ctx->pc = 0x1C4788u;
            goto label_1c4788;
        }
    }
    ctx->pc = 0x1C4758u;
    // 0x1c4758: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c4758u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c475c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C475Cu;
    {
        const bool branch_taken_0x1c475c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C4760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C475Cu;
            // 0x1c4760: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c475c) {
            ctx->pc = 0x1C4780u;
            goto label_1c4780;
        }
    }
    ctx->pc = 0x1C4764u;
    // 0x1c4764: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c4768: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C4768u;
    {
        const bool branch_taken_0x1c4768 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C476Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4768u;
            // 0x1c476c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4768) {
            ctx->pc = 0x1C4778u;
            goto label_1c4778;
        }
    }
    ctx->pc = 0x1C4770u;
    // 0x1c4770: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1C4770u;
    {
        const bool branch_taken_0x1c4770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4770) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4778u;
label_1c4778:
    // 0x1c4778: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x1C4778u;
    {
        const bool branch_taken_0x1c4778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C477Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4778u;
            // 0x1c477c: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4778) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4780u;
label_1c4780:
    // 0x1c4780: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1C4780u;
    {
        const bool branch_taken_0x1c4780 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4780u;
            // 0x1c4784: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4780) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4788u;
label_1c4788:
    // 0x1c4788: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1C4788u;
    {
        const bool branch_taken_0x1c4788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C478Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4788u;
            // 0x1c478c: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4788) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4790u;
label_1c4790:
    // 0x1c4790: 0x24020017  addiu       $v0, $zero, 0x17
    ctx->pc = 0x1c4790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1c4794: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x1C4794u;
    {
        const bool branch_taken_0x1c4794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4794u;
            // 0x1c4798: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4794) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C479Cu;
label_1c479c:
    // 0x1c479c: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C479Cu;
    SET_GPR_U32(ctx, 31, 0x1C47A4u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47A4u; }
        if (ctx->pc != 0x1C47A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47A4u; }
        if (ctx->pc != 0x1C47A4u) { return; }
    }
    ctx->pc = 0x1C47A4u;
label_1c47a4:
    // 0x1c47a4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c47a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c47a8: 0x1043001e  beq         $v0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1C47A8u;
    {
        const bool branch_taken_0x1c47a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c47a8) {
            ctx->pc = 0x1C4824u;
            goto label_1c4824;
        }
    }
    ctx->pc = 0x1C47B0u;
    // 0x1c47b0: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c47b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c47b4: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C47B4u;
    {
        const bool branch_taken_0x1c47b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C47B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C47B4u;
            // 0x1c47b8: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c47b4) {
            ctx->pc = 0x1C47FCu;
            goto label_1c47fc;
        }
    }
    ctx->pc = 0x1C47BCu;
    // 0x1c47bc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C47BCu;
    {
        const bool branch_taken_0x1c47bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C47C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C47BCu;
            // 0x1c47c0: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c47bc) {
            ctx->pc = 0x1C47CCu;
            goto label_1c47cc;
        }
    }
    ctx->pc = 0x1C47C4u;
    // 0x1c47c4: 0x1000ffd4  b           . + 4 + (-0x2C << 2)
    ctx->pc = 0x1C47C4u;
    {
        const bool branch_taken_0x1c47c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c47c4) {
            ctx->pc = 0x1C4718u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4718;
        }
    }
    ctx->pc = 0x1C47CCu;
label_1c47cc:
    // 0x1c47cc: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1c47ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1c47d0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c47d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c47d4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c47d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c47d8: 0xc07158c  jal         func_1C5630
    ctx->pc = 0x1C47D8u;
    SET_GPR_U32(ctx, 31, 0x1C47E0u);
    ctx->pc = 0x1C47DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C47D8u;
            // 0x1c47dc: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5630u;
    if (runtime->hasFunction(0x1C5630u)) {
        auto targetFn = runtime->lookupFunction(0x1C5630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47E0u; }
        if (ctx->pc != 0x1C47E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5630_0x1c5630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47E0u; }
        if (ctx->pc != 0x1C47E0u) { return; }
    }
    ctx->pc = 0x1C47E0u;
label_1c47e0:
    // 0x1c47e0: 0xc071504  jal         func_1C5410
    ctx->pc = 0x1C47E0u;
    SET_GPR_U32(ctx, 31, 0x1C47E8u);
    ctx->pc = 0x1C47E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C47E0u;
            // 0x1c47e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5410u;
    if (runtime->hasFunction(0x1C5410u)) {
        auto targetFn = runtime->lookupFunction(0x1C5410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47E8u; }
        if (ctx->pc != 0x1C47E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5410_0x1c5410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47E8u; }
        if (ctx->pc != 0x1C47E8u) { return; }
    }
    ctx->pc = 0x1C47E8u;
label_1c47e8:
    // 0x1c47e8: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c47e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c47ec: 0xc070274  jal         func_1C09D0
    ctx->pc = 0x1C47ECu;
    SET_GPR_U32(ctx, 31, 0x1C47F4u);
    ctx->pc = 0x1C47F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C47ECu;
            // 0x1c47f0: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C09D0u;
    if (runtime->hasFunction(0x1C09D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C09D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47F4u; }
        if (ctx->pc != 0x1C47F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C09D0_0x1c09d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C47F4u; }
        if (ctx->pc != 0x1C47F4u) { return; }
    }
    ctx->pc = 0x1C47F4u;
label_1c47f4:
    // 0x1c47f4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1C47F4u;
    {
        const bool branch_taken_0x1c47f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c47f4) {
            ctx->pc = 0x1C4824u;
            goto label_1c4824;
        }
    }
    ctx->pc = 0x1C47FCu;
label_1c47fc:
    // 0x1c47fc: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1c47fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c4800: 0x90254476  lbu         $a1, 0x4476($at)
    ctx->pc = 0x1c4800u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c4804: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c4804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c4808: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4808u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c480c: 0x38a50001  xori        $a1, $a1, 0x1
    ctx->pc = 0x1c480cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ (uint64_t)(uint16_t)1);
    // 0x1c4810: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4810u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c4814: 0xa0254476  sb          $a1, 0x4476($at)
    ctx->pc = 0x1c4814u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 5));
    // 0x1c4818: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1c4818u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1c481c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c481cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c4820: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c4820u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
label_1c4824:
    // 0x1c4824: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c4824u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c4828: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c4828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c482c: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1C482Cu;
    {
        const bool branch_taken_0x1c482c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C482Cu;
            // 0x1c4830: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c482c) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C4834u;
label_1c4834:
    // 0x1c4834: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C4834u;
    SET_GPR_U32(ctx, 31, 0x1C483Cu);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C483Cu; }
        if (ctx->pc != 0x1C483Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C483Cu; }
        if (ctx->pc != 0x1C483Cu) { return; }
    }
    ctx->pc = 0x1C483Cu;
label_1c483c:
    // 0x1c483c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c483cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c4840: 0x1043002a  beq         $v0, $v1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1C4840u;
    {
        const bool branch_taken_0x1c4840 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c4840) {
            ctx->pc = 0x1C48ECu;
            goto label_1c48ec;
        }
    }
    ctx->pc = 0x1C4848u;
    // 0x1c4848: 0x2403ff02  addiu       $v1, $zero, -0xFE
    ctx->pc = 0x1c4848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c484c: 0x1043001d  beq         $v0, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C484Cu;
    {
        const bool branch_taken_0x1c484c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C4850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C484Cu;
            // 0x1c4850: 0x2403ff00  addiu       $v1, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c484c) {
            ctx->pc = 0x1C48C4u;
            goto label_1c48c4;
        }
    }
    ctx->pc = 0x1C4854u;
    // 0x1c4854: 0x1043000f  beq         $v0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1C4854u;
    {
        const bool branch_taken_0x1c4854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C4858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4854u;
            // 0x1c4858: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4854) {
            ctx->pc = 0x1C4894u;
            goto label_1c4894;
        }
    }
    ctx->pc = 0x1C485Cu;
    // 0x1c485c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C485Cu;
    {
        const bool branch_taken_0x1c485c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c485c) {
            ctx->pc = 0x1C486Cu;
            goto label_1c486c;
        }
    }
    ctx->pc = 0x1C4864u;
    // 0x1c4864: 0x1000ffac  b           . + 4 + (-0x54 << 2)
    ctx->pc = 0x1C4864u;
    {
        const bool branch_taken_0x1c4864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4864) {
            ctx->pc = 0x1C4718u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c4718;
        }
    }
    ctx->pc = 0x1C486Cu;
label_1c486c:
    // 0x1c486c: 0x24020015  addiu       $v0, $zero, 0x15
    ctx->pc = 0x1c486cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1c4870: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c4870u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c4874: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1c4874u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c4878: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c4878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c487c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c487cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c4880: 0xc0704a4  jal         func_1C1290
    ctx->pc = 0x1C4880u;
    SET_GPR_U32(ctx, 31, 0x1C4888u);
    ctx->pc = 0x1C4884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4880u;
            // 0x1c4884: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1290u;
    if (runtime->hasFunction(0x1C1290u)) {
        auto targetFn = runtime->lookupFunction(0x1C1290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4888u; }
        if (ctx->pc != 0x1C4888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1290_0x1c1290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4888u; }
        if (ctx->pc != 0x1C4888u) { return; }
    }
    ctx->pc = 0x1C4888u;
label_1c4888:
    // 0x1c4888: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c4888u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c488c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1C488Cu;
    {
        const bool branch_taken_0x1c488c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C488Cu;
            // 0x1c4890: 0xa020448c  sb          $zero, 0x448C($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17548), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c488c) {
            ctx->pc = 0x1C48ECu;
            goto label_1c48ec;
        }
    }
    ctx->pc = 0x1C4894u;
label_1c4894:
    // 0x1c4894: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x1c4894u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1c4898: 0x90244476  lbu         $a0, 0x4476($at)
    ctx->pc = 0x1c4898u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c489c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c489cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c48a0: 0x38840001  xori        $a0, $a0, 0x1
    ctx->pc = 0x1c48a0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)1);
    // 0x1c48a4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c48a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c48a8: 0xa0244476  sb          $a0, 0x4476($at)
    ctx->pc = 0x1c48a8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c48ac: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c48acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c48b0: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x1c48b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c48b4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c48b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c48b8: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c48b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c48bc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1C48BCu;
    {
        const bool branch_taken_0x1c48bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C48C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C48BCu;
            // 0x1c48c0: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c48bc) {
            ctx->pc = 0x1C48ECu;
            goto label_1c48ec;
        }
    }
    ctx->pc = 0x1C48C4u;
label_1c48c4:
    // 0x1c48c4: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1c48c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1c48c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c48c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c48cc: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c48ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c48d0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c48d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c48d4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c48d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c48d8: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1c48d8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c48dc: 0xae03003c  sw          $v1, 0x3C($s0)
    ctx->pc = 0x1c48dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 3));
    // 0x1c48e0: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1c48e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1c48e4: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c48e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c48e8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c48e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_1c48ec:
    // 0x1c48ec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c48ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c48f0: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c48f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c48f4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1C48F4u;
    {
        const bool branch_taken_0x1c48f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C48F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C48F4u;
            // 0x1c48f8: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c48f4) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C48FCu;
label_1c48fc:
    // 0x1c48fc: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c48fcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c4900: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c4900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c4904: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C4904u;
    {
        const bool branch_taken_0x1c4904 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4904) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C490Cu;
    // 0x1c490c: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C490Cu;
    SET_GPR_U32(ctx, 31, 0x1C4914u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4914u; }
        if (ctx->pc != 0x1C4914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4914u; }
        if (ctx->pc != 0x1C4914u) { return; }
    }
    ctx->pc = 0x1C4914u;
label_1c4914:
    // 0x1c4914: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C4914u;
    {
        const bool branch_taken_0x1c4914 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4914u;
            // 0x1c4918: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4914) {
            ctx->pc = 0x1C4954u;
            goto label_1c4954;
        }
    }
    ctx->pc = 0x1C491Cu;
label_1c491c:
    // 0x1c491c: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c491cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c4920: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c4920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c4924: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C4924u;
    {
        const bool branch_taken_0x1c4924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c4924) {
            ctx->pc = 0x1C493Cu;
            goto label_1c493c;
        }
    }
    ctx->pc = 0x1C492Cu;
    // 0x1c492c: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C492Cu;
    SET_GPR_U32(ctx, 31, 0x1C4934u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4934u; }
        if (ctx->pc != 0x1C4934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4934u; }
        if (ctx->pc != 0x1C4934u) { return; }
    }
    ctx->pc = 0x1C4934u;
label_1c4934:
    // 0x1c4934: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C4934u;
    {
        const bool branch_taken_0x1c4934 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C4938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4934u;
            // 0x1c4938: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c4934) {
            ctx->pc = 0x1C4954u;
            goto label_1c4954;
        }
    }
    ctx->pc = 0x1C493Cu;
label_1c493c:
    // 0x1c493c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c493cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c4940:
    // 0x1c4940: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C4940u;
    SET_GPR_U32(ctx, 31, 0x1C4948u);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4948u; }
        if (ctx->pc != 0x1C4948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4948u; }
        if (ctx->pc != 0x1C4948u) { return; }
    }
    ctx->pc = 0x1C4948u;
label_1c4948:
    // 0x1c4948: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C4948u;
    SET_GPR_U32(ctx, 31, 0x1C4950u);
    ctx->pc = 0x1C494Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C4948u;
            // 0x1c494c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4950u; }
        if (ctx->pc != 0x1C4950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C4950u; }
        if (ctx->pc != 0x1C4950u) { return; }
    }
    ctx->pc = 0x1C4950u;
label_1c4950:
    // 0x1c4950: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c4950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c4954:
    // 0x1c4954: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c4954u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c4958: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c4958u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c495c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C495Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C4960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C495Cu;
            // 0x1c4960: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C43ECu: goto label_1c43ec;
            case 0x1C4404u: goto label_1c4404;
            case 0x1C441Cu: goto label_1c441c;
            case 0x1C4428u: goto label_1c4428;
            case 0x1C4444u: goto label_1c4444;
            case 0x1C444Cu: goto label_1c444c;
            case 0x1C4460u: goto label_1c4460;
            case 0x1C4468u: goto label_1c4468;
            case 0x1C44A0u: goto label_1c44a0;
            case 0x1C44B8u: goto label_1c44b8;
            case 0x1C44F0u: goto label_1c44f0;
            case 0x1C4508u: goto label_1c4508;
            case 0x1C4510u: goto label_1c4510;
            case 0x1C451Cu: goto label_1c451c;
            case 0x1C4524u: goto label_1c4524;
            case 0x1C453Cu: goto label_1c453c;
            case 0x1C4544u: goto label_1c4544;
            case 0x1C455Cu: goto label_1c455c;
            case 0x1C4568u: goto label_1c4568;
            case 0x1C457Cu: goto label_1c457c;
            case 0x1C4594u: goto label_1c4594;
            case 0x1C45ACu: goto label_1c45ac;
            case 0x1C45C8u: goto label_1c45c8;
            case 0x1C45E0u: goto label_1c45e0;
            case 0x1C45E8u: goto label_1c45e8;
            case 0x1C4600u: goto label_1c4600;
            case 0x1C4608u: goto label_1c4608;
            case 0x1C464Cu: goto label_1c464c;
            case 0x1C4678u: goto label_1c4678;
            case 0x1C4680u: goto label_1c4680;
            case 0x1C46ACu: goto label_1c46ac;
            case 0x1C46D8u: goto label_1c46d8;
            case 0x1C46E0u: goto label_1c46e0;
            case 0x1C4710u: goto label_1c4710;
            case 0x1C4718u: goto label_1c4718;
            case 0x1C4778u: goto label_1c4778;
            case 0x1C4780u: goto label_1c4780;
            case 0x1C4788u: goto label_1c4788;
            case 0x1C4790u: goto label_1c4790;
            case 0x1C479Cu: goto label_1c479c;
            case 0x1C47A4u: goto label_1c47a4;
            case 0x1C47CCu: goto label_1c47cc;
            case 0x1C47E0u: goto label_1c47e0;
            case 0x1C47E8u: goto label_1c47e8;
            case 0x1C47F4u: goto label_1c47f4;
            case 0x1C47FCu: goto label_1c47fc;
            case 0x1C4824u: goto label_1c4824;
            case 0x1C4834u: goto label_1c4834;
            case 0x1C483Cu: goto label_1c483c;
            case 0x1C486Cu: goto label_1c486c;
            case 0x1C4888u: goto label_1c4888;
            case 0x1C4894u: goto label_1c4894;
            case 0x1C48C4u: goto label_1c48c4;
            case 0x1C48ECu: goto label_1c48ec;
            case 0x1C48FCu: goto label_1c48fc;
            case 0x1C4914u: goto label_1c4914;
            case 0x1C491Cu: goto label_1c491c;
            case 0x1C4934u: goto label_1c4934;
            case 0x1C493Cu: goto label_1c493c;
            case 0x1C4940u: goto label_1c4940;
            case 0x1C4948u: goto label_1c4948;
            case 0x1C4950u: goto label_1c4950;
            case 0x1C4954u: goto label_1c4954;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C4964u;
    // 0x1c4964: 0x0  nop
    ctx->pc = 0x1c4964u;
    // NOP
    // 0x1c4968: 0x0  nop
    ctx->pc = 0x1c4968u;
    // NOP
    // 0x1c496c: 0x0  nop
    ctx->pc = 0x1c496cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
