#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CAD8
// Address: 0x11cad8 - 0x11cc58
void sub_0011CAD8_0x11cad8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CAD8_0x11cad8");
#endif

    switch (ctx->pc) {
        case 0x11cafcu: goto label_11cafc;
        case 0x11cb08u: goto label_11cb08;
        case 0x11cb10u: goto label_11cb10;
        case 0x11cb1cu: goto label_11cb1c;
        case 0x11cb40u: goto label_11cb40;
        case 0x11cbbcu: goto label_11cbbc;
        case 0x11cbc8u: goto label_11cbc8;
        case 0x11cbd4u: goto label_11cbd4;
        case 0x11cbe4u: goto label_11cbe4;
        case 0x11cbf0u: goto label_11cbf0;
        case 0x11cc00u: goto label_11cc00;
        case 0x11cc0cu: goto label_11cc0c;
        case 0x11cc40u: goto label_11cc40;
        default: break;
    }

    ctx->pc = 0x11cad8u;

    // 0x11cad8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11cad8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11cadc: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11cadcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11cae0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11cae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11cae4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11cae4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cae8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x11cae8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11caec: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11caecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11caf0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x11caf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11caf4: 0xc047df4  jal         func_11F7D0
    ctx->pc = 0x11CAF4u;
    SET_GPR_U32(ctx, 31, 0x11CAFCu);
    ctx->pc = 0x11CAF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CAF4u;
            // 0x11caf8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F7D0u;
    if (runtime->hasFunction(0x11F7D0u)) {
        auto targetFn = runtime->lookupFunction(0x11F7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAFCu; }
        if (ctx->pc != 0x11CAFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F7D0_0x11f7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAFCu; }
        if (ctx->pc != 0x11CAFCu) { return; }
    }
    ctx->pc = 0x11CAFCu;
label_11cafc:
    // 0x11cafc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x11cafcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11cb00: 0xc047df4  jal         func_11F7D0
    ctx->pc = 0x11CB00u;
    SET_GPR_U32(ctx, 31, 0x11CB08u);
    ctx->pc = 0x11CB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CB00u;
            // 0x11cb04: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F7D0u;
    if (runtime->hasFunction(0x11F7D0u)) {
        auto targetFn = runtime->lookupFunction(0x11F7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB08u; }
        if (ctx->pc != 0x11CB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F7D0_0x11f7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB08u; }
        if (ctx->pc != 0x11CB08u) { return; }
    }
    ctx->pc = 0x11CB08u;
label_11cb08:
    // 0x11cb08: 0xc04523c  jal         func_1148F0
    ctx->pc = 0x11CB08u;
    SET_GPR_U32(ctx, 31, 0x11CB10u);
    ctx->pc = 0x1148F0u;
    if (runtime->hasFunction(0x1148F0u)) {
        auto targetFn = runtime->lookupFunction(0x1148F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB10u; }
        if (ctx->pc != 0x11CB10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148F0_0x1148f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB10u; }
        if (ctx->pc != 0x11CB10u) { return; }
    }
    ctx->pc = 0x11CB10u;
label_11cb10:
    // 0x11cb10: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11cb10u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x11cb14: 0xc04528c  jal         func_114A30
    ctx->pc = 0x11CB14u;
    SET_GPR_U32(ctx, 31, 0x11CB1Cu);
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB1Cu; }
        if (ctx->pc != 0x11CB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CB1Cu; }
        if (ctx->pc != 0x11CB1Cu) { return; }
    }
    ctx->pc = 0x11CB1Cu;
label_11cb1c:
    // 0x11cb1c: 0x3c0a0026  lui         $t2, 0x26
    ctx->pc = 0x11cb1cu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)38 << 16));
    // 0x11cb20: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x11cb20u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cb24: 0x2543e640  addiu       $v1, $t2, -0x19C0
    ctx->pc = 0x11cb24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), 4294960704));
    // 0x11cb28: 0xac700014  sw          $s0, 0x14($v1)
    ctx->pc = 0x11cb28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 16));
    // 0x11cb2c: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x11cb2cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11cb30: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x11CB30u;
    {
        const bool branch_taken_0x11cb30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CB30u;
            // 0x11cb34: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cb30) {
            ctx->pc = 0x11CB60u;
            goto label_11cb60;
        }
    }
    ctx->pc = 0x11CB38u;
    // 0x11cb38: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x11cb38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cb3c: 0x90440000  lbu         $a0, 0x0($v0)
    ctx->pc = 0x11cb3cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
label_11cb40:
    // 0x11cb40: 0x2543e640  addiu       $v1, $t2, -0x19C0
    ctx->pc = 0x11cb40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), 4294960704));
    // 0x11cb44: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x11cb44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x11cb48: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x11cb48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x11cb4c: 0xa0640018  sb          $a0, 0x18($v1)
    ctx->pc = 0x11cb4cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 24), (uint8_t)GPR_U32(ctx, 4));
    // 0x11cb50: 0x2291021  addu        $v0, $s1, $t1
    ctx->pc = 0x11cb50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 9)));
    // 0x11cb54: 0x80430000  lb          $v1, 0x0($v0)
    ctx->pc = 0x11cb54u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11cb58: 0x5460fff9  bnel        $v1, $zero, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11CB58u;
    {
        const bool branch_taken_0x11cb58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11cb58) {
            ctx->pc = 0x11CB5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11CB58u;
            // 0x11cb5c: 0x90440000  lbu         $a0, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11CB40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11cb40;
        }
    }
    ctx->pc = 0x11CB60u;
