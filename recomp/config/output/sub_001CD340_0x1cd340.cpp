#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD340
// Address: 0x1cd340 - 0x1cd3f0
void sub_001CD340_0x1cd340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD340_0x1cd340");
#endif

    switch (ctx->pc) {
        case 0x1cd388u: goto label_1cd388;
        case 0x1cd3b8u: goto label_1cd3b8;
        case 0x1cd3d0u: goto label_1cd3d0;
        default: break;
    }

    ctx->pc = 0x1cd340u;

    // 0x1cd340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd344: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1cd344u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd348: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd34c: 0x29010064  slti        $at, $t0, 0x64
    ctx->pc = 0x1cd34cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1cd350: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd350u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd354: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x1cd354u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd358: 0x1020000d  beqz        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CD358u;
    {
        const bool branch_taken_0x1cd358 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD358u;
            // 0x1cd35c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd358) {
            ctx->pc = 0x1CD390u;
            goto label_1cd390;
        }
    }
    ctx->pc = 0x1CD360u;
    // 0x1cd360: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd360u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd364: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd364u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd368: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd368u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd36c: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd36cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd370: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd374: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd374u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd378: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd378u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd37c: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd37cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd380: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD380u;
    SET_GPR_U32(ctx, 31, 0x1CD388u);
    ctx->pc = 0x1CD384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD380u;
            // 0x1cd384: 0x24a55f80  addiu       $a1, $a1, 0x5F80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD388u; }
        if (ctx->pc != 0x1CD388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD388u; }
        if (ctx->pc != 0x1CD388u) { return; }
    }
    ctx->pc = 0x1CD388u;
label_1cd388:
    // 0x1cd388: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CD388u;
    {
        const bool branch_taken_0x1cd388 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd388) {
            ctx->pc = 0x1CD3B8u;
            goto label_1cd3b8;
        }
    }
    ctx->pc = 0x1CD390u;
label_1cd390:
    // 0x1cd390: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd394: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd394u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd398: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1cd398u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1cd39c: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd39cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd3a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd3a4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd3a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd3a8: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd3a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd3ac: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd3acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd3b0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD3B0u;
    SET_GPR_U32(ctx, 31, 0x1CD3B8u);
    ctx->pc = 0x1CD3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD3B0u;
            // 0x1cd3b4: 0x24a55f90  addiu       $a1, $a1, 0x5F90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD3B8u; }
        if (ctx->pc != 0x1CD3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD3B8u; }
        if (ctx->pc != 0x1CD3B8u) { return; }
    }
    ctx->pc = 0x1CD3B8u;
label_1cd3b8:
    // 0x1cd3b8: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD3B8u;
    {
        const bool branch_taken_0x1cd3b8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD3B8u;
            // 0x1cd3bc: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd3b8) {
            ctx->pc = 0x1CD3D0u;
            goto label_1cd3d0;
        }
    }
    ctx->pc = 0x1CD3C0u;
    // 0x1cd3c0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd3c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd3c4: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd3c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd3c8: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD3C8u;
    SET_GPR_U32(ctx, 31, 0x1CD3D0u);
    ctx->pc = 0x1CD3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD3C8u;
            // 0x1cd3cc: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD3D0u; }
        if (ctx->pc != 0x1CD3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD3D0u; }
        if (ctx->pc != 0x1CD3D0u) { return; }
    }
    ctx->pc = 0x1CD3D0u;
label_1cd3d0:
    // 0x1cd3d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd3d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd3d4: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd3d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd3d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd3d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd3dc: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd3dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd3e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD3E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD3E0u;
            // 0x1cd3e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD388u: goto label_1cd388;
            case 0x1CD390u: goto label_1cd390;
            case 0x1CD3B8u: goto label_1cd3b8;
            case 0x1CD3D0u: goto label_1cd3d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD3E8u;
    // 0x1cd3e8: 0x0  nop
    ctx->pc = 0x1cd3e8u;
    // NOP
    // 0x1cd3ec: 0x0  nop
    ctx->pc = 0x1cd3ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
