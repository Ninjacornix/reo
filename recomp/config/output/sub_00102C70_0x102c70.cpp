#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102C70
// Address: 0x102c70 - 0x102e48
void sub_00102C70_0x102c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102C70_0x102c70");
#endif

    switch (ctx->pc) {
        case 0x102cacu: goto label_102cac;
        default: break;
    }

    ctx->pc = 0x102c70u;

    // 0x102c70: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x102c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x102c74: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x102c74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102c78: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x102c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x102c7c: 0x34423c40  ori         $v0, $v0, 0x3C40
    ctx->pc = 0x102c7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15424);
    // 0x102c80: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x102c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x102c84: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x102c84u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102c88: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x102c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x102c8c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x102c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x102c90: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x102c90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x102c94: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x102c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x102c98: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x102c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102c9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102ca0: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x102ca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x102ca4: 0xc040b08  jal         func_102C20
    ctx->pc = 0x102CA4u;
    SET_GPR_U32(ctx, 31, 0x102CACu);
    ctx->pc = 0x102CA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102CA4u;
            // 0x102ca8: 0x8c570000  lw          $s7, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102C20u;
    if (runtime->hasFunction(0x102C20u)) {
        auto targetFn = runtime->lookupFunction(0x102C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102CACu; }
        if (ctx->pc != 0x102CACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102C20_0x102c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102CACu; }
        if (ctx->pc != 0x102CACu) { return; }
    }
    ctx->pc = 0x102CACu;
label_102cac:
    // 0x102cac: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x102cacu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x102cb0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102CB0u;
    {
        const bool branch_taken_0x102cb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102CB0u;
            // 0x102cb4: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102cb0) {
            ctx->pc = 0x102CC0u;
            goto label_102cc0;
        }
    }
    ctx->pc = 0x102CB8u;
    // 0x102cb8: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x102CB8u;
    {
        const bool branch_taken_0x102cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102CB8u;
            // 0x102cbc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102cb8) {
            ctx->pc = 0x102E1Cu;
            goto label_102e1c;
        }
    }
    ctx->pc = 0x102CC0u;