label_11cb60:
    // 0x11cb60: 0x2546e640  addiu       $a2, $t2, -0x19C0
    ctx->pc = 0x11cb60u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 10), 4294960704));
    // 0x11cb64: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x11cb64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x11cb68: 0xacc00004  sw          $zero, 0x4($a2)
    ctx->pc = 0x11cb68u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 0));
    // 0x11cb6c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x11cb6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11cb70: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x11cb70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x11cb74: 0x348400ff  ori         $a0, $a0, 0xFF
    ctx->pc = 0x11cb74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)255);
    // 0x11cb78: 0x34630003  ori         $v1, $v1, 0x3
    ctx->pc = 0x11cb78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)3);
    // 0x11cb7c: 0x24050068  addiu       $a1, $zero, 0x68
    ctx->pc = 0x11cb7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x11cb80: 0xdd42e640  ld          $v0, -0x19C0($t2)
    ctx->pc = 0x11cb80u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 10), 4294960704)));
    // 0x11cb84: 0x24070068  addiu       $a3, $zero, 0x68
    ctx->pc = 0x11cb84u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x11cb88: 0xacc90010  sw          $t1, 0x10($a2)
    ctx->pc = 0x11cb88u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 9));
    // 0x11cb8c: 0x24080044  addiu       $t0, $zero, 0x44
    ctx->pc = 0x11cb8cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x11cb90: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x11cb90u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x11cb94: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x11cb94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x11cb98: 0xfd42e640  sd          $v0, -0x19C0($t2)
    ctx->pc = 0x11cb98u;
    WRITE64(ADD32(GPR_U32(ctx, 10), 4294960704), GPR_U64(ctx, 2));
    // 0x11cb9c: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x11cb9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cba0: 0xa145e640  sb          $a1, -0x19C0($t2)
    ctx->pc = 0x11cba0u;
    WRITE8(ADD32(GPR_U32(ctx, 10), 4294960704), (uint8_t)GPR_U32(ctx, 5));
    // 0x11cba4: 0x24050068  addiu       $a1, $zero, 0x68
    ctx->pc = 0x11cba4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x11cba8: 0xafab0004  sw          $t3, 0x4($sp)
    ctx->pc = 0x11cba8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 11));
    // 0x11cbac: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x11cbacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x11cbb0: 0xafa8000c  sw          $t0, 0xC($sp)
    ctx->pc = 0x11cbb0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 8));
    // 0x11cbb4: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11CBB4u;
    SET_GPR_U32(ctx, 31, 0x11CBBCu);
    ctx->pc = 0x11CBB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBB4u;
            // 0x11cbb8: 0xafa60000  sw          $a2, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBBCu; }
        if (ctx->pc != 0x11CBBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBBCu; }
        if (ctx->pc != 0x11CBBCu) { return; }
    }
    ctx->pc = 0x11CBBCu;
label_11cbbc:
    // 0x11cbbc: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x11cbbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11cbc0: 0xc045288  jal         func_114A20
    ctx->pc = 0x11CBC0u;
    SET_GPR_U32(ctx, 31, 0x11CBC8u);
    ctx->pc = 0x11CBC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBC0u;
            // 0x11cbc4: 0x3c050004  lui         $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBC8u; }
        if (ctx->pc != 0x11CBC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBC8u; }
        if (ctx->pc != 0x11CBC8u) { return; }
    }
    ctx->pc = 0x11CBC8u;
label_11cbc8:
    // 0x11cbc8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x11cbc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cbcc: 0xc045278  jal         func_1149E0
    ctx->pc = 0x11CBCCu;
    SET_GPR_U32(ctx, 31, 0x11CBD4u);
    ctx->pc = 0x11CBD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBCCu;
            // 0x11cbd0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBD4u; }
        if (ctx->pc != 0x11CBD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBD4u; }
        if (ctx->pc != 0x11CBD4u) { return; }
    }
    ctx->pc = 0x11CBD4u;
label_11cbd4:
    // 0x11cbd4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11CBD4u;
    {
        const bool branch_taken_0x11cbd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CBD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBD4u;
            // 0x11cbd8: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cbd4) {
            ctx->pc = 0x11CC14u;
            goto label_11cc14;
        }
    }
    ctx->pc = 0x11CBDCu;
    // 0x11cbdc: 0xc045288  jal         func_114A20
    ctx->pc = 0x11CBDCu;
    SET_GPR_U32(ctx, 31, 0x11CBE4u);
    ctx->pc = 0x11CBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBDCu;
            // 0x11cbe0: 0x3c050001  lui         $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBE4u; }
        if (ctx->pc != 0x11CBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBE4u; }
        if (ctx->pc != 0x11CBE4u) { return; }
    }
    ctx->pc = 0x11CBE4u;
