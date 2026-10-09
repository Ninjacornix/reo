#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140DD0
// Address: 0x140dd0 - 0x140e88
void sub_00140DD0_0x140dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140DD0_0x140dd0");
#endif

    switch (ctx->pc) {
        case 0x140e0cu: goto label_140e0c;
        case 0x140e68u: goto label_140e68;
        default: break;
    }

    ctx->pc = 0x140dd0u;

    // 0x140dd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140dd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140dd4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140dd8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140ddc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140ddcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140de0: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140de4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140de4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140de8: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140de8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140dec: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140decu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140df0: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140df0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140df4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140df4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140df8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140df8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140dfc: 0x24040029  addiu       $a0, $zero, 0x29
    ctx->pc = 0x140dfcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x140e00: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x140e00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x140e04: 0xc04e518  jal         func_139460
    ctx->pc = 0x140E04u;
    SET_GPR_U32(ctx, 31, 0x140E0Cu);
    ctx->pc = 0x140E08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140E04u;
            // 0x140e08: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140E0Cu; }
        if (ctx->pc != 0x140E0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140E0Cu; }
        if (ctx->pc != 0x140E0Cu) { return; }
    }
    ctx->pc = 0x140E0Cu;
label_140e0c:
    // 0x140e0c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140e10: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140e14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140e14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140e18: 0x3e00008  jr          $ra
    ctx->pc = 0x140E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140E18u;
            // 0x140e1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140E0Cu: goto label_140e0c;
            case 0x140E68u: goto label_140e68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140E20u;
    // 0x140e20: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x140e24: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140e24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140e28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140e2c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140e2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140e30: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140e34: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140e38: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x140e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x140e3c: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140e3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140e40: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140e40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140e44: 0x2404002a  addiu       $a0, $zero, 0x2A
    ctx->pc = 0x140e44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x140e48: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140e48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140e4c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140e4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140e50: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140e50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140e54: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140e54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140e58: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x140e58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140e5c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140e5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140e60: 0xc04e518  jal         func_139460
    ctx->pc = 0x140E60u;
    SET_GPR_U32(ctx, 31, 0x140E68u);
    ctx->pc = 0x140E64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140E60u;
            // 0x140e64: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140E68u; }
        if (ctx->pc != 0x140E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140E68u; }
        if (ctx->pc != 0x140E68u) { return; }
    }
    ctx->pc = 0x140E68u;
label_140e68:
    // 0x140e68: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x140e68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x140e6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x140e6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140e70: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x140e70u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x140e74: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140e74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140e78: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140e78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140e7c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140e7cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140e80: 0x3e00008  jr          $ra
    ctx->pc = 0x140E80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140E80u;
            // 0x140e84: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140E0Cu: goto label_140e0c;
            case 0x140E68u: goto label_140e68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140E88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
