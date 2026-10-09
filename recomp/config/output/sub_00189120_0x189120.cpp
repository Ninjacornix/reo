#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189120
// Address: 0x189120 - 0x189420
void sub_00189120_0x189120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189120_0x189120");
#endif

    switch (ctx->pc) {
        case 0x189180u: goto label_189180;
        case 0x189194u: goto label_189194;
        case 0x189208u: goto label_189208;
        case 0x189260u: goto label_189260;
        case 0x189274u: goto label_189274;
        case 0x1892a8u: goto label_1892a8;
        case 0x18932cu: goto label_18932c;
        case 0x189360u: goto label_189360;
        case 0x1893b8u: goto label_1893b8;
        case 0x1893ccu: goto label_1893cc;
        case 0x1893d4u: goto label_1893d4;
        case 0x1893f4u: goto label_1893f4;
        default: break;
    }

    ctx->pc = 0x189120u;

    // 0x189120: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x189120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x189124: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x189124u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x189128: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18912c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18912cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x189130: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x189130u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x189134: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x189134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x189138: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x189138u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
    // 0x18913c: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x18913cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189140: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x189140u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x189144: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189144u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189148: 0x8d420008  lw          $v0, 0x8($t2)
    ctx->pc = 0x189148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 8)));
    // 0x18914c: 0x24840b88  addiu       $a0, $a0, 0xB88
    ctx->pc = 0x18914cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2952));
    // 0x189150: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189150u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189154: 0x34a5131d  ori         $a1, $a1, 0x131D
    ctx->pc = 0x189154u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4893);
    // 0x189158: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x189158u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x18915c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18915cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189160: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189160u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189164: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x189164u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189168: 0x8d42000c  lw          $v0, 0xC($t2)
    ctx->pc = 0x189168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 12)));
    // 0x18916c: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x18916cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189170: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x189170u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189174: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x189174u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189178: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189178u;
    SET_GPR_U32(ctx, 31, 0x189180u);
    ctx->pc = 0x18917Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189178u;
            // 0x18917c: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189180u; }
        if (ctx->pc != 0x189180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189180u; }
        if (ctx->pc != 0x189180u) { return; }
    }
    ctx->pc = 0x189180u;
label_189180:
    // 0x189180: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189180u;
    {
        const bool branch_taken_0x189180 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189180) {
            ctx->pc = 0x189184u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189180u;
            // 0x189184: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189198u;
            goto label_189198;
        }
    }
    ctx->pc = 0x189188u;
    // 0x189188: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189188u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x18918c: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x18918Cu;
    SET_GPR_U32(ctx, 31, 0x189194u);
    ctx->pc = 0x189190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18918Cu;
            // 0x189190: 0x248419c0  addiu       $a0, $a0, 0x19C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189194u; }
        if (ctx->pc != 0x189194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189194u; }
        if (ctx->pc != 0x189194u) { return; }
    }
    ctx->pc = 0x189194u;