label_11cbe4:
    // 0x11cbe4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x11cbe4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11cbe8: 0xc045288  jal         func_114A20
    ctx->pc = 0x11CBE8u;
    SET_GPR_U32(ctx, 31, 0x11CBF0u);
    ctx->pc = 0x11CBECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBE8u;
            // 0x11cbec: 0x3c050002  lui         $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)2 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBF0u; }
        if (ctx->pc != 0x11CBF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CBF0u; }
        if (ctx->pc != 0x11CBF0u) { return; }
    }
    ctx->pc = 0x11CBF0u;
label_11cbf0:
    // 0x11cbf0: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11cbf0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x11cbf4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11cbf4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cbf8: 0xc045288  jal         func_114A20
    ctx->pc = 0x11CBF8u;
    SET_GPR_U32(ctx, 31, 0x11CC00u);
    ctx->pc = 0x11CBFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CBF8u;
            // 0x11cbfc: 0x34840002  ori         $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC00u; }
        if (ctx->pc != 0x11CC00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC00u; }
        if (ctx->pc != 0x11CC00u) { return; }
    }
    ctx->pc = 0x11CC00u;
label_11cc00:
    // 0x11cc00: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11cc00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x11cc04: 0xc045288  jal         func_114A20
    ctx->pc = 0x11CC04u;
    SET_GPR_U32(ctx, 31, 0x11CC0Cu);
    ctx->pc = 0x11CC08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC04u;
            // 0x11cc08: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A20u;
    if (runtime->hasFunction(0x114A20u)) {
        auto targetFn = runtime->lookupFunction(0x114A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC0Cu; }
        if (ctx->pc != 0x11CC0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A20_0x114a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC0Cu; }
        if (ctx->pc != 0x11CC0Cu) { return; }
    }
    ctx->pc = 0x11CC0Cu;
label_11cc0c:
    // 0x11cc0c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11CC0Cu;
    {
        const bool branch_taken_0x11cc0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CC10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC0Cu;
            // 0x11cc10: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cc0c) {
            ctx->pc = 0x11CC18u;
            goto label_11cc18;
        }
    }
    ctx->pc = 0x11CC14u;
label_11cc14:
    // 0x11cc14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11cc14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11cc18:
    // 0x11cc18: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11cc18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11cc1c: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11cc1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11cc20: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11cc20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11cc24: 0x3e00008  jr          $ra
    ctx->pc = 0x11CC24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CC28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC24u;
            // 0x11cc28: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CAFCu: goto label_11cafc;
            case 0x11CB08u: goto label_11cb08;
            case 0x11CB10u: goto label_11cb10;
            case 0x11CB1Cu: goto label_11cb1c;
            case 0x11CB40u: goto label_11cb40;
            case 0x11CB60u: goto label_11cb60;
            case 0x11CBBCu: goto label_11cbbc;
            case 0x11CBC8u: goto label_11cbc8;
            case 0x11CBD4u: goto label_11cbd4;
            case 0x11CBE4u: goto label_11cbe4;
            case 0x11CBF0u: goto label_11cbf0;
            case 0x11CC00u: goto label_11cc00;
            case 0x11CC0Cu: goto label_11cc0c;
            case 0x11CC14u: goto label_11cc14;
            case 0x11CC18u: goto label_11cc18;
            case 0x11CC40u: goto label_11cc40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CC2Cu;
    // 0x11cc2c: 0x0  nop
    ctx->pc = 0x11cc2cu;
    // NOP
    // 0x11cc30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11cc30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11cc34: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11cc34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11cc38: 0xc04528c  jal         func_114A30
    ctx->pc = 0x11CC38u;
    SET_GPR_U32(ctx, 31, 0x11CC40u);
    ctx->pc = 0x11CC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC38u;
            // 0x11cc3c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC40u; }
        if (ctx->pc != 0x11CC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC40u; }
        if (ctx->pc != 0x11CC40u) { return; }
    }
    ctx->pc = 0x11CC40u;
label_11cc40:
    // 0x11cc40: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x11cc40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x11cc44: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11cc44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11cc48: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x11cc48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x11cc4c: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x11cc4cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11cc50: 0x3e00008  jr          $ra
    ctx->pc = 0x11CC50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC50u;
            // 0x11cc54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CAFCu: goto label_11cafc;
            case 0x11CB08u: goto label_11cb08;
            case 0x11CB10u: goto label_11cb10;
            case 0x11CB1Cu: goto label_11cb1c;
            case 0x11CB40u: goto label_11cb40;
            case 0x11CB60u: goto label_11cb60;
            case 0x11CBBCu: goto label_11cbbc;
            case 0x11CBC8u: goto label_11cbc8;
            case 0x11CBD4u: goto label_11cbd4;
            case 0x11CBE4u: goto label_11cbe4;
            case 0x11CBF0u: goto label_11cbf0;
            case 0x11CC00u: goto label_11cc00;
            case 0x11CC0Cu: goto label_11cc0c;
            case 0x11CC14u: goto label_11cc14;
            case 0x11CC18u: goto label_11cc18;
            case 0x11CC40u: goto label_11cc40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CC58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
