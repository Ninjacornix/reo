#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DB30
// Address: 0x11db30 - 0x11dc48
void sub_0011DB30_0x11db30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DB30_0x11db30");
#endif

    switch (ctx->pc) {
        case 0x11db84u: goto label_11db84;
        case 0x11dba0u: goto label_11dba0;
        case 0x11dbacu: goto label_11dbac;
        case 0x11dbc0u: goto label_11dbc0;
        case 0x11dbd8u: goto label_11dbd8;
        case 0x11dbecu: goto label_11dbec;
        case 0x11dbf8u: goto label_11dbf8;
        case 0x11dc10u: goto label_11dc10;
        default: break;
    }

    ctx->pc = 0x11db30u;

    // 0x11db30: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x11db30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11db34: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11db34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11db38: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11db38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11db3c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11db3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11db40: 0x8c53a180  lw          $s3, -0x5E80($v0)
    ctx->pc = 0x11db40u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943104)));
    // 0x11db44: 0x2467ac38  addiu       $a3, $v1, -0x53C8
    ctx->pc = 0x11db44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945848));
    // 0x11db48: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x11db48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x11db4c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x11db4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x11db50: 0x26620040  addiu       $v0, $s3, 0x40
    ctx->pc = 0x11db50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 64));
    // 0x11db54: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11db54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11db58: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x11db58u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db5c: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11db5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11db60: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11db60u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db64: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11db64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11db68: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11db68u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db6c: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x11db6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11db70: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11db70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db74: 0x8c64ac38  lw          $a0, -0x53C8($v1)
    ctx->pc = 0x11db74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294945848)));
    // 0x11db78: 0x8ce50004  lw          $a1, 0x4($a3)
    ctx->pc = 0x11db78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x11db7c: 0xc0476c8  jal         func_11DB20
    ctx->pc = 0x11DB7Cu;
    SET_GPR_U32(ctx, 31, 0x11DB84u);
    ctx->pc = 0x11DB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DB7Cu;
            // 0x11db80: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DB20u;
    if (runtime->hasFunction(0x11DB20u)) {
        auto targetFn = runtime->lookupFunction(0x11DB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DB84u; }
        if (ctx->pc != 0x11DB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DB20_0x11db20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DB84u; }
        if (ctx->pc != 0x11DB84u) { return; }
    }
    ctx->pc = 0x11DB84u;
label_11db84:
    // 0x11db84: 0x2a430010  slti        $v1, $s2, 0x10
    ctx->pc = 0x11db84u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x11db88: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x11db88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x11db8c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x11db8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db90: 0x43900a  movz        $s2, $v0, $v1
    ctx->pc = 0x11db90u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 2));
    // 0x11db94: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x11db94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11db98: 0xc0476b8  jal         func_11DAE0
    ctx->pc = 0x11DB98u;
    SET_GPR_U32(ctx, 31, 0x11DBA0u);
    ctx->pc = 0x11DB9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DB98u;
            // 0x11db9c: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DAE0u;
    if (runtime->hasFunction(0x11DAE0u)) {
        auto targetFn = runtime->lookupFunction(0x11DAE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBA0u; }
        if (ctx->pc != 0x11DBA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DAE0_0x11dae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBA0u; }
        if (ctx->pc != 0x11DBA0u) { return; }
    }
    ctx->pc = 0x11DBA0u;
label_11dba0:
    // 0x11dba0: 0x26730004  addiu       $s3, $s3, 0x4
    ctx->pc = 0x11dba0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x11dba4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x11DBA4u;
    SET_GPR_U32(ctx, 31, 0x11DBACu);
    ctx->pc = 0x11DBA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DBA4u;
            // 0x11dba8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBACu; }
        if (ctx->pc != 0x11DBACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBACu; }
        if (ctx->pc != 0x11DBACu) { return; }
    }
    ctx->pc = 0x11DBACu;
label_11dbac:
    // 0x11dbac: 0x24510001  addiu       $s1, $v0, 0x1
    ctx->pc = 0x11dbacu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11dbb0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x11dbb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dbb4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11dbb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dbb8: 0xc0476b8  jal         func_11DAE0
    ctx->pc = 0x11DBB8u;
    SET_GPR_U32(ctx, 31, 0x11DBC0u);
    ctx->pc = 0x11DBBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DBB8u;
            // 0x11dbbc: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DAE0u;
    if (runtime->hasFunction(0x11DAE0u)) {
        auto targetFn = runtime->lookupFunction(0x11DAE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBC0u; }
        if (ctx->pc != 0x11DBC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DAE0_0x11dae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBC0u; }
        if (ctx->pc != 0x11DBC0u) { return; }
    }
    ctx->pc = 0x11DBC0u;
