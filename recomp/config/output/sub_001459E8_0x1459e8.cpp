#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001459E8
// Address: 0x1459e8 - 0x145b58
void sub_001459E8_0x1459e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001459E8_0x1459e8");
#endif

    switch (ctx->pc) {
        case 0x145a48u: goto label_145a48;
        case 0x145a5cu: goto label_145a5c;
        case 0x145ad4u: goto label_145ad4;
        case 0x145b28u: goto label_145b28;
        default: break;
    }

    ctx->pc = 0x1459e8u;

    // 0x1459e8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1459e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1459ec: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1459ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1459f0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1459f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1459f4: 0x34422010  ori         $v0, $v0, 0x2010
    ctx->pc = 0x1459f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8208);
    // 0x1459f8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1459f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1459fc: 0x3c068000  lui         $a2, 0x8000
    ctx->pc = 0x1459fcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32768 << 16));
    // 0x145a00: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x145a00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x145a04: 0x34c64000  ori         $a2, $a2, 0x4000
    ctx->pc = 0x145a04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16384);
    // 0x145a08: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x145a08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x145a0c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x145a0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a10: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x145a10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145a14: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x145a14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a18: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x145a18u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a1c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x145a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145a20: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x145a20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x145a24: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x145a24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x145a28: 0x1462001b  bne         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x145A28u;
    {
        const bool branch_taken_0x145a28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x145A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145A28u;
            // 0x145a2c: 0x3c130023  lui         $s3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145a28) {
            ctx->pc = 0x145A98u;
            goto label_145a98;
        }
    }
    ctx->pc = 0x145A30u;
    // 0x145a30: 0x8e2210a0  lw          $v0, 0x10A0($s1)
    ctx->pc = 0x145a30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4256)));
    // 0x145a34: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x145A34u;
    {
        const bool branch_taken_0x145a34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x145a34) {
            ctx->pc = 0x145A38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x145A34u;
            // 0x145a38: 0x8e220830  lw          $v0, 0x830($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2096)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A3Cu;
    // 0x145a3c: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x145a3cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x145a40: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x145a40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a44: 0x0  nop
    ctx->pc = 0x145a44u;
    // NOP
label_145a48:
    // 0x145a48: 0x28421389  slti        $v0, $v0, 0x1389
    ctx->pc = 0x145a48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5001) ? 1 : 0);
    // 0x145a4c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x145A4Cu;
    {
        const bool branch_taken_0x145a4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145A4Cu;
            // 0x145a50: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145a4c) {
            ctx->pc = 0x145A60u;
            goto label_145a60;
        }
    }
    ctx->pc = 0x145A54u;
    // 0x145a54: 0xc051ff8  jal         func_147FE0
    ctx->pc = 0x145A54u;
    SET_GPR_U32(ctx, 31, 0x145A5Cu);
    ctx->pc = 0x145A58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145A54u;
            // 0x145a58: 0x8e240870  lw          $a0, 0x870($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x147FE0u;
    if (runtime->hasFunction(0x147FE0u)) {
        auto targetFn = runtime->lookupFunction(0x147FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145A5Cu; }
        if (ctx->pc != 0x145A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145A5Cu; }
        if (ctx->pc != 0x145A5Cu) { return; }
    }
    ctx->pc = 0x145A5Cu;
label_145a5c:
    // 0x145a5c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x145a5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_145a60:
    // 0x145a60: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x145a60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x145a64: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x145a64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x145a68: 0x34632010  ori         $v1, $v1, 0x2010
    ctx->pc = 0x145a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8208);
    // 0x145a6c: 0x34844000  ori         $a0, $a0, 0x4000
    ctx->pc = 0x145a6cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)16384);
    // 0x145a70: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x145a70u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x145a74: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x145a74u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x145a78: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x145a78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x145a7c: 0x54450007  bnel        $v0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x145A7Cu;
    {
        const bool branch_taken_0x145a7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x145a7c) {
            ctx->pc = 0x145A80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x145A7Cu;
            // 0x145a80: 0x8e220830  lw          $v0, 0x830($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2096)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A84u;
    // 0x145a84: 0x8e2210a0  lw          $v0, 0x10A0($s1)
    ctx->pc = 0x145a84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4256)));
    // 0x145a88: 0x1040ffef  beqz        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x145A88u;
    {
        const bool branch_taken_0x145a88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145A88u;
            // 0x145a8c: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145a88) {
            ctx->pc = 0x145A48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_145a48;
        }
    }
    ctx->pc = 0x145A90u;
    // 0x145a90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x145A90u;
    {
        const bool branch_taken_0x145a90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145A90u;
            // 0x145a94: 0x8e220830  lw          $v0, 0x830($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2096)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145a90) {
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A98u;
label_145a98:
    // 0x145a98: 0x8e220830  lw          $v0, 0x830($s1)
    ctx->pc = 0x145a98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2096)));