label_102cc0:
    // 0x102cc0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102cc4: 0x34423d00  ori         $v0, $v0, 0x3D00
    ctx->pc = 0x102cc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15616);
    // 0x102cc8: 0x34633d10  ori         $v1, $v1, 0x3D10
    ctx->pc = 0x102cc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15632);
    // 0x102ccc: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x102cccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x102cd0: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x102cd0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x102cd4: 0x34843d20  ori         $a0, $a0, 0x3D20
    ctx->pc = 0x102cd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)15648);
    // 0x102cd8: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x102cd8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102cdc: 0xaec50000  sw          $a1, 0x0($s6)
    ctx->pc = 0x102cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 5));
    // 0x102ce0: 0x34c63d30  ori         $a2, $a2, 0x3D30
    ctx->pc = 0x102ce0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)15664);
    // 0x102ce4: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x102ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x102ce8: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x102ce8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x102cec: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x102cecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x102cf0: 0x34a53d40  ori         $a1, $a1, 0x3D40
    ctx->pc = 0x102cf0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)15680);
    // 0x102cf4: 0x34e73d50  ori         $a3, $a3, 0x3D50
    ctx->pc = 0x102cf4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)15696);
    // 0x102cf8: 0x3c0c1000  lui         $t4, 0x1000
    ctx->pc = 0x102cf8u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)4096 << 16));
    // 0x102cfc: 0xaec20004  sw          $v0, 0x4($s6)
    ctx->pc = 0x102cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4), GPR_U32(ctx, 2));
    // 0x102d00: 0x358c3d60  ori         $t4, $t4, 0x3D60
    ctx->pc = 0x102d00u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)15712);
    // 0x102d04: 0x3c131000  lui         $s3, 0x1000
    ctx->pc = 0x102d04u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)4096 << 16));
    // 0x102d08: 0x3c141000  lui         $s4, 0x1000
    ctx->pc = 0x102d08u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)4096 << 16));
    // 0x102d0c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x102d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x102d10: 0x36733d70  ori         $s3, $s3, 0x3D70
    ctx->pc = 0x102d10u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)15728);
    // 0x102d14: 0x36943c70  ori         $s4, $s4, 0x3C70
    ctx->pc = 0x102d14u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | (uint64_t)(uint16_t)15472);
    // 0x102d18: 0x3c111000  lui         $s1, 0x1000
    ctx->pc = 0x102d18u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4096 << 16));
    // 0x102d1c: 0xaec20008  sw          $v0, 0x8($s6)
    ctx->pc = 0x102d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 2));
    // 0x102d20: 0x36313c80  ori         $s1, $s1, 0x3C80
    ctx->pc = 0x102d20u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)15488);
    // 0x102d24: 0x3c101000  lui         $s0, 0x1000
    ctx->pc = 0x102d24u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4096 << 16));
    // 0x102d28: 0x3c121000  lui         $s2, 0x1000
    ctx->pc = 0x102d28u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)4096 << 16));
    // 0x102d2c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x102d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102d30: 0x36103c00  ori         $s0, $s0, 0x3C00
    ctx->pc = 0x102d30u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)15360);
    // 0x102d34: 0x36523cd0  ori         $s2, $s2, 0x3CD0
    ctx->pc = 0x102d34u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)15568);
    // 0x102d38: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x102d38u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102d3c: 0xaec2000c  sw          $v0, 0xC($s6)
    ctx->pc = 0x102d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 12), GPR_U32(ctx, 2));
    // 0x102d40: 0x34c63c90  ori         $a2, $a2, 0x3C90
    ctx->pc = 0x102d40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)15504);
    // 0x102d44: 0x3c081000  lui         $t0, 0x1000
    ctx->pc = 0x102d44u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)4096 << 16));
    // 0x102d48: 0x3c0e1000  lui         $t6, 0x1000
    ctx->pc = 0x102d48u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)4096 << 16));
    // 0x102d4c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x102d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102d50: 0x35083ca0  ori         $t0, $t0, 0x3CA0
    ctx->pc = 0x102d50u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)15520);
    // 0x102d54: 0x35ce3cb0  ori         $t6, $t6, 0x3CB0
    ctx->pc = 0x102d54u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)15536);
    // 0x102d58: 0x3c0b1000  lui         $t3, 0x1000
    ctx->pc = 0x102d58u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)4096 << 16));
    // 0x102d5c: 0xaec20010  sw          $v0, 0x10($s6)
    ctx->pc = 0x102d5cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 16), GPR_U32(ctx, 2));
    // 0x102d60: 0x356b3ce0  ori         $t3, $t3, 0x3CE0
    ctx->pc = 0x102d60u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)15584);
    // 0x102d64: 0x3c091000  lui         $t1, 0x1000
    ctx->pc = 0x102d64u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4096 << 16));
    // 0x102d68: 0x3c0f1000  lui         $t7, 0x1000
    ctx->pc = 0x102d68u;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)4096 << 16));
    // 0x102d6c: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x102d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x102d70: 0x35293cc0  ori         $t1, $t1, 0x3CC0
    ctx->pc = 0x102d70u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)15552);
    // 0x102d74: 0x35ef3c30  ori         $t7, $t7, 0x3C30
    ctx->pc = 0x102d74u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | (uint64_t)(uint16_t)15408);
    // 0x102d78: 0x3c0d1000  lui         $t5, 0x1000
    ctx->pc = 0x102d78u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)4096 << 16));
    // 0x102d7c: 0xaec20014  sw          $v0, 0x14($s6)
    ctx->pc = 0x102d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 20), GPR_U32(ctx, 2));
    // 0x102d80: 0x35ad3c60  ori         $t5, $t5, 0x3C60
    ctx->pc = 0x102d80u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) | (uint64_t)(uint16_t)15456);
    // 0x102d84: 0x3c0a1000  lui         $t2, 0x1000
    ctx->pc = 0x102d84u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)4096 << 16));
    // 0x102d88: 0x17aa02  srl         $s5, $s7, 8
    ctx->pc = 0x102d88u;
    SET_GPR_S32(ctx, 21, (int32_t)SRL32(GPR_U32(ctx, 23), 8));
    // 0x102d8c: 0x8d830000  lw          $v1, 0x0($t4)
    ctx->pc = 0x102d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102d90: 0x354a3c20  ori         $t2, $t2, 0x3C20
    ctx->pc = 0x102d90u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)15392);
    // 0x102d94: 0x3c0c1000  lui         $t4, 0x1000
    ctx->pc = 0x102d94u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)4096 << 16));
    // 0x102d98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102d98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102d9c: 0xaec30018  sw          $v1, 0x18($s6)
    ctx->pc = 0x102d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 24), GPR_U32(ctx, 3));
    // 0x102da0: 0x358c3c50  ori         $t4, $t4, 0x3C50
    ctx->pc = 0x102da0u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)15440);
    // 0x102da4: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x102da4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x102da8: 0xaec3001c  sw          $v1, 0x1C($s6)
    ctx->pc = 0x102da8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 28), GPR_U32(ctx, 3));
    // 0x102dac: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x102dacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x102db0: 0xaec40020  sw          $a0, 0x20($s6)
    ctx->pc = 0x102db0u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 32), GPR_U32(ctx, 4));
    // 0x102db4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x102db4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102db8: 0xaec30024  sw          $v1, 0x24($s6)
    ctx->pc = 0x102db8u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 36), GPR_U32(ctx, 3));
    // 0x102dbc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x102dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102dc0: 0xaec40028  sw          $a0, 0x28($s6)
    ctx->pc = 0x102dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 40), GPR_U32(ctx, 4));
    // 0x102dc4: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x102dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x102dc8: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x102dc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102dcc: 0x8d050000  lw          $a1, 0x0($t0)
    ctx->pc = 0x102dccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x102dd0: 0x8dc60000  lw          $a2, 0x0($t6)
    ctx->pc = 0x102dd0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x102dd4: 0x8d670000  lw          $a3, 0x0($t3)
    ctx->pc = 0x102dd4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x102dd8: 0x8d280000  lw          $t0, 0x0($t1)
    ctx->pc = 0x102dd8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x102ddc: 0xa6c3002c  sh          $v1, 0x2C($s6)
    ctx->pc = 0x102ddcu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 44), (uint16_t)GPR_U32(ctx, 3));
    // 0x102de0: 0xa6c4002e  sh          $a0, 0x2E($s6)
    ctx->pc = 0x102de0u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 46), (uint16_t)GPR_U32(ctx, 4));
    // 0x102de4: 0xa6c50030  sh          $a1, 0x30($s6)
    ctx->pc = 0x102de4u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 48), (uint16_t)GPR_U32(ctx, 5));
    // 0x102de8: 0xa6c60032  sh          $a2, 0x32($s6)
    ctx->pc = 0x102de8u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 50), (uint16_t)GPR_U32(ctx, 6));
    // 0x102dec: 0xa6c70034  sh          $a3, 0x34($s6)
    ctx->pc = 0x102decu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 52), (uint16_t)GPR_U32(ctx, 7));
    // 0x102df0: 0xa6c80036  sh          $t0, 0x36($s6)
    ctx->pc = 0x102df0u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 54), (uint16_t)GPR_U32(ctx, 8));
    // 0x102df4: 0x8de40000  lw          $a0, 0x0($t7)
    ctx->pc = 0x102df4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x102df8: 0x8da50000  lw          $a1, 0x0($t5)
    ctx->pc = 0x102df8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x102dfc: 0x8d430000  lw          $v1, 0x0($t2)
    ctx->pc = 0x102dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x102e00: 0xa2d5003e  sb          $s5, 0x3E($s6)
    ctx->pc = 0x102e00u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 62), (uint8_t)GPR_U32(ctx, 21));
    // 0x102e04: 0xa2c3003c  sb          $v1, 0x3C($s6)
    ctx->pc = 0x102e04u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 60), (uint8_t)GPR_U32(ctx, 3));
    // 0x102e08: 0xa2d7003d  sb          $s7, 0x3D($s6)
    ctx->pc = 0x102e08u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 61), (uint8_t)GPR_U32(ctx, 23));
    // 0x102e0c: 0xa6c40038  sh          $a0, 0x38($s6)
    ctx->pc = 0x102e0cu;
    WRITE16(ADD32(GPR_U32(ctx, 22), 56), (uint16_t)GPR_U32(ctx, 4));
    // 0x102e10: 0x8d830000  lw          $v1, 0x0($t4)
    ctx->pc = 0x102e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102e14: 0xa6c5003a  sh          $a1, 0x3A($s6)
    ctx->pc = 0x102e14u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 58), (uint16_t)GPR_U32(ctx, 5));
    // 0x102e18: 0xa2c3003f  sb          $v1, 0x3F($s6)
    ctx->pc = 0x102e18u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 63), (uint8_t)GPR_U32(ctx, 3));
label_102e1c:
    // 0x102e1c: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x102e1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x102e20: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x102e20u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x102e24: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x102e24u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x102e28: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x102e28u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x102e2c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x102e2cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102e30: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x102e30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102e34: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x102e34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102e38: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102e38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102e3c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102e3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102e40: 0x3e00008  jr          $ra
    ctx->pc = 0x102E40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102E40u;
            // 0x102e44: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102CACu: goto label_102cac;
            case 0x102CC0u: goto label_102cc0;
            case 0x102E1Cu: goto label_102e1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102E48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
