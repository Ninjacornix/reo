#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115E30
// Address: 0x115e30 - 0x115ef0
void sub_00115E30_0x115e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115E30_0x115e30");
#endif

    switch (ctx->pc) {
        case 0x115e4cu: goto label_115e4c;
        case 0x115e64u: goto label_115e64;
        case 0x115ed0u: goto label_115ed0;
        default: break;
    }

    ctx->pc = 0x115e30u;

    // 0x115e30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x115e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x115e34: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x115e34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115e38: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115e3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115e40: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x115e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x115e44: 0xc045228  jal         func_1148A0
    ctx->pc = 0x115E44u;
    SET_GPR_U32(ctx, 31, 0x115E4Cu);
    ctx->pc = 0x115E48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115E44u;
            // 0x115e48: 0x3c100026  lui         $s0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115E4Cu; }
        if (ctx->pc != 0x115E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115E4Cu; }
        if (ctx->pc != 0x115E4Cu) { return; }
    }
    ctx->pc = 0x115E4Cu;
label_115e4c:
    // 0x115e4c: 0x2611ab90  addiu       $s1, $s0, -0x5470
    ctx->pc = 0x115e4cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945680));
    // 0x115e50: 0x3c060011  lui         $a2, 0x11
    ctx->pc = 0x115e50u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)17 << 16));
    // 0x115e54: 0x24040210  addiu       $a0, $zero, 0x210
    ctx->pc = 0x115e54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 528));
    // 0x115e58: 0x24c65a50  addiu       $a2, $a2, 0x5A50
    ctx->pc = 0x115e58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 23120));
    // 0x115e5c: 0xc0455dc  jal         func_115770
    ctx->pc = 0x115E5Cu;
    SET_GPR_U32(ctx, 31, 0x115E64u);
    ctx->pc = 0x115E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115E5Cu;
            // 0x115e60: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115770u;
    if (runtime->hasFunction(0x115770u)) {
        auto targetFn = runtime->lookupFunction(0x115770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115E64u; }
        if (ctx->pc != 0x115E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115770_0x115770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115E64u; }
        if (ctx->pc != 0x115E64u) { return; }
    }
    ctx->pc = 0x115E64u;
label_115e64:
    // 0x115e64: 0xae02ab90  sw          $v0, -0x5470($s0)
    ctx->pc = 0x115e64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294945680), GPR_U32(ctx, 2));
    // 0x115e68: 0x8e02ab90  lw          $v0, -0x5470($s0)
    ctx->pc = 0x115e68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294945680)));
    // 0x115e6c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115E6Cu;
    {
        const bool branch_taken_0x115e6c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x115E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115E6Cu;
            // 0x115e70: 0x3c040026  lui         $a0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115e6c) {
            ctx->pc = 0x115E7Cu;
            goto label_115e7c;
        }
    }
    ctx->pc = 0x115E74u;
    // 0x115e74: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x115E74u;
    {
        const bool branch_taken_0x115e74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115E74u;
            // 0x115e78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115e74) {
            ctx->pc = 0x115ED8u;
            goto label_115ed8;
        }
    }
    ctx->pc = 0x115E7Cu;
label_115e7c:
    // 0x115e7c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x115e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x115e80: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x115e80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x115e84: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x115e84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x115e88: 0x2484ad00  addiu       $a0, $a0, -0x5300
    ctx->pc = 0x115e88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946048));
    // 0x115e8c: 0x2442abc0  addiu       $v0, $v0, -0x5440
    ctx->pc = 0x115e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945728));
    // 0x115e90: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x115e90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x115e94: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x115e94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x115e98: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x115e98u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x115e9c: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x115e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x115ea0: 0xae240014  sw          $a0, 0x14($s1)
    ctx->pc = 0x115ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 4));
    // 0x115ea4: 0x24060210  addiu       $a2, $zero, 0x210
    ctx->pc = 0x115ea4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 528));
    // 0x115ea8: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x115ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x115eac: 0x24050045  addiu       $a1, $zero, 0x45
    ctx->pc = 0x115eacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x115eb0: 0x24030048  addiu       $v1, $zero, 0x48
    ctx->pc = 0x115eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x115eb4: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x115eb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x115eb8: 0xa4460004  sh          $a2, 0x4($v0)
    ctx->pc = 0x115eb8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 4), (uint16_t)GPR_U32(ctx, 6));
    // 0x115ebc: 0xa0450006  sb          $a1, 0x6($v0)
    ctx->pc = 0x115ebcu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 6), (uint8_t)GPR_U32(ctx, 5));
    // 0x115ec0: 0xa0430007  sb          $v1, 0x7($v0)
    ctx->pc = 0x115ec0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 7), (uint8_t)GPR_U32(ctx, 3));
    // 0x115ec4: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x115ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x115ec8: 0xc04566a  jal         func_1159A8
    ctx->pc = 0x115EC8u;
    SET_GPR_U32(ctx, 31, 0x115ED0u);
    ctx->pc = 0x115ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115EC8u;
            // 0x115ecc: 0xa4400002  sh          $zero, 0x2($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1159A8u;
    if (runtime->hasFunction(0x1159A8u)) {
        auto targetFn = runtime->lookupFunction(0x1159A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115ED0u; }
        if (ctx->pc != 0x115ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001159A8_0x1159a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115ED0u; }
        if (ctx->pc != 0x115ED0u) { return; }
    }
    ctx->pc = 0x115ED0u;
label_115ed0:
    // 0x115ed0: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x115ed0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
    // 0x115ed4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x115ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_115ed8:
    // 0x115ed8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x115ed8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115edc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115edcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115ee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x115EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115EE4u;
            // 0x115ee8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115E4Cu: goto label_115e4c;
            case 0x115E64u: goto label_115e64;
            case 0x115E7Cu: goto label_115e7c;
            case 0x115ED0u: goto label_115ed0;
            case 0x115ED8u: goto label_115ed8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115EECu;
    // 0x115eec: 0x0  nop
    ctx->pc = 0x115eecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