label_145a9c:
    // 0x145a9c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x145A9Cu;
    {
        const bool branch_taken_0x145a9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x145AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145A9Cu;
            // 0x145aa0: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145a9c) {
            ctx->pc = 0x145AB4u;
            goto label_145ab4;
        }
    }
    ctx->pc = 0x145AA4u;
    // 0x145aa4: 0x8e220854  lw          $v0, 0x854($s1)
    ctx->pc = 0x145aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2132)));
    // 0x145aa8: 0x52102a  slt         $v0, $v0, $s2
    ctx->pc = 0x145aa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x145aac: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x145AACu;
    {
        const bool branch_taken_0x145aac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x145AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145AACu;
            // 0x145ab0: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145aac) {
            ctx->pc = 0x145AE0u;
            goto label_145ae0;
        }
    }
    ctx->pc = 0x145AB4u;
label_145ab4:
    // 0x145ab4: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x145ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x145ab8: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x145ab8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x145abc: 0x2665a6f8  addiu       $a1, $s3, -0x5908
    ctx->pc = 0x145abcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294944504));
    // 0x145ac0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x145ac0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x145ac4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x145ac4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145ac8: 0x8ca20010  lw          $v0, 0x10($a1)
    ctx->pc = 0x145ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x145acc: 0xc0514f0  jal         func_1453C0
    ctx->pc = 0x145ACCu;
    SET_GPR_U32(ctx, 31, 0x145AD4u);
    ctx->pc = 0x145AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145ACCu;
            // 0x145ad0: 0xae220830  sw          $v0, 0x830($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2096), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1453C0u;
    if (runtime->hasFunction(0x1453C0u)) {
        auto targetFn = runtime->lookupFunction(0x1453C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145AD4u; }
        if (ctx->pc != 0x145AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145AD4u; }
        if (ctx->pc != 0x145AD4u) { return; }
    }
    ctx->pc = 0x145AD4u;
label_145ad4:
    // 0x145ad4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x145ad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x145ad8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x145ad8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x145adc: 0xae220850  sw          $v0, 0x850($s1)
    ctx->pc = 0x145adcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2128), GPR_U32(ctx, 2));
label_145ae0:
    // 0x145ae0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x145ae0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x145ae4: 0x3c044000  lui         $a0, 0x4000
    ctx->pc = 0x145ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16384 << 16));
    // 0x145ae8: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x145aec: 0x2442025  or          $a0, $s2, $a0
    ctx->pc = 0x145aecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) | GPR_U64(ctx, 4));
    // 0x145af0: 0xae250854  sw          $a1, 0x854($s1)
    ctx->pc = 0x145af0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2132), GPR_U32(ctx, 5));
    // 0x145af4: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x145af4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x145af8: 0x8e300850  lw          $s0, 0x850($s1)
    ctx->pc = 0x145af8u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2128)));
    // 0x145afc: 0x41f02  srl         $v1, $a0, 28
    ctx->pc = 0x145afcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 28));
    // 0x145b00: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x145b00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x145b04: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x145b04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x145b08: 0x2662a6f8  addiu       $v0, $s3, -0x5908
    ctx->pc = 0x145b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 4294944504));
    // 0x145b0c: 0xb22823  subu        $a1, $a1, $s2
    ctx->pc = 0x145b0cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0x145b10: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x145b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x145b14: 0xb08006  srlv        $s0, $s0, $a1
    ctx->pc = 0x145b14u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 5) & 0x1F));
    // 0x145b18: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x145b18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x145b1c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x145b1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b20: 0xc0514f0  jal         func_1453C0
    ctx->pc = 0x145B20u;
    SET_GPR_U32(ctx, 31, 0x145B28u);
    ctx->pc = 0x145B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145B20u;
            // 0x145b24: 0xae220830  sw          $v0, 0x830($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2096), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1453C0u;
    if (runtime->hasFunction(0x1453C0u)) {
        auto targetFn = runtime->lookupFunction(0x1453C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B28u; }
        if (ctx->pc != 0x145B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B28u; }
        if (ctx->pc != 0x145B28u) { return; }
    }
    ctx->pc = 0x145B28u;
label_145b28:
    // 0x145b28: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x145b28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x145b2c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x145b2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x145b30: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x145b30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x145b34: 0xae220850  sw          $v0, 0x850($s1)
    ctx->pc = 0x145b34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2128), GPR_U32(ctx, 2));
    // 0x145b38: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x145b38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b3c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x145b3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145b40: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x145b40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x145b44: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x145b44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145b48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x145b48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145b4c: 0x3e00008  jr          $ra
    ctx->pc = 0x145B4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145B4Cu;
            // 0x145b50: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145A48u: goto label_145a48;
            case 0x145A5Cu: goto label_145a5c;
            case 0x145A60u: goto label_145a60;
            case 0x145A98u: goto label_145a98;
            case 0x145A9Cu: goto label_145a9c;
            case 0x145AB4u: goto label_145ab4;
            case 0x145AD4u: goto label_145ad4;
            case 0x145AE0u: goto label_145ae0;
            case 0x145B28u: goto label_145b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145B54u;
    // 0x145b54: 0x0  nop
    ctx->pc = 0x145b54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