label_189194:
    // 0x189194: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x189194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_189198:
    // 0x189198: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18919c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x18919cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1891a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1891A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1891A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1891A0u;
            // 0x1891a4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189180u: goto label_189180;
            case 0x189194u: goto label_189194;
            case 0x189198u: goto label_189198;
            case 0x189208u: goto label_189208;
            case 0x189230u: goto label_189230;
            case 0x189238u: goto label_189238;
            case 0x189260u: goto label_189260;
            case 0x189274u: goto label_189274;
            case 0x18927Cu: goto label_18927c;
            case 0x1892A8u: goto label_1892a8;
            case 0x1892D0u: goto label_1892d0;
            case 0x1892D4u: goto label_1892d4;
            case 0x1892D8u: goto label_1892d8;
            case 0x18932Cu: goto label_18932c;
            case 0x189360u: goto label_189360;
            case 0x189388u: goto label_189388;
            case 0x189390u: goto label_189390;
            case 0x1893B8u: goto label_1893b8;
            case 0x1893CCu: goto label_1893cc;
            case 0x1893D4u: goto label_1893d4;
            case 0x1893DCu: goto label_1893dc;
            case 0x1893ECu: goto label_1893ec;
            case 0x1893F4u: goto label_1893f4;
            case 0x1893F8u: goto label_1893f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1891A8u;
    // 0x1891a8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1891a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1891ac: 0x3c0a0029  lui         $t2, 0x29
    ctx->pc = 0x1891acu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)41 << 16));
    // 0x1891b0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1891b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1891b4: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1891b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1891b8: 0x25500c00  addiu       $s0, $t2, 0xC00
    ctx->pc = 0x1891b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 10), 3072));
    // 0x1891bc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1891bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1891c0: 0x120982d  daddu       $s3, $t1, $zero
    ctx->pc = 0x1891c0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1891c4: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1891c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1891c8: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1891c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1891cc: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1891ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1891d0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1891d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1891d4: 0xad440c00  sw          $a0, 0xC00($t2)
    ctx->pc = 0x1891d4u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 3072), GPR_U32(ctx, 4));
    // 0x1891d8: 0xae050004  sw          $a1, 0x4($s0)
    ctx->pc = 0x1891d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
    // 0x1891dc: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1891dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1891e0: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x1891e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x1891e4: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1891e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1891e8: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1891e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x1891ec: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1891ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1891f0: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1891F0u;
    {
        const bool branch_taken_0x1891f0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1891F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1891F0u;
            // 0x1891f4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1891f0) {
            ctx->pc = 0x189230u;
            goto label_189230;
        }
    }
    ctx->pc = 0x1891F8u;
    // 0x1891f8: 0x26060010  addiu       $a2, $s0, 0x10
    ctx->pc = 0x1891f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1891fc: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x1891fcu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x189200: 0xe51021  addu        $v0, $a3, $a1
    ctx->pc = 0x189200u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x189204: 0x0  nop
    ctx->pc = 0x189204u;
    // NOP
label_189208:
    // 0x189208: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x189208u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x18920c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x18920cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x189210: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x189210u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x189214: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x189214u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x189218: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x189218u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18921c: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x18921cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x189220: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189220u;
    {
        const bool branch_taken_0x189220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189220u;
            // 0x189224: 0xe51021  addu        $v0, $a3, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189220) {
            ctx->pc = 0x189208u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189208;
        }
    }
    ctx->pc = 0x189228u;
    // 0x189228: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x189228u;
    {
        const bool branch_taken_0x189228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18922Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189228u;
            // 0x18922c: 0x25470c00  addiu       $a3, $t2, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 10), 3072));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189228) {
            ctx->pc = 0x189238u;
            goto label_189238;
        }
    }
    ctx->pc = 0x189230u;
label_189230:
    // 0x189230: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x189230u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x189234: 0x25470c00  addiu       $a3, $t2, 0xC00
    ctx->pc = 0x189234u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 10), 3072));
label_189238:
    // 0x189238: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189238u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x18923c: 0x25040b88  addiu       $a0, $t0, 0xB88
    ctx->pc = 0x18923cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 2952));
    // 0x189240: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189240u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x189244: 0x34a51318  ori         $a1, $a1, 0x1318
    ctx->pc = 0x189244u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4888);
    // 0x189248: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x189248u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18924c: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x18924cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189250: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x189250u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189254: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x189254u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189258: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189258u;
    SET_GPR_U32(ctx, 31, 0x189260u);
    ctx->pc = 0x18925Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189258u;
            // 0x18925c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189260u; }
        if (ctx->pc != 0x189260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189260u; }
        if (ctx->pc != 0x189260u) { return; }
    }
    ctx->pc = 0x189260u;
label_189260:
    // 0x189260: 0x4430006  bgezl       $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x189260u;
    {
        const bool branch_taken_0x189260 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189260) {
            ctx->pc = 0x189264u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189260u;
            // 0x189264: 0x8e020410  lw          $v0, 0x410($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 1040)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x18927Cu;
            goto label_18927c;
        }
    }
    ctx->pc = 0x189268u;
    // 0x189268: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189268u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x18926c: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x18926Cu;
    SET_GPR_U32(ctx, 31, 0x189274u);
    ctx->pc = 0x189270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18926Cu;
            // 0x189270: 0x248419e8  addiu       $a0, $a0, 0x19E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189274u; }
        if (ctx->pc != 0x189274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189274u; }
        if (ctx->pc != 0x189274u) { return; }
    }
    ctx->pc = 0x189274u;
