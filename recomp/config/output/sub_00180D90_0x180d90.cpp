#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180D90
// Address: 0x180d90 - 0x180e28
void sub_00180D90_0x180d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180D90_0x180d90");
#endif

    switch (ctx->pc) {
        case 0x180e04u: goto label_180e04;
        default: break;
    }

    ctx->pc = 0x180d90u;

    // 0x180d90: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x180d90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x180d94: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x180d94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x180d98: 0x8c66fa10  lw          $a2, -0x5F0($v1)
    ctx->pc = 0x180d98u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x180d9c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180da0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x180da0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x180da4: 0x10c0001c  beqz        $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x180DA4u;
    {
        const bool branch_taken_0x180da4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x180DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180DA4u;
            // 0x180da8: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180da4) {
            ctx->pc = 0x180E18u;
            goto label_180e18;
        }
    }
    ctx->pc = 0x180DACu;
    // 0x180dac: 0x8c870004  lw          $a3, 0x4($a0)
    ctx->pc = 0x180dacu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x180db0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180db0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180db4: 0x24e3fffe  addiu       $v1, $a3, -0x2
    ctx->pc = 0x180db4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967294));
    // 0x180db8: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x180db8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x180dbc: 0x10600016  beqz        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x180DBCu;
    {
        const bool branch_taken_0x180dbc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x180DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180DBCu;
            // 0x180dc0: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180dbc) {
            ctx->pc = 0x180E18u;
            goto label_180e18;
        }
    }
    ctx->pc = 0x180DC4u;
    // 0x180dc4: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x180dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x180dc8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180dcc: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x180DCCu;
    {
        const bool branch_taken_0x180dcc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x180DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180DCCu;
            // 0x180dd0: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180dcc) {
            ctx->pc = 0x180E18u;
            goto label_180e18;
        }
    }
    ctx->pc = 0x180DD4u;
    // 0x180dd4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x180dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x180dd8: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x180dd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x180ddc: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x180ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x180de0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x180de0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180de4: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x180de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x180de8: 0xafa70008  sw          $a3, 0x8($sp)
    ctx->pc = 0x180de8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
    // 0x180dec: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x180decu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x180df0: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x180df0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
    // 0x180df4: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x180df4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x180df8: 0xafa60004  sw          $a2, 0x4($sp)
    ctx->pc = 0x180df8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 6));
    // 0x180dfc: 0xc061e5c  jal         func_187970
    ctx->pc = 0x180DFCu;
    SET_GPR_U32(ctx, 31, 0x180E04u);
    ctx->pc = 0x180E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180DFCu;
            // 0x180e00: 0xa3a00014  sb          $zero, 0x14($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 20), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187970u;
    if (runtime->hasFunction(0x187970u)) {
        auto targetFn = runtime->lookupFunction(0x187970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180E04u; }
        if (ctx->pc != 0x180E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187970_0x187970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180E04u; }
        if (ctx->pc != 0x180E04u) { return; }
    }
    ctx->pc = 0x180E04u;
label_180e04:
    // 0x180e04: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x180e04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180e08: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180e08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180e0c: 0x28830000  slti        $v1, $a0, 0x0
    ctx->pc = 0x180e0cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x180e10: 0x34420017  ori         $v0, $v0, 0x17
    ctx->pc = 0x180e10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)23);
    // 0x180e14: 0x83100a  movz        $v0, $a0, $v1
    ctx->pc = 0x180e14u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
label_180e18:
    // 0x180e18: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180e18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180e1c: 0x3e00008  jr          $ra
    ctx->pc = 0x180E1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180E1Cu;
            // 0x180e20: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180E04u: goto label_180e04;
            case 0x180E18u: goto label_180e18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180E24u;
    // 0x180e24: 0x0  nop
    ctx->pc = 0x180e24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
