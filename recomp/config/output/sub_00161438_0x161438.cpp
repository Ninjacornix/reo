#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161438
// Address: 0x161438 - 0x1614e8
void sub_00161438_0x161438(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161438_0x161438");
#endif

    switch (ctx->pc) {
        case 0x161454u: goto label_161454;
        default: break;
    }

    ctx->pc = 0x161438u;

    // 0x161438: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16143c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16143cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161440: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161440u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161444: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161448: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x161448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16144c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16144Cu;
    SET_GPR_U32(ctx, 31, 0x161454u);
    ctx->pc = 0x161450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16144Cu;
            // 0x161450: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161454u; }
        if (ctx->pc != 0x161454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161454u; }
        if (ctx->pc != 0x161454u) { return; }
    }
    ctx->pc = 0x161454u;
label_161454:
    // 0x161454: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161454u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161458: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x161458u;
    {
        const bool branch_taken_0x161458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16145Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161458u;
            // 0x16145c: 0x2484fc20  addiu       $a0, $a0, -0x3E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161458) {
            ctx->pc = 0x161478u;
            goto label_161478;
        }
    }
    ctx->pc = 0x161460u;
    // 0x161460: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161460u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161464: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161464u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161468: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16146c: 0x8058dd4  j           func_163750
    ctx->pc = 0x16146Cu;
    ctx->pc = 0x161470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16146Cu;
            // 0x161470: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161474u;
    // 0x161474: 0x0  nop
    ctx->pc = 0x161474u;
    // NOP
label_161478:
    // 0x161478: 0x8e2200e8  lw          $v0, 0xE8($s1)
    ctx->pc = 0x161478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 232)));
    // 0x16147c: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x16147Cu;
    {
        const bool branch_taken_0x16147c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16147Cu;
            // 0x161480: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16147c) {
            ctx->pc = 0x1614D0u;
            goto label_1614d0;
        }
    }
    ctx->pc = 0x161484u;
    // 0x161484: 0x24020101  addiu       $v0, $zero, 0x101
    ctx->pc = 0x161484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x161488: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x161488u;
    {
        const bool branch_taken_0x161488 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x16148Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161488u;
            // 0x16148c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161488) {
            ctx->pc = 0x1614A8u;
            goto label_1614a8;
        }
    }
    ctx->pc = 0x161490u;
    // 0x161490: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161490u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161494: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161494u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161498: 0x2484fc58  addiu       $a0, $a0, -0x3A8
    ctx->pc = 0x161498u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966360));
    // 0x16149c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16149cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614a0: 0x8058dd4  j           func_163750
    ctx->pc = 0x1614A0u;
    ctx->pc = 0x1614A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614A0u;
            // 0x1614a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614A8u;
label_1614a8:
    // 0x1614a8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1614A8u;
    {
        const bool branch_taken_0x1614a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1614ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1614A8u;
            // 0x1614ac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1614a8) {
            ctx->pc = 0x1614D0u;
            goto label_1614d0;
        }
    }
    ctx->pc = 0x1614B0u;
    // 0x1614b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1614b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1614b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1614b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1614b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1614b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1614bc: 0x2484fca0  addiu       $a0, $a0, -0x360
    ctx->pc = 0x1614bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966432));
    // 0x1614c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1614c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614c4: 0x8058dd4  j           func_163750
    ctx->pc = 0x1614C4u;
    ctx->pc = 0x1614C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614C4u;
            // 0x1614c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614CCu;
    // 0x1614cc: 0x0  nop
    ctx->pc = 0x1614ccu;
    // NOP
label_1614d0:
    // 0x1614d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1614d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1614d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1614d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1614d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1614d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1614dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1614dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614e0: 0x805853a  j           func_1614E8
    ctx->pc = 0x1614E0u;
    ctx->pc = 0x1614E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614E0u;
            // 0x1614e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1614E8u;
    if (runtime->hasFunction(0x1614E8u)) {
        auto targetFn = runtime->lookupFunction(0x1614E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001614E8_0x1614e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