label_189274:
    // 0x189274: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x189274u;
    {
        const bool branch_taken_0x189274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189274u;
            // 0x189278: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189274) {
            ctx->pc = 0x1892D4u;
            goto label_1892d4;
        }
    }
    ctx->pc = 0x18927Cu;
label_18927c:
    // 0x18927c: 0x4400016  bltz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x18927Cu;
    {
        const bool branch_taken_0x18927c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x189280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18927Cu;
            // 0x189280: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18927c) {
            ctx->pc = 0x1892D8u;
            goto label_1892d8;
        }
    }
    ctx->pc = 0x189284u;
    // 0x189284: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x189284u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x189288: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x189288u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x18928c: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x18928cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x189290: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x189290u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x189294: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x189294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x189298: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x189298u;
    {
        const bool branch_taken_0x189298 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x18929Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189298u;
            // 0x18929c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189298) {
            ctx->pc = 0x1892D0u;
            goto label_1892d0;
        }
    }
    ctx->pc = 0x1892A0u;
    // 0x1892a0: 0x26060210  addiu       $a2, $s0, 0x210
    ctx->pc = 0x1892a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 528));
    // 0x1892a4: 0xc51021  addu        $v0, $a2, $a1
    ctx->pc = 0x1892a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
label_1892a8:
    // 0x1892a8: 0x2652021  addu        $a0, $s3, $a1
    ctx->pc = 0x1892a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x1892ac: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1892acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1892b0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1892b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1892b4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1892b4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1892b8: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1892b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1892bc: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1892bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1892c0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1892C0u;
    {
        const bool branch_taken_0x1892c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1892C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1892C0u;
            // 0x1892c4: 0xc51021  addu        $v0, $a2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1892c0) {
            ctx->pc = 0x1892A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1892a8;
        }
    }
    ctx->pc = 0x1892C8u;
    // 0x1892c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1892C8u;
    {
        const bool branch_taken_0x1892c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1892CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1892C8u;
            // 0x1892cc: 0x8e020410  lw          $v0, 0x410($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 1040)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1892c8) {
            ctx->pc = 0x1892D4u;
            goto label_1892d4;
        }
    }
    ctx->pc = 0x1892D0u;
label_1892d0:
    // 0x1892d0: 0x8e020410  lw          $v0, 0x410($s0)
    ctx->pc = 0x1892d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 1040)));
label_1892d4:
    // 0x1892d4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1892d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1892d8:
    // 0x1892d8: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1892d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1892dc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1892dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1892e0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1892e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1892e4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1892e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1892e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1892E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1892ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1892E8u;
            // 0x1892ec: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189180u: goto label_189180;
            case 0x189194u: goto label_189194;
            case 0x189198u: goto label_189198;
            case 0x189208u: goto label_189208;
            case 0x189230u: goto label_189230;
            case 0x189238u: goto label_189238;
            case 0x189260u: goto label_189260;
            case 0x189274u: goto label_189274;
            case 0x18927Cu: goto label_18927c;
            case 0x1892A8u: goto label_1892a8;
            case 0x1892D0u: goto label_1892d0;
            case 0x1892D4u: goto label_1892d4;
            case 0x1892D8u: goto label_1892d8;
            case 0x18932Cu: goto label_18932c;
            case 0x189360u: goto label_189360;
            case 0x189388u: goto label_189388;
            case 0x189390u: goto label_189390;
            case 0x1893B8u: goto label_1893b8;
            case 0x1893CCu: goto label_1893cc;
            case 0x1893D4u: goto label_1893d4;
            case 0x1893DCu: goto label_1893dc;
            case 0x1893ECu: goto label_1893ec;
            case 0x1893F4u: goto label_1893f4;
            case 0x1893F8u: goto label_1893f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1892F0u;
    // 0x1892f0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1892f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1892f4: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1892f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1892f8: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1892f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1892fc: 0x3c150029  lui         $s5, 0x29
    ctx->pc = 0x1892fcu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)41 << 16));
    // 0x189300: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x189300u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189304: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x189304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x189308: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x189308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x18930c: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x18930cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189310: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x189314: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x189314u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189318: 0x8ea44140  lw          $a0, 0x4140($s5)
    ctx->pc = 0x189318u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
    // 0x18931c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x18931cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x189320: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x189320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x189324: 0xc045198  jal         func_114660
    ctx->pc = 0x189324u;
    SET_GPR_U32(ctx, 31, 0x18932Cu);
    ctx->pc = 0x189328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189324u;
            // 0x189328: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18932Cu; }
        if (ctx->pc != 0x18932Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18932Cu; }
        if (ctx->pc != 0x18932Cu) { return; }
    }
    ctx->pc = 0x18932Cu;
