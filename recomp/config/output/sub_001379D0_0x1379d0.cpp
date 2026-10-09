#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001379D0
// Address: 0x1379d0 - 0x137ba0
void sub_001379D0_0x1379d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001379D0_0x1379d0");
#endif

    switch (ctx->pc) {
        case 0x137a28u: goto label_137a28;
        case 0x137a30u: goto label_137a30;
        case 0x137a3cu: goto label_137a3c;
        case 0x137a58u: goto label_137a58;
        case 0x137a60u: goto label_137a60;
        case 0x137a68u: goto label_137a68;
        case 0x137a70u: goto label_137a70;
        case 0x137ac0u: goto label_137ac0;
        case 0x137ad4u: goto label_137ad4;
        case 0x137ae0u: goto label_137ae0;
        case 0x137b3cu: goto label_137b3c;
        case 0x137b44u: goto label_137b44;
        case 0x137b50u: goto label_137b50;
        case 0x137b58u: goto label_137b58;
        default: break;
    }

    ctx->pc = 0x1379d0u;

    // 0x1379d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1379d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1379d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1379d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1379d8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1379d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1379dc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1379dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1379e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1379e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1379e4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1379e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1379e8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1379e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1379ec: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1379ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1379f0: 0x1443002c  bne         $v0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1379F0u;
    {
        const bool branch_taken_0x1379f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1379F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1379F0u;
            // 0x1379f4: 0x92250002  lbu         $a1, 0x2($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1379f0) {
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x1379F8u;
    // 0x1379f8: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x1379f8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1379fc: 0x2c62000a  sltiu       $v0, $v1, 0xA
    ctx->pc = 0x1379fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x137a00: 0x50400028  beql        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x137A00u;
    {
        const bool branch_taken_0x137a00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x137a00) {
            ctx->pc = 0x137A04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137A00u;
            // 0x137a04: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x137A08u;
    // 0x137a08: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x137a08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x137a0c: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x137a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x137a10: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x137a10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x137a14: 0x8c63c570  lw          $v1, -0x3A90($v1)
    ctx->pc = 0x137a14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294952304)));
    // 0x137a18: 0x600008  jr          $v1
    ctx->pc = 0x137A18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137A20u: goto label_137a20;
            case 0x137A98u: goto label_137a98;
            case 0x137AA0u: goto label_137aa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137A20u;
label_137a20:
    // 0x137a20: 0xc04e082  jal         func_138208
    ctx->pc = 0x137A20u;
    SET_GPR_U32(ctx, 31, 0x137A28u);
    ctx->pc = 0x137A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A20u;
            // 0x137a24: 0x24041600  addiu       $a0, $zero, 0x1600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A28u; }
        if (ctx->pc != 0x137A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A28u; }
        if (ctx->pc != 0x137A28u) { return; }
    }
    ctx->pc = 0x137A28u;
label_137a28:
    // 0x137a28: 0xc0406e0  jal         func_101B80
    ctx->pc = 0x137A28u;
    SET_GPR_U32(ctx, 31, 0x137A30u);
    ctx->pc = 0x101B80u;
    if (runtime->hasFunction(0x101B80u)) {
        auto targetFn = runtime->lookupFunction(0x101B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A30u; }
        if (ctx->pc != 0x137A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101B80_0x101b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A30u; }
        if (ctx->pc != 0x137A30u) { return; }
    }
    ctx->pc = 0x137A30u;
label_137a30:
    // 0x137a30: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x137a30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137a34: 0xc04e082  jal         func_138208
    ctx->pc = 0x137A34u;
    SET_GPR_U32(ctx, 31, 0x137A3Cu);
    ctx->pc = 0x137A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A34u;
            // 0x137a38: 0x24041601  addiu       $a0, $zero, 0x1601 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5633));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A3Cu; }
        if (ctx->pc != 0x137A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A3Cu; }
        if (ctx->pc != 0x137A3Cu) { return; }
    }
    ctx->pc = 0x137A3Cu;
