#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001306E0
// Address: 0x1306e0 - 0x130748
void sub_001306E0_0x1306e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001306E0_0x1306e0");
#endif

    switch (ctx->pc) {
        case 0x1306f4u: goto label_1306f4;
        default: break;
    }

    ctx->pc = 0x1306e0u;

    // 0x1306e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1306e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1306e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1306e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1306e8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1306e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1306ec: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x1306ECu;
    SET_GPR_U32(ctx, 31, 0x1306F4u);
    ctx->pc = 0x1306F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1306ECu;
            // 0x1306f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306F4u; }
        if (ctx->pc != 0x1306F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306F4u; }
        if (ctx->pc != 0x1306F4u) { return; }
    }
    ctx->pc = 0x1306F4u;
label_1306f4:
    // 0x1306f4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1306f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1306f8: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x1306f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x1306fc: 0x3463ff00  ori         $v1, $v1, 0xFF00
    ctx->pc = 0x1306fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65280);
    // 0x130700: 0x3c040001  lui         $a0, 0x1
    ctx->pc = 0x130700u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)1 << 16));
    // 0x130704: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x130704u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x130708: 0x34840200  ori         $a0, $a0, 0x200
    ctx->pc = 0x130708u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)512);
    // 0x13070c: 0x14440008  bne         $v0, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13070Cu;
    {
        const bool branch_taken_0x13070c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x130710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13070Cu;
            // 0x130710: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13070c) {
            ctx->pc = 0x130730u;
            goto label_130730;
        }
    }
    ctx->pc = 0x130714u;
    // 0x130714: 0x82030043  lb          $v1, 0x43($s0)
    ctx->pc = 0x130714u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x130718: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130718u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13071c: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13071Cu;
    {
        const bool branch_taken_0x13071c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x130720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13071Cu;
            // 0x130720: 0xa2020044  sb          $v0, 0x44($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 68), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13071c) {
            ctx->pc = 0x130738u;
            goto label_130738;
        }
    }
    ctx->pc = 0x130724u;
    // 0x130724: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x130724u;
    {
        const bool branch_taken_0x130724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x130728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130724u;
            // 0x130728: 0xa2000043  sb          $zero, 0x43($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 67), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130724) {
            ctx->pc = 0x130738u;
            goto label_130738;
        }
    }
    ctx->pc = 0x13072Cu;
    // 0x13072c: 0x0  nop
    ctx->pc = 0x13072cu;
    // NOP
label_130730:
    // 0x130730: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130734: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x130734u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_130738:
    // 0x130738: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130738u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13073c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13073cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130740: 0x80505ba  j           func_1416E8
    ctx->pc = 0x130740u;
    ctx->pc = 0x130744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130740u;
            // 0x130744: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