label_18932c:
    // 0x18932c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x18932cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x189330: 0xacf10c00  sw          $s1, 0xC00($a3)
    ctx->pc = 0x189330u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 3072), GPR_U32(ctx, 17));
    // 0x189334: 0x24f20c00  addiu       $s2, $a3, 0xC00
    ctx->pc = 0x189334u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
    // 0x189338: 0xae500004  sw          $s0, 0x4($s2)
    ctx->pc = 0x189338u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 16));
    // 0x18933c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x18933cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189340: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x189340u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x189344: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x189344u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189348: 0x1860000f  blez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x189348u;
    {
        const bool branch_taken_0x189348 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x18934Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189348u;
            // 0x18934c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189348) {
            ctx->pc = 0x189388u;
            goto label_189388;
        }
    }
    ctx->pc = 0x189350u;
    // 0x189350: 0x2646000c  addiu       $a2, $s2, 0xC
    ctx->pc = 0x189350u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x189354: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x189354u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x189358: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x189358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
    // 0x18935c: 0x0  nop
    ctx->pc = 0x18935cu;
    // NOP
label_189360:
    // 0x189360: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x189360u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x189364: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x189364u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x189368: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x189368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x18936c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x18936cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x189370: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x189370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189374: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x189374u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x189378: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189378u;
    {
        const bool branch_taken_0x189378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18937Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189378u;
            // 0x18937c: 0x2851021  addu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189378) {
            ctx->pc = 0x189360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189360;
        }
    }
    ctx->pc = 0x189380u;
    // 0x189380: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x189380u;
    {
        const bool branch_taken_0x189380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189380u;
            // 0x189384: 0x24e70c00  addiu       $a3, $a3, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189380) {
            ctx->pc = 0x189390u;
            goto label_189390;
        }
    }
    ctx->pc = 0x189388u;
label_189388:
    // 0x189388: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x189388u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x18938c: 0x24e70c00  addiu       $a3, $a3, 0xC00
    ctx->pc = 0x18938cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 3072));
label_189390:
    // 0x189390: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189390u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189394: 0x25040b88  addiu       $a0, $t0, 0xB88
    ctx->pc = 0x189394u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 2952));
    // 0x189398: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189398u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x18939c: 0x34a51319  ori         $a1, $a1, 0x1319
    ctx->pc = 0x18939cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4889);
    // 0x1893a0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1893a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1893a4: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x1893a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1893a8: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x1893a8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1893ac: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x1893acu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1893b0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1893B0u;
    SET_GPR_U32(ctx, 31, 0x1893B8u);
    ctx->pc = 0x1893B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893B0u;
            // 0x1893b4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893B8u; }
        if (ctx->pc != 0x1893B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893B8u; }
        if (ctx->pc != 0x1893B8u) { return; }
    }
    ctx->pc = 0x1893B8u;