label_137a3c:
    // 0x137a3c: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x137A3Cu;
    {
        const bool branch_taken_0x137a3c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x137A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137A3Cu;
            // 0x137a40: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137a3c) {
            ctx->pc = 0x137A58u;
            goto label_137a58;
        }
    }
    ctx->pc = 0x137A44u;
    // 0x137a44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x137a44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x137a48: 0x2442bbdc  addiu       $v0, $v0, -0x4424
    ctx->pc = 0x137a48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949852));
    // 0x137a4c: 0x2484c550  addiu       $a0, $a0, -0x3AB0
    ctx->pc = 0x137a4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952272));
    // 0x137a50: 0xc045a12  jal         func_116848
    ctx->pc = 0x137A50u;
    SET_GPR_U32(ctx, 31, 0x137A58u);
    ctx->pc = 0x137A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A50u;
            // 0x137a54: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A58u; }
        if (ctx->pc != 0x137A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A58u; }
        if (ctx->pc != 0x137A58u) { return; }
    }
    ctx->pc = 0x137A58u;
label_137a58:
    // 0x137a58: 0xc04e082  jal         func_138208
    ctx->pc = 0x137A58u;
    SET_GPR_U32(ctx, 31, 0x137A60u);
    ctx->pc = 0x137A5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A58u;
            // 0x137a5c: 0x24041700  addiu       $a0, $zero, 0x1700 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5888));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A60u; }
        if (ctx->pc != 0x137A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A60u; }
        if (ctx->pc != 0x137A60u) { return; }
    }
    ctx->pc = 0x137A60u;
label_137a60:
    // 0x137a60: 0xc04035e  jal         func_100D78
    ctx->pc = 0x137A60u;
    SET_GPR_U32(ctx, 31, 0x137A68u);
    ctx->pc = 0x137A64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A60u;
            // 0x137a64: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A68u; }
        if (ctx->pc != 0x137A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A68u; }
        if (ctx->pc != 0x137A68u) { return; }
    }
    ctx->pc = 0x137A68u;
label_137a68:
    // 0x137a68: 0xc04e082  jal         func_138208
    ctx->pc = 0x137A68u;
    SET_GPR_U32(ctx, 31, 0x137A70u);
    ctx->pc = 0x137A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137A68u;
            // 0x137a6c: 0x24041701  addiu       $a0, $zero, 0x1701 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5889));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A70u; }
        if (ctx->pc != 0x137A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A70u; }
        if (ctx->pc != 0x137A70u) { return; }
    }
    ctx->pc = 0x137A70u;
label_137a70:
    // 0x137a70: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x137a70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x137a74: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137a74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137a78: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x137a78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137a7c: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x137a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x137a80: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137a80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x137a84: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137a84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137a88: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137a88u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x137a8c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x137A8Cu;
    {
        const bool branch_taken_0x137a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137A8Cu;
            // 0x137a90: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137a8c) {
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x137A94u;
    // 0x137a94: 0x0  nop
    ctx->pc = 0x137a94u;
    // NOP
label_137a98:
    // 0x137a98: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x137a98u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x137a9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x137a9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137aa0:
    // 0x137aa0: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x137aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_137aa4:
    // 0x137aa4: 0x51600  sll         $v0, $a1, 24
    ctx->pc = 0x137aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x137aa8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137aa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137aac: 0x29603  sra         $s2, $v0, 24
    ctx->pc = 0x137aacu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 2), 24));
    // 0x137ab0: 0x5643001d  bnel        $s2, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x137AB0u;
    {
        const bool branch_taken_0x137ab0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 3));
        if (branch_taken_0x137ab0) {
            ctx->pc = 0x137AB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137AB0u;
            // 0x137ab4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137B28u;
            goto label_137b28;
        }
    }
    ctx->pc = 0x137AB8u;
    // 0x137ab8: 0xc04e082  jal         func_138208
    ctx->pc = 0x137AB8u;
    SET_GPR_U32(ctx, 31, 0x137AC0u);
    ctx->pc = 0x137ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137AB8u;
            // 0x137abc: 0x24041800  addiu       $a0, $zero, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AC0u; }
        if (ctx->pc != 0x137AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AC0u; }
        if (ctx->pc != 0x137AC0u) { return; }
    }
    ctx->pc = 0x137AC0u;
