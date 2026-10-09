#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001891A8
// Address: 0x1891a8 - 0x1892f0
void sub_001891A8_0x1891a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001891A8_0x1891a8");
#endif

    switch (ctx->pc) {
        case 0x189208u: goto label_189208;
        case 0x189260u: goto label_189260;
        case 0x189274u: goto label_189274;
        case 0x1892a8u: goto label_1892a8;
        default: break;
    }

    ctx->pc = 0x1891a8u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1892F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