label_1893b8:
    // 0x1893b8: 0x4430008  bgezl       $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1893B8u;
    {
        const bool branch_taken_0x1893b8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1893b8) {
            ctx->pc = 0x1893BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1893B8u;
            // 0x1893bc: 0x8e42020c  lw          $v0, 0x20C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 524)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1893DCu;
            goto label_1893dc;
        }
    }
    ctx->pc = 0x1893C0u;
    // 0x1893c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1893c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1893c4: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x1893C4u;
    SET_GPR_U32(ctx, 31, 0x1893CCu);
    ctx->pc = 0x1893C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893C4u;
            // 0x1893c8: 0x24841a08  addiu       $a0, $a0, 0x1A08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893CCu; }
        if (ctx->pc != 0x1893CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893CCu; }
        if (ctx->pc != 0x1893CCu) { return; }
    }
    ctx->pc = 0x1893CCu;
label_1893cc:
    // 0x1893cc: 0xc045190  jal         func_114640
    ctx->pc = 0x1893CCu;
    SET_GPR_U32(ctx, 31, 0x1893D4u);
    ctx->pc = 0x1893D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893CCu;
            // 0x1893d0: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893D4u; }
        if (ctx->pc != 0x1893D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893D4u; }
        if (ctx->pc != 0x1893D4u) { return; }
    }
    ctx->pc = 0x1893D4u;
label_1893d4:
    // 0x1893d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1893D4u;
    {
        const bool branch_taken_0x1893d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1893D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1893D4u;
            // 0x1893d8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1893d4) {
            ctx->pc = 0x1893F8u;
            goto label_1893f8;
        }
    }
    ctx->pc = 0x1893DCu;
label_1893dc:
    // 0x1893dc: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1893DCu;
    {
        const bool branch_taken_0x1893dc = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1893dc) {
            ctx->pc = 0x1893ECu;
            goto label_1893ec;
        }
    }
    ctx->pc = 0x1893E4u;
    // 0x1893e4: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x1893e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1893e8: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1893e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_1893ec:
    // 0x1893ec: 0xc045190  jal         func_114640
    ctx->pc = 0x1893ECu;
    SET_GPR_U32(ctx, 31, 0x1893F4u);
    ctx->pc = 0x1893F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1893ECu;
            // 0x1893f0: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893F4u; }
        if (ctx->pc != 0x1893F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1893F4u; }
        if (ctx->pc != 0x1893F4u) { return; }
    }
    ctx->pc = 0x1893F4u;
label_1893f4:
    // 0x1893f4: 0x8e42020c  lw          $v0, 0x20C($s2)
    ctx->pc = 0x1893f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 524)));
label_1893f8:
    // 0x1893f8: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1893f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1893fc: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x1893fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x189400: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x189400u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x189404: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x189404u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x189408: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x189408u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18940c: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x18940cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189410: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189410u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189414: 0x3e00008  jr          $ra
    ctx->pc = 0x189414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189414u;
            // 0x189418: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189180u: goto label_189180;
            case 0x189194u: goto label_189194;
            case 0x189198u: goto label_189198;
            case 0x189208u: goto label_189208;
            case 0x189230u: goto label_189230;
            case 0x189238u: goto label_189238;
            case 0x189260u: goto label_189260;
            case 0x189274u: goto label_189274;
            case 0x18927Cu: goto label_18927c;
            case 0x1892A8u: goto label_1892a8;
            case 0x1892D0u: goto label_1892d0;
            case 0x1892D4u: goto label_1892d4;
            case 0x1892D8u: goto label_1892d8;
            case 0x18932Cu: goto label_18932c;
            case 0x189360u: goto label_189360;
            case 0x189388u: goto label_189388;
            case 0x189390u: goto label_189390;
            case 0x1893B8u: goto label_1893b8;
            case 0x1893CCu: goto label_1893cc;
            case 0x1893D4u: goto label_1893d4;
            case 0x1893DCu: goto label_1893dc;
            case 0x1893ECu: goto label_1893ec;
            case 0x1893F4u: goto label_1893f4;
            case 0x1893F8u: goto label_1893f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18941Cu;
    // 0x18941c: 0x0  nop
    ctx->pc = 0x18941cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