label_137ac0:
    // 0x137ac0: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x137ac0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x137ac4: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x137ac4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x137ac8: 0x26270014  addiu       $a3, $s1, 0x14
    ctx->pc = 0x137ac8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x137acc: 0xc0405e2  jal         func_101788
    ctx->pc = 0x137ACCu;
    SET_GPR_U32(ctx, 31, 0x137AD4u);
    ctx->pc = 0x137AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137ACCu;
            // 0x137ad0: 0x8e260010  lw          $a2, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101788u;
    if (runtime->hasFunction(0x101788u)) {
        auto targetFn = runtime->lookupFunction(0x101788u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AD4u; }
        if (ctx->pc != 0x137AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101788_0x101788(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AD4u; }
        if (ctx->pc != 0x137AD4u) { return; }
    }
    ctx->pc = 0x137AD4u;
label_137ad4:
    // 0x137ad4: 0x24041801  addiu       $a0, $zero, 0x1801
    ctx->pc = 0x137ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6145));
    // 0x137ad8: 0xc04e082  jal         func_138208
    ctx->pc = 0x137AD8u;
    SET_GPR_U32(ctx, 31, 0x137AE0u);
    ctx->pc = 0x137ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137AD8u;
            // 0x137adc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AE0u; }
        if (ctx->pc != 0x137AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AE0u; }
        if (ctx->pc != 0x137AE0u) { return; }
    }
    ctx->pc = 0x137AE0u;
label_137ae0:
    // 0x137ae0: 0x1612000b  bne         $s0, $s2, . + 4 + (0xB << 2)
    ctx->pc = 0x137AE0u;
    {
        const bool branch_taken_0x137ae0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 18));
        ctx->pc = 0x137AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137AE0u;
            // 0x137ae4: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137ae0) {
            ctx->pc = 0x137B10u;
            goto label_137b10;
        }
    }
    ctx->pc = 0x137AE8u;
    // 0x137ae8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137aec: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x137aecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x137af0: 0x2442bbe0  addiu       $v0, $v0, -0x4420
    ctx->pc = 0x137af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949856));
    // 0x137af4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x137af4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x137af8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x137af8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x137afc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x137afcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x137b00: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x137b00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x137b04: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x137B04u;
    {
        const bool branch_taken_0x137b04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137B04u;
            // 0x137b08: 0xa2240002  sb          $a0, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137b04) {
            ctx->pc = 0x137B20u;
            goto label_137b20;
        }
    }
    ctx->pc = 0x137B0Cu;
    // 0x137b0c: 0x0  nop
    ctx->pc = 0x137b0cu;
    // NOP
label_137b10:
    // 0x137b10: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x137b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x137b14: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137b14u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137b18: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x137b18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137b1c: 0xae230034  sw          $v1, 0x34($s1)
    ctx->pc = 0x137b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
label_137b20:
    // 0x137b20: 0x51600  sll         $v0, $a1, 24
    ctx->pc = 0x137b20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x137b24: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x137b24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_137b28:
    // 0x137b28: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x137b28u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x137b2c: 0x14430017  bne         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x137B2Cu;
    {
        const bool branch_taken_0x137b2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x137B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137B2Cu;
            // 0x137b30: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137b2c) {
            ctx->pc = 0x137B8Cu;
            goto label_137b8c;
        }
    }
    ctx->pc = 0x137B34u;
    // 0x137b34: 0xc04e082  jal         func_138208
    ctx->pc = 0x137B34u;
    SET_GPR_U32(ctx, 31, 0x137B3Cu);
    ctx->pc = 0x137B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137B34u;
            // 0x137b38: 0x24041900  addiu       $a0, $zero, 0x1900 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B3Cu; }
        if (ctx->pc != 0x137B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B3Cu; }
        if (ctx->pc != 0x137B3Cu) { return; }
    }
    ctx->pc = 0x137B3Cu;