label_11dbc0:
    // 0x11dbc0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x11dbc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dbc4: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x11dbc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x11dbc8: 0x1a400015  blez        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x11DBC8u;
    {
        const bool branch_taken_0x11dbc8 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x11DBCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DBC8u;
            // 0x11dbcc: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11dbc8) {
            ctx->pc = 0x11DC20u;
            goto label_11dc20;
        }
    }
    ctx->pc = 0x11DBD0u;
    // 0x11dbd0: 0x280802d  daddu       $s0, $s4, $zero
    ctx->pc = 0x11dbd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dbd4: 0x0  nop
    ctx->pc = 0x11dbd4u;
    // NOP
label_11dbd8:
    // 0x11dbd8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x11dbd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dbdc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x11dbdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dbe0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x11dbe0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11dbe4: 0xc0476b8  jal         func_11DAE0
    ctx->pc = 0x11DBE4u;
    SET_GPR_U32(ctx, 31, 0x11DBECu);
    ctx->pc = 0x11DBE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DBE4u;
            // 0x11dbe8: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DAE0u;
    if (runtime->hasFunction(0x11DAE0u)) {
        auto targetFn = runtime->lookupFunction(0x11DAE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBECu; }
        if (ctx->pc != 0x11DBECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DAE0_0x11dae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBECu; }
        if (ctx->pc != 0x11DBECu) { return; }
    }
    ctx->pc = 0x11DBECu;
label_11dbec:
    // 0x11dbec: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x11dbecu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x11dbf0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x11DBF0u;
    SET_GPR_U32(ctx, 31, 0x11DBF8u);
    ctx->pc = 0x11DBF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DBF0u;
            // 0x11dbf4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBF8u; }
        if (ctx->pc != 0x11DBF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DBF8u; }
        if (ctx->pc != 0x11DBF8u) { return; }
    }
    ctx->pc = 0x11DBF8u;
label_11dbf8:
    // 0x11dbf8: 0x24510001  addiu       $s1, $v0, 0x1
    ctx->pc = 0x11dbf8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x11dbfc: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x11dbfcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11dc00: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x11dc00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dc04: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x11dc04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc08: 0xc0476b8  jal         func_11DAE0
    ctx->pc = 0x11DC08u;
    SET_GPR_U32(ctx, 31, 0x11DC10u);
    ctx->pc = 0x11DC0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DC08u;
            // 0x11dc0c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DAE0u;
    if (runtime->hasFunction(0x11DAE0u)) {
        auto targetFn = runtime->lookupFunction(0x11DAE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC10u; }
        if (ctx->pc != 0x11DC10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DAE0_0x11dae0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC10u; }
        if (ctx->pc != 0x11DC10u) { return; }
    }
    ctx->pc = 0x11DC10u;
label_11dc10:
    // 0x11dc10: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x11dc10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dc14: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x11dc14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x11dc18: 0x1640ffef  bnez        $s2, . + 4 + (-0x11 << 2)
    ctx->pc = 0x11DC18u;
    {
        const bool branch_taken_0x11dc18 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x11DC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DC18u;
            // 0x11dc1c: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11dc18) {
            ctx->pc = 0x11DBD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11dbd8;
        }
    }
    ctx->pc = 0x11DC20u;
label_11dc20:
    // 0x11dc20: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x11dc20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc24: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x11dc24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11dc28: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x11dc28u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11dc2c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x11dc2cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11dc30: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11dc30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11dc34: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11dc34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11dc38: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11dc38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dc3c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11dc3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dc40: 0x3e00008  jr          $ra
    ctx->pc = 0x11DC40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DC44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DC40u;
            // 0x11dc44: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DB84u: goto label_11db84;
            case 0x11DBA0u: goto label_11dba0;
            case 0x11DBACu: goto label_11dbac;
            case 0x11DBC0u: goto label_11dbc0;
            case 0x11DBD8u: goto label_11dbd8;
            case 0x11DBECu: goto label_11dbec;
            case 0x11DBF8u: goto label_11dbf8;
            case 0x11DC10u: goto label_11dc10;
            case 0x11DC20u: goto label_11dc20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DC48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