label_137b3c:
    // 0x137b3c: 0xc04035e  jal         func_100D78
    ctx->pc = 0x137B3Cu;
    SET_GPR_U32(ctx, 31, 0x137B44u);
    ctx->pc = 0x137B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137B3Cu;
            // 0x137b40: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B44u; }
        if (ctx->pc != 0x137B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B44u; }
        if (ctx->pc != 0x137B44u) { return; }
    }
    ctx->pc = 0x137B44u;
label_137b44:
    // 0x137b44: 0x24041901  addiu       $a0, $zero, 0x1901
    ctx->pc = 0x137b44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6401));
    // 0x137b48: 0xc04e082  jal         func_138208
    ctx->pc = 0x137B48u;
    SET_GPR_U32(ctx, 31, 0x137B50u);
    ctx->pc = 0x137B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137B48u;
            // 0x137b4c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B50u; }
        if (ctx->pc != 0x137B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B50u; }
        if (ctx->pc != 0x137B50u) { return; }
    }
    ctx->pc = 0x137B50u;
label_137b50:
    // 0x137b50: 0xc04de34  jal         func_1378D0
    ctx->pc = 0x137B50u;
    SET_GPR_U32(ctx, 31, 0x137B58u);
    ctx->pc = 0x137B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137B50u;
            // 0x137b54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1378D0u;
    if (runtime->hasFunction(0x1378D0u)) {
        auto targetFn = runtime->lookupFunction(0x1378D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B58u; }
        if (ctx->pc != 0x137B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001378D0_0x1378d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B58u; }
        if (ctx->pc != 0x137B58u) { return; }
    }
    ctx->pc = 0x137B58u;
label_137b58:
    // 0x137b58: 0x1600000b  bnez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x137B58u;
    {
        const bool branch_taken_0x137b58 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x137B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137B58u;
            // 0x137b5c: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137b58) {
            ctx->pc = 0x137B88u;
            goto label_137b88;
        }
    }
    ctx->pc = 0x137B60u;
    // 0x137b60: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x137b60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137b64: 0x54620002  bnel        $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x137B64u;
    {
        const bool branch_taken_0x137b64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x137b64) {
            ctx->pc = 0x137B68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137B64u;
            // 0x137b68: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137B70u;
            goto label_137b70;
        }
    }
    ctx->pc = 0x137B6Cu;
    // 0x137b6c: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_137b70:
    // 0x137b70: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137b70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137b74: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137b74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137b78: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x137b78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x137b7c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x137b80: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x137b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137b84: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137b84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137b88:
    // 0x137b88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_137b8c:
    // 0x137b8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137b8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137b90: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137b90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137b94: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x137b94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137b98: 0x3e00008  jr          $ra
    ctx->pc = 0x137B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137B98u;
            // 0x137b9c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137A20u: goto label_137a20;
            case 0x137A28u: goto label_137a28;
            case 0x137A30u: goto label_137a30;
            case 0x137A3Cu: goto label_137a3c;
            case 0x137A58u: goto label_137a58;
            case 0x137A60u: goto label_137a60;
            case 0x137A68u: goto label_137a68;
            case 0x137A70u: goto label_137a70;
            case 0x137A98u: goto label_137a98;
            case 0x137AA0u: goto label_137aa0;
            case 0x137AA4u: goto label_137aa4;
            case 0x137AC0u: goto label_137ac0;
            case 0x137AD4u: goto label_137ad4;
            case 0x137AE0u: goto label_137ae0;
            case 0x137B10u: goto label_137b10;
            case 0x137B20u: goto label_137b20;
            case 0x137B28u: goto label_137b28;
            case 0x137B3Cu: goto label_137b3c;
            case 0x137B44u: goto label_137b44;
            case 0x137B50u: goto label_137b50;
            case 0x137B58u: goto label_137b58;
            case 0x137B70u: goto label_137b70;
            case 0x137B88u: goto label_137b88;
            case 0x137B8Cu: goto label_137b8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137BA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
